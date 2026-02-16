/*************************************************************************
* Kurzbeschreibung: bis 100    Aufgabe: 18  ; Punkte: 
*
* Datum: 10.05.2022      Autor:                       Grund der Aenderung:
*                      
*                        
*************************************************************************/

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

/*--- Funktionsdefinitionen -------------------------------------------*/
int main( void ) {

    char c;
    int wuerfeln = 0, augen1 = 1, augen6 = 6, punkte = 0, runde = 1, wahl = 1;


    while(wahl) {
        // Zuruecksetzen der Runde
        runde = 1;

        printf("Willkommen beim Wuerfelspiel bis 100!\n");

        // Wuerfeln in mehreren Runden
        while(punkte <= 19 || runde <=5) {

            // erzeugen einer zufaelligen Augenzahl
            srand(time(NULL));
            wuerfeln = rand() % (augen6 - augen1 + 1) + augen1;

             // Wenn eine 1 gewuerfelt -> Abbruch des Wuerfelns
            if (wuerfeln == 1) {
                printf("Sie haben leider eine '1' gewuerfelt.\n");
                punkte = 0;
                break;
            }

            // Berechnung der Punkte
            punkte = punkte + wuerfeln;

            // Ausgabe
            printf("%d.Runde: Sie haben eine '%d' gewuerfelt\n\t--> Ihre Punkte sind %d\n", runde, wuerfeln, punkte);

            runde++;

            printf("Wollen Sie noch einmal wuerfeln?\n\tJa = 1,\tNein = 0,\tIhre Wahl: ");
            scanf("%d%c", &wahl, &c);


            while(wahl < 0 || wahl > 1 || c != '\n') {
                fflush(stdin);

                // Erneutes Einlesen
                printf("Geben Sie bitte 1 fuer ja oder 0 fuer nein ein. Wahl: ");
                scanf("%d%c", &wahl, &c);
            }

            // Abbruch des Wuerfelns
            if (wahl == 0) {
                break;
            }
        }

        /* Hier kann der naechste Spieler seinen Zug ausführen. Jedoch muss die Endsumme selbst zusammengerechnet werden. */

        printf("Ihr Endergebnis: %d Punkte\n\nWollen Sie noch einmal spielen?\n\tJa = 1,\tNein = 0,\tIhre Wahl: ", punkte);
        scanf("%d%c", &wahl, &c);

        while(wahl < 0 || wahl > 1 || c != '\n') {
            fflush(stdin);

            printf("Geben Sie bitte 1 fuer ja oder 0 fuer nein ein. Wahl: ");
            scanf("%d%c", &wahl, &c);
        }

        // Beenden oder fortsetzen des Spiels abhaengig von der Variable 'wahl'
        if (wahl == 1) {
            printf("\nNeues Spiel:\n");
        } else {
            printf("Ende des Spiels!");
        }
    }

    return 0;
}
