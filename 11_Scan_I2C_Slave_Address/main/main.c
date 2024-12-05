#include <stdio.h>
#include "driver/i2c.h"
#include "esp_log.h"

void app_main(void)
{
    i2c_config_t conf;

    conf.mode = I2C_MODE_MASTER;
    conf.sda_io_num = 21;
    conf.scl_io_num = 22;
    conf.master.clk_speed = 1000000;
    conf.clk_flags = 0;
    conf.sda_pullup_en = GPIO_PULLUP_ENABLE;
    conf.scl_pullup_en = GPIO_PULLUP_ENABLE;

    i2c_param_config(I2C_NUM_0, &conf);
    i2c_driver_install(I2C_NUM_0, I2C_MODE_MASTER, 0, 0, 0);

    printf("Scaning I2C Bus........\n");

        // Iterate over all possible I2C addresses
    for (int addr = 1; addr < 127; addr++) {
        // Create I2C command link
        i2c_cmd_handle_t cmd = i2c_cmd_link_create();
        i2c_master_start(cmd);
        // Send I2C address with write bit
        i2c_master_write_byte(cmd, (addr << 1) | I2C_MASTER_WRITE, true);
        i2c_master_stop(cmd);

        // Execute I2C command and check for response
        esp_err_t ret = i2c_master_cmd_begin(I2C_NUM_0, cmd, pdMS_TO_TICKS(1000));
        i2c_cmd_link_delete(cmd);

        // If device responds, print the address
        if (ret == ESP_OK) {
            printf("Found device at address 0x%02x\n", addr);
        }

    }
    printf("I2C scan completed\n");

    

}