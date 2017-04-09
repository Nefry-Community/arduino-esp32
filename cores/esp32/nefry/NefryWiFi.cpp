/**
Nefry lib

Copyright (c) 2016 wami

This software is released under the MIT License.
http://opensource.org/licenses/mit-license.php
*/

/*
ConnectSSID	: Nefry���ڑ�����WiFi��SSID��ۑ�����Ƃ��Ɏg�p����B5�܂ŕۑ��B���[�ɐ������ǉ������ String�^ null�����̎����X�g�ɒǉ����Ȃ�
ConnectPass	: Nefry���ڑ�����WiFi�̃p�X���[�h��ۑ�����Ƃ��Ɏg�p����B5�܂ŕۑ��B���[�ɐ������ǉ������ String�^
ConnectWiFi : �ڑ�����WiFi��L��or����������
*/

#include "NefryWiFi.h"
Preferences wifiPreferences;
bool wifiEnable[5];

bool initflgWifi = false;
void Nefry_WiFi::begin() {
	deleteWifi(0);
	wifiMulti = WiFiMulti();
	scanWiFi();								//WiFi���������AWeb�y�[�W�ɕ\������
	setWifiTimeout(0);//�������Ŏ����ڑ�����
	Serial.println("Saved WiFi List");
	Serial.println(getlistWifi());
	WiFi.persistent(false);
	WiFi.mode(WIFI_AP_STA);
	deleteWifi(0);
	for (int i = 0; i < 5; i++) {
		if (!NefryDataStore.getConnectSSID(i).equals("")) {
			wifiMulti.addAP(NefryDataStore.getConnectSSID(i).c_str(), NefryDataStore.getConnectPass(i).c_str());
		}
	}
	wifiMulti.addAP("NefryWiFi", "NefryWiFi");
	Serial.println(F("WiFi initialized"));
	initflgWifi = true;
	Serial.println(F("Waiting for WiFi to connect"));
	delay(20);
	int loopCounter = 0;
	while(1){
		run();
		if (loopCounter % 2) {
			Nefry.setLed(0, 0, 0xFF);
		}
		else {
			Nefry.setLed(0, 0, 0, (char)0);
		}
		delay(100);
		loopCounter++;
		Serial.print(".");
		if (loopCounter >= 30)break;
		if (WiFi.status() == WL_CONNECTED)break;
	}
	if (WiFi.status() == WL_CONNECTED) {
		Nefry.setLed(0, 100, 100);
		Serial.println("SSID : ");
		Serial.println(WiFi.SSID());
		Serial.print("IP address: ");
		Serial.println(WiFi.localIP());
	}
	else {
		Nefry.setLed(200, 0, 0);
	}
	
	/* Nefry�����M����WiFi�̐ݒ�*/
	if ( NefryDataStore.getBootSelector()== 1 || NefryDataStore.getModulePass().length() == 0) {
		WiFi.softAP(NefryDataStore.getModuleID().c_str());
		Serial.println(F("\nWaiting for WiFi to connect"));
	}
	else {
		WiFi.softAP(NefryDataStore.getModuleID().c_str(), NefryDataStore.getModulePass().c_str());
	}
	setWifiTimeout(6);//6��ڂŎ����ڑ����^�C���A�E�g����
	setWifiTimeoutClear();
	delay(1000);
}

