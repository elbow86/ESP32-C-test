// Raw SPI test - bypasses TFT_eSPI library completely
#include <SPI.h>

#define TFT_CS   15
#define TFT_DC   2
#define TFT_RST  4
#define TFT_MOSI 23
#define TFT_SCLK 18

SPIClass spi = SPIClass(VSPI);

void writeCommand(uint8_t cmd) {
  digitalWrite(TFT_DC, LOW);   // Command mode
  digitalWrite(TFT_CS, LOW);
  spi.transfer(cmd);
  digitalWrite(TFT_CS, HIGH);
}

void writeData(uint8_t data) {
  digitalWrite(TFT_DC, HIGH);  // Data mode
  digitalWrite(TFT_CS, LOW);
  spi.transfer(data);
  digitalWrite(TFT_CS, HIGH);
}

void setup() {
  Serial.begin(115200);
  delay(1000);
  Serial.println("\n=== RAW SPI TEST ===\n");
  
  // Setup pins
  pinMode(TFT_CS, OUTPUT);
  pinMode(TFT_DC, OUTPUT);
  pinMode(TFT_RST, OUTPUT);
  pinMode(27, OUTPUT);  // Backlight
  
  digitalWrite(TFT_CS, HIGH);
  digitalWrite(TFT_DC, HIGH);
  digitalWrite(27, HIGH);  // Backlight ON
  
  // Hardware reset
  Serial.println("Hardware reset...");
  digitalWrite(TFT_RST, HIGH);
  delay(10);
  digitalWrite(TFT_RST, LOW);
  delay(100);
  digitalWrite(TFT_RST, HIGH);
  delay(200);
  
  // Init SPI
  spi.begin(TFT_SCLK, -1, TFT_MOSI, TFT_CS);
  spi.setFrequency(10000000);  // 10MHz
  spi.setDataMode(SPI_MODE0);
  spi.setBitOrder(MSBFIRST);
  Serial.println("SPI initialized");
  
  // Try multiple display initialization sequences
  
  Serial.println("\nTrying ILI9488 init...");
  writeCommand(0x01); // Software reset
  delay(150);
  writeCommand(0x11); // Sleep out
  delay(150);
  writeCommand(0x3A); // Pixel format
  writeData(0x55);    // 16-bit
  writeCommand(0x29); // Display on
  delay(100);
  Serial.println("ILI9488 init sent");
  
  // Try to fill screen with red
  Serial.println("Attempting to draw red screen...");
  writeCommand(0x2A); // Column address
  writeData(0x00); writeData(0x00);
  writeData(0x01); writeData(0x3F); // 320
  
  writeCommand(0x2B); // Row address
  writeData(0x00); writeData(0x00);
  writeData(0x01); writeData(0xDF); // 480
  
  writeCommand(0x2C); // Memory write
  digitalWrite(TFT_DC, HIGH);
  digitalWrite(TFT_CS, LOW);
  
  // Send red pixels
  for(int i=0; i<320*480; i++) {
    spi.transfer16(0xF800); // Red in RGB565
    if(i % 10000 == 0) {
      Serial.print(".");
    }
  }
  digitalWrite(TFT_CS, HIGH);
  Serial.println("\nRed screen data sent");
  
  delay(2000);
  
  // Try HX8357D init
  Serial.println("\nTrying HX8357D init...");
  writeCommand(0x01); // Software reset
  delay(150);
  writeCommand(0x11); // Sleep out
  delay(150);
  writeCommand(0x3A); // Pixel format
  writeData(0x55);    // 16-bit
  writeCommand(0x36); // Memory access
  writeData(0x48);
  writeCommand(0x29); // Display on
  delay(100);
  Serial.println("HX8357D init sent");
  
  Serial.println("\n=== INIT COMPLETE ===");
  Serial.println("If display is still white:");
  Serial.println("1. Check if display has IM0-IM3 jumpers (must be set for 4-wire SPI)");
  Serial.println("2. Physically verify CS pin 15 connection with multimeter");
  Serial.println("3. Physically verify DC pin 2 connection with multimeter");
  Serial.println("4. Check if display needs 5V logic levels");
}

void loop() {
  delay(1000);
  Serial.print(".");
}
