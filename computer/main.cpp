#include <iostream>
#include "system/System.h"
#include "data/Data.h"
#include "decimal/Decimal.h"
using namespace std;

struct {
    double c;
    long long g;
    float e;
    char *a;
    void *h;
    short b;
    char d;
    char f;
}foo;

union ele{
    struct {
        int *p;
        int y;
    }e1;

    struct {
        int x;
        union ele * next;
    }e2;
}ele;

int main() {

//    验证是小端存储还是打断存储
//    if(System::IsBig_Ending()){
//        cout << "big endian" << endl;
//    }else{
//        cout << "little endian" << endl;
//    }

    //验证IEEE的编码方式
//    float float1 = 0.25f;
//    Decimal::show_float(float1);
//    Data::show_float(float1);
//    cout << "==========" << endl;
//    float float2 = -2.565f;
//    Decimal::show_float(float2);
//    Data::show_float(float2);
//    cout << "==========" << endl;

//    double double1 = 5.2645;
//    Decimal::show_double(double1);
//    Data::show_double(double1);
//    cout << "==========" << endl;
//    double double2 = -4.656;
//    Decimal::show_double(double2);
//    Data::show_double(double2);
//    cout << "==========" << endl;
    //Normalized/Denomalized/Infinity/Nan
    //Normalized格式
//    float floatTest1 = 12.25;
//    Decimal::show_float(floatTest1);
    //Denomalized格式
//    float floatTest2;
//    Decimal::show_float(floatTest2);
//    //Infinity格式
//    float floatTest3;
//    Decimal::show_float(floatTest3);
//    //Nan格式
//    float floatTest4 = 'b';
//    Decimal::show_float(floatTest4);
//第六题
    cout << &(foo.c) << endl;
    cout << &(foo.g) << endl;
    cout << &(foo.e) << endl;
    cout << &(foo.a) << endl;
    cout << &(foo.h) << endl;
    cout << &(foo.b) << endl;
    cout << &(foo.d) << endl;
    cout << &(foo.f) << endl;
//第七题
    cout << &(ele.e1.p) << endl;
    cout << &(ele.e1.y) << endl;

    cout << &(ele.e2.x) << endl;
    cout << &(ele.e2.next) << endl;

    return 0;
}

