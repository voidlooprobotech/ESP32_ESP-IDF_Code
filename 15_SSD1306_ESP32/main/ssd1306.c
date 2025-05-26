#include "ssd1306.h"
#include "ssd1306_const.h"


uint8_t ssd1306_logo[8][64] = {
    {0xFF, 0xFF, 0xFF, 0xFF, 0x0F, 0x0F, 0xEF, 0xEF, 0xEF, 0xEF, 0x0F, 0x0F, 0xFF, 0xFF, 0xFF, 0xFF,
     0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0x7F, 0x3F, 0x9F, 0x5F, 0x6F, 0xE7, 0xF3, 0xF9, 0xF9, 0xFB,
     0xF7, 0xE7, 0xCF, 0x9F, 0xBF, 0x7F, 0x7F, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF,
     0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF},
    {0xFF, 0xFF, 0xFF, 0xFF, 0x00, 0x00, 0xFF, 0xFF, 0xFF, 0xFF, 0x00, 0x00, 0x7F, 0x3F, 0x9F, 0xDF,
     0xCF, 0xE7, 0xF3, 0xF9, 0xFD, 0xFE, 0xFE, 0xFF, 0xFF, 0xC0, 0xC0, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF,
     0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFE, 0xFC, 0xF9, 0xF3, 0xF7, 0x67, 0x0F, 0x1F, 0x3F, 0x7F,
     0x7F, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF},
    {0xFF, 0xFF, 0x7F, 0x3F, 0x80, 0xC0, 0xFF, 0xFF, 0xFF, 0xFF, 0xFE, 0xFC, 0xFE, 0x3F, 0x1F, 0x1F,
     0x0F, 0x07, 0x07, 0x03, 0x03, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01,
     0x03, 0x03, 0x07, 0x07, 0x0F, 0x1F, 0x3F, 0x7F, 0xFB, 0xF9, 0xFC, 0xFC, 0xFE, 0xFF, 0xFF, 0xFF,
     0xFE, 0xFC, 0xF9, 0xF3, 0xF7, 0xEF, 0xCF, 0x9F, 0x3F, 0x7F, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF},
    {0xFF, 0x00, 0xFE, 0x7F, 0x3F, 0x3F, 0xFF, 0xFF, 0xFF, 0x7F, 0x07, 0x01, 0x00, 0x00, 0x00, 0x00,
     0x00, 0x00, 0xE0, 0xE0, 0xF0, 0xF0, 0xF0, 0xF0, 0xE0, 0xE0, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
     0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x01, 0x07, 0xFF, 0xFF, 0xFF, 0x7F, 0x7F,
     0x7F, 0x7F, 0x7F, 0x7F, 0x7F, 0xFF, 0xFF, 0x7F, 0x7F, 0xFF, 0x80, 0x00, 0xFF, 0xFF, 0xFF, 0xFF},
    {0xFF, 0xFC, 0xFC, 0xFE, 0xFE, 0x00, 0xFF, 0xFF, 0xFF, 0xFE, 0xE0, 0x00, 0x00, 0x00, 0x00, 0x00,
     0x00, 0x00, 0x07, 0x07, 0x0F, 0x0F, 0x0F, 0x0F, 0x07, 0x07, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
     0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x80, 0xE0, 0xFF, 0xFF, 0xFF, 0xFE, 0xFE,
     0xFE, 0xFE, 0xFE, 0xFE, 0xFE, 0xFF, 0xFF, 0x00, 0xFE, 0xFE, 0xFC, 0xFC, 0xFF, 0xFF, 0xFF, 0xFF},
    {0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0x00, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFE, 0xF8, 0xF0, 0xE0,
     0xC0, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
     0x00, 0x00, 0x00, 0x80, 0xC0, 0xE0, 0xF0, 0xFC, 0x9E, 0x1F, 0x3F, 0x7F, 0xFF, 0xFF, 0xFF, 0xFF,
     0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0x00, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF},
    {0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0x00, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF,
     0xFF, 0xFF, 0xFE, 0xFC, 0x70, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x60,
     0x78, 0xFC, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFE, 0xFE, 0xFC, 0xFF, 0xFF, 0xFF,
     0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0x00, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF},
    {0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xC0, 0xDF, 0xDF, 0xDF, 0xDF, 0xDF, 0xDF, 0xDF, 0xDF, 0xDF, 0xDF,
     0xDF, 0xDF, 0xDF, 0xDF, 0xD0, 0xC0, 0xC0, 0xC2, 0xC2, 0xC2, 0xC2, 0xC2, 0xC2, 0xC2, 0xC0, 0xC0,
     0xD0, 0xDF, 0xDF, 0xDF, 0xDF, 0xDF, 0xDF, 0xDF, 0xDF, 0xDF, 0xDF, 0xDF, 0xDF, 0xDF, 0xDF, 0xDF,
     0xDF, 0xDF, 0xDF, 0xDF, 0xDF, 0xDF, 0xDF, 0xC0, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF}
};

