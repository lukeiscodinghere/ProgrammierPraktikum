/*************************************************************************
* Kurzbeschreibung: Zahlen raten     Aufgabe: 22.2  ; Punkte: 
*
* Datum: 10.05.2022      Autor:                       Grund der Aenderung:
*                                                     Neuerstellung
*                        
*************************************************************************/

#include <stdio.h>
#include <stdlib.h>

/*--- Funktionsdefinitionen ---------------------------------------------------------*/
int readNumbers(int z1, int z2, int z3, int z4);

int sortNumbers(int z1, int z2, int z3, int z4);

/* Hinweis: Es werden keine gleichen Zahlen verglichen, da es keinen Sinn ergibt! (siehe while-Schleife der Funktion readNumers()) */
int main() {
    /* Definiere x, y für die Start-Koordinaten und Gesamtstrecke distance*/
    int z1 = 0, z2 = 0, z3 = 0, z4 = 0;

    /* Text */
    printf("Sortieren von 4 verschiedenen Integer Zahlen\n--------------------------------------------\n");

    /* Lies solang die Zahlen ein, bis der Nutzer sie richtig eingegeben hat und springe zur naechsten Funktion */
    readNumbers(z1, z2, z3, z4);

    return 0;
}

/* Einlesen der 4 Integer Zahlen */
int readNumbers(int z1, int z2, int z3, int z4) {
    /* Definiere Kontroll-Variablen */
    char c;
    int ok, ret;

    /* Hier wird die 1.Zahl eingelesen */
    printf("Zahl1?: ");
    ret = scanf("%d%c", &z1, &c);

    /* Wenn zwei richtige Werte ermittelt wurden und es nur Zahlen sind ist es OK */
    ok = ret == 2 && c == '\n';

    /* Wenn es nicht OK ist muss man den Buffer leeren. */
    while(!ok) {
        fflush(stdin);

        /* Erneutes einlesen der 1.Zahl */
        printf("Bitte geben Sie Zahl1 erneut ein: ");
        ret = scanf("%d%c", &z1, &c);

        /* Wenn zwei richtige Werte ermittelt wurden und es nur Zahlen sind ist es OK */
        ok = ret == 2 && c == '\n';
    }

    /* Hier wird die 2.Zahl eingelesen */
    printf("Zahl2?: ");
    ret = scanf("%d%c", &z2, &c);

    /* Wenn zwei richtige Werte ermittelt wurden und es nur Zahlen sind ist es OK */
    ok = ret == 2 && c == '\n';

    /* Wenn es nicht OK ist muss man den Buffer leeren. Und es werden keine gleichen Zahlen akzeptiert -> Hinweis */
    while(!ok || z2 == z1) {
        fflush(stdin);

        /* Erneutes einlesen der 2.Zahl */
        printf("Bitte geben Sie Zahl2 erneut ein: ");
        ret = scanf("%d%c", &z2, &c);

        /* Wenn zwei richtige Werte ermittelt wurden und es nur Zahlen sind ist es OK */
        ok = ret == 2 && c == '\n';
    }

    /* Hier wird die 3.Zahl eingelesen */
    printf("Zahl3?: ");
    ret = scanf("%d%c", &z3, &c);

    /* Wenn zwei richtige Werte ermittelt wurden und es nur Zahlen sind ist es OK */
    ok = ret == 2 && c == '\n';

    /* Wenn es nicht OK ist muss man den Buffer leeren. Und es werden keine gleichen Zahlen akzeptiert -> Hinweis */
    while(!ok || z3 == z2 || z3 == z1) {
        fflush(stdin);

        /* Erneutes einlesen der 3.Zahl */
        printf("Bitte geben Sie Zahl3 erneut ein: ");
        ret = scanf("%d%c", &z3, &c);

        /* Wenn zwei richtige Werte ermittelt wurden und es nur Zahlen sind ist es OK */
        ok = ret == 2 && c == '\n';
    }

    /* Hier wird die 4.Zahl eingelesen */
    printf("Zahl4?: ");
    ret = scanf("%d%c", &z4, &c);

    /* Wenn zwei richtige Werte ermittelt wurden und es nur Zahlen sind ist es OK */
    ok = ret == 2 && c == '\n';

    /* Wenn es nicht OK ist muss man den Buffer leeren. Und es werden keine gleichen Zahlen akzeptiert -> Hinweis */
    while(!ok || z4 == z3 || z4 == z2 || z4 == z1) {
        fflush(stdin);

        /* Erneutes einlesen der 4.Zahl */
        printf("Bitte geben Sie Zahl4 erneut ein: ");
        ret = scanf("%d%c", &z4, &c);

        /* Wenn zwei richtige Werte ermittelt wurden und es nur Zahlen sind ist es OK */
        ok = ret == 2 && c == '\n';
    }

    /* Uebergabe der Werte in die naechste Funktion */
    sortNumbers(z1, z2, z3, z4);

    return 0;
}

