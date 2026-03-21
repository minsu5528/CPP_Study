#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <cstring>
using namespace std;

class Printer {
private:
	char str[100];
public:
	void SetString(const char* a);
	void ShowString();
};

void Printer::SetString(const char* a) {
	strcpy(str, a);
}

void Printer::ShowString() {
	cout << str << endl;
}

int main(void) {
	Printer pnt;
	pnt.SetString("Hello world!");
	pnt.ShowString();

	pnt.SetString("I Love C++");
	pnt.ShowString();
	return 0;
}