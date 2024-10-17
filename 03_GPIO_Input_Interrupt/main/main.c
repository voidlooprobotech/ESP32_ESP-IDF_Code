#include <stdio.h>
#include "freertos/FreeRTOS.h"
#include "driver/gpio.h"
#include "esp_log.h"
#include "inttypes.h"

#define interrupt_pin        5
uint16_t interrupt_count =   0;
bool button_state        =   false;

static void IRAM_ATTR gpio_isr_handler(void *arg)
{

    interrupt_count ++;
    button_state    = true;

    gpio_isr_handler_add(interrupt_pin, gpio_isr_handler, NULL);
    gpio_intr_enable(interrupt_pin);
}

void app_main(void)
{
    gpio_reset_pin(interrupt_pin);
    gpio_set_direction(interrupt_pin, GPIO_MODE_INPUT);

    gpio_set_pull_mode(interrupt_pin, GPIO_PULLUP_ONLY);

    gpio_set_intr_type(interrupt_pin, GPIO_INTR_POSEDGE);

    gpio_install_isr_service(0);
    gpio_isr_handler_add(interrupt_pin, gpio_isr_handler, NULL);

    gpio_intr_enable(interrupt_pin);

    while(1)
    {
        if(button_state == true)
        {
            printf("%d\n", interrupt_count);
            button_state = false;
        }
        vTaskDelay(100 / portTICK_PERIOD_MS);

    }

}