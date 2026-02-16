/*************************************************************************
* Kurzbeschreibung: Tic tac    Aufgabe: 25.2  ; Punkte: 
*
* Datum: 10.05.2022      Autor:                       Grund der Aenderung:
*                                                     Neuerstellung
*                        
*************************************************************************/

#include <stdio.h>
#include <stdlib.h>

#define MAX 10

/*--- Funktionsdefinitionen --------------------------------------------------*/
/* Funktion die das passende Array generiert und beschreibt */
int defineSpielfeld(int spaltenZeilen, char spielfeld[MAX][MAX]);

/* Funktion liest Wert ein und führt Spielzug von Spieler 1 aus */
int spieler1(int spaltenZeilen, char spielfeld[MAX][MAX]);

/* Funktion liest Wert ein und führt Spielzug von Spieler 2 aus */
int spieler2(int spaltenZeilen, char spielfeld[MAX][MAX]);

/* Funktion, die entscheidet wann ein Spieler drei Eintraege in einer Reihe und damit gewonnen hat */
int gewonnen(char spielfeld[MAX][MAX], int eintrag, int zeile, int spalte);

/* Funktion bricht Spiel ab wenn alle Positionen im Spielfeld mit 'X' oder 'O' beschrieben wurden */
int testUnentschieden(int spaltenZeilen, char spielfeld[MAX][MAX]);

int main( void ) {
   /* Definieren der Variablen, die die Groesse des quadratischen arrays bestimmt*/
   char spielfeld[MAX][MAX];
   int spaltenZeilen;

   /* Text */
   printf("Das Spiel Tictac\n----------------\n");

   /* Uebergabe der Variablen in die Funktion die das passende Array generiert und beschreibt*/
   defineSpielfeld(spaltenZeilen, spielfeld);

   return 0;
}

int defineSpielfeld(int spaltenZeilen, char spielfeld[MAX][MAX]) {
   /* Definieren der Variablen und des Arrays */
   char c;
   int ok, ret, i = 1, j = 1;

   /* Einlesen der Anzahl der Spalten/Zeilen */
   printf("Spielfeldgroesse (mindestens 3, maximal %d) ? ", MAX);
   ret = scanf("%d%c", &spaltenZeilen, &c);

   /* Wenn zwei richtige Werte ermittelt wurden und es nur Zahlen sind ist es OK */
   ok = ret == 2 && c == '\n';

   /* Wenn es nicht OK ist muss man den Buffer leeren. */
   while(!ok || spaltenZeilen > MAX || spaltenZeilen < 3) {
      fflush(stdin);

      /* Erneutes einlesen der Anzahl der Spalten/Zeilen */
      printf("Bitte geben Sie die Spielfeldgroesse erneut ein (mindestens 3, maximal %d): ", MAX);
      ret = scanf("%d%c", &spaltenZeilen, &c);

      /* Wenn zwei richtige Werte ermittelt wurden und es nur Zahlen sind ist es OK */
      ok = ret == 2 && c == '\n';
   }

   /* Beschreiben des Spielfeldes/Arrays */
   for(int i = 0; i < spaltenZeilen; i++) {
        for(int j = 0; j < spaltenZeilen; j++)
            spielfeld[i][j] = '.';
   }

   /* Ausgabe des Spielfeldes. Bestehend aus drei For-Anweisungen*/
   printf("Ihr Spielfeld:\n   ");

   for(int k = 1; k < spaltenZeilen + 1; k++) {
      printf("%d ", k);
   }

   printf("\n");

   for(int i = 0, k = 1; i < spaltenZeilen; i++, k++) {
      printf(" %d ", k);
      for(int j = 0; j < spaltenZeilen; j++) {
         printf("%c ", spielfeld[i][j]);
      }

      printf("\b \n");
   }

   /* Uebergabe des Spielfeldes und der Variablen, die die Groesse bestimmt, an die Funktion fuer den ersten Spielzug von Spieler 1 */
   spieler1(spaltenZeilen, spielfeld);

   return 0;
}

