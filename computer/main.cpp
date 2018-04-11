#include <iostream>
#include "system/System.h"
#include "data/Data.h"
#include "decimal/Decimal.h"
#include "matrix/Matrix.h"
#define LEN 5
using namespace std;
typedef int zip_dig[LEN];

//第六题的结构体
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

//第七题的结构体
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
    if(System::IsBig_Ending()){
        cout << "big endian" << endl;
    }else{
        cout << "little endian" << endl;
    }

    cout << "第一个实验" << endl;
    Data::show_int(5546);
    cout << "==============" << endl;
    Data::show_float(3.54f);
    cout << "==============" << endl;
    Data::show_double(546.62);
    cout << "==============" << endl;
    Data::show_long(45645);
    cout << "==============" << endl;

//    验证IEEE的编码方式
    cout <<endl << "第二个实验" << endl;
    float float1 = 0.25f;
    Decimal::show_float(float1);
    Data::show_float(float1);
    cout << "==========" << endl;
    float float2 = -2.565f;
    Decimal::show_float(float2);
    Data::show_float(float2);
    cout << "==========" << endl;

    double double1 = 5.2645;
    Decimal::show_double(double1);
    Data::show_double(double1);
    cout << "==========" << endl;
    double double2 = -4.656;
    Decimal::show_double(double2);
    Data::show_double(double2);
    cout << "==========" << endl;
    //Normalized/Denomalized/Infinity/Nan
    cout << endl << "第三个实验" << endl;
    Data::show_float(1.0 / 0.0);
    cout  << endl << "第四个实验" << endl;
    zip_dig cmu = {1, 5, 2, 1, 3};
    zip_dig mit = {0, 2, 1, 3, 9};
    zip_dig ucb = {9, 4, 7, 2, 0};
    cout << "cmu" << endl;
    for(int i = 0; i < 5; i++){
        cout << cmu[i] << "地址" << &cmu[i] << endl;
    }

    cout << "mit" << endl;
    for(int i = 0; i < 5; i++){
        cout << mit[i] << "地址" << &mit[i] << endl;
    }

    cout << "ucb" << endl;
    for(int i = 0; i < 5; i++){
        cout << ucb[i] << "地址" << &ucb[i] << endl;
    }
    cout  << endl << "第五个实验" << endl;
    Matrix::square(cmu, mit, ucb, 5, 3);

//第六题
    cout << endl << "第六个实验" << endl;
    cout << "c的地址" << &(foo.c) << endl;
    cout << "g的地址" << &(foo.g) << endl;
    cout << "e的地址" << &(foo.e) << endl;
    cout << "a的地址" << &(foo.a) << endl;
    cout << "h的地址" << &(foo.h) << endl;
    cout << "b的地址" << &(foo.b) << endl;
    cout << "d的地址";
    printf("0x%x\n", &foo.d);
    cout << "f的地址";
    printf("0x%x\n", &foo.f);
//第七题
    cout << endl << "第七个实验" << endl;
    cout << &(ele.e1.p) << endl;
    cout << &(ele.e1.y) << endl;

    cout << &(ele.e2.x) << endl;
    cout << &(ele.e2.next) << endl;

    return 0;
}

