#include <stdlib.h>

typedef struct Knoop Knoop;

struct Knoop {
    int d;
    Knoop * op;
};

int main() {
    Knoop * l = 0;
    Knoop * k = l;
    k = malloc(sizeof(Knoop));

    Knoop ** m = &l;
    m[0] = malloc(sizeof(Knoop));

    l->d = 5;

    printf("%d", l->d);
}