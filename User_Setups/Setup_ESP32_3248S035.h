// Setup_ESP32_3248S035.h

#define ILI9488_DRIVER       // Try ILI9488 again with different settings
//#define ST7796_DRIVER

#define TFT_WIDTH  320
#define TFT_HEIGHT 480

// SPI pins
#define TFT_MISO 12  // Try different MISO pin for C variant
#define TFT_MOSI 13  // Try different MOSI pin
#define TFT_SCLK 14  // Try different SCLK pin

// Control pins 
#define TFT_CS   15
#define TFT_DC    2
#define TFT_RST   4

// Backlight pin (your hardware uses GPIO27)
#define TFT_BL   27
#define TFT_BACKLIGHT_ON HIGH

// Many ILI9488 boards are more reliable at <= 20MHz
#define SPI_FREQUENCY  20000000

// Common colour order for ILI9488 breakout boards
#define TFT_RGB_ORDER TFT_BGR

// Load fonts
#define LOAD_GLCD   // Font 1. Original Adafruit 8 pixel font needs ~1820 bytes in FLASH
#define LOAD_FONT2  // Font 2. Small 16 pixel high font, needs ~3534 bytes in FLASH, 96 characters
#define LOAD_FONT4  // Font 4. Medium 26 pixel high font, needs ~5848 bytes in FLASH, 96 characters
#define LOAD_FONT6  // Font 6. Large 48 pixel font, needs ~2666 bytes in FLASH
#define LOAD_FONT7  // Font 7. 7 segment 48 pixel font
#define LOAD_FONT8  // Font 8. Large 75 pixel font
#define LOAD_GFXFF  // FreeFonts

#define SMOOTH_FONT
