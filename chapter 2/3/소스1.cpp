#include <iostream>
using namespace std;


typedef struct __Point {
	int xpos;
	int ypos;
} Point;

Point& PntAdder(const Point& p1, const Point& pt2);

int main(void) {
	Point* p1 = new Point;
	p1->xpos = 5; p1->ypos = 6;
	Point* p2 = new Point;
	p2->xpos = 8; p2->ypos = 9;

	Point& p3 = PntAdder(*p1, *p2);

	cout << p3.xpos << endl;
	cout << p3.ypos << endl;

	delete p1;
	delete p2;
	delete& p3;
	return 0;
}

Point& PntAdder(const Point& p1, const Point& p2) {
	Point* p = new Point;
	p->xpos = p1.xpos + p2.xpos;
	p->ypos = p1.ypos + p2.ypos;
	return *p;
}

// 1. 포인터 변수에 * 붙여서 전달
// 2. new를 통해 힙에 할당하여 선언
