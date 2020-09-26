#ifndef FUNCTION_H_INCLUDED
#define FUNCTION_H_INCLUDED

#include <stdio.h>
#include <stdlib.h>
#include <windows.h>
// FUNCTION FOR COLOR
void Color(int couleurDuTexte,int couleurDeFond) // fonction d'affichage de couleurs
{
        HANDLE H=GetStdHandle(STD_OUTPUT_HANDLE);
        SetConsoleTextAttribute(H,couleurDeFond*16+couleurDuTexte);
}
// FUNCTION TO FILL THE VISITED ARRAY WITH 0
void fill0(int** visited)
{
    int i, j;

    for(i=0 ; i++ ; i<10)
    {
        for(j=0 ; j++ ; j<16)
        {
            visited[i][j]=0;
        }
    }
}


// FUNCTION TO FREE A 2D ARRAY
void freeT(int** T, int L)
{
    int i;

    for(i=0 ; i<L ; i++)
        free(T[i]);

    free(T);
}

// FUNCTION TO DROP THE FLAG RANDOMLY
void flagdrop(int**field, int** position1, int k, int l, int flag)
{
    int x, y, i, j;

    do
    {
        x=rand()%30;
        if(x<10)
            i=-1;
        if(x>=10 && x<20)
            i=0;
        if(x>=20 && x<30)
            i=1;

        y=rand()%30;
        if(y<10)
            j=-1;
        if(y>=10 && y<20)
            j=0;
        if(y>=20 && y<30)
            j=1;
    }while(i==0 && i+j==0 || field[k+i][l+j]>10 || k+i>10 || k+i<=0 || l+j>15 || l+j<0);

    position1[4][2]=field[k+i][l+j];
    field[k+i][l+j]=flag;
}

// FUNCTION TO FILL VISITED WITH ONE WHERE THE FIELD HAS BEEN VISITED
void fog(int**visited, int k, int l)
{
    int i;

    for(i=-1 ; i<2 ; i++)
    {
        if(k+i>=0 && k+i<10)
            visited[k+i][l]=1;
        if(l+i>=0 && l+i<16)
            visited[k][l+i]=1;
    }
}

// FUNCTION TO PRINT WITH COLOR AND FOG
void print(int**field, int** visited, int k, int l)
{
    int i, j, unveiled;

    unveiled = 0;
    fog(visited, k, l);

    for(i=0 ; i<10 ; i++)
    {
        for(j=0 ; j<16 ; j++)
        {
            if(visited[i][j]==1)
                unveiled=1;

            if(((i==k-2 || i==k+2) && j==l) || ((i==k-1 || i==k+1) && j>=l-1 && j<=l+1) || (i==k && j>=l-2 && j<=l+2) || unveiled==1)
            {
                if(field[i][j]==50 || field[i][j]==51)
                {
                    Color(0,4);
                    printf(" S ");
                    Color(15,0);
                    printf("  ");
                }
                else if(field[i][j]==20)
                {
                    Color(0,4);
                    printf(" T ");
                    Color(15,0);
                    printf("  ");
                }
                else if(field[i][j]==30)
                {
                    Color(0,4);
                    printf(" I ");
                    Color(15,0);
                    printf("  ");
                }
                else if(field[i][j]==52 || field[i][j]==53)
                {
                    Color(0,4);
                    printf(" Sf");
                    Color(15,0);
                    printf("  ");
                }
                else if(field[i][j]==0)
                {
                    Color(0,4);
                    printf(" F ");
                    Color(15,0);
                    printf("  ");
                }
                else if(field[i][j]==150 || field[i][j]==151)
                {
                    Color(0,14);
                    printf(" S ");
                    Color(15,0);
                    printf("  ");
                }
                else if(field[i][j]==120)
                {
                    Color(0,14);
                    printf(" T ");
                    Color(15,0);
                    printf("  ");
                }
                else if(field[i][j]==130)
                {
                    Color(0,14);
                    printf(" I ");
                    Color(15,0);
                    printf("  ");
                }
                else if(field[i][j]==152 || field[i][j]==153)
                {
                    Color(0,14);
                    printf(" Sf");
                    Color(15,0);
                    printf("  ");
                }
                else if(field[i][j]==-1)
                {
                    Color(0,14);
                    printf(" F ");
                    Color(15,0);
                    printf("  ");
                }
                else if(field[i][j]==5)
                {
                    Color(9,9);
                    printf("   ");
                    Color(15,0);
                    printf("  ");
                }
                else if(field[i][j]==2)
                {
                    Color(6,6);
                    printf("   ");
                    Color(15,0);
                    printf("  ");
                }
                else if(field[i][j]==1)
                {
                    Color(10,10);
                    printf("   ");
                    Color(15,0);
                    printf("  ");
                }
            }
            else
            {
                Color(7,7);
                printf("   ");
                Color(15,0);
                printf("  ");
            }
            unveiled=0;
        }
        printf("\n \n");
    }
}

