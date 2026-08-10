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



void setup_scr_List_2(lv_ui *ui)
{
    //Write codes List_2
    ui->List_2 = lv_obj_create(NULL);
    lv_obj_set_size(ui->List_2, 240, 280);
    lv_obj_set_scrollbar_mode(ui->List_2, LV_SCROLLBAR_MODE_AUTO);

    //Write style for List_2, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
    lv_obj_set_style_bg_opa(ui->List_2, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_color(ui->List_2, lv_color_hex(0x000000), LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_grad_dir(ui->List_2, LV_GRAD_DIR_NONE, LV_PART_MAIN|LV_STATE_DEFAULT);

    //Write codes List_2_btn_1
    ui->List_2_btn_1 = lv_btn_create(ui->List_2);
    ui->List_2_btn_1_label = lv_label_create(ui->List_2_btn_1);
    lv_label_set_text(ui->List_2_btn_1_label, "< Home");
    lv_label_set_long_mode(ui->List_2_btn_1_label, LV_LABEL_LONG_WRAP);
    lv_obj_align(ui->List_2_btn_1_label, LV_ALIGN_CENTER, 0, 0);
    lv_obj_set_style_pad_all(ui->List_2_btn_1, 0, LV_STATE_DEFAULT);
    lv_obj_set_width(ui->List_2_btn_1_label, LV_PCT(100));
    lv_obj_set_pos(ui->List_2_btn_1, 22, 9);
    lv_obj_set_size(ui->List_2_btn_1, 70, 32);

    //Write style for List_2_btn_1, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
    lv_obj_set_style_bg_opa(ui->List_2_btn_1, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_border_width(ui->List_2_btn_1, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_radius(ui->List_2_btn_1, 5, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_width(ui->List_2_btn_1, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_color(ui->List_2_btn_1, lv_color_hex(0xffffff), LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_font(ui->List_2_btn_1, &lv_font_montserratMedium_16, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_opa(ui->List_2_btn_1, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_align(ui->List_2_btn_1, LV_TEXT_ALIGN_CENTER, LV_PART_MAIN|LV_STATE_DEFAULT);

    //Write codes List_2_cont_1
    ui->List_2_cont_1 = lv_obj_create(ui->List_2);
    lv_obj_set_pos(ui->List_2_cont_1, 10, 40);
    lv_obj_set_size(ui->List_2_cont_1, 220, 377);
    lv_obj_set_scrollbar_mode(ui->List_2_cont_1, LV_SCROLLBAR_MODE_OFF);

    //Write style for List_2_cont_1, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
    lv_obj_set_style_border_width(ui->List_2_cont_1, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_radius(ui->List_2_cont_1, 35, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ui->List_2_cont_1, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_top(ui->List_2_cont_1, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_bottom(ui->List_2_cont_1, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_left(ui->List_2_cont_1, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_right(ui->List_2_cont_1, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_width(ui->List_2_cont_1, 0, LV_PART_MAIN|LV_STATE_DEFAULT);

    //Write codes List_2_cont_2
    ui->List_2_cont_2 = lv_obj_create(ui->List_2_cont_1);
    lv_obj_set_pos(ui->List_2_cont_2, 0, 0);
    lv_obj_set_size(ui->List_2_cont_2, 215, 40);
    lv_obj_set_scrollbar_mode(ui->List_2_cont_2, LV_SCROLLBAR_MODE_OFF);

    //Write style for List_2_cont_2, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
    lv_obj_set_style_border_width(ui->List_2_cont_2, 2, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_border_opa(ui->List_2_cont_2, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_border_color(ui->List_2_cont_2, lv_color_hex(0x2E2E2E), LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_border_side(ui->List_2_cont_2, LV_BORDER_SIDE_FULL, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_radius(ui->List_2_cont_2, 35, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ui->List_2_cont_2, 102, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_color(ui->List_2_cont_2, lv_color_hex(0x2E2E2E), LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_grad_dir(ui->List_2_cont_2, LV_GRAD_DIR_NONE, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_top(ui->List_2_cont_2, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_bottom(ui->List_2_cont_2, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_left(ui->List_2_cont_2, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_right(ui->List_2_cont_2, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_width(ui->List_2_cont_2, 0, LV_PART_MAIN|LV_STATE_DEFAULT);

    //Write codes List_2_img_13
    ui->List_2_img_13 = lv_img_create(ui->List_2_cont_2);
    lv_obj_add_flag(ui->List_2_img_13, LV_OBJ_FLAG_CLICKABLE);
    lv_img_set_src(ui->List_2_img_13, &_heart32x32_alpha_48x39);
    lv_img_set_pivot(ui->List_2_img_13, 50,50);
    lv_img_set_angle(ui->List_2_img_13, 0);
    lv_obj_set_pos(ui->List_2_img_13, 27, 2);
    lv_obj_set_size(ui->List_2_img_13, 48, 39);

    //Write style for List_2_img_13, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
    lv_obj_set_style_img_recolor_opa(ui->List_2_img_13, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_img_opa(ui->List_2_img_13, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_radius(ui->List_2_img_13, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_clip_corner(ui->List_2_img_13, true, LV_PART_MAIN|LV_STATE_DEFAULT);

    //Write codes List_2_label_13
    ui->List_2_label_13 = lv_label_create(ui->List_2_cont_2);
    lv_label_set_text(ui->List_2_label_13, "Heart rate");
    lv_label_set_long_mode(ui->List_2_label_13, LV_LABEL_LONG_WRAP);
    lv_obj_set_pos(ui->List_2_label_13, 52, 9);
    lv_obj_set_size(ui->List_2_label_13, 135, 18);

    //Write style for List_2_label_13, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
    lv_obj_set_style_border_width(ui->List_2_label_13, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_radius(ui->List_2_label_13, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_color(ui->List_2_label_13, lv_color_hex(0xffffff), LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_font(ui->List_2_label_13, &lv_font_montserratMedium_16, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_opa(ui->List_2_label_13, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_letter_space(ui->List_2_label_13, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_line_space(ui->List_2_label_13, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_align(ui->List_2_label_13, LV_TEXT_ALIGN_CENTER, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ui->List_2_label_13, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_top(ui->List_2_label_13, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_right(ui->List_2_label_13, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_bottom(ui->List_2_label_13, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_left(ui->List_2_label_13, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_width(ui->List_2_label_13, 0, LV_PART_MAIN|LV_STATE_DEFAULT);

    //Write codes List_2_cont_3
    ui->List_2_cont_3 = lv_obj_create(ui->List_2_cont_1);
    lv_obj_set_pos(ui->List_2_cont_3, 0, 54);
    lv_obj_set_size(ui->List_2_cont_3, 215, 40);
    lv_obj_set_scrollbar_mode(ui->List_2_cont_3, LV_SCROLLBAR_MODE_OFF);

    //Write style for List_2_cont_3, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
    lv_obj_set_style_border_width(ui->List_2_cont_3, 2, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_border_opa(ui->List_2_cont_3, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_border_color(ui->List_2_cont_3, lv_color_hex(0x2E2E2E), LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_border_side(ui->List_2_cont_3, LV_BORDER_SIDE_FULL, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_radius(ui->List_2_cont_3, 35, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ui->List_2_cont_3, 102, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_color(ui->List_2_cont_3, lv_color_hex(0x2E2E2E), LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_grad_dir(ui->List_2_cont_3, LV_GRAD_DIR_NONE, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_top(ui->List_2_cont_3, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_bottom(ui->List_2_cont_3, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_left(ui->List_2_cont_3, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_right(ui->List_2_cont_3, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_width(ui->List_2_cont_3, 0, LV_PART_MAIN|LV_STATE_DEFAULT);

    //Write codes List_2_img_12
    ui->List_2_img_12 = lv_img_create(ui->List_2_cont_3);
    lv_obj_add_flag(ui->List_2_img_12, LV_OBJ_FLAG_CLICKABLE);
    lv_img_set_src(ui->List_2_img_12, &_location32x32_alpha_30x30);
    lv_img_set_pivot(ui->List_2_img_12, 50,50);
    lv_img_set_angle(ui->List_2_img_12, 0);
    lv_obj_set_pos(ui->List_2_img_12, 24, 1);
    lv_obj_set_size(ui->List_2_img_12, 30, 30);

    //Write style for List_2_img_12, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
    lv_obj_set_style_img_recolor_opa(ui->List_2_img_12, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_img_opa(ui->List_2_img_12, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_radius(ui->List_2_img_12, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_clip_corner(ui->List_2_img_12, true, LV_PART_MAIN|LV_STATE_DEFAULT);

    //Write codes List_2_label_12
    ui->List_2_label_12 = lv_label_create(ui->List_2_cont_3);
    lv_label_set_text(ui->List_2_label_12, "Electronic fence");
    lv_label_set_long_mode(ui->List_2_label_12, LV_LABEL_LONG_WRAP);
    lv_obj_set_pos(ui->List_2_label_12, 59, 7);
    lv_obj_set_size(ui->List_2_label_12, 135, 18);

    //Write style for List_2_label_12, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
    lv_obj_set_style_border_width(ui->List_2_label_12, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_radius(ui->List_2_label_12, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_color(ui->List_2_label_12, lv_color_hex(0xffffff), LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_font(ui->List_2_label_12, &lv_font_montserratMedium_16, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_opa(ui->List_2_label_12, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_letter_space(ui->List_2_label_12, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_line_space(ui->List_2_label_12, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_align(ui->List_2_label_12, LV_TEXT_ALIGN_CENTER, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ui->List_2_label_12, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_top(ui->List_2_label_12, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_right(ui->List_2_label_12, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_bottom(ui->List_2_label_12, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_left(ui->List_2_label_12, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_width(ui->List_2_label_12, 0, LV_PART_MAIN|LV_STATE_DEFAULT);

    //Write codes List_2_cont_4
    ui->List_2_cont_4 = lv_obj_create(ui->List_2_cont_1);
    lv_obj_set_pos(ui->List_2_cont_4, 0, 108);
    lv_obj_set_size(ui->List_2_cont_4, 215, 40);
    lv_obj_set_scrollbar_mode(ui->List_2_cont_4, LV_SCROLLBAR_MODE_OFF);

    //Write style for List_2_cont_4, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
    lv_obj_set_style_border_width(ui->List_2_cont_4, 2, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_border_opa(ui->List_2_cont_4, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_border_color(ui->List_2_cont_4, lv_color_hex(0x2E2E2E), LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_border_side(ui->List_2_cont_4, LV_BORDER_SIDE_FULL, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_radius(ui->List_2_cont_4, 35, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ui->List_2_cont_4, 102, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_color(ui->List_2_cont_4, lv_color_hex(0x2E2E2E), LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_grad_dir(ui->List_2_cont_4, LV_GRAD_DIR_NONE, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_top(ui->List_2_cont_4, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_bottom(ui->List_2_cont_4, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_left(ui->List_2_cont_4, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_right(ui->List_2_cont_4, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_width(ui->List_2_cont_4, 0, LV_PART_MAIN|LV_STATE_DEFAULT);

    //Write codes List_2_img_11
    ui->List_2_img_11 = lv_img_create(ui->List_2_cont_4);
    lv_obj_add_flag(ui->List_2_img_11, LV_OBJ_FLAG_CLICKABLE);
    lv_img_set_src(ui->List_2_img_11, &_NFC32x32_alpha_30x30);
    lv_img_set_pivot(ui->List_2_img_11, 50,50);
    lv_img_set_angle(ui->List_2_img_11, 0);
    lv_obj_set_pos(ui->List_2_img_11, 26, 7);
    lv_obj_set_size(ui->List_2_img_11, 30, 30);

    //Write style for List_2_img_11, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
    lv_obj_set_style_img_recolor_opa(ui->List_2_img_11, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_img_opa(ui->List_2_img_11, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_radius(ui->List_2_img_11, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_clip_corner(ui->List_2_img_11, true, LV_PART_MAIN|LV_STATE_DEFAULT);

    //Write codes List_2_label_11
    ui->List_2_label_11 = lv_label_create(ui->List_2_cont_4);
    lv_label_set_text(ui->List_2_label_11, "NFC card");
    lv_label_set_long_mode(ui->List_2_label_11, LV_LABEL_LONG_WRAP);
    lv_obj_set_pos(ui->List_2_label_11, 61, 9);
    lv_obj_set_size(ui->List_2_label_11, 135, 18);

    //Write style for List_2_label_11, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
    lv_obj_set_style_border_width(ui->List_2_label_11, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_radius(ui->List_2_label_11, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_color(ui->List_2_label_11, lv_color_hex(0xffffff), LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_font(ui->List_2_label_11, &lv_font_montserratMedium_16, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_opa(ui->List_2_label_11, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_letter_space(ui->List_2_label_11, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_line_space(ui->List_2_label_11, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_align(ui->List_2_label_11, LV_TEXT_ALIGN_CENTER, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ui->List_2_label_11, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_top(ui->List_2_label_11, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_right(ui->List_2_label_11, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_bottom(ui->List_2_label_11, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_left(ui->List_2_label_11, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_width(ui->List_2_label_11, 0, LV_PART_MAIN|LV_STATE_DEFAULT);

    //Write codes List_2_cont_5
    ui->List_2_cont_5 = lv_obj_create(ui->List_2_cont_1);
    lv_obj_set_pos(ui->List_2_cont_5, 0, 162);
    lv_obj_set_size(ui->List_2_cont_5, 215, 40);
    lv_obj_set_scrollbar_mode(ui->List_2_cont_5, LV_SCROLLBAR_MODE_OFF);

    //Write style for List_2_cont_5, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
    lv_obj_set_style_border_width(ui->List_2_cont_5, 2, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_border_opa(ui->List_2_cont_5, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_border_color(ui->List_2_cont_5, lv_color_hex(0x2E2E2E), LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_border_side(ui->List_2_cont_5, LV_BORDER_SIDE_FULL, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_radius(ui->List_2_cont_5, 35, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ui->List_2_cont_5, 102, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_color(ui->List_2_cont_5, lv_color_hex(0x2E2E2E), LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_grad_dir(ui->List_2_cont_5, LV_GRAD_DIR_NONE, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_top(ui->List_2_cont_5, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_bottom(ui->List_2_cont_5, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_left(ui->List_2_cont_5, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_right(ui->List_2_cont_5, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_width(ui->List_2_cont_5, 0, LV_PART_MAIN|LV_STATE_DEFAULT);

    //Write codes List_2_img_10
    ui->List_2_img_10 = lv_img_create(ui->List_2_cont_5);
    lv_obj_add_flag(ui->List_2_img_10, LV_OBJ_FLAG_CLICKABLE);
    lv_img_set_src(ui->List_2_img_10, &_qrcode32x32_alpha_30x30);
    lv_img_set_pivot(ui->List_2_img_10, 50,50);
    lv_img_set_angle(ui->List_2_img_10, 0);
    lv_obj_set_pos(ui->List_2_img_10, 27, 4);
    lv_obj_set_size(ui->List_2_img_10, 30, 30);

    //Write style for List_2_img_10, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
    lv_obj_set_style_img_recolor_opa(ui->List_2_img_10, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_img_opa(ui->List_2_img_10, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_radius(ui->List_2_img_10, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_clip_corner(ui->List_2_img_10, true, LV_PART_MAIN|LV_STATE_DEFAULT);

    //Write codes List_2_label_10
    ui->List_2_label_10 = lv_label_create(ui->List_2_cont_5);
    lv_label_set_text(ui->List_2_label_10, "QR code\n");
    lv_label_set_long_mode(ui->List_2_label_10, LV_LABEL_LONG_WRAP);
    lv_obj_set_pos(ui->List_2_label_10, 64, 11);
    lv_obj_set_size(ui->List_2_label_10, 135, 18);

    //Write style for List_2_label_10, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
    lv_obj_set_style_border_width(ui->List_2_label_10, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_radius(ui->List_2_label_10, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_color(ui->List_2_label_10, lv_color_hex(0xffffff), LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_font(ui->List_2_label_10, &lv_font_montserratMedium_16, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_opa(ui->List_2_label_10, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_letter_space(ui->List_2_label_10, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_line_space(ui->List_2_label_10, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_align(ui->List_2_label_10, LV_TEXT_ALIGN_CENTER, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ui->List_2_label_10, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_top(ui->List_2_label_10, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_right(ui->List_2_label_10, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_bottom(ui->List_2_label_10, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_left(ui->List_2_label_10, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_width(ui->List_2_label_10, 0, LV_PART_MAIN|LV_STATE_DEFAULT);

    //Write codes List_2_cont_6
    ui->List_2_cont_6 = lv_obj_create(ui->List_2_cont_1);
    lv_obj_set_pos(ui->List_2_cont_6, 0, 216);
    lv_obj_set_size(ui->List_2_cont_6, 215, 40);
    lv_obj_set_scrollbar_mode(ui->List_2_cont_6, LV_SCROLLBAR_MODE_OFF);

    //Write style for List_2_cont_6, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
    lv_obj_set_style_border_width(ui->List_2_cont_6, 2, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_border_opa(ui->List_2_cont_6, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_border_color(ui->List_2_cont_6, lv_color_hex(0x2E2E2E), LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_border_side(ui->List_2_cont_6, LV_BORDER_SIDE_FULL, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_radius(ui->List_2_cont_6, 35, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ui->List_2_cont_6, 102, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_color(ui->List_2_cont_6, lv_color_hex(0x2E2E2E), LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_grad_dir(ui->List_2_cont_6, LV_GRAD_DIR_NONE, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_top(ui->List_2_cont_6, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_bottom(ui->List_2_cont_6, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_left(ui->List_2_cont_6, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_right(ui->List_2_cont_6, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_width(ui->List_2_cont_6, 0, LV_PART_MAIN|LV_STATE_DEFAULT);

    //Write codes List_2_img_9
    ui->List_2_img_9 = lv_img_create(ui->List_2_cont_6);
    lv_obj_add_flag(ui->List_2_img_9, LV_OBJ_FLAG_CLICKABLE);
    lv_img_set_src(ui->List_2_img_9, &_syteam32x32_alpha_30x30);
    lv_img_set_pivot(ui->List_2_img_9, 50,50);
    lv_img_set_angle(ui->List_2_img_9, 0);
    lv_obj_set_pos(ui->List_2_img_9, 21, 2);
    lv_obj_set_size(ui->List_2_img_9, 30, 30);

    //Write style for List_2_img_9, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
    lv_obj_set_style_img_recolor_opa(ui->List_2_img_9, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_img_opa(ui->List_2_img_9, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_radius(ui->List_2_img_9, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_clip_corner(ui->List_2_img_9, true, LV_PART_MAIN|LV_STATE_DEFAULT);

    //Write codes List_2_label_9
    ui->List_2_label_9 = lv_label_create(ui->List_2_cont_6);
    lv_label_set_text(ui->List_2_label_9, "Sys Update\n\n");
    lv_label_set_long_mode(ui->List_2_label_9, LV_LABEL_LONG_WRAP);
    lv_obj_set_pos(ui->List_2_label_9, 59, 9);
    lv_obj_set_size(ui->List_2_label_9, 135, 18);

    //Write style for List_2_label_9, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
    lv_obj_set_style_border_width(ui->List_2_label_9, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_radius(ui->List_2_label_9, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_color(ui->List_2_label_9, lv_color_hex(0xffffff), LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_font(ui->List_2_label_9, &lv_font_montserratMedium_16, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_opa(ui->List_2_label_9, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_letter_space(ui->List_2_label_9, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_line_space(ui->List_2_label_9, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_align(ui->List_2_label_9, LV_TEXT_ALIGN_CENTER, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ui->List_2_label_9, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_top(ui->List_2_label_9, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_right(ui->List_2_label_9, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_bottom(ui->List_2_label_9, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_left(ui->List_2_label_9, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_width(ui->List_2_label_9, 0, LV_PART_MAIN|LV_STATE_DEFAULT);

    //Write codes List_2_cont_7
    ui->List_2_cont_7 = lv_obj_create(ui->List_2_cont_1);
    lv_obj_set_pos(ui->List_2_cont_7, 4, 270);
    lv_obj_set_size(ui->List_2_cont_7, 215, 40);
    lv_obj_set_scrollbar_mode(ui->List_2_cont_7, LV_SCROLLBAR_MODE_OFF);

    //Write style for List_2_cont_7, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
    lv_obj_set_style_bg_opa(ui->List_2_cont_7, 102, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_color(ui->List_2_cont_7, lv_color_hex(0x2E2E2E), LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_grad_dir(ui->List_2_cont_7, LV_GRAD_DIR_NONE, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_border_width(ui->List_2_cont_7, 2, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_border_opa(ui->List_2_cont_7, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_border_color(ui->List_2_cont_7, lv_color_hex(0x2E2E2E), LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_border_side(ui->List_2_cont_7, LV_BORDER_SIDE_FULL, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_radius(ui->List_2_cont_7, 35, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_width(ui->List_2_cont_7, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_top(ui->List_2_cont_7, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_bottom(ui->List_2_cont_7, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_left(ui->List_2_cont_7, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_right(ui->List_2_cont_7, 0, LV_PART_MAIN|LV_STATE_DEFAULT);

    //Write codes List_2_img_8
    ui->List_2_img_8 = lv_img_create(ui->List_2_cont_7);
    lv_obj_add_flag(ui->List_2_img_8, LV_OBJ_FLAG_CLICKABLE);
    lv_img_set_src(ui->List_2_img_8, &_weater32x32_alpha_30x30);
    lv_img_set_pivot(ui->List_2_img_8, 50,50);
    lv_img_set_angle(ui->List_2_img_8, 0);
    lv_obj_set_pos(ui->List_2_img_8, 22, 4);
    lv_obj_set_size(ui->List_2_img_8, 30, 30);

    //Write style for List_2_img_8, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
    lv_obj_set_style_img_recolor_opa(ui->List_2_img_8, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_img_opa(ui->List_2_img_8, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_radius(ui->List_2_img_8, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_clip_corner(ui->List_2_img_8, true, LV_PART_MAIN|LV_STATE_DEFAULT);

    //Write codes List_2_label_8
    ui->List_2_label_8 = lv_label_create(ui->List_2_cont_7);
    lv_label_set_text(ui->List_2_label_8, "Weather\n");
    lv_label_set_long_mode(ui->List_2_label_8, LV_LABEL_LONG_WRAP);
    lv_obj_set_pos(ui->List_2_label_8, 57, 9);
    lv_obj_set_size(ui->List_2_label_8, 135, 18);

    //Write style for List_2_label_8, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
    lv_obj_set_style_border_width(ui->List_2_label_8, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_radius(ui->List_2_label_8, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_color(ui->List_2_label_8, lv_color_hex(0xffffff), LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_font(ui->List_2_label_8, &lv_font_montserratMedium_16, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_opa(ui->List_2_label_8, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_letter_space(ui->List_2_label_8, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_line_space(ui->List_2_label_8, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_align(ui->List_2_label_8, LV_TEXT_ALIGN_CENTER, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ui->List_2_label_8, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_top(ui->List_2_label_8, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_right(ui->List_2_label_8, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_bottom(ui->List_2_label_8, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_left(ui->List_2_label_8, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_width(ui->List_2_label_8, 0, LV_PART_MAIN|LV_STATE_DEFAULT);

    //Write codes List_2_cont_8
    ui->List_2_cont_8 = lv_obj_create(ui->List_2_cont_1);
    lv_obj_set_pos(ui->List_2_cont_8, 3, 326);
    lv_obj_set_size(ui->List_2_cont_8, 215, 40);
    lv_obj_set_scrollbar_mode(ui->List_2_cont_8, LV_SCROLLBAR_MODE_OFF);

    //Write style for List_2_cont_8, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
    lv_obj_set_style_border_width(ui->List_2_cont_8, 2, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_border_opa(ui->List_2_cont_8, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_border_color(ui->List_2_cont_8, lv_color_hex(0x2E2E2E), LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_border_side(ui->List_2_cont_8, LV_BORDER_SIDE_FULL, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_radius(ui->List_2_cont_8, 35, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ui->List_2_cont_8, 102, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_color(ui->List_2_cont_8, lv_color_hex(0x2E2E2E), LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_grad_dir(ui->List_2_cont_8, LV_GRAD_DIR_NONE, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_top(ui->List_2_cont_8, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_bottom(ui->List_2_cont_8, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_left(ui->List_2_cont_8, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_right(ui->List_2_cont_8, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_width(ui->List_2_cont_8, 0, LV_PART_MAIN|LV_STATE_DEFAULT);

    //Write codes List_2_img_15
    ui->List_2_img_15 = lv_img_create(ui->List_2_cont_8);
    lv_obj_add_flag(ui->List_2_img_15, LV_OBJ_FLAG_CLICKABLE);
    lv_img_set_src(ui->List_2_img_15, &_set32x32_alpha_30x30);
    lv_img_set_pivot(ui->List_2_img_15, 50,50);
    lv_img_set_angle(ui->List_2_img_15, 0);
    lv_obj_set_pos(ui->List_2_img_15, 22, 4);
    lv_obj_set_size(ui->List_2_img_15, 30, 30);

    //Write style for List_2_img_15, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
    lv_obj_set_style_img_recolor_opa(ui->List_2_img_15, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_img_opa(ui->List_2_img_15, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_radius(ui->List_2_img_15, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_clip_corner(ui->List_2_img_15, true, LV_PART_MAIN|LV_STATE_DEFAULT);

    //Write codes List_2_label_15
    ui->List_2_label_15 = lv_label_create(ui->List_2_cont_8);
    lv_label_set_text(ui->List_2_label_15, "Set\n");
    lv_label_set_long_mode(ui->List_2_label_15, LV_LABEL_LONG_WRAP);
    lv_obj_set_pos(ui->List_2_label_15, 52, 9);
    lv_obj_set_size(ui->List_2_label_15, 135, 18);

    //Write style for List_2_label_15, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
    lv_obj_set_style_border_width(ui->List_2_label_15, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_radius(ui->List_2_label_15, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_color(ui->List_2_label_15, lv_color_hex(0xffffff), LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_font(ui->List_2_label_15, &lv_font_montserratMedium_16, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_opa(ui->List_2_label_15, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_letter_space(ui->List_2_label_15, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_line_space(ui->List_2_label_15, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_align(ui->List_2_label_15, LV_TEXT_ALIGN_CENTER, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ui->List_2_label_15, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_top(ui->List_2_label_15, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_right(ui->List_2_label_15, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_bottom(ui->List_2_label_15, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_left(ui->List_2_label_15, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_width(ui->List_2_label_15, 0, LV_PART_MAIN|LV_STATE_DEFAULT);

    //The custom code of List_2.


    //Update current screen layout.
    lv_obj_update_layout(ui->List_2);

    //Init events for screen.
    events_init_List_2(ui);
}
