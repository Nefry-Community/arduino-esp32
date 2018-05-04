/**
Nefry FastSensing

Copyright (c) 2017 wami

*/

#include "NefryThingSpeak.h"

NefryThingSpeakClass NefryThingSpeak;

void NefryThingSpeakClass::begin(int nefryConfigChannelNumber, const char* hint)
{
	_nefryThingsChannelAPIKey = 0;
	ThingSpeak.begin(_nefryThingClient);
	_nefryConfigChannelNumber = nefryConfigChannelNumber;
	Nefry.setStoreTitleValue(hint, _nefryConfigChannelNumber);
}

void NefryThingSpeakClass::setWriteAPIKey(int nefryConfigWriteApikey, const char* hint)
{
	_nefryThingsWriteAPIKey = "";
	_nefryConfigWriteApikey = nefryConfigWriteApikey;
	Nefry.setStoreTitleStr(hint, _nefryConfigWriteApikey);
}

void NefryThingSpeakClass::setReadAPIKey(int nefryConfigReadApikey, const char* hint)
{
	_nefryThingsReadAPIKey = "";
	_nefryConfigReadApikey = nefryConfigReadApikey;
	Nefry.setStoreTitleStr(hint, _nefryConfigReadApikey);
}

void NefryThingSpeakClass::begin(unsigned long thingsChannelNum)
{
	_nefryThingsChannelAPIKey = thingsChannelNum;
}

void NefryThingSpeakClass::setWriteAPIKey(String thingsWriteAPIKey)
{
	_nefryThingsWriteAPIKey = thingsWriteAPIKey;
}

void NefryThingSpeakClass::setReadAPIKey(String thingsReadAPIKey)
{
	_nefryThingsReadAPIKey = thingsReadAPIKey;
}

const char * NefryThingSpeakClass::getWriteAPIKey()
{
	if (_nefryThingsWriteAPIKey.equals("")) {
		_nefryThingsWriteAPIKey = Nefry.getStoreStr(_nefryConfigWriteApikey);
	}
	return _nefryThingsWriteAPIKey.c_str();
}

const char * NefryThingSpeakClass::getReadAPIKey()
{
	if (_nefryThingsReadAPIKey.equals("")) {
		_nefryThingsReadAPIKey = Nefry.getStoreStr(_nefryConfigReadApikey);
	}
	return _nefryThingsReadAPIKey.c_str();
}

unsigned long NefryThingSpeakClass::getChannelNumber()
{
	if (_nefryThingsChannelAPIKey == 0) {
		_nefryThingsChannelAPIKey = Nefry.getStoreValue(_nefryConfigChannelNumber);
	}
	return _nefryThingsChannelAPIKey;
}

int NefryThingSpeakClass::writeField( unsigned int field, int value)
{
	return ThingSpeak.writeField(getChannelNumber(),field,value, getWriteAPIKey());
}

int NefryThingSpeakClass::writeField(unsigned int field, long value)
{
	return ThingSpeak.writeField(getChannelNumber(), field, value, getWriteAPIKey());
}

int NefryThingSpeakClass::writeField(unsigned int field, float value)
{
	return ThingSpeak.writeField(getChannelNumber(), field, value, getWriteAPIKey());
}

int NefryThingSpeakClass::writeField(unsigned int field, const char * value)
{
	return ThingSpeak.writeField(getChannelNumber(), field, value, getWriteAPIKey());
}

int NefryThingSpeakClass::writeField(unsigned int field, String value)
{
	return ThingSpeak.writeField(getChannelNumber(), field, value, getWriteAPIKey());
}

int NefryThingSpeakClass::writeFields()
{
	return ThingSpeak.writeFields(getChannelNumber(), getWriteAPIKey());
}

