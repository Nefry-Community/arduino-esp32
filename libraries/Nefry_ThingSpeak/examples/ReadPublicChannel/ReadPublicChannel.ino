#include<NefryThingSpeak.h>
/**
 * ReadPrivate
 * ThingSpeakから公開データを取得します
 */
void setup() {
  //初期設定
  //DataStoreで設定するパターン
  NefryThingSpeak.begin();
  NefryThingSpeak.setReadAPIKey();
  //直接キー情報を入力するパターン
  //  NefryThingSpeak.begin(100);//channel番号
  //  NefryThingSpeak.setReadAPIKey("ReadKey");//ReadKey情報を入力します
}

void loop() {
  //読み込みたいチャンネルを設定する
  float readValue = ThingSpeak.readFloatField(NefryThingSpeak.getChannelNumber(), 1);
  //データを取得できた場合に表示する
  int resultCode = NefryThingSpeak.getLastReadStatus();
  if (resultCode == 200)
  { //正常データを取得できた場合に表示する
    Serial.print("Latest message is: ");
    Serial.println(readValue);
  }
  else
  { //データを取得できなかった場合に表示する
    Serial.print("Error reading message.  Status was: ");
    Serial.println(resultCode);
  }

  delay(30000);
}
