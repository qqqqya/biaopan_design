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
static lv_obj_t* list_1_obj[8];

static int16_t move_distace;
static uint8_t current_moving_index = 0;
lv_anim_t move_anim;
static lv_obj_t* list_1_obj[8];
static bool is_List_visible_1;
static bool is_List_visible_2;
static bool is_List_visible_3;
static bool is_List_visible_4;
static bool is_List_visible_5;
static bool is_List_visible_6;
static bool is_List_visible_7;
static bool is_List_visible_btn;

static uint8_t get_last_visible_index(void) {
    bool *visible_array[7] = {&is_List_visible_1, &is_List_visible_2, &is_List_visible_3,
                              &is_List_visible_4, &is_List_visible_5, &is_List_visible_6, &is_List_visible_7
                             };

    for(int8_t i = 6; i >= 0; i--) {
        if(visible_array[i]) {
            return i;
        }
    }

    return 0;  // 如果都不可见，返回0
}

// 向上移动其他项目的动画
static void move_items_up(void) {
    bool *visible_array[7] = {&is_List_visible_1, &is_List_visible_2, &is_List_visible_3,
                              &is_List_visible_4, &is_List_visible_5, &is_List_visible_6, &is_List_visible_7
                             };


    for(uint8_t i = current_moving_index + 1; i < 7; i++) {
        if(visible_array[i]) {
            lv_anim_t a;
            lv_anim_init(&a);
            lv_anim_set_var(&a, list_1_obj[i]);
            lv_anim_set_exec_cb(&a, (lv_anim_exec_xcb_t)lv_obj_set_y);
            lv_anim_set_time(&a, 500);
            lv_anim_set_values(&a, i * 90, (i-1) * 90);
            lv_anim_set_path_cb(&a, lv_anim_path_ease_out);
            lv_anim_start(&a);
        }
    }

    // 获取最后一个可见项的索引
    uint8_t last_visible = get_last_visible_index();

    // 显示添加按钮
    lv_obj_clear_flag(list_1_obj[7], LV_OBJ_FLAG_HIDDEN);
    is_List_visible_btn = true;

    // 移动添加按钮
    lv_anim_t a;
    lv_anim_init(&a);
    lv_anim_set_var(&a, list_1_obj[7]);
    lv_anim_set_exec_cb(&a, (lv_anim_exec_xcb_t)lv_obj_set_y);
    lv_anim_set_time(&a, 500);
    lv_anim_set_values(&a, (last_visible + 1) * 90, (last_visible ) * 90);
    lv_anim_set_path_cb(&a, lv_anim_path_ease_out);
    lv_anim_start(&a);
}

void clear_flage(lv_anim_t *a) {
    lv_obj_t* obj=a->var;
    lv_obj_add_flag(obj,LV_OBJ_FLAG_CLICKABLE);
// 设置该项为不可见
    if(list_1_obj[0] == obj) {
        is_List_visible_1 = false;
    }
    else if(list_1_obj[1] == obj)
    {
        is_List_visible_2 = false;
    }
    else if(list_1_obj[2] == obj) {
        is_List_visible_3 = false;
    }
    else if(list_1_obj[3] == obj) {
        is_List_visible_4 = false;
    }
    else if(list_1_obj[4] == obj) {
        is_List_visible_5 = false;
    }
    else if(list_1_obj[5] == obj) {
        is_List_visible_6 = false;
    }
    else if(list_1_obj[6] == obj) {
        is_List_visible_7 = false;
    }

//  move_items_up();
}
// 如果所有项都已显示,隐藏添加按钮
bool all_visible = true;

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

