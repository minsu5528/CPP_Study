#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <cstring>
using namespace std;

class Car // 기본 연료 자동차
{
private:
	int gasolineGauge;
public:
	Car(int gas) : gasolineGauge(gas) {

	}

	int GetGasGauge() {
		return gasolineGauge;
	}
};

class HybridCar : public Car // 하이브리드 자동차
{
private:
	int electricGauge;
public:
	HybridCar(int gas, int ele) : Car(gas), electricGauge(ele) {

	}
	int GetElecGauge() {
		return electricGauge;
	}
};

class HybridWaterCar : public HybridCar // 하이브리드 워터카
{
private:
	int waterGauge;
public:
	HybridWaterCar(int gas, int elc, int wat) : HybridCar(gas, elc), waterGauge(wat) {

	}
	void ShowCurrentGauge() {
		cout << "잔여 가솔린: " << GetGasGauge() << endl;
		cout << "잔여 전기량: " << GetElecGauge() << endl;
		cout << "잔여 워터량: " << waterGauge << endl;
	}
};

int main(void) {
	HybridWaterCar c1(10, 20, 30);
	c1.ShowCurrentGauge();

	return 0;
}