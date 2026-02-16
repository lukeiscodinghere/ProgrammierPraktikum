/*************************************************************************
* Kurzbeschreibung: Lotto      Aufgabe: 25.1  ; Punkte: 
*
* Datum: 10.05.2022      Autor:                       Grund der Aenderung:
*                        Luke                         Neuerstellung
*                        
*************************************************************************/

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define OBERGRENZE 100

/*--- Funktionsdefinitionen --------------------------------------------------*/
void readMaxKugeln(int maxKugeln);

int readZiehungen(int maxKugeln);

int zufallszahl(int *pzufall, int maxKugeln);

int defineArray(int ziehungen, int maxKugeln);

int main( void ) {
   /* Definieren der Variablen */
   int maxKugeln = 1;

   printf("Lottozahlen-Simulation\n----------------------\n");

   readMaxKugeln(maxKugeln);

   return 0;
}

void readMaxKugeln(int maxKugeln) {
   /* Definieren der Variablen */
   char c;
   int ok, ret;

   /* Einlesen der Anzahl der Kugeln */
   printf("Wie viele Kugeln sollen zur Verfuegung stehen (mind. 1 und max %d): ", OBERGRENZE);
   ret = scanf("%d%c", &maxKugeln, &c);

   /* Wenn zwei richtige Werte ermittelt wurden und es nur Zahlen sind ist es OK */
   ok = ret == 2 && c == '\n';

   /* Wenn es nicht OK ist muss man den Buffer leeren. */
   while(!ok || maxKugeln > OBERGRENZE || maxKugeln <= 1) {
      fflush(stdin);

      /* Erneutes einlesen der Anzahl der Kugeln */
      printf("Bitte geben Sie die maximale Anzahl der Kugeln erneut ein (mind. 1 und max %d): ", OBERGRENZE);
      ret = scanf("%d%c", &maxKugeln, &c);

      /* Wenn zwei richtige Werte ermittelt wurden und es nur Zahlen sind ist es OK */
      ok = ret == 2 && c == '\n';
   }

   readZiehungen(maxKugeln);
}

int readZiehungen(int maxKugeln) {
   /* Definieren der Variablen */
   char c;
   int ok, ret, ziehungen;

   /* Einlesen der Anzahl der Ziehungen */
   printf("Wie viele Kugeln sollen gezogen werden (mind. 1 und max %d): ", maxKugeln);
   ret = scanf("%d%c", &ziehungen, &c);

   /* Wenn zwei richtige Werte ermittelt wurden und es nur Zahlen sind ist es OK */
   ok = ret == 2 && c == '\n';

   /* Wenn es nicht OK ist muss man den Buffer leeren. */
   while(!ok || ziehungen > maxKugeln) {
      fflush(stdin);

      /* Erneutes einlesen der Anzahl der Ziehungen */
      printf("Bitte geben Sie die Anzahl der Ziehungen erneut ein (mind. 1 und max %d): ", maxKugeln);
      ret = scanf("%d%c", &ziehungen, &c);

      /* Wenn zwei richtige Werte ermittelt wurden und es nur Zahlen sind ist es OK */
      ok = ret == 2 && c == '\n';
   }

   printf("\n---- %d aus %d ----\n", ziehungen, maxKugeln);

   defineArray(ziehungen, maxKugeln);
}

int zufallszahl(int *pzufall, int maxKugeln) {

   *pzufall = (rand() % maxKugeln) + 1;
}

int defineArray(int ziehungen, int maxKugeln) {
   /* Deifinieren des Arrays */
   char enter;
   int lottoPot [maxKugeln], unten = 1, zufall, i = 0, n, k = 1, value = 1, ret, ok;

   for(i = 0; i < maxKugeln; i++) {
      lottoPot [i] = value++;
   }

   printf("\b \n");

   srand(time(NULL));

   while(k < (ziehungen + 1)) {

      /* Zufällige Zahl */
      zufallszahl(&zufall, maxKugeln);

      do {
         zufallszahl(&zufall, maxKugeln);

         n = zufall;
      } while(lottoPot[(n-1)] == 0);

      printf("%d\n", lottoPot[n-1]);

      lottoPot[n-1] = 0;

      k++;

      printf("Weiter mit Return...");

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

   printf("\nEnde der Ziehung!\n");
}