uint8_t prevWifiStatus = WL_IDLE_STATUS;
int Nefry_WiFi::run() {
	/*
run�֐��ŕԂ��l

-1	:�s���ȃG���[
0	:�ڑ��ς�
1	:�����ڑ����Ȃ�
2	:�^�C���A�E�g
3	:�l�b�g���[�N�A�C�h����
4	:SSID���o�ł���
5	:��������
6	:�ڑ��G���[
7	:�ؒf

*/
	if (initflgWifi == false)return 1;
	if (getWifiTimeout() == -1)return 1;
	if (getWifiTimeout() !=0 && getWifiTimeout() >= _WifiTimeOutCount)return 2;
	uint8_t wifiStatus = wifiMulti.run();
	if (prevWifiStatus != wifiStatus) {
		prevWifiStatus = wifiStatus;
		if (wifiStatus == WL_CONNECTED) {
			_WifiTimeOutCount = 0;
			Serial.println("WiFi connected");
			Serial.println("SSID: ");
			Serial.println(WiFi.SSID());
			Serial.println("IP address: ");
			Serial.println(WiFi.localIP());
			return 0;
		}
		prevWifiStatus = wifiStatus;
		_WifiTimeOutCount++;
		Serial.print(F("WiFi errorCode : "));
		switch (wifiStatus)
		{
		case WL_IDLE_STATUS:
			Serial.println(F("Network Idle"));
			return 3;
			break;
		case WL_NO_SSID_AVAIL:
			Serial.println(F("SSID Not Found"));
			return 4;
			break;
		case WL_SCAN_COMPLETED:
			Serial.println(F("Scan Complete"));
			return 5;
			break;
		case WL_CONNECT_FAILED:
			Serial.println(F("Connect Failed"));
			return 6;
			break;
		case WL_CONNECTION_LOST:
			Serial.println(F("Connection Lost"));
			return 7;
			break;
		case WL_DISCONNECTED:
			Serial.println(F("Disconnected"));
			return 7;
			break;
		default:
			break;
		}
	}
	return -1;
}

String Nefry_WiFi::beginWeb(String url)
{
	if (url.equals("wifi_conf")) {
		String content = F(
			"<h1>Nefry Wifi Set</h1>"
			"<form  name=\"myForm\" method='get' action='set_wifi'><div class=\"row\"> <label for=\"ssid\">SSID: </label> <div> <input name=\"ssid\" id=\"ssid\" maxlength=\"32\"list=\"network_list\" value=\"\"> </div></div>"
			"<div class=\"row\"> <label for=\"pwd\">PASS: </label> <div> <input type=\"password\" name=\"pwd\" id=\"pwd\"maxlength=\"64\"> </div></div>"
			"<div class=\"footer\">");
		if (_WifiTimeOutCount >= _WifiTimeOutCountMax) {
			//println(_WifiTimeOutCountMax);
			//println(_WifiTimeOutCount);
			content += F("<button type=\"button\"onclick=\"location.href='/wifiCount'\">WiFiAutoConnectionCount Clear</button>");
		}
		content += F("<button type=\"button\"onclick=\"location.href='/wifiReload'\">Reload</button><input type=\"button\"value=\"Sava\"onclick=\"return jsSubmit(this.form);\"></div></form><a href=\"/\">Back to top</a></div><div>");
		content += network_html;
		content += network_list;
		content += F("</div><div><h1>Saved WiFi List</h1><p>Delete WiFi Select</p><form  name=\"myForm\" method='get' action='delete_wifi'>");
		for (int i = 0; i < 5; i++) {
			if (!NefryDataStore.getConnectSSID(i).equals("")){
				content += F("<input type=\"checkbox\" value=\"1\"name=\"");
				content += i;
				content += F("\">");
				content += NefryDataStore.getConnectSSID(i);
				content += F("<br>");
			}
		}
		content += F("<input type=\"button\" value=\"Delete\" onclick=\"return jsSubmit(this.form);\"></form>");
		return NefryWeb.createHtml(F("Nefry Wifi Confing"), "", content);
	}
	else if (url.equals("wifiReload")) {
		scanWiFi();
		return NefryWeb.createHtml(F("Wifi Reload"),(String)F("<meta http-equiv=\"Refresh\" content=\"0; URL = http://") + Nefry.getAddressStr(WiFi.localIP()) + (String)F("/wifi_conf\">"), F("<p>Please wait...</p><a href=\"/wifi_conf\">"));
	}
	else if (url.equals("wifiCount")) {
		setWifiTimeoutClear();
		return NefryWeb.createHtml(F("Wifi Count Clear"), (String)F("<meta http-equiv=\"Refresh\" content=\"0; URL = http://") + Nefry.getAddressStr(WiFi.localIP()) + (String)F("/wifi_conf\">"), F("<p>Please wait...</p><a href=\"/wifi_conf\">"));
	}
}


//WiFi

void Nefry_WiFi::deleteWifi(int id)
{
	if (id < 0 || id >= 5)return;
	NefryDataStore.setConnectSSID("",id);
	NefryDataStore.setConnectPass("",id);
}

