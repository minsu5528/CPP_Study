#include <iostream>
using namespace std;

void add(int &a);
void sign(int &a);


int main(void) {
	int a;
	cin >> a;
	cout << a << "\n";
	add(a);
	cout << a << "\n";
	sign(a);
	cout << a << "\n";
	return 0;
}

void add(int &a) {
	a++;
}

void sign(int* a) {
	a *= -1;
}

