#include <stdio.h>
int main(){
    int t[6] = {0,10,20,30,40,50};
    int* pt[3];
    int i;
    for(i=0; i<3; i++){
        pt[i] = &t[2*i];
    }
    pt[1] += 3;
    *(pt[0]+1) *= 2;
    pt[2] = pt[1];
    *pt[1] += 1;
    *pt[2] *= 2;

    int ** ppt = &pt[0];
    (*ppt)++;
    **pt += 1;
    for(i=0; i<sizeof(pt)/sizeof(int*); i++){
        printf("%d ",*pt[i]);
    }
    printf("\n");
    return 0;
}