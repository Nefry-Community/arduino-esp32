# Arduino core for ESP32 WiFi chip and NefryLibrary
[![Build Status](https://travis-ci.org/Nefry-Community/arduino-esp32.svg?branch=master)](https://travis-ci.org/Nefry-Community/arduino-esp32)

[Arduino core for ESP32 WiFi chip](https://github.com/espressif/arduino-esp32)をベースにして開発しています。
NefryBTはArduinoIDEで開発することができる開発ボードになります。

## 開発環境を整える

NefryBTのArduinoIDEでの開発環境は詳しくはこちらを参照していただくと整えることができます。
ArduinoIDEの設定欄に入れるURLは開発版と安定版の2つがあります。
開発版の方が先行してアップデートされますが、バグがある可能性は高いので問題ない方のみ入力してください。

### 安定版

```
http://nefry.studio/package_nefrybt_index.json
```

### 開発版

```
http://nefry.studio/develop/package_devnefrybt_index.json
```


## 開発について
NefryBTは適宜バージョンアップをしてArduinoIDEのボードマネージャーからインストールすることができます。
最新の機能についてはこのレポジトリを参照していただくことで試すことができます。
### 導入方法
他の方法もありますが、おすすめなのはArduinoIDEに上の手順でインストールし、一度インストールしたフォルダを置き換える手順がお勧めです。
1. ArduinoIDEの設定欄より、NefryBTライブラリがインストールされている場所を探します。
2. そのフォルダにpackegeフォルダがあります。下記に書いたパスを順に下ってください。
```packages/Nefry(ESP32)/hardware/esp32/1.0.1 ```(末端のパスはインストールしたバージョンによって異なります。)
3. 適切なパスに移動できると、coreフォルダやlibraryフォルダがあることを確認したうえでそのフォルダの中身をまるごと消去してください。
4. 消去ができたら、このレポジトリをそのバージョンフォルダにクローンすることで最新のレポジトリを参照することができます。

## リンク

- [Facebookグループ](https://www.facebook.com/nefrystudio/) 
- [質問等についてはこちら](https://teratail.com/tags/Nefry) 
- [NefryBTドキュメント](https://dotstud.io/docs/nefrybt/) 
- [NefryBT説明書](https://drive.google.com/file/d/0B_mvDQF8yaQRLVprUHl4WTFLWVE/view) 

## エラーデコーダー

[EspExceptionDecoder](https://github.com/me-no-dev/EspExceptionDecoder) エラーデコーダはこちらからダウンロードできます。

## NefryBT Board PINMAP

![Pin Functions](https://nefry.studio/img/nefrybt_pinmap.png)

## リリースノート

リリースノートは[こちら](https://github.com/Nefry-Community/arduino-esp32/blob/master/release%20note.md)
