#include <LiquidCrystal.h>
#include <LiquidCrystal_I2C.h>

#include <Wire.h>

LiquidCrystal_I2C lcdekranim(0x27, 16, 2);

void setup()
{
  lcdekranim.init();
  lcdekranim.backlight();
  lcdekranim.setCursor(0, 0);
  lcdekranim.print("Giris Ekrani");
  delay(1000);
  lcdekranim.clear();
}

void loop()
{
  for (int x = 0; x <= 16; x++)
  {
    lcdekranim.setCursor(x, 0);
    lcdekranim.print("Internet of Things Dersi Semih ");
    delay(500);
    lcdekranim.clear();
  }
  for (int e = 16; e >= 0; e--)
  {
    lcdekranim.setCursor(e, 0);
    lcdekranim.print("Internet of Things Dersi Semih ");
    delay(500);
    lcdekranim.clear();
  }


}
