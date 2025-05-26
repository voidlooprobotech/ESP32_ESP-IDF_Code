#pragma once

#include <driver/i2c_master.h>
#include <esp_err.h>
#include <esp_log.h>
#include <string.h>
#include "freertos/FreeRTOS.h"

#define SSD1306_TAG "SSD1306"

#define I2C_SSD1306_TIMEOUT_MS 1000

/**
 * @brief Enumeration for SSD1306 display orientation.
 *
 * Defines the orientation (drawing order) used for the SSD1306 display.
 */
typedef enum
{
    SSD1306_TOP_TO_BOTTOM,
    SSD1306_BOTTOM_TO_TOP
} ssd1306_wise_t;

/**
 * @brief Structure for an SSD1306 page segment.
 *
 * Contains a pointer to the segment data for a page in the SSD1306 buffer.
 */
typedef struct
{
    uint8_t *segment;
} ssd1306_page_t;

/**
 * @brief Configuration for the I2C SSD1306 display.
 *
 * Holds configuration parameters for both the SSD1306 display and the I2C master.
 */
typedef struct
{
    uint16_t i2c_device_address;
    uint32_t i2c_scl_speed_hz;
    uint8_t width;
    uint8_t height;
    ssd1306_wise_t wise;
} i2c_ssd1306_config_t;

/**
 * @brief Handle for the I2C SSD1306 display.
 *
 * Contains runtime information including the I2C device handle, display dimensions, and pointers to the page buffers.
 */
typedef struct
{
    i2c_master_dev_handle_t i2c_master_dev;
    uint8_t width;
    uint8_t height;
    uint8_t total_pages;
    ssd1306_page_t *page;
} i2c_ssd1306_handle_t;


void init_ssd1306(void);
esp_err_t ssd1306_print_str(uint8_t x, uint8_t y, const char *text, bool invert);
esp_err_t ssd1306_display(void);


/**
 * @brief Initialize the I2C SSD1306 display.
 *
 * Configures and initializes the SSD1306 display using the provided I2C bus and configuration.
 *
 * @param i2c_master_bus       An initialized I2C master bus handle.
 * @param i2c_ssd1306_config   Configuration parameters for the SSD1306 display.
 * @param i2c_ssd1306          Pointer to the SSD1306 handle to be initialized.
 *
 * @return
 *   - ESP_OK on success.
 *   - ESP_ERR_INVALID_ARG if an argument is invalid.
 *   - ESP_ERR_NO_MEM if memory allocation fails.
 *   - ESP_FAIL on other failures.
 */
esp_err_t i2c_ssd1306_init(i2c_master_bus_handle_t i2c_master_bus, i2c_ssd1306_config_t i2c_ssd1306_config, i2c_ssd1306_handle_t *i2c_ssd1306);

/**
 * @brief Deinitialize the I2C SSD1306 display.
 *
 * Frees the memory allocated for the SSD1306 display handle.
 *
 * @param i2c_ssd1306 Pointer to the SSD1306 handle.
 *
 * @return ESP_OK on success, or an error code otherwise.
 */
esp_err_t i2c_ssd1306_deinit(i2c_ssd1306_handle_t *i2c_ssd1306);

/**
 * @brief Display the contents of the SSD1306 buffer.
 *
 * Prints the hexadecimal values of each segment in every page of the SSD1306 buffer
 * for debugging purposes.
 *
 * @param i2c_ssd1306 Pointer to the SSD1306 handle.
 *
 * @return ESP_OK on success, or an error code otherwise.
 */
esp_err_t i2c_ssd1306_buffer_check(i2c_ssd1306_handle_t *i2c_ssd1306);

/**
 * @brief Clear the SSD1306 display buffer.
 *
 * Resets all segments in the SSD1306 buffer to 0x00.
 *
 * @param i2c_ssd1306 Pointer to the SSD1306 handle.
 *
 * @return ESP_OK on success, or an error code otherwise.
 */
