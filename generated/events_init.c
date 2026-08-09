/*
* Copyright 2026 NXP
* NXP Proprietary. This software is owned or controlled by NXP and may only be used strictly in
* accordance with the applicable license terms. By expressly accepting such terms or by downloading, installing,
* activating and/or otherwise using the software, you are agreeing that you have read, and that you agree to
* comply with and are bound by, such license terms.  If you do not agree to be bound by the applicable license
* terms, then you may not retain, install, activate or otherwise use the software.
*/

#include "events_init.h"
#include <stdio.h>
#include "lvgl.h"

#if LV_USE_GUIDER_SIMULATOR && LV_USE_FREEMASTER
#include "freemaster_client.h"
#endif

#include "custom.h"
bool screen_1_home_btn_1_is_click = 0;
bool screen_1_home_btn_2_is_click = 0;
bool screen_1_home_btn_3_is_click = 0;
bool screen_2_btn_1_is_click = 0;
bool screen_2_btn_2_is_click = 0;
bool screen_2_btn_3_is_click = 0;
bool screen_3_btn_1_is_click = 0;
bool screen_3_btn_2_is_click = 0;
bool screen_3_btn_3_is_click = 0;

static void screen_1_home_event_handler (lv_event_t *e)
{
    lv_event_code_t code = lv_event_get_code(e);
    switch (code) {
    case LV_EVENT_LONG_PRESSED:
    {
        lv_obj_clear_flag(guider_ui.screen_1_home_cont_shadow, LV_OBJ_FLAG_HIDDEN);
        ui_animation(guider_ui.screen_1_home_cont_shadow, 200, 0, lv_obj_get_x(guider_ui.screen_1_home_cont_shadow), 120, &lv_anim_path_overshoot, 2, 0, 0, 0, (lv_anim_exec_xcb_t)lv_obj_set_x, NULL, NULL, NULL);
        ui_animation(guider_ui.screen_1_home_cont_slide, 200, 0, lv_obj_get_x(guider_ui.screen_1_home_cont_slide), 0, &lv_anim_path_step, 2, 0, 0, 0, (lv_anim_exec_xcb_t)lv_obj_set_x, NULL, NULL, NULL);
        break;
    }
    case LV_EVENT_GESTURE:
    {
        lv_dir_t dir = lv_indev_get_gesture_dir(lv_indev_get_act());
        switch(dir) {
        case LV_DIR_LEFT:
        {
            lv_indev_wait_release(lv_indev_get_act());
            ui_load_scr_animation(&guider_ui, &guider_ui.screen_2, guider_ui.screen_2_del, &guider_ui.screen_1_home_del, setup_scr_screen_2, LV_SCR_LOAD_ANIM_NONE, 200, 2, true, false);
            screen_index=1;
            break;
        }
        case LV_DIR_BOTTOM:
        {
            lv_indev_wait_release(lv_indev_get_act());
            ui_load_scr_animation(&guider_ui, &guider_ui.top_lap, guider_ui.top_lap_del, &guider_ui.screen_1_home_del, setup_scr_top_lap, LV_SCR_LOAD_ANIM_NONE, 200, 2, true, true);
            break;
        }
        case LV_DIR_TOP:
        {
            lv_indev_wait_release(lv_indev_get_act());
            ui_load_scr_animation(&guider_ui, &guider_ui.under, guider_ui.under_del, &guider_ui.screen_1_home_del, setup_scr_under, LV_SCR_LOAD_ANIM_NONE, 200, 200, true, true);
            break;
        }
        case LV_DIR_RIGHT:
        {
            lv_indev_wait_release(lv_indev_get_act());
            ui_load_scr_animation(&guider_ui, &guider_ui.List_1, guider_ui.List_1_del, &guider_ui.screen_1_home_del, setup_scr_List_1, LV_SCR_LOAD_ANIM_MOVE_RIGHT, 200, 2, true, false);
            break;
        }
        default:
            break;
        }
        break;
    }
    default:
        break;
    }
}

