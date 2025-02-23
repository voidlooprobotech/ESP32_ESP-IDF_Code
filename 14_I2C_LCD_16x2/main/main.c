#include <stdio.h>
#include "driver/i2c.h"
#include "i2c_lcd.h"


void app_main(void)
{
    lcd_init();                             // Initialize the LCD
    lcd_clear();                            // Clear the LCD screen

    lcd_put_cursor(0, 0);                   // Set the cursor position to the first row, first column
    lcd_send_string("Hello world!");        // Display the string "Hello world!!!" on the LCD
    lcd_put_cursor(1, 0);                   // Set the cursor position to the second row, first column
    lcd_send_string("from @voidlooop");     // Display the string "from @voidlooop" on the LCD
}
