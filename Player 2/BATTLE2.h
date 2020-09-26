#ifndef BATTLE2_H_INCLUDED
#define BATTLE2_H_INCLUDED

// FUNCTION WHICH MAKES BATTLE FOR PLAYER 2
void battlep2(int**field, int** position2, int** position, int save, int* p2i, int* p2j, int p1i, int p1j)
{
    int x, i, j;

    switch(field[p1i][p1j])
    {
        case 0:
            if(save==120)
            {
                field[*p2i][*p2j]=152;
                field[p1i][p1j]=position[4][2];
            }
            if(save==130)
            {
                field[*p2i][*p2j]=153;
                field[p1i][p1j]=position[4][2];
            }
            if(save==151 || save==150)
                printf("You can't pick a flag with a scoot");
            break;
        case 50:
            if(save==130 || save==120)
            {
                field[4][0]=50;
                field[p1i][p1j]=position[1][2];
                position[1][2]=1;
                position[1][0]=4;
                position[1][1]=0;

            }
            break;

        case 51:
            if(save==130 || save==120)
            {
                field[5][0]=51;
                field[p1i][p1j]=position[2][2];
                position[2][2]=1;
                position[2][0]=5;
                position[2][1]=0;
            }
            break;

        case 52:
            if(save==130 || save==120)
            {
                flagdrop(field, position2, p1i, p1j, -1);
                field[1][0]=20;
                field[p1i][p1j]=position[0][2];
                position[0][2]=1;
                position[0][0]=1;
                position[0][1]=0;
            }
            break;

        case 53:
            if(save==120 || save==130)
            {
                flagdrop(field, position2, p1i, p1j, -1);
                field[8][0]=30;
                field[p1i][p1j]=position[3][2];
                position[3][2]=1;
                position[3][0]=8;
                position[3][1]=0;

            }
            break;

        case 20:
            if(save==120)
            {
                if(field[p1i][p1j-1]<10 && p1j>0)
                {
                    position[0][2]=field[p1i][p1j-1];
                    field[p1i][p1j]=position[0][2];
                    field[p1i][p1j-1]=20;
                    position[0][1]=p1j-1;
                }
                else
                {
                    field[1][0]=20;
                    field[p1i][p1j]=position[0][2];
                    position[0][2]=1;
                    position[0][0]=1;
                    position[0][1]=0;
                }

                if(field[*p2i][*p2j+1]<10 && *p2j<15)
                {
                    position2[3][2]=field[*p2i][*p2j+1];
                    field[*p2i][*p2j]=position2[3][2];
                    field[*p2i][*p2j+1]=120;
                    position2[3][1]=*p2j+1;
                }
                else
                {
                    field[8][15]=120;
                    field[*p2i][*p2j]=position2[3][2];
                    position2[3][2]=1;
                    position2[3][0]=8;
                    position2[3][1]=15;
                    *p2i=8;
                    *p2j=15;
                }
            }
            if(save==130)
            {
                field[1][15]=130;
                field[*p2i][*p2j]=position2[0][2];
                position2[0][2]=1;
                position2[0][0]=1;
                position2[0][1]=15;
                *p2i=1;
                *p2j=15;
            }
            if(save==153)
            {
                flagdrop(field, position, *p2i, *p2j, 0);
                field[1][15]=130;
                field[*p2i][*p2j]=position2[0][2];
                position2[0][2]=1;
                position2[0][0]=1;
                position2[0][1]=15;
                *p2i=1;
                *p2j=15;
            }
            if(save==152)
            {
                flagdrop(field, position, *p2i, *p2j, 0);
                field[8][15]=120;
                field[*p2i][*p2j]=position2[3][2];
                position2[3][2]=1;
                position2[3][0]=8;
                position2[3][1]=15;
                *p2i=8;
                *p2j=15;
            }
            if(save==151)
            {
                field[4][15]=151;
                field[*p2i][*p2j]=position2[1][2];
                position2[1][2]=1;
                position2[1][0]=4;
                position2[1][1]=15;
                *p2i=4;
                *p2j=15;

            }
            if(save==150)
            {
                field[5][15]=150;
                field[*p2i][*p2j]=position2[2][2];
                position2[2][2]=1;
                position2[2][0]=5;
                position2[2][1]=15;
                *p2i=5;
                *p2j=15;
            }
            break;
        case 30:
            if(save==130)
            {
                x=rand()%100;
                if(x<=50)
                {
                    field[1][15]=130;
                    field[*p2i][*p2j]=position2[0][2];
                    position2[0][2]=1;
                    position2[0][0]=1;
                    position2[0][1]=15;
                    *p2i=1;
                    *p2j=15;
                }
                else
                {
                    field[8][0]=30;
                    field[p1i][p1j]=position[3][2];
                    position[3][2]=1;
                    position[3][0]=8;
                    position[3][1]=0;
                }

            }
            if(save==153)
            {
                flagdrop(field, position, *p2i, *p2j, 0);
                field[1][15]=130;
                field[*p2i][*p2j]=position2[0][2];
                position2[0][2]=1;
                position2[0][0]=1;
                position2[0][1]=15;
                *p2i=1;
                *p2j=15;
            }
            if(save==152)
            {
                flagdrop(field, position, *p2i, *p2j, 0);
                field[8][15]=120;
                field[*p2i][*p2j]=position2[3][2];
                position2[3][2]=1;
                position2[3][0]=8;
                position2[3][1]=15;
                *p2i=8;
                *p2j=15;
            }
            if(save==151)
            {
                field[4][15]=151;
                field[*p2i][*p2j]=position2[1][2];
                position2[1][2]=1;
                position2[1][0]=4;
                position2[1][1]=15;
                *p2i=4;
                *p2j=15;

            }
            if(save==150)
            {
                field[5][15]=150;
                field[*p2i][*p2j]=position2[2][2];
                position2[2][2]=1;
                position2[2][0]=5;
                position2[2][1]=15;
                *p2i=5;
                *p2j=15;
            }
            if(save==120)
            {
                field[8][0]=30;
                field[p1i][p1j]=position[3][2];
                position[3][2]=1;
                position[3][0]=8;
                position[3][1]=0;
            }
            break;
    }
}



#endif // BATTLE2_H_INCLUDED
