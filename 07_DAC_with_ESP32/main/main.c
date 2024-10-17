#include <stdio.h>
#include "freertos/FreeRTOS.h"
#include"driver/gpio.h"
#include "driver/dac.h"


void app_main(void)
{
    dac_output_enable(DAC_CHANNEL_1);

    while(true)
    {
        for(int i = 0; i <= 255; i++)
        {
            dac_output_voltage(DAC_CHANNEL_1, i);
            printf("DAC is %d\n", i);
            vTaskDelay(50/portTICK_PERIOD_MS);
        }
        for(int i = 255; i > 0; i--)
        {
            dac_output_voltage(DAC_CHANNEL_1, i);
            printf("DAC is %d\n", i);
            vTaskDelay(50/portTICK_PERIOD_MS);
        }
    }
}