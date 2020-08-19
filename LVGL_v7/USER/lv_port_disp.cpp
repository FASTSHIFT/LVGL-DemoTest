#include "DisplayPrivate.h"

static lv_disp_buf_t disp_buf;
static lv_color_t lv_disp_buf[LV_HOR_RES_MAX * 100];

#if LV_USE_LOG != 0
/* Serial debugging */
void my_print(lv_log_level_t level, const char * file, uint32_t line, const char * dsc)
{
    Serial.printf("%s@%d->%s\r\n", file, line, dsc);
}
#endif

/* Display flushing */
static void disp_flush(lv_disp_drv_t *disp, const lv_area_t *area, lv_color_t *color_p)
{
    screen.drawFastRGBBitmap(area->x1, area->y1, (uint16_t*)color_p, (area->x2 - area->x1 + 1), (area->y2 - area->y1 + 1));
    lv_disp_flush_ready(disp); /* tell lvgl that flushing is done */
//    static uint16_t color; 
//    screen.drawRect(area->x1, area->y1, (area->x2 - area->x1 + 1), (area->y2 - area->y1 + 1), color += 50);
}

void lv_port_disp_init()
{

#if LV_USE_LOG != 0
    lv_log_register_print_cb(my_print); /* register print function for debugging */
#endif

    lv_disp_buf_init(&disp_buf, lv_disp_buf, NULL, sizeof(lv_disp_buf)/sizeof(lv_color_t));

    /*Initialize the display*/
    lv_disp_drv_t disp_drv;
    lv_disp_drv_init(&disp_drv);
    disp_drv.flush_cb = disp_flush;
    disp_drv.buffer = &disp_buf;
    lv_disp_drv_register(&disp_drv);
}
