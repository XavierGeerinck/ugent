#include <stdio.h>

void schrijf_letter_voor_letter(const char * w, int aantal){
    int i;
    for(i=0; i<aantal; i++){
        printf("%c",w[i]);
    }
}

int main(){
    char w[8] = {'0','1','2','3','4','5','6','7'};
    char * locatie = w+2;
    int i;
    for(i=0; i<100; i++){               /* sluit programma evt. voortijdig met Ctrl-C */
        printf("\nGeef een woord: ");
        scanf("%s",locatie);
        printf("Via printf:                      %s.\n",locatie);
        printf("Via tabelelementen uitschrijven: ");
        schrijf_letter_voor_letter(w,6);
        printf(".\n");
    }
	
    return 0;
}
