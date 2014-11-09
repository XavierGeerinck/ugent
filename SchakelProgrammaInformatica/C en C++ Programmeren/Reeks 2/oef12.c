#include <stdio.h>

main() {
    int i, j;
    double d;
    int *ip, *jp;
    double *dp;
    i = 7;

//    ip = &7;
    jp = &i;
    *jp = j;
    *ip = i;
    ip = &j;

//    &i = ip;
    j = 4;
    (*ip)++;
//    &d = dp;
    *ip *= i;
    *jp = *&j;
    ip++;
    i = ip - &i;
    dp = &i;
    dp = ip;
    /*&dp = &&d;*/
    *ip += 1;
    *ip++;
    int t[25];
    int *tp = t;
    j = &t[5] - tp;

    printf("%d, %d, %lf", i, j, d);
}