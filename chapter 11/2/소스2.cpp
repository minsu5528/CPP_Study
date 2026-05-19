#include <iostream>
using namespace std;

class BoundCheckIntArray
{
private:
    int* arr;
    int arrlen;
    // 복사와 대입을 원천 차단하기 위해 private에 선언만 해둠
    BoundCheckIntArray(const BoundCheckIntArray& arr) {}
    BoundCheckIntArray& operator=(const BoundCheckIntArray& arr) {}

public:
    BoundCheckIntArray(int len) :arrlen(len)
    {
        arr = new int[len];
    }
    int& operator[] (int idx)
    {
        if (idx < 0 || idx >= arrlen)
        {
            cout << "Array index out of bound exception" << endl;
            exit(1);
        }
        return arr[idx];
    }
    int operator[] (int idx) const
    {
        if (idx < 0 || idx >= arrlen)
        {
            cout << "Array index out of bound exception" << endl;
            exit(1);
        }
        return arr[idx];
    }
    int GetArrLen() const
    {
        return arrlen;
    }
    ~BoundCheckIntArray()
    {
        delete[]arr;
    }
};

// 1차원 배열 객체를 가리키는 포인터 타입을 보기 좋게 재정의
typedef BoundCheckIntArray* BoundCheckIntArrayPtr;

class BoundCheck2DIntArray
{
private:
    BoundCheckIntArray** arr;
    int arrlen;
    // 여기서도 2차원 배열의 복사와 대입을 차단
    BoundCheck2DIntArray(const BoundCheck2DIntArray& arr) {}
    BoundCheck2DIntArray& operator=(const BoundCheck2DIntArray& arr) {}
public:
    BoundCheck2DIntArray(int col, int row) :arrlen(col)
    {
        arr = new BoundCheckIntArrayPtr[col];
        for (int i = 0; i < col; i++)
            arr[i] = new BoundCheckIntArray(row);
    }
    BoundCheckIntArray& operator[] (int idx)
    {
        if (idx < 0 || idx >= arrlen) {
            cout << "Array index out of bound exception" << endl;
            exit(1);
        }
        return *(arr[idx]); // 1차원 배열 객체(Proxy) 자체를 반환!
    }
    ~BoundCheck2DIntArray() {
        for (int i = 0; i < arrlen; i++)
            delete arr[i];
        delete[]arr;
    }
};

int main(void)
{
    BoundCheck2DIntArray arr2d(3, 4);

    for (int n = 0; n < 3; n++)
        for (int m = 0; m < 4; m++)
            arr2d[n][m] = n + m;

    for (int n = 0; n < 3; n++)
    {
        for (int m = 0; m < 4; m++)
            cout << arr2d[n][m] << ' ';
        cout << endl;
    }
    return 0;
}