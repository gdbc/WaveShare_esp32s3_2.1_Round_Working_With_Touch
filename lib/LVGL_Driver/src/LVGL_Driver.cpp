/*****************************************************************************
  | File        :   LVGL_Driver.c
  
  | help        : 
    The provided LVGL library file must be installed first
******************************************************************************/
#include "LVGL_Driver.h"

static lv_color_t* buf1 = (lv_color_t*)heap_caps_aligned_alloc(32, (LCD_WIDTH * LCD_HEIGHT * 2) / 6, MALLOC_CAP_DMA);
static lv_color_t* buf2 = (lv_color_t*)heap_caps_aligned_alloc(32, (LCD_WIDTH * LCD_HEIGHT * 2) / 6, MALLOC_CAP_DMA);

/*  Display flushing 
    Displays LVGL content on the LCD
    This function implements associating LVGL data to the LCD screen
*/
void flushDisplay(lv_display_t *disp, const lv_area_t *area, uint8_t *color_p) {
    LCD_addWindow(area->x1, area->x2, area->y1, area->y2, color_p);
    lv_display_flush_ready(disp);
}

void example_increase_lvgl_tick(void *arg)
{
    lv_tick_inc(EXAMPLE_LVGL_TICK_PERIOD_MS);
}


void Lvgl_Touchpad_Read(lv_indev_t *indev_drv, lv_indev_data_t *data)
{
  Touch_Read_Data();
  if (touch_data.points != 0x00) {
    data->point.x = touch_data.x;
    data->point.y = touch_data.y;
    data->state = LV_INDEV_STATE_PR;
    printf("LVGL : X=%u Y=%u points=%d\r\n",  touch_data.x , touch_data.y,touch_data.points);
  } else {
    data->state = LV_INDEV_STATE_RELEASED;
  }
  if (touch_data.gesture != NONE ) {    
  }
  touch_data.x = 0;
  touch_data.y = 0;
  touch_data.points = 0;
  touch_data.gesture = NONE;
}



void lvgl_init(void)
{
  lv_init();
  lv_tick_set_cb(xTaskGetTickCount);
  
  lv_display_t *disp_drv = lv_display_create(LCD_WIDTH, LCD_HEIGHT);

  /* Initialize the draw buffer */
  lv_display_set_buffers(disp_drv, buf1, buf2, (LCD_WIDTH * LCD_HEIGHT) / 6, LV_DISPLAY_RENDER_MODE_PARTIAL);

  /* Set the display resolution */
  lv_display_set_resolution(disp_drv, LCD_WIDTH, LCD_HEIGHT);
  lv_display_set_physical_resolution(disp_drv, LCD_WIDTH, LCD_HEIGHT);

  /* Set flush callback */
  lv_display_set_flush_cb(disp_drv, flushDisplay);

  lv_indev_t *indev = lv_indev_create();
  lv_indev_set_type(indev, LV_INDEV_TYPE_POINTER);
  lv_indev_set_read_cb(indev, Lvgl_Touchpad_Read);

}

void Lvgl_Loop(void)
{
  lv_timer_handler(); /* let the GUI do its work */
  // vTaskDelay(pdMS_TO_TICKS(5));
}