// FUNCTION TO FILL THE FIELD WITH PAWN AND RANDOM OBSTACLES
void fill(int** field)
{
    int i, j, x;

    srand(time(NULL));

    for(i=0 ; i<10 ; i++)
    {
        for(j=0 ; j<16 ; j++)
        {
            x=rand()%100;
            if(0<=x && x<=60)
                field[i][j]=1;
            if(60<=x && x<=85)
                field[i][j]=2;
            if(85<=x && x<=100)
               field[i][j]=5;
        }
    }

    field[1][0]=20;
    field[1][15]=130;

    field[8][0]=30;
    field[8][15]=120;

    field[4][0]=50;
    field[5][0]=51;

    field[5][15]=150;
    field[4][15]=151;
}


// FUNCTION TO ALLOCATE A 2D ARRAY
void alloc(int*** T,int l,int c)
{
    int i;

    *T = (int**) malloc(sizeof(int*)*l);

    for(i=0 ; i<l ; i++)
        (*T)[i]= (int*) malloc(sizeof(int)*c);
}


// FUNCTION TO CHECK IF YOUR FLAG IS AT IS STARTING POSITION AND IF SOMEONE CARRY THE ENEMY FLAG NEXT TO HIM
int gameover(int** field, int** position, int flag, int carry1, int carry2)
{
    int i, j, checki, checkj;
    for(i=0 ; i<10 ; i++)
    {
        for(j=0 ; j<16 ; j++)
        {
            if(field[i][j]==flag && position[4][0]==i && position[4][1]==j)
            {
                for(checki=-1 ; checki<2 ; checki++)
                {
                    for(checkj=-1 ; checkj<2 ; checkj++)
                    {
                        if(i+checki>=0 && i+checki<10 && j+checkj>=0 && j+checkj<16)
                        {
                            if(field[i+checki][j+checkj]==carry1 || field[i+checki][j+checkj]==carry2)
                                return 1;
                        }
                    }
                }
            }

        }
    }
    return 0;
}

//FUNCTION TO DISPLAY THE RULES
void rules()
{
    printf("DIRECTIONS  \n\n");
    printf("DO NOT USE CAPITAL LETTER.\nEnter : \n z to move forward \n a to move left forward \n q to move left \n w to move left backward \n x to move backward \n c to move right backward \n d to move right \n e to move right forward \n s to pass to the next pawn.\n\n");
    printf("COLORS \n\n");
    printf(" Red: Pawns of player 1\n Yellow: Pawns of player 2\n Blue: River, if you want to cross them, you have to possess all your moving points\n Dark green: Forest, you need 2 moving points to cross them\n Green: Grass, you need only one moving point to cross it\n\n");
    printf("PAWNS \n\n");
    printf(" I: 3 moving points\n T: 2 moving points\n S: 5 moving points\n F : This is the flag you have to capture it and position yourself next to the initial position of your flag ");
}

// FUNCTION TO PRINT PLAYER 1 IN COLOR
void p1Color()
{
    Color(0,4);
    printf("\nPLAYER 1\n\n");
    Color(15,0);
}

// FUNCTION TO PRINT PLAYER 2 IN COLOR
void p2Color()
{
    Color(0,14);
    printf("\nPLAYER 2\n\n");
    Color(15,0);
}

#endif // FUNCTION_H_INCLUDED
