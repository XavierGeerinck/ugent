#include <stdio.h>

int main() {
    int list[] = { 1, 0, 5, -1, 7 };
    int listSize = sizeof(list) / sizeof(int);
    double result = 0.0;
    double powerResult;
    int i, j;
    double x; // input X

    scanf("%lf", &x);

    for (i = 0; i < listSize; i++) {
        /* Reset powerResult */
        powerResult = 1;

        /* If the power of the X is bigger then 0, calculate X */
        if (listSize - i - 1 > 0) {
            for (j = 0; j < listSize - i - 1; j++) {
                if (j == 0) powerResult = x;
                else powerResult *= x;
            }

        }

        printf("%2dx^%d = %lf\n", list[i], listSize - i - 1, powerResult * list[i]);
        result += (powerResult * list[i]);
    }

    printf("%lf\n", result);
}