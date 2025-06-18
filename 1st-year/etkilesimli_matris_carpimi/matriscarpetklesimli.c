#include <stdio.h>
#include <stdlib.h>

int main(){
    int m, n, a, b, top=0;

    do{
    printf("Ilk matrisin satir ve sutun numarasini giriniz: ");
    scanf("%d %d", &m, &n);

    printf("Ikinci matrisin satir ve sutun numarasini giriniz: ");
    scanf("%d %d", &a, &b);

    if(n!=a)
        printf("\nBu matrisler carpilamaz!\n\n");

    }while(n!=a);

    int matris1[m][n], matris2[a][b], matris3[m][b];

    printf("\n1. matrisin elemanlarini girin.\n");
    for(int i=0; i<m; i++){
        for(int j=0; j<n; j++){
            printf("1.matris[%d][%d]=", i, j);
            scanf("%d", &matris1[i][j]);
        }
    }

    printf("\n2. matrisin elemanlarini girin.\n");
    for(int i=0; i<a; i++){
        for(int j=0; j<b; j++){
            printf("2.matris[%d][%d]=", i, j);
            scanf("%d", &matris2[i][j]);
        }
    }

    printf("\n");

    for(int i=0; i<m; i++){
        for(int j=0; j<b; j++){
            for(int k=0; k<a; k++){
                top+=matris1[i][k]*matris2[k][j];
            }
            matris3[i][j]=top;
            top=0;
        }
    }

    printf("\n***1. MATRIS***\n");
    for(int i=0; i<m; i++){
        for(int j=0; j<n; j++){
            printf("%4d", matris1[i][j]);
        }
        printf("\n");
    }

    printf("\n***2. MATRIS***\n");
    for(int i=0; i<a; i++){
        for(int j=0; j<b; j++){
            printf("%4d", matris2[i][j]);
        }
        printf("\n");
    }

    printf("\n1. Matris X 2. Matris = 3. Matris\n\n***3. MATRIS***\n");

    for(int i=0; i<m; i++){
        for(int j=0; j<b; j++){
            printf("%5d", matris3[i][j]);
        }
        printf("\n");
    }

    printf("\n");

    return 0;
}
