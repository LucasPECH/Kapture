#ifndef FUNCTION2_H_INCLUDED
#define FUNCTION2_H_INCLUDED

// FUNCTION TO FILL POSITION2 WITH THE STARTING POSITION OF PLAYER 2 PAWNS
void pos2(int**position2)
{
    int i;

    for(i=0 ; i<4 ; i++)
    {
        {
            position2[i][1]=15;
            position2[i][2]=1;
        }

        position2[0][0]=1;
        position2[1][0]=4;
        position2[2][0]=5;
        position2[3][0]=8;
    }
}

// FUNCTION TO PLACE THE FLAG OF PLAYER 2 RANDOMLY OR LET HIM CHOOSE
void flag2(int** field, int** position2)
{
    int x;
    int L1, C1, x2, x3;

    Color(0,14);
    printf("PLAYER 2");
    Color(15,0);
    printf(" : Do you want to place your flag or not ?\n");
    printf("1 for choice / 2 for random ");
    scanf("%d", &x);
    printf("\n");

    if(x==1)
    {
        do
        {
        printf("Choose your line and your colummn (your camp is between column 8 and 15) ");
        scanf("%d%d", &L1, &C1);
        }
        while((0>L1 || L1>15) || (C1<8 || C1>15));

        field[L1][C1]=-1;
        position2[4][0]=L1;
        position2[4][1]=C1;
    }
    if(x==2)
    {
        x2=rand()%7+8;
        x3=rand()%10;
        field[x3][x2]=-1;

        position2[4][0]=x3;
        position2[4][1]=x2;
    }
    position2[4][2]=1;
}

// FUNCTION TO CHECK IF THE PAWN OF PLAYER 2 CAN MOVE AT POSITION SAVE
int movement2(int** field, int k, int l, int player)
{
    if(k<0 || k>9 || l<0 || l>15)
        return 1;
    else
    {
        if(10<field[k][l] || field[k][l]==-1 || (field[k][l]==0 && (player==151 || player==150)))
            return 1;
    }
    return 2;
}


#endif // FUNCTION2_H_INCLUDED
