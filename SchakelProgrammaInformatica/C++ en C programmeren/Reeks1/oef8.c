#include <stdio.h>

#define PI 3.14159265359

double my_sine(double);
double power(double, int);
int calculate_faculty(int);
double calculate_taylor_sine(double);

int main() {
    printf("%lf", my_sine(23));
}

/*
Calculate Sinus in degrees (we convert it to radians)
 */
double my_sine(double degrees) {
    double basic_sine =  degrees / 180 * PI;
    double taylor_row = calculate_taylor_sine(basic_sine);
    return basic_sine - taylor_row;
}

/*
Taylor for Sine x - (x^3/3!) + (x^5/5!) + (x^7/7!)
 */
double calculate_taylor_sine(double x) {
    int i, j;
    double result = 0.0;

    for (i = 3, j = 1; i <= 7; i += 2, j++) {
        if (j % 2 == 0) {
            result -= (power(x, i) / calculate_faculty(i));
        } else {
            result += (power(x, i) / calculate_faculty(i));
        }
    }

    return result;
}

double power(double base, int n) {
    double p = 1.0;
    int i;
    for (i=1 ; i<=n ; i++) p *= base;
    return p;
}

int calculate_faculty(int number) {
    int i = 0;
    int result = 1;

    for (i = 2; i <= number; i++) {
        result *= i;
    }

    return result;
}

