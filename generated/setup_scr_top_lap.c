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



void setup_scr_top_lap(lv_ui *ui)
{
    //Write codes top_lap
    ui->top_lap = lv_obj_create(NULL);
    lv_obj_set_size(ui->top_lap, 240, 280);
    lv_obj_set_scrollbar_mode(ui->top_lap, LV_SCROLLBAR_MODE_OFF);

    //Write style for top_lap, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
    lv_obj_set_style_bg_opa(ui->top_lap, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_color(ui->top_lap, lv_color_hex(0x000000), LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_grad_dir(ui->top_lap, LV_GRAD_DIR_NONE, LV_PART_MAIN|LV_STATE_DEFAULT);

    //Write codes top_lap_cont_4
    ui->top_lap_cont_4 = lv_obj_create(ui->top_lap);
    lv_obj_set_pos(ui->top_lap_cont_4, 31, 138);
    lv_obj_set_size(ui->top_lap_cont_4, 50, 50);
    lv_obj_set_scrollbar_mode(ui->top_lap_cont_4, LV_SCROLLBAR_MODE_OFF);

    //Write style for top_lap_cont_4, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
    lv_obj_set_style_border_width(ui->top_lap_cont_4, 2, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_border_opa(ui->top_lap_cont_4, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_border_color(ui->top_lap_cont_4, lv_color_hex(0x2195f6), LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_border_side(ui->top_lap_cont_4, LV_BORDER_SIDE_FULL, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_radius(ui->top_lap_cont_4, 50, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ui->top_lap_cont_4, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_color(ui->top_lap_cont_4, lv_color_hex(0xff00f7), LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_grad_dir(ui->top_lap_cont_4, LV_GRAD_DIR_NONE, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_top(ui->top_lap_cont_4, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_bottom(ui->top_lap_cont_4, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_left(ui->top_lap_cont_4, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_right(ui->top_lap_cont_4, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_img_src(ui->top_lap_cont_4, &_taiwan_50x50, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_img_opa(ui->top_lap_cont_4, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_img_recolor_opa(ui->top_lap_cont_4, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_width(ui->top_lap_cont_4, 0, LV_PART_MAIN|LV_STATE_DEFAULT);

    //Write codes top_lap_cont_5
    ui->top_lap_cont_5 = lv_obj_create(ui->top_lap);
    lv_obj_set_pos(ui->top_lap_cont_5, 152, 138);
    lv_obj_set_size(ui->top_lap_cont_5, 50, 50);
    lv_obj_set_scrollbar_mode(ui->top_lap_cont_5, LV_SCROLLBAR_MODE_OFF);

    //Write style for top_lap_cont_5, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
    lv_obj_set_style_border_width(ui->top_lap_cont_5, 2, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_border_opa(ui->top_lap_cont_5, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_border_color(ui->top_lap_cont_5, lv_color_hex(0x2195f6), LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_border_side(ui->top_lap_cont_5, LV_BORDER_SIDE_FULL, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_radius(ui->top_lap_cont_5, 50, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ui->top_lap_cont_5, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_color(ui->top_lap_cont_5, lv_color_hex(0x00d606), LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_grad_dir(ui->top_lap_cont_5, LV_GRAD_DIR_NONE, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_top(ui->top_lap_cont_5, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_bottom(ui->top_lap_cont_5, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_left(ui->top_lap_cont_5, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_right(ui->top_lap_cont_5, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_img_src(ui->top_lap_cont_5, &_nfc_50x50, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_img_opa(ui->top_lap_cont_5, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_img_recolor_opa(ui->top_lap_cont_5, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_width(ui->top_lap_cont_5, 0, LV_PART_MAIN|LV_STATE_DEFAULT);

    //Write codes top_lap_cont_2
    ui->top_lap_cont_2 = lv_obj_create(ui->top_lap);
    lv_obj_set_pos(ui->top_lap_cont_2, 31, 48);
    lv_obj_set_size(ui->top_lap_cont_2, 50, 50);
    lv_obj_set_scrollbar_mode(ui->top_lap_cont_2, LV_SCROLLBAR_MODE_OFF);

    //Write style for top_lap_cont_2, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
    lv_obj_set_style_border_width(ui->top_lap_cont_2, 2, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_border_opa(ui->top_lap_cont_2, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_border_color(ui->top_lap_cont_2, lv_color_hex(0x2195f6), LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_border_side(ui->top_lap_cont_2, LV_BORDER_SIDE_FULL, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_radius(ui->top_lap_cont_2, 50, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ui->top_lap_cont_2, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_color(ui->top_lap_cont_2, lv_color_hex(0xf00000), LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_grad_dir(ui->top_lap_cont_2, LV_GRAD_DIR_NONE, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_top(ui->top_lap_cont_2, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_bottom(ui->top_lap_cont_2, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_left(ui->top_lap_cont_2, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_right(ui->top_lap_cont_2, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_img_src(ui->top_lap_cont_2, &_BT32_50x50, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_img_opa(ui->top_lap_cont_2, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_img_recolor_opa(ui->top_lap_cont_2, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_width(ui->top_lap_cont_2, 0, LV_PART_MAIN|LV_STATE_DEFAULT);

    //Write codes top_lap_slider_1
    ui->top_lap_slider_1 = lv_slider_create(ui->top_lap);
    lv_slider_set_range(ui->top_lap_slider_1, 0, 100);
    lv_slider_set_mode(ui->top_lap_slider_1, LV_SLIDER_MODE_NORMAL);
    lv_slider_set_value(ui->top_lap_slider_1, 50, LV_ANIM_OFF);
    lv_obj_set_pos(ui->top_lap_slider_1, 12, 209);
    lv_obj_set_size(ui->top_lap_slider_1, 220, 37);

    //Write style for top_lap_slider_1, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
    lv_obj_set_style_bg_opa(ui->top_lap_slider_1, 134, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_color(ui->top_lap_slider_1, lv_color_hex(0xffbf4c), LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_grad_dir(ui->top_lap_slider_1, LV_GRAD_DIR_NONE, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_radius(ui->top_lap_slider_1, 8, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_outline_width(ui->top_lap_slider_1, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_width(ui->top_lap_slider_1, 0, LV_PART_MAIN|LV_STATE_DEFAULT);

    //Write style for top_lap_slider_1, Part: LV_PART_INDICATOR, State: LV_STATE_DEFAULT.
    lv_obj_set_style_bg_opa(ui->top_lap_slider_1, 255, LV_PART_INDICATOR|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_color(ui->top_lap_slider_1, lv_color_hex(0xfbae00), LV_PART_INDICATOR|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_grad_dir(ui->top_lap_slider_1, LV_GRAD_DIR_NONE, LV_PART_INDICATOR|LV_STATE_DEFAULT);
    lv_obj_set_style_radius(ui->top_lap_slider_1, 8, LV_PART_INDICATOR|LV_STATE_DEFAULT);

    //Write style for top_lap_slider_1, Part: LV_PART_KNOB, State: LV_STATE_DEFAULT.
    lv_obj_set_style_bg_opa(ui->top_lap_slider_1, 255, LV_PART_KNOB|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_color(ui->top_lap_slider_1, lv_color_hex(0xff9d00), LV_PART_KNOB|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_grad_dir(ui->top_lap_slider_1, LV_GRAD_DIR_NONE, LV_PART_KNOB|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_img_src(ui->top_lap_slider_1, &_liangdu_47x47, LV_PART_KNOB|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_img_opa(ui->top_lap_slider_1, 255, LV_PART_KNOB|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_img_recolor_opa(ui->top_lap_slider_1, 0, LV_PART_KNOB|LV_STATE_DEFAULT);
    lv_obj_set_style_radius(ui->top_lap_slider_1, 8, LV_PART_KNOB|LV_STATE_DEFAULT);

    //Write codes top_lap_cont_3
    ui->top_lap_cont_3 = lv_obj_create(ui->top_lap);
    lv_obj_set_pos(ui->top_lap_cont_3, 151, 48);
    lv_obj_set_size(ui->top_lap_cont_3, 50, 50);
    lv_obj_set_scrollbar_mode(ui->top_lap_cont_3, LV_SCROLLBAR_MODE_OFF);

    //Write style for top_lap_cont_3, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
    lv_obj_set_style_border_width(ui->top_lap_cont_3, 2, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_border_opa(ui->top_lap_cont_3, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_border_color(ui->top_lap_cont_3, lv_color_hex(0x2195f6), LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_border_side(ui->top_lap_cont_3, LV_BORDER_SIDE_FULL, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_radius(ui->top_lap_cont_3, 50, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ui->top_lap_cont_3, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_color(ui->top_lap_cont_3, lv_color_hex(0xffab00), LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_grad_dir(ui->top_lap_cont_3, LV_GRAD_DIR_NONE, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_top(ui->top_lap_cont_3, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_bottom(ui->top_lap_cont_3, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_left(ui->top_lap_cont_3, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_right(ui->top_lap_cont_3, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_img_src(ui->top_lap_cont_3, &_location_50x50, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_img_opa(ui->top_lap_cont_3, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_img_recolor_opa(ui->top_lap_cont_3, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_width(ui->top_lap_cont_3, 0, LV_PART_MAIN|LV_STATE_DEFAULT);

    //Write codes top_lap_img_1
    ui->top_lap_img_1 = lv_img_create(ui->top_lap);
    lv_obj_add_flag(ui->top_lap_img_1, LV_OBJ_FLAG_CLICKABLE);
    lv_img_set_src(ui->top_lap_img_1, &_power_over_alpha_50x50);
    lv_img_set_pivot(ui->top_lap_img_1, 50,50);
    lv_img_set_angle(ui->top_lap_img_1, 0);
    lv_obj_set_pos(ui->top_lap_img_1, 159, 0);
    lv_obj_set_size(ui->top_lap_img_1, 50, 50);

    //Write style for top_lap_img_1, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
    lv_obj_set_style_img_recolor_opa(ui->top_lap_img_1, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_img_opa(ui->top_lap_img_1, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_radius(ui->top_lap_img_1, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_clip_corner(ui->top_lap_img_1, true, LV_PART_MAIN|LV_STATE_DEFAULT);

    //The custom code of top_lap.


    //Update current screen layout.
    lv_obj_update_layout(ui->top_lap);

    //Init events for screen.
    events_init_top_lap(ui);
}
