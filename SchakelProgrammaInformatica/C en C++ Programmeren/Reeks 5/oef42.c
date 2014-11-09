#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

#define MAX_LENGTE 10

void sorteer(void * tabel, int aantal, int grootte, int (*comparator)(void *, void *));
void schrijf(const int * tabel, int aantal);
void vul(int * tabel, int aantal);
int is_gesorteerd(const int * tabel, int aantal);
int vergelijk_int(const int *a, const int *b);

int main(){
    int tabel[MAX_LENGTE];
    int test_geslaagd = 1;
    int lengte;

    srand(time(NULL));


    for(lengte=1; lengte<MAX_LENGTE; lengte++){
        vul(tabel,lengte);
        sorteer(tabel, lengte, sizeof(int), (int (*)(void *, void *))vergelijk_int);
        if(!is_gesorteerd(tabel,lengte)){
            printf("Niet ok voor lengte %d.\n",lengte);
            schrijf(tabel,lengte);
            test_geslaagd = 0;
        }
    }
    if(test_geslaagd == 1){
        schrijf(tabel,lengte);
        printf("test geslaagd");  /* laat iets weten als alles ok was; dat is
		                             net iets beleefder dan gewoon zonder meer afsluiten... */
    }
    return 0;
}

/*
- Voor elk element in een tabel, vergelijk met de vorige, als 1 dan is het ok, als 0 verzet naar links
vb voor: 1,4,5,2,7,5
Als we element 2 hebben, dan gaan we dit in een temp var steken.
Nu gaan we zolang we niet aan index 0 zitten kijken of de vorige variabele < is dan 2
We herhalen dit tot < 2
Nu zetten we die vorige variabele aan de temp variabele en de index van 2 gelijk aan de vorige variabele

- Grootte: Dit is het byte geheugen om te comparen
 */
void sorteer(void * tabel, int aantal, int grootte, int (*comparator)(void *, void *)){  /* geen const !! */
    void * hulp = malloc(grootte);
    int i, j;

    /* Voor elk element */
    for (i = 1; i < aantal; i++) {
        j = i - 1;

        /* Kopieer onze waarde in een hulp pointer */
        memcpy(hulp, (tabel + (i * grootte)), grootte);

        /* Dan ga kijken zolang we geen 0 bekomen waar dit moet komen */
        while(j >= 0 && comparator(tabel + j * grootte, hulp)) {
            memcpy(tabel + (j + 1) * grootte, tabel + (j * grootte), grootte);
            j--;
        }

        memcpy(tabel + (j + 1) * grootte, hulp, grootte);
    }

    free(hulp);
}

int vergelijk_int(const int *a, const int *b) {
    if (*a > *b) {
        return 1;
    }

    return 0;
}

void schrijf(const int * tabel, int aantal){  /* const !! */
    int i;
    for(i=0; i<aantal; i++){
        printf("%d ",tabel[i]);
    }
}

int is_gesorteerd(const int * tabel, int aantal){
    int i=1;
    while(i < aantal && tabel[i-1] <= tabel[i]){
        i++;
    }
    return i==aantal;
}

void vul(int * tabel, int aantal){
    int i;
    for(i=0; i<aantal; i++){
        tabel[i] = rand()%(2*aantal);
    }
}
