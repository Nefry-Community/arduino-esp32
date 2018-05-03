/**
Nefry IFTTT lib

Copyright (c) 2015 wami

This software is released under the MIT License.
http://opensource.org/licenses/mit-license.php
*/

#include "NefryLineNotify.h"

bool Nefry_LINE_Notify::send(String auth,String message)
{
	WiFiClientSecure client;
	if (client.connect("notify-api.line.me", 443)) {
		String url = "/api/notify";
		url += "?message=";
		url += StrPerEncord(escapeParameter(message).c_str());

		client.print(String("POST ") + url + " HTTP/1.1\r\n" +
			"Authorization: Bearer " + auth + "\r\n" +
			"Content-Type: application/x-www-form-urlencoded\r\n" +
			"Host: notify-api.line.me\r\n" +
			"Connection: close\r\n\r\n");
		client.println();

		unsigned long timeout = millis();
		while (client.available() == 0) {
			if (millis() - timeout > 5000) {
				Serial.println(">>> Client Timeout !");
				client.stop();
				return false;
			}
		}
		// Read all the lines of the reply from server and print them to Serial
		while (client.available()) {
			String line = client.readStringUntil('\r');
			Serial.print(line);
		}
		Serial.println();
		Serial.println("closing connection");
		delay(10);
		return true;
	}
	return false;
}

//********************UTF-8文字列をパーセントエンコード*************************
String Nefry_LINE_Notify::StrPerEncord(const char* c_str) {
	uint16_t i = 0;
	String str_ret = "";
	char c1[3], c2[3], c3[3];

	while (c_str[i] != '\0') {
		if (c_str[i] >= 0xC2 && c_str[i] <= 0xD1) { //2バイト文字
			sprintf(c1, "%2x", c_str[i]);
			sprintf(c2, "%2x", c_str[i + 1]);
			str_ret += "%" + String(c1) + "%" + String(c2);
			i = i + 2;
		}
		else if (c_str[i] >= 0xE2 && c_str[i] <= 0xEF) {
			sprintf(c1, "%2x", c_str[i]);
			sprintf(c2, "%2x", c_str[i + 1]);
			sprintf(c3, "%2x", c_str[i + 2]);
			str_ret += "%" + String(c1) + "%" + String(c2) + "%" + String(c3);
			i = i + 3;
		}
		else {
			str_ret += String(c_str[i]);
			i++;
		}
	}
	return str_ret;
}

String Nefry_LINE_Notify::escapeParameter(String param) {
	param.replace("%", "%25");
	param.replace("+", "%2B");
	param.replace(" ", "+");
	param.replace("\"", "%22");
	param.replace("#", "%23");
	param.replace("$", "%24");
	param.replace("&", "%26");
	param.replace("'", "%27");
	param.replace("(", "%28");
	param.replace(")", "%29");
	param.replace("*", "%2A");
	param.replace(",", "%2C");
	param.replace("/", "%2F");
	param.replace(":", "%3A");
	param.replace(";", "%3B");
	param.replace("<", "%3C");
	param.replace("=", "%3D");
	param.replace(">", "%3E");
	param.replace("?", "%3F");
	param.replace("@", "%40");
	param.replace("[", "%5B");
	param.replace("\\", "%5C");
	param.replace("]", "%5D");
	param.replace("^", "%5E");
	param.replace("'", "%60");
	param.replace("{", "%7B");
	param.replace("|", "%7C");
	param.replace("}", "%7D");
	return param;
}


Nefry_LINE_Notify LineNotify;
