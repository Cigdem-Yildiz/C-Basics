#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

void caesarSifre(char*, int);
void caesarSifreCozme(char*, int);

int main()
{
    char row[256];
    int shift, choice;

    do{
    printf("********\n");
    printf("* MENU *\n");
    printf("********\n\n");
    printf("1. Sifrele\n");
    printf("2. Sifreyi Coz\n");
    printf("3. Programdan Cik\n");
    printf("Seciminizi sayi olarak giriniz: ");
    scanf("%d", &choice);
    getchar();

    switch(choice){
        case 1: ;
                FILE* fPGirdi, *fPCikti;

                fPGirdi = fopen("girdi.txt", "r");
                if (fPGirdi == NULL) {
                    printf("Sifrelenecek dosya acilamadi!\n");
                    return -1;
                }

                fPCikti = fopen("cikti.txt", "w");
                if (fPCikti == NULL) {
                    printf("Sifrelenmis dosya acilamadi!\n");
                    return -1;
                }

                printf("Kaydirma miktarini giriniz: ");
                scanf("%d", &shift);
                getchar();

                while(fgets(row, sizeof(row), fPGirdi)){
                    caesarSifre(row, shift);
                    fputs(row, fPCikti);
                }

                fclose(fPGirdi);
                fclose(fPCikti);

                printf("\nSifreleme islemi tamamlandi.\n\n");

                break;

        case 2: ;
                FILE* fPCozulmus;

                fPCozulmus = fopen("cozulmus.txt", "w");
                if (fPCozulmus == NULL) {
                    printf("Sifrelenecek dosya acilamadi!\n");
                    return -1;
                }

                fPCikti = fopen("cikti.txt", "r");
                if (fPCikti == NULL) {
                    printf("Sifrelenmis dosya acilamadi!\n");
                    return -1;
                }

                printf("Kaydirma miktarini giriniz: ");
                scanf("%d", &shift);
                getchar();

                while(fgets(row, sizeof(row), fPCikti)){
                    caesarSifreCozme(row, shift);
                    fputs(row, fPCozulmus);
                }

                fclose(fPCikti);
                fclose(fPCozulmus);

                printf("\nSifre cozme islemi tamamlandi.\n\n");

                break;

        case 3: printf("\nProgramdan cikiliyor..\n\n");
                return 0;

        default: printf("Hatali giris!\nLutfen menudeki seceneklerden birini seciniz.\n");
    }
    }while(choice!=3);


/*
    char text[100];
    int kayma, onay;

    printf("Sifrelenecek metni giriniz: ");
    fgets(text, sizeof(text), stdin);

    printf("Kaydirma miktarini giriniz: ");
    scanf("%d", &kayma);

    caesarSifre(text, kayma);
    printf("Sifrelenmis metin: %s", text);

    printf("Metni geri cozmek ister misiniz?(1=Evet, 0=Hayir): ");
    do{
        scanf("%d", &onay);
        if(onay==1){
            caesarSifreCozme(text, kayma);
            printf("Cozulmus metin: %s", text);
            break;
        }else if(onay==0)
            break;
        else
            printf("Hatali giris yaptiniz. Metni geri cozmek icin 1 programdan cikmak icin 0 giriniz: ");
    }while(onay!=0 || onay!=1);

    return 0;
*/

}
void caesarSifre(char* metin, int kay){
    for(int i=0; metin[i]!='\0';i++){
        if(isalpha(metin[i])){
            if(isupper(metin[i]))
                metin[i]=((metin[i]+kay-'A') % 26) + 'A';
            else
                metin[i]=((metin[i]+kay-'a') % 26) + 'a';
        }
    }
}

void caesarSifreCozme(char* metin, int kay){
    for(int i=0; metin[i]!='\0';i++){
        if(isalpha(metin[i])){
            if(isupper(metin[i]))
                metin[i]=((metin[i]-kay-'A'+26) % 26) + 'A';
            else
                metin[i]=((metin[i]-kay-'a'+26) % 26) + 'a';
        }
    }
}
