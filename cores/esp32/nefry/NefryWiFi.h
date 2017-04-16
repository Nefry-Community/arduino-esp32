#ifndef NefryWiFi_h
#define NefryWiFi_h

#include "./inc/WiFi/src/WiFiMulti.h"
#include "Nefry.h"
#include "./inc/Preferences/src/Preferences.h"
#include"NefryWeb.h"
#include "NefryWebServer.h"

class Nefry_WiFi
{
public:
	void
		begin(),
		addWifi(String ssid, String pwd),
		deleteWifi(int id),
		setWifiTimeout(int count),
		setWifiTimeoutClear(),
		saveWifi();

	int 
		run(),
		getWifiTimeout();

	String beginWeb(String s),
		getlistWifi();



private:

	WiFiMulti wifiMulti;
	String network_html, network_list;
	void
		scanWiFi(),
		dataCache();
		
	String escapeParameter(String param),
		_nefryssid[5], _nefrypwd[5];

	int 
		sortWifi(),
		_WifiTimeOutCountMax,
		_WifiTimeOutCount = 0;
};
extern Nefry_WiFi NefryWiFi;
#endif
