#include <stdio.h>

int zijn_gelijk(int, int);
int tel_aantal_1bits(int);
int is_even(int);

int main() {
    printf("Zijn gelijk 5, 5: %d\n", zijn_gelijk(5, 5));
    printf("Zijn gelijk 5, 6: %d\n", zijn_gelijk(5, 6));
    printf("Zijn gelijk 223, 15: %d\n", zijn_gelijk(5, 6));

    printf("Aantal 1 bits van 5 moet 2 zijn: %d\n", tel_aantal_1bits(5));
    printf("Aantal 1 bits van 15 moet 4 zijn: %d\n", tel_aantal_1bits(15));

    printf("is_even? 5 moet 0 geven (oneven): %d\n", is_even(5));
    printf("is_even? 6 moet 1 geven (even): %d", is_even(6));

}

/**
* XOR == NOT EQUALS
*
* Not Not Equals = Equals
*/
int zijn_gelijk(int a, int b) {
    if (!(a^b)) {
        return 0;
    }

    return -1;
}

int tel_aantal_1bits(int getal) {
    int temp = getal;
    int count = 0;

    while (temp) {
        count += temp & 0x1;
        temp >>= 1;
    }

    return count;
}

/**
* Een getal is even als lsb is set.
*/
int is_even(int getal) {
    return !(getal & 0x1);
}