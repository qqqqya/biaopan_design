/*
* Copyright 2026 NXP
* NXP Proprietary. This software is owned or controlled by NXP and may only be used strictly in
* accordance with the applicable license terms. By expressly accepting such terms or by downloading, installing,
* activating and/or otherwise using the software, you are agreeing that you have read, and that you agree to
* comply with and are bound by, such license terms.  If you do not agree to be bound by the applicable license
* terms, then you may not retain, install, activate or otherwise use the software.
*/

#include "lvgl.h"
#include <stdio.h>
#include "gui_guider.h"
#include "events_init.h"
#include "widgets_init.h"
#include "custom.h"



int screen_1_home_analog_clock_1_hour_value = 3;
int screen_1_home_analog_clock_1_min_value = 3;
int screen_1_home_analog_clock_1_sec_value = 50;
void setup_scr_screen_1_home(lv_ui *ui)
{
    //Write codes screen_1_home
    ui->screen_1_home = lv_obj_create(NULL);
    lv_obj_set_size(ui->screen_1_home, 240, 280);
    lv_obj_set_scrollbar_mode(ui->screen_1_home, LV_SCROLLBAR_MODE_OFF);

    //Write style for screen_1_home, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
    lv_obj_set_style_bg_opa(ui->screen_1_home, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_color(ui->screen_1_home, lv_color_hex(0x000000), LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_grad_dir(ui->screen_1_home, LV_GRAD_DIR_NONE, LV_PART_MAIN|LV_STATE_DEFAULT);

    //Write codes screen_1_home_analog_clock_1
    static bool screen_1_home_analog_clock_1_timer_enabled = false;
    ui->screen_1_home_analog_clock_1 = lv_analogclock_create(ui->screen_1_home);
    lv_analogclock_hide_digits(ui->screen_1_home_analog_clock_1, true);
    lv_analogclock_set_major_ticks(ui->screen_1_home_analog_clock_1, 2, 10, lv_color_hex(0x555555), 10);
    lv_analogclock_set_ticks(ui->screen_1_home_analog_clock_1, 2, 5, lv_color_hex(0x333333));
    lv_analogclock_set_hour_needle_line(ui->screen_1_home_analog_clock_1, 2, lv_color_hex(0xffffff), -40);
    lv_analogclock_set_min_needle_line(ui->screen_1_home_analog_clock_1, 2, lv_color_hex(0xffffff), -30);
    lv_analogclock_set_sec_needle_line(ui->screen_1_home_analog_clock_1, 2, lv_color_hex(0xff0027), -10);
    lv_analogclock_set_time(ui->screen_1_home_analog_clock_1, screen_1_home_analog_clock_1_hour_value, screen_1_home_analog_clock_1_min_value,screen_1_home_analog_clock_1_sec_value);
    // create timer
    if (!screen_1_home_analog_clock_1_timer_enabled) {
        lv_timer_create(screen_1_home_analog_clock_1_timer, 1000, NULL);
        screen_1_home_analog_clock_1_timer_enabled = true;
    }
    lv_obj_set_pos(ui->screen_1_home_analog_clock_1, 20, 41);
    lv_obj_set_size(ui->screen_1_home_analog_clock_1, 200, 200);

    //Write style for screen_1_home_analog_clock_1, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
    lv_obj_set_style_bg_opa(ui->screen_1_home_analog_clock_1, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_color(ui->screen_1_home_analog_clock_1, lv_color_hex(0xffffff), LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_grad_dir(ui->screen_1_home_analog_clock_1, LV_GRAD_DIR_NONE, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_border_width(ui->screen_1_home_analog_clock_1, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_width(ui->screen_1_home_analog_clock_1, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_img_src(ui->screen_1_home_analog_clock_1, &_biaopan1_200x200, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_img_opa(ui->screen_1_home_analog_clock_1, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_img_recolor_opa(ui->screen_1_home_analog_clock_1, 0, LV_PART_MAIN|LV_STATE_DEFAULT);

    //Write style for screen_1_home_analog_clock_1, Part: LV_PART_TICKS, State: LV_STATE_DEFAULT.
    lv_obj_set_style_text_color(ui->screen_1_home_analog_clock_1, lv_color_hex(0xff0000), LV_PART_TICKS|LV_STATE_DEFAULT);
    lv_obj_set_style_text_font(ui->screen_1_home_analog_clock_1, &lv_font_montserratMedium_12, LV_PART_TICKS|LV_STATE_DEFAULT);
    lv_obj_set_style_text_opa(ui->screen_1_home_analog_clock_1, 255, LV_PART_TICKS|LV_STATE_DEFAULT);

    //Write style for screen_1_home_analog_clock_1, Part: LV_PART_INDICATOR, State: LV_STATE_DEFAULT.
    lv_obj_set_style_bg_opa(ui->screen_1_home_analog_clock_1, 255, LV_PART_INDICATOR|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_color(ui->screen_1_home_analog_clock_1, lv_color_hex(0x000000), LV_PART_INDICATOR|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_grad_dir(ui->screen_1_home_analog_clock_1, LV_GRAD_DIR_NONE, LV_PART_INDICATOR|LV_STATE_DEFAULT);

    //Write codes screen_1_home_img_2
    ui->screen_1_home_img_2 = lv_img_create(ui->screen_1_home);
    lv_obj_add_flag(ui->screen_1_home_img_2, LV_OBJ_FLAG_CLICKABLE);
    lv_img_set_src(ui->screen_1_home_img_2, &_Ellipse_alpha_26x30);
    lv_img_set_pivot(ui->screen_1_home_img_2, 50,50);
    lv_img_set_angle(ui->screen_1_home_img_2, 0);
    lv_obj_set_pos(ui->screen_1_home_img_2, 21, 24);
    lv_obj_set_size(ui->screen_1_home_img_2, 26, 30);

    //Write style for screen_1_home_img_2, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
    lv_obj_set_style_radius(ui->screen_1_home_img_2, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_clip_corner(ui->screen_1_home_img_2, true, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_img_recolor_opa(ui->screen_1_home_img_2, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_img_opa(ui->screen_1_home_img_2, 255, LV_PART_MAIN|LV_STATE_DEFAULT);

    //Write codes screen_1_home_img_3
    ui->screen_1_home_img_3 = lv_img_create(ui->screen_1_home);
    lv_obj_add_flag(ui->screen_1_home_img_3, LV_OBJ_FLAG_CLICKABLE);
    lv_img_set_src(ui->screen_1_home_img_3, &_watchdight3_alpha_61x68);
    lv_img_set_pivot(ui->screen_1_home_img_3, 50,50);
    lv_img_set_angle(ui->screen_1_home_img_3, 0);
    lv_obj_set_pos(ui->screen_1_home_img_3, 164, 43);
    lv_obj_set_size(ui->screen_1_home_img_3, 61, 68);

    //Write style for screen_1_home_img_3, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
    lv_obj_set_style_radius(ui->screen_1_home_img_3, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_clip_corner(ui->screen_1_home_img_3, true, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_img_recolor_opa(ui->screen_1_home_img_3, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_img_opa(ui->screen_1_home_img_3, 255, LV_PART_MAIN|LV_STATE_DEFAULT);

    //Write codes screen_1_home_img_4
    ui->screen_1_home_img_4 = lv_img_create(ui->screen_1_home);
    lv_obj_add_flag(ui->screen_1_home_img_4, LV_OBJ_FLAG_CLICKABLE);
    lv_img_set_src(ui->screen_1_home_img_4, &_watchdight2_alpha_51x57);
    lv_img_set_pivot(ui->screen_1_home_img_4, 50,50);
    lv_img_set_angle(ui->screen_1_home_img_4, 0);
    lv_obj_set_pos(ui->screen_1_home_img_4, 25, 188);
    lv_obj_set_size(ui->screen_1_home_img_4, 51, 57);

    //Write style for screen_1_home_img_4, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
    lv_obj_set_style_img_recolor_opa(ui->screen_1_home_img_4, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_img_opa(ui->screen_1_home_img_4, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_radius(ui->screen_1_home_img_4, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_clip_corner(ui->screen_1_home_img_4, true, LV_PART_MAIN|LV_STATE_DEFAULT);

    //Write codes screen_1_home_img_5
    ui->screen_1_home_img_5 = lv_img_create(ui->screen_1_home);
    lv_obj_add_flag(ui->screen_1_home_img_5, LV_OBJ_FLAG_CLICKABLE);
    lv_img_set_src(ui->screen_1_home_img_5, &_watchdight1_alpha_56x59);
    lv_img_set_pivot(ui->screen_1_home_img_5, 50,50);
    lv_img_set_angle(ui->screen_1_home_img_5, 0);
    lv_obj_set_pos(ui->screen_1_home_img_5, 25, 43);
    lv_obj_set_size(ui->screen_1_home_img_5, 56, 59);

    //Write style for screen_1_home_img_5, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
    lv_obj_set_style_radius(ui->screen_1_home_img_5, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_clip_corner(ui->screen_1_home_img_5, true, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_img_recolor_opa(ui->screen_1_home_img_5, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_img_opa(ui->screen_1_home_img_5, 255, LV_PART_MAIN|LV_STATE_DEFAULT);

    //Write codes screen_1_home_cont_slide
    ui->screen_1_home_cont_slide = lv_obj_create(ui->screen_1_home);
    lv_obj_set_pos(ui->screen_1_home_cont_slide, -136, 0);
    lv_obj_set_size(ui->screen_1_home_cont_slide, 120, 280);
    lv_obj_set_scrollbar_mode(ui->screen_1_home_cont_slide, LV_SCROLLBAR_MODE_OFF);

    //Write style for screen_1_home_cont_slide, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
    lv_obj_set_style_radius(ui->screen_1_home_cont_slide, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ui->screen_1_home_cont_slide, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_color(ui->screen_1_home_cont_slide, lv_color_hex(0x000000), LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_grad_dir(ui->screen_1_home_cont_slide, LV_GRAD_DIR_NONE, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_border_width(ui->screen_1_home_cont_slide, 2, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_border_opa(ui->screen_1_home_cont_slide, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_border_color(ui->screen_1_home_cont_slide, lv_color_hex(0x000000), LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_border_side(ui->screen_1_home_cont_slide, LV_BORDER_SIDE_FULL, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_width(ui->screen_1_home_cont_slide, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_top(ui->screen_1_home_cont_slide, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_bottom(ui->screen_1_home_cont_slide, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_left(ui->screen_1_home_cont_slide, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_right(ui->screen_1_home_cont_slide, 0, LV_PART_MAIN|LV_STATE_DEFAULT);

    //Write codes screen_1_home_btn_3
    ui->screen_1_home_btn_3 = lv_btn_create(ui->screen_1_home_cont_slide);
    ui->screen_1_home_btn_3_label = lv_label_create(ui->screen_1_home_btn_3);
    lv_label_set_text(ui->screen_1_home_btn_3_label, " ");
    lv_label_set_long_mode(ui->screen_1_home_btn_3_label, LV_LABEL_LONG_WRAP);
    lv_obj_align(ui->screen_1_home_btn_3_label, LV_ALIGN_CENTER, 0, 0);
    lv_obj_set_style_pad_all(ui->screen_1_home_btn_3, 0, LV_STATE_DEFAULT);
    lv_obj_set_width(ui->screen_1_home_btn_3_label, LV_PCT(100));
    lv_obj_set_pos(ui->screen_1_home_btn_3, 61, 202);
    lv_obj_set_size(ui->screen_1_home_btn_3, 50, 50);

    //Write style for screen_1_home_btn_3, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
    lv_obj_set_style_radius(ui->screen_1_home_btn_3, 5, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ui->screen_1_home_btn_3, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_color(ui->screen_1_home_btn_3, lv_color_hex(0x5a5a5a), LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_grad_dir(ui->screen_1_home_btn_3, LV_GRAD_DIR_NONE, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_border_width(ui->screen_1_home_btn_3, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_width(ui->screen_1_home_btn_3, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_color(ui->screen_1_home_btn_3, lv_color_hex(0xffffff), LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_font(ui->screen_1_home_btn_3, &lv_font_montserratMedium_16, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_opa(ui->screen_1_home_btn_3, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_align(ui->screen_1_home_btn_3, LV_TEXT_ALIGN_CENTER, LV_PART_MAIN|LV_STATE_DEFAULT);

    //Write codes screen_1_home_btn_2
    ui->screen_1_home_btn_2 = lv_btn_create(ui->screen_1_home_cont_slide);
    ui->screen_1_home_btn_2_label = lv_label_create(ui->screen_1_home_btn_2);
    lv_label_set_text(ui->screen_1_home_btn_2_label, " ");
    lv_label_set_long_mode(ui->screen_1_home_btn_2_label, LV_LABEL_LONG_WRAP);
    lv_obj_align(ui->screen_1_home_btn_2_label, LV_ALIGN_CENTER, 0, 0);
    lv_obj_set_style_pad_all(ui->screen_1_home_btn_2, 0, LV_STATE_DEFAULT);
    lv_obj_set_width(ui->screen_1_home_btn_2_label, LV_PCT(100));
    lv_obj_set_pos(ui->screen_1_home_btn_2, 10, 143);
    lv_obj_set_size(ui->screen_1_home_btn_2, 100, 50);

    //Write style for screen_1_home_btn_2, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
    lv_obj_set_style_radius(ui->screen_1_home_btn_2, 5, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ui->screen_1_home_btn_2, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_color(ui->screen_1_home_btn_2, lv_color_hex(0x5a5a5a), LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_grad_dir(ui->screen_1_home_btn_2, LV_GRAD_DIR_NONE, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_border_width(ui->screen_1_home_btn_2, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_width(ui->screen_1_home_btn_2, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_color(ui->screen_1_home_btn_2, lv_color_hex(0xffffff), LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_font(ui->screen_1_home_btn_2, &lv_font_montserratMedium_16, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_opa(ui->screen_1_home_btn_2, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_align(ui->screen_1_home_btn_2, LV_TEXT_ALIGN_CENTER, LV_PART_MAIN|LV_STATE_DEFAULT);

    //Write codes screen_1_home_btn_1
    ui->screen_1_home_btn_1 = lv_btn_create(ui->screen_1_home_cont_slide);
    ui->screen_1_home_btn_1_label = lv_label_create(ui->screen_1_home_btn_1);
    lv_label_set_text(ui->screen_1_home_btn_1_label, " ");
    lv_label_set_long_mode(ui->screen_1_home_btn_1_label, LV_LABEL_LONG_WRAP);
    lv_obj_align(ui->screen_1_home_btn_1_label, LV_ALIGN_CENTER, 0, 0);
    lv_obj_set_style_pad_all(ui->screen_1_home_btn_1, 0, LV_STATE_DEFAULT);
    lv_obj_set_width(ui->screen_1_home_btn_1_label, LV_PCT(100));
    lv_obj_set_pos(ui->screen_1_home_btn_1, 7, 202);
    lv_obj_set_size(ui->screen_1_home_btn_1, 50, 50);

    //Write style for screen_1_home_btn_1, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
    lv_obj_set_style_radius(ui->screen_1_home_btn_1, 5, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ui->screen_1_home_btn_1, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_color(ui->screen_1_home_btn_1, lv_color_hex(0x5a5a5a), LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_grad_dir(ui->screen_1_home_btn_1, LV_GRAD_DIR_NONE, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_border_width(ui->screen_1_home_btn_1, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_width(ui->screen_1_home_btn_1, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_color(ui->screen_1_home_btn_1, lv_color_hex(0xffffff), LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_font(ui->screen_1_home_btn_1, &lv_font_montserratMedium_16, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_opa(ui->screen_1_home_btn_1, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_align(ui->screen_1_home_btn_1, LV_TEXT_ALIGN_CENTER, LV_PART_MAIN|LV_STATE_DEFAULT);

    //Write codes screen_1_home_img_8
    ui->screen_1_home_img_8 = lv_img_create(ui->screen_1_home_cont_slide);
    lv_obj_add_flag(ui->screen_1_home_img_8, LV_OBJ_FLAG_CLICKABLE);
    lv_img_set_src(ui->screen_1_home_img_8, &_zhengdong_0_alpha_30x30);
    lv_img_set_pivot(ui->screen_1_home_img_8, 50,50);
    lv_img_set_angle(ui->screen_1_home_img_8, 0);
    lv_obj_set_pos(ui->screen_1_home_img_8, 72, 211);
    lv_obj_set_size(ui->screen_1_home_img_8, 30, 30);

    //Write style for screen_1_home_img_8, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
    lv_obj_set_style_img_recolor_opa(ui->screen_1_home_img_8, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_img_opa(ui->screen_1_home_img_8, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_radius(ui->screen_1_home_img_8, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_clip_corner(ui->screen_1_home_img_8, true, LV_PART_MAIN|LV_STATE_DEFAULT);

    //Write codes screen_1_home_img_10
    ui->screen_1_home_img_10 = lv_img_create(ui->screen_1_home_cont_slide);
    lv_obj_add_flag(ui->screen_1_home_img_10, LV_OBJ_FLAG_CLICKABLE);
    lv_img_set_src(ui->screen_1_home_img_10, &_mianti_0_alpha_30x30);
    lv_img_set_pivot(ui->screen_1_home_img_10, 50,50);
    lv_img_set_angle(ui->screen_1_home_img_10, 0);
    lv_obj_set_pos(ui->screen_1_home_img_10, 18, 211);
    lv_obj_set_size(ui->screen_1_home_img_10, 30, 30);

    //Write style for screen_1_home_img_10, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
    lv_obj_set_style_radius(ui->screen_1_home_img_10, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_clip_corner(ui->screen_1_home_img_10, true, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_img_recolor_opa(ui->screen_1_home_img_10, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_img_opa(ui->screen_1_home_img_10, 255, LV_PART_MAIN|LV_STATE_DEFAULT);

    //Write codes screen_1_home_img_9
    ui->screen_1_home_img_9 = lv_img_create(ui->screen_1_home_cont_slide);
    lv_obj_add_flag(ui->screen_1_home_img_9, LV_OBJ_FLAG_CLICKABLE);
    lv_img_set_src(ui->screen_1_home_img_9, &_BT32_alpha_30x30);
    lv_img_set_pivot(ui->screen_1_home_img_9, 50,50);
    lv_img_set_angle(ui->screen_1_home_img_9, 0);
    lv_obj_set_pos(ui->screen_1_home_img_9, 45, 152);
    lv_obj_set_size(ui->screen_1_home_img_9, 30, 30);

    //Write style for screen_1_home_img_9, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
    lv_obj_set_style_img_recolor_opa(ui->screen_1_home_img_9, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_img_opa(ui->screen_1_home_img_9, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_radius(ui->screen_1_home_img_9, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_clip_corner(ui->screen_1_home_img_9, true, LV_PART_MAIN|LV_STATE_DEFAULT);

    //Write codes screen_1_home_img_7
    ui->screen_1_home_img_7 = lv_img_create(ui->screen_1_home_cont_slide);
    lv_obj_add_flag(ui->screen_1_home_img_7, LV_OBJ_FLAG_CLICKABLE);
    lv_img_set_src(ui->screen_1_home_img_7, &_copesss_alpha_30x30);
    lv_img_set_pivot(ui->screen_1_home_img_7, 50,50);
    lv_img_set_angle(ui->screen_1_home_img_7, 0);
    lv_obj_set_pos(ui->screen_1_home_img_7, 9, 84);
    lv_obj_set_size(ui->screen_1_home_img_7, 30, 30);

    //Write style for screen_1_home_img_7, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
    lv_obj_set_style_img_recolor_opa(ui->screen_1_home_img_7, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_img_opa(ui->screen_1_home_img_7, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_radius(ui->screen_1_home_img_7, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_clip_corner(ui->screen_1_home_img_7, true, LV_PART_MAIN|LV_STATE_DEFAULT);

    //Write codes screen_1_home_img_6
    ui->screen_1_home_img_6 = lv_img_create(ui->screen_1_home_cont_slide);
    lv_obj_add_flag(ui->screen_1_home_img_6, LV_OBJ_FLAG_CLICKABLE);
    lv_img_set_src(ui->screen_1_home_img_6, &_weater32x32_alpha_30x30);
    lv_img_set_pivot(ui->screen_1_home_img_6, 50,50);
    lv_img_set_angle(ui->screen_1_home_img_6, 0);
    lv_obj_set_pos(ui->screen_1_home_img_6, 6, 34);
    lv_obj_set_size(ui->screen_1_home_img_6, 30, 30);

    //Write style for screen_1_home_img_6, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
    lv_obj_set_style_radius(ui->screen_1_home_img_6, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_clip_corner(ui->screen_1_home_img_6, true, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_img_recolor_opa(ui->screen_1_home_img_6, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_img_opa(ui->screen_1_home_img_6, 255, LV_PART_MAIN|LV_STATE_DEFAULT);

    //Write codes screen_1_home_label_1
    ui->screen_1_home_label_1 = lv_label_create(ui->screen_1_home_cont_slide);
    lv_label_set_text(ui->screen_1_home_label_1, "38");
    lv_label_set_long_mode(ui->screen_1_home_label_1, LV_LABEL_LONG_WRAP);
    lv_obj_set_pos(ui->screen_1_home_label_1, 44, 92);
    lv_obj_set_size(ui->screen_1_home_label_1, 68, 17);

    //Write style for screen_1_home_label_1, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
    lv_obj_set_style_radius(ui->screen_1_home_label_1, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_border_width(ui->screen_1_home_label_1, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ui->screen_1_home_label_1, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_top(ui->screen_1_home_label_1, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_right(ui->screen_1_home_label_1, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_bottom(ui->screen_1_home_label_1, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_left(ui->screen_1_home_label_1, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_width(ui->screen_1_home_label_1, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_color(ui->screen_1_home_label_1, lv_color_hex(0xffffff), LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_font(ui->screen_1_home_label_1, &lv_font_SourceHanSerifSC_Regular_16, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_opa(ui->screen_1_home_label_1, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_letter_space(ui->screen_1_home_label_1, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_line_space(ui->screen_1_home_label_1, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_align(ui->screen_1_home_label_1, LV_TEXT_ALIGN_CENTER, LV_PART_MAIN|LV_STATE_DEFAULT);

    //Write codes screen_1_home_label_2
    ui->screen_1_home_label_2 = lv_label_create(ui->screen_1_home_cont_slide);
    lv_label_set_text(ui->screen_1_home_label_2, "天气");
    lv_label_set_long_mode(ui->screen_1_home_label_2, LV_LABEL_LONG_WRAP);
    lv_obj_set_pos(ui->screen_1_home_label_2, 39, 43);
    lv_obj_set_size(ui->screen_1_home_label_2, 68, 17);

    //Write style for screen_1_home_label_2, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
    lv_obj_set_style_radius(ui->screen_1_home_label_2, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_border_width(ui->screen_1_home_label_2, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ui->screen_1_home_label_2, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_top(ui->screen_1_home_label_2, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_bottom(ui->screen_1_home_label_2, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_left(ui->screen_1_home_label_2, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_right(ui->screen_1_home_label_2, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_width(ui->screen_1_home_label_2, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_color(ui->screen_1_home_label_2, lv_color_hex(0xffffff), LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_font(ui->screen_1_home_label_2, &lv_font_SourceHanSerifSC_Regular_16, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_opa(ui->screen_1_home_label_2, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_letter_space(ui->screen_1_home_label_2, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_line_space(ui->screen_1_home_label_2, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_align(ui->screen_1_home_label_2, LV_TEXT_ALIGN_CENTER, LV_PART_MAIN|LV_STATE_DEFAULT);

    //Write codes screen_1_home_cont_shadow
    ui->screen_1_home_cont_shadow = lv_obj_create(ui->screen_1_home);
    lv_obj_set_pos(ui->screen_1_home_cont_shadow, 0, 0);
    lv_obj_set_size(ui->screen_1_home_cont_shadow, 240, 280);
    lv_obj_set_scrollbar_mode(ui->screen_1_home_cont_shadow, LV_SCROLLBAR_MODE_OFF);
    lv_obj_add_flag(ui->screen_1_home_cont_shadow, LV_OBJ_FLAG_HIDDEN);

    //Write style for screen_1_home_cont_shadow, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
    lv_obj_set_style_border_width(ui->screen_1_home_cont_shadow, 2, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_border_opa(ui->screen_1_home_cont_shadow, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_border_color(ui->screen_1_home_cont_shadow, lv_color_hex(0x000000), LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_border_side(ui->screen_1_home_cont_shadow, LV_BORDER_SIDE_FULL, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_radius(ui->screen_1_home_cont_shadow, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ui->screen_1_home_cont_shadow, 123, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_color(ui->screen_1_home_cont_shadow, lv_color_hex(0x000000), LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_grad_dir(ui->screen_1_home_cont_shadow, LV_GRAD_DIR_NONE, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_top(ui->screen_1_home_cont_shadow, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_right(ui->screen_1_home_cont_shadow, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_bottom(ui->screen_1_home_cont_shadow, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_left(ui->screen_1_home_cont_shadow, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_width(ui->screen_1_home_cont_shadow, 0, LV_PART_MAIN|LV_STATE_DEFAULT);

    //The custom code of screen_1_home.


    //Update current screen layout.
    lv_obj_update_layout(ui->screen_1_home);

    //Init events for screen.
    events_init_screen_1_home(ui);
}
