#include <stdio.h>

main(){

    char woord [100];
    int geheelgetal;
    double kommagetal;
    char karakter;

    /* Voor elk type input (woorden, getallen, karakters) een aparte scanf-opdracht */
    printf("Geef een woord in: ");
    scanf("%s",woord);
    printf("Geef een geheel getal in: ");
    scanf("%i",&geheelgetal);
    printf("Geef een kommagetal in: ");
    scanf("%lf",&kommagetal);
    printf("Geef een karakter in: ");
    scanf("%c",&karakter);
    printf("Ik las in: %s|%i|%f|%c.\n",woord,geheelgetal,kommagetal,karakter);

    /* Woorden, getallen, karakters in dezelfde scanf-opdracht; spaties ertussen */
    printf("Geef woord, geheel getal, kommagetal en karakter in - ");
    printf("gescheiden door spaties.\n");
    scanf("%s %i %lf %c",woord,&geheelgetal,&kommagetal,&karakter);
    printf("Ik las in: %s|%i|%f|%c.\n",woord,geheelgetal,kommagetal,karakter);

    /* Woorden, getallen, karakters in dezelfde scanf-opdracht; komma's ertussen*/
    printf("Geef woord, geheel getal, kommagetal en karakter in - ");
    printf("gescheiden door komma's.\n");
    scanf("%s,%i,%lf,%c",woord,&geheelgetal,&kommagetal,&karakter);
    printf("Ik las in: %s|%i|%f|%c.\n",woord,geheelgetal,kommagetal,karakter);

}