static void List_1_event_handler (lv_event_t *e)
{
    lv_event_code_t code = lv_event_get_code(e);
    switch (code) {
    case LV_EVENT_SCREEN_LOADED:
    {
        list_1_obj[0]=guider_ui.List_1_cont_2;
        list_1_obj[1]=guider_ui.List_1_cont_3;
        list_1_obj[2]=guider_ui.List_1_cont_4;
        list_1_obj[3]=guider_ui.List_1_cont_5;
        list_1_obj[4]=guider_ui.List_1_cont_6;
        list_1_obj[5]=guider_ui.List_1_cont_7;
        list_1_obj[6]=guider_ui.List_1_cont_8;
        list_1_obj[7]=guider_ui.List_1_btn_2;
        break;
    }
    default:
        break;
    }
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
    case LV_EVENT_PRESSING:
    {
        lv_obj_t* obj = lv_event_get_target(e); //获取事件产生的对象
        lv_indev_t* indev = lv_indev_get_act();  //获取活动界面输入设备
        lv_point_t vect;
        lv_indev_get_vect(indev, &vect); //获取vect point
        lv_coord_t x = lv_obj_get_x(obj) + vect.x; //计算x
        move_distace=x;
        // 获取当前移动项的索引
        for(uint8_t i = 0; i < 7; i++) {
            if(list_1_obj[i] == obj) {
                current_moving_index = i;
                break;
            }
        }
        if(move_distace<100&&move_distace>0) {
            lv_obj_set_x(obj, x); //移动对象到x,y
        }
        if(move_distace>100) {
            lv_obj_clear_flag(obj,LV_OBJ_FLAG_CLICKABLE);
            lv_anim_init(&move_anim);
            lv_anim_set_var(&move_anim, obj);                      // 要移动的对象
            lv_anim_set_exec_cb(&move_anim, (lv_anim_exec_xcb_t)lv_obj_set_x); // 修改x坐标
            lv_anim_set_time(&move_anim,(lv_coord_t)1500);                      // 动画持续时间500ms
            lv_anim_set_values(&move_anim,lv_obj_get_x(obj), 240); // 从当前位置到240
            lv_anim_set_path_cb(&move_anim, lv_anim_path_overshoot); // 使用overshoot路径
            lv_anim_set_ready_cb(&move_anim,(lv_anim_ready_cb_t)clear_flage);
            lv_anim_start(&move_anim);
        }


        //     lv_obj_t* obj = lv_event_get_target(e); //获取事件产生的对象
        //     lv_indev_t* indev = lv_indev_get_act();  //获取活动界面输入设备
        //     lv_point_t vect;
        //     lv_indev_get_vect(indev, &vect); //获取vect point
        //     lv_coord_t x = lv_obj_get_x(obj) + vect.x; //计算x
        //     move_distace=x;
        //     // 获取当前移动项的索引
        //     for(uint8_t i = 0; i < 7; i++) {
        //         if(list_1_obj[i] == obj) {
        //             current_moving_index = i;
        //             break;
        //         }
        //     }
        //     if(move_distace<100&&move_distace>0){
        //          lv_obj_set_x(obj, x); //移动对象到x,y
        //     }
        //     if(move_distace>100){
        //     lv_obj_clear_flag(obj,LV_OBJ_FLAG_CLICKABLE);
        //     lv_anim_init(&move_anim);
        //     lv_anim_set_var(&move_anim, obj);                      // 要移动的对象
        //     lv_anim_set_exec_cb(&move_anim, (lv_anim_exec_xcb_t)lv_obj_set_x); // 修改x坐标
        //     lv_anim_set_time(&move_anim,(lv_coord_t)1500);                      // 动画持续时间500ms
        //     lv_anim_set_values(&move_anim,lv_obj_get_x(obj), 240); // 从当前位置到240
        //     lv_anim_set_path_cb(&move_anim, lv_anim_path_overshoot); // 使用overshoot路径
        //     lv_anim_set_ready_cb(&move_anim,(lv_anim_ready_cb_t)clear_flage);
        //     lv_anim_start(&move_anim);
        //  }
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
    case LV_EVENT_PRESSING:
    {
        lv_obj_t* obj = lv_event_get_target(e); //获取事件产生的对象
        lv_indev_t* indev = lv_indev_get_act();  //获取活动界面输入设备
        lv_point_t vect;
        lv_indev_get_vect(indev, &vect); //获取vect point
        lv_coord_t x = lv_obj_get_x(obj) + vect.x; //计算x
        move_distace=x;
        // 获取当前移动项的索引
        for(uint8_t i = 0; i < 7; i++) {
            if(list_1_obj[i] == obj) {
                current_moving_index = i;
                break;
            }
        }
        if(move_distace<100&&move_distace>0) {
            lv_obj_set_x(obj, x); //移动对象到x,y
        }
        if(move_distace>100) {
            lv_obj_clear_flag(obj,LV_OBJ_FLAG_CLICKABLE);
            lv_anim_init(&move_anim);
            lv_anim_set_var(&move_anim, obj);                      // 要移动的对象
            lv_anim_set_exec_cb(&move_anim, (lv_anim_exec_xcb_t)lv_obj_set_x); // 修改x坐标
            lv_anim_set_time(&move_anim,(lv_coord_t)1500);                      // 动画持续时间500ms
            lv_anim_set_values(&move_anim,lv_obj_get_x(obj), 240); // 从当前位置到240
            lv_anim_set_path_cb(&move_anim, lv_anim_path_overshoot); // 使用overshoot路径
            lv_anim_set_ready_cb(&move_anim,(lv_anim_ready_cb_t)clear_flage);
            lv_anim_start(&move_anim);
        }
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
    case LV_EVENT_PRESSING:
    {
        lv_obj_t* obj = lv_event_get_target(e); //获取事件产生的对象
        lv_indev_t* indev = lv_indev_get_act();  //获取活动界面输入设备
        lv_point_t vect;
        lv_indev_get_vect(indev, &vect); //获取vect point
        lv_coord_t x = lv_obj_get_x(obj) + vect.x; //计算x
        move_distace=x;
        // 获取当前移动项的索引
        for(uint8_t i = 0; i < 7; i++) {
            if(list_1_obj[i] == obj) {
                current_moving_index = i;
                break;
            }
        }
        if(move_distace<100&&move_distace>0) {
            lv_obj_set_x(obj, x); //移动对象到x,y
        }
        if(move_distace>100) {
            lv_obj_clear_flag(obj,LV_OBJ_FLAG_CLICKABLE);
            lv_anim_init(&move_anim);
            lv_anim_set_var(&move_anim, obj);                      // 要移动的对象
            lv_anim_set_exec_cb(&move_anim, (lv_anim_exec_xcb_t)lv_obj_set_x); // 修改x坐标
            lv_anim_set_time(&move_anim,(lv_coord_t)1500);                      // 动画持续时间500ms
            lv_anim_set_values(&move_anim,lv_obj_get_x(obj), 240); // 从当前位置到240
            lv_anim_set_path_cb(&move_anim, lv_anim_path_overshoot); // 使用overshoot路径
            lv_anim_set_ready_cb(&move_anim,(lv_anim_ready_cb_t)clear_flage);
            lv_anim_start(&move_anim);
        }
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
    case LV_EVENT_PRESSING:
    {
        lv_obj_t* obj = lv_event_get_target(e); //获取事件产生的对象
        lv_indev_t* indev = lv_indev_get_act();  //获取活动界面输入设备
        lv_point_t vect;
        lv_indev_get_vect(indev, &vect); //获取vect point
        lv_coord_t x = lv_obj_get_x(obj) + vect.x; //计算x
        move_distace=x;
        // 获取当前移动项的索引
        for(uint8_t i = 0; i < 7; i++) {
            if(list_1_obj[i] == obj) {
                current_moving_index = i;
                break;
            }
        }
        if(move_distace<100&&move_distace>0) {
            lv_obj_set_x(obj, x); //移动对象到x,y
        }
        if(move_distace>100) {
            lv_obj_clear_flag(obj,LV_OBJ_FLAG_CLICKABLE);
            lv_anim_init(&move_anim);
            lv_anim_set_var(&move_anim, obj);                      // 要移动的对象
            lv_anim_set_exec_cb(&move_anim, (lv_anim_exec_xcb_t)lv_obj_set_x); // 修改x坐标
            lv_anim_set_time(&move_anim,(lv_coord_t)1500);                      // 动画持续时间500ms
            lv_anim_set_values(&move_anim,lv_obj_get_x(obj), 240); // 从当前位置到240
            lv_anim_set_path_cb(&move_anim, lv_anim_path_overshoot); // 使用overshoot路径
            lv_anim_set_ready_cb(&move_anim,(lv_anim_ready_cb_t)clear_flage);
            lv_anim_start(&move_anim);
        }
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
    case LV_EVENT_PRESSING:
    {
        lv_obj_t* obj = lv_event_get_target(e); //获取事件产生的对象
        lv_indev_t* indev = lv_indev_get_act();  //获取活动界面输入设备
        lv_point_t vect;
        lv_indev_get_vect(indev, &vect); //获取vect point
        lv_coord_t x = lv_obj_get_x(obj) + vect.x; //计算x
        move_distace=x;
        // 获取当前移动项的索引
        for(uint8_t i = 0; i < 7; i++) {
            if(list_1_obj[i] == obj) {
                current_moving_index = i;
                break;
            }
        }
        if(move_distace<100&&move_distace>0) {
            lv_obj_set_x(obj, x); //移动对象到x,y
        }
        if(move_distace>100) {
            lv_obj_clear_flag(obj,LV_OBJ_FLAG_CLICKABLE);
            lv_anim_init(&move_anim);
            lv_anim_set_var(&move_anim, obj);                      // 要移动的对象
            lv_anim_set_exec_cb(&move_anim, (lv_anim_exec_xcb_t)lv_obj_set_x); // 修改x坐标
            lv_anim_set_time(&move_anim,(lv_coord_t)1500);                      // 动画持续时间500ms
            lv_anim_set_values(&move_anim,lv_obj_get_x(obj), 240); // 从当前位置到240
            lv_anim_set_path_cb(&move_anim, lv_anim_path_overshoot); // 使用overshoot路径
            lv_anim_set_ready_cb(&move_anim,(lv_anim_ready_cb_t)clear_flage);
            lv_anim_start(&move_anim);
        }
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
        ui_load_scr_animation(&guider_ui, &guider_ui.Set, guider_ui.Set_del, &guider_ui.List_1_del, setup_scr_Set, LV_SCR_LOAD_ANIM_NONE, 200, 2, true, false);
        break;
    }
    case LV_EVENT_PRESSING:
    {
        lv_obj_t* obj = lv_event_get_target(e); //获取事件产生的对象
        lv_indev_t* indev = lv_indev_get_act();  //获取活动界面输入设备
        lv_point_t vect;
        lv_indev_get_vect(indev, &vect); //获取vect point
        lv_coord_t x = lv_obj_get_x(obj) + vect.x; //计算x
        move_distace=x;
        // 获取当前移动项的索引
        for(uint8_t i = 0; i < 7; i++) {
            if(list_1_obj[i] == obj) {
                current_moving_index = i;
                break;
            }
        }
        if(move_distace<100&&move_distace>0) {
            lv_obj_set_x(obj, x); //移动对象到x,y
        }
        if(move_distace>100) {
            lv_obj_clear_flag(obj,LV_OBJ_FLAG_CLICKABLE);
            lv_anim_init(&move_anim);
            lv_anim_set_var(&move_anim, obj);                      // 要移动的对象
            lv_anim_set_exec_cb(&move_anim, (lv_anim_exec_xcb_t)lv_obj_set_x); // 修改x坐标
            lv_anim_set_time(&move_anim,(lv_coord_t)1500);                      // 动画持续时间500ms
            lv_anim_set_values(&move_anim,lv_obj_get_x(obj), 240); // 从当前位置到240
            lv_anim_set_path_cb(&move_anim, lv_anim_path_overshoot); // 使用overshoot路径
            lv_anim_set_ready_cb(&move_anim,(lv_anim_ready_cb_t)clear_flage);
            lv_anim_start(&move_anim);
        }
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
        ui_load_scr_animation(&guider_ui, &guider_ui.Set, guider_ui.Set_del, &guider_ui.List_1_del, setup_scr_Set, LV_SCR_LOAD_ANIM_NONE, 200, 2, true, true);
        break;
    }
    case LV_EVENT_PRESSING:
    {
        lv_obj_t* obj = lv_event_get_target(e); //获取事件产生的对象
        lv_indev_t* indev = lv_indev_get_act();  //获取活动界面输入设备
        lv_point_t vect;
        lv_indev_get_vect(indev, &vect); //获取vect point
        lv_coord_t x = lv_obj_get_x(obj) + vect.x; //计算x
        move_distace=x;
        // 获取当前移动项的索引
        for(uint8_t i = 0; i < 7; i++) {
            if(list_1_obj[i] == obj) {
                current_moving_index = i;
                break;
            }
        }
        if(move_distace<100&&move_distace>0) {
            lv_obj_set_x(obj, x); //移动对象到x,y
        }
        if(move_distace>100) {
            lv_obj_clear_flag(obj,LV_OBJ_FLAG_CLICKABLE);
            lv_anim_init(&move_anim);
            lv_anim_set_var(&move_anim, obj);                      // 要移动的对象
            lv_anim_set_exec_cb(&move_anim, (lv_anim_exec_xcb_t)lv_obj_set_x); // 修改x坐标
            lv_anim_set_time(&move_anim,(lv_coord_t)1500);                      // 动画持续时间500ms
            lv_anim_set_values(&move_anim,lv_obj_get_x(obj), 240); // 从当前位置到240
            lv_anim_set_path_cb(&move_anim, lv_anim_path_overshoot); // 使用overshoot路径
            lv_anim_set_ready_cb(&move_anim,(lv_anim_ready_cb_t)clear_flage);
            lv_anim_start(&move_anim);
        }
        break;
    }
    default:
        break;
    }
}

static void List_1_btn_2_event_handler (lv_event_t *e)
{
    lv_event_code_t code = lv_event_get_code(e);
    switch (code) {
    case LV_EVENT_CLICKED:
    {
        bool* visible_array[7] = {&is_List_visible_1, &is_List_visible_2, &is_List_visible_3,
                                  &is_List_visible_4, &is_List_visible_5, &is_List_visible_6, &is_List_visible_7
                                 };

        // 查找第一个被移除的项
        for(uint8_t i = 0; i < 7; i++) {
            if(!(*visible_array[i])) {
                // 重新显示该项
                *visible_array[i] = true;
                lv_obj_clear_flag(list_1_obj[i], LV_OBJ_FLAG_HIDDEN);

                // 设置初始位置并启动动画
                // lv_obj_set_y(list_1_obj[i], 610);
                lv_anim_t a;
                lv_anim_init(&a);
                lv_anim_set_var(&a, list_1_obj[i]);
                lv_anim_set_exec_cb(&a, (lv_anim_exec_xcb_t)lv_obj_set_x);
                lv_anim_set_time(&a, 500);
                lv_anim_set_values(&a, lv_obj_get_x(list_1_obj[i]), 0);
                lv_anim_set_path_cb(&a, lv_anim_path_overshoot);
                lv_anim_start(&a);

                for(uint8_t j = 0; j < 7; j++) {
                    if(!(*visible_array[j])) {
                        all_visible = false;
                        break;
                    }
                }
                if(all_visible) {
                    lv_obj_add_flag(list_1_obj[7], LV_OBJ_FLAG_HIDDEN);
                    is_List_visible_btn = false;
                }

            }
        }
        break;
    }
    default:
        break;
    }
}

void events_init_List_1 (lv_ui *ui)
{
    lv_obj_add_event_cb(ui->List_1, List_1_event_handler, LV_EVENT_ALL, ui);
    lv_obj_add_event_cb(ui->List_1_btn_1, List_1_btn_1_event_handler, LV_EVENT_ALL, ui);
    lv_obj_add_event_cb(ui->List_1_cont_2, List_1_cont_2_event_handler, LV_EVENT_ALL, ui);
    lv_obj_add_event_cb(ui->List_1_cont_3, List_1_cont_3_event_handler, LV_EVENT_ALL, ui);
    lv_obj_add_event_cb(ui->List_1_cont_4, List_1_cont_4_event_handler, LV_EVENT_ALL, ui);
    lv_obj_add_event_cb(ui->List_1_cont_5, List_1_cont_5_event_handler, LV_EVENT_ALL, ui);
    lv_obj_add_event_cb(ui->List_1_cont_6, List_1_cont_6_event_handler, LV_EVENT_ALL, ui);
    lv_obj_add_event_cb(ui->List_1_cont_7, List_1_cont_7_event_handler, LV_EVENT_ALL, ui);
    lv_obj_add_event_cb(ui->List_1_cont_8, List_1_cont_8_event_handler, LV_EVENT_ALL, ui);
    lv_obj_add_event_cb(ui->List_1_btn_2, List_1_btn_2_event_handler, LV_EVENT_ALL, ui);
}

static void Set_cont_1_event_handler (lv_event_t *e)
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

void events_init_Set (lv_ui *ui)
{
    lv_obj_add_event_cb(ui->Set_cont_1, Set_cont_1_event_handler, LV_EVENT_ALL, ui);
}

static void heart_btn_1_event_handler (lv_event_t *e)
{
    lv_event_code_t code = lv_event_get_code(e);
    switch (code) {
    case LV_EVENT_CLICKED:
    {
        ui_load_scr_animation(&guider_ui, &guider_ui.List_1, guider_ui.List_1_del, &guider_ui.heart_del, setup_scr_List_1, LV_SCR_LOAD_ANIM_NONE, 200, 2, true, true);
        break;
    }
    default:
        break;
    }
}

void events_init_heart (lv_ui *ui)
{
    lv_obj_add_event_cb(ui->heart_btn_1, heart_btn_1_event_handler, LV_EVENT_ALL, ui);
}


void events_init(lv_ui *ui)
{

}
