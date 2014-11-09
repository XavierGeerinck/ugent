#include <stddef.h>
#include <time.h>
#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>

#define MAX_LENGTE 10

int main(){
    srand(time(NULL));

    int tabel[MAX_LENGTE];
    int test_geslaagd = 1;
    int lengte;

    for(lengte=1; lengte<=MAX_LENGTE; lengte++){
        vul(tabel,lengte);
        sorteer(tabel,lengte);
        if(!is_gesorteerd(tabel,lengte)){
            printf("Niet ok voor lengte %d.\n",lengte);
            schrijf(tabel,lengte);
            test_geslaagd = 0;
        }
    }
    if(test_geslaagd == 1){
        printf("test geslaagd"); /* laat iets weten als alles ok was; dat is net is beleefder dan gewoon zonder meer afsluiten... */
    }
    return 0;
}

void vul(int tabel[], int lengte) {
    int i;
    for (i = 0; i < lengte; i++) {
        tabel[i] = rand() % 20;
    }
}

void sorteer(int tabel[], int lengte) {

}

bool is_gesorteerd(int tabel[], int lengte) {

}

void schrijf(int tabel[], int lengte) {

}
