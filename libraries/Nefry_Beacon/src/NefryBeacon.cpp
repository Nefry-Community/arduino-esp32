// Nefry Beacon
// Copyright(C) 2017 wami
//
// This program is free software : you can redistribute it and/or modify
// it under the terms of the GNU General Public License as published by
// the Free Software Foundation, either version 3 of the License, or
// (at your option) any later version.
//
// This program is distributed in the hope that it will be useful,
// but WITHOUT ANY WARRANTY; without even the implied warranty of
// MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.See the
// GNU General Public License for more details.
//
// You should have received a copy of the GNU General Public License
// along with this program.If not, see <http://www.gnu.org/licenses/>.

#include "sdkconfig.h"

#if defined(CONFIG_BT_ENABLED) && defined(CONFIG_BLUEDROID_ENABLED)

#include "NefryBeacon.h"
#include "esp32-hal-log.h"

#include "bt.h"
#include "bta_api.h"
#include "esp_gap_ble_api.h"
#include "esp_gatts_api.h"
#include "esp_bt_defs.h"
#include "esp_bt_main.h"
#include "Arduino.h"

static esp_ble_adv_params_t _adv_params = {
        .adv_int_min         = 0x20,
        .adv_int_max         = 0x40,
        .adv_type            = ADV_TYPE_NONCONN_IND,
        .own_addr_type       = BLE_ADDR_TYPE_PUBLIC,
        .peer_addr           = {0x00, },
        .peer_addr_type      = BLE_ADDR_TYPE_PUBLIC,
        .channel_map         = ADV_CHNL_ALL,
        .adv_filter_policy   = ADV_FILTER_ALLOW_SCAN_ANY_CON_ANY,
};

uint8_t ibeacon_packet[] = {
	0x02, 0x01, 0x06, 0x1a, 0xff, 0x4c, 0x00, 0x02, 0x15,//9
	0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,//UUID 16
	0x00, 0x00,//major
	0x00, 0x00,//minor
	0xc5 //power
};
/*
 * BLE Arduino
 *
 * */
bool NefryBeacon::begin(uint8_t uuid[16],uint16_t major,uint16_t minor){
	for (int i = 0; i < 16; i++) {
		ibeacon_packet[9 + i] = uuid[i];
	}

	ibeacon_packet[25] = major>>8 & 0xFF;
	ibeacon_packet[26] = major & 0xFF;

	ibeacon_packet[27] = minor >> 8 & 0xFF;
	ibeacon_packet[28] = minor & 0xFF;

	for (int i = 0; i < 30; i++) {
		//Serial.print(ibeacon_packet[i]);
		//Serial.print(":");
	}
	//Serial.println("btStart");
	if (!btStarted() && !btStart()) {
		//Serial.println("btStart failed");
		return false;
	}
	//Serial.println("esp_bluedroid_init");
	esp_bluedroid_status_t bt_state = esp_bluedroid_get_status();
	if (bt_state == ESP_BLUEDROID_STATUS_UNINITIALIZED) {
		if (esp_bluedroid_init()) {
			//Serial.println("esp_bluedroid_init failed");
			return false;
		}
	}
	//Serial.println("esp_bluedroid_enable");
	if (bt_state != ESP_BLUEDROID_STATUS_ENABLED) {
		if (esp_bluedroid_enable()) {
			//Serial.println("esp_bluedroid_enable failed");
			return false;
		}
	}

	if (esp_ble_gap_config_adv_data_raw(ibeacon_packet, 31)) {
		//Serial.println("gap_config_adv_data failed");
		return false;
	}

	 esp_ble_gap_start_advertising(&_adv_params);
	return true;
}

bool NefryBeacon::end()
{
	if (btStarted()) {
		esp_bluedroid_disable();
		esp_bluedroid_deinit();
		btStop();
    return true;
	}
	return false;
}

#endif
