#include <stdio.h>
#include <string.h>
#include <time.h>
#include "driver/i2c.h"
#include "esp_log.h"
#include "freertos/FreeRTOS.h"
#include "freertos/task.h"
#include "ds3231.h"
#include "esp_mac.h"

#define TAG "TIME"

float temp;
struct tm rtcinfo;

void app_main(void)
{
    i2c_dev_t dev;
	if (ds3231_init_desc(&dev, I2C_NUM_0, 21, 22) != ESP_OK) {
		ESP_LOGI(TAG, "Could not init device descriptor.");
		while (1) 
        {
            vTaskDelay(1);
        }
	}

    while (1) 
    {
        if (ds3231_get_temp_float(&dev, &temp) != ESP_OK) {
            ESP_LOGI(TAG,"Could not get temperature.");
            while (1) 
            { 
                vTaskDelay(1); 
            }
        }

        if (ds3231_get_time(&dev, &rtcinfo) != ESP_OK) {
            ESP_LOGI(TAG, "Could not get time.");
            while (1) 
            { 
                vTaskDelay(1); 
            }
        }

        ESP_LOGI(TAG, "%04d-%02d-%02d %02d:%02d:%02d, %.2f deg Cel", rtcinfo.tm_year, rtcinfo.tm_mon + 1, rtcinfo.tm_mday, rtcinfo.tm_hour, rtcinfo.tm_min, rtcinfo.tm_sec, temp);
        vTaskDelay(1000 / portTICK_PERIOD_MS);
	}

}