esp_err_t i2c_ssd1306_buffer_clear(i2c_ssd1306_handle_t *i2c_ssd1306);

/**
 * @brief Fill the SSD1306 display buffer.
 *
 * Fills every segment in each page of the SSD1306 buffer with 0xFF.
 *
 * @param i2c_ssd1306 Pointer to the SSD1306 handle.
 *
 * @return ESP_OK on success, or an error code otherwise.
 */
esp_err_t i2c_ssd1306_buffer_fill(i2c_ssd1306_handle_t *i2c_ssd1306);

/**
 * @brief Set or clear an individual pixel in the SSD1306 buffer.
 *
 * Modifies the state of a specific pixel in the SSD1306 buffer.
 *
 * @param i2c_ssd1306 Pointer to the SSD1306 handle.
 * @param x           X-coordinate of the pixel.
 * @param y           Y-coordinate of the pixel.
 * @param fill        If true, the pixel is set; if false, it is cleared.
 *
 * @return ESP_OK on success, or an error code otherwise.
 */
esp_err_t i2c_ssd1306_buffer_fill_pixel(i2c_ssd1306_handle_t *i2c_ssd1306, uint8_t x, uint8_t y, bool fill);

/**
 * @brief Fill or clear a rectangular area in the SSD1306 buffer.
 *
 * Sets or clears a block of pixels within the specified coordinate range.
 *
 * @param i2c_ssd1306 Pointer to the SSD1306 handle.
 * @param x1          X-coordinate of the starting pixel.
 * @param x2          X-coordinate of the ending pixel.
 * @param y1          Y-coordinate of the starting pixel.
 * @param y2          Y-coordinate of the ending pixel.
 * @param fill        If true, pixels are set; if false, pixels are cleared.
 *
 * @return ESP_OK on success, or an error code otherwise.
 */
esp_err_t i2c_ssd1306_buffer_fill_space(i2c_ssd1306_handle_t *i2c_ssd1306, uint8_t x1, uint8_t x2, uint8_t y1, uint8_t y2, bool fill);

/**
 * @brief Render text into the SSD1306 buffer.
 *
 * Copies 8x8 font characters representing the provided string into the SSD1306 buffer.
 *
 * @param i2c_ssd1306 Pointer to the SSD1306 handle.
 * @param x           X-coordinate for the text's starting position.
 * @param y           Y-coordinate for the text's starting position.
 * @param text        Null-terminated string to render.
 * @param invert      If true, the text is rendered inverted.
 *
 * @return ESP_OK on success, or an error code otherwise.
 */
esp_err_t i2c_ssd1306_buffer_text(i2c_ssd1306_handle_t *i2c_ssd1306, uint8_t x, uint8_t y, const char *text, bool invert);

/**
 * @brief Render an integer into the SSD1306 buffer.
 *
 * Copies 8x8 font characters representing the given integer into the SSD1306 buffer.
 *
 * @param i2c_ssd1306 Pointer to the SSD1306 handle.
 * @param x           X-coordinate for the integer's starting position.
 * @param y           Y-coordinate for the integer's starting position.
 * @param value       Integer value to render.
 * @param invert      If true, the integer is rendered inverted.
 *
 * @return ESP_OK on success, or an error code otherwise.
 */
esp_err_t i2c_ssd1306_buffer_int(i2c_ssd1306_handle_t *i2c_ssd1306, uint8_t x, uint8_t y, int value, bool invert);

/**
 * @brief Render a floating-point number into the SSD1306 buffer.
 *
 * Copies 8x8 font characters representing the given float value into the SSD1306 buffer.
 *
 * @param i2c_ssd1306 Pointer to the SSD1306 handle.
 * @param x           X-coordinate for the float's starting position.
 * @param y           Y-coordinate for the float's starting position.
 * @param value       Float value to render.
 * @param decimals    Number of decimal places to display.
 * @param invert      If true, the float is rendered inverted.
 *
 * @return ESP_OK on success, or an error code otherwise.
 */
