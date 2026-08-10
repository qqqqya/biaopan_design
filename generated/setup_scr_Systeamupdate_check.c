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



void setup_scr_Systeamupdate_check(lv_ui *ui)
{
    //Write codes Systeamupdate_check
    ui->Systeamupdate_check = lv_obj_create(NULL);
    lv_obj_set_size(ui->Systeamupdate_check, 240, 280);
    lv_obj_set_scrollbar_mode(ui->Systeamupdate_check, LV_SCROLLBAR_MODE_OFF);

    //Write style for Systeamupdate_check, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
    lv_obj_set_style_bg_opa(ui->Systeamupdate_check, 253, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_color(ui->Systeamupdate_check, lv_color_hex(0x000000), LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_grad_dir(ui->Systeamupdate_check, LV_GRAD_DIR_NONE, LV_PART_MAIN|LV_STATE_DEFAULT);

    //Write codes Systeamupdate_check_label_1
    ui->Systeamupdate_check_label_1 = lv_label_create(ui->Systeamupdate_check);
    lv_label_set_text(ui->Systeamupdate_check_label_1, "update now?");
    lv_label_set_long_mode(ui->Systeamupdate_check_label_1, LV_LABEL_LONG_WRAP);
    lv_obj_set_pos(ui->Systeamupdate_check_label_1, 62, 72);
    lv_obj_set_size(ui->Systeamupdate_check_label_1, 124, 63);

    //Write style for Systeamupdate_check_label_1, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
    lv_obj_set_style_border_width(ui->Systeamupdate_check_label_1, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_radius(ui->Systeamupdate_check_label_1, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_color(ui->Systeamupdate_check_label_1, lv_color_hex(0xffffff), LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_font(ui->Systeamupdate_check_label_1, &lv_font_montserratMedium_26, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_opa(ui->Systeamupdate_check_label_1, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_letter_space(ui->Systeamupdate_check_label_1, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_line_space(ui->Systeamupdate_check_label_1, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_align(ui->Systeamupdate_check_label_1, LV_TEXT_ALIGN_CENTER, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ui->Systeamupdate_check_label_1, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_top(ui->Systeamupdate_check_label_1, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_right(ui->Systeamupdate_check_label_1, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_bottom(ui->Systeamupdate_check_label_1, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_left(ui->Systeamupdate_check_label_1, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_width(ui->Systeamupdate_check_label_1, 0, LV_PART_MAIN|LV_STATE_DEFAULT);

    //Write codes Systeamupdate_check_btn_1
    ui->Systeamupdate_check_btn_1 = lv_btn_create(ui->Systeamupdate_check);
    ui->Systeamupdate_check_btn_1_label = lv_label_create(ui->Systeamupdate_check_btn_1);
    lv_label_set_text(ui->Systeamupdate_check_btn_1_label, "" LV_SYMBOL_CLOSE " ");
    lv_label_set_long_mode(ui->Systeamupdate_check_btn_1_label, LV_LABEL_LONG_WRAP);
    lv_obj_align(ui->Systeamupdate_check_btn_1_label, LV_ALIGN_CENTER, 0, 0);
    lv_obj_set_style_pad_all(ui->Systeamupdate_check_btn_1, 0, LV_STATE_DEFAULT);
    lv_obj_set_width(ui->Systeamupdate_check_btn_1_label, LV_PCT(100));
    lv_obj_set_pos(ui->Systeamupdate_check_btn_1, 42, 192);
    lv_obj_set_size(ui->Systeamupdate_check_btn_1, 70, 32);

    //Write style for Systeamupdate_check_btn_1, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
    lv_obj_set_style_bg_opa(ui->Systeamupdate_check_btn_1, 253, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_color(ui->Systeamupdate_check_btn_1, lv_color_hex(0x5e5e5e), LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_grad_dir(ui->Systeamupdate_check_btn_1, LV_GRAD_DIR_NONE, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_border_width(ui->Systeamupdate_check_btn_1, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_radius(ui->Systeamupdate_check_btn_1, 5, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_width(ui->Systeamupdate_check_btn_1, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_color(ui->Systeamupdate_check_btn_1, lv_color_hex(0xffffff), LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_font(ui->Systeamupdate_check_btn_1, &lv_font_montserratMedium_16, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_opa(ui->Systeamupdate_check_btn_1, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_align(ui->Systeamupdate_check_btn_1, LV_TEXT_ALIGN_CENTER, LV_PART_MAIN|LV_STATE_DEFAULT);

    //Write codes Systeamupdate_check_btn_2
    ui->Systeamupdate_check_btn_2 = lv_btn_create(ui->Systeamupdate_check);
    ui->Systeamupdate_check_btn_2_label = lv_label_create(ui->Systeamupdate_check_btn_2);
    lv_label_set_text(ui->Systeamupdate_check_btn_2_label, "" LV_SYMBOL_OK " ");
    lv_label_set_long_mode(ui->Systeamupdate_check_btn_2_label, LV_LABEL_LONG_WRAP);
    lv_obj_align(ui->Systeamupdate_check_btn_2_label, LV_ALIGN_CENTER, 0, 0);
    lv_obj_set_style_pad_all(ui->Systeamupdate_check_btn_2, 0, LV_STATE_DEFAULT);
    lv_obj_set_width(ui->Systeamupdate_check_btn_2_label, LV_PCT(100));
    lv_obj_set_pos(ui->Systeamupdate_check_btn_2, 143, 192);
    lv_obj_set_size(ui->Systeamupdate_check_btn_2, 70, 32);

    //Write style for Systeamupdate_check_btn_2, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
    lv_obj_set_style_bg_opa(ui->Systeamupdate_check_btn_2, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_color(ui->Systeamupdate_check_btn_2, lv_color_hex(0xffb900), LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_grad_dir(ui->Systeamupdate_check_btn_2, LV_GRAD_DIR_NONE, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_border_width(ui->Systeamupdate_check_btn_2, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_radius(ui->Systeamupdate_check_btn_2, 5, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_width(ui->Systeamupdate_check_btn_2, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_color(ui->Systeamupdate_check_btn_2, lv_color_hex(0xffffff), LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_font(ui->Systeamupdate_check_btn_2, &lv_font_montserratMedium_16, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_opa(ui->Systeamupdate_check_btn_2, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_align(ui->Systeamupdate_check_btn_2, LV_TEXT_ALIGN_CENTER, LV_PART_MAIN|LV_STATE_DEFAULT);

    //The custom code of Systeamupdate_check.


    //Update current screen layout.
    lv_obj_update_layout(ui->Systeamupdate_check);

    //Init events for screen.
    events_init_Systeamupdate_check(ui);
}
