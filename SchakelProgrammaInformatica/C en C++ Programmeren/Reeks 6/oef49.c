#include <stdio.h>

/**
 * Schrijf een programma dat twee getallen inleest en het product van beide getallen bepaalt zonder
 * gebruik te maken van de vermenigvuldigingsoperator *
 *
 * vb: 5 * 3 = 15
 * 0101
 * 0011
 *
 * = 00100011
 *
 * 1 * 101 + 1 * 101 + 0 * 101
 * 101 + 101 = 1111
 *
 */

int multiply(int, int);

int main() {
    printf("Vermenigvuldigd 5 x 3 = %d\n", multiply(5, 3));
    printf("Vermenigvuldigd 7 x 0 = %d\n", multiply(7, 0));
    printf("Vermenigvuldigd 300 x 1000 = %d", multiply(300, 1000));
}

/*
While b is not 0, we check the lsb of b and add this to the result if this is 1.
Then we shift a 1 to the left and b one to the right

example:
5 x 3
0101 x 0011 =
result += 5
a = 1010
b = 0001

result += 10
a = 10100
b = 0000

STOP

==> Dit neemt getal a, en telt dit altijd op bij resultaat, a wordt vermenigvuldigd met 2 de hele tijd.
 */
int multiply(int a, int b) {
    int result = 0;

    while (b != 0) {
        if (b & 0x1) {
            result += a;
        }

        a <<= 1;
        b >>= 1;
    }

    return result;
}