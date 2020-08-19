#include "DisplayPrivate.h"
#include "SysConfig.h"

SCREEN_CLASS screen(
    TFT_PORT_Pin, TFT_RST_Pin, TFT_CS_Pin,
    TFT_RS_Pin, TFT_RW_Pin, TFT_RD_Pin
);

extern "C" {
void lv_demo_widgets(void);
void lv_demo_benchmark(void);
void lv_demo_stress(void);
void lv_demo_printer(void);
}

void Display_Init()
{
    screen.begin();
    screen.setRotation(1);
    screen.fillScreen(screen.Black);
    
    pinMode(TFT_LED_Pin, OUTPUT);
    digitalWrite(TFT_LED_Pin, HIGH);

    lv_init();
    lv_port_disp_init();
    lv_port_indev_init();
    
    lv_demo_widgets();
    //lv_demo_benchmark();
    //lv_demo_stress();
    //lv_demo_printer();
}

void Display_Task()
{
    lv_task_handler();
}
