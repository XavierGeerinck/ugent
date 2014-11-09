#include <stdlib.h>
#include <stdio.h>

typedef struct Knoop Knoop;

void voeg_vooraan_toe(int d, Knoop **);
void schrijf(Knoop *);

struct Knoop {
    int d;
    Knoop * next;
};

int main() {
    Knoop * l = 0;

    voeg_vooraan_toe(7, &l);
    voeg_vooraan_toe(3, &l);
    voeg_vooraan_toe(3, &l);
    voeg_vooraan_toe(3, &l);
    voeg_vooraan_toe(3, &l);

    schrijf(l);
}

void voeg_vooraan_toe(int d, Knoop ** l_knoop) {
    /* Create Knoop */
    Knoop * temp = malloc(sizeof(Knoop));
    temp = malloc(sizeof(Knoop));
    temp->d = d;

    if (l_knoop) {
        temp->next = *l_knoop;
        *l_knoop = temp;
    } else {
        *l_knoop = temp;
    }
}

/* Print knopen */
void schrijf(Knoop * k) {
    Knoop *temp = k;

    while (temp && temp->next) {
        printf("%d ", k->d);
        temp = k->next;
    }
}
