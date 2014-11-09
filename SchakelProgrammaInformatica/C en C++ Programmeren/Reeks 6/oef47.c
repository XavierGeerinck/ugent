#include <stdio.h>
#include <stdlib.h>
#include <math.h>

typedef unsigned int uint;

char* int2bits(uint x, uint lengte){
    char * c = (char*) malloc((lengte+1)*sizeof(char));
    uint i;
    for(i=0; i<lengte; i++){
        c[lengte-1-i] = '0'+(x%2);
        x/=2;
    }
    c[lengte] = 0;
    return c;
}

void schrijf(uint i, uint lengte){
    char * bits = int2bits(i,lengte);
    printf("%s %u",bits,i);  /* merk op: %u */
    free(bits);
}

void schrijf_lijstje(uint aantal){
    uint lengte = (uint)(log(aantal))+1;
    uint i=0;
    for(i=0; i<aantal; i++){
        schrijf(i,lengte);
        printf("\n");
    }
    printf("\n");
}