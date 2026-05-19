#define _CRT_SECURE_NO_WARNINGS
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
	Book(const Book& ref) : price(ref.price) {
		title = new char[strlen(ref.title) + 1];
		isbn = new char[strlen(ref.isbn) + 1];
		strcpy(title, ref.title);
		strcpy(isbn, ref.isbn);
	}

	Book& operator=(const Book& ref) {
		delete[] title;
		delete[] isbn;
		title = new char[strlen(ref.title) + 1];
		isbn = new char[strlen(ref.isbn) + 1];
		strcpy(title, ref.title);
		strcpy(isbn, ref.isbn);
		price = ref.price;
		return *this;
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

	EBook(const EBook& ref) : Book(ref) {
		DRMKey = new char[strlen(ref.DRMKey) + 1];
		strcpy(DRMKey, ref.DRMKey);
	}

	EBook& operator=(const EBook& ref) {
		Book::operator=(ref);
		delete[]DRMKey;
		DRMKey = new char[strlen(ref.DRMKey) + 1];
		strcpy(DRMKey, ref.DRMKey);
		return *this;
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
	EBook ebook1("good C++", "555-12345-890-0", 10000, "fdx9w0i8k");
	EBook ebook2 = ebook1;
	ebook2.ShowBookInfo();
	cout << endl;

	EBook ebook3("dumy", "dumy", 0, "dumy");
	ebook3 = ebook2;
	ebook3.ShowEBookInfo();
	return 0;
}