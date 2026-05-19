#include <iostream>
#include <cstring>

using namespace std;

class Gun {
private:
	int bullet; // 장전된 총알의 수
public:
	Gun(int bnum) : bullet(bnum) {

	}

	void Shot() {
		cout << "BBANG!" << endl;
		bullet--;
	}
};

class Police {
private:
	int handcuffs; // 수갑의 수
	Gun* pistol; // 권총의 수
public:
	Police(int bnum, int bcuff) : handcuffs(bcuff) {
		if (bnum > 0) pistol = new Gun(bnum);
		else pistol = NULL;
	}
	Police(const Police& ref) : handcuffs(ref.handcuffs) {
		if (ref.pistol != NULL) pistol = new Gun(*(ref.pistol));
		else pistol = NULL;
	}
	void PutHandcuff() {
		cout << "SNAP!" << endl;
		handcuffs--;
	}
	void Shot() {
		if (pistol == NULL) cout << "Hut BBANG!" << endl;
		else pistol->Shot();
	}

	Police& operator=(const Police& ref) {
		if (pistol != NULL) delete pistol;
		handcuffs = ref.handcuffs;
		if (ref.pistol != NULL)
			pistol = new Gun(*(ref.pistol));
		else pistol = NULL;
		return *this;
	}
	~Police() {
		if (pistol != NULL) delete pistol;
	}
};

int main(void) {
	Police pman1(5, 3);
	Police pman2 = pman1;
	pman2.Shot();
	pman2.PutHandcuff();

	Police pman3(2, 4);
	pman3 = pman1;
	pman3.Shot();
	pman3.PutHandcuff();

	return 0;
}