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



int screen_1_digital_clock_1_min_value = 25;
int screen_1_digital_clock_1_hour_value = 11;
int screen_1_digital_clock_1_sec_value = 50;
void setup_scr_screen_1(lv_ui *ui)
{
    //Write codes screen_1
    ui->screen_1 = lv_obj_create(NULL);
    lv_obj_set_size(ui->screen_1, 240, 280);
    lv_obj_set_scrollbar_mode(ui->screen_1, LV_SCROLLBAR_MODE_OFF);

    //Write style for screen_1, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
    lv_obj_set_style_bg_opa(ui->screen_1, 0, LV_PART_MAIN|LV_STATE_DEFAULT);

    //Write codes screen_1_cont_2
    ui->screen_1_cont_2 = lv_obj_create(ui->screen_1);
    lv_obj_set_pos(ui->screen_1_cont_2, 0, 0);
    lv_obj_set_size(ui->screen_1_cont_2, 240, 280);
    lv_obj_set_scrollbar_mode(ui->screen_1_cont_2, LV_SCROLLBAR_MODE_OFF);

    //Write style for screen_1_cont_2, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
    lv_obj_set_style_border_width(ui->screen_1_cont_2, 2, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_border_opa(ui->screen_1_cont_2, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_border_color(ui->screen_1_cont_2, lv_color_hex(0x2195f6), LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_border_side(ui->screen_1_cont_2, LV_BORDER_SIDE_FULL, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_radius(ui->screen_1_cont_2, 40, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ui->screen_1_cont_2, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_color(ui->screen_1_cont_2, lv_color_hex(0xffffff), LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_grad_dir(ui->screen_1_cont_2, LV_GRAD_DIR_NONE, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_top(ui->screen_1_cont_2, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_bottom(ui->screen_1_cont_2, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_left(ui->screen_1_cont_2, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_right(ui->screen_1_cont_2, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_width(ui->screen_1_cont_2, 0, LV_PART_MAIN|LV_STATE_DEFAULT);

    //Write codes screen_1_img_1
    ui->screen_1_img_1 = lv_img_create(ui->screen_1);
    lv_obj_add_flag(ui->screen_1_img_1, LV_OBJ_FLAG_CLICKABLE);
    lv_img_set_src(ui->screen_1_img_1, &_MDLBG_alpha_240x280);
    lv_img_set_pivot(ui->screen_1_img_1, 50,50);
    lv_img_set_angle(ui->screen_1_img_1, 0);
    lv_obj_set_pos(ui->screen_1_img_1, 0, 0);
    lv_obj_set_size(ui->screen_1_img_1, 240, 280);

    //Write style for screen_1_img_1, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
    lv_obj_set_style_img_recolor_opa(ui->screen_1_img_1, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_img_opa(ui->screen_1_img_1, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_radius(ui->screen_1_img_1, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_clip_corner(ui->screen_1_img_1, true, LV_PART_MAIN|LV_STATE_DEFAULT);

    //Write codes screen_1_digital_clock_1
    static bool screen_1_digital_clock_1_timer_enabled = false;
    ui->screen_1_digital_clock_1 = lv_dclock_create(ui->screen_1, "11:25:50");
    if (!screen_1_digital_clock_1_timer_enabled) {
        lv_timer_create(screen_1_digital_clock_1_timer, 1000, NULL);
        screen_1_digital_clock_1_timer_enabled = true;
    }
    lv_obj_set_pos(ui->screen_1_digital_clock_1, 100, 81);
    lv_obj_set_size(ui->screen_1_digital_clock_1, 130, 36);

    //Write style for screen_1_digital_clock_1, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
    lv_obj_set_style_radius(ui->screen_1_digital_clock_1, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_color(ui->screen_1_digital_clock_1, lv_color_hex(0xf00000), LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_font(ui->screen_1_digital_clock_1, &lv_font_montserratMedium_25, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_opa(ui->screen_1_digital_clock_1, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_letter_space(ui->screen_1_digital_clock_1, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_align(ui->screen_1_digital_clock_1, LV_TEXT_ALIGN_CENTER, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ui->screen_1_digital_clock_1, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_color(ui->screen_1_digital_clock_1, lv_color_hex(0xffbf00), LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_grad_dir(ui->screen_1_digital_clock_1, LV_GRAD_DIR_NONE, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_top(ui->screen_1_digital_clock_1, 7, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_right(ui->screen_1_digital_clock_1, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_bottom(ui->screen_1_digital_clock_1, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_left(ui->screen_1_digital_clock_1, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_width(ui->screen_1_digital_clock_1, 0, LV_PART_MAIN|LV_STATE_DEFAULT);

    //Write codes screen_1_datetext_1
    ui->screen_1_datetext_1 = lv_label_create(ui->screen_1);
    lv_label_set_text(ui->screen_1_datetext_1, "2023/07/31");
    lv_obj_set_style_text_align(ui->screen_1_datetext_1, LV_TEXT_ALIGN_CENTER, 0);
    lv_obj_add_flag(ui->screen_1_datetext_1, LV_OBJ_FLAG_CLICKABLE);
    lv_obj_add_event_cb(ui->screen_1_datetext_1, screen_1_datetext_1_event_handler, LV_EVENT_ALL, NULL);
    lv_obj_set_pos(ui->screen_1_datetext_1, 100, 39);
    lv_obj_set_size(ui->screen_1_datetext_1, 130, 36);

    //Write style for screen_1_datetext_1, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
    lv_obj_set_style_text_color(ui->screen_1_datetext_1, lv_color_hex(0xffffff), LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_font(ui->screen_1_datetext_1, &lv_font_montserratMedium_16, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_opa(ui->screen_1_datetext_1, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_letter_space(ui->screen_1_datetext_1, 2, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_align(ui->screen_1_datetext_1, LV_TEXT_ALIGN_CENTER, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ui->screen_1_datetext_1, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_color(ui->screen_1_datetext_1, lv_color_hex(0xffbf00), LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_grad_dir(ui->screen_1_datetext_1, LV_GRAD_DIR_NONE, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_border_width(ui->screen_1_datetext_1, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_radius(ui->screen_1_datetext_1, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_top(ui->screen_1_datetext_1, 7, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_right(ui->screen_1_datetext_1, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_left(ui->screen_1_datetext_1, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_width(ui->screen_1_datetext_1, 0, LV_PART_MAIN|LV_STATE_DEFAULT);

    //The custom code of screen_1.


    //Update current screen layout.
    lv_obj_update_layout(ui->screen_1);

    //Init events for screen.
    events_init_screen_1(ui);
}
