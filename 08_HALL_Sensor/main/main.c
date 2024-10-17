#include <stdio.h>
#include "driver/gpio.h"
#include "freertos/FreeRTOS.h"

#define led_pin 12

uint32_t hall_sens_read();
uint32_t hall_sensor_value;

void app_main(void)
{
    gpio_reset_pin(led_pin);
    gpio_set_direction(led_pin, GPIO_MODE_OUTPUT);

    while(true)
    {
        hall_sensor_value =  hall_sens_read();
        printf("Hall Sensor Value: %ld \n", hall_sensor_value);

        if(hall_sensor_value < 100)
        {
            gpio_set_level(led_pin, true);
        }
        else{
           gpio_set_level(led_pin, false); 
        }
        vTaskDelay(100 / portTICK_PERIOD_MS);
    }

}