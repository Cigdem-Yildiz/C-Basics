#include <stdio.h>
#include <stdlib.h>
#include <math.h>

void letterScroll(char*, int);

int main(){
    char Letter[7] = {'Y', 'a', 'z', 'i', 'l', 'i', 'm'};
    int size = sizeof(Letter)/sizeof(Letter[0]);

    for(int i=0; i<size; i++)
        printf("%c", *(Letter+i));

    printf("\n");

    for(int i=0; i<size; i++)
        letterScroll(Letter, size);

    printf("\n");

    return 0;
}

void letterScroll(char* Letter, int size){
    int temp;
    temp=*(Letter);
    for(int i=0; i<size-1; i++){
        *(Letter+i) = *(Letter+i+1);
    }
    *(Letter+size-1) = temp;

    for(int i=0; i<size; i++)
        printf("%c", *(Letter+i));

    printf("\n");
}
