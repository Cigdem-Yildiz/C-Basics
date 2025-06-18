#include <stdio.h>
#include <stdlib.h>

int main(){
    srand(time(NULL));

    int dizi[20];
    int sayac[21]={0};

    printf("Dizinin elemanlari: ");
    for(int i=0; i<20; i++){
        dizi[i]=rand()%20+1;
        printf("%d ", dizi[i]);
        sayac[dizi[i]]++;
    }
    printf("\n\n");

    for(int i=1; i<=20; i++){
        if(sayac[i]>1)
            printf("'%d' sayisi %d kez kullanilmistir.\n", i, sayac[i]);
    }

    return 0;
}
