/*
* Copyright 2026 NXP
* NXP Proprietary. This software is owned or controlled by NXP and may only be used strictly in
* accordance with the applicable license terms. By expressly accepting such terms or by downloading, installing,
* activating and/or otherwise using the software, you are agreeing that you have read, and that you agree to
* comply with and are bound by, such license terms.  If you do not agree to be bound by the applicable license
* terms, then you may not retain, install, activate or otherwise use the software.
*/

#ifndef GUI_GUIDER_H
#define GUI_GUIDER_H
#ifdef __cplusplus
extern "C" {
#endif

#include "lvgl.h"

typedef struct
{
  
	lv_obj_t *screen_1_home;
	bool screen_1_home_del;
	lv_obj_t *screen_1_home_analog_clock_1;
	lv_obj_t *screen_1_home_img_2;
	lv_obj_t *screen_1_home_img_3;
	lv_obj_t *screen_1_home_img_4;
	lv_obj_t *screen_1_home_img_5;
	lv_obj_t *screen_1_home_cont_slide;
	lv_obj_t *screen_1_home_btn_3;
	lv_obj_t *screen_1_home_btn_3_label;
	lv_obj_t *screen_1_home_btn_2;
	lv_obj_t *screen_1_home_btn_2_label;
	lv_obj_t *screen_1_home_btn_1;
	lv_obj_t *screen_1_home_btn_1_label;
	lv_obj_t *screen_1_home_img_8;
	lv_obj_t *screen_1_home_img_10;
	lv_obj_t *screen_1_home_img_9;
	lv_obj_t *screen_1_home_img_7;
	lv_obj_t *screen_1_home_img_6;
	lv_obj_t *screen_1_home_label_1;
	lv_obj_t *screen_1_home_label_2;
	lv_obj_t *screen_1_home_cont_shadow;
	lv_obj_t *screen_2;
	bool screen_2_del;
	lv_obj_t *screen_2_img_1;
	lv_obj_t *screen_2_digital_clock_1;
	lv_obj_t *screen_2_datetext_1;
	lv_obj_t *screen_2_cont_3;
	lv_obj_t *screen_2_btn_3;
	lv_obj_t *screen_2_btn_3_label;
	lv_obj_t *screen_2_btn_2;
	lv_obj_t *screen_2_btn_2_label;
	lv_obj_t *screen_2_btn_1;
	lv_obj_t *screen_2_btn_1_label;
	lv_obj_t *screen_2_img_6;
	lv_obj_t *screen_2_img_5;
	lv_obj_t *screen_2_img_4;
	lv_obj_t *screen_2_img_3;
	lv_obj_t *screen_2_img_2;
	lv_obj_t *screen_2_label_2;
	lv_obj_t *screen_2_label_1;
	lv_obj_t *screen_2_cont_4;
	lv_obj_t *screen_3;
	bool screen_3_del;
	lv_obj_t *screen_3_label_2;
	lv_obj_t *screen_3_label_3;
	lv_obj_t *screen_3_img_2;
	lv_obj_t *screen_3_img_3;
	lv_obj_t *screen_3_img_4;
	lv_obj_t *screen_3_arc_2;
	lv_obj_t *screen_3_arc_4;
	lv_obj_t *screen_3_arc_5;
	lv_obj_t *screen_3_label_1;
	lv_obj_t *screen_3_label_4;
	lv_obj_t *screen_3_label_5;
	lv_obj_t *screen_3_label_6;
	lv_obj_t *screen_3_cont_1;
	lv_obj_t *screen_3_btn_3;
	lv_obj_t *screen_3_btn_3_label;
	lv_obj_t *screen_3_btn_2;
	lv_obj_t *screen_3_btn_2_label;
	lv_obj_t *screen_3_btn_1;
	lv_obj_t *screen_3_btn_1_label;
	lv_obj_t *screen_3_img_9;
	lv_obj_t *screen_3_img_8;
	lv_obj_t *screen_3_img_7;
	lv_obj_t *screen_3_img_6;
	lv_obj_t *screen_3_img_5;
	lv_obj_t *screen_3_label_8;
	lv_obj_t *screen_3_label_7;
	lv_obj_t *screen_3_cont_2;
	lv_obj_t *top_lap;
	bool top_lap_del;
	lv_obj_t *top_lap_cont_4;
	lv_obj_t *top_lap_cont_5;
	lv_obj_t *top_lap_cont_2;
	lv_obj_t *top_lap_slider_1;
	lv_obj_t *top_lap_cont_3;
	lv_obj_t *top_lap_img_1;
	lv_obj_t *under;
	bool under_del;
	lv_obj_t *under_cont_1;
	lv_obj_t *under_cont_2;
	lv_obj_t *under_img_1;
	lv_obj_t *List_1;
	bool List_1_del;
	lv_obj_t *List_1_btn_1;
	lv_obj_t *List_1_btn_1_label;
	lv_obj_t *List_1_cont_1;
	lv_obj_t *List_1_cont_2;
	lv_obj_t *List_1_img_1;
	lv_obj_t *List_1_label_2;
	lv_obj_t *List_1_cont_3;
	lv_obj_t *List_1_img_2;
	lv_obj_t *List_1_label_1;
	lv_obj_t *List_1_cont_4;
	lv_obj_t *List_1_img_3;
	lv_obj_t *List_1_label_3;
	lv_obj_t *List_1_cont_5;
	lv_obj_t *List_1_img_4;
	lv_obj_t *List_1_label_4;
	lv_obj_t *List_1_cont_6;
	lv_obj_t *List_1_img_5;
	lv_obj_t *List_1_label_5;
	lv_obj_t *List_1_cont_7;
	lv_obj_t *List_1_img_7;
	lv_obj_t *List_1_label_7;
	lv_obj_t *List_1_cont_8;
	lv_obj_t *List_1_img_8;
	lv_obj_t *List_1_label_8;
	lv_obj_t *List_1_btn_2;
	lv_obj_t *List_1_btn_2_label;
	lv_obj_t *List_2;
	bool List_2_del;
	lv_obj_t *List_2_btn_1;
	lv_obj_t *List_2_btn_1_label;
	lv_obj_t *List_2_cont_1;
	lv_obj_t *List_2_cont_2;
	lv_obj_t *List_2_img_13;
	lv_obj_t *List_2_label_13;
	lv_obj_t *List_2_cont_3;
	lv_obj_t *List_2_img_12;
	lv_obj_t *List_2_label_12;
	lv_obj_t *List_2_cont_4;
	lv_obj_t *List_2_img_11;
	lv_obj_t *List_2_label_11;
	lv_obj_t *List_2_cont_5;
	lv_obj_t *List_2_img_10;
	lv_obj_t *List_2_label_10;
	lv_obj_t *List_2_cont_6;
	lv_obj_t *List_2_img_9;
	lv_obj_t *List_2_label_9;
	lv_obj_t *List_2_cont_7;
	lv_obj_t *List_2_img_8;
	lv_obj_t *List_2_label_8;
	lv_obj_t *List_2_cont_8;
	lv_obj_t *List_2_img_15;
	lv_obj_t *List_2_label_15;
	lv_obj_t *List_3;
	bool List_3_del;
	lv_obj_t *List_3_btn_1;
	lv_obj_t *List_3_btn_1_label;
	lv_obj_t *List_3_cont_1;
	lv_obj_t *List_3_img_1;
	lv_obj_t *List_3_img_2;
	lv_obj_t *List_3_img_3;
	lv_obj_t *List_3_img_4;
	lv_obj_t *List_3_img_5;
	lv_obj_t *List_3_img_6;
	lv_obj_t *List_3_img_7;
	lv_obj_t *List_3_btn_2;
	lv_obj_t *List_3_btn_2_label;
	lv_obj_t *Set;
	bool Set_del;
	lv_obj_t *Set_label_1;
	lv_obj_t *Set_cont_1;
	lv_obj_t *Set_label_2;
	lv_obj_t *Set_btn_1;
	lv_obj_t *Set_btn_1_label;
	lv_obj_t *Set_cont_2;
	lv_obj_t *Set_label_3;
	lv_obj_t *Set_cont_3;
	lv_obj_t *Set_label_4;
	lv_obj_t *Heart;
	bool Heart_del;
	lv_obj_t *Heart_label_1;
	lv_obj_t *Heart_btn_1;
	lv_obj_t *Heart_btn_1_label;
	lv_obj_t *NFC;
	bool NFC_del;
	lv_obj_t *NFC_Label1;
	lv_obj_t *NFC_btn_1;
	lv_obj_t *NFC_btn_1_label;
	lv_obj_t *Map;
	bool Map_del;
	lv_obj_t *Map_label_1;
	lv_obj_t *Map_btn_1;
	lv_obj_t *Map_btn_1_label;
	lv_obj_t *QRcode;
	bool QRcode_del;
	lv_obj_t *QRcode_label_1;
	lv_obj_t *QRcode_btn_1;
	lv_obj_t *QRcode_btn_1_label;
	lv_obj_t *Systeamupdate;
	bool Systeamupdate_del;
	lv_obj_t *Systeamupdate_label_1;
	lv_obj_t *Systeamupdate_btn_1;
	lv_obj_t *Systeamupdate_btn_1_label;
}lv_ui;

typedef void (*ui_setup_scr_t)(lv_ui * ui);

void ui_init_style(lv_style_t * style);

void ui_load_scr_animation(lv_ui *ui, lv_obj_t ** new_scr, bool new_scr_del, bool * old_scr_del, ui_setup_scr_t setup_scr,
                           lv_scr_load_anim_t anim_type, uint32_t time, uint32_t delay, bool is_clean, bool auto_del);

void ui_animation(void * var, int32_t duration, int32_t delay, int32_t start_value, int32_t end_value, lv_anim_path_cb_t path_cb,
                       uint16_t repeat_cnt, uint32_t repeat_delay, uint32_t playback_time, uint32_t playback_delay,
                       lv_anim_exec_xcb_t exec_cb, lv_anim_start_cb_t start_cb, lv_anim_ready_cb_t ready_cb, lv_anim_deleted_cb_t deleted_cb);


void init_scr_del_flag(lv_ui *ui);

void setup_ui(lv_ui *ui);

void init_keyboard(lv_ui *ui);

extern lv_ui guider_ui;


void setup_scr_screen_1_home(lv_ui *ui);
void setup_scr_screen_2(lv_ui *ui);
void setup_scr_screen_3(lv_ui *ui);
void setup_scr_top_lap(lv_ui *ui);
void setup_scr_under(lv_ui *ui);
void setup_scr_List_1(lv_ui *ui);
void setup_scr_List_2(lv_ui *ui);
void setup_scr_List_3(lv_ui *ui);
void setup_scr_Set(lv_ui *ui);
void setup_scr_Heart(lv_ui *ui);
void setup_scr_NFC(lv_ui *ui);
void setup_scr_Map(lv_ui *ui);
void setup_scr_QRcode(lv_ui *ui);
void setup_scr_Systeamupdate(lv_ui *ui);

LV_IMG_DECLARE(_biaopan1_200x200);
LV_IMG_DECLARE(_Ellipse_alpha_26x30);
LV_IMG_DECLARE(_watchdight3_alpha_61x68);
LV_IMG_DECLARE(_watchdight2_alpha_51x57);
LV_IMG_DECLARE(_watchdight1_alpha_56x59);
LV_IMG_DECLARE(_zhengdong_0_alpha_30x30);
LV_IMG_DECLARE(_mianti_0_alpha_30x30);
LV_IMG_DECLARE(_BT32_alpha_30x30);
LV_IMG_DECLARE(_copesss_alpha_30x30);
LV_IMG_DECLARE(_weater32x32_alpha_30x30);
LV_IMG_DECLARE(_MDLBG_alpha_179x220);
LV_IMG_DECLARE(_zhengdong_0_alpha_30x30);
LV_IMG_DECLARE(_mianti_0_alpha_30x30);
LV_IMG_DECLARE(_BT32_alpha_30x30);
LV_IMG_DECLARE(_copesss_alpha_30x30);
LV_IMG_DECLARE(_weater32x32_alpha_30x30);
LV_IMG_DECLARE(_foot16x16_alpha_20x20);
LV_IMG_DECLARE(_KLL16x16_alpha_20x20);
LV_IMG_DECLARE(_heart16x16_alpha_20x20);
LV_IMG_DECLARE(_zhengdong_0_alpha_30x30);
LV_IMG_DECLARE(_mianti_0_alpha_30x30);
LV_IMG_DECLARE(_BT32_alpha_30x30);
LV_IMG_DECLARE(_copesss_alpha_30x30);
LV_IMG_DECLARE(_weater32x32_alpha_30x30);

LV_IMG_DECLARE(_taiwan_50x50);

LV_IMG_DECLARE(_nfc_50x50);

LV_IMG_DECLARE(_BT32_50x50);

LV_IMG_DECLARE(_liangdu_47x47);

LV_IMG_DECLARE(_location_50x50);
LV_IMG_DECLARE(_power_over_alpha_50x50);

LV_IMG_DECLARE(_nfc_50x50);
LV_IMG_DECLARE(_ZNZBG_alpha_100x100);
LV_IMG_DECLARE(_heart32x32_alpha_30x30);
LV_IMG_DECLARE(_location32x32_alpha_30x30);
LV_IMG_DECLARE(_NFC32x32_alpha_30x30);
LV_IMG_DECLARE(_qrcode32x32_alpha_30x30);
LV_IMG_DECLARE(_syteam32x32_alpha_30x30);
LV_IMG_DECLARE(_weater32x32_alpha_30x30);
LV_IMG_DECLARE(_set32x32_alpha_30x30);
LV_IMG_DECLARE(_heart32x32_alpha_48x39);
LV_IMG_DECLARE(_location32x32_alpha_30x30);
LV_IMG_DECLARE(_NFC32x32_alpha_30x30);
LV_IMG_DECLARE(_qrcode32x32_alpha_30x30);
LV_IMG_DECLARE(_syteam32x32_alpha_30x30);
LV_IMG_DECLARE(_weater32x32_alpha_30x30);
LV_IMG_DECLARE(_set32x32_alpha_30x30);
LV_IMG_DECLARE(_heart32x32_alpha_30x30);
LV_IMG_DECLARE(_weater32x32_alpha_30x30);
LV_IMG_DECLARE(_qrcode32x32_alpha_30x30);
LV_IMG_DECLARE(_set32x32_alpha_30x30);
LV_IMG_DECLARE(_syteam32x32_alpha_30x30);
LV_IMG_DECLARE(_NFC32x32_alpha_30x30);
LV_IMG_DECLARE(_location32x32_alpha_30x30);

LV_IMG_DECLARE(_ZNZ_100x100);

LV_FONT_DECLARE(lv_font_montserratMedium_12)
LV_FONT_DECLARE(lv_font_montserratMedium_16)
LV_FONT_DECLARE(lv_font_SourceHanSerifSC_Regular_16)
LV_FONT_DECLARE(lv_font_montserratMedium_25)
LV_FONT_DECLARE(lv_font_interttf_82)
LV_FONT_DECLARE(lv_font_interttf_28)


#ifdef __cplusplus
}
#endif
#endif
