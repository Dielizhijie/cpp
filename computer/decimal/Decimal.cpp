#include "Decimal.h"
#include <string>
using namespace std;

void Decimal::show_float(float x) {
    int s;
    int E;
    string M;

    //求符号位
    if(x >= 0) {
        s = 0;
    }else {
        x = 0 - x;
        s = 1;
    }

    //求不完整的尾数位
    int x_integer = x;
    float x_demical = x - x_integer;
    //先将整数转为二进制
    string str_integer;
    while(x_integer > 1){
        char num = '0' + (x_integer % 2);
        x_integer = x_integer / 2;
        str_integer = str_integer + num;
    }
    char num = '0' + x_integer;
    str_integer = str_integer + num;
    int number = str_integer.length();
    for(int i = 0; i < number; i++){
        M += str_integer.at(number - 1 - i);
    }

    //将小数部分转为二进制数
    while (x_demical > 0){
        x_demical = x_demical * 2;
        if(x_demical < 1){
            M += "0";
        }
        if(x_demical > 1){
            M += "1";
            x_demical = x_demical -1;
        }
        if(x_demical == 1) {
            M += "1";
            break;
        }

        if(M.length() >= 23) {
            break;
        }
    }
    //求指数位
    int numOfM = M.length();
    int index = 0;
    for(int i = 0; i < numOfM; i ++) {
        if(M.at(i) == '1') {
            index++;
            break;
        } else {
            index++;
        }
    }
    string M1;
    for(int i = index; i < numOfM; i++) {
        M1 += M.at(i);
    }
    for(int i = M1.length(); i < 23; i++) {
        M1 += "0";
    }

    if(x_integer == 0){
        E = 0 - index;
    } else {
        E = number - index;
    }
    E = E + 127;
    string strE;
    while(E > 1){
        char num = '0' + (E % 2);
        E = E / 2;
        strE = strE + num;
    }
    char numE = '0' + E;
    strE = strE + numE;
    for(int i = strE.length(); i < 8; i++) {
        strE += "0";
    }
    string E1;
    for(int i = 0; i < 8; i++){
        E1 += strE.at(7 - i);
    }

    cout << "符号位 s = " << s << "" << endl;
    cout << "指数位指数 E = " << E1  << endl;
    cout << "尾数位 M = "  << M1 << endl;
}

void Decimal::show_double(double x) {
    int s;
    int E;
    string M;

    //求符号位
    if(x >= 0) {
        s = 0;
    }else {
        x = 0 - x;
        s = 1;
    }

    //求不完整的尾数位
    int x_integer = x;
    float x_demical = x - x_integer;
    //先将整数转为二进制
    string str_integer;
    while(x_integer > 1){
        char num = '0' + (x_integer % 2);
        x_integer = x_integer / 2;
        str_integer = str_integer + num;
    }
    char num = '0' + x_integer;
    str_integer = str_integer + num;
    int number = str_integer.length();
    for(int i = 0; i < number; i++){
        M += str_integer.at(number - 1 - i);
    }

    //将小数部分转为二进制数
    while (x_demical > 0){
        x_demical = x_demical * 2;
        if(x_demical < 1){
            M += "0";
        }
        if(x_demical > 1){
            M += "1";
            x_demical = x_demical -1;
        }
        if(x_demical == 1) {
            M += "1";
            break;
        }

        if(M.length() >= 52) {
            break;
        }
    }
    //求指数位
    int numOfM = M.length();
    int index = 0;
    for(int i = 0; i < numOfM; i ++) {
        if(M.at(i) == '1') {
            index++;
            break;
        } else {
            index++;
        }
    }
    string M1;
    for(int i = index; i < numOfM; i++) {
        M1 += M.at(i);
    }
    for(int i = M1.length(); i < 52; i++) {
        M1 += "0";
    }

    if(x_integer == 0){
        E = 0 - index;
    } else {
        E = number - index;
    }
    E = E + 1023;
    string strE;
    while(E > 1){
        char num = '0' + (E % 2);
        E = E / 2;
        strE = strE + num;
    }
    char numE = '0' + E;
    strE = strE + numE;
    for(int i = strE.length(); i < 11; i++) {
        strE += "0";
    }
    string E1;
    for(int i = 0; i < 11; i++){
        E1 += strE.at(10 - i);
    }

    cout << "符号位 s = " << s << "" << endl;
    cout << "指数位指数 E = " << E1  << endl;
    cout << "尾数位 M = "  << M1 << endl;
}