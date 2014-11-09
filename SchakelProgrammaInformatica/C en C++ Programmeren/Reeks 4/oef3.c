#include <stdlib.h>
#include <stdio.h>
#include <time.h>

#define AANTAL_GETALLEN 21

typedef struct Getal Getal;

void schrijf(const Getal *);
int * delers_van(const int, int);
int aantal_delers_func(const int);

struct Getal {
    int waarde; /* Geheel getal */
    int aantal_delers; /* Hoeveel delers tusen 1 en waarde dit getal heeft */
    int *delers; /* pointer naar een tabel van ints waar de delers te vinden zijn, we gebruiken pointer omdat dit een dynamische tabel is */
};

int main() {
    srand(time(NULL));
    int i, random_value, aantal_delers;
    Getal getal;
    Getal * getallen;

    getallen = (Getal *)malloc(sizeof(Getal) * AANTAL_GETALLEN);
    for (i = 0; i < AANTAL_GETALLEN; i++) {
        random_value = rand() % 21 + 10;
        aantal_delers = aantal_delers_func(random_value);

        getal.waarde = random_value;
        getal.aantal_delers = aantal_delers;
        getal.delers = delers_van(random_value, aantal_delers);

        getallen[i] = getal;
    }

    for (i = 0; i < AANTAL_GETALLEN; i++) {
        schrijf(&getallen[i]);
    }
}

int aantal_delers_func(int x) {
    int i, aantal_delers = 0;

    for (i = 2; i < x / 2; i++) {
        if (x % i == 0) {
            aantal_delers++;
        }
    }

    return aantal_delers;
}

int * delers_van(int x, int aantal_delers) {
    int i, j = 0;
    int * delers = malloc(sizeof(int) * aantal_delers);

    for (i = 2; i <= (x / 2); i++) {
        if (x % i == 0) {
            delers[j] = i;
            j++;
        }
    }

    return delers;
}

void schrijf(const Getal *getal) {
    int i, j;

    for (i = 0; i < AANTAL_GETALLEN; i++) {
        printf("Getal: %d\nAantal Delers: %d\nDelers:\n", getal->waarde, getal->aantal_delers);

        for (j = 0; j < getal->aantal_delers; j++) {
            printf("----Deler: %d\n", getal->delers[j]);
        }
    }
}
