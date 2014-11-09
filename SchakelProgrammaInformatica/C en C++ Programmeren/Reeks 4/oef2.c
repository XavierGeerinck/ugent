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
    Getal * t = (Getal *)malloc(sizeof(Getal) * 5);
    Getal * p = t;

    t[2].waarde = 24;
    t[2].aantal_delers = 7;
    t[2].delers = malloc(sizeof(int) * 7);
    t[2].delers[0] = 1;
    t[2].delers[1] = 2;
    t[2].delers[2] = 3;
    t[2].delers[3] = 4;
    t[2].delers[4] = 6;
    t[2].delers[5] = 8;
    t[2].delers[6] = 12;

    p += 2;

    printf("%d\n", t[2].waarde);
    printf("%d\n", p->waarde);

    int * k = t[2].delers;
    /* int * k = p->delers; */

    k += 3;

    printf("Value 4: %d\n", *k);
    printf("Value 4: %d\n", t[2].delers[3]);
    printf("Value 4: %d\n", p->delers[3]);

    free(t);
}

void schrijf(const Getal *getal) {
    int i = 0;

    for (i = 0; i < getal->aantal_delers; i++) {
        printf("%d ", *(getal->delers + i));
    }
}