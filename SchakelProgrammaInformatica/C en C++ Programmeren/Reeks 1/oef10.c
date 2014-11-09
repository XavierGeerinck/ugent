#include <stdio.h>

int main() {
    int i;
    int width = 3;

    for (i = 0; i <= 64; i++) {
        printf("oct: %*o dec: %*i hex: %*X\n", width, i, width, i, width, i);
    }

    return 0;
}