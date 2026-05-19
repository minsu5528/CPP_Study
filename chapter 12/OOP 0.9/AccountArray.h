#ifdef __ACCOUN_ARRAY_H__
#define __ACCOUN_ARRAY_H__

#include "Account.h"
typedef Accout* ACCOUNT_PTR;

class BoundCheckAccountPtrArray {
private:
    POINT_PTR* arr;
    int arrlen;
    BoundCheckAccountPtrArray(const BoundCheckAccountPtrArray& arr) {}
    BoundCheckAccountPtrArray& operator=(const BoundCheckAccountPtrArray& arr) {}
public:
    BoundCheckAccountPtrArray(int len = 100);
    ACCOUNT_PTR& operator[] (int idx);
    ACCOUNT_PTR operator[] (int idx) const;
    int GetArrLen() const;
    ~BoundCheckAccountPtrArray();
};

#endif