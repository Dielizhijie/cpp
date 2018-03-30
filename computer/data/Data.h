#ifndef COMPUTER_DATA_H
#define COMPUTER_DATA_H
#include <iostream>

class Data {

    public:typedef unsigned char *byte_pointer;

    public:static void show_bytes(byte_pointer start, size_t len);

    public:static void show_int(int x);

    public:static void show_long(long x);

    public:static void show_float(float x);

    public:static void show_double(double x);

    public:static void show_pointer(void *x);

};
#endif //COMPUTER_DATA_H
