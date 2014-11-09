#include <stdio.h>

#define LENGTH 8

void shift_char_left(char row[], int);
void print_array(char row[], int length);
void shift_char_left_pointer(char *, int);

int main() {
    char row[LENGTH] = { 's', 'a', 'p', 'a', 'p', 'p', 'e', 'l' };
    print_array(row, LENGTH);
    shift_char_left_pointer(row, LENGTH);
    shift_char_left_pointer(row, LENGTH);
    shift_char_left_pointer(row, LENGTH);
    print_array(row, LENGTH);
}

void print_array(char row[], int length) {
    int i;

    for (i = 0; i < length; i++) {
        printf("%c", row[i]);
    }

    printf("\n");
}

void shift_char_left(char row[], int length) {
    /* Save temp char */
    char temp = row[0];
    int i = 0;

    /* Shift every char to left */
    while (i < length) {
        row[i] = row[i + 1];
        i++;
    }

    /* Add our temp char on the end */
    row[length - 1] = temp;
}

void shift_char_left_pointer(char *row, int length) {
    int i;

    /* Temp save */
    char temp = *row;

    for (i = 0; i < length; i++) {
        *(row + i) = *(row + i + 1);
    }

    *(row + length - 1) = temp;
}
