//
// Created by ahmed on 10/24/2022.
//

#ifndef EX_BIGDECIMALINT_H
#define EX_BIGDECIMALINT_H

#include <bits/stdc++.h>
#include <iostream>

using namespace std;

class BigDecimalInt{
private:

    string num1;

    int nums;

public:


    BigDecimalInt(string n1);
    BigDecimalInt(int n2);



    BigDecimalInt operator + (BigDecimalInt anotherDec);
    BigDecimalInt operator - (BigDecimalInt anotherDec);
    void print();
    void print_int();
    bool operator<(const BigDecimalInt &anotherDec);
    friend bool operator==(const BigDecimalInt &a, const BigDecimalInt &b);
    friend char sign(const BigDecimalInt &a);
    friend bool operator>(const BigDecimalInt &a, const BigDecimalInt &b);
    BigDecimalInt &operator=(const BigDecimalInt &a);
    friend int Length(const BigDecimalInt &a);
    friend ostream &operator<<(ostream &out, const BigDecimalInt &b);
    friend ostream &operator<<(ostream &out, const BigDecimalInt &a);





    };


#endif //EX_BIGDECIMALINT_H
