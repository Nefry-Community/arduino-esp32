#include <Nefry.h>
#include <NefryLineNotify.h>
String auth, message;

void setup() {
  Nefry.setStoreTitle("Auth",0); //Nefry DataStoreのタイトルを指定
  Nefry.setStoreTitle("Message",1);     //Nefry DataStoreのタイトルを指定
  auth = Nefry.getStoreStr(0);   //Nefry DataStoreからデータを取得
  message = Nefry.getStoreStr(1);       //Nefry DataStoreからデータを取得
  Nefry.enableSW();                   //SW有効化
}
 
void loop() {
  if (Nefry.readSW()) {               //SWを押した時
    if (!LineNotify.send(auth, message)) {//IFTTTにデータを送信
      Nefry.setLed(255, 0, 0);        //Errの時、赤色点灯
    }
    Nefry.ndelay(1000);               //送信後1秒間待つ
  }
}
