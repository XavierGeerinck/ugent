#include <stdio.h>

int cijfersom(int);
int cijfersom_herhaald(int);

int main() {
    int input; /* Input number to count digits */

    printf("Number to count: ");
    scanf("%d", &input);

    printf("Result = %d\n", cijfersom(input));
    printf("Result Herhaald = %d", cijfersom_herhaald(input));
}

int cijfersom(int input) {
    int rest;
    int sum = 0;

    /* While input > 0 */
    while (input) {
        rest = input % 10;
        input = input / 10;
        sum += rest;
    }

    return sum;
}

int cijfersom_herhaald(int input) {
    int result = cijfersom(input);

    if (result >= 10) {
        return cijfersom_herhaald(result);
    }

    return result;
}