#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int main()
{
    int index1, index2, index3;
    char characters[]={'!','?','#','%','='};
    srand(time(NULL));

    printf(" ------------------------ \n");
    printf("|  Welcome to our game!  |\n");
    printf(" ------------------------ \n\n");

    printf("Press enter to start the game.");
    getchar();
    sleep(1);

    index1=rand()%5;
    index2=rand()%5;
    index3=rand()%5;

    printf("\n*************\n");
    printf("| %c | %c | %c |\n", characters[index1], characters[index2], characters[index3]);
    printf("*************\n\n");
    sleep(1);

    if(index1==index2 && index1==index3)
        printf("Congrats! You win the game :)");
    else if(index1==index2 || index1==index3 || index2==index3)
        printf("You got a close one!\n");
    else
        printf("You lost :P");

    return 0;
}
