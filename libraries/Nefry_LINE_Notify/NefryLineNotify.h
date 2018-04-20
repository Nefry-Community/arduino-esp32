#ifndef NefryLINENotify_h
#define NefryLINENotify_h

#include <WiFiClientSecure.h>
#include <Nefry.h>

class Nefry_LINE_Notify
{
public:
	bool
		send(String auth, String message);
private:
	String
		escapeParameter(String param),
		StrPerEncord(const char* c_str);
};
extern Nefry_LINE_Notify LineNotify;
#endif