#include <stdio.h>
#define AANTAL 5

int som(int, int);
int product(int, int);
int verschil(int, int);
void schrijf(const int *, int);
void vul_tabel(int *, int *, int *, int, int(*functie)(int, int));

int main() {
    int a[AANTAL];
    int b[AANTAL];
    int c[AANTAL];

    int i;

    for (i = 0; i < AANTAL; i++) {
        a[i] = 10 * i;
        b[i] = i;
    }

    vul_tabel(a, b, c, AANTAL, &som);
    schrijf(c, AANTAL);

    vul_tabel(a, b, c, AANTAL, &product);
    schrijf(c, AANTAL);

    vul_tabel(a, b, c, AANTAL, &verschil);
    schrijf(c, AANTAL);

    return 0;
}

void vul_tabel(int * a, int * b, int * c, int aantal, int(*functie)(int, int)) {
    int i;

    for (i = 0; i < aantal; i++) {
        c[i] = functie(a[i], b[i]);
    }
}

int som(int a, int b) {
    return a + b;
}

int product(int a, int b) {
    return a * b;
}

int verschil(int a, int b) {
    return a - b;
}

void schrijf(const int * t, int aantal) {
    int i;
    for (i = 0; i < aantal; i++) {
        printf("%i ", t[i]);
    }

    printf("\n");
}