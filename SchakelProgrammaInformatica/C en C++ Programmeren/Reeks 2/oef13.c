#include <stdio.h>
#include <string.h>

#define LENGTH 10

void write_table(int[], int);

int main() {
    int table[LENGTH];

    write_table(table, LENGTH);

    memset(table, 0, sizeof(table));

    write_table(table, LENGTH);
}

void write_table(int table[], int length) {
    int i;

    /* Print size table */
    printf("%d\n", length);

    /* Print content table */
    for (i = 0; i < length; i++) {
        printf("%d ", table[i]);
    }

    printf("\n");
}
