/**
 * 1) Test met 0x80 (Dit meet of XOR moet gebeuren of niet)
 * 2) Schuif register naar links en voeg nieuwe bit toe (van de input dus)
 * 3) Afhankelijk van punt 1)
 *      1) Als == 0, dan niets
 *      2) Als == 0x80 dan XOR met de 3 punten (3 punten = 01010001 = 0x51)
 */
#include <stdio.h>

int main() {
    int input = 0x666;
    int crc_register = 0x0;
    int XOR = 0x51;
    int test_needed = 0;

    while (input) {
        /* xor nodig? */
        if (crc_register & 0x80) {
            test_needed = 1;
            printf("XOR Nodig\n");
        }

        crc_register <<= 1; /* Schuif 1 naar links */
        crc_register |= (input & 1); /* Voeg meest rechtse bit van input toe */
        input >>= 1;

        if (test_needed == 1) {
            crc_register ^= XOR; /* XOR met 3 punten */
            test_needed = 0;
        }


        printf("%d\n", crc_register);
    }

    /* Nog een laatste keer omdat we niet meer aan het bijvullen zijn */
    if (crc_register & 0x80) {
        test_needed = 1;
        printf("XOR Nodig\n");
    }

    crc_register <<= 1; /* Schuif 1 naar links */

    if (test_needed == 1) {
        crc_register ^= XOR; /* XOR met 3 punten */
        test_needed = 0;
    }

    /* Steek juist de laatste 8 er in */
    crc_register &= 0xFF;

    /* Print resultaat */
    printf("%d", crc_register);
}