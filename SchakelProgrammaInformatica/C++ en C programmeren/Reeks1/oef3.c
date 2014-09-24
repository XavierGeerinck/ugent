#include <stdio.h>

int faculteit();
void schrijf_faculteit();

int main() {
    schrijf_faculteit(40);
}

/*
Faculteit is het product van alle vorige getallen tot dit getal,
bv: 5! = 1 * 2 * 3 * 4 * 5
 */
int faculteit(int getal) {
    int i = 0;
    int result = 1;

    for (i = 2; i <= getal; i++) {
        result *= i;
    }

    return result;
}

/*
schrijft de faculteit uit voor het gegeven getal
 */
void schrijf_faculteit(int getal) {
    int i = 0;

    for (i = 1; i <= getal; i++) {
        printf("%2d! = %-20d\n", i, faculteit(i));
    }
}