static void screen_1_home_btn_3_event_handler (lv_event_t *e)
{
    lv_event_code_t code = lv_event_get_code(e);
    switch (code) {
    case LV_EVENT_CLICKED:
    {
        if(screen_1_home_btn_3_is_click) {
            screen_1_home_btn_3_is_click = 0;
            lv_obj_set_style_img_recolor_opa(guider_ui.screen_1_home_img_8, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
            lv_obj_set_style_img_recolor(guider_ui.screen_1_home_img_8, lv_color_hex(0x313131), LV_PART_MAIN|LV_STATE_DEFAULT);
            lv_obj_set_style_bg_color(guider_ui.screen_1_home_btn_3, lv_color_hex(0x5a5a5a), LV_PART_MAIN|LV_STATE_DEFAULT);
        } else {
            screen_1_home_btn_3_is_click = 1;
            lv_obj_set_style_img_recolor_opa(guider_ui.screen_1_home_img_8, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
            lv_obj_set_style_img_recolor(guider_ui.screen_1_home_img_8, lv_color_hex(0x313131), LV_PART_MAIN|LV_STATE_DEFAULT);
            lv_obj_set_style_bg_color(guider_ui.screen_1_home_btn_3, lv_color_hex(0xff6500), LV_PART_MAIN|LV_STATE_DEFAULT);
        }
        break;
    }
    default:
        break;
    }
}

static void screen_1_home_btn_2_event_handler (lv_event_t *e)
{
    lv_event_code_t code = lv_event_get_code(e);
    switch (code) {
    case LV_EVENT_CLICKED:
    {
        if(screen_1_home_btn_2_is_click) {
            screen_1_home_btn_2_is_click = 0;
            lv_obj_set_style_img_recolor_opa(guider_ui.screen_1_home_img_9, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
            lv_obj_set_style_img_recolor(guider_ui.screen_1_home_img_9, lv_color_hex(0x313131), LV_PART_MAIN|LV_STATE_DEFAULT);
            lv_obj_set_style_bg_color(guider_ui.screen_1_home_btn_2, lv_color_hex(0x5a5a5a), LV_PART_MAIN|LV_STATE_DEFAULT);
        } else {
            screen_1_home_btn_2_is_click = 1;
            lv_obj_set_style_img_recolor_opa(guider_ui.screen_1_home_img_9, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
            lv_obj_set_style_img_recolor(guider_ui.screen_1_home_img_9, lv_color_hex(0x313131), LV_PART_MAIN|LV_STATE_DEFAULT);
            lv_obj_set_style_bg_color(guider_ui.screen_1_home_btn_2, lv_color_hex(0xff6500), LV_PART_MAIN|LV_STATE_DEFAULT);
        }
        break;
    }
    default:
        break;
    }
}

static void screen_1_home_btn_1_event_handler (lv_event_t *e)
{
    lv_event_code_t code = lv_event_get_code(e);
    switch (code) {
    case LV_EVENT_CLICKED:
    {
        if(screen_1_home_btn_1_is_click) {
            screen_1_home_btn_1_is_click = 0;
            lv_obj_set_style_img_recolor_opa(guider_ui.screen_1_home_img_10, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
            lv_obj_set_style_img_recolor(guider_ui.screen_1_home_img_10, lv_color_hex(0x313131), LV_PART_MAIN|LV_STATE_DEFAULT);
            lv_obj_set_style_bg_color(guider_ui.screen_1_home_btn_1, lv_color_hex(0x5a5a5a), LV_PART_MAIN|LV_STATE_DEFAULT);
        } else {
            screen_1_home_btn_1_is_click = 1;
            lv_obj_set_style_img_recolor_opa(guider_ui.screen_1_home_img_10, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
            lv_obj_set_style_img_recolor(guider_ui.screen_1_home_img_10, lv_color_hex(0x313131), LV_PART_MAIN|LV_STATE_DEFAULT);
            lv_obj_set_style_bg_color(guider_ui.screen_1_home_btn_1, lv_color_hex(0xff6500), LV_PART_MAIN|LV_STATE_DEFAULT);
        }
        break;
    }
    default:
        break;
    }
}

static void screen_1_home_cont_shadow_event_handler (lv_event_t *e)
{
    lv_event_code_t code = lv_event_get_code(e);
    switch (code) {
    case LV_EVENT_LONG_PRESSED:
    {
        lv_obj_add_flag(guider_ui.screen_1_home_cont_shadow, LV_OBJ_FLAG_HIDDEN);
        ui_animation(guider_ui.screen_1_home_cont_shadow, 200, 0, lv_obj_get_x(guider_ui.screen_1_home_cont_shadow), 0, &lv_anim_path_overshoot, 1, 0, 0, 0, (lv_anim_exec_xcb_t)lv_obj_set_x, NULL, NULL, NULL);
        ui_animation(guider_ui.screen_1_home_cont_slide, 200, 0, lv_obj_get_x(guider_ui.screen_1_home_cont_slide), -120, &lv_anim_path_overshoot, 1, 0, 0, 0, (lv_anim_exec_xcb_t)lv_obj_set_x, NULL, NULL, NULL);
        break;
    }
    default:
        break;
    }
}

void events_init_screen_1_home (lv_ui *ui)
{
    lv_obj_add_event_cb(ui->screen_1_home, screen_1_home_event_handler, LV_EVENT_ALL, ui);
    lv_obj_add_event_cb(ui->screen_1_home_btn_3, screen_1_home_btn_3_event_handler, LV_EVENT_ALL, ui);
    lv_obj_add_event_cb(ui->screen_1_home_btn_2, screen_1_home_btn_2_event_handler, LV_EVENT_ALL, ui);
    lv_obj_add_event_cb(ui->screen_1_home_btn_1, screen_1_home_btn_1_event_handler, LV_EVENT_ALL, ui);
    lv_obj_add_event_cb(ui->screen_1_home_cont_shadow, screen_1_home_cont_shadow_event_handler, LV_EVENT_ALL, ui);
}

static void screen_2_event_handler (lv_event_t *e)
{
    lv_event_code_t code = lv_event_get_code(e);
    switch (code) {
    case LV_EVENT_LONG_PRESSED:
    {
        ui_animation(guider_ui.screen_2_cont_4, 20, 0, lv_obj_get_x(guider_ui.screen_2_cont_4), 120, &lv_anim_path_step, 1, 0, 0, 0, (lv_anim_exec_xcb_t)lv_obj_set_x, NULL, NULL, NULL);
        lv_obj_clear_flag(guider_ui.screen_2_cont_4, LV_OBJ_FLAG_HIDDEN);
        ui_animation(guider_ui.screen_2_cont_3, 20, 0, lv_obj_get_x(guider_ui.screen_2_cont_3), 0, &lv_anim_path_step, 1, 0, 0, 0, (lv_anim_exec_xcb_t)lv_obj_set_x, NULL, NULL, NULL);
        break;
    }
    case LV_EVENT_GESTURE:
    {
        lv_dir_t dir = lv_indev_get_gesture_dir(lv_indev_get_act());
        switch(dir) {
        case LV_DIR_LEFT:
        {
            lv_indev_wait_release(lv_indev_get_act());
            ui_load_scr_animation(&guider_ui, &guider_ui.screen_3, guider_ui.screen_3_del, &guider_ui.screen_2_del, setup_scr_screen_3, LV_SCR_LOAD_ANIM_NONE, 200, 2, true, false);
            screen_index=2;
            break;
        }
        case LV_DIR_BOTTOM:
        {
            lv_indev_wait_release(lv_indev_get_act());
            ui_load_scr_animation(&guider_ui, &guider_ui.top_lap, guider_ui.top_lap_del, &guider_ui.screen_2_del, setup_scr_top_lap, LV_SCR_LOAD_ANIM_OVER_BOTTOM, 200, 2, true, false);
            break;
        }
        case LV_DIR_TOP:
        {
            lv_indev_wait_release(lv_indev_get_act());
            ui_load_scr_animation(&guider_ui, &guider_ui.under, guider_ui.under_del, &guider_ui.screen_2_del, setup_scr_under, LV_SCR_LOAD_ANIM_MOVE_TOP, 200, 2, true, false);
            break;
        }
        default:
            break;
        }
        break;
    }
    default:
        break;
    }
}

static void screen_2_btn_3_event_handler (lv_event_t *e)
{
    lv_event_code_t code = lv_event_get_code(e);
    switch (code) {
    case LV_EVENT_CLICKED:
    {
        if(screen_2_btn_3_is_click) {
            screen_2_btn_3_is_click = 0;
            lv_obj_set_style_img_recolor_opa(guider_ui.screen_2_img_6, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
            lv_obj_set_style_img_recolor(guider_ui.screen_2_img_6, lv_color_hex(0x313131), LV_PART_MAIN|LV_STATE_DEFAULT);
            lv_obj_set_style_bg_color(guider_ui.screen_2_btn_3, lv_color_hex(0x5a5a5a), LV_PART_MAIN|LV_STATE_DEFAULT);
        } else {
            screen_2_btn_3_is_click = 1;
            lv_obj_set_style_img_recolor_opa(guider_ui.screen_2_img_6, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
            lv_obj_set_style_img_recolor(guider_ui.screen_2_img_6, lv_color_hex(0x313131), LV_PART_MAIN|LV_STATE_DEFAULT);
            lv_obj_set_style_bg_color(guider_ui.screen_2_btn_3, lv_color_hex(0xff6500), LV_PART_MAIN|LV_STATE_DEFAULT);
        }
        break;
    }
    default:
        break;
    }
}

static void screen_2_btn_2_event_handler (lv_event_t *e)
{
    lv_event_code_t code = lv_event_get_code(e);
    switch (code) {
    case LV_EVENT_CLICKED:
    {
        if(screen_2_btn_2_is_click) {
            screen_2_btn_2_is_click = 0;
            lv_obj_set_style_img_recolor_opa(guider_ui.screen_2_img_4, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
            lv_obj_set_style_img_recolor(guider_ui.screen_2_img_4, lv_color_hex(0x313131), LV_PART_MAIN|LV_STATE_DEFAULT);
            lv_obj_set_style_bg_color(guider_ui.screen_2_btn_2, lv_color_hex(0x5a5a5a), LV_PART_MAIN|LV_STATE_DEFAULT);
        } else {
            screen_2_btn_2_is_click = 1;
            lv_obj_set_style_img_recolor_opa(guider_ui.screen_2_img_4, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
            lv_obj_set_style_img_recolor(guider_ui.screen_2_img_4, lv_color_hex(0x313131), LV_PART_MAIN|LV_STATE_DEFAULT);
            lv_obj_set_style_bg_color(guider_ui.screen_2_btn_2, lv_color_hex(0xff6500), LV_PART_MAIN|LV_STATE_DEFAULT);
        }
        break;
    }
    default:
        break;
    }
}

static void screen_2_btn_1_event_handler (lv_event_t *e)
{
    lv_event_code_t code = lv_event_get_code(e);
    switch (code) {
    case LV_EVENT_CLICKED:
    {
        if(screen_2_btn_1_is_click) {
            screen_2_btn_1_is_click = 0;
            lv_obj_set_style_img_recolor_opa(guider_ui.screen_2_img_5, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
            lv_obj_set_style_img_recolor(guider_ui.screen_2_img_5, lv_color_hex(0x313131), LV_PART_MAIN|LV_STATE_DEFAULT);
            lv_obj_set_style_bg_color(guider_ui.screen_2_btn_1, lv_color_hex(0x5a5a5a), LV_PART_MAIN|LV_STATE_DEFAULT);
        } else {
            screen_2_btn_1_is_click = 1;
            lv_obj_set_style_img_recolor_opa(guider_ui.screen_2_img_5, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
            lv_obj_set_style_img_recolor(guider_ui.screen_2_img_5, lv_color_hex(0x313131), LV_PART_MAIN|LV_STATE_DEFAULT);
            lv_obj_set_style_bg_color(guider_ui.screen_2_btn_1, lv_color_hex(0xff6500), LV_PART_MAIN|LV_STATE_DEFAULT);
        }
        break;
    }
    default:
        break;
    }
}

static void screen_2_cont_4_event_handler (lv_event_t *e)
{
    lv_event_code_t code = lv_event_get_code(e);
    switch (code) {
    case LV_EVENT_LONG_PRESSED:
    {
        lv_obj_set_x(guider_ui.screen_2_cont_3, -120);
        lv_obj_add_flag(guider_ui.screen_2_cont_4, LV_OBJ_FLAG_HIDDEN);
        lv_obj_set_x(guider_ui.screen_2_cont_4, 0);
        break;
    }
    default:
        break;
    }
}

void events_init_screen_2 (lv_ui *ui)
{
    lv_obj_add_event_cb(ui->screen_2, screen_2_event_handler, LV_EVENT_ALL, ui);
    lv_obj_add_event_cb(ui->screen_2_btn_3, screen_2_btn_3_event_handler, LV_EVENT_ALL, ui);
    lv_obj_add_event_cb(ui->screen_2_btn_2, screen_2_btn_2_event_handler, LV_EVENT_ALL, ui);
    lv_obj_add_event_cb(ui->screen_2_btn_1, screen_2_btn_1_event_handler, LV_EVENT_ALL, ui);
    lv_obj_add_event_cb(ui->screen_2_cont_4, screen_2_cont_4_event_handler, LV_EVENT_ALL, ui);
}

static void screen_3_event_handler (lv_event_t *e)
{
    lv_event_code_t code = lv_event_get_code(e);
    switch (code) {
    case LV_EVENT_LONG_PRESSED:
    {
        lv_obj_set_x(guider_ui.screen_3_cont_2, 120);
        lv_obj_clear_flag(guider_ui.screen_3_cont_2, LV_OBJ_FLAG_HIDDEN);
        lv_obj_set_x(guider_ui.screen_3_cont_1, 0);
        break;
    }
    case LV_EVENT_GESTURE:
    {
        lv_dir_t dir = lv_indev_get_gesture_dir(lv_indev_get_act());
        switch(dir) {
        case LV_DIR_LEFT:
        {
            lv_indev_wait_release(lv_indev_get_act());
            ui_load_scr_animation(&guider_ui, &guider_ui.screen_1_home, guider_ui.screen_1_home_del, &guider_ui.screen_3_del, setup_scr_screen_1_home, LV_SCR_LOAD_ANIM_MOVE_RIGHT, 200, 2, true, false);
            screen_index=0;
            break;
        }
        case LV_DIR_TOP:
        {
            lv_indev_wait_release(lv_indev_get_act());
            ui_load_scr_animation(&guider_ui, &guider_ui.under, guider_ui.under_del, &guider_ui.screen_3_del, setup_scr_under, LV_SCR_LOAD_ANIM_OVER_TOP, 200, 2, true, false);
            break;
        }
        case LV_DIR_BOTTOM:
        {
            lv_indev_wait_release(lv_indev_get_act());
            ui_load_scr_animation(&guider_ui, &guider_ui.top_lap, guider_ui.top_lap_del, &guider_ui.screen_3_del, setup_scr_top_lap, LV_SCR_LOAD_ANIM_NONE, 200, 200, true, false);
            break;
        }
        default:
            break;
        }
        break;
    }
    default:
        break;
    }
}

static void screen_3_btn_3_event_handler (lv_event_t *e)
{
    lv_event_code_t code = lv_event_get_code(e);
    switch (code) {
    case LV_EVENT_CLICKED:
    {
        if(screen_3_btn_3_is_click) {
            screen_3_btn_3_is_click = 0;
            lv_obj_set_style_img_recolor_opa(guider_ui.screen_3_img_9, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
            lv_obj_set_style_img_recolor(guider_ui.screen_3_img_9, lv_color_hex(0x313131), LV_PART_MAIN|LV_STATE_DEFAULT);
            lv_obj_set_style_bg_color(guider_ui.screen_3_btn_3, lv_color_hex(0x5a5a5a), LV_PART_MAIN|LV_STATE_DEFAULT);
        } else {
            screen_3_btn_3_is_click = 1;
            lv_obj_set_style_img_recolor_opa(guider_ui.screen_3_img_9, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
            lv_obj_set_style_img_recolor(guider_ui.screen_3_img_9, lv_color_hex(0x313131), LV_PART_MAIN|LV_STATE_DEFAULT);
            lv_obj_set_style_bg_color(guider_ui.screen_3_btn_3, lv_color_hex(0xff6500), LV_PART_MAIN|LV_STATE_DEFAULT);
        }
        break;
    }
    default:
        break;
    }
}

static void screen_3_btn_2_event_handler (lv_event_t *e)
{
    lv_event_code_t code = lv_event_get_code(e);
    switch (code) {
    case LV_EVENT_CLICKED:
    {
        if(screen_3_btn_2_is_click) {
            screen_3_btn_2_is_click = 0;
            lv_obj_set_style_img_recolor_opa(guider_ui.screen_3_img_7, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
            lv_obj_set_style_img_recolor(guider_ui.screen_3_img_7, lv_color_hex(0x313131), LV_PART_MAIN|LV_STATE_DEFAULT);
            lv_obj_set_style_bg_color(guider_ui.screen_3_btn_2, lv_color_hex(0x5a5a5a), LV_PART_MAIN|LV_STATE_DEFAULT);
        } else {
            screen_3_btn_2_is_click = 1;
            lv_obj_set_style_img_recolor_opa(guider_ui.screen_3_img_7, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
            lv_obj_set_style_img_recolor(guider_ui.screen_3_img_7, lv_color_hex(0x313131), LV_PART_MAIN|LV_STATE_DEFAULT);
            lv_obj_set_style_bg_color(guider_ui.screen_3_btn_2, lv_color_hex(0xff6500), LV_PART_MAIN|LV_STATE_DEFAULT);
        }
        break;
    }
    default:
        break;
    }
}

static void screen_3_btn_1_event_handler (lv_event_t *e)
{
    lv_event_code_t code = lv_event_get_code(e);
    switch (code) {
    case LV_EVENT_CLICKED:
    {
        if(screen_3_btn_1_is_click) {
            screen_3_btn_1_is_click = 0;
            lv_obj_set_style_img_recolor_opa(guider_ui.screen_3_img_8, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
            lv_obj_set_style_img_recolor(guider_ui.screen_3_img_8, lv_color_hex(0x313131), LV_PART_MAIN|LV_STATE_DEFAULT);
            lv_obj_set_style_bg_color(guider_ui.screen_3_btn_1, lv_color_hex(0x5a5a5a), LV_PART_MAIN|LV_STATE_DEFAULT);
        } else {
            screen_3_btn_1_is_click = 1;
            lv_obj_set_style_img_recolor_opa(guider_ui.screen_3_img_8, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
            lv_obj_set_style_img_recolor(guider_ui.screen_3_img_8, lv_color_hex(0x313131), LV_PART_MAIN|LV_STATE_DEFAULT);
            lv_obj_set_style_bg_color(guider_ui.screen_3_btn_1, lv_color_hex(0xff6500), LV_PART_MAIN|LV_STATE_DEFAULT);
        }
        break;
    }
    default:
        break;
    }
}

static void screen_3_cont_2_event_handler (lv_event_t *e)
{
    lv_event_code_t code = lv_event_get_code(e);
    switch (code) {
    case LV_EVENT_LONG_PRESSED:
    {
        ui_animation(guider_ui.screen_3_cont_1, 200, 0, lv_obj_get_x(guider_ui.screen_3_cont_1), -120, &lv_anim_path_linear, 1, 0, 0, 0, (lv_anim_exec_xcb_t)lv_obj_set_x, NULL, NULL, NULL);
        ui_animation(guider_ui.screen_3_cont_2, 200, 0, lv_obj_get_x(guider_ui.screen_3_cont_2), 0, &lv_anim_path_linear, 1, 0, 0, 0, (lv_anim_exec_xcb_t)lv_obj_set_x, NULL, NULL, NULL);
        lv_obj_add_flag(guider_ui.screen_3_cont_2, LV_OBJ_FLAG_HIDDEN);
        break;
    }
    default:
        break;
    }
}

void events_init_screen_3 (lv_ui *ui)
{
    lv_obj_add_event_cb(ui->screen_3, screen_3_event_handler, LV_EVENT_ALL, ui);
    lv_obj_add_event_cb(ui->screen_3_btn_3, screen_3_btn_3_event_handler, LV_EVENT_ALL, ui);
    lv_obj_add_event_cb(ui->screen_3_btn_2, screen_3_btn_2_event_handler, LV_EVENT_ALL, ui);
    lv_obj_add_event_cb(ui->screen_3_btn_1, screen_3_btn_1_event_handler, LV_EVENT_ALL, ui);
    lv_obj_add_event_cb(ui->screen_3_cont_2, screen_3_cont_2_event_handler, LV_EVENT_ALL, ui);
}

static void top_lap_event_handler (lv_event_t *e)
{
    lv_event_code_t code = lv_event_get_code(e);
    switch (code) {
    case LV_EVENT_GESTURE:
    {
        lv_dir_t dir = lv_indev_get_gesture_dir(lv_indev_get_act());
        switch(dir) {
        case LV_DIR_TOP:
        {
            lv_indev_wait_release(lv_indev_get_act());
            switch (screen_index)
            {
            case 0:
                lv_indev_wait_release(lv_indev_get_act());
                ui_load_scr_animation(&guider_ui, &guider_ui.screen_1_home, guider_ui.screen_1_home_del, &guider_ui.top_lap_del, setup_scr_screen_1_home, LV_SCR_LOAD_ANIM_MOVE_TOP, 200, 0, true, true);
                break;
            case 1:
                lv_indev_wait_release(lv_indev_get_act());
                ui_load_scr_animation(&guider_ui, &guider_ui.screen_2, guider_ui.screen_2_del, &guider_ui.top_lap_del, setup_scr_screen_2, LV_SCR_LOAD_ANIM_MOVE_TOP, 200, 0, true, true);
                break;
            case 2:
                lv_indev_wait_release(lv_indev_get_act());
                ui_load_scr_animation(&guider_ui, &guider_ui.screen_3, guider_ui.screen_3_del, &guider_ui.top_lap_del, setup_scr_screen_3, LV_SCR_LOAD_ANIM_MOVE_TOP, 200, 0, true, true);
                break;
            default:
                break;
            }
            break;
        }
        default:
            break;
        }
        break;
    }
    default:
        break;
    }
}

void events_init_top_lap (lv_ui *ui)
{
    lv_obj_add_event_cb(ui->top_lap, top_lap_event_handler, LV_EVENT_ALL, ui);
}

static void under_event_handler (lv_event_t *e)
{
    lv_event_code_t code = lv_event_get_code(e);
    switch (code) {
    case LV_EVENT_GESTURE:
    {
        lv_dir_t dir = lv_indev_get_gesture_dir(lv_indev_get_act());
        switch(dir) {
        case LV_DIR_BOTTOM:
        {
            lv_indev_wait_release(lv_indev_get_act());
            switch (screen_index)
            {
            case 0:
                lv_indev_wait_release(lv_indev_get_act());
                ui_load_scr_animation(&guider_ui, &guider_ui.screen_1_home, guider_ui.screen_1_home_del, &guider_ui.under_del, setup_scr_screen_1_home, LV_SCR_LOAD_ANIM_MOVE_BOTTOM, 200, 0, true, true);
                break;
            case 1:
                lv_indev_wait_release(lv_indev_get_act());
                ui_load_scr_animation(&guider_ui, &guider_ui.screen_2, guider_ui.screen_2_del, &guider_ui.under_del, setup_scr_screen_2, LV_SCR_LOAD_ANIM_MOVE_BOTTOM, 200, 0, true, true);
                break;
            case 2:
                lv_indev_wait_release(lv_indev_get_act());
                ui_load_scr_animation(&guider_ui, &guider_ui.screen_3, guider_ui.screen_3_del, &guider_ui.under_del, setup_scr_screen_3, LV_SCR_LOAD_ANIM_MOVE_BOTTOM, 200, 0, true, true);
                break;
            default:
                break;
            }
            break;
        }
        default:
            break;
        }
        break;
    }
    default:
        break;
    }
}

void events_init_under (lv_ui *ui)
{
    lv_obj_add_event_cb(ui->under, under_event_handler, LV_EVENT_ALL, ui);
}

static void List_1_btn_1_event_handler (lv_event_t *e)
{
    lv_event_code_t code = lv_event_get_code(e);
    switch (code) {
    case LV_EVENT_CLICKED:
    {
        switch (screen_index)
        {
        case 0:
            lv_indev_wait_release(lv_indev_get_act());
            ui_load_scr_animation(&guider_ui, &guider_ui.screen_1_home, guider_ui.screen_1_home_del, &guider_ui.List_1_del, setup_scr_screen_1_home, LV_SCR_LOAD_ANIM_MOVE_RIGHT, 200, 0, true, true);
            break;
        case 1:
            lv_indev_wait_release(lv_indev_get_act());
            ui_load_scr_animation(&guider_ui, &guider_ui.screen_2, guider_ui.screen_2_del, &guider_ui.List_1_del, setup_scr_screen_2, LV_SCR_LOAD_ANIM_MOVE_RIGHT, 200, 0, true, true);
            break;
        case 2:
            lv_indev_wait_release(lv_indev_get_act());
            ui_load_scr_animation(&guider_ui, &guider_ui.screen_3, guider_ui.screen_3_del, &guider_ui.List_1_del, setup_scr_screen_3, LV_SCR_LOAD_ANIM_MOVE_RIGHT, 200, 0, true, true);
            break;
        default:
            break;
        }
        break;
    }
    default:
        break;
    }
}

static void List_1_cont_2_event_handler (lv_event_t *e)
{
    lv_event_code_t code = lv_event_get_code(e);
    switch (code) {
    case LV_EVENT_CLICKED:
    {
        ui_load_scr_animation(&guider_ui, &guider_ui.heart, guider_ui.heart_del, &guider_ui.List_1_del, setup_scr_heart, LV_SCR_LOAD_ANIM_NONE, 200, 2, true, false);
        break;
    }
    default:
        break;
    }
}

static void List_1_cont_3_event_handler (lv_event_t *e)
{
    lv_event_code_t code = lv_event_get_code(e);
    switch (code) {
    case LV_EVENT_CLICKED:
    {
        ui_load_scr_animation(&guider_ui, &guider_ui.Map, guider_ui.Map_del, &guider_ui.List_1_del, setup_scr_Map, LV_SCR_LOAD_ANIM_NONE, 200, 2, true, false);
        break;
    }
    default:
        break;
    }
}

static void List_1_cont_4_event_handler (lv_event_t *e)
{
    lv_event_code_t code = lv_event_get_code(e);
    switch (code) {
    case LV_EVENT_CLICKED:
    {
        ui_load_scr_animation(&guider_ui, &guider_ui.NFC, guider_ui.NFC_del, &guider_ui.List_1_del, setup_scr_NFC, LV_SCR_LOAD_ANIM_NONE, 200, 2, true, false);
        break;
    }
    default:
        break;
    }
}

static void List_1_cont_5_event_handler (lv_event_t *e)
{
    lv_event_code_t code = lv_event_get_code(e);
    switch (code) {
    case LV_EVENT_CLICKED:
    {
        ui_load_scr_animation(&guider_ui, &guider_ui.QRCode, guider_ui.QRCode_del, &guider_ui.List_1_del, setup_scr_QRCode, LV_SCR_LOAD_ANIM_NONE, 200, 200, true, false);
        break;
    }
    default:
        break;
    }
}

static void List_1_cont_6_event_handler (lv_event_t *e)
{
    lv_event_code_t code = lv_event_get_code(e);
    switch (code) {
    case LV_EVENT_CLICKED:
    {
        ui_load_scr_animation(&guider_ui, &guider_ui.Sysupdate, guider_ui.Sysupdate_del, &guider_ui.List_1_del, setup_scr_Sysupdate, LV_SCR_LOAD_ANIM_NONE, 200, 2, true, false);
        break;
    }
    default:
        break;
    }
}

static void List_1_cont_8_event_handler (lv_event_t *e)
{
    lv_event_code_t code = lv_event_get_code(e);
    switch (code) {
    case LV_EVENT_CLICKED:
    {
        ui_load_scr_animation(&guider_ui, &guider_ui.Set, guider_ui.Set_del, &guider_ui.List_1_del, setup_scr_Set, LV_SCR_LOAD_ANIM_NONE, 200, 2, true, false);
        break;
    }
    default:
        break;
    }
}

static void List_1_cont_7_event_handler (lv_event_t *e)
{
    lv_event_code_t code = lv_event_get_code(e);
    switch (code) {
    case LV_EVENT_CLICKED:
    {
        break;
    }
    default:
        break;
    }
}

void events_init_List_1 (lv_ui *ui)
{
    lv_obj_add_event_cb(ui->List_1_btn_1, List_1_btn_1_event_handler, LV_EVENT_ALL, ui);
    lv_obj_add_event_cb(ui->List_1_cont_2, List_1_cont_2_event_handler, LV_EVENT_ALL, ui);
    lv_obj_add_event_cb(ui->List_1_cont_3, List_1_cont_3_event_handler, LV_EVENT_ALL, ui);
    lv_obj_add_event_cb(ui->List_1_cont_4, List_1_cont_4_event_handler, LV_EVENT_ALL, ui);
    lv_obj_add_event_cb(ui->List_1_cont_5, List_1_cont_5_event_handler, LV_EVENT_ALL, ui);
    lv_obj_add_event_cb(ui->List_1_cont_6, List_1_cont_6_event_handler, LV_EVENT_ALL, ui);
    lv_obj_add_event_cb(ui->List_1_cont_8, List_1_cont_8_event_handler, LV_EVENT_ALL, ui);
    lv_obj_add_event_cb(ui->List_1_cont_7, List_1_cont_7_event_handler, LV_EVENT_ALL, ui);
}


void events_init(lv_ui *ui)
{

}