esp_err_t i2c_ssd1306_buffer_float(i2c_ssd1306_handle_t *i2c_ssd1306, uint8_t x, uint8_t y, float value, uint8_t decimals, bool invert);

/**
 * @brief Render an image into the SSD1306 buffer.
 *
 * Copies the provided image data into the SSD1306 buffer at an 8x8 pixel resolution.
 *
 * @param i2c_ssd1306 Pointer to the SSD1306 handle.
 * @param x           X-coordinate for the image's starting position.
 * @param y           Y-coordinate for the image's starting position.
 * @param image       Pointer to the image data.
 * @param width       Width of the image in pixels.
 * @param height      Height of the image in pixels.
 * @param invert      If true, the image is rendered inverted.
 *
 * @return ESP_OK on success, or an error code otherwise.
 */
esp_err_t i2c_ssd1306_buffer_image(i2c_ssd1306_handle_t *i2c_ssd1306, uint8_t x, uint8_t y, const uint8_t *image, uint8_t width, uint8_t height, bool invert);

/**
 * @brief Transfer a specific buffer segment to the SSD1306 display RAM.
 *
 * Moves the designated segment from the buffer to the corresponding location in the display's RAM.
 *
 * @param i2c_ssd1306 Pointer to the SSD1306 handle.
 * @param page        Page number that contains the segment.
 * @param segment     Segment number within the page.
 *
 * @return ESP_OK on success, or an error code otherwise.
 */
esp_err_t i2c_ssd1306_segment_to_ram(i2c_ssd1306_handle_t *i2c_ssd1306, uint8_t page, uint8_t segment);

/**
 * @brief Transfer a range of buffer segments to the SSD1306 display RAM.
 *
 * Moves a sequence of segments from the specified page in the buffer to the display's RAM.
 *
 * @param i2c_ssd1306     Pointer to the SSD1306 handle.
 * @param page            Page number that contains the segments.
 * @param initial_segment Starting segment number.
 * @param final_segment   Ending segment number.
 *
 * @return ESP_OK on success, or an error code otherwise.
 */
esp_err_t i2c_ssd1306_segments_to_ram(i2c_ssd1306_handle_t *i2c_ssd1306, uint8_t page, uint8_t initial_segment, uint8_t final_segment);

/**
 * @brief Transfer an entire page from the buffer to the SSD1306 display RAM.
 *
 * Updates the display's RAM by transferring all segments of the specified page.
 *
 * @param i2c_ssd1306 Pointer to the SSD1306 handle.
 * @param page        Page number to update.
 *
 * @return ESP_OK on success, or an error code otherwise.
 */
esp_err_t i2c_ssd1306_page_to_ram(i2c_ssd1306_handle_t *i2c_ssd1306, uint8_t page);

/**
 * @brief Transfer a range of pages from the buffer to the SSD1306 display RAM.
 *
 * Updates the display's RAM by transferring all segments for pages within the specified range.
 *
 * @param i2c_ssd1306 Pointer to the SSD1306 handle.
 * @param initial_page Starting page number.
 * @param final_page   Ending page number.
 *
 * @return ESP_OK on success, or an error code otherwise.
 */
esp_err_t i2c_ssd1306_pages_to_ram(i2c_ssd1306_handle_t *i2c_ssd1306, uint8_t initial_page, uint8_t final_page);

/**
 * @brief Transfer the entire buffer to the SSD1306 display RAM.
 *
 * Updates the display's RAM by transferring the contents of all pages in the buffer.
 *
 * @param i2c_ssd1306 Pointer to the SSD1306 handle.
 *
 * @return ESP_OK on success, or an error code otherwise.
 */
esp_err_t i2c_ssd1306_buffer_to_ram(i2c_ssd1306_handle_t *i2c_ssd1306);