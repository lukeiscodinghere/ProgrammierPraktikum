#include <stdlib.h>


int main (void){


int nMax = 0, nMin = 0;

scanf("%d", &nMax);

srand(time(NULL));

int nRandonNumber = rand()%((nMax+1)-nMin) + nMin;

printf("\n- %d -\n",nRandonNumber);

return 0;
}
