#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main()
{
    char array[100];
    int counter[26]={0};

    printf("Enter a sentence: ");
    scanf("%s", &array);

    int len=strlen(array);

    for(int i=0; i<len; i++){
        array[i]=toupper(array[i]);
        counter[array[i]-'A']++;
    }

    printf("The sentence: %s\n", array);
    for(int i=0; i<26; i++){
        if(counter[i]>0)
            printf("Letter '%c' -> %d\n", i+'A', counter[i]);
    }

    return 0;
}
