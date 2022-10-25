//
// Created by ahmed on 10/9/2022.
//

#include "BigDecimalInt.h"
#include "iostream"

BigDecimalInt::BigDecimalInt(string n1) : num1(n1) {
    for (int i = 0; i <= num1.size(); ++i) {
        if (num1[i] == ' ') {
            num1 = "Invalid Input";
            break;  // break the loop if space is found
        }


    }

}


BigDecimalInt::BigDecimalInt(int n2) : nums(n2)
{

}

BigDecimalInt BigDecimalInt::operator+(BigDecimalInt anotherDec) {
    if(num1 != "Invalid Input") {


        string ans = "";

        int i1 = num1.size() - 1, i2 = anotherDec.num1.size() - 1, carry = 0;

        while (i1 >= 0 || i2 >= 0 || carry > 0) {

            if (i1 >= 0) {

                carry += num1[i1] - '0';

                i1 -= 1;
            }
            if (i2 >= 0) {

                carry += anotherDec.num1[i2] - '0';

                i2 -= 1;
            }
            ans += char(carry % 10 + '0');

            carry /= 10;
        }
        reverse(ans.begin(), ans.end());

        return BigDecimalInt(ans);
    }
    else{
        string ans = "Invalid Input";
        return BigDecimalInt(ans);
    }
}

BigDecimalInt BigDecimalInt::operator-(BigDecimalInt anotherDec) {

    string ans = "";
    int diff = 0;
    bool is_negative = 0;
    bool is_reversed = 0;
    int i1 = num1.size() - 1, i2 = anotherDec.num1.size() - 1, carry = 0, scnd_carry = 0;

    if (i1 < i2){
        here:
        cout << "Sustained " << endl;
        string TempContainer ="";
        int container;

        //reversing num1 and num2 (first number is less than second number)
        TempContainer = num1;
        num1 = anotherDec.num1;
        anotherDec.num1 = TempContainer;

        container = i1;
        i1 = i2;
        i2 = container;

        is_negative = 1;

        goto there;


    }else if (i1 == i2 && (is_reversed == 0)){
        //checking if num1 < num2
        if(stoi(num1) < stoi(anotherDec.num1)){
            goto here;
        }else{
            goto there;
        }

    }else{
        //if num1 >= num2
        there:
        while (i1 >= 0 || i2 >= 0) {
            carry = 0;
            if (i1 >= 0){
                //putting last number of string in carry
                carry += num1[i1] - '0';
                i1 -= 1;
            }
            if (i2 >= 0) {
                diff = carry;
                diff -=  anotherDec.num1[i2] - '0'; // diff between carry and last number (in string num1) of second number

                //if diff > 0, we will get the diff
                if((diff) >= 0){
                    carry -= anotherDec.num1[i2] - '0';
                    i2 -= 1;
                }
                //if diff < 0, we will add 10 before get diff
                if((diff) < 0 && i1>=0){
                    carry += 10;
                    carry -= anotherDec.num1[i2] - '0';

                    num1[i1] -= 1;
                    i2 -= 1;

                }

            }
            //multiple borrowing of zeros condition
            if(carry < 0){
                carry += 10;
                num1[i1] -= 1;
            }


            //puting carry in answer string
            ans += char (carry + '0');


        }
        //if operation leads to negative answer, put negative in answer
        if(is_negative){
            ans += "-";
        }

        //reversing answer string as algorithm was moving backward
        reverse(ans.begin(), ans.end());
        return BigDecimalInt (ans);
    }
}



bool operator==(const BigDecimalInt &a, const BigDecimalInt &b) {
    return a.num1 == b.num1;
}

bool operator>(const BigDecimalInt &a, const BigDecimalInt &b) {
    if(a.num1 == "Invalid Input" || b.num1 == "Invalid Input"){
        return false;
    }
    else {
        return a.num1 > b.num1;
    }

}

bool BigDecimalInt::operator<(const BigDecimalInt &anotherDec)
{
    int size_1= num1.size(), size_2= anotherDec.num1.size();

    //checking strings
    if(!num1.empty() && !anotherDec.num1.empty()){
        if(size_1 > size_2){

            cout << "False" << endl;
            return false;

        }
        if(size_1 < size_2){
            cout << "True" << endl;
            return true;


        }

        if(size_1 == size_2){
            //checking
            if(stoi(num1) < stoi(anotherDec.num1)){
                cout << "True" << endl;
                return true;
            }else{
                cout << "False" << endl;
                return false;
            }

            return false;

        }

    }

    //checking numbers
    if(nums !=0 && anotherDec.nums !=0){
        if(nums < anotherDec.nums){
            cout << "True";
            return true;
        }else{
            cout << "false";
            return false;
        }
    }

}



BigDecimalInt &BigDecimalInt::operator=(const BigDecimalInt &a) {
            num1 = a.num1;
            return *this;
}

int Length(const BigDecimalInt &a) {
    return a.num1.size();
}

char sign(const BigDecimalInt &a) {
    char c;
    if (a.num1[0] == '-') {
        c = '-';
    } else {
        c = '+';
    }
    return c;

}

ostream &operator<<(ostream &out, const BigDecimalInt &b) {
    for (int i =0; i <= b.num1.size() - 1;i++)
            cout << b.num1[i];
            return cout;
}


void BigDecimalInt::print() {
    cout << "The number = " << num1;
}

void BigDecimalInt::print_int() {
    cout << "The number with integer value = " << nums;

}








