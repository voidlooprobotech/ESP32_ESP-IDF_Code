#include <stdio.h>
#include "freertos/FreeRTOS.h"
#include "freertos/task.h"
#include "driver/i2c.h"

#define i2c_addr 0x0c
uint8_t i2c_data[14];

void app_main(void)
{
    i2c_config_t config = {
    .mode = I2C_MODE_MASTER,
    .sda_io_num = 21,
    .scl_io_num = 22,
    .sda_pullup_en = GPIO_PULLUP_ENABLE,
    .scl_pullup_en = GPIO_PULLUP_ENABLE,
    .master.clk_speed = 10000
    };

    i2c_param_config(I2C_NUM_0, &config);
    i2c_driver_install(I2C_NUM_0, config.mode, 0,0,0);

    while(1)
    {
        i2c_cmd_handle_t cmd_handle = i2c_cmd_link_create();
        i2c_master_start(cmd_handle);
        i2c_master_write_byte(cmd_handle, (i2c_addr << 1) | I2C_MASTER_READ, true);
        i2c_master_read(cmd_handle, (uint8_t*)i2c_data, 14, I2C_MASTER_ACK);
        i2c_master_stop(cmd_handle);
        i2c_master_cmd_begin(I2C_NUM_0, cmd_handle, 1000 / portTICK_PERIOD_MS);
        i2c_cmd_link_delete(cmd_handle);

        printf("Received I2C data: %s\n", i2c_data);
        vTaskDelay(1000 / portTICK_PERIOD_MS);
    }
}
