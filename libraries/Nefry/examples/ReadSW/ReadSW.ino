#include <Nefry.h>
void setup() {
}
void loop() {
  //SWを押した時にLEDが赤色に点灯する
  if(Nefry.readSW()){
    //押した時
    //赤色になる（r,g,b）の順で色を指定できる
    Nefry.setLed(0,0,255);
    Nefry.println("Push SW");
  }else{
    //離した時
    Nefry.setLed(255,0,0);
  }
  delay(100);
}
