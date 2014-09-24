#include <stdio.h>

int main() {
    char table[9] = { 'b', 'f', 'r', 'o', 'a', 'u', 'v', 't', 'o' };
    int i = 0;

    for (i = 0; i < sizeof(table) / sizeof(char); i += 2) {
        printf("%c", table[i]);
    }
}