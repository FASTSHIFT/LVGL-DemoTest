#include "Arduino.h"
#include "DisplayPrivate.h"

void setup()
{
    Display_Init();
}

void loop()
{
    Display_Task();
}

/**
  * @brief  Main Function
  * @param  None
  * @retval None
  */
int main(void)
{
    NVIC_PriorityGroupConfig(NVIC_PriorityGroup_2);
    Delay_Init();
    ADCx_Init(ADC1);
    setup();
    for(;;)loop();
}
