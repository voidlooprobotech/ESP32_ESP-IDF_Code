#include <stdio.h>
#include <string.h>
#include "freertos/FreeRTOS.h"
#include "freertos/task.h"
#include "driver/uart.h"

char *tx_data = "Hi I am from ESP32";
char rx_data[128];

void app_main(void)
{

    uart_config_t uart_config = {
        .baud_rate = 9600,
        .data_bits = UART_DATA_8_BITS,
        .parity   = UART_PARITY_DISABLE,
        .stop_bits = UART_STOP_BITS_1,
        .flow_ctrl = UART_HW_FLOWCTRL_DISABLE,
        .source_clk = UART_SCLK_APB,
    };

    uart_param_config(UART_NUM_2, &uart_config);
    uart_set_pin(UART_NUM_2, 17, 16, UART_PIN_NO_CHANGE, UART_PIN_NO_CHANGE);
    uart_driver_install(UART_NUM_2, 1024, 0, 0, NULL, 0);

    while(1)
    {
        uart_write_bytes(UART_NUM_2, tx_data, strlen(tx_data));
        int len = uart_read_bytes(UART_NUM_2, rx_data, 128, pdMS_TO_TICKS(5));
        if(len > 0)
        {
            rx_data[len] = '\0';
            printf("Length: %d, Data: %s\n", len, rx_data);
            fflush(stdout);
        }

        vTaskDelay(500 / portTICK_PERIOD_MS);
    }

}