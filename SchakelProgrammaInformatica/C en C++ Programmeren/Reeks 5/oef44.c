#include <time.h>
#include <stdlib.h>
#include <stdio.h>
#include <pthread.h>

#define TABEL_GROOTTE 1000000

void vul_tabel(double * tabel, int grootte);
void * vind_grootste(void * grootste);
void * vind_kleinste(void * kleinste);
void print_tabel(double * tabel, int grootte);

double tabel[TABEL_GROOTTE];

int main() {
    double grootste, kleinste;

    pthread_t vind_grootste_thread;
    pthread_t vind_kleinste_thread;

    srand(time(NULL));

    vul_tabel(tabel, TABEL_GROOTTE);

    pthread_create(&vind_grootste_thread, NULL, vind_grootste, &grootste);
    pthread_create(&vind_kleinste_thread, NULL, vind_kleinste, &kleinste);

    pthread_join(vind_grootste_thread, NULL);
    pthread_join(vind_kleinste_thread, NULL);

    printf("Grootste: %lf\n", grootste);
    printf("Kleinste: %lf", kleinste);
}

void vul_tabel(double * tabel, int grootte) {
    int i;

    for (i = 0; i < TABEL_GROOTTE; i++) {
        tabel[i] = rand();
    }
}

void print_tabel(double * tabel, int grootte) {
    int i;

    for (i = 0; i < grootte; i++) {
        printf("%lf ", tabel[i]);
    }
}

void * vind_grootste(void * grootste) {
    int i;

    for (i = 0; i < TABEL_GROOTTE; i++) {
        if (tabel[i] > *(double *)grootste) {
            *(double *)grootste = tabel[i];
        }
    }
}

void * vind_kleinste(void * kleinste) {
    int i;

    *(double *)kleinste = tabel[0];

    for (i = 0; i < TABEL_GROOTTE; i++) {
        if (tabel[i] < *(double *)kleinste) {
            *(double *)kleinste = tabel[i];
        }
    }
}
