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



void setup_scr_List_1(lv_ui *ui)
{
    //Write codes List_1
    ui->List_1 = lv_obj_create(NULL);
    lv_obj_set_size(ui->List_1, 240, 280);
    lv_obj_set_scrollbar_mode(ui->List_1, LV_SCROLLBAR_MODE_AUTO);

    //Write style for List_1, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
    lv_obj_set_style_bg_opa(ui->List_1, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_color(ui->List_1, lv_color_hex(0x000000), LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_grad_dir(ui->List_1, LV_GRAD_DIR_NONE, LV_PART_MAIN|LV_STATE_DEFAULT);

    //Write codes List_1_btn_1
    ui->List_1_btn_1 = lv_btn_create(ui->List_1);
    ui->List_1_btn_1_label = lv_label_create(ui->List_1_btn_1);
    lv_label_set_text(ui->List_1_btn_1_label, "< Home");
    lv_label_set_long_mode(ui->List_1_btn_1_label, LV_LABEL_LONG_WRAP);
    lv_obj_align(ui->List_1_btn_1_label, LV_ALIGN_CENTER, 0, 0);
    lv_obj_set_style_pad_all(ui->List_1_btn_1, 0, LV_STATE_DEFAULT);
    lv_obj_set_width(ui->List_1_btn_1_label, LV_PCT(100));
    lv_obj_set_pos(ui->List_1_btn_1, 22, 9);
    lv_obj_set_size(ui->List_1_btn_1, 70, 32);

    //Write style for List_1_btn_1, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
    lv_obj_set_style_bg_opa(ui->List_1_btn_1, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_border_width(ui->List_1_btn_1, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_radius(ui->List_1_btn_1, 5, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_width(ui->List_1_btn_1, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_color(ui->List_1_btn_1, lv_color_hex(0xffffff), LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_font(ui->List_1_btn_1, &lv_font_montserratMedium_16, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_opa(ui->List_1_btn_1, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_align(ui->List_1_btn_1, LV_TEXT_ALIGN_CENTER, LV_PART_MAIN|LV_STATE_DEFAULT);

    //Write codes List_1_cont_1
    ui->List_1_cont_1 = lv_obj_create(ui->List_1);
    lv_obj_set_pos(ui->List_1_cont_1, 10, 40);
    lv_obj_set_size(ui->List_1_cont_1, 220, 658);
    lv_obj_set_scrollbar_mode(ui->List_1_cont_1, LV_SCROLLBAR_MODE_OFF);

    //Write style for List_1_cont_1, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
    lv_obj_set_style_bg_opa(ui->List_1_cont_1, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_border_width(ui->List_1_cont_1, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_radius(ui->List_1_cont_1, 35, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_width(ui->List_1_cont_1, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_top(ui->List_1_cont_1, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_bottom(ui->List_1_cont_1, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_left(ui->List_1_cont_1, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_right(ui->List_1_cont_1, 0, LV_PART_MAIN|LV_STATE_DEFAULT);

    //Write codes List_1_cont_2
    ui->List_1_cont_2 = lv_obj_create(ui->List_1_cont_1);
    lv_obj_set_pos(ui->List_1_cont_2, 0, 1);
    lv_obj_set_size(ui->List_1_cont_2, 215, 69);
    lv_obj_set_scrollbar_mode(ui->List_1_cont_2, LV_SCROLLBAR_MODE_OFF);

    //Write style for List_1_cont_2, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
    lv_obj_set_style_border_width(ui->List_1_cont_2, 2, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_border_opa(ui->List_1_cont_2, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_border_color(ui->List_1_cont_2, lv_color_hex(0x2E2E2E), LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_border_side(ui->List_1_cont_2, LV_BORDER_SIDE_FULL, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_radius(ui->List_1_cont_2, 35, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ui->List_1_cont_2, 102, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_color(ui->List_1_cont_2, lv_color_hex(0x2E2E2E), LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_grad_dir(ui->List_1_cont_2, LV_GRAD_DIR_NONE, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_top(ui->List_1_cont_2, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_bottom(ui->List_1_cont_2, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_left(ui->List_1_cont_2, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_right(ui->List_1_cont_2, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_width(ui->List_1_cont_2, 0, LV_PART_MAIN|LV_STATE_DEFAULT);

    //Write codes List_1_img_1
    ui->List_1_img_1 = lv_img_create(ui->List_1_cont_2);
    lv_obj_add_flag(ui->List_1_img_1, LV_OBJ_FLAG_CLICKABLE);
    lv_img_set_src(ui->List_1_img_1, &_heart32x32_alpha_30x30);
    lv_img_set_pivot(ui->List_1_img_1, 50,50);
    lv_img_set_angle(ui->List_1_img_1, 0);
    lv_obj_set_pos(ui->List_1_img_1, 28, 24);
    lv_obj_set_size(ui->List_1_img_1, 30, 30);

    //Write style for List_1_img_1, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
    lv_obj_set_style_img_recolor_opa(ui->List_1_img_1, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_img_opa(ui->List_1_img_1, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_radius(ui->List_1_img_1, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_clip_corner(ui->List_1_img_1, true, LV_PART_MAIN|LV_STATE_DEFAULT);

    //Write codes List_1_label_2
    ui->List_1_label_2 = lv_label_create(ui->List_1_cont_2);
    lv_label_set_text(ui->List_1_label_2, "Heart rate");
    lv_label_set_long_mode(ui->List_1_label_2, LV_LABEL_LONG_WRAP);
    lv_obj_set_pos(ui->List_1_label_2, 49, 28);
    lv_obj_set_size(ui->List_1_label_2, 135, 18);

    //Write style for List_1_label_2, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
    lv_obj_set_style_border_width(ui->List_1_label_2, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_radius(ui->List_1_label_2, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_color(ui->List_1_label_2, lv_color_hex(0xffffff), LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_font(ui->List_1_label_2, &lv_font_montserratMedium_16, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_opa(ui->List_1_label_2, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_letter_space(ui->List_1_label_2, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_line_space(ui->List_1_label_2, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_align(ui->List_1_label_2, LV_TEXT_ALIGN_CENTER, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ui->List_1_label_2, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_top(ui->List_1_label_2, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_right(ui->List_1_label_2, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_bottom(ui->List_1_label_2, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_left(ui->List_1_label_2, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_width(ui->List_1_label_2, 0, LV_PART_MAIN|LV_STATE_DEFAULT);

    //Write codes List_1_cont_3
    ui->List_1_cont_3 = lv_obj_create(ui->List_1_cont_1);
    lv_obj_set_pos(ui->List_1_cont_3, 0, 84);
    lv_obj_set_size(ui->List_1_cont_3, 215, 69);
    lv_obj_set_scrollbar_mode(ui->List_1_cont_3, LV_SCROLLBAR_MODE_OFF);

    //Write style for List_1_cont_3, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
    lv_obj_set_style_border_width(ui->List_1_cont_3, 2, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_border_opa(ui->List_1_cont_3, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_border_color(ui->List_1_cont_3, lv_color_hex(0x2E2E2E), LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_border_side(ui->List_1_cont_3, LV_BORDER_SIDE_FULL, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_radius(ui->List_1_cont_3, 35, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ui->List_1_cont_3, 102, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_color(ui->List_1_cont_3, lv_color_hex(0x2E2E2E), LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_grad_dir(ui->List_1_cont_3, LV_GRAD_DIR_NONE, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_top(ui->List_1_cont_3, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_bottom(ui->List_1_cont_3, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_left(ui->List_1_cont_3, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_right(ui->List_1_cont_3, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_width(ui->List_1_cont_3, 0, LV_PART_MAIN|LV_STATE_DEFAULT);

    //Write codes List_1_img_2
    ui->List_1_img_2 = lv_img_create(ui->List_1_cont_3);
    lv_obj_add_flag(ui->List_1_img_2, LV_OBJ_FLAG_CLICKABLE);
    lv_img_set_src(ui->List_1_img_2, &_location32x32_alpha_30x30);
    lv_img_set_pivot(ui->List_1_img_2, 50,50);
    lv_img_set_angle(ui->List_1_img_2, 0);
    lv_obj_set_pos(ui->List_1_img_2, 28, 17);
    lv_obj_set_size(ui->List_1_img_2, 30, 30);

    //Write style for List_1_img_2, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
    lv_obj_set_style_img_recolor_opa(ui->List_1_img_2, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_img_opa(ui->List_1_img_2, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_radius(ui->List_1_img_2, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_clip_corner(ui->List_1_img_2, true, LV_PART_MAIN|LV_STATE_DEFAULT);

    //Write codes List_1_label_1
    ui->List_1_label_1 = lv_label_create(ui->List_1_cont_3);
    lv_label_set_text(ui->List_1_label_1, "Electronic fence");
    lv_label_set_long_mode(ui->List_1_label_1, LV_LABEL_LONG_WRAP);
    lv_obj_set_pos(ui->List_1_label_1, 63, 23);
    lv_obj_set_size(ui->List_1_label_1, 135, 18);

    //Write style for List_1_label_1, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
    lv_obj_set_style_border_width(ui->List_1_label_1, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_radius(ui->List_1_label_1, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_color(ui->List_1_label_1, lv_color_hex(0xffffff), LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_font(ui->List_1_label_1, &lv_font_montserratMedium_16, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_opa(ui->List_1_label_1, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_letter_space(ui->List_1_label_1, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_line_space(ui->List_1_label_1, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_align(ui->List_1_label_1, LV_TEXT_ALIGN_CENTER, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ui->List_1_label_1, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_top(ui->List_1_label_1, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_right(ui->List_1_label_1, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_bottom(ui->List_1_label_1, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_left(ui->List_1_label_1, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_width(ui->List_1_label_1, 0, LV_PART_MAIN|LV_STATE_DEFAULT);

    //Write codes List_1_cont_4
    ui->List_1_cont_4 = lv_obj_create(ui->List_1_cont_1);
    lv_obj_set_pos(ui->List_1_cont_4, 0, 167);
    lv_obj_set_size(ui->List_1_cont_4, 215, 69);
    lv_obj_set_scrollbar_mode(ui->List_1_cont_4, LV_SCROLLBAR_MODE_OFF);

    //Write style for List_1_cont_4, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
    lv_obj_set_style_border_width(ui->List_1_cont_4, 2, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_border_opa(ui->List_1_cont_4, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_border_color(ui->List_1_cont_4, lv_color_hex(0x2E2E2E), LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_border_side(ui->List_1_cont_4, LV_BORDER_SIDE_FULL, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_radius(ui->List_1_cont_4, 35, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ui->List_1_cont_4, 102, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_color(ui->List_1_cont_4, lv_color_hex(0x2E2E2E), LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_grad_dir(ui->List_1_cont_4, LV_GRAD_DIR_NONE, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_top(ui->List_1_cont_4, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_bottom(ui->List_1_cont_4, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_left(ui->List_1_cont_4, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_right(ui->List_1_cont_4, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_width(ui->List_1_cont_4, 0, LV_PART_MAIN|LV_STATE_DEFAULT);

    //Write codes List_1_img_3
    ui->List_1_img_3 = lv_img_create(ui->List_1_cont_4);
    lv_obj_add_flag(ui->List_1_img_3, LV_OBJ_FLAG_CLICKABLE);
    lv_img_set_src(ui->List_1_img_3, &_NFC32x32_alpha_30x30);
    lv_img_set_pivot(ui->List_1_img_3, 50,50);
    lv_img_set_angle(ui->List_1_img_3, 0);
    lv_obj_set_pos(ui->List_1_img_3, 28, 18);
    lv_obj_set_size(ui->List_1_img_3, 30, 30);

    //Write style for List_1_img_3, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
    lv_obj_set_style_img_recolor_opa(ui->List_1_img_3, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_img_opa(ui->List_1_img_3, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_radius(ui->List_1_img_3, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_clip_corner(ui->List_1_img_3, true, LV_PART_MAIN|LV_STATE_DEFAULT);

    //Write codes List_1_label_3
    ui->List_1_label_3 = lv_label_create(ui->List_1_cont_4);
    lv_label_set_text(ui->List_1_label_3, "Electronic card");
    lv_label_set_long_mode(ui->List_1_label_3, LV_LABEL_LONG_WRAP);
    lv_obj_set_pos(ui->List_1_label_3, 61, 24);
    lv_obj_set_size(ui->List_1_label_3, 135, 18);

    //Write style for List_1_label_3, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
    lv_obj_set_style_border_width(ui->List_1_label_3, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_radius(ui->List_1_label_3, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_color(ui->List_1_label_3, lv_color_hex(0xffffff), LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_font(ui->List_1_label_3, &lv_font_montserratMedium_16, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_opa(ui->List_1_label_3, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_letter_space(ui->List_1_label_3, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_line_space(ui->List_1_label_3, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_align(ui->List_1_label_3, LV_TEXT_ALIGN_CENTER, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ui->List_1_label_3, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_top(ui->List_1_label_3, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_right(ui->List_1_label_3, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_bottom(ui->List_1_label_3, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_left(ui->List_1_label_3, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_width(ui->List_1_label_3, 0, LV_PART_MAIN|LV_STATE_DEFAULT);

    //Write codes List_1_cont_5
    ui->List_1_cont_5 = lv_obj_create(ui->List_1_cont_1);
    lv_obj_set_pos(ui->List_1_cont_5, 1, 250);
    lv_obj_set_size(ui->List_1_cont_5, 215, 69);
    lv_obj_set_scrollbar_mode(ui->List_1_cont_5, LV_SCROLLBAR_MODE_OFF);

    //Write style for List_1_cont_5, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
    lv_obj_set_style_border_width(ui->List_1_cont_5, 2, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_border_opa(ui->List_1_cont_5, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_border_color(ui->List_1_cont_5, lv_color_hex(0x2E2E2E), LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_border_side(ui->List_1_cont_5, LV_BORDER_SIDE_FULL, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_radius(ui->List_1_cont_5, 35, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ui->List_1_cont_5, 102, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_color(ui->List_1_cont_5, lv_color_hex(0x2E2E2E), LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_grad_dir(ui->List_1_cont_5, LV_GRAD_DIR_NONE, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_top(ui->List_1_cont_5, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_bottom(ui->List_1_cont_5, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_left(ui->List_1_cont_5, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_right(ui->List_1_cont_5, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_width(ui->List_1_cont_5, 0, LV_PART_MAIN|LV_STATE_DEFAULT);

    //Write codes List_1_img_4
    ui->List_1_img_4 = lv_img_create(ui->List_1_cont_5);
    lv_obj_add_flag(ui->List_1_img_4, LV_OBJ_FLAG_CLICKABLE);
    lv_img_set_src(ui->List_1_img_4, &_qrcode32x32_alpha_30x30);
    lv_img_set_pivot(ui->List_1_img_4, 50,50);
    lv_img_set_angle(ui->List_1_img_4, 0);
    lv_obj_set_pos(ui->List_1_img_4, 28, 19);
    lv_obj_set_size(ui->List_1_img_4, 30, 30);

    //Write style for List_1_img_4, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
    lv_obj_set_style_img_recolor_opa(ui->List_1_img_4, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_img_opa(ui->List_1_img_4, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_radius(ui->List_1_img_4, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_clip_corner(ui->List_1_img_4, true, LV_PART_MAIN|LV_STATE_DEFAULT);

    //Write codes List_1_label_4
    ui->List_1_label_4 = lv_label_create(ui->List_1_cont_5);
    lv_label_set_text(ui->List_1_label_4, "QR code\n");
    lv_label_set_long_mode(ui->List_1_label_4, LV_LABEL_LONG_WRAP);
    lv_obj_set_pos(ui->List_1_label_4, 65, 26);
    lv_obj_set_size(ui->List_1_label_4, 135, 18);

    //Write style for List_1_label_4, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
    lv_obj_set_style_border_width(ui->List_1_label_4, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_radius(ui->List_1_label_4, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_color(ui->List_1_label_4, lv_color_hex(0xffffff), LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_font(ui->List_1_label_4, &lv_font_montserratMedium_16, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_opa(ui->List_1_label_4, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_letter_space(ui->List_1_label_4, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_line_space(ui->List_1_label_4, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_align(ui->List_1_label_4, LV_TEXT_ALIGN_CENTER, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ui->List_1_label_4, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_top(ui->List_1_label_4, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_right(ui->List_1_label_4, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_bottom(ui->List_1_label_4, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_left(ui->List_1_label_4, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_width(ui->List_1_label_4, 0, LV_PART_MAIN|LV_STATE_DEFAULT);

    //Write codes List_1_cont_6
    ui->List_1_cont_6 = lv_obj_create(ui->List_1_cont_1);
    lv_obj_set_pos(ui->List_1_cont_6, 0, 333);
    lv_obj_set_size(ui->List_1_cont_6, 215, 69);
    lv_obj_set_scrollbar_mode(ui->List_1_cont_6, LV_SCROLLBAR_MODE_OFF);

    //Write style for List_1_cont_6, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
    lv_obj_set_style_border_width(ui->List_1_cont_6, 2, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_border_opa(ui->List_1_cont_6, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_border_color(ui->List_1_cont_6, lv_color_hex(0x2E2E2E), LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_border_side(ui->List_1_cont_6, LV_BORDER_SIDE_FULL, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_radius(ui->List_1_cont_6, 35, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ui->List_1_cont_6, 102, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_color(ui->List_1_cont_6, lv_color_hex(0x2E2E2E), LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_grad_dir(ui->List_1_cont_6, LV_GRAD_DIR_NONE, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_top(ui->List_1_cont_6, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_bottom(ui->List_1_cont_6, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_left(ui->List_1_cont_6, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_right(ui->List_1_cont_6, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_width(ui->List_1_cont_6, 0, LV_PART_MAIN|LV_STATE_DEFAULT);

    //Write codes List_1_img_5
    ui->List_1_img_5 = lv_img_create(ui->List_1_cont_6);
    lv_obj_add_flag(ui->List_1_img_5, LV_OBJ_FLAG_CLICKABLE);
    lv_img_set_src(ui->List_1_img_5, &_syteam32x32_alpha_30x30);
    lv_img_set_pivot(ui->List_1_img_5, 50,50);
    lv_img_set_angle(ui->List_1_img_5, 0);
    lv_obj_set_pos(ui->List_1_img_5, 28, 19);
    lv_obj_set_size(ui->List_1_img_5, 30, 30);

    //Write style for List_1_img_5, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
    lv_obj_set_style_img_recolor_opa(ui->List_1_img_5, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_img_opa(ui->List_1_img_5, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_radius(ui->List_1_img_5, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_clip_corner(ui->List_1_img_5, true, LV_PART_MAIN|LV_STATE_DEFAULT);

    //Write codes List_1_label_5
    ui->List_1_label_5 = lv_label_create(ui->List_1_cont_6);
    lv_label_set_text(ui->List_1_label_5, "Sys Update\n\n");
    lv_label_set_long_mode(ui->List_1_label_5, LV_LABEL_LONG_WRAP);
    lv_obj_set_pos(ui->List_1_label_5, 66, 26);
    lv_obj_set_size(ui->List_1_label_5, 135, 18);

    //Write style for List_1_label_5, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
    lv_obj_set_style_border_width(ui->List_1_label_5, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_radius(ui->List_1_label_5, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_color(ui->List_1_label_5, lv_color_hex(0xffffff), LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_font(ui->List_1_label_5, &lv_font_montserratMedium_16, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_opa(ui->List_1_label_5, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_letter_space(ui->List_1_label_5, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_line_space(ui->List_1_label_5, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_align(ui->List_1_label_5, LV_TEXT_ALIGN_CENTER, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ui->List_1_label_5, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_top(ui->List_1_label_5, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_right(ui->List_1_label_5, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_bottom(ui->List_1_label_5, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_left(ui->List_1_label_5, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_width(ui->List_1_label_5, 0, LV_PART_MAIN|LV_STATE_DEFAULT);

    //Write codes List_1_cont_8
    ui->List_1_cont_8 = lv_obj_create(ui->List_1_cont_1);
    lv_obj_set_pos(ui->List_1_cont_8, 2, 499);
    lv_obj_set_size(ui->List_1_cont_8, 215, 69);
    lv_obj_set_scrollbar_mode(ui->List_1_cont_8, LV_SCROLLBAR_MODE_OFF);

    //Write style for List_1_cont_8, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
    lv_obj_set_style_border_width(ui->List_1_cont_8, 2, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_border_opa(ui->List_1_cont_8, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_border_color(ui->List_1_cont_8, lv_color_hex(0x2E2E2E), LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_border_side(ui->List_1_cont_8, LV_BORDER_SIDE_FULL, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_radius(ui->List_1_cont_8, 35, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ui->List_1_cont_8, 102, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_color(ui->List_1_cont_8, lv_color_hex(0x2E2E2E), LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_grad_dir(ui->List_1_cont_8, LV_GRAD_DIR_NONE, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_top(ui->List_1_cont_8, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_bottom(ui->List_1_cont_8, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_left(ui->List_1_cont_8, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_right(ui->List_1_cont_8, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_width(ui->List_1_cont_8, 0, LV_PART_MAIN|LV_STATE_DEFAULT);

    //Write codes List_1_img_7
    ui->List_1_img_7 = lv_img_create(ui->List_1_cont_8);
    lv_obj_add_flag(ui->List_1_img_7, LV_OBJ_FLAG_CLICKABLE);
    lv_img_set_src(ui->List_1_img_7, &_set32x32_alpha_30x30);
    lv_img_set_pivot(ui->List_1_img_7, 50,50);
    lv_img_set_angle(ui->List_1_img_7, 0);
    lv_obj_set_pos(ui->List_1_img_7, 28, 19);
    lv_obj_set_size(ui->List_1_img_7, 30, 30);

    //Write style for List_1_img_7, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
    lv_obj_set_style_img_recolor_opa(ui->List_1_img_7, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_img_opa(ui->List_1_img_7, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_radius(ui->List_1_img_7, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_clip_corner(ui->List_1_img_7, true, LV_PART_MAIN|LV_STATE_DEFAULT);

    //Write codes List_1_label_7
    ui->List_1_label_7 = lv_label_create(ui->List_1_cont_8);
    lv_label_set_text(ui->List_1_label_7, "Set\n");
    lv_label_set_long_mode(ui->List_1_label_7, LV_LABEL_LONG_WRAP);
    lv_obj_set_pos(ui->List_1_label_7, 66, 26);
    lv_obj_set_size(ui->List_1_label_7, 135, 18);

    //Write style for List_1_label_7, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
    lv_obj_set_style_border_width(ui->List_1_label_7, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_radius(ui->List_1_label_7, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_color(ui->List_1_label_7, lv_color_hex(0xffffff), LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_font(ui->List_1_label_7, &lv_font_montserratMedium_16, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_opa(ui->List_1_label_7, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_letter_space(ui->List_1_label_7, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_line_space(ui->List_1_label_7, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_align(ui->List_1_label_7, LV_TEXT_ALIGN_CENTER, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ui->List_1_label_7, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_top(ui->List_1_label_7, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_right(ui->List_1_label_7, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_bottom(ui->List_1_label_7, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_left(ui->List_1_label_7, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_width(ui->List_1_label_7, 0, LV_PART_MAIN|LV_STATE_DEFAULT);

    //Write codes List_1_cont_7
    ui->List_1_cont_7 = lv_obj_create(ui->List_1_cont_1);
    lv_obj_set_pos(ui->List_1_cont_7, 2, 416);
    lv_obj_set_size(ui->List_1_cont_7, 215, 69);
    lv_obj_set_scrollbar_mode(ui->List_1_cont_7, LV_SCROLLBAR_MODE_OFF);

    //Write style for List_1_cont_7, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
    lv_obj_set_style_border_width(ui->List_1_cont_7, 2, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_border_opa(ui->List_1_cont_7, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_border_color(ui->List_1_cont_7, lv_color_hex(0x2E2E2E), LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_border_side(ui->List_1_cont_7, LV_BORDER_SIDE_FULL, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_radius(ui->List_1_cont_7, 35, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ui->List_1_cont_7, 102, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_color(ui->List_1_cont_7, lv_color_hex(0x2E2E2E), LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_grad_dir(ui->List_1_cont_7, LV_GRAD_DIR_NONE, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_top(ui->List_1_cont_7, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_bottom(ui->List_1_cont_7, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_left(ui->List_1_cont_7, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_right(ui->List_1_cont_7, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_width(ui->List_1_cont_7, 0, LV_PART_MAIN|LV_STATE_DEFAULT);

    //Write codes List_1_img_6
    ui->List_1_img_6 = lv_img_create(ui->List_1_cont_7);
    lv_obj_add_flag(ui->List_1_img_6, LV_OBJ_FLAG_CLICKABLE);
    lv_img_set_src(ui->List_1_img_6, &_weater32x32_alpha_30x30);
    lv_img_set_pivot(ui->List_1_img_6, 50,50);
    lv_img_set_angle(ui->List_1_img_6, 0);
    lv_obj_set_pos(ui->List_1_img_6, 28, 19);
    lv_obj_set_size(ui->List_1_img_6, 30, 30);

    //Write style for List_1_img_6, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
    lv_obj_set_style_img_recolor_opa(ui->List_1_img_6, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_img_opa(ui->List_1_img_6, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_radius(ui->List_1_img_6, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_clip_corner(ui->List_1_img_6, true, LV_PART_MAIN|LV_STATE_DEFAULT);

    //Write codes List_1_label_6
    ui->List_1_label_6 = lv_label_create(ui->List_1_cont_7);
    lv_label_set_text(ui->List_1_label_6, "Weather\n");
    lv_label_set_long_mode(ui->List_1_label_6, LV_LABEL_LONG_WRAP);
    lv_obj_set_pos(ui->List_1_label_6, 66, 26);
    lv_obj_set_size(ui->List_1_label_6, 135, 18);

    //Write style for List_1_label_6, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
    lv_obj_set_style_border_width(ui->List_1_label_6, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_radius(ui->List_1_label_6, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_color(ui->List_1_label_6, lv_color_hex(0xffffff), LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_font(ui->List_1_label_6, &lv_font_montserratMedium_16, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_opa(ui->List_1_label_6, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_letter_space(ui->List_1_label_6, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_line_space(ui->List_1_label_6, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_align(ui->List_1_label_6, LV_TEXT_ALIGN_CENTER, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ui->List_1_label_6, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_top(ui->List_1_label_6, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_right(ui->List_1_label_6, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_bottom(ui->List_1_label_6, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_left(ui->List_1_label_6, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_width(ui->List_1_label_6, 0, LV_PART_MAIN|LV_STATE_DEFAULT);

    //Write codes List_1_btn_2
    ui->List_1_btn_2 = lv_btn_create(ui->List_1);
    ui->List_1_btn_2_label = lv_label_create(ui->List_1_btn_2);
    lv_label_set_text(ui->List_1_btn_2_label, "+");
    lv_label_set_long_mode(ui->List_1_btn_2_label, LV_LABEL_LONG_WRAP);
    lv_obj_align(ui->List_1_btn_2_label, LV_ALIGN_CENTER, 0, 0);
    lv_obj_set_style_pad_all(ui->List_1_btn_2, 0, LV_STATE_DEFAULT);
    lv_obj_set_width(ui->List_1_btn_2_label, LV_PCT(100));
    lv_obj_set_pos(ui->List_1_btn_2, 13, 627);
    lv_obj_set_size(ui->List_1_btn_2, 215, 69);

    //Write style for List_1_btn_2, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
    lv_obj_set_style_radius(ui->List_1_btn_2, 35, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ui->List_1_btn_2, 102, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_color(ui->List_1_btn_2, lv_color_hex(0x2E2E2E), LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_grad_dir(ui->List_1_btn_2, LV_GRAD_DIR_NONE, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_border_width(ui->List_1_btn_2, 2, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_border_opa(ui->List_1_btn_2, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_border_color(ui->List_1_btn_2, lv_color_hex(0x2E2E2E), LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_border_side(ui->List_1_btn_2, LV_BORDER_SIDE_FULL, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_width(ui->List_1_btn_2, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_color(ui->List_1_btn_2, lv_color_hex(0xffffff), LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_font(ui->List_1_btn_2, &lv_font_montserratMedium_16, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_opa(ui->List_1_btn_2, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_align(ui->List_1_btn_2, LV_TEXT_ALIGN_CENTER, LV_PART_MAIN|LV_STATE_DEFAULT);

    //The custom code of List_1.


    //Update current screen layout.
    lv_obj_update_layout(ui->List_1);

    //Init events for screen.
    events_init_List_1(ui);
}