static i2c_ssd1306_handle_t i2c_ssd1306;
static i2c_master_bus_handle_t i2c_master_bus;

/* I2C Master */
static const i2c_master_bus_config_t i2c_master_bus_config = {
    .i2c_port = I2C_NUM_0,
    .scl_io_num = GPIO_NUM_22,
    .sda_io_num = GPIO_NUM_21,
    .clk_source = I2C_CLK_SRC_DEFAULT,
    .glitch_ignore_cnt = 7,
    .flags.enable_internal_pullup = true};


/* SSD1306 */
static const i2c_ssd1306_config_t i2c_ssd1306_config = {
    .i2c_device_address = 0x3C,
    .i2c_scl_speed_hz = 400000,
    .width = 128,
    .height = 64,
    .wise = SSD1306_BOTTOM_TO_TOP};


void init_ssd1306(void)
{
    i2c_new_master_bus(&i2c_master_bus_config, &i2c_master_bus);
    i2c_ssd1306_init(i2c_master_bus, i2c_ssd1306_config, &i2c_ssd1306);
    i2c_ssd1306_buffer_image(&i2c_ssd1306, 32, 0, (const uint8_t *)ssd1306_logo, 64, 64, false);
    i2c_ssd1306_buffer_to_ram(&i2c_ssd1306);
    vTaskDelay(1000 / portTICK_PERIOD_MS);
    i2c_ssd1306_buffer_clear(&i2c_ssd1306);
}

esp_err_t ssd1306_print_str(uint8_t x, uint8_t y, const char *text, bool invert)
{
    return (i2c_ssd1306_buffer_text(&i2c_ssd1306, x, y, text, invert));
}

esp_err_t ssd1306_display(void)
{
    return (i2c_ssd1306_buffer_to_ram(&i2c_ssd1306));
}

