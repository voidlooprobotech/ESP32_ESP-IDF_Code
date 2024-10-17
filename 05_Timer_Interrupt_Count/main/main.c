#include <stdio.h>
#include "driver/gpio.h"
#include "freertos/FreeRTOS.h"
#include "esp_timer.h"

uint16_t count = 0;

void timer_callback(void *param)
{
    count++;
}

void app_main(void)
{
    const esp_timer_create_args_t my_timer_args = 
    {
        .callback = &timer_callback,
        .name = "Timer Interrupt"
    };

    esp_timer_handle_t timer_handler;
    esp_timer_create(&my_timer_args, &timer_handler);
    esp_timer_start_periodic(timer_handler, 10000);  // One Second = 1000000 micro second

    while(true)
    {
        printf("%d\n", count);
        vTaskDelay(10/ portTICK_PERIOD_MS);
    }

}