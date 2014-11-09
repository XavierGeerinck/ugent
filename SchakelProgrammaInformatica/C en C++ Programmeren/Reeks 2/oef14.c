#include <stddef.h>
#include <stdio.h>

#define LENGTH 5

int index_of(double[], int, double);
double *place_of(double[], int, double);

int main() {
    double table[LENGTH] = { 0.0, 0.5, 1.0, 1.5, 2.0 };

    printf("IndexOf 0.5: %d\n", index_of(table, LENGTH, 1.5));
    printf("PlaceOf 0.5: %p", place_of(table, LENGTH, 1.5));
}

int index_of(double table[], int length, double number) {
    int i = 0;

    while (i < length) {
        if (table[i] == number) {
            return i;
        }

        i++;
    }

    return -1;
}

double *place_of(double table[], int length, double number) {
    int i = 0;

    while (i < length) {
        if (table[i] == number) {
            return &table[i];
        }

        i++;
    }

    return NULL;
}
