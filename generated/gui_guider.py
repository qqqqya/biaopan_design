# Copyright 2026 NXP
# NXP Proprietary. This software is owned or controlled by NXP and may only be used strictly in
# accordance with the applicable license terms. By expressly accepting such terms or by downloading, installing,
# activating and/or otherwise using the software, you are agreeing that you have read, and that you agree to
# comply with and are bound by, such license terms.  If you do not agree to be bound by the applicable license
# terms, then you may not retain, install, activate or otherwise use the software.

import SDL
import utime as time
import usys as sys
import lvgl as lv
import lodepng as png
import ustruct
import fs_driver

lv.init()
SDL.init(w=240,h=280)

# Register SDL display driver.
disp_buf1 = lv.disp_draw_buf_t()
buf1_1 = bytearray(240*280*4)
disp_buf1.init(buf1_1, None, len(buf1_1)//4)
disp_drv = lv.disp_drv_t()
disp_drv.init()
disp_drv.draw_buf = disp_buf1
disp_drv.flush_cb = SDL.monitor_flush
disp_drv.hor_res = 240
disp_drv.ver_res = 280
disp_drv.register()

# Regsiter SDL mouse driver
indev_drv = lv.indev_drv_t()
indev_drv.init()
indev_drv.type = lv.INDEV_TYPE.POINTER
indev_drv.read_cb = SDL.mouse_read
indev_drv.register()

fs_drv = lv.fs_drv_t()
fs_driver.fs_register(fs_drv, 'Z')

# Below: Taken from https://github.com/lvgl/lv_binding_micropython/blob/master/driver/js/imagetools.py#L22-L94

COLOR_SIZE = lv.color_t.__SIZE__
COLOR_IS_SWAPPED = hasattr(lv.color_t().ch,'green_h')

class lodepng_error(RuntimeError):
    def __init__(self, err):
        if type(err) is int:
            super().__init__(png.error_text(err))
        else:
            super().__init__(err)

# Parse PNG file header
# Taken from https://github.com/shibukawa/imagesize_py/blob/ffef30c1a4715c5acf90e8945ceb77f4a2ed2d45/imagesize.py#L63-L85

def get_png_info(decoder, src, header):
    # Only handle variable image types

    if lv.img.src_get_type(src) != lv.img.SRC.VARIABLE:
        return lv.RES.INV

    data = lv.img_dsc_t.__cast__(src).data
    if data == None:
        return lv.RES.INV

    png_header = bytes(data.__dereference__(24))

    if png_header.startswith(b'\211PNG\r\n\032\n'):
        if png_header[12:16] == b'IHDR':
            start = 16
        # Maybe this is for an older PNG version.
        else:
            start = 8
        try:
            width, height = ustruct.unpack(">LL", png_header[start:start+8])
        except ustruct.error:
            return lv.RES.INV
    else:
        return lv.RES.INV

    header.always_zero = 0
    header.w = width
    header.h = height
    header.cf = lv.img.CF.TRUE_COLOR_ALPHA

    return lv.RES.OK

def convert_rgba8888_to_bgra8888(img_view):
    for i in range(0, len(img_view), lv.color_t.__SIZE__):
        ch = lv.color_t.__cast__(img_view[i:i]).ch
        ch.red, ch.blue = ch.blue, ch.red

# Read and parse PNG file

def open_png(decoder, dsc):
    img_dsc = lv.img_dsc_t.__cast__(dsc.src)
    png_data = img_dsc.data
    png_size = img_dsc.data_size
    png_decoded = png.C_Pointer()
    png_width = png.C_Pointer()
    png_height = png.C_Pointer()
    error = png.decode32(png_decoded, png_width, png_height, png_data, png_size)
    if error:
        raise lodepng_error(error)
    img_size = png_width.int_val * png_height.int_val * 4
    img_data = png_decoded.ptr_val
    img_view = img_data.__dereference__(img_size)

    if COLOR_SIZE == 4:
        convert_rgba8888_to_bgra8888(img_view)
    else:
        raise lodepng_error("Error: Color mode not supported yet!")

    dsc.img_data = img_data
    return lv.RES.OK

# Above: Taken from https://github.com/lvgl/lv_binding_micropython/blob/master/driver/js/imagetools.py#L22-L94

decoder = lv.img.decoder_create()
decoder.info_cb = get_png_info
decoder.open_cb = open_png

def anim_x_cb(obj, v):
    obj.set_x(v)

def anim_y_cb(obj, v):
    obj.set_y(v)

def anim_width_cb(obj, v):
    obj.set_width(v)

def anim_height_cb(obj, v):
    obj.set_height(v)

def anim_img_zoom_cb(obj, v):
    obj.set_zoom(v)

def anim_img_rotate_cb(obj, v):
    obj.set_angle(v)

global_font_cache = {}
def test_font(font_family, font_size):
    global global_font_cache
    if font_family + str(font_size) in global_font_cache:
        return global_font_cache[font_family + str(font_size)]
    if font_size % 2:
        candidates = [
            (font_family, font_size),
            (font_family, font_size-font_size%2),
            (font_family, font_size+font_size%2),
            ("montserrat", font_size-font_size%2),
            ("montserrat", font_size+font_size%2),
            ("montserrat", 16)
        ]
    else:
        candidates = [
            (font_family, font_size),
            ("montserrat", font_size),
            ("montserrat", 16)
        ]
    for (family, size) in candidates:
        try:
            if eval(f'lv.font_{family}_{size}'):
                global_font_cache[font_family + str(font_size)] = eval(f'lv.font_{family}_{size}')
                if family != font_family or size != font_size:
                    print(f'WARNING: lv.font_{family}_{size} is used!')
                return eval(f'lv.font_{family}_{size}')
        except AttributeError:
            try:
                load_font = lv.font_load(f"Z:MicroPython/lv_font_{family}_{size}.fnt")
                global_font_cache[font_family + str(font_size)] = load_font
                return load_font
            except:
                if family == font_family and size == font_size:
                    print(f'WARNING: lv.font_{family}_{size} is NOT supported!')

global_image_cache = {}
def load_image(file):
    global global_image_cache
    if file in global_image_cache:
        return global_image_cache[file]
    try:
        with open(file,'rb') as f:
            data = f.read()
    except:
        print(f'Could not open {file}')
        sys.exit()

    img = lv.img_dsc_t({
        'data_size': len(data),
        'data': data
    })
    global_image_cache[file] = img
    return img

def calendar_event_handler(e,obj):
    code = e.get_code()

    if code == lv.EVENT.VALUE_CHANGED:
        source = e.get_current_target()
        date = lv.calendar_date_t()
        if source.get_pressed_date(date) == lv.RES.OK:
            source.set_highlighted_dates([date], 1)

def spinbox_increment_event_cb(e, obj):
    code = e.get_code()
    if code == lv.EVENT.SHORT_CLICKED or code == lv.EVENT.LONG_PRESSED_REPEAT:
        obj.increment()
def spinbox_decrement_event_cb(e, obj):
    code = e.get_code()
    if code == lv.EVENT.SHORT_CLICKED or code == lv.EVENT.LONG_PRESSED_REPEAT:
        obj.decrement()

def digital_clock_cb(timer, obj, current_time, show_second, use_ampm):
    hour = int(current_time[0])
    minute = int(current_time[1])
    second = int(current_time[2])
    ampm = current_time[3]
    second = second + 1
    if second == 60:
        second = 0
        minute = minute + 1
        if minute == 60:
            minute = 0
            hour = hour + 1
            if use_ampm:
                if hour == 12:
                    if ampm == 'AM':
                        ampm = 'PM'
                    elif ampm == 'PM':
                        ampm = 'AM'
                if hour > 12:
                    hour = hour % 12
    hour = hour % 24
    if use_ampm:
        if show_second:
            obj.set_text("%d:%02d:%02d %s" %(hour, minute, second, ampm))
        else:
            obj.set_text("%d:%02d %s" %(hour, minute, ampm))
    else:
        if show_second:
            obj.set_text("%d:%02d:%02d" %(hour, minute, second))
        else:
            obj.set_text("%d:%02d" %(hour, minute))
    current_time[0] = hour
    current_time[1] = minute
    current_time[2] = second
    current_time[3] = ampm

def analog_clock_cb(timer, obj):
    datetime = time.localtime()
    hour = datetime[3]
    if hour >= 12: hour = hour - 12
    obj.set_time(hour, datetime[4], datetime[5])

def datetext_event_handler(e, obj):
    code = e.get_code()
    target = e.get_target()
    if code == lv.EVENT.FOCUSED:
        if obj is None:
            bg = lv.layer_top()
            bg.add_flag(lv.obj.FLAG.CLICKABLE)
            obj = lv.calendar(bg)
            scr = target.get_screen()
            scr_height = scr.get_height()
            scr_width = scr.get_width()
            obj.set_size(int(scr_width * 0.8), int(scr_height * 0.8))
            datestring = target.get_text()
            year = int(datestring.split('/')[0])
            month = int(datestring.split('/')[1])
            day = int(datestring.split('/')[2])
            obj.set_showed_date(year, month)
            highlighted_days=[lv.calendar_date_t({'year':year, 'month':month, 'day':day})]
            obj.set_highlighted_dates(highlighted_days, 1)
            obj.align(lv.ALIGN.CENTER, 0, 0)
            lv.calendar_header_arrow(obj)
            obj.add_event_cb(lambda e: datetext_calendar_event_handler(e, target), lv.EVENT.ALL, None)
            scr.update_layout()

def datetext_calendar_event_handler(e, obj):
    code = e.get_code()
    target = e.get_current_target()
    if code == lv.EVENT.VALUE_CHANGED:
        date = lv.calendar_date_t()
        if target.get_pressed_date(date) == lv.RES.OK:
            obj.set_text(f"{date.year}/{date.month}/{date.day}")
            bg = lv.layer_top()
            bg.clear_flag(lv.obj.FLAG.CLICKABLE)
            bg.set_style_bg_opa(lv.OPA.TRANSP, 0)
            target.delete()

# Create screen_1_home
screen_1_home = lv.obj()
screen_1_home.set_size(240, 280)
screen_1_home.set_scrollbar_mode(lv.SCROLLBAR_MODE.OFF)
# Set style for screen_1_home, Part: lv.PART.MAIN, State: lv.STATE.DEFAULT.
screen_1_home.set_style_bg_opa(255, lv.PART.MAIN|lv.STATE.DEFAULT)
screen_1_home.set_style_bg_color(lv.color_hex(0x000000), lv.PART.MAIN|lv.STATE.DEFAULT)
screen_1_home.set_style_bg_grad_dir(lv.GRAD_DIR.NONE, lv.PART.MAIN|lv.STATE.DEFAULT)

# Create screen_1_home_analog_clock_1
screen_1_home_analog_clock_1 = lv.analogclock(screen_1_home)
screen_1_home_analog_clock_1.hide_digits(True)
screen_1_home_analog_clock_1.hide_point(False)
screen_1_home_analog_clock_1.set_major_ticks(2, 10, lv.color_hex(0x555555), 10)
screen_1_home_analog_clock_1.set_ticks(2, 5, lv.color_hex(0x333333))
screen_1_home_analog_clock_1.set_hour_needle_line(2, lv.color_hex(0xffffff), -40)
screen_1_home_analog_clock_1.set_sec_needle_line(2, lv.color_hex(0xff0027), -10)
screen_1_home_analog_clock_1.set_time(7, 51, 58)
screen_1_home_analog_clock_1_timer = lv.timer_create_basic()
screen_1_home_analog_clock_1_timer.set_period(1000)
screen_1_home_analog_clock_1_timer.set_cb(lambda src: analog_clock_cb(screen_1_home_analog_clock_1_timer, screen_1_home_analog_clock_1))
screen_1_home_analog_clock_1.set_pos(20, 41)
screen_1_home_analog_clock_1.set_size(200, 200)
# Set style for screen_1_home_analog_clock_1, Part: lv.PART.MAIN, State: lv.STATE.DEFAULT.
screen_1_home_analog_clock_1.set_style_bg_opa(255, lv.PART.MAIN|lv.STATE.DEFAULT)
screen_1_home_analog_clock_1.set_style_bg_color(lv.color_hex(0xffffff), lv.PART.MAIN|lv.STATE.DEFAULT)
screen_1_home_analog_clock_1.set_style_bg_grad_dir(lv.GRAD_DIR.NONE, lv.PART.MAIN|lv.STATE.DEFAULT)
screen_1_home_analog_clock_1.set_style_border_width(0, lv.PART.MAIN|lv.STATE.DEFAULT)
screen_1_home_analog_clock_1.set_style_shadow_width(0, lv.PART.MAIN|lv.STATE.DEFAULT)
screen_1_home_analog_clock_1.set_style_bg_img_src("B:MicroPython/_biaopan1_200x200.bin", lv.PART.MAIN|lv.STATE.DEFAULT)
screen_1_home_analog_clock_1.set_style_bg_img_opa(255, lv.PART.MAIN|lv.STATE.DEFAULT)
screen_1_home_analog_clock_1.set_style_bg_img_recolor_opa(0, lv.PART.MAIN|lv.STATE.DEFAULT)
# Set style for screen_1_home_analog_clock_1, Part: lv.PART.TICKS, State: lv.STATE.DEFAULT.
screen_1_home_analog_clock_1.set_style_text_color(lv.color_hex(0xff0000), lv.PART.TICKS|lv.STATE.DEFAULT)
screen_1_home_analog_clock_1.set_style_text_font(test_font("montserratMedium", 12), lv.PART.TICKS|lv.STATE.DEFAULT)
screen_1_home_analog_clock_1.set_style_text_opa(255, lv.PART.TICKS|lv.STATE.DEFAULT)
# Set style for screen_1_home_analog_clock_1, Part: lv.PART.INDICATOR, State: lv.STATE.DEFAULT.
screen_1_home_analog_clock_1.set_style_bg_opa(255, lv.PART.INDICATOR|lv.STATE.DEFAULT)
screen_1_home_analog_clock_1.set_style_bg_color(lv.color_hex(0x000000), lv.PART.INDICATOR|lv.STATE.DEFAULT)
screen_1_home_analog_clock_1.set_style_bg_grad_dir(lv.GRAD_DIR.NONE, lv.PART.INDICATOR|lv.STATE.DEFAULT)

# Create screen_1_home_img_2
screen_1_home_img_2 = lv.img(screen_1_home)
screen_1_home_img_2.set_src("B:MicroPython/_Ellipse_alpha_26x30.bin")
screen_1_home_img_2.add_flag(lv.obj.FLAG.CLICKABLE)
screen_1_home_img_2.set_pivot(50,50)
screen_1_home_img_2.set_angle(0)
screen_1_home_img_2.set_pos(21, 24)
screen_1_home_img_2.set_size(26, 30)
# Set style for screen_1_home_img_2, Part: lv.PART.MAIN, State: lv.STATE.DEFAULT.
screen_1_home_img_2.set_style_radius(0, lv.PART.MAIN|lv.STATE.DEFAULT)
screen_1_home_img_2.set_style_clip_corner(True, lv.PART.MAIN|lv.STATE.DEFAULT)
screen_1_home_img_2.set_style_img_opa(255, lv.PART.MAIN|lv.STATE.DEFAULT)

# Create screen_1_home_img_3
screen_1_home_img_3 = lv.img(screen_1_home)
screen_1_home_img_3.set_src("B:MicroPython/_watchdight3_alpha_61x68.bin")
screen_1_home_img_3.add_flag(lv.obj.FLAG.CLICKABLE)
screen_1_home_img_3.set_pivot(50,50)
screen_1_home_img_3.set_angle(0)
screen_1_home_img_3.set_pos(164, 43)
screen_1_home_img_3.set_size(61, 68)
# Set style for screen_1_home_img_3, Part: lv.PART.MAIN, State: lv.STATE.DEFAULT.
screen_1_home_img_3.set_style_radius(0, lv.PART.MAIN|lv.STATE.DEFAULT)
screen_1_home_img_3.set_style_clip_corner(True, lv.PART.MAIN|lv.STATE.DEFAULT)
screen_1_home_img_3.set_style_img_opa(255, lv.PART.MAIN|lv.STATE.DEFAULT)

# Create screen_1_home_img_4
screen_1_home_img_4 = lv.img(screen_1_home)
screen_1_home_img_4.set_src("B:MicroPython/_watchdight2_alpha_51x57.bin")
screen_1_home_img_4.add_flag(lv.obj.FLAG.CLICKABLE)
screen_1_home_img_4.set_pivot(50,50)
screen_1_home_img_4.set_angle(0)
screen_1_home_img_4.set_pos(25, 188)
screen_1_home_img_4.set_size(51, 57)
# Set style for screen_1_home_img_4, Part: lv.PART.MAIN, State: lv.STATE.DEFAULT.
screen_1_home_img_4.set_style_img_opa(255, lv.PART.MAIN|lv.STATE.DEFAULT)
screen_1_home_img_4.set_style_radius(0, lv.PART.MAIN|lv.STATE.DEFAULT)
screen_1_home_img_4.set_style_clip_corner(True, lv.PART.MAIN|lv.STATE.DEFAULT)

# Create screen_1_home_img_5
screen_1_home_img_5 = lv.img(screen_1_home)
screen_1_home_img_5.set_src("B:MicroPython/_watchdight1_alpha_56x59.bin")
screen_1_home_img_5.add_flag(lv.obj.FLAG.CLICKABLE)
screen_1_home_img_5.set_pivot(50,50)
screen_1_home_img_5.set_angle(0)
screen_1_home_img_5.set_pos(25, 43)
screen_1_home_img_5.set_size(56, 59)
# Set style for screen_1_home_img_5, Part: lv.PART.MAIN, State: lv.STATE.DEFAULT.
screen_1_home_img_5.set_style_radius(0, lv.PART.MAIN|lv.STATE.DEFAULT)
screen_1_home_img_5.set_style_clip_corner(True, lv.PART.MAIN|lv.STATE.DEFAULT)
screen_1_home_img_5.set_style_img_opa(255, lv.PART.MAIN|lv.STATE.DEFAULT)

# Create screen_1_home_cont_slide
screen_1_home_cont_slide = lv.obj(screen_1_home)
screen_1_home_cont_slide.set_pos(-136, 0)
screen_1_home_cont_slide.set_size(120, 280)
screen_1_home_cont_slide.set_scrollbar_mode(lv.SCROLLBAR_MODE.OFF)
# Set style for screen_1_home_cont_slide, Part: lv.PART.MAIN, State: lv.STATE.DEFAULT.
screen_1_home_cont_slide.set_style_radius(0, lv.PART.MAIN|lv.STATE.DEFAULT)
screen_1_home_cont_slide.set_style_bg_opa(255, lv.PART.MAIN|lv.STATE.DEFAULT)
screen_1_home_cont_slide.set_style_bg_color(lv.color_hex(0x000000), lv.PART.MAIN|lv.STATE.DEFAULT)
screen_1_home_cont_slide.set_style_bg_grad_dir(lv.GRAD_DIR.NONE, lv.PART.MAIN|lv.STATE.DEFAULT)
screen_1_home_cont_slide.set_style_border_width(2, lv.PART.MAIN|lv.STATE.DEFAULT)
screen_1_home_cont_slide.set_style_border_opa(255, lv.PART.MAIN|lv.STATE.DEFAULT)
screen_1_home_cont_slide.set_style_border_color(lv.color_hex(0x000000), lv.PART.MAIN|lv.STATE.DEFAULT)
screen_1_home_cont_slide.set_style_border_side(lv.BORDER_SIDE.FULL, lv.PART.MAIN|lv.STATE.DEFAULT)
screen_1_home_cont_slide.set_style_shadow_width(0, lv.PART.MAIN|lv.STATE.DEFAULT)
screen_1_home_cont_slide.set_style_pad_top(0, lv.PART.MAIN|lv.STATE.DEFAULT)
screen_1_home_cont_slide.set_style_pad_bottom(0, lv.PART.MAIN|lv.STATE.DEFAULT)
screen_1_home_cont_slide.set_style_pad_left(0, lv.PART.MAIN|lv.STATE.DEFAULT)
screen_1_home_cont_slide.set_style_pad_right(0, lv.PART.MAIN|lv.STATE.DEFAULT)
# Create screen_1_home_btn_3
screen_1_home_btn_3 = lv.btn(screen_1_home_cont_slide)
screen_1_home_btn_3_label = lv.label(screen_1_home_btn_3)
screen_1_home_btn_3_label.set_text(" ")
screen_1_home_btn_3_label.set_long_mode(lv.label.LONG.WRAP)
screen_1_home_btn_3_label.set_width(lv.pct(100))
screen_1_home_btn_3_label.align(lv.ALIGN.CENTER, 0, 0)
screen_1_home_btn_3.set_style_pad_all(0, lv.STATE.DEFAULT)
screen_1_home_btn_3.set_pos(61, 202)
screen_1_home_btn_3.set_size(50, 50)
# Set style for screen_1_home_btn_3, Part: lv.PART.MAIN, State: lv.STATE.DEFAULT.
screen_1_home_btn_3.set_style_radius(5, lv.PART.MAIN|lv.STATE.DEFAULT)
screen_1_home_btn_3.set_style_bg_opa(255, lv.PART.MAIN|lv.STATE.DEFAULT)
screen_1_home_btn_3.set_style_bg_color(lv.color_hex(0x5a5a5a), lv.PART.MAIN|lv.STATE.DEFAULT)
screen_1_home_btn_3.set_style_bg_grad_dir(lv.GRAD_DIR.NONE, lv.PART.MAIN|lv.STATE.DEFAULT)
screen_1_home_btn_3.set_style_border_width(0, lv.PART.MAIN|lv.STATE.DEFAULT)
screen_1_home_btn_3.set_style_shadow_width(0, lv.PART.MAIN|lv.STATE.DEFAULT)
screen_1_home_btn_3.set_style_text_color(lv.color_hex(0xffffff), lv.PART.MAIN|lv.STATE.DEFAULT)
screen_1_home_btn_3.set_style_text_font(test_font("montserratMedium", 16), lv.PART.MAIN|lv.STATE.DEFAULT)
screen_1_home_btn_3.set_style_text_opa(255, lv.PART.MAIN|lv.STATE.DEFAULT)
screen_1_home_btn_3.set_style_text_align(lv.TEXT_ALIGN.CENTER, lv.PART.MAIN|lv.STATE.DEFAULT)

# Create screen_1_home_btn_2
screen_1_home_btn_2 = lv.btn(screen_1_home_cont_slide)
screen_1_home_btn_2_label = lv.label(screen_1_home_btn_2)
screen_1_home_btn_2_label.set_text(" ")
screen_1_home_btn_2_label.set_long_mode(lv.label.LONG.WRAP)
screen_1_home_btn_2_label.set_width(lv.pct(100))
screen_1_home_btn_2_label.align(lv.ALIGN.CENTER, 0, 0)
screen_1_home_btn_2.set_style_pad_all(0, lv.STATE.DEFAULT)
screen_1_home_btn_2.set_pos(10, 143)
screen_1_home_btn_2.set_size(100, 50)
# Set style for screen_1_home_btn_2, Part: lv.PART.MAIN, State: lv.STATE.DEFAULT.
screen_1_home_btn_2.set_style_radius(5, lv.PART.MAIN|lv.STATE.DEFAULT)
screen_1_home_btn_2.set_style_bg_opa(255, lv.PART.MAIN|lv.STATE.DEFAULT)
screen_1_home_btn_2.set_style_bg_color(lv.color_hex(0x5a5a5a), lv.PART.MAIN|lv.STATE.DEFAULT)
screen_1_home_btn_2.set_style_bg_grad_dir(lv.GRAD_DIR.NONE, lv.PART.MAIN|lv.STATE.DEFAULT)
screen_1_home_btn_2.set_style_border_width(0, lv.PART.MAIN|lv.STATE.DEFAULT)
screen_1_home_btn_2.set_style_shadow_width(0, lv.PART.MAIN|lv.STATE.DEFAULT)
screen_1_home_btn_2.set_style_text_color(lv.color_hex(0xffffff), lv.PART.MAIN|lv.STATE.DEFAULT)
screen_1_home_btn_2.set_style_text_font(test_font("montserratMedium", 16), lv.PART.MAIN|lv.STATE.DEFAULT)
screen_1_home_btn_2.set_style_text_opa(255, lv.PART.MAIN|lv.STATE.DEFAULT)
screen_1_home_btn_2.set_style_text_align(lv.TEXT_ALIGN.CENTER, lv.PART.MAIN|lv.STATE.DEFAULT)

# Create screen_1_home_btn_1
screen_1_home_btn_1 = lv.btn(screen_1_home_cont_slide)
screen_1_home_btn_1_label = lv.label(screen_1_home_btn_1)
screen_1_home_btn_1_label.set_text(" ")
screen_1_home_btn_1_label.set_long_mode(lv.label.LONG.WRAP)
screen_1_home_btn_1_label.set_width(lv.pct(100))
screen_1_home_btn_1_label.align(lv.ALIGN.CENTER, 0, 0)
screen_1_home_btn_1.set_style_pad_all(0, lv.STATE.DEFAULT)
screen_1_home_btn_1.set_pos(7, 202)
screen_1_home_btn_1.set_size(50, 50)
# Set style for screen_1_home_btn_1, Part: lv.PART.MAIN, State: lv.STATE.DEFAULT.
screen_1_home_btn_1.set_style_radius(5, lv.PART.MAIN|lv.STATE.DEFAULT)
screen_1_home_btn_1.set_style_bg_opa(255, lv.PART.MAIN|lv.STATE.DEFAULT)
screen_1_home_btn_1.set_style_bg_color(lv.color_hex(0x5a5a5a), lv.PART.MAIN|lv.STATE.DEFAULT)
screen_1_home_btn_1.set_style_bg_grad_dir(lv.GRAD_DIR.NONE, lv.PART.MAIN|lv.STATE.DEFAULT)
screen_1_home_btn_1.set_style_border_width(0, lv.PART.MAIN|lv.STATE.DEFAULT)
screen_1_home_btn_1.set_style_shadow_width(0, lv.PART.MAIN|lv.STATE.DEFAULT)
screen_1_home_btn_1.set_style_text_color(lv.color_hex(0xffffff), lv.PART.MAIN|lv.STATE.DEFAULT)
screen_1_home_btn_1.set_style_text_font(test_font("montserratMedium", 16), lv.PART.MAIN|lv.STATE.DEFAULT)
screen_1_home_btn_1.set_style_text_opa(255, lv.PART.MAIN|lv.STATE.DEFAULT)
screen_1_home_btn_1.set_style_text_align(lv.TEXT_ALIGN.CENTER, lv.PART.MAIN|lv.STATE.DEFAULT)

# Create screen_1_home_img_8
screen_1_home_img_8 = lv.img(screen_1_home_cont_slide)
screen_1_home_img_8.set_src("B:MicroPython/_zhengdong_0_alpha_30x30.bin")
screen_1_home_img_8.add_flag(lv.obj.FLAG.CLICKABLE)
screen_1_home_img_8.set_pivot(50,50)
screen_1_home_img_8.set_angle(0)
screen_1_home_img_8.set_pos(72, 211)
screen_1_home_img_8.set_size(30, 30)
# Set style for screen_1_home_img_8, Part: lv.PART.MAIN, State: lv.STATE.DEFAULT.
screen_1_home_img_8.set_style_img_opa(255, lv.PART.MAIN|lv.STATE.DEFAULT)
screen_1_home_img_8.set_style_radius(0, lv.PART.MAIN|lv.STATE.DEFAULT)
screen_1_home_img_8.set_style_clip_corner(True, lv.PART.MAIN|lv.STATE.DEFAULT)

# Create screen_1_home_img_10
screen_1_home_img_10 = lv.img(screen_1_home_cont_slide)
screen_1_home_img_10.set_src("B:MicroPython/_mianti_0_alpha_30x30.bin")
screen_1_home_img_10.add_flag(lv.obj.FLAG.CLICKABLE)
screen_1_home_img_10.set_pivot(50,50)
screen_1_home_img_10.set_angle(0)
screen_1_home_img_10.set_pos(18, 211)
screen_1_home_img_10.set_size(30, 30)
# Set style for screen_1_home_img_10, Part: lv.PART.MAIN, State: lv.STATE.DEFAULT.
screen_1_home_img_10.set_style_radius(0, lv.PART.MAIN|lv.STATE.DEFAULT)
screen_1_home_img_10.set_style_clip_corner(True, lv.PART.MAIN|lv.STATE.DEFAULT)
screen_1_home_img_10.set_style_img_opa(255, lv.PART.MAIN|lv.STATE.DEFAULT)

# Create screen_1_home_img_9
screen_1_home_img_9 = lv.img(screen_1_home_cont_slide)
screen_1_home_img_9.set_src("B:MicroPython/_BT32_alpha_30x30.bin")
screen_1_home_img_9.add_flag(lv.obj.FLAG.CLICKABLE)
screen_1_home_img_9.set_pivot(50,50)
screen_1_home_img_9.set_angle(0)
screen_1_home_img_9.set_pos(45, 152)
screen_1_home_img_9.set_size(30, 30)
# Set style for screen_1_home_img_9, Part: lv.PART.MAIN, State: lv.STATE.DEFAULT.
screen_1_home_img_9.set_style_img_opa(255, lv.PART.MAIN|lv.STATE.DEFAULT)
screen_1_home_img_9.set_style_radius(0, lv.PART.MAIN|lv.STATE.DEFAULT)
screen_1_home_img_9.set_style_clip_corner(True, lv.PART.MAIN|lv.STATE.DEFAULT)

# Create screen_1_home_img_7
screen_1_home_img_7 = lv.img(screen_1_home_cont_slide)
screen_1_home_img_7.set_src("B:MicroPython/_copesss_alpha_30x30.bin")
screen_1_home_img_7.add_flag(lv.obj.FLAG.CLICKABLE)
screen_1_home_img_7.set_pivot(50,50)
screen_1_home_img_7.set_angle(0)
screen_1_home_img_7.set_pos(9, 84)
screen_1_home_img_7.set_size(30, 30)
# Set style for screen_1_home_img_7, Part: lv.PART.MAIN, State: lv.STATE.DEFAULT.
screen_1_home_img_7.set_style_img_opa(255, lv.PART.MAIN|lv.STATE.DEFAULT)
screen_1_home_img_7.set_style_radius(0, lv.PART.MAIN|lv.STATE.DEFAULT)
screen_1_home_img_7.set_style_clip_corner(True, lv.PART.MAIN|lv.STATE.DEFAULT)

# Create screen_1_home_img_6
screen_1_home_img_6 = lv.img(screen_1_home_cont_slide)
screen_1_home_img_6.set_src("B:MicroPython/_weater32x32_alpha_30x30.bin")
screen_1_home_img_6.add_flag(lv.obj.FLAG.CLICKABLE)
screen_1_home_img_6.set_pivot(50,50)
screen_1_home_img_6.set_angle(0)
screen_1_home_img_6.set_pos(6, 34)
screen_1_home_img_6.set_size(30, 30)
# Set style for screen_1_home_img_6, Part: lv.PART.MAIN, State: lv.STATE.DEFAULT.
screen_1_home_img_6.set_style_radius(0, lv.PART.MAIN|lv.STATE.DEFAULT)
screen_1_home_img_6.set_style_clip_corner(True, lv.PART.MAIN|lv.STATE.DEFAULT)
screen_1_home_img_6.set_style_img_opa(255, lv.PART.MAIN|lv.STATE.DEFAULT)

# Create screen_1_home_label_1
screen_1_home_label_1 = lv.label(screen_1_home_cont_slide)
screen_1_home_label_1.set_text("38")
screen_1_home_label_1.set_long_mode(lv.label.LONG.WRAP)
screen_1_home_label_1.set_width(lv.pct(100))
screen_1_home_label_1.set_pos(44, 92)
screen_1_home_label_1.set_size(68, 17)
# Set style for screen_1_home_label_1, Part: lv.PART.MAIN, State: lv.STATE.DEFAULT.
screen_1_home_label_1.set_style_radius(0, lv.PART.MAIN|lv.STATE.DEFAULT)
screen_1_home_label_1.set_style_border_width(0, lv.PART.MAIN|lv.STATE.DEFAULT)
screen_1_home_label_1.set_style_bg_opa(0, lv.PART.MAIN|lv.STATE.DEFAULT)
screen_1_home_label_1.set_style_pad_top(0, lv.PART.MAIN|lv.STATE.DEFAULT)
screen_1_home_label_1.set_style_pad_right(0, lv.PART.MAIN|lv.STATE.DEFAULT)
screen_1_home_label_1.set_style_pad_bottom(0, lv.PART.MAIN|lv.STATE.DEFAULT)
screen_1_home_label_1.set_style_pad_left(0, lv.PART.MAIN|lv.STATE.DEFAULT)
screen_1_home_label_1.set_style_shadow_width(0, lv.PART.MAIN|lv.STATE.DEFAULT)
screen_1_home_label_1.set_style_text_color(lv.color_hex(0xffffff), lv.PART.MAIN|lv.STATE.DEFAULT)
screen_1_home_label_1.set_style_text_font(test_font("montserratMedium", 16), lv.PART.MAIN|lv.STATE.DEFAULT)
screen_1_home_label_1.set_style_text_opa(255, lv.PART.MAIN|lv.STATE.DEFAULT)
screen_1_home_label_1.set_style_text_letter_space(0, lv.PART.MAIN|lv.STATE.DEFAULT)
screen_1_home_label_1.set_style_text_line_space(0, lv.PART.MAIN|lv.STATE.DEFAULT)
screen_1_home_label_1.set_style_text_align(lv.TEXT_ALIGN.CENTER, lv.PART.MAIN|lv.STATE.DEFAULT)

# Create screen_1_home_label_2
screen_1_home_label_2 = lv.label(screen_1_home_cont_slide)
screen_1_home_label_2.set_text("天气")
screen_1_home_label_2.set_long_mode(lv.label.LONG.WRAP)
screen_1_home_label_2.set_width(lv.pct(100))
screen_1_home_label_2.set_pos(39, 43)
screen_1_home_label_2.set_size(68, 17)
# Set style for screen_1_home_label_2, Part: lv.PART.MAIN, State: lv.STATE.DEFAULT.
screen_1_home_label_2.set_style_radius(0, lv.PART.MAIN|lv.STATE.DEFAULT)
screen_1_home_label_2.set_style_border_width(0, lv.PART.MAIN|lv.STATE.DEFAULT)
screen_1_home_label_2.set_style_bg_opa(0, lv.PART.MAIN|lv.STATE.DEFAULT)
screen_1_home_label_2.set_style_pad_top(0, lv.PART.MAIN|lv.STATE.DEFAULT)
screen_1_home_label_2.set_style_pad_bottom(0, lv.PART.MAIN|lv.STATE.DEFAULT)
screen_1_home_label_2.set_style_pad_left(0, lv.PART.MAIN|lv.STATE.DEFAULT)
screen_1_home_label_2.set_style_pad_right(0, lv.PART.MAIN|lv.STATE.DEFAULT)
screen_1_home_label_2.set_style_shadow_width(0, lv.PART.MAIN|lv.STATE.DEFAULT)
screen_1_home_label_2.set_style_text_color(lv.color_hex(0xffffff), lv.PART.MAIN|lv.STATE.DEFAULT)
screen_1_home_label_2.set_style_text_font(test_font("montserratMedium", 16), lv.PART.MAIN|lv.STATE.DEFAULT)
screen_1_home_label_2.set_style_text_opa(255, lv.PART.MAIN|lv.STATE.DEFAULT)
screen_1_home_label_2.set_style_text_letter_space(0, lv.PART.MAIN|lv.STATE.DEFAULT)
screen_1_home_label_2.set_style_text_line_space(0, lv.PART.MAIN|lv.STATE.DEFAULT)
screen_1_home_label_2.set_style_text_align(lv.TEXT_ALIGN.CENTER, lv.PART.MAIN|lv.STATE.DEFAULT)

# Create screen_1_home_cont_shadow
screen_1_home_cont_shadow = lv.obj(screen_1_home)
screen_1_home_cont_shadow.set_pos(0, 0)
screen_1_home_cont_shadow.set_size(240, 280)
screen_1_home_cont_shadow.set_scrollbar_mode(lv.SCROLLBAR_MODE.OFF)
screen_1_home_cont_shadow.add_flag(lv.obj.FLAG.HIDDEN)
# Set style for screen_1_home_cont_shadow, Part: lv.PART.MAIN, State: lv.STATE.DEFAULT.
screen_1_home_cont_shadow.set_style_border_width(2, lv.PART.MAIN|lv.STATE.DEFAULT)
screen_1_home_cont_shadow.set_style_border_opa(255, lv.PART.MAIN|lv.STATE.DEFAULT)
screen_1_home_cont_shadow.set_style_border_color(lv.color_hex(0x000000), lv.PART.MAIN|lv.STATE.DEFAULT)
screen_1_home_cont_shadow.set_style_border_side(lv.BORDER_SIDE.FULL, lv.PART.MAIN|lv.STATE.DEFAULT)
screen_1_home_cont_shadow.set_style_radius(0, lv.PART.MAIN|lv.STATE.DEFAULT)
screen_1_home_cont_shadow.set_style_bg_opa(123, lv.PART.MAIN|lv.STATE.DEFAULT)
screen_1_home_cont_shadow.set_style_bg_color(lv.color_hex(0x000000), lv.PART.MAIN|lv.STATE.DEFAULT)
screen_1_home_cont_shadow.set_style_bg_grad_dir(lv.GRAD_DIR.NONE, lv.PART.MAIN|lv.STATE.DEFAULT)
screen_1_home_cont_shadow.set_style_pad_top(0, lv.PART.MAIN|lv.STATE.DEFAULT)
screen_1_home_cont_shadow.set_style_pad_right(0, lv.PART.MAIN|lv.STATE.DEFAULT)
screen_1_home_cont_shadow.set_style_pad_bottom(0, lv.PART.MAIN|lv.STATE.DEFAULT)
screen_1_home_cont_shadow.set_style_pad_left(0, lv.PART.MAIN|lv.STATE.DEFAULT)
screen_1_home_cont_shadow.set_style_shadow_width(0, lv.PART.MAIN|lv.STATE.DEFAULT)

screen_1_home.update_layout()
# Create screen_2
screen_2 = lv.obj()
screen_2.set_size(240, 280)
screen_2.set_scrollbar_mode(lv.SCROLLBAR_MODE.OFF)
# Set style for screen_2, Part: lv.PART.MAIN, State: lv.STATE.DEFAULT.
screen_2.set_style_bg_opa(255, lv.PART.MAIN|lv.STATE.DEFAULT)
screen_2.set_style_bg_color(lv.color_hex(0xda0808), lv.PART.MAIN|lv.STATE.DEFAULT)
screen_2.set_style_bg_grad_dir(lv.GRAD_DIR.NONE, lv.PART.MAIN|lv.STATE.DEFAULT)

# Create screen_2_img_1
screen_2_img_1 = lv.img(screen_2)
screen_2_img_1.set_src("B:MicroPython/_MDLBG_alpha_179x220.bin")
screen_2_img_1.add_flag(lv.obj.FLAG.CLICKABLE)
screen_2_img_1.set_pivot(50,50)
screen_2_img_1.set_angle(0)
screen_2_img_1.set_pos(52, 19)
screen_2_img_1.set_size(179, 220)
# Set style for screen_2_img_1, Part: lv.PART.MAIN, State: lv.STATE.DEFAULT.
screen_2_img_1.set_style_radius(0, lv.PART.MAIN|lv.STATE.DEFAULT)
screen_2_img_1.set_style_clip_corner(True, lv.PART.MAIN|lv.STATE.DEFAULT)
screen_2_img_1.set_style_img_opa(255, lv.PART.MAIN|lv.STATE.DEFAULT)

# Create screen_2_digital_clock_1
screen_2_digital_clock_1_time = [int(11), int(25), int(50), ""]
screen_2_digital_clock_1 = lv.dclock(screen_2, "11:25:50")
screen_2_digital_clock_1_timer = lv.timer_create_basic()
screen_2_digital_clock_1_timer.set_period(1000)
screen_2_digital_clock_1_timer.set_cb(lambda src: digital_clock_cb(screen_2_digital_clock_1_timer, screen_2_digital_clock_1, screen_2_digital_clock_1_time, True, False ))
screen_2_digital_clock_1.set_pos(124, 81)
screen_2_digital_clock_1.set_size(106, 36)
# Set style for screen_2_digital_clock_1, Part: lv.PART.MAIN, State: lv.STATE.DEFAULT.
screen_2_digital_clock_1.set_style_radius(0, lv.PART.MAIN|lv.STATE.DEFAULT)
screen_2_digital_clock_1.set_style_text_color(lv.color_hex(0xf00000), lv.PART.MAIN|lv.STATE.DEFAULT)
screen_2_digital_clock_1.set_style_text_font(test_font("montserratMedium", 25), lv.PART.MAIN|lv.STATE.DEFAULT)
screen_2_digital_clock_1.set_style_text_opa(255, lv.PART.MAIN|lv.STATE.DEFAULT)
screen_2_digital_clock_1.set_style_text_letter_space(0, lv.PART.MAIN|lv.STATE.DEFAULT)
screen_2_digital_clock_1.set_style_text_align(lv.TEXT_ALIGN.CENTER, lv.PART.MAIN|lv.STATE.DEFAULT)
screen_2_digital_clock_1.set_style_bg_opa(255, lv.PART.MAIN|lv.STATE.DEFAULT)
screen_2_digital_clock_1.set_style_bg_color(lv.color_hex(0xffbf00), lv.PART.MAIN|lv.STATE.DEFAULT)
screen_2_digital_clock_1.set_style_bg_grad_dir(lv.GRAD_DIR.NONE, lv.PART.MAIN|lv.STATE.DEFAULT)
screen_2_digital_clock_1.set_style_pad_top(7, lv.PART.MAIN|lv.STATE.DEFAULT)
screen_2_digital_clock_1.set_style_pad_right(0, lv.PART.MAIN|lv.STATE.DEFAULT)
screen_2_digital_clock_1.set_style_pad_bottom(0, lv.PART.MAIN|lv.STATE.DEFAULT)
screen_2_digital_clock_1.set_style_pad_left(0, lv.PART.MAIN|lv.STATE.DEFAULT)
screen_2_digital_clock_1.set_style_shadow_width(0, lv.PART.MAIN|lv.STATE.DEFAULT)

# Create screen_2_datetext_1
screen_2_datetext_1 = lv.label(screen_2)
screen_2_datetext_1.set_text("2023/07/31")
screen_2_datetext_1.set_style_text_align(lv.TEXT_ALIGN.CENTER, 0)
screen_2_datetext_1.add_flag(lv.obj.FLAG.CLICKABLE)
screen_2_datetext_1_calendar = None
screen_2_datetext_1.add_event_cb(lambda e: datetext_event_handler(e, screen_2_datetext_1_calendar), lv.EVENT.ALL, None)
screen_2_datetext_1.set_pos(117, 44)
screen_2_datetext_1.set_size(110, 26)
# Set style for screen_2_datetext_1, Part: lv.PART.MAIN, State: lv.STATE.DEFAULT.
screen_2_datetext_1.set_style_text_color(lv.color_hex(0xffffff), lv.PART.MAIN|lv.STATE.DEFAULT)
screen_2_datetext_1.set_style_text_font(test_font("montserratMedium", 16), lv.PART.MAIN|lv.STATE.DEFAULT)
screen_2_datetext_1.set_style_text_opa(255, lv.PART.MAIN|lv.STATE.DEFAULT)
screen_2_datetext_1.set_style_text_letter_space(2, lv.PART.MAIN|lv.STATE.DEFAULT)
screen_2_datetext_1.set_style_text_align(lv.TEXT_ALIGN.CENTER, lv.PART.MAIN|lv.STATE.DEFAULT)
screen_2_datetext_1.set_style_bg_opa(255, lv.PART.MAIN|lv.STATE.DEFAULT)
screen_2_datetext_1.set_style_bg_color(lv.color_hex(0xffbf00), lv.PART.MAIN|lv.STATE.DEFAULT)
screen_2_datetext_1.set_style_bg_grad_dir(lv.GRAD_DIR.NONE, lv.PART.MAIN|lv.STATE.DEFAULT)
screen_2_datetext_1.set_style_radius(0, lv.PART.MAIN|lv.STATE.DEFAULT)
screen_2_datetext_1.set_style_pad_top(7, lv.PART.MAIN|lv.STATE.DEFAULT)
screen_2_datetext_1.set_style_pad_right(0, lv.PART.MAIN|lv.STATE.DEFAULT)
screen_2_datetext_1.set_style_pad_left(0, lv.PART.MAIN|lv.STATE.DEFAULT)
screen_2_datetext_1.set_style_shadow_width(0, lv.PART.MAIN|lv.STATE.DEFAULT)
screen_2_datetext_1.set_style_border_width(0, lv.PART.MAIN|lv.STATE.DEFAULT)

# Create screen_2_cont_3
screen_2_cont_3 = lv.obj(screen_2)
screen_2_cont_3.set_pos(-136, 0)
screen_2_cont_3.set_size(120, 280)
screen_2_cont_3.set_scrollbar_mode(lv.SCROLLBAR_MODE.OFF)
# Set style for screen_2_cont_3, Part: lv.PART.MAIN, State: lv.STATE.DEFAULT.
screen_2_cont_3.set_style_radius(0, lv.PART.MAIN|lv.STATE.DEFAULT)
screen_2_cont_3.set_style_bg_opa(255, lv.PART.MAIN|lv.STATE.DEFAULT)
screen_2_cont_3.set_style_bg_color(lv.color_hex(0x000000), lv.PART.MAIN|lv.STATE.DEFAULT)
screen_2_cont_3.set_style_bg_grad_dir(lv.GRAD_DIR.NONE, lv.PART.MAIN|lv.STATE.DEFAULT)
screen_2_cont_3.set_style_border_width(2, lv.PART.MAIN|lv.STATE.DEFAULT)
screen_2_cont_3.set_style_border_opa(255, lv.PART.MAIN|lv.STATE.DEFAULT)
screen_2_cont_3.set_style_border_color(lv.color_hex(0x000000), lv.PART.MAIN|lv.STATE.DEFAULT)
screen_2_cont_3.set_style_border_side(lv.BORDER_SIDE.FULL, lv.PART.MAIN|lv.STATE.DEFAULT)
screen_2_cont_3.set_style_shadow_width(0, lv.PART.MAIN|lv.STATE.DEFAULT)
screen_2_cont_3.set_style_pad_top(0, lv.PART.MAIN|lv.STATE.DEFAULT)
screen_2_cont_3.set_style_pad_left(0, lv.PART.MAIN|lv.STATE.DEFAULT)
screen_2_cont_3.set_style_pad_right(0, lv.PART.MAIN|lv.STATE.DEFAULT)
screen_2_cont_3.set_style_pad_bottom(0, lv.PART.MAIN|lv.STATE.DEFAULT)
# Create screen_2_btn_3
screen_2_btn_3 = lv.btn(screen_2_cont_3)
screen_2_btn_3_label = lv.label(screen_2_btn_3)
screen_2_btn_3_label.set_text(" ")
screen_2_btn_3_label.set_long_mode(lv.label.LONG.WRAP)
screen_2_btn_3_label.set_width(lv.pct(100))
screen_2_btn_3_label.align(lv.ALIGN.CENTER, 0, 0)
screen_2_btn_3.set_style_pad_all(0, lv.STATE.DEFAULT)
screen_2_btn_3.set_pos(61, 202)
screen_2_btn_3.set_size(50, 50)
# Set style for screen_2_btn_3, Part: lv.PART.MAIN, State: lv.STATE.DEFAULT.
screen_2_btn_3.set_style_radius(5, lv.PART.MAIN|lv.STATE.DEFAULT)
screen_2_btn_3.set_style_bg_opa(255, lv.PART.MAIN|lv.STATE.DEFAULT)
screen_2_btn_3.set_style_bg_color(lv.color_hex(0x5a5a5a), lv.PART.MAIN|lv.STATE.DEFAULT)
screen_2_btn_3.set_style_bg_grad_dir(lv.GRAD_DIR.NONE, lv.PART.MAIN|lv.STATE.DEFAULT)
screen_2_btn_3.set_style_border_width(0, lv.PART.MAIN|lv.STATE.DEFAULT)
screen_2_btn_3.set_style_shadow_width(0, lv.PART.MAIN|lv.STATE.DEFAULT)
screen_2_btn_3.set_style_text_color(lv.color_hex(0xffffff), lv.PART.MAIN|lv.STATE.DEFAULT)
screen_2_btn_3.set_style_text_font(test_font("montserratMedium", 16), lv.PART.MAIN|lv.STATE.DEFAULT)
screen_2_btn_3.set_style_text_opa(255, lv.PART.MAIN|lv.STATE.DEFAULT)
screen_2_btn_3.set_style_text_align(lv.TEXT_ALIGN.CENTER, lv.PART.MAIN|lv.STATE.DEFAULT)

# Create screen_2_btn_2
screen_2_btn_2 = lv.btn(screen_2_cont_3)
screen_2_btn_2_label = lv.label(screen_2_btn_2)
screen_2_btn_2_label.set_text(" ")
screen_2_btn_2_label.set_long_mode(lv.label.LONG.WRAP)
screen_2_btn_2_label.set_width(lv.pct(100))
screen_2_btn_2_label.align(lv.ALIGN.CENTER, 0, 0)
screen_2_btn_2.set_style_pad_all(0, lv.STATE.DEFAULT)
screen_2_btn_2.set_pos(10, 143)
screen_2_btn_2.set_size(100, 50)
# Set style for screen_2_btn_2, Part: lv.PART.MAIN, State: lv.STATE.DEFAULT.
screen_2_btn_2.set_style_radius(5, lv.PART.MAIN|lv.STATE.DEFAULT)
screen_2_btn_2.set_style_bg_opa(255, lv.PART.MAIN|lv.STATE.DEFAULT)
screen_2_btn_2.set_style_bg_color(lv.color_hex(0x5a5a5a), lv.PART.MAIN|lv.STATE.DEFAULT)
screen_2_btn_2.set_style_bg_grad_dir(lv.GRAD_DIR.NONE, lv.PART.MAIN|lv.STATE.DEFAULT)
screen_2_btn_2.set_style_border_width(0, lv.PART.MAIN|lv.STATE.DEFAULT)
screen_2_btn_2.set_style_shadow_width(0, lv.PART.MAIN|lv.STATE.DEFAULT)
screen_2_btn_2.set_style_text_color(lv.color_hex(0xffffff), lv.PART.MAIN|lv.STATE.DEFAULT)
screen_2_btn_2.set_style_text_font(test_font("montserratMedium", 16), lv.PART.MAIN|lv.STATE.DEFAULT)
screen_2_btn_2.set_style_text_opa(255, lv.PART.MAIN|lv.STATE.DEFAULT)
screen_2_btn_2.set_style_text_align(lv.TEXT_ALIGN.CENTER, lv.PART.MAIN|lv.STATE.DEFAULT)

# Create screen_2_btn_1
screen_2_btn_1 = lv.btn(screen_2_cont_3)
screen_2_btn_1_label = lv.label(screen_2_btn_1)
screen_2_btn_1_label.set_text(" ")
screen_2_btn_1_label.set_long_mode(lv.label.LONG.WRAP)
screen_2_btn_1_label.set_width(lv.pct(100))
screen_2_btn_1_label.align(lv.ALIGN.CENTER, 0, 0)
screen_2_btn_1.set_style_pad_all(0, lv.STATE.DEFAULT)
screen_2_btn_1.set_pos(7, 202)
screen_2_btn_1.set_size(50, 50)
# Set style for screen_2_btn_1, Part: lv.PART.MAIN, State: lv.STATE.DEFAULT.
screen_2_btn_1.set_style_radius(5, lv.PART.MAIN|lv.STATE.DEFAULT)
screen_2_btn_1.set_style_bg_opa(255, lv.PART.MAIN|lv.STATE.DEFAULT)
screen_2_btn_1.set_style_bg_color(lv.color_hex(0x5a5a5a), lv.PART.MAIN|lv.STATE.DEFAULT)
screen_2_btn_1.set_style_bg_grad_dir(lv.GRAD_DIR.NONE, lv.PART.MAIN|lv.STATE.DEFAULT)
screen_2_btn_1.set_style_border_width(0, lv.PART.MAIN|lv.STATE.DEFAULT)
screen_2_btn_1.set_style_shadow_width(0, lv.PART.MAIN|lv.STATE.DEFAULT)
screen_2_btn_1.set_style_text_color(lv.color_hex(0xffffff), lv.PART.MAIN|lv.STATE.DEFAULT)
screen_2_btn_1.set_style_text_font(test_font("montserratMedium", 16), lv.PART.MAIN|lv.STATE.DEFAULT)
screen_2_btn_1.set_style_text_opa(255, lv.PART.MAIN|lv.STATE.DEFAULT)
screen_2_btn_1.set_style_text_align(lv.TEXT_ALIGN.CENTER, lv.PART.MAIN|lv.STATE.DEFAULT)

# Create screen_2_img_6
screen_2_img_6 = lv.img(screen_2_cont_3)
screen_2_img_6.set_src("B:MicroPython/_zhengdong_0_alpha_30x30.bin")
screen_2_img_6.add_flag(lv.obj.FLAG.CLICKABLE)
screen_2_img_6.set_pivot(50,50)
screen_2_img_6.set_angle(0)
screen_2_img_6.set_pos(72, 211)
screen_2_img_6.set_size(30, 30)
# Set style for screen_2_img_6, Part: lv.PART.MAIN, State: lv.STATE.DEFAULT.
screen_2_img_6.set_style_img_opa(255, lv.PART.MAIN|lv.STATE.DEFAULT)
screen_2_img_6.set_style_radius(0, lv.PART.MAIN|lv.STATE.DEFAULT)
screen_2_img_6.set_style_clip_corner(True, lv.PART.MAIN|lv.STATE.DEFAULT)

# Create screen_2_img_5
screen_2_img_5 = lv.img(screen_2_cont_3)
screen_2_img_5.set_src("B:MicroPython/_mianti_0_alpha_30x30.bin")
screen_2_img_5.add_flag(lv.obj.FLAG.CLICKABLE)
screen_2_img_5.set_pivot(50,50)
screen_2_img_5.set_angle(0)
screen_2_img_5.set_pos(18, 211)
screen_2_img_5.set_size(30, 30)
# Set style for screen_2_img_5, Part: lv.PART.MAIN, State: lv.STATE.DEFAULT.
screen_2_img_5.set_style_radius(0, lv.PART.MAIN|lv.STATE.DEFAULT)
screen_2_img_5.set_style_clip_corner(True, lv.PART.MAIN|lv.STATE.DEFAULT)
screen_2_img_5.set_style_img_opa(255, lv.PART.MAIN|lv.STATE.DEFAULT)

# Create screen_2_img_4
screen_2_img_4 = lv.img(screen_2_cont_3)
screen_2_img_4.set_src("B:MicroPython/_BT32_alpha_30x30.bin")
screen_2_img_4.add_flag(lv.obj.FLAG.CLICKABLE)
screen_2_img_4.set_pivot(50,50)
screen_2_img_4.set_angle(0)
screen_2_img_4.set_pos(45, 152)
screen_2_img_4.set_size(30, 30)
# Set style for screen_2_img_4, Part: lv.PART.MAIN, State: lv.STATE.DEFAULT.
screen_2_img_4.set_style_img_opa(255, lv.PART.MAIN|lv.STATE.DEFAULT)
screen_2_img_4.set_style_radius(0, lv.PART.MAIN|lv.STATE.DEFAULT)
screen_2_img_4.set_style_clip_corner(True, lv.PART.MAIN|lv.STATE.DEFAULT)

# Create screen_2_img_3
screen_2_img_3 = lv.img(screen_2_cont_3)
screen_2_img_3.set_src("B:MicroPython/_copesss_alpha_30x30.bin")
screen_2_img_3.add_flag(lv.obj.FLAG.CLICKABLE)
screen_2_img_3.set_pivot(50,50)
screen_2_img_3.set_angle(0)
screen_2_img_3.set_pos(9, 84)
screen_2_img_3.set_size(30, 30)
# Set style for screen_2_img_3, Part: lv.PART.MAIN, State: lv.STATE.DEFAULT.
screen_2_img_3.set_style_img_opa(255, lv.PART.MAIN|lv.STATE.DEFAULT)
screen_2_img_3.set_style_radius(0, lv.PART.MAIN|lv.STATE.DEFAULT)
screen_2_img_3.set_style_clip_corner(True, lv.PART.MAIN|lv.STATE.DEFAULT)

# Create screen_2_img_2
screen_2_img_2 = lv.img(screen_2_cont_3)
screen_2_img_2.set_src("B:MicroPython/_weater32x32_alpha_30x30.bin")
screen_2_img_2.add_flag(lv.obj.FLAG.CLICKABLE)
screen_2_img_2.set_pivot(50,50)
screen_2_img_2.set_angle(0)
screen_2_img_2.set_pos(6, 34)
screen_2_img_2.set_size(30, 30)
# Set style for screen_2_img_2, Part: lv.PART.MAIN, State: lv.STATE.DEFAULT.
screen_2_img_2.set_style_radius(0, lv.PART.MAIN|lv.STATE.DEFAULT)
screen_2_img_2.set_style_clip_corner(True, lv.PART.MAIN|lv.STATE.DEFAULT)
screen_2_img_2.set_style_img_opa(255, lv.PART.MAIN|lv.STATE.DEFAULT)

# Create screen_2_label_2
screen_2_label_2 = lv.label(screen_2_cont_3)
screen_2_label_2.set_text("38")
screen_2_label_2.set_long_mode(lv.label.LONG.WRAP)
screen_2_label_2.set_width(lv.pct(100))
screen_2_label_2.set_pos(44, 92)
screen_2_label_2.set_size(68, 17)
# Set style for screen_2_label_2, Part: lv.PART.MAIN, State: lv.STATE.DEFAULT.
screen_2_label_2.set_style_radius(0, lv.PART.MAIN|lv.STATE.DEFAULT)
screen_2_label_2.set_style_border_width(0, lv.PART.MAIN|lv.STATE.DEFAULT)
screen_2_label_2.set_style_bg_opa(0, lv.PART.MAIN|lv.STATE.DEFAULT)
screen_2_label_2.set_style_pad_top(0, lv.PART.MAIN|lv.STATE.DEFAULT)
screen_2_label_2.set_style_pad_right(0, lv.PART.MAIN|lv.STATE.DEFAULT)
screen_2_label_2.set_style_pad_bottom(0, lv.PART.MAIN|lv.STATE.DEFAULT)
screen_2_label_2.set_style_pad_left(0, lv.PART.MAIN|lv.STATE.DEFAULT)
screen_2_label_2.set_style_shadow_width(0, lv.PART.MAIN|lv.STATE.DEFAULT)
screen_2_label_2.set_style_text_color(lv.color_hex(0xffffff), lv.PART.MAIN|lv.STATE.DEFAULT)
screen_2_label_2.set_style_text_font(test_font("montserratMedium", 16), lv.PART.MAIN|lv.STATE.DEFAULT)
screen_2_label_2.set_style_text_opa(255, lv.PART.MAIN|lv.STATE.DEFAULT)
screen_2_label_2.set_style_text_letter_space(0, lv.PART.MAIN|lv.STATE.DEFAULT)
screen_2_label_2.set_style_text_line_space(0, lv.PART.MAIN|lv.STATE.DEFAULT)
screen_2_label_2.set_style_text_align(lv.TEXT_ALIGN.CENTER, lv.PART.MAIN|lv.STATE.DEFAULT)

# Create screen_2_label_1
screen_2_label_1 = lv.label(screen_2_cont_3)
screen_2_label_1.set_text("天气")
screen_2_label_1.set_long_mode(lv.label.LONG.WRAP)
screen_2_label_1.set_width(lv.pct(100))
screen_2_label_1.set_pos(39, 43)
screen_2_label_1.set_size(68, 17)
# Set style for screen_2_label_1, Part: lv.PART.MAIN, State: lv.STATE.DEFAULT.
screen_2_label_1.set_style_radius(0, lv.PART.MAIN|lv.STATE.DEFAULT)
screen_2_label_1.set_style_border_width(0, lv.PART.MAIN|lv.STATE.DEFAULT)
screen_2_label_1.set_style_bg_opa(0, lv.PART.MAIN|lv.STATE.DEFAULT)
screen_2_label_1.set_style_pad_top(0, lv.PART.MAIN|lv.STATE.DEFAULT)
screen_2_label_1.set_style_pad_bottom(0, lv.PART.MAIN|lv.STATE.DEFAULT)
screen_2_label_1.set_style_pad_left(0, lv.PART.MAIN|lv.STATE.DEFAULT)
screen_2_label_1.set_style_pad_right(0, lv.PART.MAIN|lv.STATE.DEFAULT)
screen_2_label_1.set_style_shadow_width(0, lv.PART.MAIN|lv.STATE.DEFAULT)
screen_2_label_1.set_style_text_color(lv.color_hex(0xffffff), lv.PART.MAIN|lv.STATE.DEFAULT)
screen_2_label_1.set_style_text_font(test_font("montserratMedium", 16), lv.PART.MAIN|lv.STATE.DEFAULT)
screen_2_label_1.set_style_text_opa(255, lv.PART.MAIN|lv.STATE.DEFAULT)
screen_2_label_1.set_style_text_letter_space(0, lv.PART.MAIN|lv.STATE.DEFAULT)
screen_2_label_1.set_style_text_line_space(0, lv.PART.MAIN|lv.STATE.DEFAULT)
screen_2_label_1.set_style_text_align(lv.TEXT_ALIGN.CENTER, lv.PART.MAIN|lv.STATE.DEFAULT)

# Create screen_2_cont_4
screen_2_cont_4 = lv.obj(screen_2)
screen_2_cont_4.set_pos(-1, 0)
screen_2_cont_4.set_size(240, 280)
screen_2_cont_4.set_scrollbar_mode(lv.SCROLLBAR_MODE.OFF)
screen_2_cont_4.add_flag(lv.obj.FLAG.HIDDEN)
# Set style for screen_2_cont_4, Part: lv.PART.MAIN, State: lv.STATE.DEFAULT.
screen_2_cont_4.set_style_border_width(2, lv.PART.MAIN|lv.STATE.DEFAULT)
screen_2_cont_4.set_style_border_opa(255, lv.PART.MAIN|lv.STATE.DEFAULT)
screen_2_cont_4.set_style_border_color(lv.color_hex(0x000000), lv.PART.MAIN|lv.STATE.DEFAULT)
screen_2_cont_4.set_style_border_side(lv.BORDER_SIDE.FULL, lv.PART.MAIN|lv.STATE.DEFAULT)
screen_2_cont_4.set_style_radius(0, lv.PART.MAIN|lv.STATE.DEFAULT)
screen_2_cont_4.set_style_bg_opa(123, lv.PART.MAIN|lv.STATE.DEFAULT)
screen_2_cont_4.set_style_bg_color(lv.color_hex(0x000000), lv.PART.MAIN|lv.STATE.DEFAULT)
screen_2_cont_4.set_style_bg_grad_dir(lv.GRAD_DIR.NONE, lv.PART.MAIN|lv.STATE.DEFAULT)
screen_2_cont_4.set_style_pad_top(0, lv.PART.MAIN|lv.STATE.DEFAULT)
screen_2_cont_4.set_style_pad_right(0, lv.PART.MAIN|lv.STATE.DEFAULT)
screen_2_cont_4.set_style_pad_bottom(0, lv.PART.MAIN|lv.STATE.DEFAULT)
screen_2_cont_4.set_style_pad_left(0, lv.PART.MAIN|lv.STATE.DEFAULT)
screen_2_cont_4.set_style_shadow_width(0, lv.PART.MAIN|lv.STATE.DEFAULT)

screen_2.update_layout()
# Create screen_3
screen_3 = lv.obj()
screen_3.set_size(240, 280)
screen_3.set_scrollbar_mode(lv.SCROLLBAR_MODE.OFF)
# Set style for screen_3, Part: lv.PART.MAIN, State: lv.STATE.DEFAULT.
screen_3.set_style_bg_opa(255, lv.PART.MAIN|lv.STATE.DEFAULT)
screen_3.set_style_bg_color(lv.color_hex(0x000000), lv.PART.MAIN|lv.STATE.DEFAULT)
screen_3.set_style_bg_grad_dir(lv.GRAD_DIR.NONE, lv.PART.MAIN|lv.STATE.DEFAULT)

# Create screen_3_label_2
screen_3_label_2 = lv.label(screen_3)
screen_3_label_2.set_text("06")
screen_3_label_2.set_long_mode(lv.label.LONG.WRAP)
screen_3_label_2.set_width(lv.pct(100))
screen_3_label_2.set_pos(115, 138)
screen_3_label_2.set_size(99, 88)
# Set style for screen_3_label_2, Part: lv.PART.MAIN, State: lv.STATE.DEFAULT.
screen_3_label_2.set_style_border_width(0, lv.PART.MAIN|lv.STATE.DEFAULT)
screen_3_label_2.set_style_radius(0, lv.PART.MAIN|lv.STATE.DEFAULT)
screen_3_label_2.set_style_text_color(lv.color_hex(0xffab00), lv.PART.MAIN|lv.STATE.DEFAULT)
screen_3_label_2.set_style_text_font(test_font("interttf", 82), lv.PART.MAIN|lv.STATE.DEFAULT)
screen_3_label_2.set_style_text_opa(255, lv.PART.MAIN|lv.STATE.DEFAULT)
screen_3_label_2.set_style_text_letter_space(0, lv.PART.MAIN|lv.STATE.DEFAULT)
screen_3_label_2.set_style_text_line_space(0, lv.PART.MAIN|lv.STATE.DEFAULT)
screen_3_label_2.set_style_text_align(lv.TEXT_ALIGN.CENTER, lv.PART.MAIN|lv.STATE.DEFAULT)
screen_3_label_2.set_style_bg_opa(0, lv.PART.MAIN|lv.STATE.DEFAULT)
screen_3_label_2.set_style_pad_top(0, lv.PART.MAIN|lv.STATE.DEFAULT)
screen_3_label_2.set_style_pad_right(0, lv.PART.MAIN|lv.STATE.DEFAULT)
screen_3_label_2.set_style_pad_bottom(0, lv.PART.MAIN|lv.STATE.DEFAULT)
screen_3_label_2.set_style_pad_left(0, lv.PART.MAIN|lv.STATE.DEFAULT)
screen_3_label_2.set_style_shadow_width(0, lv.PART.MAIN|lv.STATE.DEFAULT)

# Create screen_3_label_3
screen_3_label_3 = lv.label(screen_3)
screen_3_label_3.set_text("AM     08/06")
screen_3_label_3.set_long_mode(lv.label.LONG.WRAP)
screen_3_label_3.set_width(lv.pct(100))
screen_3_label_3.set_pos(72, 230)
screen_3_label_3.set_size(155, 26)
# Set style for screen_3_label_3, Part: lv.PART.MAIN, State: lv.STATE.DEFAULT.
screen_3_label_3.set_style_border_width(0, lv.PART.MAIN|lv.STATE.DEFAULT)
screen_3_label_3.set_style_radius(0, lv.PART.MAIN|lv.STATE.DEFAULT)
screen_3_label_3.set_style_text_color(lv.color_hex(0xffffff), lv.PART.MAIN|lv.STATE.DEFAULT)
screen_3_label_3.set_style_text_font(test_font("interttf", 28), lv.PART.MAIN|lv.STATE.DEFAULT)
screen_3_label_3.set_style_text_opa(255, lv.PART.MAIN|lv.STATE.DEFAULT)
screen_3_label_3.set_style_text_letter_space(0, lv.PART.MAIN|lv.STATE.DEFAULT)
screen_3_label_3.set_style_text_line_space(0, lv.PART.MAIN|lv.STATE.DEFAULT)
screen_3_label_3.set_style_text_align(lv.TEXT_ALIGN.CENTER, lv.PART.MAIN|lv.STATE.DEFAULT)
screen_3_label_3.set_style_bg_opa(0, lv.PART.MAIN|lv.STATE.DEFAULT)
screen_3_label_3.set_style_pad_top(0, lv.PART.MAIN|lv.STATE.DEFAULT)
screen_3_label_3.set_style_pad_right(0, lv.PART.MAIN|lv.STATE.DEFAULT)
screen_3_label_3.set_style_pad_bottom(0, lv.PART.MAIN|lv.STATE.DEFAULT)
screen_3_label_3.set_style_pad_left(0, lv.PART.MAIN|lv.STATE.DEFAULT)
screen_3_label_3.set_style_shadow_width(0, lv.PART.MAIN|lv.STATE.DEFAULT)

# Create screen_3_img_2
screen_3_img_2 = lv.img(screen_3)
screen_3_img_2.set_src("B:MicroPython/_foot16x16_alpha_20x20.bin")
screen_3_img_2.add_flag(lv.obj.FLAG.CLICKABLE)
screen_3_img_2.set_pivot(50,50)
screen_3_img_2.set_angle(0)
screen_3_img_2.set_pos(48, 185)
screen_3_img_2.set_size(20, 20)
# Set style for screen_3_img_2, Part: lv.PART.MAIN, State: lv.STATE.DEFAULT.
screen_3_img_2.set_style_img_opa(255, lv.PART.MAIN|lv.STATE.DEFAULT)
screen_3_img_2.set_style_radius(0, lv.PART.MAIN|lv.STATE.DEFAULT)
screen_3_img_2.set_style_clip_corner(True, lv.PART.MAIN|lv.STATE.DEFAULT)

# Create screen_3_img_3
screen_3_img_3 = lv.img(screen_3)
screen_3_img_3.set_src("B:MicroPython/_KLL16x16_alpha_20x20.bin")
screen_3_img_3.add_flag(lv.obj.FLAG.CLICKABLE)
screen_3_img_3.set_pivot(50,50)
screen_3_img_3.set_angle(0)
screen_3_img_3.set_pos(52, 121)
screen_3_img_3.set_size(20, 20)
# Set style for screen_3_img_3, Part: lv.PART.MAIN, State: lv.STATE.DEFAULT.
screen_3_img_3.set_style_img_opa(255, lv.PART.MAIN|lv.STATE.DEFAULT)
screen_3_img_3.set_style_radius(0, lv.PART.MAIN|lv.STATE.DEFAULT)
screen_3_img_3.set_style_clip_corner(True, lv.PART.MAIN|lv.STATE.DEFAULT)

# Create screen_3_img_4
screen_3_img_4 = lv.img(screen_3)
screen_3_img_4.set_src("B:MicroPython/_heart16x16_alpha_20x20.bin")
screen_3_img_4.add_flag(lv.obj.FLAG.CLICKABLE)
screen_3_img_4.set_pivot(50,50)
screen_3_img_4.set_angle(0)
screen_3_img_4.set_pos(31, 53)
screen_3_img_4.set_size(20, 20)
# Set style for screen_3_img_4, Part: lv.PART.MAIN, State: lv.STATE.DEFAULT.
screen_3_img_4.set_style_img_opa(255, lv.PART.MAIN|lv.STATE.DEFAULT)
screen_3_img_4.set_style_radius(0, lv.PART.MAIN|lv.STATE.DEFAULT)
screen_3_img_4.set_style_clip_corner(True, lv.PART.MAIN|lv.STATE.DEFAULT)

# Create screen_3_arc_2
screen_3_arc_2 = lv.arc(screen_3)
screen_3_arc_2.set_mode(lv.arc.MODE.NORMAL)
screen_3_arc_2.set_range(0, 100)
screen_3_arc_2.set_bg_angles(135, 45)
screen_3_arc_2.set_value(100)
screen_3_arc_2.set_rotation(250)
screen_3_arc_2.set_pos(27, 118)
screen_3_arc_2.set_size(41, 53)
# Set style for screen_3_arc_2, Part: lv.PART.MAIN, State: lv.STATE.DEFAULT.
screen_3_arc_2.set_style_bg_opa(0, lv.PART.MAIN|lv.STATE.DEFAULT)
screen_3_arc_2.set_style_border_width(0, lv.PART.MAIN|lv.STATE.DEFAULT)
screen_3_arc_2.set_style_arc_opa(0, lv.PART.MAIN|lv.STATE.DEFAULT)
screen_3_arc_2.set_style_radius(6, lv.PART.MAIN|lv.STATE.DEFAULT)
screen_3_arc_2.set_style_pad_top(0, lv.PART.MAIN|lv.STATE.DEFAULT)
screen_3_arc_2.set_style_pad_bottom(0, lv.PART.MAIN|lv.STATE.DEFAULT)
screen_3_arc_2.set_style_pad_left(0, lv.PART.MAIN|lv.STATE.DEFAULT)
screen_3_arc_2.set_style_pad_right(0, lv.PART.MAIN|lv.STATE.DEFAULT)
screen_3_arc_2.set_style_shadow_width(0, lv.PART.MAIN|lv.STATE.DEFAULT)

# Set style for screen_3_arc_2, Part: lv.PART.INDICATOR, State: lv.STATE.DEFAULT.
screen_3_arc_2.set_style_arc_width(2, lv.PART.INDICATOR|lv.STATE.DEFAULT)
screen_3_arc_2.set_style_arc_opa(255, lv.PART.INDICATOR|lv.STATE.DEFAULT)
screen_3_arc_2.set_style_arc_color(lv.color_hex(0xffbf00), lv.PART.INDICATOR|lv.STATE.DEFAULT)

# Set style for screen_3_arc_2, Part: lv.PART.KNOB, State: lv.STATE.DEFAULT.
screen_3_arc_2.set_style_bg_opa(255, lv.PART.KNOB|lv.STATE.DEFAULT)
screen_3_arc_2.set_style_bg_color(lv.color_hex(0xffc600), lv.PART.KNOB|lv.STATE.DEFAULT)
screen_3_arc_2.set_style_bg_grad_dir(lv.GRAD_DIR.NONE, lv.PART.KNOB|lv.STATE.DEFAULT)
screen_3_arc_2.set_style_pad_all(0, lv.PART.KNOB|lv.STATE.DEFAULT)

# Create screen_3_arc_4
screen_3_arc_4 = lv.arc(screen_3)
screen_3_arc_4.set_mode(lv.arc.MODE.NORMAL)
screen_3_arc_4.set_range(0, 100)
screen_3_arc_4.set_bg_angles(135, 45)
screen_3_arc_4.set_value(100)
screen_3_arc_4.set_rotation(210)
screen_3_arc_4.set_pos(27, 193)
screen_3_arc_4.set_size(41, 53)
# Set style for screen_3_arc_4, Part: lv.PART.MAIN, State: lv.STATE.DEFAULT.
screen_3_arc_4.set_style_bg_opa(0, lv.PART.MAIN|lv.STATE.DEFAULT)
screen_3_arc_4.set_style_border_width(0, lv.PART.MAIN|lv.STATE.DEFAULT)
screen_3_arc_4.set_style_arc_opa(0, lv.PART.MAIN|lv.STATE.DEFAULT)
screen_3_arc_4.set_style_radius(6, lv.PART.MAIN|lv.STATE.DEFAULT)
screen_3_arc_4.set_style_pad_top(0, lv.PART.MAIN|lv.STATE.DEFAULT)
screen_3_arc_4.set_style_pad_bottom(0, lv.PART.MAIN|lv.STATE.DEFAULT)
screen_3_arc_4.set_style_pad_left(0, lv.PART.MAIN|lv.STATE.DEFAULT)
screen_3_arc_4.set_style_pad_right(0, lv.PART.MAIN|lv.STATE.DEFAULT)
screen_3_arc_4.set_style_shadow_width(0, lv.PART.MAIN|lv.STATE.DEFAULT)

# Set style for screen_3_arc_4, Part: lv.PART.INDICATOR, State: lv.STATE.DEFAULT.
screen_3_arc_4.set_style_arc_width(2, lv.PART.INDICATOR|lv.STATE.DEFAULT)
screen_3_arc_4.set_style_arc_opa(255, lv.PART.INDICATOR|lv.STATE.DEFAULT)
screen_3_arc_4.set_style_arc_color(lv.color_hex(0x00ff16), lv.PART.INDICATOR|lv.STATE.DEFAULT)

# Set style for screen_3_arc_4, Part: lv.PART.KNOB, State: lv.STATE.DEFAULT.
screen_3_arc_4.set_style_bg_opa(255, lv.PART.KNOB|lv.STATE.DEFAULT)
screen_3_arc_4.set_style_bg_color(lv.color_hex(0xffc600), lv.PART.KNOB|lv.STATE.DEFAULT)
screen_3_arc_4.set_style_bg_grad_dir(lv.GRAD_DIR.NONE, lv.PART.KNOB|lv.STATE.DEFAULT)
screen_3_arc_4.set_style_pad_all(0, lv.PART.KNOB|lv.STATE.DEFAULT)

# Create screen_3_arc_5
screen_3_arc_5 = lv.arc(screen_3)
screen_3_arc_5.set_mode(lv.arc.MODE.NORMAL)
screen_3_arc_5.set_range(0, 100)
screen_3_arc_5.set_bg_angles(135, 45)
screen_3_arc_5.set_value(100)
screen_3_arc_5.set_rotation(160)
screen_3_arc_5.set_pos(27, 60)
screen_3_arc_5.set_size(41, 53)
# Set style for screen_3_arc_5, Part: lv.PART.MAIN, State: lv.STATE.DEFAULT.
screen_3_arc_5.set_style_bg_opa(0, lv.PART.MAIN|lv.STATE.DEFAULT)
screen_3_arc_5.set_style_border_width(0, lv.PART.MAIN|lv.STATE.DEFAULT)
screen_3_arc_5.set_style_arc_opa(0, lv.PART.MAIN|lv.STATE.DEFAULT)
screen_3_arc_5.set_style_radius(6, lv.PART.MAIN|lv.STATE.DEFAULT)
screen_3_arc_5.set_style_pad_top(0, lv.PART.MAIN|lv.STATE.DEFAULT)
screen_3_arc_5.set_style_pad_bottom(0, lv.PART.MAIN|lv.STATE.DEFAULT)
screen_3_arc_5.set_style_pad_left(0, lv.PART.MAIN|lv.STATE.DEFAULT)
screen_3_arc_5.set_style_pad_right(0, lv.PART.MAIN|lv.STATE.DEFAULT)
screen_3_arc_5.set_style_shadow_width(0, lv.PART.MAIN|lv.STATE.DEFAULT)

# Set style for screen_3_arc_5, Part: lv.PART.INDICATOR, State: lv.STATE.DEFAULT.
screen_3_arc_5.set_style_arc_width(2, lv.PART.INDICATOR|lv.STATE.DEFAULT)
screen_3_arc_5.set_style_arc_opa(255, lv.PART.INDICATOR|lv.STATE.DEFAULT)
screen_3_arc_5.set_style_arc_color(lv.color_hex(0xe01030), lv.PART.INDICATOR|lv.STATE.DEFAULT)

# Set style for screen_3_arc_5, Part: lv.PART.KNOB, State: lv.STATE.DEFAULT.
screen_3_arc_5.set_style_bg_opa(255, lv.PART.KNOB|lv.STATE.DEFAULT)
screen_3_arc_5.set_style_bg_color(lv.color_hex(0xffc600), lv.PART.KNOB|lv.STATE.DEFAULT)
screen_3_arc_5.set_style_bg_grad_dir(lv.GRAD_DIR.NONE, lv.PART.KNOB|lv.STATE.DEFAULT)
screen_3_arc_5.set_style_pad_all(0, lv.PART.KNOB|lv.STATE.DEFAULT)

# Create screen_3_label_1
screen_3_label_1 = lv.label(screen_3)
screen_3_label_1.set_text("10")
screen_3_label_1.set_long_mode(lv.label.LONG.WRAP)
screen_3_label_1.set_width(lv.pct(100))
screen_3_label_1.set_pos(116, 53)
screen_3_label_1.set_size(99, 88)
# Set style for screen_3_label_1, Part: lv.PART.MAIN, State: lv.STATE.DEFAULT.
screen_3_label_1.set_style_border_width(0, lv.PART.MAIN|lv.STATE.DEFAULT)
screen_3_label_1.set_style_radius(0, lv.PART.MAIN|lv.STATE.DEFAULT)
screen_3_label_1.set_style_text_color(lv.color_hex(0xf00000), lv.PART.MAIN|lv.STATE.DEFAULT)
screen_3_label_1.set_style_text_font(test_font("interttf", 82), lv.PART.MAIN|lv.STATE.DEFAULT)
screen_3_label_1.set_style_text_opa(255, lv.PART.MAIN|lv.STATE.DEFAULT)
screen_3_label_1.set_style_text_letter_space(0, lv.PART.MAIN|lv.STATE.DEFAULT)
screen_3_label_1.set_style_text_line_space(0, lv.PART.MAIN|lv.STATE.DEFAULT)
screen_3_label_1.set_style_text_align(lv.TEXT_ALIGN.CENTER, lv.PART.MAIN|lv.STATE.DEFAULT)
screen_3_label_1.set_style_bg_opa(0, lv.PART.MAIN|lv.STATE.DEFAULT)
screen_3_label_1.set_style_pad_top(0, lv.PART.MAIN|lv.STATE.DEFAULT)
screen_3_label_1.set_style_pad_right(0, lv.PART.MAIN|lv.STATE.DEFAULT)
screen_3_label_1.set_style_pad_bottom(0, lv.PART.MAIN|lv.STATE.DEFAULT)
screen_3_label_1.set_style_pad_left(0, lv.PART.MAIN|lv.STATE.DEFAULT)
screen_3_label_1.set_style_shadow_width(0, lv.PART.MAIN|lv.STATE.DEFAULT)

# Create screen_3_label_4
screen_3_label_4 = lv.label(screen_3)
screen_3_label_4.set_text("15")
screen_3_label_4.set_long_mode(lv.label.LONG.WRAP)
screen_3_label_4.set_width(lv.pct(100))
screen_3_label_4.set_pos(15, 73)
screen_3_label_4.set_size(63, 21)
# Set style for screen_3_label_4, Part: lv.PART.MAIN, State: lv.STATE.DEFAULT.
screen_3_label_4.set_style_border_width(0, lv.PART.MAIN|lv.STATE.DEFAULT)
screen_3_label_4.set_style_radius(0, lv.PART.MAIN|lv.STATE.DEFAULT)
screen_3_label_4.set_style_text_color(lv.color_hex(0xffffff), lv.PART.MAIN|lv.STATE.DEFAULT)
screen_3_label_4.set_style_text_font(test_font("SourceHanSerifSC_Regular", 16), lv.PART.MAIN|lv.STATE.DEFAULT)
screen_3_label_4.set_style_text_opa(255, lv.PART.MAIN|lv.STATE.DEFAULT)
screen_3_label_4.set_style_text_letter_space(0, lv.PART.MAIN|lv.STATE.DEFAULT)
screen_3_label_4.set_style_text_line_space(0, lv.PART.MAIN|lv.STATE.DEFAULT)
screen_3_label_4.set_style_text_align(lv.TEXT_ALIGN.CENTER, lv.PART.MAIN|lv.STATE.DEFAULT)
screen_3_label_4.set_style_bg_opa(0, lv.PART.MAIN|lv.STATE.DEFAULT)
screen_3_label_4.set_style_pad_top(0, lv.PART.MAIN|lv.STATE.DEFAULT)
screen_3_label_4.set_style_pad_right(0, lv.PART.MAIN|lv.STATE.DEFAULT)
screen_3_label_4.set_style_pad_bottom(0, lv.PART.MAIN|lv.STATE.DEFAULT)
screen_3_label_4.set_style_pad_left(0, lv.PART.MAIN|lv.STATE.DEFAULT)
screen_3_label_4.set_style_shadow_width(0, lv.PART.MAIN|lv.STATE.DEFAULT)

# Create screen_3_label_5
screen_3_label_5 = lv.label(screen_3)
screen_3_label_5.set_text("15")
screen_3_label_5.set_long_mode(lv.label.LONG.WRAP)
screen_3_label_5.set_width(lv.pct(100))
screen_3_label_5.set_pos(15, 205)
screen_3_label_5.set_size(63, 21)
# Set style for screen_3_label_5, Part: lv.PART.MAIN, State: lv.STATE.DEFAULT.
screen_3_label_5.set_style_border_width(0, lv.PART.MAIN|lv.STATE.DEFAULT)
screen_3_label_5.set_style_radius(0, lv.PART.MAIN|lv.STATE.DEFAULT)
screen_3_label_5.set_style_text_color(lv.color_hex(0xffffff), lv.PART.MAIN|lv.STATE.DEFAULT)
screen_3_label_5.set_style_text_font(test_font("SourceHanSerifSC_Regular", 16), lv.PART.MAIN|lv.STATE.DEFAULT)
screen_3_label_5.set_style_text_opa(255, lv.PART.MAIN|lv.STATE.DEFAULT)
screen_3_label_5.set_style_text_letter_space(0, lv.PART.MAIN|lv.STATE.DEFAULT)
screen_3_label_5.set_style_text_line_space(0, lv.PART.MAIN|lv.STATE.DEFAULT)
screen_3_label_5.set_style_text_align(lv.TEXT_ALIGN.CENTER, lv.PART.MAIN|lv.STATE.DEFAULT)
screen_3_label_5.set_style_bg_opa(0, lv.PART.MAIN|lv.STATE.DEFAULT)
screen_3_label_5.set_style_pad_top(0, lv.PART.MAIN|lv.STATE.DEFAULT)
screen_3_label_5.set_style_pad_right(0, lv.PART.MAIN|lv.STATE.DEFAULT)
screen_3_label_5.set_style_pad_bottom(0, lv.PART.MAIN|lv.STATE.DEFAULT)
screen_3_label_5.set_style_pad_left(0, lv.PART.MAIN|lv.STATE.DEFAULT)
screen_3_label_5.set_style_shadow_width(0, lv.PART.MAIN|lv.STATE.DEFAULT)

# Create screen_3_label_6
screen_3_label_6 = lv.label(screen_3)
screen_3_label_6.set_text("20")
screen_3_label_6.set_long_mode(lv.label.LONG.WRAP)
screen_3_label_6.set_width(lv.pct(100))
screen_3_label_6.set_pos(15, 131)
screen_3_label_6.set_size(63, 21)
# Set style for screen_3_label_6, Part: lv.PART.MAIN, State: lv.STATE.DEFAULT.
screen_3_label_6.set_style_border_width(0, lv.PART.MAIN|lv.STATE.DEFAULT)
screen_3_label_6.set_style_radius(0, lv.PART.MAIN|lv.STATE.DEFAULT)
screen_3_label_6.set_style_text_color(lv.color_hex(0xffffff), lv.PART.MAIN|lv.STATE.DEFAULT)
screen_3_label_6.set_style_text_font(test_font("SourceHanSerifSC_Regular", 16), lv.PART.MAIN|lv.STATE.DEFAULT)
screen_3_label_6.set_style_text_opa(255, lv.PART.MAIN|lv.STATE.DEFAULT)
screen_3_label_6.set_style_text_letter_space(0, lv.PART.MAIN|lv.STATE.DEFAULT)
screen_3_label_6.set_style_text_line_space(0, lv.PART.MAIN|lv.STATE.DEFAULT)
screen_3_label_6.set_style_text_align(lv.TEXT_ALIGN.CENTER, lv.PART.MAIN|lv.STATE.DEFAULT)
screen_3_label_6.set_style_bg_opa(0, lv.PART.MAIN|lv.STATE.DEFAULT)
screen_3_label_6.set_style_pad_top(0, lv.PART.MAIN|lv.STATE.DEFAULT)
screen_3_label_6.set_style_pad_right(0, lv.PART.MAIN|lv.STATE.DEFAULT)
screen_3_label_6.set_style_pad_bottom(0, lv.PART.MAIN|lv.STATE.DEFAULT)
screen_3_label_6.set_style_pad_left(0, lv.PART.MAIN|lv.STATE.DEFAULT)
screen_3_label_6.set_style_shadow_width(0, lv.PART.MAIN|lv.STATE.DEFAULT)

# Create screen_3_cont_1
screen_3_cont_1 = lv.obj(screen_3)
screen_3_cont_1.set_pos(-136, 0)
screen_3_cont_1.set_size(120, 280)
screen_3_cont_1.set_scrollbar_mode(lv.SCROLLBAR_MODE.OFF)
# Set style for screen_3_cont_1, Part: lv.PART.MAIN, State: lv.STATE.DEFAULT.
screen_3_cont_1.set_style_radius(0, lv.PART.MAIN|lv.STATE.DEFAULT)
screen_3_cont_1.set_style_bg_opa(255, lv.PART.MAIN|lv.STATE.DEFAULT)
screen_3_cont_1.set_style_bg_color(lv.color_hex(0x000000), lv.PART.MAIN|lv.STATE.DEFAULT)
screen_3_cont_1.set_style_bg_grad_dir(lv.GRAD_DIR.NONE, lv.PART.MAIN|lv.STATE.DEFAULT)
screen_3_cont_1.set_style_border_width(2, lv.PART.MAIN|lv.STATE.DEFAULT)
screen_3_cont_1.set_style_border_opa(255, lv.PART.MAIN|lv.STATE.DEFAULT)
screen_3_cont_1.set_style_border_color(lv.color_hex(0x000000), lv.PART.MAIN|lv.STATE.DEFAULT)
screen_3_cont_1.set_style_border_side(lv.BORDER_SIDE.FULL, lv.PART.MAIN|lv.STATE.DEFAULT)
screen_3_cont_1.set_style_shadow_width(0, lv.PART.MAIN|lv.STATE.DEFAULT)
screen_3_cont_1.set_style_pad_top(0, lv.PART.MAIN|lv.STATE.DEFAULT)
screen_3_cont_1.set_style_pad_bottom(0, lv.PART.MAIN|lv.STATE.DEFAULT)
screen_3_cont_1.set_style_pad_left(0, lv.PART.MAIN|lv.STATE.DEFAULT)
screen_3_cont_1.set_style_pad_right(0, lv.PART.MAIN|lv.STATE.DEFAULT)
# Create screen_3_btn_3
screen_3_btn_3 = lv.btn(screen_3_cont_1)
screen_3_btn_3_label = lv.label(screen_3_btn_3)
screen_3_btn_3_label.set_text(" ")
screen_3_btn_3_label.set_long_mode(lv.label.LONG.WRAP)
screen_3_btn_3_label.set_width(lv.pct(100))
screen_3_btn_3_label.align(lv.ALIGN.CENTER, 0, 0)
screen_3_btn_3.set_style_pad_all(0, lv.STATE.DEFAULT)
screen_3_btn_3.set_pos(61, 202)
screen_3_btn_3.set_size(50, 50)
# Set style for screen_3_btn_3, Part: lv.PART.MAIN, State: lv.STATE.DEFAULT.
screen_3_btn_3.set_style_radius(5, lv.PART.MAIN|lv.STATE.DEFAULT)
screen_3_btn_3.set_style_bg_opa(255, lv.PART.MAIN|lv.STATE.DEFAULT)
screen_3_btn_3.set_style_bg_color(lv.color_hex(0x5a5a5a), lv.PART.MAIN|lv.STATE.DEFAULT)
screen_3_btn_3.set_style_bg_grad_dir(lv.GRAD_DIR.NONE, lv.PART.MAIN|lv.STATE.DEFAULT)
screen_3_btn_3.set_style_border_width(0, lv.PART.MAIN|lv.STATE.DEFAULT)
screen_3_btn_3.set_style_shadow_width(0, lv.PART.MAIN|lv.STATE.DEFAULT)
screen_3_btn_3.set_style_text_color(lv.color_hex(0xffffff), lv.PART.MAIN|lv.STATE.DEFAULT)
screen_3_btn_3.set_style_text_font(test_font("montserratMedium", 16), lv.PART.MAIN|lv.STATE.DEFAULT)
screen_3_btn_3.set_style_text_opa(255, lv.PART.MAIN|lv.STATE.DEFAULT)
screen_3_btn_3.set_style_text_align(lv.TEXT_ALIGN.CENTER, lv.PART.MAIN|lv.STATE.DEFAULT)

# Create screen_3_btn_2
screen_3_btn_2 = lv.btn(screen_3_cont_1)
screen_3_btn_2_label = lv.label(screen_3_btn_2)
screen_3_btn_2_label.set_text(" ")
screen_3_btn_2_label.set_long_mode(lv.label.LONG.WRAP)
screen_3_btn_2_label.set_width(lv.pct(100))
screen_3_btn_2_label.align(lv.ALIGN.CENTER, 0, 0)
screen_3_btn_2.set_style_pad_all(0, lv.STATE.DEFAULT)
screen_3_btn_2.set_pos(10, 143)
screen_3_btn_2.set_size(100, 50)
# Set style for screen_3_btn_2, Part: lv.PART.MAIN, State: lv.STATE.DEFAULT.
screen_3_btn_2.set_style_radius(5, lv.PART.MAIN|lv.STATE.DEFAULT)
screen_3_btn_2.set_style_bg_opa(255, lv.PART.MAIN|lv.STATE.DEFAULT)
screen_3_btn_2.set_style_bg_color(lv.color_hex(0x5a5a5a), lv.PART.MAIN|lv.STATE.DEFAULT)
screen_3_btn_2.set_style_bg_grad_dir(lv.GRAD_DIR.NONE, lv.PART.MAIN|lv.STATE.DEFAULT)
screen_3_btn_2.set_style_border_width(0, lv.PART.MAIN|lv.STATE.DEFAULT)
screen_3_btn_2.set_style_shadow_width(0, lv.PART.MAIN|lv.STATE.DEFAULT)
screen_3_btn_2.set_style_text_color(lv.color_hex(0xffffff), lv.PART.MAIN|lv.STATE.DEFAULT)
screen_3_btn_2.set_style_text_font(test_font("montserratMedium", 16), lv.PART.MAIN|lv.STATE.DEFAULT)
screen_3_btn_2.set_style_text_opa(255, lv.PART.MAIN|lv.STATE.DEFAULT)
screen_3_btn_2.set_style_text_align(lv.TEXT_ALIGN.CENTER, lv.PART.MAIN|lv.STATE.DEFAULT)

# Create screen_3_btn_1
screen_3_btn_1 = lv.btn(screen_3_cont_1)
screen_3_btn_1_label = lv.label(screen_3_btn_1)
screen_3_btn_1_label.set_text(" ")
screen_3_btn_1_label.set_long_mode(lv.label.LONG.WRAP)
screen_3_btn_1_label.set_width(lv.pct(100))
screen_3_btn_1_label.align(lv.ALIGN.CENTER, 0, 0)
screen_3_btn_1.set_style_pad_all(0, lv.STATE.DEFAULT)
screen_3_btn_1.set_pos(7, 202)
screen_3_btn_1.set_size(50, 50)
# Set style for screen_3_btn_1, Part: lv.PART.MAIN, State: lv.STATE.DEFAULT.
screen_3_btn_1.set_style_radius(5, lv.PART.MAIN|lv.STATE.DEFAULT)
screen_3_btn_1.set_style_bg_opa(255, lv.PART.MAIN|lv.STATE.DEFAULT)
screen_3_btn_1.set_style_bg_color(lv.color_hex(0x5a5a5a), lv.PART.MAIN|lv.STATE.DEFAULT)
screen_3_btn_1.set_style_bg_grad_dir(lv.GRAD_DIR.NONE, lv.PART.MAIN|lv.STATE.DEFAULT)
screen_3_btn_1.set_style_border_width(0, lv.PART.MAIN|lv.STATE.DEFAULT)
screen_3_btn_1.set_style_shadow_width(0, lv.PART.MAIN|lv.STATE.DEFAULT)
screen_3_btn_1.set_style_text_color(lv.color_hex(0xffffff), lv.PART.MAIN|lv.STATE.DEFAULT)
screen_3_btn_1.set_style_text_font(test_font("montserratMedium", 16), lv.PART.MAIN|lv.STATE.DEFAULT)
screen_3_btn_1.set_style_text_opa(255, lv.PART.MAIN|lv.STATE.DEFAULT)
screen_3_btn_1.set_style_text_align(lv.TEXT_ALIGN.CENTER, lv.PART.MAIN|lv.STATE.DEFAULT)

# Create screen_3_img_9
screen_3_img_9 = lv.img(screen_3_cont_1)
screen_3_img_9.set_src("B:MicroPython/_zhengdong_0_alpha_30x30.bin")
screen_3_img_9.add_flag(lv.obj.FLAG.CLICKABLE)
screen_3_img_9.set_pivot(50,50)
screen_3_img_9.set_angle(0)
screen_3_img_9.set_pos(72, 211)
screen_3_img_9.set_size(30, 30)
# Set style for screen_3_img_9, Part: lv.PART.MAIN, State: lv.STATE.DEFAULT.
screen_3_img_9.set_style_img_opa(255, lv.PART.MAIN|lv.STATE.DEFAULT)
screen_3_img_9.set_style_radius(0, lv.PART.MAIN|lv.STATE.DEFAULT)
screen_3_img_9.set_style_clip_corner(True, lv.PART.MAIN|lv.STATE.DEFAULT)

# Create screen_3_img_8
screen_3_img_8 = lv.img(screen_3_cont_1)
screen_3_img_8.set_src("B:MicroPython/_mianti_0_alpha_30x30.bin")
screen_3_img_8.add_flag(lv.obj.FLAG.CLICKABLE)
screen_3_img_8.set_pivot(50,50)
screen_3_img_8.set_angle(0)
screen_3_img_8.set_pos(18, 211)
screen_3_img_8.set_size(30, 30)
# Set style for screen_3_img_8, Part: lv.PART.MAIN, State: lv.STATE.DEFAULT.
screen_3_img_8.set_style_radius(0, lv.PART.MAIN|lv.STATE.DEFAULT)
screen_3_img_8.set_style_clip_corner(True, lv.PART.MAIN|lv.STATE.DEFAULT)
screen_3_img_8.set_style_img_opa(255, lv.PART.MAIN|lv.STATE.DEFAULT)

# Create screen_3_img_7
screen_3_img_7 = lv.img(screen_3_cont_1)
screen_3_img_7.set_src("B:MicroPython/_BT32_alpha_30x30.bin")
screen_3_img_7.add_flag(lv.obj.FLAG.CLICKABLE)
screen_3_img_7.set_pivot(50,50)
screen_3_img_7.set_angle(0)
screen_3_img_7.set_pos(45, 152)
screen_3_img_7.set_size(30, 30)
# Set style for screen_3_img_7, Part: lv.PART.MAIN, State: lv.STATE.DEFAULT.
screen_3_img_7.set_style_img_opa(255, lv.PART.MAIN|lv.STATE.DEFAULT)
screen_3_img_7.set_style_radius(0, lv.PART.MAIN|lv.STATE.DEFAULT)
screen_3_img_7.set_style_clip_corner(True, lv.PART.MAIN|lv.STATE.DEFAULT)

# Create screen_3_img_6
screen_3_img_6 = lv.img(screen_3_cont_1)
screen_3_img_6.set_src("B:MicroPython/_copesss_alpha_30x30.bin")
screen_3_img_6.add_flag(lv.obj.FLAG.CLICKABLE)
screen_3_img_6.set_pivot(50,50)
screen_3_img_6.set_angle(0)
screen_3_img_6.set_pos(9, 84)
screen_3_img_6.set_size(30, 30)
# Set style for screen_3_img_6, Part: lv.PART.MAIN, State: lv.STATE.DEFAULT.
screen_3_img_6.set_style_img_opa(255, lv.PART.MAIN|lv.STATE.DEFAULT)
screen_3_img_6.set_style_radius(0, lv.PART.MAIN|lv.STATE.DEFAULT)
screen_3_img_6.set_style_clip_corner(True, lv.PART.MAIN|lv.STATE.DEFAULT)

# Create screen_3_img_5
screen_3_img_5 = lv.img(screen_3_cont_1)
screen_3_img_5.set_src("B:MicroPython/_weater32x32_alpha_30x30.bin")
screen_3_img_5.add_flag(lv.obj.FLAG.CLICKABLE)
screen_3_img_5.set_pivot(50,50)
screen_3_img_5.set_angle(0)
screen_3_img_5.set_pos(6, 34)
screen_3_img_5.set_size(30, 30)
# Set style for screen_3_img_5, Part: lv.PART.MAIN, State: lv.STATE.DEFAULT.
screen_3_img_5.set_style_radius(0, lv.PART.MAIN|lv.STATE.DEFAULT)
screen_3_img_5.set_style_clip_corner(True, lv.PART.MAIN|lv.STATE.DEFAULT)
screen_3_img_5.set_style_img_opa(255, lv.PART.MAIN|lv.STATE.DEFAULT)

# Create screen_3_label_8
screen_3_label_8 = lv.label(screen_3_cont_1)
screen_3_label_8.set_text("38")
screen_3_label_8.set_long_mode(lv.label.LONG.WRAP)
screen_3_label_8.set_width(lv.pct(100))
screen_3_label_8.set_pos(44, 92)
screen_3_label_8.set_size(68, 17)
# Set style for screen_3_label_8, Part: lv.PART.MAIN, State: lv.STATE.DEFAULT.
screen_3_label_8.set_style_radius(0, lv.PART.MAIN|lv.STATE.DEFAULT)
screen_3_label_8.set_style_border_width(0, lv.PART.MAIN|lv.STATE.DEFAULT)
screen_3_label_8.set_style_bg_opa(0, lv.PART.MAIN|lv.STATE.DEFAULT)
screen_3_label_8.set_style_pad_top(0, lv.PART.MAIN|lv.STATE.DEFAULT)
screen_3_label_8.set_style_pad_right(0, lv.PART.MAIN|lv.STATE.DEFAULT)
screen_3_label_8.set_style_pad_bottom(0, lv.PART.MAIN|lv.STATE.DEFAULT)
screen_3_label_8.set_style_pad_left(0, lv.PART.MAIN|lv.STATE.DEFAULT)
screen_3_label_8.set_style_shadow_width(0, lv.PART.MAIN|lv.STATE.DEFAULT)
screen_3_label_8.set_style_text_color(lv.color_hex(0xffffff), lv.PART.MAIN|lv.STATE.DEFAULT)
screen_3_label_8.set_style_text_font(test_font("montserratMedium", 16), lv.PART.MAIN|lv.STATE.DEFAULT)
screen_3_label_8.set_style_text_opa(255, lv.PART.MAIN|lv.STATE.DEFAULT)
screen_3_label_8.set_style_text_letter_space(0, lv.PART.MAIN|lv.STATE.DEFAULT)
screen_3_label_8.set_style_text_line_space(0, lv.PART.MAIN|lv.STATE.DEFAULT)
screen_3_label_8.set_style_text_align(lv.TEXT_ALIGN.CENTER, lv.PART.MAIN|lv.STATE.DEFAULT)

# Create screen_3_label_7
screen_3_label_7 = lv.label(screen_3_cont_1)
screen_3_label_7.set_text("天气")
screen_3_label_7.set_long_mode(lv.label.LONG.WRAP)
screen_3_label_7.set_width(lv.pct(100))
screen_3_label_7.set_pos(39, 43)
screen_3_label_7.set_size(68, 17)
# Set style for screen_3_label_7, Part: lv.PART.MAIN, State: lv.STATE.DEFAULT.
screen_3_label_7.set_style_radius(0, lv.PART.MAIN|lv.STATE.DEFAULT)
screen_3_label_7.set_style_border_width(0, lv.PART.MAIN|lv.STATE.DEFAULT)
screen_3_label_7.set_style_bg_opa(0, lv.PART.MAIN|lv.STATE.DEFAULT)
screen_3_label_7.set_style_pad_top(0, lv.PART.MAIN|lv.STATE.DEFAULT)
screen_3_label_7.set_style_pad_bottom(0, lv.PART.MAIN|lv.STATE.DEFAULT)
screen_3_label_7.set_style_pad_left(0, lv.PART.MAIN|lv.STATE.DEFAULT)
screen_3_label_7.set_style_pad_right(0, lv.PART.MAIN|lv.STATE.DEFAULT)
screen_3_label_7.set_style_shadow_width(0, lv.PART.MAIN|lv.STATE.DEFAULT)
screen_3_label_7.set_style_text_color(lv.color_hex(0xffffff), lv.PART.MAIN|lv.STATE.DEFAULT)
screen_3_label_7.set_style_text_font(test_font("montserratMedium", 16), lv.PART.MAIN|lv.STATE.DEFAULT)
screen_3_label_7.set_style_text_opa(255, lv.PART.MAIN|lv.STATE.DEFAULT)
screen_3_label_7.set_style_text_letter_space(0, lv.PART.MAIN|lv.STATE.DEFAULT)
screen_3_label_7.set_style_text_line_space(0, lv.PART.MAIN|lv.STATE.DEFAULT)
screen_3_label_7.set_style_text_align(lv.TEXT_ALIGN.CENTER, lv.PART.MAIN|lv.STATE.DEFAULT)

# Create screen_3_cont_2
screen_3_cont_2 = lv.obj(screen_3)
screen_3_cont_2.set_pos(0, 0)
screen_3_cont_2.set_size(240, 280)
screen_3_cont_2.set_scrollbar_mode(lv.SCROLLBAR_MODE.OFF)
screen_3_cont_2.add_flag(lv.obj.FLAG.HIDDEN)
# Set style for screen_3_cont_2, Part: lv.PART.MAIN, State: lv.STATE.DEFAULT.
screen_3_cont_2.set_style_border_width(2, lv.PART.MAIN|lv.STATE.DEFAULT)
screen_3_cont_2.set_style_border_opa(255, lv.PART.MAIN|lv.STATE.DEFAULT)
screen_3_cont_2.set_style_border_color(lv.color_hex(0x000000), lv.PART.MAIN|lv.STATE.DEFAULT)
screen_3_cont_2.set_style_border_side(lv.BORDER_SIDE.FULL, lv.PART.MAIN|lv.STATE.DEFAULT)
screen_3_cont_2.set_style_radius(0, lv.PART.MAIN|lv.STATE.DEFAULT)
screen_3_cont_2.set_style_bg_opa(123, lv.PART.MAIN|lv.STATE.DEFAULT)
screen_3_cont_2.set_style_bg_color(lv.color_hex(0x000000), lv.PART.MAIN|lv.STATE.DEFAULT)
screen_3_cont_2.set_style_bg_grad_dir(lv.GRAD_DIR.NONE, lv.PART.MAIN|lv.STATE.DEFAULT)
screen_3_cont_2.set_style_pad_top(0, lv.PART.MAIN|lv.STATE.DEFAULT)
screen_3_cont_2.set_style_pad_right(0, lv.PART.MAIN|lv.STATE.DEFAULT)
screen_3_cont_2.set_style_pad_bottom(0, lv.PART.MAIN|lv.STATE.DEFAULT)
screen_3_cont_2.set_style_pad_left(0, lv.PART.MAIN|lv.STATE.DEFAULT)
screen_3_cont_2.set_style_shadow_width(0, lv.PART.MAIN|lv.STATE.DEFAULT)

screen_3.update_layout()
# Create top_lap
top_lap = lv.obj()
top_lap.set_size(240, 280)
top_lap.set_scrollbar_mode(lv.SCROLLBAR_MODE.OFF)
# Set style for top_lap, Part: lv.PART.MAIN, State: lv.STATE.DEFAULT.
top_lap.set_style_bg_opa(255, lv.PART.MAIN|lv.STATE.DEFAULT)
top_lap.set_style_bg_color(lv.color_hex(0x000000), lv.PART.MAIN|lv.STATE.DEFAULT)
top_lap.set_style_bg_grad_dir(lv.GRAD_DIR.NONE, lv.PART.MAIN|lv.STATE.DEFAULT)

# Create top_lap_cont_4
top_lap_cont_4 = lv.obj(top_lap)
top_lap_cont_4.set_pos(31, 138)
top_lap_cont_4.set_size(50, 50)
top_lap_cont_4.set_scrollbar_mode(lv.SCROLLBAR_MODE.OFF)
# Set style for top_lap_cont_4, Part: lv.PART.MAIN, State: lv.STATE.DEFAULT.
top_lap_cont_4.set_style_border_width(2, lv.PART.MAIN|lv.STATE.DEFAULT)
top_lap_cont_4.set_style_border_opa(255, lv.PART.MAIN|lv.STATE.DEFAULT)
top_lap_cont_4.set_style_border_color(lv.color_hex(0x2195f6), lv.PART.MAIN|lv.STATE.DEFAULT)
top_lap_cont_4.set_style_border_side(lv.BORDER_SIDE.FULL, lv.PART.MAIN|lv.STATE.DEFAULT)
top_lap_cont_4.set_style_radius(50, lv.PART.MAIN|lv.STATE.DEFAULT)
top_lap_cont_4.set_style_bg_opa(255, lv.PART.MAIN|lv.STATE.DEFAULT)
top_lap_cont_4.set_style_bg_color(lv.color_hex(0xff00f7), lv.PART.MAIN|lv.STATE.DEFAULT)
top_lap_cont_4.set_style_bg_grad_dir(lv.GRAD_DIR.NONE, lv.PART.MAIN|lv.STATE.DEFAULT)
top_lap_cont_4.set_style_pad_top(0, lv.PART.MAIN|lv.STATE.DEFAULT)
top_lap_cont_4.set_style_pad_bottom(0, lv.PART.MAIN|lv.STATE.DEFAULT)
top_lap_cont_4.set_style_pad_left(0, lv.PART.MAIN|lv.STATE.DEFAULT)
top_lap_cont_4.set_style_pad_right(0, lv.PART.MAIN|lv.STATE.DEFAULT)
top_lap_cont_4.set_style_bg_img_src("B:MicroPython/_taiwan_50x50.bin", lv.PART.MAIN|lv.STATE.DEFAULT)
top_lap_cont_4.set_style_bg_img_opa(255, lv.PART.MAIN|lv.STATE.DEFAULT)
top_lap_cont_4.set_style_bg_img_recolor_opa(0, lv.PART.MAIN|lv.STATE.DEFAULT)
top_lap_cont_4.set_style_shadow_width(0, lv.PART.MAIN|lv.STATE.DEFAULT)

# Create top_lap_cont_5
top_lap_cont_5 = lv.obj(top_lap)
top_lap_cont_5.set_pos(152, 138)
top_lap_cont_5.set_size(50, 50)
top_lap_cont_5.set_scrollbar_mode(lv.SCROLLBAR_MODE.OFF)
# Set style for top_lap_cont_5, Part: lv.PART.MAIN, State: lv.STATE.DEFAULT.
top_lap_cont_5.set_style_border_width(2, lv.PART.MAIN|lv.STATE.DEFAULT)
top_lap_cont_5.set_style_border_opa(255, lv.PART.MAIN|lv.STATE.DEFAULT)
top_lap_cont_5.set_style_border_color(lv.color_hex(0x2195f6), lv.PART.MAIN|lv.STATE.DEFAULT)
top_lap_cont_5.set_style_border_side(lv.BORDER_SIDE.FULL, lv.PART.MAIN|lv.STATE.DEFAULT)
top_lap_cont_5.set_style_radius(50, lv.PART.MAIN|lv.STATE.DEFAULT)
top_lap_cont_5.set_style_bg_opa(255, lv.PART.MAIN|lv.STATE.DEFAULT)
top_lap_cont_5.set_style_bg_color(lv.color_hex(0x00d606), lv.PART.MAIN|lv.STATE.DEFAULT)
top_lap_cont_5.set_style_bg_grad_dir(lv.GRAD_DIR.NONE, lv.PART.MAIN|lv.STATE.DEFAULT)
top_lap_cont_5.set_style_pad_top(0, lv.PART.MAIN|lv.STATE.DEFAULT)
top_lap_cont_5.set_style_pad_bottom(0, lv.PART.MAIN|lv.STATE.DEFAULT)
top_lap_cont_5.set_style_pad_left(0, lv.PART.MAIN|lv.STATE.DEFAULT)
top_lap_cont_5.set_style_pad_right(0, lv.PART.MAIN|lv.STATE.DEFAULT)
top_lap_cont_5.set_style_bg_img_src("B:MicroPython/_nfc_50x50.bin", lv.PART.MAIN|lv.STATE.DEFAULT)
top_lap_cont_5.set_style_bg_img_opa(255, lv.PART.MAIN|lv.STATE.DEFAULT)
top_lap_cont_5.set_style_bg_img_recolor_opa(0, lv.PART.MAIN|lv.STATE.DEFAULT)
top_lap_cont_5.set_style_shadow_width(0, lv.PART.MAIN|lv.STATE.DEFAULT)

# Create top_lap_cont_2
top_lap_cont_2 = lv.obj(top_lap)
top_lap_cont_2.set_pos(31, 48)
top_lap_cont_2.set_size(50, 50)
top_lap_cont_2.set_scrollbar_mode(lv.SCROLLBAR_MODE.OFF)
# Set style for top_lap_cont_2, Part: lv.PART.MAIN, State: lv.STATE.DEFAULT.
top_lap_cont_2.set_style_border_width(2, lv.PART.MAIN|lv.STATE.DEFAULT)
top_lap_cont_2.set_style_border_opa(255, lv.PART.MAIN|lv.STATE.DEFAULT)
top_lap_cont_2.set_style_border_color(lv.color_hex(0x2195f6), lv.PART.MAIN|lv.STATE.DEFAULT)
top_lap_cont_2.set_style_border_side(lv.BORDER_SIDE.FULL, lv.PART.MAIN|lv.STATE.DEFAULT)
top_lap_cont_2.set_style_radius(50, lv.PART.MAIN|lv.STATE.DEFAULT)
top_lap_cont_2.set_style_bg_opa(255, lv.PART.MAIN|lv.STATE.DEFAULT)
top_lap_cont_2.set_style_bg_color(lv.color_hex(0xf00000), lv.PART.MAIN|lv.STATE.DEFAULT)
top_lap_cont_2.set_style_bg_grad_dir(lv.GRAD_DIR.NONE, lv.PART.MAIN|lv.STATE.DEFAULT)
top_lap_cont_2.set_style_pad_top(0, lv.PART.MAIN|lv.STATE.DEFAULT)
top_lap_cont_2.set_style_pad_bottom(0, lv.PART.MAIN|lv.STATE.DEFAULT)
top_lap_cont_2.set_style_pad_left(0, lv.PART.MAIN|lv.STATE.DEFAULT)
top_lap_cont_2.set_style_pad_right(0, lv.PART.MAIN|lv.STATE.DEFAULT)
top_lap_cont_2.set_style_bg_img_src("B:MicroPython/_BT32_50x50.bin", lv.PART.MAIN|lv.STATE.DEFAULT)
top_lap_cont_2.set_style_bg_img_opa(255, lv.PART.MAIN|lv.STATE.DEFAULT)
top_lap_cont_2.set_style_bg_img_recolor_opa(0, lv.PART.MAIN|lv.STATE.DEFAULT)
top_lap_cont_2.set_style_shadow_width(0, lv.PART.MAIN|lv.STATE.DEFAULT)

# Create top_lap_slider_1
top_lap_slider_1 = lv.slider(top_lap)
top_lap_slider_1.set_range(0, 100)
top_lap_slider_1.set_mode(lv.slider.MODE.NORMAL)
top_lap_slider_1.set_value(50, lv.ANIM.OFF)
top_lap_slider_1.set_pos(12, 209)
top_lap_slider_1.set_size(220, 37)
# Set style for top_lap_slider_1, Part: lv.PART.MAIN, State: lv.STATE.DEFAULT.
top_lap_slider_1.set_style_bg_opa(134, lv.PART.MAIN|lv.STATE.DEFAULT)
top_lap_slider_1.set_style_bg_color(lv.color_hex(0xffbf4c), lv.PART.MAIN|lv.STATE.DEFAULT)
top_lap_slider_1.set_style_bg_grad_dir(lv.GRAD_DIR.NONE, lv.PART.MAIN|lv.STATE.DEFAULT)
top_lap_slider_1.set_style_radius(8, lv.PART.MAIN|lv.STATE.DEFAULT)
top_lap_slider_1.set_style_outline_width(0, lv.PART.MAIN|lv.STATE.DEFAULT)
top_lap_slider_1.set_style_shadow_width(0, lv.PART.MAIN|lv.STATE.DEFAULT)

# Set style for top_lap_slider_1, Part: lv.PART.INDICATOR, State: lv.STATE.DEFAULT.
top_lap_slider_1.set_style_bg_opa(255, lv.PART.INDICATOR|lv.STATE.DEFAULT)
top_lap_slider_1.set_style_bg_color(lv.color_hex(0xfbae00), lv.PART.INDICATOR|lv.STATE.DEFAULT)
top_lap_slider_1.set_style_bg_grad_dir(lv.GRAD_DIR.NONE, lv.PART.INDICATOR|lv.STATE.DEFAULT)
top_lap_slider_1.set_style_radius(8, lv.PART.INDICATOR|lv.STATE.DEFAULT)

# Set style for top_lap_slider_1, Part: lv.PART.KNOB, State: lv.STATE.DEFAULT.
top_lap_slider_1.set_style_bg_opa(255, lv.PART.KNOB|lv.STATE.DEFAULT)
top_lap_slider_1.set_style_bg_color(lv.color_hex(0xff9d00), lv.PART.KNOB|lv.STATE.DEFAULT)
top_lap_slider_1.set_style_bg_grad_dir(lv.GRAD_DIR.NONE, lv.PART.KNOB|lv.STATE.DEFAULT)
top_lap_slider_1.set_style_bg_img_src("B:MicroPython/_liangdu_47x47.bin", lv.PART.KNOB|lv.STATE.DEFAULT)
top_lap_slider_1.set_style_bg_img_opa(255, lv.PART.KNOB|lv.STATE.DEFAULT)
top_lap_slider_1.set_style_bg_img_recolor_opa(0, lv.PART.KNOB|lv.STATE.DEFAULT)
top_lap_slider_1.set_style_radius(8, lv.PART.KNOB|lv.STATE.DEFAULT)

# Create top_lap_cont_3
top_lap_cont_3 = lv.obj(top_lap)
top_lap_cont_3.set_pos(151, 48)
top_lap_cont_3.set_size(50, 50)
top_lap_cont_3.set_scrollbar_mode(lv.SCROLLBAR_MODE.OFF)
# Set style for top_lap_cont_3, Part: lv.PART.MAIN, State: lv.STATE.DEFAULT.
top_lap_cont_3.set_style_border_width(2, lv.PART.MAIN|lv.STATE.DEFAULT)
top_lap_cont_3.set_style_border_opa(255, lv.PART.MAIN|lv.STATE.DEFAULT)
top_lap_cont_3.set_style_border_color(lv.color_hex(0x2195f6), lv.PART.MAIN|lv.STATE.DEFAULT)
top_lap_cont_3.set_style_border_side(lv.BORDER_SIDE.FULL, lv.PART.MAIN|lv.STATE.DEFAULT)
top_lap_cont_3.set_style_radius(50, lv.PART.MAIN|lv.STATE.DEFAULT)
top_lap_cont_3.set_style_bg_opa(255, lv.PART.MAIN|lv.STATE.DEFAULT)
top_lap_cont_3.set_style_bg_color(lv.color_hex(0xffab00), lv.PART.MAIN|lv.STATE.DEFAULT)
top_lap_cont_3.set_style_bg_grad_dir(lv.GRAD_DIR.NONE, lv.PART.MAIN|lv.STATE.DEFAULT)
top_lap_cont_3.set_style_pad_top(0, lv.PART.MAIN|lv.STATE.DEFAULT)
top_lap_cont_3.set_style_pad_bottom(0, lv.PART.MAIN|lv.STATE.DEFAULT)
top_lap_cont_3.set_style_pad_left(0, lv.PART.MAIN|lv.STATE.DEFAULT)
top_lap_cont_3.set_style_pad_right(0, lv.PART.MAIN|lv.STATE.DEFAULT)
top_lap_cont_3.set_style_bg_img_src("B:MicroPython/_location_50x50.bin", lv.PART.MAIN|lv.STATE.DEFAULT)
top_lap_cont_3.set_style_bg_img_opa(255, lv.PART.MAIN|lv.STATE.DEFAULT)
top_lap_cont_3.set_style_bg_img_recolor_opa(0, lv.PART.MAIN|lv.STATE.DEFAULT)
top_lap_cont_3.set_style_shadow_width(0, lv.PART.MAIN|lv.STATE.DEFAULT)

# Create top_lap_img_1
top_lap_img_1 = lv.img(top_lap)
top_lap_img_1.set_src("B:MicroPython/_power_over_alpha_50x50.bin")
top_lap_img_1.add_flag(lv.obj.FLAG.CLICKABLE)
top_lap_img_1.set_pivot(50,50)
top_lap_img_1.set_angle(0)
top_lap_img_1.set_pos(159, 0)
top_lap_img_1.set_size(50, 50)
# Set style for top_lap_img_1, Part: lv.PART.MAIN, State: lv.STATE.DEFAULT.
top_lap_img_1.set_style_img_opa(255, lv.PART.MAIN|lv.STATE.DEFAULT)
top_lap_img_1.set_style_radius(0, lv.PART.MAIN|lv.STATE.DEFAULT)
top_lap_img_1.set_style_clip_corner(True, lv.PART.MAIN|lv.STATE.DEFAULT)

top_lap.update_layout()
# Create under
under = lv.obj()
under.set_size(240, 280)
under.set_scrollbar_mode(lv.SCROLLBAR_MODE.OFF)
# Set style for under, Part: lv.PART.MAIN, State: lv.STATE.DEFAULT.
under.set_style_bg_opa(0, lv.PART.MAIN|lv.STATE.DEFAULT)

# Create under_cont_1
under_cont_1 = lv.obj(under)
under_cont_1.set_pos(0, 0)
under_cont_1.set_size(240, 280)
under_cont_1.set_scrollbar_mode(lv.SCROLLBAR_MODE.OFF)
# Set style for under_cont_1, Part: lv.PART.MAIN, State: lv.STATE.DEFAULT.
under_cont_1.set_style_border_width(2, lv.PART.MAIN|lv.STATE.DEFAULT)
under_cont_1.set_style_border_opa(255, lv.PART.MAIN|lv.STATE.DEFAULT)
under_cont_1.set_style_border_color(lv.color_hex(0x2195f6), lv.PART.MAIN|lv.STATE.DEFAULT)
under_cont_1.set_style_border_side(lv.BORDER_SIDE.FULL, lv.PART.MAIN|lv.STATE.DEFAULT)
under_cont_1.set_style_radius(40, lv.PART.MAIN|lv.STATE.DEFAULT)
under_cont_1.set_style_bg_opa(255, lv.PART.MAIN|lv.STATE.DEFAULT)
under_cont_1.set_style_bg_color(lv.color_hex(0x000000), lv.PART.MAIN|lv.STATE.DEFAULT)
under_cont_1.set_style_bg_grad_dir(lv.GRAD_DIR.NONE, lv.PART.MAIN|lv.STATE.DEFAULT)
under_cont_1.set_style_pad_top(0, lv.PART.MAIN|lv.STATE.DEFAULT)
under_cont_1.set_style_pad_bottom(0, lv.PART.MAIN|lv.STATE.DEFAULT)
under_cont_1.set_style_pad_left(0, lv.PART.MAIN|lv.STATE.DEFAULT)
under_cont_1.set_style_pad_right(0, lv.PART.MAIN|lv.STATE.DEFAULT)
under_cont_1.set_style_shadow_width(0, lv.PART.MAIN|lv.STATE.DEFAULT)
# Create under_cont_2
under_cont_2 = lv.obj(under_cont_1)
under_cont_2.set_pos(152, 33)
under_cont_2.set_size(50, 50)
under_cont_2.set_scrollbar_mode(lv.SCROLLBAR_MODE.OFF)
# Set style for under_cont_2, Part: lv.PART.MAIN, State: lv.STATE.DEFAULT.
under_cont_2.set_style_border_width(2, lv.PART.MAIN|lv.STATE.DEFAULT)
under_cont_2.set_style_border_opa(255, lv.PART.MAIN|lv.STATE.DEFAULT)
under_cont_2.set_style_border_color(lv.color_hex(0x2195f6), lv.PART.MAIN|lv.STATE.DEFAULT)
under_cont_2.set_style_border_side(lv.BORDER_SIDE.FULL, lv.PART.MAIN|lv.STATE.DEFAULT)
under_cont_2.set_style_radius(50, lv.PART.MAIN|lv.STATE.DEFAULT)
under_cont_2.set_style_bg_opa(255, lv.PART.MAIN|lv.STATE.DEFAULT)
under_cont_2.set_style_bg_color(lv.color_hex(0x00d606), lv.PART.MAIN|lv.STATE.DEFAULT)
under_cont_2.set_style_bg_grad_dir(lv.GRAD_DIR.NONE, lv.PART.MAIN|lv.STATE.DEFAULT)
under_cont_2.set_style_pad_top(0, lv.PART.MAIN|lv.STATE.DEFAULT)
under_cont_2.set_style_pad_bottom(0, lv.PART.MAIN|lv.STATE.DEFAULT)
under_cont_2.set_style_pad_left(0, lv.PART.MAIN|lv.STATE.DEFAULT)
under_cont_2.set_style_pad_right(0, lv.PART.MAIN|lv.STATE.DEFAULT)
under_cont_2.set_style_bg_img_src("B:MicroPython/_nfc_50x50.bin", lv.PART.MAIN|lv.STATE.DEFAULT)
under_cont_2.set_style_bg_img_opa(255, lv.PART.MAIN|lv.STATE.DEFAULT)
under_cont_2.set_style_bg_img_recolor_opa(0, lv.PART.MAIN|lv.STATE.DEFAULT)
under_cont_2.set_style_shadow_width(0, lv.PART.MAIN|lv.STATE.DEFAULT)

# Create under_img_1
under_img_1 = lv.img(under)
under_img_1.set_src("B:MicroPython/_ZNZBG_alpha_100x100.bin")
under_img_1.add_flag(lv.obj.FLAG.CLICKABLE)
under_img_1.set_pivot(50,50)
under_img_1.set_angle(0)
under_img_1.set_pos(70, 90)
under_img_1.set_size(100, 100)
# Set style for under_img_1, Part: lv.PART.MAIN, State: lv.STATE.DEFAULT.
under_img_1.set_style_img_opa(255, lv.PART.MAIN|lv.STATE.DEFAULT)
under_img_1.set_style_radius(0, lv.PART.MAIN|lv.STATE.DEFAULT)
under_img_1.set_style_clip_corner(True, lv.PART.MAIN|lv.STATE.DEFAULT)

under.update_layout()

def screen_1_home_event_handler(e):
    code = e.get_code()
    indev = lv.indev_get_act()
    gestureDir = lv.DIR.NONE
    if indev is not None: gestureDir = indev.get_gesture_dir()
    if (code == lv.EVENT.GESTURE and lv.DIR.LEFT == gestureDir):
        if indev is not None: indev.wait_release()
        pass
        lv.scr_load_anim(screen_2, lv.SCR_LOAD_ANIM.NONE, 200, 2, False)
        

    indev = lv.indev_get_act()
    gestureDir = lv.DIR.NONE
    if indev is not None: gestureDir = indev.get_gesture_dir()
    if (code == lv.EVENT.GESTURE and lv.DIR.BOTTOM == gestureDir):
        if indev is not None: indev.wait_release()
        pass
        lv.scr_load_anim(top_lap, lv.SCR_LOAD_ANIM.NONE, 200, 2, False)
    indev = lv.indev_get_act()
    gestureDir = lv.DIR.NONE
    if indev is not None: gestureDir = indev.get_gesture_dir()
    if (code == lv.EVENT.GESTURE and lv.DIR.TOP == gestureDir):
        if indev is not None: indev.wait_release()
        pass
        lv.scr_load_anim(under, lv.SCR_LOAD_ANIM.NONE, 200, 200, False)
    if (code == lv.EVENT.LONG_PRESSED):
        pass
        screen_1_home_cont_shadow.clear_flag(lv.obj.FLAG.HIDDEN)
        #Write animation: screen_1_home_cont_shadow x
        screen_1_home_cont_shadow_anim_x = lv.anim_t()
        screen_1_home_cont_shadow_anim_x.init()
        screen_1_home_cont_shadow_anim_x.set_var(screen_1_home_cont_shadow)
        screen_1_home_cont_shadow_anim_x.set_time(200)
        screen_1_home_cont_shadow_anim_x.set_delay(0)
        screen_1_home_cont_shadow_anim_x.set_custom_exec_cb(lambda e,val: anim_x_cb(screen_1_home_cont_shadow,val))
        screen_1_home_cont_shadow_anim_x.set_values(screen_1_home_cont_shadow.get_x(), 120)
        screen_1_home_cont_shadow_anim_x.set_path_cb(lv.anim_t.path_overshoot)
        screen_1_home_cont_shadow_anim_x.set_repeat_count(2)
        screen_1_home_cont_shadow_anim_x.set_repeat_delay(0)
        screen_1_home_cont_shadow_anim_x.set_playback_time(0)
        screen_1_home_cont_shadow_anim_x.set_playback_delay(0)
        screen_1_home_cont_shadow_anim_x.start()
        #Write animation: screen_1_home_cont_slide x
        screen_1_home_cont_slide_anim_x = lv.anim_t()
        screen_1_home_cont_slide_anim_x.init()
        screen_1_home_cont_slide_anim_x.set_var(screen_1_home_cont_slide)
        screen_1_home_cont_slide_anim_x.set_time(200)
        screen_1_home_cont_slide_anim_x.set_delay(0)
        screen_1_home_cont_slide_anim_x.set_custom_exec_cb(lambda e,val: anim_x_cb(screen_1_home_cont_slide,val))
        screen_1_home_cont_slide_anim_x.set_values(screen_1_home_cont_slide.get_x(), 0)
        screen_1_home_cont_slide_anim_x.set_path_cb(lv.anim_t.path_step)
        screen_1_home_cont_slide_anim_x.set_repeat_count(2)
        screen_1_home_cont_slide_anim_x.set_repeat_delay(0)
        screen_1_home_cont_slide_anim_x.set_playback_time(0)
        screen_1_home_cont_slide_anim_x.set_playback_delay(0)
        screen_1_home_cont_slide_anim_x.start()
screen_1_home.add_event_cb(lambda e: screen_1_home_event_handler(e), lv.EVENT.ALL, None)

def screen_1_home_cont_shadow_event_handler(e):
    code = e.get_code()
    if (code == lv.EVENT.LONG_PRESSED):
        pass
        screen_1_home_cont_shadow.add_flag(lv.obj.FLAG.HIDDEN)
        #Write animation: screen_1_home_cont_shadow x
        screen_1_home_cont_shadow_anim_x = lv.anim_t()
        screen_1_home_cont_shadow_anim_x.init()
        screen_1_home_cont_shadow_anim_x.set_var(screen_1_home_cont_shadow)
        screen_1_home_cont_shadow_anim_x.set_time(200)
        screen_1_home_cont_shadow_anim_x.set_delay(0)
        screen_1_home_cont_shadow_anim_x.set_custom_exec_cb(lambda e,val: anim_x_cb(screen_1_home_cont_shadow,val))
        screen_1_home_cont_shadow_anim_x.set_values(screen_1_home_cont_shadow.get_x(), 0)
        screen_1_home_cont_shadow_anim_x.set_path_cb(lv.anim_t.path_overshoot)
        screen_1_home_cont_shadow_anim_x.set_repeat_count(1)
        screen_1_home_cont_shadow_anim_x.set_repeat_delay(0)
        screen_1_home_cont_shadow_anim_x.set_playback_time(0)
        screen_1_home_cont_shadow_anim_x.set_playback_delay(0)
        screen_1_home_cont_shadow_anim_x.start()
        #Write animation: screen_1_home_cont_slide x
        screen_1_home_cont_slide_anim_x = lv.anim_t()
        screen_1_home_cont_slide_anim_x.init()
        screen_1_home_cont_slide_anim_x.set_var(screen_1_home_cont_slide)
        screen_1_home_cont_slide_anim_x.set_time(200)
        screen_1_home_cont_slide_anim_x.set_delay(0)
        screen_1_home_cont_slide_anim_x.set_custom_exec_cb(lambda e,val: anim_x_cb(screen_1_home_cont_slide,val))
        screen_1_home_cont_slide_anim_x.set_values(screen_1_home_cont_slide.get_x(), -120)
        screen_1_home_cont_slide_anim_x.set_path_cb(lv.anim_t.path_overshoot)
        screen_1_home_cont_slide_anim_x.set_repeat_count(1)
        screen_1_home_cont_slide_anim_x.set_repeat_delay(0)
        screen_1_home_cont_slide_anim_x.set_playback_time(0)
        screen_1_home_cont_slide_anim_x.set_playback_delay(0)
        screen_1_home_cont_slide_anim_x.start()
screen_1_home_cont_shadow.add_event_cb(lambda e: screen_1_home_cont_shadow_event_handler(e), lv.EVENT.ALL, None)

def screen_2_event_handler(e):
    code = e.get_code()
    indev = lv.indev_get_act()
    gestureDir = lv.DIR.NONE
    if indev is not None: gestureDir = indev.get_gesture_dir()
    if (code == lv.EVENT.GESTURE and lv.DIR.LEFT == gestureDir):
        if indev is not None: indev.wait_release()
        pass
        lv.scr_load_anim(screen_3, lv.SCR_LOAD_ANIM.NONE, 200, 2, False)
        

    indev = lv.indev_get_act()
    gestureDir = lv.DIR.NONE
    if indev is not None: gestureDir = indev.get_gesture_dir()
    if (code == lv.EVENT.GESTURE and lv.DIR.BOTTOM == gestureDir):
        if indev is not None: indev.wait_release()
        pass
        lv.scr_load_anim(top_lap, lv.SCR_LOAD_ANIM.OVER_BOTTOM, 200, 2, False)
    if (code == lv.EVENT.LONG_PRESSED):
        pass
        #Write animation: screen_2_cont_4 x
        screen_2_cont_4_anim_x = lv.anim_t()
        screen_2_cont_4_anim_x.init()
        screen_2_cont_4_anim_x.set_var(screen_2_cont_4)
        screen_2_cont_4_anim_x.set_time(20)
        screen_2_cont_4_anim_x.set_delay(0)
        screen_2_cont_4_anim_x.set_custom_exec_cb(lambda e,val: anim_x_cb(screen_2_cont_4,val))
        screen_2_cont_4_anim_x.set_values(screen_2_cont_4.get_x(), 120)
        screen_2_cont_4_anim_x.set_path_cb(lv.anim_t.path_step)
        screen_2_cont_4_anim_x.set_repeat_count(1)
        screen_2_cont_4_anim_x.set_repeat_delay(0)
        screen_2_cont_4_anim_x.set_playback_time(0)
        screen_2_cont_4_anim_x.set_playback_delay(0)
        screen_2_cont_4_anim_x.start()
        screen_2_cont_4.clear_flag(lv.obj.FLAG.HIDDEN)
        #Write animation: screen_2_cont_3 x
        screen_2_cont_3_anim_x = lv.anim_t()
        screen_2_cont_3_anim_x.init()
        screen_2_cont_3_anim_x.set_var(screen_2_cont_3)
        screen_2_cont_3_anim_x.set_time(20)
        screen_2_cont_3_anim_x.set_delay(0)
        screen_2_cont_3_anim_x.set_custom_exec_cb(lambda e,val: anim_x_cb(screen_2_cont_3,val))
        screen_2_cont_3_anim_x.set_values(screen_2_cont_3.get_x(), 0)
        screen_2_cont_3_anim_x.set_path_cb(lv.anim_t.path_step)
        screen_2_cont_3_anim_x.set_repeat_count(1)
        screen_2_cont_3_anim_x.set_repeat_delay(0)
        screen_2_cont_3_anim_x.set_playback_time(0)
        screen_2_cont_3_anim_x.set_playback_delay(0)
        screen_2_cont_3_anim_x.start()
screen_2.add_event_cb(lambda e: screen_2_event_handler(e), lv.EVENT.ALL, None)

def screen_3_event_handler(e):
    code = e.get_code()
    indev = lv.indev_get_act()
    gestureDir = lv.DIR.NONE
    if indev is not None: gestureDir = indev.get_gesture_dir()
    if (code == lv.EVENT.GESTURE and lv.DIR.LEFT == gestureDir):
        if indev is not None: indev.wait_release()
        pass
        lv.scr_load_anim(screen_1_home, lv.SCR_LOAD_ANIM.MOVE_RIGHT, 200, 2, False)
        

    indev = lv.indev_get_act()
    gestureDir = lv.DIR.NONE
    if indev is not None: gestureDir = indev.get_gesture_dir()
    if (code == lv.EVENT.GESTURE and lv.DIR.TOP == gestureDir):
        if indev is not None: indev.wait_release()
        pass
        lv.scr_load_anim(under, lv.SCR_LOAD_ANIM.OVER_BOTTOM, 200, 2, False)
screen_3.add_event_cb(lambda e: screen_3_event_handler(e), lv.EVENT.ALL, None)

def top_lap_event_handler(e):
    code = e.get_code()
    indev = lv.indev_get_act()
    gestureDir = lv.DIR.NONE
    if indev is not None: gestureDir = indev.get_gesture_dir()
    if (code == lv.EVENT.GESTURE and lv.DIR.TOP == gestureDir):
        if indev is not None: indev.wait_release()
        pass
        lv.scr_load_anim(screen_1_home, lv.SCR_LOAD_ANIM.NONE, 200, 200, False)
top_lap.add_event_cb(lambda e: top_lap_event_handler(e), lv.EVENT.ALL, None)

def under_event_handler(e):
    code = e.get_code()
    indev = lv.indev_get_act()
    gestureDir = lv.DIR.NONE
    if indev is not None: gestureDir = indev.get_gesture_dir()
    if (code == lv.EVENT.GESTURE and lv.DIR.BOTTOM == gestureDir):
        if indev is not None: indev.wait_release()
        pass
        lv.scr_load_anim(screen_1_home, lv.SCR_LOAD_ANIM.NONE, 200, 2, False)
under.add_event_cb(lambda e: under_event_handler(e), lv.EVENT.ALL, None)

# content from custom.py

# Load the default screen
lv.scr_load(screen_1_home)

while SDL.check():
    time.sleep_ms(5)

