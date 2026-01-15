#include <iostream>
using namespace std;

int main(void) {
	int result;

	for (int i = 1; i < 5; i++) {
		cout << i << "번째 정수 입력: ";
		int n;
		cin >> n;
		result += n;
	}

	cout << "합계: " << reselt;
}