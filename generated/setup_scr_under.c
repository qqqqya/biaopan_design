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



void setup_scr_under(lv_ui *ui)
{
    //Write codes under
    ui->under = lv_obj_create(NULL);
    lv_obj_set_size(ui->under, 240, 280);
    lv_obj_set_scrollbar_mode(ui->under, LV_SCROLLBAR_MODE_OFF);

    //Write style for under, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
    lv_obj_set_style_bg_opa(ui->under, 0, LV_PART_MAIN|LV_STATE_DEFAULT);

    //Write codes under_cont_1
    ui->under_cont_1 = lv_obj_create(ui->under);
    lv_obj_set_pos(ui->under_cont_1, 0, 0);
    lv_obj_set_size(ui->under_cont_1, 240, 280);
    lv_obj_set_scrollbar_mode(ui->under_cont_1, LV_SCROLLBAR_MODE_OFF);

    //Write style for under_cont_1, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
    lv_obj_set_style_border_width(ui->under_cont_1, 2, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_border_opa(ui->under_cont_1, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_border_color(ui->under_cont_1, lv_color_hex(0x2195f6), LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_border_side(ui->under_cont_1, LV_BORDER_SIDE_FULL, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_radius(ui->under_cont_1, 40, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ui->under_cont_1, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_color(ui->under_cont_1, lv_color_hex(0x000000), LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_grad_dir(ui->under_cont_1, LV_GRAD_DIR_NONE, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_top(ui->under_cont_1, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_bottom(ui->under_cont_1, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_left(ui->under_cont_1, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_right(ui->under_cont_1, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_width(ui->under_cont_1, 0, LV_PART_MAIN|LV_STATE_DEFAULT);

    //Write codes under_cont_2
    ui->under_cont_2 = lv_obj_create(ui->under_cont_1);
    lv_obj_set_pos(ui->under_cont_2, 152, 33);
    lv_obj_set_size(ui->under_cont_2, 50, 50);
    lv_obj_set_scrollbar_mode(ui->under_cont_2, LV_SCROLLBAR_MODE_OFF);

    //Write style for under_cont_2, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
    lv_obj_set_style_border_width(ui->under_cont_2, 2, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_border_opa(ui->under_cont_2, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_border_color(ui->under_cont_2, lv_color_hex(0x2195f6), LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_border_side(ui->under_cont_2, LV_BORDER_SIDE_FULL, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_radius(ui->under_cont_2, 50, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ui->under_cont_2, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_color(ui->under_cont_2, lv_color_hex(0x00d606), LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_grad_dir(ui->under_cont_2, LV_GRAD_DIR_NONE, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_top(ui->under_cont_2, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_bottom(ui->under_cont_2, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_left(ui->under_cont_2, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_right(ui->under_cont_2, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_img_src(ui->under_cont_2, &_nfc_50x50, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_img_opa(ui->under_cont_2, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_img_recolor_opa(ui->under_cont_2, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_width(ui->under_cont_2, 0, LV_PART_MAIN|LV_STATE_DEFAULT);

    //Write codes under_img_1
    ui->under_img_1 = lv_img_create(ui->under);
    lv_obj_add_flag(ui->under_img_1, LV_OBJ_FLAG_CLICKABLE);
    lv_img_set_src(ui->under_img_1, &_ZNZBG_alpha_100x100);
    lv_img_set_pivot(ui->under_img_1, 50,50);
    lv_img_set_angle(ui->under_img_1, 0);
    lv_obj_set_pos(ui->under_img_1, 70, 90);
    lv_obj_set_size(ui->under_img_1, 100, 100);

    //Write style for under_img_1, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
    lv_obj_set_style_img_recolor_opa(ui->under_img_1, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_img_opa(ui->under_img_1, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_radius(ui->under_img_1, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_clip_corner(ui->under_img_1, true, LV_PART_MAIN|LV_STATE_DEFAULT);

    //The custom code of under.


    //Update current screen layout.
    lv_obj_update_layout(ui->under);

    //Init events for screen.
    events_init_under(ui);
}
