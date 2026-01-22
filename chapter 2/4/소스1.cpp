#define _CRT_SECURE_NO_WARNINGS
#include <cstring>
#include <iostream>
using namespace std;


int main(void) {
	char a[50] = "Hello";
	char b[50] = "World";

	cout << a << endl;
	cout << b << endl;
	cout << "±æÀÌ " << strlen(a) << ", " << strlen(b) << endl;

	strcat(a, b);
	cout << a << endl;
	cout << b << endl;

	strcpy(b, a);
	cout << a << endl;
	cout << b << endl;

	cout << strcmp(a, b);
	return 0;

}

