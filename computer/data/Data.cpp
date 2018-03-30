#include "Data.h"
using namespace std;

void Data::show_bytes(byte_pointer start, size_t len) {
    size_t i;

    for(i = 0; i < len; i++) {
        printf("%.2x", start[i]);
        printf("\n");
    }
}

void Data::show_int(int x) {
    show_bytes((byte_pointer) &x, sizeof(int));
}

void Data::show_long(long x) {
    show_bytes((byte_pointer) &x, sizeof(long));
}

void Data::show_float(float x) {
    show_bytes((byte_pointer) &x, sizeof(float));
}

void Data::show_double(double x) {
    show_bytes((byte_pointer) &x, sizeof(double));
}

void Data::show_pointer(void *x) {
    show_bytes((byte_pointer) &x, sizeof(void *));
}

