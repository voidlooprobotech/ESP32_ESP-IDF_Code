#include <stdio.h>
#include "driver/gpio.h"
#include "freertos/FreeRTOS.h"

#define Led    2
#define Button 5

void app_main(void)
{
    gpio_reset_pin(Led);
    gpio_reset_pin(Button);

    gpio_set_direction(Led, GPIO_MODE_OUTPUT);

    gpio_set_pull_mode(Button, GPIO_PULLUP_ONLY);
    gpio_set_direction(Button, GPIO_MODE_INPUT);

    while(true)
    {
        int status = gpio_get_level(Button);

        if(status == false)
        {
            gpio_set_level(Led, true);
        }
        else
        {
            gpio_set_level(Led, false);
        }

        vTaskDelay(50 / portTICK_PERIOD_MS);
    }

}