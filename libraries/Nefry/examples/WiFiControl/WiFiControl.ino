#include<Nefry.h>
void setup() {
  Nefry.addWiFi("SSID", "Password"); //WiFiの保存をします。
  Nefry.println(Nefry.getWiFiList());//保存されているWiFiリストを表示します。
  Nefry.deleteWiFi(1);//保存されているWiFiリストを削除します。
  Nefry.println(Nefry.getWiFiList());//保存されているWiFiリストを表示します。
  Nefry.saveWiFi();//この関数で今までの変更を保存します
}

void loop() {
}
