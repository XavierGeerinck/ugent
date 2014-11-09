#include <stdio.h>
#include <stdlib.h>

typedef struct Knoop Knoop;

struct Knoop {
    int waarde;
    Knoop * next;
};

Knoop * maak_lijst();

int main() {
    Knoop *h;
    Knoop *lijst_start = maak_lijst();

    /* Print list */
    h = lijst_start;

    while (h) {
        printf("Waarde: %d \n", h->waarde);

        h = h->next;
    }

    /* Clear memory */
    free(lijst_start);
}

Knoop * maak_lijst() {
    Knoop *start = NULL;
    Knoop *h, *h2;

    int getal;

    scanf("%d", &getal);

    while (getal != 0) {
        Knoop *n = malloc(sizeof(Knoop));
        n->waarde = getal;
        n->next = NULL;

        if (!start || start->waarde > getal) {
            n->next = start;
            start = n;
        } else {
            h = start;

            while (h->next != 0 && h->next->waarde < getal) {
                h = h->next;
            }

            h2 = h->next;
            h->next = n;
            h = h->next;
            h->next = h2;

            scanf("%d", &getal);
        }
    }

    return start;
}
