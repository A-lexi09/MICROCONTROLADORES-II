#include <Wire.h>
#include <LiquidCrystal_I2C.h>

LiquidCrystal_I2C lcd(0x27, 16, 2);  // Cambia a la dirección que encontraste

String mensaje = "ES EL MEJOR INGENIERO";
int scrollPos = 0;

void setup() {
  lcd.init();
  lcd.backlight();
}

void loop() {
  lcd.clear();
  lcd.setCursor(0, 0);
  lcd.print(mensaje.substring(scrollPos, scrollPos + 16));
  scrollPos++;
  if (scrollPos > mensaje.length() - 16) {
    scrollPos = 0;
    delay(2000);  // Pausa al final del mensaje
  }
  delay(600);  // Velocidad del scroll
}
