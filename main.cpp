#include <bits/stdc++.h>
#include "BigDecimalInt.h"


using namespace std;

int main() {

    BigDecimalInt num0(123123);
    BigDecimalInt num1("10");
    BigDecimalInt num2("55");
    BigDecimalInt num3("-200000000000000000000000000000");
    if(num1==num2){
        cout<<"num1 is equal to num2"<<endl;
    }
    if(num1>num2){
        cout<<"num1 is greater than num2"<<endl;
    }
    if(num1<num2){
        cout<<"num1 is less than num2"<<endl;
    }

    cout<<"sign of num1 is : " <<sign(num1)<<endl;
    cout<<"Length of num1 is : " <<Length(num1)<<endl;

    BigDecimalInt num4 = num2 + num1;
    BigDecimalInt num5 = num2 - num1;
    num0.print_int();
    cout<<endl;
    cout << "num1 = " << num1 << endl;
    cout << "num2 = " << num2 << endl;
    cout << "num2 + num1 = " << num4 << endl;
    cout << "num2 - num1 = " << num5 << endl;




        return 0;

}