esp_err_t i2c_ssd1306_init(i2c_master_bus_handle_t i2c_master_bus, i2c_ssd1306_config_t i2c_ssd1306_config, i2c_ssd1306_handle_t *i2c_ssd1306)
{
    if (i2c_ssd1306_config.i2c_scl_speed_hz > 400000 || i2c_ssd1306_config.width > 128 || i2c_ssd1306_config.height % 8 != 0 || i2c_ssd1306_config.height < 16 || i2c_ssd1306_config.height > 64)
    {
        ESP_LOGE(SSD1306_TAG, "Invalid SSD1306 configuration, 'i2c_scl_speed_hz' must be less than or equal to 400000, 'width' must be less than or equal to 128, 'height' must be between 16 and 64 and multiple of 8");
        return ESP_ERR_INVALID_ARG;
    }

    ESP_LOGI(SSD1306_TAG, "Initializing I2C SSD1306...");
    esp_err_t ret = i2c_master_probe(i2c_master_bus, i2c_ssd1306_config.i2c_device_address, I2C_SSD1306_TIMEOUT_MS / portTICK_PERIOD_MS);
    if (ret != ESP_OK)
    {
        switch (ret)
        {
        case ESP_ERR_NOT_FOUND:
            ESP_LOGE(SSD1306_TAG, "I2C SSD1306 device not found in address 0x%02X", i2c_ssd1306_config.i2c_device_address);
            break;
        case ESP_ERR_TIMEOUT:
            ESP_LOGE(SSD1306_TAG, "I2C SSD1306 device timeout in address 0x%02X", i2c_ssd1306_config.i2c_device_address);
            break;
        default:
            ESP_LOGE(SSD1306_TAG, "I2C SSD1306 device error in address 0x%02X", i2c_ssd1306_config.i2c_device_address);
            break;
        }

        return ret;
    }

    i2c_device_config_t i2c_device_config = {
        .dev_addr_length = I2C_ADDR_BIT_7,
        .device_address = i2c_ssd1306_config.i2c_device_address,
        .scl_speed_hz = i2c_ssd1306_config.i2c_scl_speed_hz};
    ret = i2c_master_bus_add_device(i2c_master_bus, &i2c_device_config, &i2c_ssd1306->i2c_master_dev);
    if (ret != ESP_OK)
    {
        ESP_LOGE(SSD1306_TAG, "Failed to add I2C SSD1306 device");
        return ret;
    }
    uint8_t ssd1306_init_cmd[] = {
        OLED_CONTROL_BYTE_CMD,
        OLED_CMD_DISPLAY_OFF,
        OLED_CMD_SET_MUX_RATIO, (i2c_ssd1306_config.height - 1),
        OLED_CMD_SET_VERT_DISPLAY_OFFSET, 0x00,
        OLED_MASK_DISPLAY_START_LINE | 0x00,
        OLED_CMD_COM_SCAN_DIRECTION_NORMAL,
        OLED_CMD_SEGMENT_REMAP_LEFT_TO_RIGHT,
        OLED_CMD_SET_COM_PIN_HARDWARE_MAP, 0x12,
        OLED_CMD_SET_MEMORY_ADDR_MODE, 0x02,
        OLED_CMD_SET_CONTRAST_CONTROL, 0xFF,
        OLED_CMD_SET_DISPLAY_CLK_DIVIDE, 0x80,
        OLED_CMD_ENABLE_DISPLAY_RAM,
        OLED_CMD_NORMAL_DISPLAY,
        OLED_CMD_SET_CHARGE_PUMP, 0x14,
        OLED_CMD_DISPLAY_ON};
    if (i2c_ssd1306_config.wise == SSD1306_BOTTOM_TO_TOP)
    {
        ssd1306_init_cmd[7] = OLED_CMD_COM_SCAN_DIRECTION_REMAP;
        ssd1306_init_cmd[8] = OLED_CMD_SEGMENT_REMAP_RIGHT_TO_LEFT;
    }
    ret = i2c_master_transmit(i2c_ssd1306->i2c_master_dev, ssd1306_init_cmd, sizeof(ssd1306_init_cmd), I2C_SSD1306_TIMEOUT_MS / portTICK_PERIOD_MS);
    if (ret != ESP_OK)
    {
        ESP_LOGE(SSD1306_TAG, "Failed to initialize I2C SSD1306 device");
        return ret;
    }

    i2c_ssd1306->width = i2c_ssd1306_config.width;
    i2c_ssd1306->height = i2c_ssd1306_config.height;
    i2c_ssd1306->total_pages = i2c_ssd1306_config.height / 8;

    i2c_ssd1306->page = (ssd1306_page_t *)calloc(i2c_ssd1306->total_pages, sizeof(ssd1306_page_t));
    if (i2c_ssd1306->page == NULL)
    {
        ESP_LOGE(SSD1306_TAG, "Failed to allocate memory for I2C SSD1306 device");
        return ESP_ERR_NO_MEM;
    }
    for (uint8_t i = 0; i < i2c_ssd1306->total_pages; i++)
    {
        i2c_ssd1306->page[i].segment = (uint8_t *)calloc(i2c_ssd1306->width, sizeof(uint8_t));
        if (i2c_ssd1306->page[i].segment == NULL)
            return ESP_ERR_NO_MEM;
    }
    ESP_LOGI(SSD1306_TAG, "I2C SSD1306 initialized successfully");

    return ret;
}

esp_err_t i2c_ssd1306_deinit(i2c_ssd1306_handle_t *i2c_ssd1306)
{
    ESP_LOGI(SSD1306_TAG, "Deinitializing I2C SSD1306...");
    for (uint8_t i = 0; i < i2c_ssd1306->total_pages; i++)
    {
        free(i2c_ssd1306->page[i].segment);
    }
    free(i2c_ssd1306->page);
    esp_err_t ret = i2c_master_bus_rm_device(i2c_ssd1306->i2c_master_dev);
    if (ret != ESP_OK)
    {
        ESP_LOGE(SSD1306_TAG, "Failed to remove I2C SSD1306 device");
        return ret;
    }
    ESP_LOGI(SSD1306_TAG, "I2C SSD1306 deinitialized successfully");

    return ret;
}

