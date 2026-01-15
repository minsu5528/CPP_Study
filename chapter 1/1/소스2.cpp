#include <iostream>
using namespace std;

int main(void) {
	char name[100];
	char number[100];
	
	cout << "이름: ";
	cin >> name;
	cout << "전화번호: ";
	cin >> number;

	cout << "이름은 " << name << "이고 전화번호는 " << number << "입니다.\n";
}