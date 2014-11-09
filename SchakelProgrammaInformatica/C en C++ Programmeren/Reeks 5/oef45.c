#include <stddef.h>
#include <time.h>
#include <stdlib.h>
#include <stdio.h>
#include <pthread.h>

#define MATRIX_RIJEN_KOLOMMEN 100
#define N_THREADS 4

void matrix_zonder_pthread();
void matrix_met_pthread();
void * bereken_rij(void * start_rij);

int a[MATRIX_RIJEN_KOLOMMEN][MATRIX_RIJEN_KOLOMMEN];
int b[MATRIX_RIJEN_KOLOMMEN][MATRIX_RIJEN_KOLOMMEN];
int result[MATRIX_RIJEN_KOLOMMEN][MATRIX_RIJEN_KOLOMMEN];

int main () {
    /*matrix_zonder_pthread();*/
    matrix_met_pthread();
}

void matrix_met_pthread() {
    int i, j, sum, k;
    pthread_t p[N_THREADS];

    srand(time(NULL));

    /* Vul matrix */
    for (i = 0; i < MATRIX_RIJEN_KOLOMMEN; i++) {
        for (j = 0; j < MATRIX_RIJEN_KOLOMMEN; j++) {
            a[i][j] = rand() % 30 + 1;
            b[i][j] = rand() % 30 + 1;
        }
    }

    /* Bereken vermenigvuldiging */
    for (i = 0; i < N_THREADS; i++) {
        pthread_create(&p[i], NULL, bereken_rij, &j);
    }

    for (i = 0; i < N_THREADS; i++) {
        pthread_join(p[i], NULL);
    }


    /* Print result */
    for (i = 0; i < MATRIX_RIJEN_KOLOMMEN; i++) {
        for (j = 0; j < MATRIX_RIJEN_KOLOMMEN; j++) {
            printf(" %d ", result[i][j]);
        }
        printf("\n");
    }
}

void * bereken_rij(void * start_rij) {
    int i, j, sum, k;

    /* Bereken vermenigvuldiging */
    for (i = *(int *)start_rij; i < *(int *)start_rij + (MATRIX_RIJEN_KOLOMMEN / N_THREADS); i++) {
        for (j = 0; j < MATRIX_RIJEN_KOLOMMEN; j++) {
            sum = 0;

            for (k = 0; k < MATRIX_RIJEN_KOLOMMEN; k++) {
                sum = sum + a[i][k] * b[k][j];
            }

            result[i][j] = sum;
        }
    }
}

void matrix_zonder_pthread() {
    int i, j, sum, k;

    srand(time(NULL));

    /* Vul matrix */
    for (i = 0; i < MATRIX_RIJEN_KOLOMMEN; i++) {
        for (j = 0; j < MATRIX_RIJEN_KOLOMMEN; j++) {
            a[i][j] = rand() % 30 + 1;
            b[i][j] = rand() % 30 + 1;
        }
    }

    /* Bereken vermenigvuldiging */
    for (i = 0; i < MATRIX_RIJEN_KOLOMMEN; i++) {
        for (j = 0; j < MATRIX_RIJEN_KOLOMMEN; j++) {
            sum = 0;

            for (k = 0; k < MATRIX_RIJEN_KOLOMMEN; k++) {
                sum = sum + a[i][k] * b[k][j];
            }

            result[i][j] = sum;
        }
    }

    /* Print result */
    for (i = 0; i < MATRIX_RIJEN_KOLOMMEN; i++) {
        for (j = 0; j < MATRIX_RIJEN_KOLOMMEN; j++) {
            printf(" %d ", result[i][j]);
        }
        printf("\n");
    }
}
