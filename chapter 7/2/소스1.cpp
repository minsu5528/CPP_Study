#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <cstring>
using namespace std;


class Rectangle {
private:
	int x;
	int y;
public:
	Rectangle(int xlen, int ylen) :x(xlen), y(ylen) {

	}

	void ShowAreaInfo() {
		cout << "¸éÀû: " << x * y << endl;
	}
};

class Square : public Rectangle {
public:
	Square(int len) : Rectangle(len, len) {

	}
};

int main(void) {
	Rectangle rec(4, 3);
	rec.ShowAreaInfo();

	Square sqr(7);
	sqr.ShowAreaInfo();
	return 0;
}