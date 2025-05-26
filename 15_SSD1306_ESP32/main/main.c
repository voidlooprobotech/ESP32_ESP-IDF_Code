#include <stdio.h>
#include <esp_log.h>
#include <ssd1306.h>

void app_main(void)
{
    init_ssd1306();

    while(1)
    {   
        ssd1306_print_str(18, 0, "Hello World!", false);
        ssd1306_print_str(18, 17, "SSD1306 OLED", false);
        ssd1306_print_str(28, 27, "with ESP32", false);
        ssd1306_print_str(38, 37, "ESP-IDF", false);
        ssd1306_print_str(28, 47, "Embedded C", false);

        ssd1306_display();
        vTaskDelay(3000 / portTICK_PERIOD_MS);
    }
}