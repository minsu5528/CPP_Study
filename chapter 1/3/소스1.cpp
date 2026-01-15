#include <iostream>
using namespace std;

int BoxVolume(int a, int b, int c) {
	return a * b * c;
}

int BoxVolume(int a, int b) {
	return a * b * 1;
}

int BoxVolume(int a) {
	return a * 1 * 1;
}




int main(void) {
	cout << " [3, 3, 3] : " << BoxVolume(3, 3, 3) << endl;
	cout << " [5, 5, D] : " << BoxVolume(5, 5) << endl;
	cout << " [7, D, D] : " << BoxVolume(7) << endl;
	//cout << " [D, D, D] : " << BoxVloume() << endl;
	return 0;
}