esp_err_t i2c_ssd1306_buffer_check(i2c_ssd1306_handle_t *i2c_ssd1306)
{
    for (uint8_t i = 0; i < i2c_ssd1306->total_pages; i++)
    {
        for (uint8_t j = 0; j < i2c_ssd1306->width; j++)
        {
            printf("%02X ", i2c_ssd1306->page[i].segment[j]);
        }
        printf("\n");
    }

    return ESP_OK;
}

esp_err_t i2c_ssd1306_buffer_clear(i2c_ssd1306_handle_t *i2c_ssd1306)
{
    for (uint8_t i = 0; i < i2c_ssd1306->total_pages; i++)
    {
        memset(i2c_ssd1306->page[i].segment, 0x00, i2c_ssd1306->width);
    }

    return ESP_OK;
}

esp_err_t i2c_ssd1306_buffer_fill(i2c_ssd1306_handle_t *i2c_ssd1306)
{
    for (uint8_t i = 0; i < i2c_ssd1306->total_pages; i++)
    {
        memset(i2c_ssd1306->page[i].segment, 0xFF, i2c_ssd1306->width);
    }

    return ESP_OK;
}

esp_err_t i2c_ssd1306_buffer_fill_pixel(i2c_ssd1306_handle_t *i2c_ssd1306, uint8_t x, uint8_t y, bool fill)
{
    if (x >= i2c_ssd1306->width || y >= i2c_ssd1306->height)
    {
        ESP_LOGE(SSD1306_TAG, "Invalid pixel coordinates, 'x' must be between 0 and %d, 'y' must be between 0 and %d", i2c_ssd1306->width - 1, i2c_ssd1306->height - 1);
        return ESP_ERR_INVALID_ARG;
    }
    uint8_t page = y / 8;
    uint8_t bit = 1 << (y % 8);
    if (fill)
    {
        i2c_ssd1306->page[page].segment[x] |= bit;
    }
    else
    {
        i2c_ssd1306->page[page].segment[x] &= ~bit;
    }

    return ESP_OK;
}

esp_err_t i2c_ssd1306_buffer_fill_space(i2c_ssd1306_handle_t *i2c_ssd1306, uint8_t x1, uint8_t x2, uint8_t y1, uint8_t y2, bool fill)
{
    if (x1 >= i2c_ssd1306->width || x2 >= i2c_ssd1306->width || y1 >= i2c_ssd1306->height || y2 >= i2c_ssd1306->height || x1 > x2 || y1 > y2)
    {
        ESP_LOGE(SSD1306_TAG, "Invalid space coordinates, 'x1' and 'x2' must be between 0 and %d, 'y1' and 'y2' must be between 0 and %d, 'x1' must be less than 'x2', 'y1' must be less than 'y2'", i2c_ssd1306->width - 1, i2c_ssd1306->height - 1);
        return ESP_ERR_INVALID_ARG;
    }

    uint8_t start_page = y1 / 8;
    uint8_t end_page = y2 / 8;
    uint8_t mask;
    uint8_t offset_start = y1 % 8;
    uint8_t offset_end = y2 % 8;

    for (uint8_t page = start_page; page <= end_page; page++)
    {
        if (start_page == end_page)
        {
            mask = (0xFF << offset_start) & (0xFF >> (7 - offset_end));
        }
        else if (page == start_page)
        {
            mask = 0xFF << offset_start;
        }
        else if (page == end_page)
        {
            mask = 0xFF >> (7 - offset_end);
        }
        else
        {
            mask = 0xFF;
        }

        for (uint8_t j = x1; j <= x2; j++)
        {
            if (fill)
                i2c_ssd1306->page[page].segment[j] |= mask;
            else
                i2c_ssd1306->page[page].segment[j] &= ~mask;
        }
    }

    return ESP_OK;
}

