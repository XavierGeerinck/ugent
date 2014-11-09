#include<stdio.h>
int main(){
    int lijnlengte=40;
    int AANTAL=0;
    int i=0,j=0;
    printf("Hoeveel lijnen sterretjes wil je? ");
    scanf("%d",&AANTAL);
    while(i<AANTAL){
        while(j<=i && j<40) {
            printf("*");
            j++;
        }
        printf("\n");
        i++;
        j = 0;
    }
    return 0;
}