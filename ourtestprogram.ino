#include <TFT_eSPI.h>
TFT_eSPI tft;

void setup() {
  Serial.begin(115200);
  delay(500);

  // Backlight ON
  pinMode(27, OUTPUT);
  digitalWrite(27, HIGH);

  // Init display
  tft.init();
  tft.setRotation(1);  // Landscape mode: 480x320
  tft.fillScreen(TFT_BLUE);
  
  Serial.println("Display initialized");
  Serial.print("Width: "); Serial.println(tft.width());
  Serial.print("Height: "); Serial.println(tft.height());

  // Draw a white rectangle where text should be
  tft.fillRect(90, 120, 300, 80, TFT_WHITE);
  delay(1000);
  
  // Now draw text on blue background
  tft.fillScreen(TFT_BLUE);
  tft.setTextColor(TFT_YELLOW, TFT_BLUE);
  tft.setTextSize(4);
  tft.drawString("HELLO!", 100, 130);
  
  tft.setTextSize(2);
  tft.drawString("Display Working!", 120, 180);
  
  Serial.println("Graphics drawn!");
}

void loop() {
}
