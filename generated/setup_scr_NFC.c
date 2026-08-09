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



void setup_scr_NFC(lv_ui *ui)
{
    //Write codes NFC
    ui->NFC = lv_obj_create(NULL);
    lv_obj_set_size(ui->NFC, 240, 280);
    lv_obj_set_scrollbar_mode(ui->NFC, LV_SCROLLBAR_MODE_OFF);

    //Write style for NFC, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
    lv_obj_set_style_bg_opa(ui->NFC, 0, LV_PART_MAIN|LV_STATE_DEFAULT);

    //Write codes NFC_Label1
    ui->NFC_Label1 = lv_label_create(ui->NFC);
    lv_label_set_text(ui->NFC_Label1, "NFC");
    lv_label_set_long_mode(ui->NFC_Label1, LV_LABEL_LONG_WRAP);
    lv_obj_set_pos(ui->NFC_Label1, 70, 124);
    lv_obj_set_size(ui->NFC_Label1, 100, 32);

    //Write style for NFC_Label1, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
    lv_obj_set_style_border_width(ui->NFC_Label1, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_radius(ui->NFC_Label1, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_color(ui->NFC_Label1, lv_color_hex(0x000000), LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_font(ui->NFC_Label1, &lv_font_montserratMedium_16, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_opa(ui->NFC_Label1, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_letter_space(ui->NFC_Label1, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_line_space(ui->NFC_Label1, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_align(ui->NFC_Label1, LV_TEXT_ALIGN_CENTER, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ui->NFC_Label1, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_top(ui->NFC_Label1, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_right(ui->NFC_Label1, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_bottom(ui->NFC_Label1, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_left(ui->NFC_Label1, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_width(ui->NFC_Label1, 0, LV_PART_MAIN|LV_STATE_DEFAULT);

    //The custom code of NFC.


    //Update current screen layout.
    lv_obj_update_layout(ui->NFC);

}
