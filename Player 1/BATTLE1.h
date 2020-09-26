#ifndef BATTLE1_H_INCLUDED
#define BATTLE1_H_INCLUDED

// FUNCTION TO MAKES PLAYER 1 BATTLE WORKS
void battlep1(int**field, int** position2, int** position, int save, int p2i, int p2j, int* p1i, int* p1j)

{
    int x, i, j;

    switch(field[p2i][p2j]) // field[p2i][p2j] is the position of the enemy pawn
    {
        case -1:
            if(save==20) // Save is the value of our pawn, so here the pawn played by player1
            {
                field[*p1i][*p1j]=52;
                field[p2i][p2j]=position2[4][2];
            }
            if(save==30)
            {
                field[*p1i][*p1j]=53;
                field[p2i][p2j]=position2[4][2];
            }
            if(save==51 || save==50)
                printf("You can't pick a flag with a scoot");
            break;

        case 150:
            if(save==30 || save==20)
            {
                field[5][15]=150;
                field[p2i][p2j]=position2[2][2];
                position2[2][2]=1;
                position2[2][0]=5;
                position2[2][1]=15;
            }
            break;
        case 151:
            if(save==30 || save==20)
            {
                field[4][15]=151;
                field[p2i][p2j]=position2[1][2];
                position2[1][2]=1;
                position2[1][0]=4;
                position2[1][1]=15;

            }
            break;

        case 152:
            if(save==30 || save==20)
            {
                flagdrop(field, position, p2i, p2j, 0);
                field[8][15]=120;
                field[p2i][p2j]=position2[3][2];
                position2[3][2]=1;
                position2[3][0]=8;
                position2[3][1]=15;

            }
            break;
        case 153:
            if(save==20 || save==30)
            {
                flagdrop(field, position, p2i, p2j, 0);
                field[1][15]=130;
                field[p2i][p2j]=position2[0][2];
                position2[3][2]=1;
                position2[3][0]=1;
                position2[3][1]=15;

            }
            break;

        case 120:
            if(save==20)
            {
                if(field[*p1i][*p1j-1]<10 && *p1j>0)
                {
                    position[0][2]=field[*p1i][*p1j-1];
                    field[*p1i][*p1j]=position[0][2];
                    field[*p1i][*p1j-1]=20;
                    position[0][1]=*p1j-1;
                    *p1j=*p1j-1;
                }
                else
                {
                    field[1][0]=20;
                    field[*p1i][*p1j]=position[0][2];
                    position[0][2]=1;
                    position[0][0]=1;
                    position[0][1]=0;
                    *p1i=0;
                    *p1j=1;
                }

                if(field[p2i][p2j+1]<10 && p2j<15)
                {
                    position2[3][2]=field[p2i][p2j+1];
                    field[p2i][p2j]=position2[3][2];
                    field[p2i][p2j+1]=120;
                    position2[3][1]=p2j+1;
                }
                else
                {
                    field[8][15]=120;
                    field[p2i][p2j]=position2[3][2];
                    position2[3][2]=1;
                    position2[3][0]=8;
                    position2[3][1]=15;
                }
            }

            if(save==30)
            {
                field[8][0]=30;
                field[*p1i][*p1j]=position[3][2];
                position[3][2]=1;
                position[3][0]=8;
                position[3][1]=0;
                *p1i=8;
                *p1j=0;
              }
            if(save==53)
            {
                flagdrop(field, position2, *p1i, *p1j, -1);
                field[8][0]=30;
                field[*p1i][*p1j]=position[3][2];
                position[3][2]=1;
                position[3][0]=8;
                position[3][1]=0;
                *p1i=8;
                *p1j=0;
            }
            if(save==52)
            {
                flagdrop(field, position2, *p1i, *p1j, -1);
                field[1][0]=20;
                field[*p1i][*p1j]=position[0][2];
                position[0][2]=1;
                position[0][0]=1;
                position[0][1]=0;
                *p1i=1;
                *p1j=0;
            }
            if(save==51)
            {
                field[5][0]=51;
                field[*p1i][*p1j]=position[2][2];
                position[2][2]=1;
                position[2][0]=5;
                position[2][1]=0;
                *p1i=5;
                *p1j=0;
            }
            if(save==50)
            {
                field[4][0]=50;
                field[*p1i][*p1j]=position[1][2];
                position[1][2]=1;
                position[1][0]=4;
                position[1][1]=0;
                *p1i=4;
                *p1j=0;
            }
            break;

        case 130:
            if(save==30)
            {
                x=rand()%100;
                if(x<=50)
                {
                    field[8][0]=30;
                    field[*p1i][*p1j]=position[3][2];
                    position[3][2]=1;
                    position[3][0]=8;
                    position[3][1]=0;
                    *p1i=8;
                    *p1j=0;
                }
                else
                {
                    field[1][15]=130;
                    field[p2i][p2j]=position2[0][2];
                    position2[0][2]=1;
                    position2[0][0]=1;
                    position2[0][1]=15;
                }

            }
            if(save==53)
            {
                flagdrop(field, position2, *p1i, *p1j, -1);
                field[8][0]=30;
                field[*p1i][*p1j]=position[3][2];
                position[3][2]=1;
                position[3][0]=8;
                position[3][1]=0;
                *p1i=8;
                *p1j=0;
            }
            if(save==52)
            {
                flagdrop(field, position2, *p1i, *p1j, -1);
                field[1][0]=20;
                field[*p1i][*p1j]=position[0][2];
                position[0][2]=1;
                position[0][0]=1;
                position[0][1]=0;
                *p1i=1;
                *p1j=0;
            }
            if(save==51)
            {
                field[5][0]=51;
                field[*p1i][*p1j]=position[2][2];
                position[2][2]=1;
                position[2][0]=5;
                position[2][1]=0;
                *p1i=5;
                *p1j=0;
            }
            if(save==50)
            {
                field[4][0]=50;
                field[*p1i][*p1j]=position[1][2];
                position[1][2]=1;
                position[1][0]=4;
                position[1][1]=0;
                *p1i=4;
                *p1j=0;
            }
            if(save==20)
            {
                field[1][15]=130;
                field[p2i][p2j]=position2[0][2];
                position2[0][2]=1;
                position2[0][0]=1;
                position2[0][1]=15;
            }
            break;
    }
}


#endif // BATTLE1_H_INCLUDED
