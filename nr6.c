/*************************************************************************
* Kurzbeschreibung: Zahlen raten     Aufgabe: 17  ; Punkte: 
*
* Datum: 07.05.2022      Autor:                       Grund der Aenderung:
*                      
*************************************************************************/

#include <stdio.h>
#include <stdlib.h>

/*--- Funktionsdefinitionen ------------------------------------------*/

#define TRUE (1)

#define FLUSH() int c = 0; while((c = getchar() !=  '\n' && c != EOF)); //Cleaner


int main (void)
{
    int eingabe = 0, i = 0, endwert = 0, fehlercode = 0, zufall = 0, anfangswert = 1;

    printf("\nIch denke mir eine Zahl aus dem Intervall [1,x]. Hierbei muss x positiv sein.\nDu musst dann versuchen, diese Zahl zu erraten.\
           \n\nZunaechst musst du einmal festlegen, wie gross die zu\nratende Zahl maximal sein darf: ");


    while (TRUE)
    {
            eingabe = 0;
            endwert = 0;
            fehlercode = 0;
            i = 0;

            fehlercode = scanf("%d", &endwert); //Einlesen

            while (fehlercode == 0 || endwert < 0)
            {
                printf("\n-> Ungueltige Eingabe.\nGeben Sie eine erlaubte Intervallgrenze an!\nNeue Eingabe: ");

                FLUSH();

                fehlercode = scanf("%d", &endwert);
            }

            while (endwert > 0)
            {
                //Zufallszahl wird generiert
                srand(time(NULL));

                zufall = rand() % ((endwert + 1) - anfangswert) + anfangswert;

                printf("Hm..... Ok, ich habe eine Zahl\n\n");

            }

            do{

                printf("Dein %d.Versuch:", i); // vor jeder neuer eingabe
                scanf("%d", &eingabe);
            }

            while(eingabe > endwert)
            {
                printf("Hallo");
            }

    }

   /* printf("\n%180s", "......zu niedrig");//Antwort1

    printf("\n%180s", "......zu hoch");//Antwort2

    printf("\n%180s", "......Richtig");//Antwort3



    printf("Du hast %d Versuche zum Erraten der Zahl benoetigt.", i); //finale Ausgabe
*/
    return 0;
}

