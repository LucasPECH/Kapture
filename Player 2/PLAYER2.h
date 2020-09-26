#ifndef PLAYER2_H_INCLUDED
#define PLAYER2_H_INCLUDED
#include "BATTLE2.h"
#include "FUNCTION2.h"

// FUNCTION WHICH ALLOW THE PLAYER2 MOVE HIS PAWNS
int player2(int** field, int** position2, int** position, int** visited2)
{
    int i, j, k, l, PM, pos, save, cpt1, cpt2, test, cpt, end;
    char deplacement;

    cpt=0;

    save=1;

    while(cpt<4)
    {
        k=position2[cpt][0];
        l=position2[cpt][1];
        if(field[k][l]>151)
            PM = (field[k][l]%50);
        else
            PM = (field[k][l]-100)/10;
        do
        {
            p2Color();
            print(field, visited2, k, l);
            printf("Move your pawn or enter h for help");
            printf("\nYou have : %d PM\n", PM);
            scanf(" %c", &deplacement);

            PM = PM-position2[cpt][2];
            pos = field[k][l];
            switch(deplacement)
            {
            case 'z':
                test=movement2(field, k-1, l, field[k][l]);
                if(test==2)
                {
                    save=field[k-1][l];
                    field[k-1][l]=pos;
                    field[k][l]=position2[cpt][2];
                    position2[cpt][2]=save;
                    k--;
                }
                else
                {
                    printf("You can't move here, try again.\n");
                    PM=PM+position2[cpt][2];
                }

                break;
            case 'a':
                test=movement2(field, k-1, l-1, field[k][l]);
                if(test==2)
                {
                    save=field[k-1][l-1];
                    field[k-1][l-1]=pos;
                    field[k][l]=position2[cpt][2];
                    position2[cpt][2]=save;
                    k--;
                    l--;
                }
                else
                {
                    printf("You can't move here, try again.\n");
                    PM=PM+position2[cpt][2];
                }

                break;
            case 'q':
                test=movement2(field, k, l-1, field[k][l]);
                if(test==2)
                {
                    save=field[k][l-1];
                    field[k][l-1]=pos;
                    field[k][l]=position2[cpt][2];
                    position2[cpt][2]=save;
                    l--;
                }
                else
                {
                    printf("You can't move here, try again.\n");
                    PM=PM+position2[cpt][2];
                }

                break;
            case 'w':
                test=movement2(field, k+1, l-1, field[k][l]);
                if(test==2)
                {
                    save=field[k+1][l-1];
                    field[k+1][l-1]=pos;
                    field[k][l]=position2[cpt][2];
                    position2[cpt][2]=save;
                    k++;
                    l--;
                }
                else
                {
                    printf("You can't move here, try again.\n");
                    PM=PM+position2[cpt][2];
                }

                break;
            case 'x':
                test=movement2(field, k+1, l, field[k][l]);
                if(test==2)
                {
                    save=field[k+1][l];
                    field[k+1][l]=pos;
                    field[k][l]=position2[cpt][2];
                    position2[cpt][2]=save;
                    k++;
                }
                else
                {
                    printf("You can't move here, try again.\n");
                    PM=PM+position2[cpt][2];
                }

                break;
            case 'c':
                test=movement2(field, k+1, l+1, field[k][l]);
                if(test==2)
                {
                    save=field[k+1][l+1];
                    field[k+1][l+1]=pos;
                    field[k][l]=position2[cpt][2];
                    position2[cpt][2]=save;
                    k++;
                    l++;
                }
                else
                {
                    printf("You can't move here, try again.\n");
                    PM=PM+position2[cpt][2];
                }
                break;

            case 'd':
                test=movement2(field, k, l+1, field[k][l]);
                if(test==2)
                {
                    save=field[k][l+1];
                    field[k][l+1]=pos;
                    field[k][l]=position2[cpt][2];
                    position2[cpt][2]=save;
                    l++;
                }
                else
                {
                    printf("You can't move here, try again.\n");
                    PM=PM+position2[cpt][2];
                }
                break;
            case 'e':
                test=movement2(field, k-1, l+1, field[k][l]);
                if(test==2)
                {
                    save=field[k-1][l+1];
                    field[k-1][l+1]=pos;
                    field[k][l]=position2[cpt][2];
                    position2[cpt][2]=save;
                    l++;
                    k--;
                }
                else
                {
                    printf("You can't move here, try again.\n");
                    PM=PM+position2[cpt][2];
                }

                break;
            case 'h':
                rules();
                PM = PM+position2[cpt][2];
                break;
            default:
                PM=PM-100;
                break;
            }
            position2[cpt][0]=k;
            position2[cpt][1]=l;

            fog(visited2, k, l);

            cpt1=k;

            cpt2=l;


            for(i=-1 ; i<2 ; i++)
            {
                for(j=-1 ; j<2 ; j++)
                {
                    if(cpt1+i>=0 && cpt2+j>=0 && cpt1+i<10 && cpt2+j<=15)
                    {
                        if((field[cpt1+i][cpt2+j]<120 && field[cpt1+i][cpt2+j]>10) || field[cpt1+i][cpt2+j]==0)
                        {
                            p2Color();
                            printf("/!/ BATTLE /!/ \n");
                            print(field, visited2, k, l);
                            printf("\n");
                            battlep2(field, position2, position, field[k][l], &k, &l, k+i, l+j);
                        }
                    }
                }
            }
            end=gameover(field, position2, -1, 152, 153);
            if(end==1)
            {
                print(field, visited2, k, l);
                return 1;
            }

        }while(PM-position2[cpt][2]>=0);
        cpt++;
    }
    p2Color();
    print(field, visited2, k, l);
    return 0;
}



#endif // PLAYER2_H_INCLUDED
