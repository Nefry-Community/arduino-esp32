# このノートはNefry(ESP32版)のリリースノートになります。

## 1.1.5 (2018/05/05)

Nefryライブラリ1.2.2 までの対応をマージしました。
[6826508](https://github.com/Nefry-Community/arduino-esp32/commit/68265084b1681075f8c60ea47e1d4b8f9f68c91c)まで対応 2018/05/02まで対応

## 1.2.2 (2018/04/21)

NefryBTr3の仕様変更に対応しました。
MDNS対応やサンプルコードの追加を行いました。

新規機能

- LINE Notifyライブラリを追加しました。
- MDNS対応しました。(http://nefrybt.local)で接続できます。
- サンプルコードの追加を行いました。

バグ修正

- Nefry BT r3の仕様変更に伴いライブラリの修正を行いました。
- Azureライブラリの更新を行いました。
- チュートリアル本のサンプルコードを更新しました。

## 1.2.1 (2018/03/16)

NefryBTr3に対応しました。それに伴い多数のバグ、新規機能が追加されました。

新規機能

- Nefry BT r3に対応しました。
- Nefryチュートリアル本のサンプルコードを同封しました。
- Nefry BT r3対応に伴い、LED周りの制御を調整しました。

バグ修正

- ディスプレイダイアログのタイトルを編集できるようになりました。
- ThingSpeakライブラリを調整しました。
- Nefry BT r2以降でディスプレイとI2Cが共存できない問題を修正しました。

## 1.2.0 (2018/01/13)

1.0.9をベースに現状の1.1.4までのコードを反映しました。
これ以降、マイナーバージョンが偶数(例：1.2.1 1.6.4 など)を安定版。奇数なら開発版としていきます。 

## 1.1.4 (2018/01/06)

1.1.3 のバグ修正、[70d0d46](https://github.com/Nefry-Community/arduino-esp32/commit/70d0d4648766cea047613062ed50a9ecfc9de31f)まで対応 2017/12/

新規機能

- [@bluetone](https://twitter.com/bluetoneinfo)さんからのプルリクでディスプレイ制御関数が追加されました。
- ESP32ライブラリ[70d0d46]まで対応

バグ対応

- コンパイラ座標を修正
- [@n0bisuke](https://twitter.com/n0bisuke)さんからのプルリクで表示バグが修正されました

## 1.1.3 (2017/11/26)

設定機能関数の追加、ネットワーク設定変更の対応

新規対応

- 設定機能関数の追加
- WiFi無効化機能の追加 [@m2wasabiさん](https://github.com/m2wasabi)からのプルリクありがとうございます。
- ESP32ライブラリ[a907113](https://github.com/Nefry-Community/arduino-esp32/commit/a907113ba2c67d2dc3785b1ef93e5ab298d82412)まで対応 2017/11/25まで対応

## 1.1.2 (2017/11/26)

デバック版

## 1.1.1 (2017/10/31)

###注意
このバージョンは仮リリースとなります。
captive portalが正常に動作しませんが、BLEを扱えることを優先します。

新規対応

- ESP32ライブラリ[081ca1c]まで対応 2017/10/30まで対応

バグ対応

- BLEライブラリの動作確認

## 1.1.0 (2017/10/28)

BLEサポート、ESP32ライブラリ[0768590]10月25日まで対応

新規対応

- BLEサポート
- ESP32ライブラリ[0768590]
- EddystoneとiBeacon互換対応
- Nefry BT r2追加

## 1.0.9

Nefry BT r2対応

新規対応

- ボード追加

バグフィックス

- ディスプレイ表示でのバグを修正

## 1.0.8
ディスプレイスクロール対応 [@ctw_yamada](https://twitter.com/ctw_yamada)さんのプルリクありがとうございます。


新規対応

- ディスプレイスクロール対応
- ディスプレイ表示関数対応、サンプルコード追加


## 1.0.7
ライブラリバグ対応


バグ対応

- ライブラリバグ対応


## 1.0.6
ThingSpeakライブラリ、FastSensingライブラリを新規追加


新規対応

- ThingSpeakライブラリ追加
- FastSensingライブラリ追加


## 1.0.5
BLE仮サポート


新規対応

- BLEライブラリ追加

バグフィックス

- ピンアサインを修正
- BLEサポートのためメモリ領域を変更

## 1.0.4
NefryBTライブラリのバグフィックス


新規対応

- ESP32ライブラリ(9edf65d)(9/9まで)対応
- FireBaseライブラリ追加

バグフィックス

- LED制御を修正
- IFTTTライブラリの表示を変更
- GPIOのErrataを修正
- Azure IoTHubのライブラリを修正
- ボードの設定を変更


## 1.0.3
NefryBTライブラリのバグフィックス

バグフィックス

- アップデート時にプログレスバーを表示するように修正
- 表記ミスを修正
- IFTTTライブラリのログ表示
- コンパイルエラー修正
- タスク処理を変更

## 1.0.2
デバッグ用イメージ

## 1.0.1
Nefry BTライブラリをGitの最新にマージ、esptoolの更新

新規対応

- esptool a420774対応
- ESP32ライブラリ(41e36a7)(8/4まで)対応

バグフィックス

- NefryBTが起動しなくなるバグの修正

## 1.0.0
NefryBTリリースに伴いメジャーアップデート

バグフィックス

- Webページのミスを修正


## 0.9.6
2つのバグフィックス

バグフィックス

- ピン指定が間違っていたのを修復
- Console機能の有効化

## 0.9.5
コンパイラ周りの調整

バグフィックス

- WebServerがうまく動作しなかった件の修正


## 0.9.4

ESP32ライブラリ更新(d8330cc)(2017/7/17まで)
JavaScriptで制御ができるFirmata対応

新規機能

- 下位互換対応のため以下の関数追加
getlistWiFi
createHtml
setIndexLink
getDisplayInfo
getWebServer
getConfStr
setConfHtmlStr
setConfStr
setStoreTitleStr
getConfValue
setConfHtmlValue
setConfValue
setStoreTitleValue
getModuleName


## 0.9.3

ESP32ライブラリ更新(13bb22d)(2017/7/7まで)
JavaScriptで制御ができるFirmata対応

新規機能

- Firmata対応

## 0.9.2

ディスプレイ制御対応

新規機能

- ディスプレイ制御機能

バグフィックス

- Mac対応

## 0.9.1

ESP32ライブラリ更新(839318c)(2017/6/21まで)
ライブラリ追加

新規機能

- Ambientライブラリ追加
- AzureIoTHubライブラリ追加

## 0.9.0

NefryのOTA機能の追加
URLでアップデートする機能は未実装

新規機能

-  NefryのOTA機能の追加、それに関連する関数の追加

## 0.8.0

NefryのWebConsole機能の追加

新規機能

-  WebConsole機能の追加、それに関連する関数の追加
- print,println,read,available,clearConsole関数の追加

## 0.7.2

0.7.1で修正した内容を破棄

バグフィックス

- コンパイラ環境の復元

## 0.7.1

コンパイル環境のesptoolがうまく動作しなかったため修正

バグフィックス

- コンパイラ環境の修正

## 0.7.0

NefryのModule設定機能の追加

新規機能

- モジュール情報設定機能
- esp32/arduino[3b86e0c]コミットまでマージ
- サンプルプログラムを追加


## 0.6.2

NefryのWeb関連機能の修正とDNSの追加、それに伴う起動シークエンスの変更

新規機能

- DNS対応
- CaptivePortal対応
- webserver更新

バグフィックス

- 起動シークエンスの変更

## 0.6.1

IFTTTライブラリー追加とバグフィックス対応

新規機能

- IFTTTライブラリー追加

バグフィックス

- ボード名変更　Nefry BT
- 関数名変更　storageとstoreがあったためStoreに統一
- SWの処理を変更

## 0.6.0
Data Store機能の追加

新規機能

- Data Store機能の追加
- setStoreTitle関数の追加

バグフィックス

- メイン処理の変更
- 初回起動時の処理の修正
- スイッチ関連関数の修正
- Data Store機能のデータのキャッシュ機能の追加
- WiFi機能の修正


## 0.5.4
WiFi関連のバグフィックス

機能
- WiFi関連機能のバグフィックス
- 関数追加
	- saveWiFi
	- addWiFi
	- deleteWiFi

## 0.5.3
書き込み時にパスが通らなくなってしまったためその修正

機能
- コンパイルオプションの変更

## 0.5.2
コンパイルが通らなくなってしまったためその修正

機能
- コンパイルオプションの変更

## 0.5.1
Nefry Icingボードを追加。

機能
- ボードの追加


## 0.5.0
NefryのベースとなるWebserver機能、WiFi設定機能を搭載した初回リリース。

機能
- ESP32 Arduino公式までをマージ(https://github.com/espressif/arduino-esp32/commit/2b075f320477278be0eec55a34de9eca19426019)
- 公式が出すまでの仮バージョンのWebServerを追加
- WiFiの設定機能を追加
- 最低限のデータ管理システムとRGBLED制御などNefryとしての機能を追加
- RTOSの機能によりwebserverとボタン確認機能を追加

