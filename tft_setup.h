// Per-sketch TFT_eSPI setup for ESP32-3248S035 integrated board
#define USER_SETUP_INFO "ESP32 XH-32S ILI9341"

#define ILI9341_DRIVER  // Try ILI9341 driver
#define TFT_WIDTH  320
#define TFT_HEIGHT 480

// VSPI pins
#define TFT_MISO 19
#define TFT_MOSI 23
#define TFT_SCLK 18

// Control pins
#define TFT_CS   15
#define TFT_DC    2
#define TFT_RST   4

// Backlight
#define TFT_BL   27
#define TFT_BACKLIGHT_ON HIGH

// Common colour order
#define TFT_RGB_ORDER TFT_BGR

// SPI speed
#define SPI_FREQUENCY  20000000
#define SPI_READ_FREQUENCY 16000000
