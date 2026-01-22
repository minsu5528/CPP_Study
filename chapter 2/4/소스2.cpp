#define _CRT_SECURE_NO_WARNINGS
#include <ctime>
#include <cstdlib>
#include <iostream>
using namespace std;


int main(void) {
	srand(time(NULL));
	for (int i = 0; i < 5; i++)
		printf("%d : %d\n", i, rand() % 100);
	return 0;

}