/* Sortieren der eingelesenen Zahlen */
int sortNumbers(int z1, int z2, int z3, int z4) {
    char enter;
    int ret, ok, z01, z02, z03, z04, uebertrag = 0, minimum = -2147483648, durchlauf = 1;

    /* Setzen der Endwerte auf Minimum (fuer Integer) zum Rechnen */
    z01 = z02 = z03 = z04 = -2147483648;

    if(z1 > z2 || z2 > z3 || z3 > z4) {
        /* Schleife zur Bestimmung der groessten Zahl */
        while(z1 > z2 || z2 > z3 || z3 > z4) {
            if((z4 > z3) && (z4 > z2) && (z4 > z1)) {
                /* Zur Ausgabe */
                uebertrag = z4;
                /* Setzen des Wertes auf Minimum -> kleinster Wert */
                z4 = minimum;
                printf("\nNR:\n[ü4: %d, z4: %d]\n", uebertrag, z4);
            } else if((z3 > z4) && (z3 > z2) && (z3 > z1)) {
                /* Zur Ausgabe */
                uebertrag = z3;
                /* Setzen des Wertes auf Minimum -> kleinster Wert */
                z3 = minimum;
                printf("\nNR:\n[ü3: %d, z3: %d]\n", uebertrag, z3);
            } else if((z2 > z3) && (z2 > z3) && (z2 > z1)) {
                /* Zur Ausgabe */
                uebertrag = z2;
                /* Setzen des Wertes auf Minimum -> kleinster Wert */
                z2 = minimum;
                printf("\nNR:\n[ü2: %d, z2: %d]\n", uebertrag, z2);
            } else {
                /* Zur Ausgabe */
                uebertrag = z1;
                /* Setzen des Wertes auf Minimum -> kleinster Wert */
                z1 = minimum;
                printf("\n[ü1: %d, z1: %d]\n", uebertrag, z1);
            }

            /* Schreiben des groessten Wertes auf z04, des zweitgroessten Wertes auf z03 und des drittgroessten Wertes auf z02*/
            if(uebertrag > z04) {
                z04 = uebertrag;
                printf("\nNR:\n[ü4: %d, z04: %d]\n", uebertrag, z04);
            } else if (uebertrag > z03) {
                z03 = uebertrag;
                printf("\nNR:\n[ü3: %d, z03: %d]\n", uebertrag, z03);
            }  else if (uebertrag > z02) {
                z02 = uebertrag;
                printf("\nNR:\n[ü2: %d, z02: %d]\n", uebertrag, z02);
            } else {
                z01 = uebertrag;
                printf("\nNR:\n[ü1: %d, z01: %d]\n", uebertrag, z01);
            }

            /* Ausgabe des aktuellen Standes */
            printf("\n%d. Durchlauf - Aktueller Stand:\n", durchlauf);
            printf("\n%d. Hoechste Zahl gefunden: %d\nWeiter mit Return... ", durchlauf, uebertrag);

            /* Naechster Durchlauf und naechsthoehere Zahl*/
            durchlauf++;

            /* Einlesen des Return-Befehls */
            ret = scanf("%c", &enter);

            /* Wenn Return eingegeben wurde, ist es OK */
            ok = ret == 1 && enter == '\n';

            /* Wenn es nicht OK ist muss man den Buffer leeren. */
            fflush(stdin);
            while(!ok) {
                fflush(stdin);

                /* Erneutes einlesen des Return-Befehls */
                printf("Weiter mit Return... ");
                ret = scanf("%c", &enter);

                /* Wenn Return eingegeben wurde, ist es OK */
                ok = ret == 1 && enter == '\n';
            }
        }

        /* Schreiben des kleinsten Wert auf z01 */
        if(z4 != minimum) {
            z01 = z4;
            printf("\nNR:\nz4: %d, z04: %d\n", z4, z04);
        } else if(z3 != minimum) {
            z01 = z3;
            printf("\nNR:\nz3: %d, z03: %d\n", z3, z03);
        } else if(z2 != minimum) {
            z01 = z2;
            printf("\nNR:\nz2: %d, z02: %d\n", z2, z02);
        } else if (z1 != minimum) {
            z01 = z1;
            printf("\nNR:\nz1: %d, z01: %d\n", z1, z01);
        } else { }

        /* Ausgabe aller Werte und der Anzahl an Durchlaeufen */
        printf("\nZahl1: %d\nZahl2: %d\nZahl3: %d\nZahl4: %d\n", z01, z02, z03, z04);
        printf("-----------------------------------------\n!!!! FERTIG nach %d Durchlaeufen !!!!\n", durchlauf - 1);
    } else {
        /* Bei bereits sortierten Zahlen */
        printf("Was soll das?!\nDie Zahlen sind bereits sortiert!!");
    }
   return 0;
}
