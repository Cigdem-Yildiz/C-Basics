#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main()
{
    char sentence[100];
    int count=0, length;

    printf("Enter a sentence: ");
    fgets(sentence, sizeof(sentence), stdin);


    length=strlen(sentence);

    if(sentence[length-1]=='\n') {
        sentence[length-1]='\0';
        length--;
    }
    for(int i=0; i<length; i++){
        char letter = tolower(sentence[i]);
        if(letter=='a'||letter=='e'||letter=='i'||letter=='o'||letter=='u'){
            count++;
        }
    }

    printf("There are %d vowels in \"%s\"", count, sentence);

    return 0;
}
