#include <stdio.h>
#include <string.h>

#include "freertos/FreeRTOS.h"
#include "driver/spi_master.h" 
#include "driver/gpio.h"

#define MOSI    12
#define MISO    13
#define SCLK    15
#define CS      14

void app_main(void)
{
    spi_device_handle_t handle;

    spi_bus_config_t spi_config = {
        .mosi_io_num = MOSI,
        .miso_io_num = MISO,
        .sclk_io_num = SCLK
    };

    spi_device_interface_config_t spi_device_confg = {
        .clock_speed_hz = 1000000,
        .duty_cycle_pos = 128,
        .mode           = 0,
        .spics_io_num   = CS,
        .queue_size     = 1
    };

    spi_bus_initialize(SPI2_HOST, &spi_config, SPI_DMA_CH_AUTO);
    spi_bus_add_device(SPI2_HOST, &spi_device_confg, &handle);

    char sendbuf[128] = {0};
    char recvbuf[128] = {0};

    spi_transaction_t t;
    memset(&t, 0, sizeof(t));

    while(1)
    {
        snprintf(sendbuf, sizeof(sendbuf), "Hi I am from ESP32");
        t.length = sizeof(sendbuf) * 8;
        t.tx_buffer = sendbuf;
        t.rx_buffer = recvbuf;
        spi_device_transmit(handle, &t);
        printf("Transmitted: %s\n", sendbuf);
        printf("Received: %s\n", recvbuf);
        vTaskDelay(1000 / portTICK_PERIOD_MS);
    }


}