#ifndef FUNCTION1_H_INCLUDED
#define FUNCTION1_H_INCLUDED

// FUNCTION TO FILL POSITION2 WITH THE STARTING POSITION OF PLAYER 1 PAWNS
void pos1(int**position)
{
    int i;

    for(i=0 ; i<4 ; i++)
    {
        {
            position[i][1]=0;
            position[i][2]=1;
        }

        position[0][0]=1;
        position[1][0]=4;
        position[2][0]=5;
        position[3][0]=8;
    }
}



// FUNCTION TO PLACE THE FLAG OF PLAYER 1 RANDOMLY OR LET HIM CHOOSE
void flag1(int** field, int** position)
{
    int x;
    int L1, C1, x2, x3;
    Color(0,4);
    printf("PLAYER 1");
    Color(15,0);
    printf(" : Do you want to place your flag or not ?\n");
    printf("1 for choice / 2 for random ");
    scanf("%d", &x);
    printf("\n");

    if(x==1)
    {
        do
        {
        printf("Choose your line and your colummn (your camp is between column 1 and 7) ");
        scanf("%d%d", &L1, &C1);
        }
        while((0>L1 || L1>15) || (C1<0 || C1>8));

        field[L1][C1]=0;
        position[4][0]=L1;
        position[4][1]=C1;
    }
    if(x==2)
    {
        x2=rand()%7+1;
        x3=rand()%10+1;
        field[x3][x2]=0;

        position[4][0]=x3;
        position[4][1]=x2;
    }
    position[4][2]=1;
}

// FUNCTION TO CHECK IF THE PAWN OF PLAYER 1 CAN MOVE AT POSITION SAVE
int movement1(int** field,int k, int l, int player)
{
    if(k<0 || k>9 || l<0 || l>15)
            return 1;
    else
    {
        if(10<field[k][l] || field[k][l]==0 || (field[k][l]==-1 && (player==51 || player==50)))
            return 1;
    }
    return 2;
}



#endif // FUNCTION1_H_INCLUDED