void Nefry_WiFi::addWifi(String ssid, String pwd)
{
	Serial.print("addwifi : ");
	Serial.println(ssid);
	sortWifi();
	for (int i = 0; i < 5; i++) {
		if (NefryDataStore.getConnectSSID(i).equals("")) {
			NefryDataStore.setConnectSSID(ssid, i);
			NefryDataStore.setConnectPass(pwd, i);
			return;
		}
	}
	deleteWifi(0);
	sortWifi();
	NefryDataStore.setConnectSSID(ssid, 4);
	NefryDataStore.setConnectPass(pwd, 4);
}
void Nefry_WiFi::sortWifi()
{
	for (int i = 0,j = 0; i < 4; i++) {
		if (NefryDataStore.getConnectSSID(i).equals("")) {
			for (j = i + 1; j < 5; j++) {
				if (!NefryDataStore.getConnectSSID(j).equals("")) {
					NefryDataStore.setConnectSSID(NefryDataStore.getConnectSSID(j), i);
					NefryDataStore.setConnectPass(NefryDataStore.getConnectPass(j), i);
					NefryDataStore.setConnectSSID("", j);
					NefryDataStore.setConnectPass("", j);
					break;
				}
			}
			if (j == 5)return;
		}
	}
}
void Nefry_WiFi::saveWifi() {
	sortWifi();
}
String Nefry_WiFi::getlistWifi() {
	String lisWifi = "";
	for (int i = 0; i < 5; i++) {
		if (!NefryDataStore.getConnectSSID(i).equals("")) {
		lisWifi += "ID : ";
		lisWifi += i;
		lisWifi += " SSID : ";
		lisWifi += NefryDataStore.getConnectSSID(i);
		lisWifi += "\n";
		}
	}
	return lisWifi;
}

void Nefry_WiFi::scanWiFi(void) {
	int founds = WiFi.scanNetworks();
	Serial.println();
	Serial.println(F("scan done"));
	if (founds == 0) {
		Serial.println(F("no networks found"));
	}
	else {
		Serial.print(founds);
		Serial.println(F(" networks found"));
		network_html = F("<ol>");
		network_list = F("<datalist id=\"network_list\">");
		for (int i = 0; i < founds; ++i) {
			// Print SSID and RSSI for each network found
			Serial.print(i + 1);
			Serial.print(": ");
			Serial.print(WiFi.SSID(i));
			Serial.print(" (");
			Serial.print(WiFi.RSSI(i));
			Serial.println(")");
			network_html += F("<li>");
			network_html += WiFi.SSID(i);
			network_html += " (";
			network_html += WiFi.RSSI(i);
			network_html += ")";
			//network_html += (WiFi.encryptionType(i) == ENC_TYPE_NONE) ? " " : "*";
			network_html += F("</li>");
			network_list += F("<option value=\"");
			network_list += WiFi.SSID(i);
			network_list += F("\"></option>");
		}
		network_html += F("</ol>");
		network_list += F("</datalist>");
	}
}
/* �����u�� */
String Nefry_WiFi::escapeParameter(String param) {
	param.replace("+", " ");
	param.replace("%21", "!");
	param.replace("%22", "\"");
	param.replace("%23", "#");
	param.replace("%24", "$");
	param.replace("%25", "%");
	param.replace("%26", "&");
	param.replace("%27", "'");
	param.replace("%28", "(");
	param.replace("%29", ")");
	param.replace("%2A", "*");
	param.replace("%2B", "+");
	param.replace("%2C", ",");
	param.replace("%2F", "/");
	param.replace("%3A", ":");
	param.replace("%3B", ";");
	param.replace("%3C", "<");
	param.replace("%3D", "=");
	param.replace("%3E", ">");
	param.replace("%3F", "?");
	param.replace("%40", "@");
	param.replace("%5B", "[");
	param.replace("%5C", "\\");
	param.replace("%5D", "]");
	param.replace("%5E", "^");
	param.replace("%60", "'");
	param.replace("%7B", "{");
	param.replace("%7C", "|");
	param.replace("%7D", "}");
	return param;
}

/* WiFi�̃^�C���A�E�g�̕b����ݒ肵�܂��B */

int Nefry_WiFi::getWifiTimeout()
{
	return _WifiTimeOutCountMax;
}
void Nefry_WiFi::setWifiTimeout(int count)
{
	_WifiTimeOutCountMax = count;
}
void Nefry_WiFi::setWifiTimeoutClear()
{
	_WifiTimeOutCount = 0;
}

Nefry_WiFi NefryWiFi;