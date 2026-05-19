#ifndef __BANKING_COMMON_H__
#define __BANKING_COMMON_H__

#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <cstring>

using namespace std;
const int NAME_LEN = 20;


enum { MAKE = 1, DEPOSIT, WITHDRAW, INQUIRE, EXIT };
enum { A = 7, B = 4, C = 2 };
enum { NORMAL = 1, CREDIT = 2 };

#endif; // !__BANKING_COMMON_H__
