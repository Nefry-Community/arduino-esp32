#include <Nefry.h>
#include <NefryDisplay.h>
//フルカラーLED　順番に色が変わります。
void setup() {
  Nefry.setProgramName("FullColorLED"); //プログラム名を管理することができます。
}
void loop() {
  NefryDisplay.print("Red");
  Nefry.setLed(255, 0, 0);       //LEDが赤色に点灯します。
  delay(5000);                          //5秒待つ
  NefryDisplay.print("Green");
  Nefry.setLed(0, 255, 0);       //LEDが緑色に点灯します。
  delay(5000);                          //5秒待つ
  NefryDisplay.print("Blue");
  Nefry.setLed(0, 0, 255);       //LEDが青色に点灯します。
  delay(5000);                          //5秒待つ
  NefryDisplay.print("OFF");
  Nefry.setLed(0, 0, 0);         //LEDが消灯します。
  delay(5000);                          //5秒待つ
}