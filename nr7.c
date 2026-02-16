/*************************************************************************
* Kurzbeschreibung: Zahlen raten     Aufgabe: 17  ; Punkte: 0
*
* Datum: 10.05.2022      Autor:                       Grund der Aenderung:
*                        
*************************************************************************/

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

/*--- Funktionsdefinitionen ----------------------------------------------------*/
int main( void )
{
    char c;
    int zufall = 0, startwert = 1, endwert, nVersuch = 1, inputUser;

    /* Text */
    printf("Ich denke mir eine Zahl aus dem Intervall [1;x].\nSie muessen dann versuchen, die Zahl zu erraten.\n\n");
    printf("Zunaechst muessen Sie einmal festlegen, wie gross die zu\nerratende Zahlmaximal sein darf: ");
    scanf("%d%c", &endwert, &c);
    printf("\n");

    /* Ueberpruefen ob Zahl im Bereich liegt */
    while(endwert <= startwert || c != '\n')
    {
        /* Ueberpruefen ob es ein Buchstabe oder Zeichen ist */
        fflush(stdin);

        /* Erneutes einlesen der Zahl */
        printf("Geben Sie bitte eine Zahl ein, die groesser als 1 ist: ");
        scanf("%d%c", &endwert, &c);
        printf("\n");

    }

    /* Ausgabe einer Zufallszahl */
    srand(time(NULL));

    zufall = rand() % (startwert - endwert + 1) + startwert;

    /* Text */
    printf("Hm..... Ok, ich habe eine Zahl\n\n");

    do{
        /* Einlesen des Inputs */
        printf("Dein %d.Versuch: ", nVersuch);
        scanf("%d%c", &inputUser, &c);

        /* Ueberpruefen des Inputs */
        while(inputUser < startwert || inputUser > endwert || c != '\n')
        {
            /* Ueberpruefen ob es ein Buchstabe oder Zeichen ist */
            fflush(stdin);

            /* Erneutes einlesen der Zahl */
            printf("Geben Sie bitte eine Zahl ein, die im Intervall liegt: ");
            scanf("%d%c", &inputUser, &c);
        }

        /* Testen, ob input gleich der Zufallszahl */
        if (inputUser == zufall) {
            printf("%65s\n", "........Richtig");
        }
        /* Testen, ob input groesser als Zufallszahl */
        else if (inputUser > zufall) {
            printf("%65s\n", "........zu hoch");
        }
        /* Testen, ob input kleiner als Zufallszahl */
        else if (inputUser < zufall) {
            printf("%65s\n", ".....zu niedrig");
        }
        /* Ansonsten ERROR */
        else {
            printf("ERROR");
        }

        /* Naechster Versuch */
        nVersuch++;

    } while(inputUser != zufall);

    /* Ausgabe */
    printf("Du hast %d Versuche zum erraten der Zahl benötigt", nVersuch - 1);

    return 0;
}
