#include <stdio.h>

int main() {
    char rij[] = { 's', 'a', 'p', 'p', 'e', 'l', 'm', 'o', 'e' };
    int sizeRij = sizeof(rij) / sizeof(char);
    char newRij[sizeRij];
    int i = 0;
    int result;

    for (i = 0; i < sizeRij; i++) {
        if (i == 0) result = sizeRij - 1;
        else result = i - 1;

        /* printf("%d = %d\n", i, result); */
        newRij[result] = rij[i];
    }

    printf("%s\n", newRij);
}