int spieler1(int spaltenZeilen, char spielfeld[MAX][MAX]) {
   /* Definieren der Variablen */
   char c;
   int ok, ret, zeile, spalte, eintrag, gewinner, i = 1, j = 1, k = 1, a = 0, b = 0;

   /* Einlesen der Anzahl der Ziehungen */
   printf("Dein Zug, Spieler 1 (Zeile,Spalte) ? ");
   ret = scanf("%d,%d%c", &zeile, &spalte, &c);

   /* Wenn zwei richtige Werte ermittelt wurden und es nur Zahlen sind ist es OK */
   ok = ret == 3 && c == '\n';

   /* Wenn es nicht OK ist muss man den Buffer leeren. */
   while(!ok || zeile > spaltenZeilen || spalte > spaltenZeilen || spielfeld[zeile - 1][spalte - 1] != '.') {
      fflush(stdin);

      /* Erneutes einlesen der Anzahl der Ziehungen */
      printf(".... Unerlaubter Spielzug\nDein Zug, Spieler 1 (Zeile,Spalte) ? ");
      ret = scanf("%d,%d%c", &zeile, &spalte, &c);

      /* Wenn zwei richtige Werte ermittelt wurden und es nur Zahlen sind ist es OK */
      ok = ret == 3 && c == '\n';
   }

   /* Schreiben des 'X' in Spielfeld, anhand der Eingabe (Zeilen/Spalten) des Spielers */
   spielfeld[zeile - 1][spalte - 1] = 'X';


   /* Ausgabe des Spielfeldes. Bestehend aus drei For-Anweisungen*/
   printf("   ");

   for(int k = 1; k < spaltenZeilen + 1; k++) {
      printf("%d ", k);
   }

   printf("\n");

   for(int i = 0, k = 1; i < spaltenZeilen; i++, k++) {
      printf(" %d ", k);
      for(int j = 0; j < spaltenZeilen; j++) {
         printf("%c ", spielfeld[i][j]);
      }

      printf("\b \n");
   }

   /* Setzen des Eintrags auf das Zeichen des Spielers, also 'X' */
   eintrag = 'X';

   /* Die Funktion gibt 1 zurück, wenn alle Positionen im Spielfeld mit 'X' oder 'O' beschrieben wurden */
   a = testUnentschieden(spaltenZeilen, spielfeld);

   /* Die Funktion gibt 1 zurück, wenn ein Spieler drei Eintraege in einer Reihe hat */
   b = gewonnen(spielfeld, eintrag, zeile, spalte);

   /* Falls unentschieden = 1 Abbruch des Spiels mit Unentschieden */
   /* Falls gewinner = 1 Abbruch des Spiels mit Sieg eines Spielers */
   /* Falls unentschieden und gewinner gleich 0 sind wird das Programm fortgeführt */
   if(a == 1) {
      printf("Es gibt keine freie Felder mehr!\n!! Unentschieden !!");
      exit(0);
   } else if(b == 1) {
      printf("\n====================\nSpieler 1 hat gewonnen!\n====================\n");
      exit(0);
   } else { }

   /* Uebergabe des Spielfeldes und der Variablen, die die Groesse bestimmt, an die Funktion fuer den naechsten Spielzug von Spieler 2 */
   spieler2(spaltenZeilen, spielfeld);

   return 0;
}

int spieler2(int spaltenZeilen, char spielfeld[MAX][MAX]) {
   /* Definieren der Variablen */
   char c;
   int ok, ret, zeile, spalte, eintrag, gewinner, i = 1, j = 1, k = 1, a = 0, b = 0;

   /* Einlesen der Anzahl der Ziehungen */
   printf("Dein Zug, Spieler 2 (Zeile,Spalte) ? ");
   ret = scanf("%d,%d%c", &zeile, &spalte, &c);

   /* Wenn zwei richtige Werte ermittelt wurden und es nur Zahlen sind ist es OK */
   ok = ret == 3 && c == '\n';

   /* Wenn es nicht OK ist muss man den Buffer leeren. */
   while(!ok || zeile > spaltenZeilen || spalte > spaltenZeilen || spielfeld[zeile - 1][spalte - 1] != '.') {
      fflush(stdin);

      /* Erneutes einlesen der Anzahl der Ziehungen */
      printf(".... Unerlaubter Spielzug\nDein Zug, Spieler 2 (Zeile,Spalte) ? ");
      ret = scanf("%d,%d%c", &zeile, &spalte, &c);

      /* Wenn zwei richtige Werte ermittelt wurden und es nur Zahlen sind ist es OK */
      ok = ret == 3 && c == '\n';
   }

   /* Schreiben des 'O' in Spielfeld, anhand der Eingabe (Zeilen/Spalten) des Spielers */
   spielfeld[zeile - 1][spalte - 1] = 'O';

   /* Ausgabe des Spielfeldes. Bestehend aus drei For-Anweisungen*/
   printf("   ");

   for(int k = 1; k < spaltenZeilen + 1; k++) {
      printf("%d ", k);
   }

   printf("\n");

   for(int i = 0, k = 1; i < spaltenZeilen; i++, k++) {
      printf(" %d ", k);
      for(int j = 0; j < spaltenZeilen; j++) {
         printf("%c ", spielfeld[i][j]);
      }

      printf("\b \n");
   }

   /* Setzen des Eintrags auf das Zeichen des Spielers, also 'X' */
   eintrag = 'O';

   /* Die Funktion gibt 1 zurück, wenn alle Positionen im Spielfeld mit 'X' oder 'O' beschrieben wurden */
   a = testUnentschieden(spaltenZeilen, spielfeld);

   /* Die Funktion gibt 1 zurück, wenn ein Spieler drei Eintraege in einer Reihe hat */
   b = gewonnen(spielfeld, eintrag, zeile, spalte);

   /* Falls unentschieden = 1 Abbruch des Spiels mit Unentschieden */
   /* Falls gewinner = 1 Abbruch des Spiels mit Sieg eines Spielers */
   /* Falls unentschieden und gewinner gleich 0 sind wird das Programm fortgeführt */
   if(a == 1) {
      printf("Es gibt keine freie Felder mehr!\n!! Unentschieden !!");
      exit(0);
   } else if(b == 1) {
      printf("\n====================\nSpieler 2 hat gewonnen!\n");
      exit(0);
   } else { }

   /* Uebergabe des Spielfeldes und der Variablen, die die Groesse bestimmt, an die Funktion fuer den naechsten Spielzug von Spieler 1 */
   spieler1(spaltenZeilen, spielfeld);

   return 0;
}

