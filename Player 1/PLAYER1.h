#ifndef PLAYER1_H_INCLUDED
#define PLAYER1_H_INCLUDED
#include "BATTLE1.h"
#include "FUNCTION1.h"

// FUNCTION WHICH ALLOW THE PLAYER 1 MOVE HIS PAWNS
int player1(int** field, int** position, int** position2, int** visited1)
{
    int i, j, k, l, PM, pos, save, cpt, test, cpt1, cpt2, end;
    char deplacement;

    cpt=0;

    while(cpt<4)
    {

        k=position[cpt][0]; //k is the line of the pawn we are moving
        l=position[cpt][1]; //l is the column
        if(field[k][l]>51)
            PM = (field[k][l]%50); //Higher than 51 means he has a flag (so field[k][l] is 52 or 53)
        else
            PM = field[k][l]/10; //field[k][l] is 30, 20, 51 or 50

        do
        {
            p1Color();
            print(field, visited1, k, l);
            printf("Move your pawn or enter h for help");
            printf("\nYou have : %d PM\n", PM);
            scanf(" %c", &deplacement);

            PM = PM-position[cpt][2];
            pos = field[k][l];
            switch(deplacement)
            {
            case 'z':
                test=movement1(field, k-1, l, field[k][l]);
                if(test==2)
                {
                    save=field[k-1][l];
                    field[k-1][l]=pos;
                    field[k][l]=position[cpt][2];
                    position[cpt][2]=save;
                    k--;
                }
                else
                {
                    printf("You can't move here, try again.\n");
                    PM=PM+position[cpt][2];
                }

                break;
            case 'a':
                test=movement1(field, k-1, l-1, field[k][l]);
                if(test==2)
                {
                    save=field[k-1][l-1];
                    field[k-1][l-1]=pos;
                    field[k][l]=position[cpt][2];
                    position[cpt][2]=save;
                    k--;
                    l--;
                }
                else
                {
                    printf("You can't move here, try again.\n");
                    PM=PM+position[cpt][2];
                }

                break;
            case 'q':
                test=movement1(field, k, l-1, field[k][l]);
                if(test==2)
                {
                    save=field[k][l-1];
                    field[k][l-1]=pos;
                    field[k][l]=position[cpt][2];
                    position[cpt][2]=save;
                    l--;
                }
                else
                {
                    printf("You can't move here, try again.\n");
                    PM=PM+position[cpt][2];
                }

                break;
            case 'w':
                test=movement1(field, k+1, l-1, field[k][l]);
                if(test==2)
                {
                    save=field[k+1][l-1];
                    field[k+1][l-1]=pos;
                    field[k][l]=position[cpt][2];
                    position[cpt][2]=save;
                    k++;
                    l--;
                }
                else
                {
                    printf("You can't move here, try again.\n");
                    PM=PM+position[cpt][2];
                }

                break;
            case 'x':
                test=movement1(field, k+1, l, field[k][l]);
                if(test==2)
                {
                    save=field[k+1][l];
                    field[k+1][l]=pos;
                    field[k][l]=position[cpt][2];
                    position[cpt][2]=save;
                    k++;
                }
                else
                {
                    printf("You can't move here, try again.\n");
                    PM=PM+position[cpt][2];
                }

                break;
            case 'c':
                test=movement1(field, k+1, l+1, field[k][l]);
                if(test==2)
                {
                    save=field[k+1][l+1];
                    field[k+1][l+1]=pos;
                    field[k][l]=position[cpt][2];
                    position[cpt][2]=save;
                    k++;
                    l++;
                }
                else
                {
                    printf("You can't move here, try again.\n");
                    PM=PM+position[cpt][2];
                }
                break;

            case 'd':
                test=movement1(field, k, l+1, field[k][l]);
                if(test==2)
                {
                    save=field[k][l+1];
                    field[k][l+1]=pos;
                    field[k][l]=position[cpt][2];
                    position[cpt][2]=save;
                    l++;
                }
                else
                {
                    printf("You can't move here, try again.\n");
                    PM=PM+position[cpt][2];
                }
                break;
            case 'e':
                test=movement1(field, k-1, l+1, field[k][l]);
                if(test==2)
                {
                    save=field[k-1][l+1];
                    field[k-1][l+1]=pos;
                    field[k][l]=position[cpt][2];
                    position[cpt][2]=save;
                    l++;
                    k--;
                }
                else
                {
                    printf("You can't move here, try again.\n");
                    PM=PM+position[cpt][2];
                }

                break;
            case 'h':
                rules();
                PM = PM+position[cpt][2];
                break;
            default:
                PM=PM-100;
                break;
            }
            position[cpt][0]=k;
            position[cpt][1]=l;
            fog(visited1, k, l);

            cpt1=k; // we use this because we may change k or l during the battle

            cpt2=l;

            for(i=-1 ; i<2 ; i++) // this loop scan around the pawn to find enemy pawn
            {
                for(j=-1 ; j<2 ; j++)
                {
                    if(cpt1+i>=0 && cpt2+j>=0 && cpt1+i<10 && cpt2+j<=15)
                    {
                        if((field[cpt1+i][cpt2+j]>53 && field[cpt1+i][cpt2+j]<200) || field[cpt1+i][cpt2+j]==-1)
                        {
                            p1Color();
                            printf("/!/ BATTLE /!/ \n");
                            print(field, visited1, k, l); // print why there is a battle
                            printf("\n");
                            battlep1(field, position2, position, field[k][l], k+i, l+j, &k, &l);
                        }
                    }
                }
            }
            end=gameover(field, position, 0, 52, 53);
            if(end==1)
            {
                print(field, visited1, k, l); //print the final field
                return 1; // it will stop the loop in the main
            }

        }while(PM-position[cpt][2]>=0);
        cpt++; // cpt correspond to the number of the pawn we are playing, there is only 4 pawns
    }
    p1Color();
    print(field, visited1, k, l);
    return 0; // not game over
}



#endif // PLAYER1_H_INCLUDED
