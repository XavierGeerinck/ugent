#include <stdlib.h>
#include <stdio.h>

typedef struct Knoop Knoop;

void schrijf(Knoop * m);
void voeg_vooraan_toe(int d, Knoop ** m);
Knoop ** vind_plaats(int d, Knoop ** l);
void voeg_toe(int d, Knoop ** l);

struct Knoop{
    int d;
    struct Knoop * op;
};

int main() {
    struct Knoop * l = 0;

    voeg_toe(2, &l);
    voeg_toe(8, &l);
    voeg_toe(9, &l);
    voeg_toe(0, &l);
    voeg_toe(5, &l);
    voeg_toe(3, &l);
    voeg_toe(1, &l);
    voeg_toe(7, &l);
    voeg_toe(4, &l);
    voeg_toe(6, &l);

    schrijf(l);
}

void voeg_vooraan_toe(int d, Knoop ** m) {
    Knoop *temp = (Knoop *)malloc(sizeof(Knoop));
    temp->d = d;
    temp->op = *m;

    *m = temp;
}

void voeg_toe(int d, Knoop ** l) {
    Knoop **plaats;
    Knoop *newKnoop;

    newKnoop = (Knoop *) malloc(sizeof(Knoop));
    newKnoop->d = d;

    /* If no pointer yet, then just create and add the new Knoop */
    if ((*l) == NULL) {
        newKnoop->op = *l;

        *l = newKnoop;
    }
    /* Else, vind een de knoop waar we deze nieuwe knoop aan toevoegen en voeg die toe */
    else {
        plaats = vind_plaats(d, l);

        /* Als plaats waarde kleiner dan d, voeg toe op plaats->op, anders voeg toe voor plaats->op */
        if ((*plaats)->d < d) {
            newKnoop->op = (*plaats)->op;
            (*plaats)->op = newKnoop;
        } else {
            newKnoop->op = (*l);
            (*l) = newKnoop;
        }
    }
}

Knoop ** vind_plaats(int d, Knoop ** l) {
    Knoop * temp = *l;

    while (temp && temp->op && temp->op->d < d) {
        temp = temp->op;
    }

    return &temp;
}

void schrijf(Knoop * m) {
    while (m) {
        printf("Knoop: %d\n", m->d);
        m = m->op;
    }
}
