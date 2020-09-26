#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "function.h"
#include "Player 1/PLAYER1.h"
#include "Player 1/BATTLE1.h"
#include "Player 2/PLAYER2.h"
#include "Player 2/BATTLE2.h"
#include "Player 1/FUNCTION1.h"
#include "Player 2/FUNCTION2.h"


int main()
{
    int** field;
    int** position;
    int** position2;
    int** visited1;
    int** visited2;
    int over1, over2, i, j;

    alloc(&field, 10, 16);
    fill(field);

    alloc(&position, 5, 3);
    alloc(&position2, 5, 3);

    alloc(&visited1, 10, 16);
    fill0(visited1);

    alloc(&visited2, 10, 16);
    fill0(visited2);

    over1=0;
    over2=0;

    flag1(field, position);
    flag2(field, position2);

    pos1(position);
    pos2(position2);




    while(over1==0 && over2==0)
    {
        over1=player1(field, position, position2, visited2);
        if(over1==0)
            over2=player2(field, position2, position, visited1);
    }

    if(over1==1)
        printf("WELL PLAYED PLAYER 1");
    if(over2==1)
        printf("WELL PLAYER PLAYER 2");

    freeT(field, 10);
    freeT(position, 5);
    freeT(position2, 5);
    freeT(visited1, 10);
    freeT(visited2, 10);

    return 0;
}



