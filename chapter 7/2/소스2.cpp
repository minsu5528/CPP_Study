#define _CRT_SECUR_NO_WARNINGS
#include <iostream>
#include <cstring>
using namespace std;

class Book {
private:
	char* title;
	char* isbn;
	int price;
public:
	Book(const char* t, const char* i, const int p) : price(p) {
		title = new char[strlen(t) + 1];
		isbn = new char[strlen(i) + 1];
		strcpy(title, t);
		strcpy(isbn, i);
	}
	void ShowBookInfo() const {
		cout << "제목: " << title << endl;
		cout << "ISBN: " << isbn << endl;
		cout << "가격: " << price << endl;
		return;
	}
	~Book() {
		delete[]title;
		delete[]isbn;
	}
};

class EBook : public Book {
private:
	char* DRMKey;
public:
	EBook(const char* t, const char* i, int p, const char* DRM) : Book(t, i, p) {
		DRMKey = new char[strlen(DRM) + 1];
		strcpy(DRMKey, DRM);
	}
	void ShowEBookInfo() {
		ShowBookInfo();
		cout << "인증키: " << DRMKey << endl;
		return;
	}
	~EBook() {
		delete[]DRMKey;
	}
};

int main(void) {
	Book book("좋은 C++", "555-12345-890-0", 20000);
	book.ShowBookInfo();
	cout << endl;
	EBook ebook("좋은 C++ ebook", "555-12345-890-1", 10000, "fdx9w0i8kiw");
	ebook.ShowEBookInfo();
	return 0;
}