esp_err_t i2c_ssd1306_buffer_text(i2c_ssd1306_handle_t *i2c_ssd1306, uint8_t x, uint8_t y, const char *text, bool invert)
{
    if (x >= i2c_ssd1306->width || y >= i2c_ssd1306->height || !text || strlen(text) == 0)
    {
        ESP_LOGE(SSD1306_TAG, "Invalid text or coordinates: x=%d (max %d), y=%d (max %d)", x, i2c_ssd1306->width - 1, y, i2c_ssd1306->height - 1);
        return ESP_ERR_INVALID_ARG;
    }

    uint8_t len = strlen(text);
    uint8_t page = y / 8;
    uint8_t offset = y % 8;
    bool has_next_page = (page + 1) < i2c_ssd1306->total_pages;

    uint8_t max_chars = (i2c_ssd1306->width - x) / 8;
    if (len > max_chars)
    {
        ESP_LOGW(SSD1306_TAG, "Text truncated: text columns exceed display width, lost %d columns", x + (len * 8) - i2c_ssd1306->width);
    }

    if (offset != 0 && !has_next_page)
    {
        ESP_LOGW(SSD1306_TAG, "Vertical truncation: text exceeds display height, lost %d rows", offset);
    }

    for (uint8_t i = 0; i < len && x < i2c_ssd1306->width; i++)
    {
        const uint8_t *char_data = font8x8[(uint8_t)text[i]];
        uint8_t available_columns = i2c_ssd1306->width - x;
        uint8_t columns_to_draw = (available_columns < 8) ? available_columns : 8;

        for (uint8_t j = 0; j < columns_to_draw; j++)
        {
            uint8_t char_col = char_data[j];

            if (invert)
            {
                char_col = ~char_col;
            }

            if (offset == 0)
            {
                i2c_ssd1306->page[page].segment[x + j] |= char_col;
            }
            else
            {
                uint8_t lower_part = char_col << offset;
                uint8_t upper_part = char_col >> (8 - offset);

                i2c_ssd1306->page[page].segment[x + j] |= lower_part;
                if (has_next_page)
                {
                    i2c_ssd1306->page[page + 1].segment[x + j] |= upper_part;
                }
            }
        }

        x += 8;
    }

    return ESP_OK;
}

esp_err_t i2c_ssd1306_buffer_int(i2c_ssd1306_handle_t *i2c_ssd1306, uint8_t x, uint8_t y, int value, bool invert)
{
    char text[16];
    sprintf(text, "%d", value);

    return i2c_ssd1306_buffer_text(i2c_ssd1306, x, y, text, invert);
}

esp_err_t i2c_ssd1306_buffer_float(i2c_ssd1306_handle_t *i2c_ssd1306, uint8_t x, uint8_t y, float value, uint8_t decimals, bool invert)
{
    char text[16];
    sprintf(text, "%.*f", decimals, value);

    return i2c_ssd1306_buffer_text(i2c_ssd1306, x, y, text, invert);
}

esp_err_t i2c_ssd1306_buffer_image(i2c_ssd1306_handle_t *i2c_ssd1306, uint8_t x, uint8_t y, const uint8_t *image, uint8_t img_width, uint8_t img_height, bool invert)
{
    if (image == NULL || img_width == 0 || img_height == 0 || x >= i2c_ssd1306->width || y >= i2c_ssd1306->height)
    {
        ESP_LOGE(SSD1306_TAG, "Invalid image or coordinates: x=%d (max %d), y=%d (max %d)", x, i2c_ssd1306->width - 1, y, i2c_ssd1306->height - 1);
        return ESP_ERR_INVALID_ARG;
    }

    uint8_t draw_width = (img_width < (i2c_ssd1306->width - x)) ? img_width : (i2c_ssd1306->width - x);
    uint8_t draw_height = (img_height < (i2c_ssd1306->height - y)) ? img_height : (i2c_ssd1306->height - y);

    uint8_t start_page = y / 8;
    uint8_t vertical_offset = y % 8;
    uint8_t num_pages = i2c_ssd1306->total_pages;
    uint8_t draw_pages = (((draw_height + 7) / 8) < (num_pages - start_page)) ? ((draw_height + 7) / 8) : (num_pages - start_page);

    if (img_height > draw_height)
    {
        ESP_LOGW(SSD1306_TAG, "Vertical truncation: Lost %d rows", img_height - draw_height);
    }
    if (draw_width < img_width)
    {
        ESP_LOGW(SSD1306_TAG, "Horizontal truncation: Lost %d columns", img_width - draw_width);
    }

    for (uint8_t col = 0; col < draw_width; col++)
    {
        for (uint8_t page = 0; page < draw_pages; page++)
        {
            uint8_t target_page = start_page + page;
            if (target_page >= num_pages)
                break;

            uint8_t img_byte = image[page * img_width + col];
            if (invert)
                img_byte = ~img_byte;

            if (vertical_offset == 0)
            {
                i2c_ssd1306->page[target_page].segment[x + col] |= img_byte;
            }
            else
            {
                uint8_t lower = img_byte << vertical_offset;
                uint8_t upper = img_byte >> (8 - vertical_offset);

                i2c_ssd1306->page[target_page].segment[x + col] |= lower;
                if (target_page + 1 < num_pages)
                {
                    i2c_ssd1306->page[target_page + 1].segment[x + col] |= upper;
                }
            }
        }
    }

    return ESP_OK;
}

