#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main(){
    srand(time(NULL));
    printf("Ik genereer 5 getallen tussen 1 en 10: ");
    int som = 0;
    int i, a;
    for(i=0; i<5; i++){
        a = rand()%10+1;
        som += a;
        printf("%d ",a);
    }
    printf("\nDe som van deze getallen is %d",som);
    return 0;
}