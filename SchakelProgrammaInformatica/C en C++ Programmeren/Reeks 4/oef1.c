#include <stdlib.h>
#include <stdio.h>

typedef struct Getal Getal;

void schrijf(const Getal *);

struct Getal {
    int waarde; /* Geheel getal */
    int aantal_delers; /* Hoeveel delers tusen 1 en waarde dit getal heeft */
    int *delers; /* pointer naar een tabel van ints waar de delers te vinden zijn, we gebruiken pointer omdat dit een dynamische tabel is */
};

int main() {
    Getal * getal = (Getal *)malloc(sizeof(getal));
    getal->waarde = 6;
    getal->aantal_delers = 3;
    getal->delers = malloc(sizeof(int) * 3);

    getal->delers[0] = 1;
    getal->delers[1] = 2;
    getal->delers[2] = 3;

    schrijf(getal);

    free(getal);
}

void schrijf(const Getal *getal) {
    int i = 0;

    for (i = 0; i < getal->aantal_delers; i++) {
        printf("%d ", *(getal->delers + i));
    }
}