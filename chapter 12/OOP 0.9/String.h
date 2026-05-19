#ifndef __STRING_H__
#define __STRING_H__

#include "BankingCommonDec1.h"

class String {
private:
	int len;
	char* str;
public:
	String();
	String(const char* s);
	String(const String& s);
	~String();

	String& operator=(const String& s);
	String& operator+=(const String& s);
	bool operator==(const String& s);
	String operator+(const String& s);

	friend ostream& operator<<(ostream& os, const String& s);
	friend iostream& operator>>(iostream& is, String& s);
};
#endif