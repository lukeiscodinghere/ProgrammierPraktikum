/*************************************************************************
* Kurzbeschreibung: Zuglänge     Aufgabe: 22.1  ; Punkte: 
*
* Datum: 10.05.2022      Autor:                       Grund der Aenderung:
*                                                     Neuerstellung
*                        
*************************************************************************/

#include <stdio.h>
#include <stdlib.h>
#include <math.h>

/*--- Funktionsdefinitionen ---------------------------------------------------------*/
float readStartCoordinates(int x1, int y1, float distance);

float readNextCoordinates(int x1, int y1, float distance);

float calculateDistance(int x1, int y1, int x, int y, float distance);

int main() {
    /* Definiere x, y für die Start-Koordinaten und Gesamtstrecke distance*/
    int x1 = 0, y1 = 0;
    float distance = 0;

    /* Text */
    printf("Strecken-Berechnungen\n---------------------\n\n");

    /* Lies solang die Koordinaten ein, bis der Nutzer sie richtig eingegeben hat und springe zur naechsten Funktion */
    readStartCoordinates(x1, y1, distance);

    return 0;
}

/* Einlesen der Start-Koordinaten */
float readStartCoordinates(int x1, int y1, float distance) {
    /* Definiere Kontroll-Variablen */
    char c;
    int ok, ret;

    /* Hier werden die Koordinaten eingelesen */
    printf("Bitte Startpunkt eingeben (x,y): ");
    ret = scanf("%d,%d%c", &x1, &y1, &c);

    /* Wenn drei richtige Werte ermittelt wurden und es nur Zahlen sind ist es OK */
    ok = ret == 3 && c == '\n';

    /* Wenn es nicht OK ist muss man den Buffer leeren. */
    while(!ok) {
        while ((c = getchar()) != '\n' && c != EOF) { }

        /* Erneutes einlesen der Koordinaten */
        printf("Bitte geben Sie ihre Eingabe erneut ein: ");
        ret = scanf("%d,%d%c", &x1, &y1, &c);

        /* Wenn drei richtige Werte ermittelt wurden und es nur Zahlen sind ist es OK */
        ok = ret == 3 && c == '\n';
    }
    /* Uebergabe der Werte in die naechste Funktion */
    readNextCoordinates(x1, y1, distance);

    return 0;
}

/* Einlesen aller weiteren Koordinaten */
float readNextCoordinates(int x1, int y1, float distance) {
    /* Definiere Kontroll-Variablen */
    char c;
    int x, y, ok, ret;

    /* Hier werden die Koordinaten eingelesen */
    printf("Neuer Streckenpunkt x,y (Abbruch mit x = -1): ");
    ret = scanf("%d,%d%c", &x, &y, &c) ;

    /* Falls -1 fuer Abbruch eingelesen wurde -> Ausgabe der Strecke und exit */
    if (x == -1 && ret == 1){
        printf("\n-> Die Streckenlaenge betraegt: %.2f Einheiten", distance);
        exit(0);
    }

    /* Wenn drei richtige Werte ermittelt wurden und es nur Zahlen sind ist es OK */
    ok = ret == 3 && c == '\n';

    /* Wenn es nicht OK ist muss man den Buffer leeren. */
    while(!ok) {
        while ((c = getchar()) != '\n' && c != EOF) { }

        /* Erneutes einlesen der Koordinaten */
        printf("Bitte geben Sie ihre Eingabe erneut ein: ");
        ret = scanf("%d,%d%c", &x, &y, &c);

        /* Wenn drei richtige Werte ermittelt wurden und es nur Zahlen sind ist es OK */
        ok = ret == 3 && c == '\n';
    }

    /* Uebergabe der Werte in die naechste Funktion */
    calculateDistance(x1, y1, x, y, distance);

    return 0;
}


/* Berechnung des Abstands zwischen den Koordinaten */
float calculateDistance(int x1, int y1, int x, int y, float distance) {
    /* Definieren der Variablen zum Berechnen */
    int deltaX = 0, deltaY = 0;
    float wurzel = 0.;

    /* Steigungsdreieck definieren */
    deltaX = x - x1;
    deltaY = y - y1;

    /* Pythagoras ausrechnen */
    wurzel = sqrt(deltaX * deltaX + deltaY * deltaY);

    /* Aufaddieren der Abstände */
    distance +=wurzel;

    /* Erneutes Setzen der Start-Koordinaten */
    x1 = x;
    y1 = y;


    /* Uebergabe der Werte in die naechste Funktion */
    readNextCoordinates(x1, y1, distance);

   return 0;
}
