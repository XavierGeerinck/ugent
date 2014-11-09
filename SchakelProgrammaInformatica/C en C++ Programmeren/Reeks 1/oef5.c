#include <stdio.h>

int main() {
    int rij[] = { 8, 4, 2, 6, 0, 10 };
    int x; // Input our number to find
    int i; // For loop
    int index = -1; // Index of the found number x

    printf("Geef een geheel getal op ");
    scanf("%i", &x);

    for (i = 0; i < sizeof(rij) / sizeof(int); i++) {
        if (rij[i] == x) {
            index = i;
        }
    }

    if (index == -1) {
        printf("\nHet getal %i werd niet gevonden", x);
        return 0;
    }

    printf("\nHet getal %i werd gevonden op plaats %i.", x, index);
    return 0;
}