esp_err_t i2c_ssd1306_segment_to_ram(i2c_ssd1306_handle_t *i2c_ssd1306, uint8_t page, uint8_t segment)
{
    if (page >= i2c_ssd1306->total_pages || segment >= i2c_ssd1306->width)
    {
        ESP_LOGE(SSD1306_TAG, "Invalid page or segment number, 'page' must be between 0 and %d, 'segment' must be between 0 and %d", i2c_ssd1306->total_pages - 1, i2c_ssd1306->width - 1);
        return ESP_ERR_INVALID_ARG;
    }

    uint8_t ram_addr_cmd[] = {
        OLED_CONTROL_BYTE_CMD,
        OLED_MASK_PAGE_ADDR | page,
        OLED_MASK_LSB_NIBBLE_SEG_ADDR | (segment & 0x0F),
        OLED_MASK_HSB_NIBBLE_SEG_ADDR | (segment >> 4 & 0x0F)};
    esp_err_t err = i2c_master_transmit(i2c_ssd1306->i2c_master_dev, ram_addr_cmd, sizeof(ram_addr_cmd), I2C_SSD1306_TIMEOUT_MS / portTICK_PERIOD_MS);
    if (err != ESP_OK)
    {
        ESP_LOGE(SSD1306_TAG, "Failed to address the segment to the RAM of the SSD1306 device");
        return err;
    }
    uint8_t ram_data_cmd[] = {
        OLED_CONTROL_BYTE_DATA,
        i2c_ssd1306->page[page].segment[segment]};
    err = i2c_master_transmit(i2c_ssd1306->i2c_master_dev, ram_data_cmd, sizeof(ram_data_cmd), I2C_SSD1306_TIMEOUT_MS / portTICK_PERIOD_MS);
    if (err != ESP_OK)
    {
        ESP_LOGE(SSD1306_TAG, "Failed to transfer the segment to the RAM of the SSD1306 device");
        return err;
    }

    return err;
}

esp_err_t i2c_ssd1306_segments_to_ram(i2c_ssd1306_handle_t *i2c_ssd1306, uint8_t page, uint8_t initial_segment, uint8_t final_segment)
{
    if (page >= i2c_ssd1306->total_pages || initial_segment >= i2c_ssd1306->width || final_segment >= i2c_ssd1306->width || initial_segment > final_segment)
    {
        ESP_LOGE(SSD1306_TAG, "Invalid page or segment range, 'page' must be between 0 and %d, 'initial_segment' and 'final_segment' must be between 0 and %d, 'initial_segment' must be less than or equal to 'final_segment'", i2c_ssd1306->total_pages - 1, i2c_ssd1306->width - 1);
        return ESP_ERR_INVALID_ARG;
    }

    uint8_t ram_addr_cmd[] = {
        OLED_CONTROL_BYTE_CMD,
        OLED_MASK_PAGE_ADDR | page,
        OLED_MASK_LSB_NIBBLE_SEG_ADDR | (initial_segment & 0x0F),
        OLED_MASK_HSB_NIBBLE_SEG_ADDR | (initial_segment >> 4 & 0x0F)};
    esp_err_t err = i2c_master_transmit(i2c_ssd1306->i2c_master_dev, ram_addr_cmd, sizeof(ram_addr_cmd), I2C_SSD1306_TIMEOUT_MS / portTICK_PERIOD_MS);
    if (err != ESP_OK)
    {
        ESP_LOGE(SSD1306_TAG, "Failed to address the initial segment to the RAM of the SSD1306 device");
        return err;
    }
    uint8_t ram_data_cmd[final_segment - initial_segment + 2];
    ram_data_cmd[0] = OLED_CONTROL_BYTE_DATA;
    for (uint8_t i = 0; i < final_segment - initial_segment + 1; i++)
    {
        ram_data_cmd[i + 1] = i2c_ssd1306->page[page].segment[initial_segment + i];
    }
    err = i2c_master_transmit(i2c_ssd1306->i2c_master_dev, ram_data_cmd, sizeof(ram_data_cmd), I2C_SSD1306_TIMEOUT_MS / portTICK_PERIOD_MS);
    if (err != ESP_OK)
    {
        ESP_LOGE(SSD1306_TAG, "Failed to transfer the segments to the RAM of the SSD1306 device");
        return err;
    }

    return err;
}

