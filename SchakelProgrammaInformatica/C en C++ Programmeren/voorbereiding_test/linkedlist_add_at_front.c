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

    int g;

    scanf("%d", &g);

    while(g != 0) {
        Knoop * n = malloc(sizeof(Knoop));
        n->waarde = g;
        n->next = start;
        start = n;
        scanf("%d", &g);
    }

    return start;
}
