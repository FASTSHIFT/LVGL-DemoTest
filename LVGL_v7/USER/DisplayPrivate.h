#ifndef __DISPLAYPRIVATE_H
#define __DISPLAYPRIVATE_H

void Display_Init();
void Display_Task();

/*Basic*/
#include "TFT_ILI9488/TFT_ILI9488.h"
#include "GT911/touch.h"

typedef TFT_ILI9488 SCREEN_CLASS;
extern SCREEN_CLASS screen;

/*LittleVGL*/
#include "lvgl/lvgl.h"

void lv_port_disp_init();
void lv_port_indev_init();

#endif
