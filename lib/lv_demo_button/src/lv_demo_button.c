/**
 * @file lv_demo_button.c
 *
 */

/*********************
 *      INCLUDES
 *********************/
#include "lv_demo_button.h"
#include "lvgl.h"

//#if LV_USE_DEMO_BUTTON
/*********************
 *      DEFINES
 *********************/

/**********************
 *      TYPEDEFS
 **********************/

/**********************
 *  STATIC PROTOTYPES
 **********************/
static void obj_test_task_cb(lv_timer_t * tmr);

/**********************
 *  STATIC VARIABLES
 **********************/
static lv_obj_t * main_page;
static lv_obj_t * label;
static lv_obj_t * ta;
static const char * mbox_btns[] = {"Ok", "Cancel", ""};
static uint32_t mem_free_start = 0;
/**********************
 *      MACROS
 **********************/

/**********************
 *   GLOBAL FUNCTIONS
 **********************/

 /*
void lv_demo_button(void)
{
    lv_timer_create(obj_test_task_cb, LV_DEMO_BUTTON_TIME_STEP, NULL);
}
*/
/**********************
 *   STATIC FUNCTIONS
 **********************/

 #define LV_HOR_RES 480 
 #define LV_VER_RES 480

 static void event_handler(lv_event_t * e)
{
    lv_event_code_t code = lv_event_get_code(e);

    if(code == LV_EVENT_CLICKED) {
        LV_LOG_USER("Clicked");
    }
    else if(code == LV_EVENT_VALUE_CHANGED) {
        LV_LOG_USER("Toggled");
    }
}

//void obj_test_task_cb(lv_timer_t * tmr)
void lv_demo_button(void)
{
    static int16_t state = -1;

    lv_anim_t a;
    lv_obj_t * obj;

    lv_obj_t * tv = lv_tileview_create(lv_scr_act());

    /*Tile1: just a label*/
    lv_obj_t * tile1 = lv_tileview_add_tile(tv, 0, 0, LV_DIR_BOTTOM);
    lv_obj_t * label = lv_label_create(tile1);
    lv_label_set_text(label, "Scroll Down Mate");
    lv_obj_center(label);

    /*Tile2: a button*/
    lv_obj_t * tile2 = lv_tileview_add_tile(tv, 0, 1, (lv_dir_t)(LV_DIR_TOP | LV_DIR_RIGHT));

    lv_obj_t * btn = lv_btn_create(tile2);

    label = lv_label_create(btn);
    lv_label_set_text(label, "Scroll up or right");

    lv_obj_set_size(btn, LV_SIZE_CONTENT, LV_SIZE_CONTENT);
    lv_obj_center(btn);

    /*Tile3: a list*/
    lv_obj_t * tile3 = lv_tileview_add_tile(tv, 1, 1, LV_DIR_LEFT);
    lv_obj_t * list = lv_list_create(tile3);
    lv_obj_set_size(list, LV_PCT(100), LV_PCT(100));

    lv_list_add_btn(list, NULL, "One");
    lv_list_add_btn(list, NULL, "Two");
    lv_list_add_btn(list, NULL, "Three");
    lv_list_add_btn(list, NULL, "Four");
    lv_list_add_btn(list, NULL, "Five");
    lv_list_add_btn(list, NULL, "Six");
    lv_list_add_btn(list, NULL, "Seven");
    lv_list_add_btn(list, NULL, "Eight");
    lv_list_add_btn(list, NULL, "Nine");
    lv_list_add_btn(list, NULL, "Ten");
    /*

    // Holder for all object types 
    main_page = lv_obj_create(lv_scr_act());
    lv_obj_set_size(main_page,LV_HOR_RES, LV_VER_RES);
    //lv_obj_set_style_bg_color(main_page, lv_color_hex(0x101010),LV_PART_MAIN);
    lv_obj_set_style_bg_color(main_page, LV_PALETTE_LIGHT_BLUE,LV_PART_MAIN);
    
    lv_obj_t * btn = lv_btn_create(main_page);
    lv_obj_add_event_cb(btn, event_handler, LV_EVENT_ALL, NULL);
    lv_obj_add_flag(btn, LV_OBJ_FLAG_CHECKABLE);
    lv_obj_set_size(btn, 100, 70);
    //lv_obj_set_style_bg_color(btn, LV_PALETTE_RED);
    lv_obj_set_style_bg_color(btn,lv_color_hex(0x101010),LV_PART_MAIN);
    lv_obj_align(btn, LV_ALIGN_CENTER, 0, 0);

    label = lv_label_create(btn);
    lv_label_set_text(label, "Button!");
    lv_obj_center(label);

    */
}

//#endif /* LV_USE_DEMO_STRESS */