esp_err_t i2c_ssd1306_page_to_ram(i2c_ssd1306_handle_t *i2c_ssd1306, uint8_t page)
{
    if (page >= i2c_ssd1306->total_pages)
    {
        ESP_LOGE(SSD1306_TAG, "Invalid page number, must be between 0 and %d", i2c_ssd1306->total_pages - 1);
        return ESP_ERR_INVALID_ARG;
    }

    uint8_t ram_addr_cmd[] = {
        OLED_CONTROL_BYTE_CMD,
        OLED_MASK_PAGE_ADDR | page,
        OLED_MASK_LSB_NIBBLE_SEG_ADDR | (0x00 & 0x0F),
        OLED_MASK_HSB_NIBBLE_SEG_ADDR | (0x00 >> 4 & 0x0F)};
    esp_err_t err = i2c_master_transmit(i2c_ssd1306->i2c_master_dev, ram_addr_cmd, sizeof(ram_addr_cmd), I2C_SSD1306_TIMEOUT_MS / portTICK_PERIOD_MS);
    if (err != ESP_OK)
    {
        ESP_LOGE(SSD1306_TAG, "Failed to address the page to the RAM of the SSD1306 device");
        return err;
    }
    uint8_t ram_data_cmd[i2c_ssd1306->width + 1];
    ram_data_cmd[0] = OLED_CONTROL_BYTE_DATA;
    for (uint8_t i = 0; i < i2c_ssd1306->width; i++)
    {
        ram_data_cmd[i + 1] = i2c_ssd1306->page[page].segment[i];
    }
    err = i2c_master_transmit(i2c_ssd1306->i2c_master_dev, ram_data_cmd, sizeof(ram_data_cmd), I2C_SSD1306_TIMEOUT_MS / portTICK_PERIOD_MS);
    if (err != ESP_OK)
    {
        ESP_LOGE(SSD1306_TAG, "Failed to transfer the page to the RAM of the SSD1306 device");
        return err;
    }

    return err;
}

esp_err_t i2c_ssd1306_pages_to_ram(i2c_ssd1306_handle_t *i2c_ssd1306, uint8_t initial_page, uint8_t final_page)
{
    if (initial_page >= i2c_ssd1306->total_pages || final_page >= i2c_ssd1306->total_pages || initial_page > final_page)
    {
        ESP_LOGE(SSD1306_TAG, "Invalid page range, 'initial_page' and 'final_page' must be between 0 and %d, 'initial_page' must be less than or equal to 'final_page'", i2c_ssd1306->total_pages - 1);
        return ESP_ERR_INVALID_ARG;
    }

    esp_err_t err = ESP_OK;
    for (uint8_t i = initial_page; i <= final_page; i++)
    {
        esp_err_t err = i2c_ssd1306_page_to_ram(i2c_ssd1306, i);
        if (err != ESP_OK)
            return err;
    }

    return err;
}

esp_err_t i2c_ssd1306_buffer_to_ram(i2c_ssd1306_handle_t *i2c_ssd1306)
{
    esp_err_t err = ESP_OK;
    for (uint8_t i = 0; i < i2c_ssd1306->total_pages; i++)
    {
        err = i2c_ssd1306_page_to_ram(i2c_ssd1306, i);
        if (err != ESP_OK)
            return err;
    }

    return err;
}