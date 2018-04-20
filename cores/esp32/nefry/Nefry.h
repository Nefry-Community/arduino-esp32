#ifndef Nefry_h
#define Nefry_h

#include <Esp.h>
#include "./inc/led/Adafruit_NeoPixel.h"
#include "./inc/Preferences/src/Preferences.h"
#include "NefryWiFi.h"
#include "./NefryDataStore.h"
#include "NefryConfig.h"
#include "NefryConsole.h"
#include "NefryDisplay.h"
#include "NefryWeb.h"
#include "NefryWebServer.h"
#include "./inc/WiFi/src/WiFiClient.h"
#include "./inc/ESPmDNS/src/ESPmDNS.h"


// Offset:         W          R          G          B
#define NEO_RGB  ((0 << 6) | (0 << 4) | (1 << 2) | (2))
#define NEO_RBG  ((0 << 6) | (0 << 4) | (2 << 2) | (1))
#define NEO_GRB  ((1 << 6) | (1 << 4) | (0 << 2) | (2))
#define NEO_GBR  ((2 << 6) | (2 << 4) | (0 << 2) | (1))
#define NEO_BRG  ((1 << 6) | (1 << 4) | (2 << 2) | (0))
#define NEO_BGR  ((2 << 6) | (2 << 4) | (1 << 2) | (0))
void getNefryDisplayInfo();

class Nefry_lib
{
public:

	bool
		setModuleID(String id),
		setModulePass(String pass),
		setModuleClass(String className),
		setUser(String user),
		setUserPass(String pass),
		setStoreValue(long value,const int pointer),
		setStoreStr(String str,const int pointer),
		getWriteMode(),
		readSW(),
		getPollingSW(),
		getWifiEnabled(),
		getDisplayStatusEnabled();
		
	String
		getModuleID(),
		getModuleClass(),
		getUser(),
		getStoreStr(const int pointer),
		getVersion(),
		getProgramName(),
		getAddressStr(IPAddress ip),
		getDefaultModuleId(),
		/* Console */
		read(),
		
		getlistWifi(),
		createHtml(String title, String head, String body);

	long
		getStoreValue(const int pointer),
		getBootMode();

	int
		/* Console */
		available(),
		getNefryState();
	void
		reset(),
		sleep(const int sec),
		setProgramName(const char * pn), 
		beginLed(const int num, const int dataOut, uint8_t t = 0, const int clk = -1),
		setLed(const int r, const int g, const int b, const char w = 80, const int pin = 16, const int num = 0),
		setLed(String _colorStr, const char w = 122, const int pin = 16, const int num = 0),
		addWiFi(String ssid, String pass),
		deleteWiFi(const int id),
		saveWiFi(),
		nefry_init(),
		nefry_loop(),
		ndelay(unsigned long ms),

		setStoreTitle(const char set[15], const int num),

		enableSW(),
		disableSW(),

		enableWifi(),
		disableWifi(),

		enableDisplayStatus(),
		disableDisplayStatus(),

		/* Pollingでスイッチの状態をチェック */
		pollingSW(),

		/* Console機能追加 */
		clearConsole(),

		println(float text),
		println(double text),
		println(char text),
		println(int text),
		println(long text),
		println(unsigned char text),
		println(unsigned int text),
		println(unsigned long text),
		print(float text),
		print(double text),
		print(char text),
		print(int text),
		print(long text),
		print(unsigned char text),
		print(unsigned int text),
		print(unsigned long text),
		print(String text),
		println(String text),

		setIndexLink(const char title[32], const char url[32]),
		printDeviceInfo(),

		setNefryState(int state),
		setLedBlink(int red, int green, int blue, bool EN, int wait),
		LedBlinkTask();

		ESP32WebServer* getWebServer();

		//下位互換

	String getConfStr(const int num){
		return getStoreStr(num);
	}
	void setConfHtmlStr(const char set[15], const int num){
		setStoreTitle(set,num);
	}
	void setConfStr(const char *pt, const int num){
		setStoreStr(pt,num);
	}
	void setStoreTitleStr(const char set[15], const int pt) {
		setStoreTitle(set, pt);
	}
	int getConfValue(const int num){
		return getStoreValue(num+10);
	}
	void setConfHtmlValue(const char set[15], const int num){
		setStoreTitle(set,num+10);
	}
	void setConfValue(const int pt, const int num){
		setStoreValue(num,pt+10);
	}
	void setStoreTitleValue(const char set[15], const int pt) {
		setStoreTitle(set, pt+10);
	}
	String getModuleName(){
		return getModuleID();
	}


private:
	bool
		_swEnableFlg = false,/* SWの有効無効化 */
		_swflg = false, /* SWの状態を保持 */
		_swPushingflg = false,
		_wifiEnableFlg = true,/* Wi-Fiの有効無効化 */
		_displayStatusFlg = true;/* ディスプレイの状態表示の有効無効化 */

	bool setAnalyticsData(String action);
		
	int 
		_bootMode = -1,	/* Boot状態を管理　-1:初期化中 0:起動中 1:通常起動 2:書き込みモード */
		hextonum(char c),
		_nefryState = 0,
		_nefryWifiWait;
	int _nefryLedBlinkState[5];
	const char * program;
};
extern Nefry_lib Nefry;
#endif