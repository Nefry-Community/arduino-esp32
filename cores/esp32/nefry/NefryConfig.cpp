/**
Nefry Config

Copyright (c) 2016 wami

This software is released under the MIT License.
http://opensource.org/licenses/mit-license.php
*/

/*
ModuleID	: Nefry���W���[���� & Nefry�����M����SSID
ModulePass	: Nefry�����M����WiFi�p�X���[�h
ModuleClass	: Nefry�̃��W���[����������N���X
user		: Nefry�Ń��O�C���@�\���g���Ƃ��Ɏg�p���郆�[�U��
userPass	: Nefry�Ń��O�C���@�\���g���Ƃ��Ɏg�p����p�X���[�h
StorageValue: Nefry�̊��ϐ���ۑ�����Ƃ��Ɏg�p����B(0-7)�͈̔͂ŕۑ�����B���[�ɐ������ǉ������ long�^
StorageStr	: Nefry�̊��ϐ���ۑ�����Ƃ��Ɏg�p����B(0-7)�͈̔͂ŕۑ�����B���[�ɐ������ǉ������ String�^
*/

#include "NefryConfig.h"



String Nefry_Conf::beginWeb(String link) {

	if (link.equals("config")) {
		String content = F("<h1>Nefry DataStore Setup</h1><form method='get'action='set_config'>");
		int formNumber;
		for (formNumber = 0; formNumber < 10; formNumber++) {
			if (htmlPrint[formNumber] == 1) {
				content += F("<div class=\"row\"><label>");
				content += module_input[formNumber];
				content += F("</label><div><input name=\"smo");
				content += formNumber;
				content += F("\"maxlength=\"128\"value=\"");
				content += NefryDataStore.getStorageStr(formNumber);
				content += F("\"></div></div>");
			}
		}
		for (formNumber = 10; formNumber < 20; formNumber++) {
			if (htmlPrint[formNumber] == 1) {
				content += F("<div class=\"row\"><label>");
				content += module_input[formNumber];
				content += F("</label><div><input name=\"imo");
				content += formNumber - 10;
				content += F("\"type=\"number\"value=\"");
				content += NefryDataStore.getStorageValue(formNumber - 10);
				content += F("\"></div></div>");
			}
		}
		delay(1);
		content += F("<div class=\"psrow\"><div><input type=\"button\"value=\"Save\"onclick=\"return jsSubmit(this.form);\"></div></form></div><div class=\"writemode\">");
		if (Nefry.getWriteMode())content += "WriteMode";
		content += F("</div><a href=\"/\">Back to top</a>");
		NefryWeb.createHtml(F("Nefry DataStore"), "", content);
	}
}
				   /* HTML�ɕ\������̂� */
void Nefry_Conf::setStoreTitle(const char set[15], const int num) {
	if (0 <= num&&num < 20) {
		strcpy(module_input[num], set);
		htmlPrint[num] = 1;
	}

}

void Nefry_Conf::begin()
{
	for (int i = 0; i < 10; i++) {
		sprintf(module_input[i], "String %d", i);
		sprintf(module_input[10+i], "Value %d", 10+i);
		if (Nefry.getWriteMode()) {
			htmlPrint[i] = 1;
			htmlPrint[10+i] = 1;
		}
		else {
			htmlPrint[i] = 0;
			htmlPrint[10 + i] = 0;
		}		
	}
}
Nefry_Conf NefryConfig;