int gewonnen(char spielfeld[MAX][MAX], int eintrag, int zeile, int spalte) {
   /********************************************************************************************************\
   * Es wird in jede Richtung vom Eintrag aus abgefragt, ob drei weitere gleiche Eintraege zu finden sind.
   *
   * Beispiel: Als erstes wird die Position 1-links des Eintrags abgefragt.
   *           Danach wird die Position 2-links des Eintrags kontrolliert.
   *           Falls diese immernoch nicht übereinstimmt wird die Position 1-rechtss des Eintrags überprüft.
   *           Wenn diese auch nicht übereinstimmt gewinnt der Spieler nicht!
   *
   *      Linksoben          Oben         Rechtsoben
   *                X    .    X    .    X
   *                .    X    X    X    .
   *          Links X    X Eintrag X    X Rechts
   *                .    X    X    X    .
   *                X    .    X    .    X
   *     Linksunten         Unten         Rechtsunten
   \********************************************************************************************************/

   int gewinner = 0;

   /* Abfrage: Links */
   if(spielfeld[zeile - 1][spalte - 2] == eintrag) {
      if(spielfeld[zeile - 1][spalte - 3] == eintrag) {
         gewinner |= 1;
      } else if(spielfeld[zeile - 1][spalte] == eintrag) {
         gewinner |= 1;
      } else { }
   } else { }

   /* Abfrage: Rechts */
   if(spielfeld[zeile - 1][spalte] == eintrag) {
      if(spielfeld[zeile - 1][spalte + 1] == eintrag) {
         gewinner |= 1;
      } else if(spielfeld[zeile - 1][spalte - 2] == eintrag) {
         gewinner |= 1;
      } else { }
   } else { }

   /* Abfrage: Oben */
   if(spielfeld[zeile - 2][spalte - 1] == eintrag) {
      if(spielfeld[zeile - 3][spalte - 1] == eintrag) {
         gewinner |= 1;
      } else if(spielfeld[zeile][spalte - 1] == eintrag) {
         gewinner |= 1;
      } else { }
   } else { }

   /* Abfrage: Unten */
   if(spielfeld[zeile][spalte - 1] == eintrag) {
      if(spielfeld[zeile + 1][spalte - 1] == eintrag) {
         gewinner |= 1;
      } else if(spielfeld[zeile - 2][spalte - 1] == eintrag) {
         gewinner |= 1;
      } else { }
   } else { }

   /* Abfrage: Linksoben */
   if(spielfeld[zeile - 2][spalte - 2] == eintrag) {
      if(spielfeld[zeile - 3][spalte - 3] == eintrag) {
         gewinner |= 1;
      } else if(spielfeld[zeile][spalte] == eintrag) {
         gewinner |= 1;
      } else { }
   } else { }

   /* Abfrage: Rechtsoben */
   if(spielfeld[zeile - 2][spalte] == eintrag) {
      if(spielfeld[zeile - 3][spalte + 1] == eintrag) {
         gewinner |= 1;
      } else if(spielfeld[zeile][spalte - 2] == eintrag) {
         gewinner |= 1;
      } else { }
   } else { }

   /* Abfrage: Rechtsunten */
   if(spielfeld[zeile][spalte] == eintrag) {
      if(spielfeld[zeile + 1][spalte + 1] == eintrag) {
         gewinner |= 1;
      } else if(spielfeld[zeile - 2][spalte - 2] == eintrag) {
         gewinner |= 1;
      } else { }
   } else { }

   /* Abfrage: Linksunten */
   if(spielfeld[zeile][spalte - 2] == eintrag) {
      if(spielfeld[zeile + 1][spalte - 3] == eintrag) {
         gewinner |= 1;
      } else if(spielfeld[zeile - 2][spalte] == eintrag) {
         gewinner |= 1;
      } else { }
   } else { }

   return gewinner;
}

int testUnentschieden(int spaltenZeilen, char spielfeld[MAX][MAX]) {
   /* Setzen der Variablen unentschieden */
   int unentschieden = 1;

   /* Pruefen ob im Spielfeld nur 'X' oder 'O' geschrieben sind. Anschließend bitweise verunden => unentschieden gibt nur 1 zurück wenn auch alle Werte gesetzt sind */
   for(int i = 0; i < (spaltenZeilen); i++) {
      for(int j = 0; j < (spaltenZeilen); j++) {
         if(spielfeld[i][j] == '.') {
            unentschieden = 0;
            break;
         }
      }
   }

   return unentschieden;
}
