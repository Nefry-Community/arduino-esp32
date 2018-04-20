#include <NefryIFTTT.h>
  #include <NefryLineNotify.h>
  #include <WiFiClientSecure.h>

  String Event, SecretKey, LineAuth, SendMessageLINE;

  void setup() {
    Nefry.setStoreTitle("SecretKey", 0); //Nefry DataStoreのタイトルを指定
    Nefry.setStoreTitle("Event", 1);    //Nefry DataStoreのタイトルを指定
    Nefry.setStoreTitle("LINE Auth", 2); //Nefry DataStoreのタイトルを指定
    Nefry.setStoreTitle("LINEMessage", 3);    //Nefry DataStoreのタイトルを指定

    SecretKey = Nefry.getStoreStr(0);   //Nefry DataStoreからデータを取得
    Event = Nefry.getStoreStr(1);       //Nefry DataStoreからデータを取得
    LineAuth = Nefry.getStoreStr(2);   //Nefry DataStoreからデータを取得
    SendMessageLINE = Nefry.getStoreStr(3);       //Nefry DataStoreからデータを取得

    Nefry.enableSW();                   //スイッチ有効化
    Nefry.setProgramName("NefryBT Default Program");//プログラム名登録
  }

  void loop() {
    if (Nefry.readSW()) {               //スイッチを押した時
      if (!SecretKey.equals("") && !Event.equals("")) {
        if (!IFTTT.send(Event, SecretKey)) {//IFTTTにデータを送信
          Nefry.setLed(255, 0, 0);        //Errの時、赤色点灯
        }
      }
      if (!LineAuth.equals("")) {
        if (SendMessageLINE.equals(""))
          SendMessageLINE = "Welcome to the NefryBT world!";
        LineNotify.send(L
        FeineAuth,SendMessageLINE);        //LINE送信
      }
      delay(1000);               //送信後1秒間待つ
    }
    Nefry.setLed(random(255), random(255), random(255));
    delay(500);               //送信後0.5秒間待つ
  }
