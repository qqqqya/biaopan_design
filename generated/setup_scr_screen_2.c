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



void setup_scr_screen_2(lv_ui *ui)
{
    //Write codes screen_2
    ui->screen_2 = lv_obj_create(NULL);
    lv_obj_set_size(ui->screen_2, 240, 280);
    lv_obj_set_scrollbar_mode(ui->screen_2, LV_SCROLLBAR_MODE_OFF);

    //Write style for screen_2, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
    lv_obj_set_style_bg_opa(ui->screen_2, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_color(ui->screen_2, lv_color_hex(0x000000), LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_grad_dir(ui->screen_2, LV_GRAD_DIR_NONE, LV_PART_MAIN|LV_STATE_DEFAULT);

    //Write codes screen_2_cont_1
    ui->screen_2_cont_1 = lv_obj_create(ui->screen_2);
    lv_obj_set_pos(ui->screen_2_cont_1, -1, -1);
    lv_obj_set_size(ui->screen_2_cont_1, 240, 280);
    lv_obj_set_scrollbar_mode(ui->screen_2_cont_1, LV_SCROLLBAR_MODE_OFF);

    //Write style for screen_2_cont_1, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
    lv_obj_set_style_border_width(ui->screen_2_cont_1, 2, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_border_opa(ui->screen_2_cont_1, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_border_color(ui->screen_2_cont_1, lv_color_hex(0x2195f6), LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_border_side(ui->screen_2_cont_1, LV_BORDER_SIDE_FULL, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_radius(ui->screen_2_cont_1, 40, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ui->screen_2_cont_1, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_color(ui->screen_2_cont_1, lv_color_hex(0x000000), LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_grad_dir(ui->screen_2_cont_1, LV_GRAD_DIR_NONE, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_top(ui->screen_2_cont_1, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_bottom(ui->screen_2_cont_1, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_left(ui->screen_2_cont_1, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_right(ui->screen_2_cont_1, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_width(ui->screen_2_cont_1, 0, LV_PART_MAIN|LV_STATE_DEFAULT);

    //Write codes screen_2_label_2
    ui->screen_2_label_2 = lv_label_create(ui->screen_2_cont_1);
    lv_label_set_text(ui->screen_2_label_2, "06");
    lv_label_set_long_mode(ui->screen_2_label_2, LV_LABEL_LONG_WRAP);
    lv_obj_set_pos(ui->screen_2_label_2, 115, 138);
    lv_obj_set_size(ui->screen_2_label_2, 99, 88);

    //Write style for screen_2_label_2, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
    lv_obj_set_style_border_width(ui->screen_2_label_2, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_radius(ui->screen_2_label_2, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_color(ui->screen_2_label_2, lv_color_hex(0xffab00), LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_font(ui->screen_2_label_2, &lv_font_interttf_82, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_opa(ui->screen_2_label_2, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_letter_space(ui->screen_2_label_2, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_line_space(ui->screen_2_label_2, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_align(ui->screen_2_label_2, LV_TEXT_ALIGN_CENTER, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ui->screen_2_label_2, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_top(ui->screen_2_label_2, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_right(ui->screen_2_label_2, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_bottom(ui->screen_2_label_2, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_left(ui->screen_2_label_2, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_width(ui->screen_2_label_2, 0, LV_PART_MAIN|LV_STATE_DEFAULT);

    //Write codes screen_2_label_3
    ui->screen_2_label_3 = lv_label_create(ui->screen_2_cont_1);
    lv_label_set_text(ui->screen_2_label_3, "AM     08/06");
    lv_label_set_long_mode(ui->screen_2_label_3, LV_LABEL_LONG_WRAP);
    lv_obj_set_pos(ui->screen_2_label_3, 72, 230);
    lv_obj_set_size(ui->screen_2_label_3, 155, 26);

    //Write style for screen_2_label_3, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
    lv_obj_set_style_border_width(ui->screen_2_label_3, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_radius(ui->screen_2_label_3, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_color(ui->screen_2_label_3, lv_color_hex(0xffffff), LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_font(ui->screen_2_label_3, &lv_font_interttf_28, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_opa(ui->screen_2_label_3, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_letter_space(ui->screen_2_label_3, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_line_space(ui->screen_2_label_3, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_align(ui->screen_2_label_3, LV_TEXT_ALIGN_CENTER, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ui->screen_2_label_3, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_top(ui->screen_2_label_3, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_right(ui->screen_2_label_3, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_bottom(ui->screen_2_label_3, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_left(ui->screen_2_label_3, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_width(ui->screen_2_label_3, 0, LV_PART_MAIN|LV_STATE_DEFAULT);

    //Write codes screen_2_img_2
    ui->screen_2_img_2 = lv_img_create(ui->screen_2);
    lv_obj_add_flag(ui->screen_2_img_2, LV_OBJ_FLAG_CLICKABLE);
    lv_img_set_src(ui->screen_2_img_2, &_foot16x16_alpha_20x20);
    lv_img_set_pivot(ui->screen_2_img_2, 50,50);
    lv_img_set_angle(ui->screen_2_img_2, 0);
    lv_obj_set_pos(ui->screen_2_img_2, 48, 185);
    lv_obj_set_size(ui->screen_2_img_2, 20, 20);

    //Write style for screen_2_img_2, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
    lv_obj_set_style_img_recolor_opa(ui->screen_2_img_2, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_img_opa(ui->screen_2_img_2, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_radius(ui->screen_2_img_2, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_clip_corner(ui->screen_2_img_2, true, LV_PART_MAIN|LV_STATE_DEFAULT);

    //Write codes screen_2_img_3
    ui->screen_2_img_3 = lv_img_create(ui->screen_2);
    lv_obj_add_flag(ui->screen_2_img_3, LV_OBJ_FLAG_CLICKABLE);
    lv_img_set_src(ui->screen_2_img_3, &_KLL16x16_alpha_20x20);
    lv_img_set_pivot(ui->screen_2_img_3, 50,50);
    lv_img_set_angle(ui->screen_2_img_3, 0);
    lv_obj_set_pos(ui->screen_2_img_3, 52, 121);
    lv_obj_set_size(ui->screen_2_img_3, 20, 20);

    //Write style for screen_2_img_3, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
    lv_obj_set_style_img_recolor_opa(ui->screen_2_img_3, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_img_opa(ui->screen_2_img_3, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_radius(ui->screen_2_img_3, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_clip_corner(ui->screen_2_img_3, true, LV_PART_MAIN|LV_STATE_DEFAULT);

    //Write codes screen_2_img_4
    ui->screen_2_img_4 = lv_img_create(ui->screen_2);
    lv_obj_add_flag(ui->screen_2_img_4, LV_OBJ_FLAG_CLICKABLE);
    lv_img_set_src(ui->screen_2_img_4, &_heart16x16_alpha_20x20);
    lv_img_set_pivot(ui->screen_2_img_4, 50,50);
    lv_img_set_angle(ui->screen_2_img_4, 0);
    lv_obj_set_pos(ui->screen_2_img_4, 31, 53);
    lv_obj_set_size(ui->screen_2_img_4, 20, 20);

    //Write style for screen_2_img_4, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
    lv_obj_set_style_img_recolor_opa(ui->screen_2_img_4, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_img_opa(ui->screen_2_img_4, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_radius(ui->screen_2_img_4, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_clip_corner(ui->screen_2_img_4, true, LV_PART_MAIN|LV_STATE_DEFAULT);

    //Write codes screen_2_arc_2
    ui->screen_2_arc_2 = lv_arc_create(ui->screen_2);
    lv_arc_set_mode(ui->screen_2_arc_2, LV_ARC_MODE_NORMAL);
    lv_arc_set_range(ui->screen_2_arc_2, 0, 100);
    lv_arc_set_bg_angles(ui->screen_2_arc_2, 135, 45);
    lv_arc_set_value(ui->screen_2_arc_2, 100);
    lv_arc_set_rotation(ui->screen_2_arc_2, 250);
    lv_obj_set_pos(ui->screen_2_arc_2, 27, 118);
    lv_obj_set_size(ui->screen_2_arc_2, 41, 53);

    //Write style for screen_2_arc_2, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
    lv_obj_set_style_bg_opa(ui->screen_2_arc_2, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_border_width(ui->screen_2_arc_2, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_arc_opa(ui->screen_2_arc_2, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_radius(ui->screen_2_arc_2, 6, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_top(ui->screen_2_arc_2, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_bottom(ui->screen_2_arc_2, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_left(ui->screen_2_arc_2, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_right(ui->screen_2_arc_2, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_width(ui->screen_2_arc_2, 0, LV_PART_MAIN|LV_STATE_DEFAULT);

    //Write style for screen_2_arc_2, Part: LV_PART_INDICATOR, State: LV_STATE_DEFAULT.
    lv_obj_set_style_arc_width(ui->screen_2_arc_2, 2, LV_PART_INDICATOR|LV_STATE_DEFAULT);
    lv_obj_set_style_arc_opa(ui->screen_2_arc_2, 255, LV_PART_INDICATOR|LV_STATE_DEFAULT);
    lv_obj_set_style_arc_color(ui->screen_2_arc_2, lv_color_hex(0xffbf00), LV_PART_INDICATOR|LV_STATE_DEFAULT);

    //Write style for screen_2_arc_2, Part: LV_PART_KNOB, State: LV_STATE_DEFAULT.
    lv_obj_set_style_bg_opa(ui->screen_2_arc_2, 255, LV_PART_KNOB|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_color(ui->screen_2_arc_2, lv_color_hex(0xffc600), LV_PART_KNOB|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_grad_dir(ui->screen_2_arc_2, LV_GRAD_DIR_NONE, LV_PART_KNOB|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_all(ui->screen_2_arc_2, 0, LV_PART_KNOB|LV_STATE_DEFAULT);

    //Write codes screen_2_arc_4
    ui->screen_2_arc_4 = lv_arc_create(ui->screen_2);
    lv_arc_set_mode(ui->screen_2_arc_4, LV_ARC_MODE_NORMAL);
    lv_arc_set_range(ui->screen_2_arc_4, 0, 100);
    lv_arc_set_bg_angles(ui->screen_2_arc_4, 135, 45);
    lv_arc_set_value(ui->screen_2_arc_4, 100);
    lv_arc_set_rotation(ui->screen_2_arc_4, 210);
    lv_obj_set_pos(ui->screen_2_arc_4, 27, 193);
    lv_obj_set_size(ui->screen_2_arc_4, 41, 53);

    //Write style for screen_2_arc_4, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
    lv_obj_set_style_bg_opa(ui->screen_2_arc_4, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_border_width(ui->screen_2_arc_4, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_arc_opa(ui->screen_2_arc_4, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_radius(ui->screen_2_arc_4, 6, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_top(ui->screen_2_arc_4, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_bottom(ui->screen_2_arc_4, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_left(ui->screen_2_arc_4, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_right(ui->screen_2_arc_4, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_width(ui->screen_2_arc_4, 0, LV_PART_MAIN|LV_STATE_DEFAULT);

    //Write style for screen_2_arc_4, Part: LV_PART_INDICATOR, State: LV_STATE_DEFAULT.
    lv_obj_set_style_arc_width(ui->screen_2_arc_4, 2, LV_PART_INDICATOR|LV_STATE_DEFAULT);
    lv_obj_set_style_arc_opa(ui->screen_2_arc_4, 255, LV_PART_INDICATOR|LV_STATE_DEFAULT);
    lv_obj_set_style_arc_color(ui->screen_2_arc_4, lv_color_hex(0x00ff16), LV_PART_INDICATOR|LV_STATE_DEFAULT);

    //Write style for screen_2_arc_4, Part: LV_PART_KNOB, State: LV_STATE_DEFAULT.
    lv_obj_set_style_bg_opa(ui->screen_2_arc_4, 255, LV_PART_KNOB|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_color(ui->screen_2_arc_4, lv_color_hex(0xffc600), LV_PART_KNOB|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_grad_dir(ui->screen_2_arc_4, LV_GRAD_DIR_NONE, LV_PART_KNOB|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_all(ui->screen_2_arc_4, 0, LV_PART_KNOB|LV_STATE_DEFAULT);

    //Write codes screen_2_arc_5
    ui->screen_2_arc_5 = lv_arc_create(ui->screen_2);
    lv_arc_set_mode(ui->screen_2_arc_5, LV_ARC_MODE_NORMAL);
    lv_arc_set_range(ui->screen_2_arc_5, 0, 100);
    lv_arc_set_bg_angles(ui->screen_2_arc_5, 135, 45);
    lv_arc_set_value(ui->screen_2_arc_5, 100);
    lv_arc_set_rotation(ui->screen_2_arc_5, 160);
    lv_obj_set_pos(ui->screen_2_arc_5, 27, 60);
    lv_obj_set_size(ui->screen_2_arc_5, 41, 53);

    //Write style for screen_2_arc_5, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
    lv_obj_set_style_bg_opa(ui->screen_2_arc_5, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_border_width(ui->screen_2_arc_5, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_arc_opa(ui->screen_2_arc_5, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_radius(ui->screen_2_arc_5, 6, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_top(ui->screen_2_arc_5, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_bottom(ui->screen_2_arc_5, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_left(ui->screen_2_arc_5, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_right(ui->screen_2_arc_5, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_width(ui->screen_2_arc_5, 0, LV_PART_MAIN|LV_STATE_DEFAULT);

    //Write style for screen_2_arc_5, Part: LV_PART_INDICATOR, State: LV_STATE_DEFAULT.
    lv_obj_set_style_arc_width(ui->screen_2_arc_5, 2, LV_PART_INDICATOR|LV_STATE_DEFAULT);
    lv_obj_set_style_arc_opa(ui->screen_2_arc_5, 255, LV_PART_INDICATOR|LV_STATE_DEFAULT);
    lv_obj_set_style_arc_color(ui->screen_2_arc_5, lv_color_hex(0xe01030), LV_PART_INDICATOR|LV_STATE_DEFAULT);

    //Write style for screen_2_arc_5, Part: LV_PART_KNOB, State: LV_STATE_DEFAULT.
    lv_obj_set_style_bg_opa(ui->screen_2_arc_5, 255, LV_PART_KNOB|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_color(ui->screen_2_arc_5, lv_color_hex(0xffc600), LV_PART_KNOB|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_grad_dir(ui->screen_2_arc_5, LV_GRAD_DIR_NONE, LV_PART_KNOB|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_all(ui->screen_2_arc_5, 0, LV_PART_KNOB|LV_STATE_DEFAULT);

    //Write codes screen_2_label_1
    ui->screen_2_label_1 = lv_label_create(ui->screen_2);
    lv_label_set_text(ui->screen_2_label_1, "10");
    lv_label_set_long_mode(ui->screen_2_label_1, LV_LABEL_LONG_WRAP);
    lv_obj_set_pos(ui->screen_2_label_1, 116, 53);
    lv_obj_set_size(ui->screen_2_label_1, 99, 88);

    //Write style for screen_2_label_1, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
    lv_obj_set_style_border_width(ui->screen_2_label_1, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_radius(ui->screen_2_label_1, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_color(ui->screen_2_label_1, lv_color_hex(0xf00000), LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_font(ui->screen_2_label_1, &lv_font_interttf_82, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_opa(ui->screen_2_label_1, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_letter_space(ui->screen_2_label_1, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_line_space(ui->screen_2_label_1, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_align(ui->screen_2_label_1, LV_TEXT_ALIGN_CENTER, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ui->screen_2_label_1, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_top(ui->screen_2_label_1, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_right(ui->screen_2_label_1, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_bottom(ui->screen_2_label_1, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_left(ui->screen_2_label_1, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_width(ui->screen_2_label_1, 0, LV_PART_MAIN|LV_STATE_DEFAULT);

    //Write codes screen_2_label_4
    ui->screen_2_label_4 = lv_label_create(ui->screen_2);
    lv_label_set_text(ui->screen_2_label_4, "15");
    lv_label_set_long_mode(ui->screen_2_label_4, LV_LABEL_LONG_WRAP);
    lv_obj_set_pos(ui->screen_2_label_4, 15, 73);
    lv_obj_set_size(ui->screen_2_label_4, 63, 21);

    //Write style for screen_2_label_4, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
    lv_obj_set_style_border_width(ui->screen_2_label_4, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_radius(ui->screen_2_label_4, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_color(ui->screen_2_label_4, lv_color_hex(0xffffff), LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_font(ui->screen_2_label_4, &lv_font_SourceHanSerifSC_Regular_16, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_opa(ui->screen_2_label_4, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_letter_space(ui->screen_2_label_4, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_line_space(ui->screen_2_label_4, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_align(ui->screen_2_label_4, LV_TEXT_ALIGN_CENTER, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ui->screen_2_label_4, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_top(ui->screen_2_label_4, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_right(ui->screen_2_label_4, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_bottom(ui->screen_2_label_4, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_left(ui->screen_2_label_4, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_width(ui->screen_2_label_4, 0, LV_PART_MAIN|LV_STATE_DEFAULT);

    //Write codes screen_2_label_5
    ui->screen_2_label_5 = lv_label_create(ui->screen_2);
    lv_label_set_text(ui->screen_2_label_5, "15");
    lv_label_set_long_mode(ui->screen_2_label_5, LV_LABEL_LONG_WRAP);
    lv_obj_set_pos(ui->screen_2_label_5, 15, 205);
    lv_obj_set_size(ui->screen_2_label_5, 63, 21);

    //Write style for screen_2_label_5, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
    lv_obj_set_style_border_width(ui->screen_2_label_5, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_radius(ui->screen_2_label_5, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_color(ui->screen_2_label_5, lv_color_hex(0xffffff), LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_font(ui->screen_2_label_5, &lv_font_SourceHanSerifSC_Regular_16, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_opa(ui->screen_2_label_5, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_letter_space(ui->screen_2_label_5, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_line_space(ui->screen_2_label_5, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_align(ui->screen_2_label_5, LV_TEXT_ALIGN_CENTER, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ui->screen_2_label_5, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_top(ui->screen_2_label_5, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_right(ui->screen_2_label_5, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_bottom(ui->screen_2_label_5, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_left(ui->screen_2_label_5, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_width(ui->screen_2_label_5, 0, LV_PART_MAIN|LV_STATE_DEFAULT);

    //Write codes screen_2_label_6
    ui->screen_2_label_6 = lv_label_create(ui->screen_2);
    lv_label_set_text(ui->screen_2_label_6, "20");
    lv_label_set_long_mode(ui->screen_2_label_6, LV_LABEL_LONG_WRAP);
    lv_obj_set_pos(ui->screen_2_label_6, 15, 131);
    lv_obj_set_size(ui->screen_2_label_6, 63, 21);

    //Write style for screen_2_label_6, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
    lv_obj_set_style_border_width(ui->screen_2_label_6, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_radius(ui->screen_2_label_6, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_color(ui->screen_2_label_6, lv_color_hex(0xffffff), LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_font(ui->screen_2_label_6, &lv_font_SourceHanSerifSC_Regular_16, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_opa(ui->screen_2_label_6, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_letter_space(ui->screen_2_label_6, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_line_space(ui->screen_2_label_6, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_align(ui->screen_2_label_6, LV_TEXT_ALIGN_CENTER, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ui->screen_2_label_6, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_top(ui->screen_2_label_6, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_right(ui->screen_2_label_6, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_bottom(ui->screen_2_label_6, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_left(ui->screen_2_label_6, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_width(ui->screen_2_label_6, 0, LV_PART_MAIN|LV_STATE_DEFAULT);

    //The custom code of screen_2.


    //Update current screen layout.
    lv_obj_update_layout(ui->screen_2);

    //Init events for screen.
    events_init_screen_2(ui);
}
