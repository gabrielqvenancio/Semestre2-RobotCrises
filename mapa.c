#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <conio.h>
#include <time.h>
#include <windows.h>
#include <math.h>
#include <sys/time.h>
#include <locale.h>

#define limitex 90
#define limitey 90

typedef struct
{
    int XPyield;
    char nome[35];
    int HP;
    int ATK;
    int DEF;
    int SPD;
    int posNightx;
    int posNighty;
}robosNight;

void ResetaEstruturas(char **m)
{
    for(int i = 1; i < limitey - 1; i++)
    {
        for(int j = 1; j < limitex - 1; j++)
        {
            if(m[i][j] == 'v')
                m[i][j] = 'V';
            else if(m[i][j] == 'w')
                m[i][j] = 'W';
            else if(m[i][j] == 'b')
                m[i][j] == 'B';
        }
    }
}

void atualizaTela(char mov, char **m, int *posxDann, int *posyDann, char *blocoAnt, int *inicio, int *gameover, int *qtdBerries, int *qtdEnlatada, int *qtdOleo, int *sede, double *totalfls)
{
    int mudaEstrutura = 0;
    srand(time(NULL));
    int posxDann2;
    int posyDann2;
    FILE *arq;
    int escolheDrop;

    if(mov != '\0')
    {
        gotoxy(0,39);
        printf("                                  ");
    }

    if(*inicio == 0)
    {
        if(*posxDann < 30)
        {
            if(*posyDann < 30)
            {
                for(int i = 0; i < 30; i++)
                {
                    for(int j = 0; j < 30; j++)
                    {
                        gotoxy(j,i);
                        printf("%c", m[i][j]);
                    }
                    gotoxy(90, i);
                    printf("\n");
                }
            }
            else if(*posyDann >= 30 && *posyDann < 60)
            {
                for(int i = 30; i < 60; i++)
                {
                    for(int j = 0; j < 30; j++)
                    {
                        gotoxy(j, i - 29);
                        printf("%c", m[i][j]);
                    }
                    gotoxy(90, i);
                    printf("\n");
                }
            }
            else if(*posyDann >= 60 && *posyDann < 89)
            {
                for(int i = 60; i < 89; i++)
                {
                    for(int j = 0; j < 30; j++)
                    {
                        gotoxy(j, i - 59);
                        printf("%c", m[i][j]);
                    }
                    gotoxy(90, i);
                    printf("\n");
                }
            }
        }
        else if(*posxDann >= 30 && *posxDann < 60)
        {
            if(*posyDann < 30)
            {
                for(int i = 0; i < 30; i++)
                {
                    for(int j = 30; j < 60; j++)
                    {
                        gotoxy(j - 29, i);
                        printf("%c", m[i][j]);
                    }
                    gotoxy(90, i);
                    printf("\n");
                }
            }
            else if(*posyDann >= 30 && *posyDann < 60)
            {
                for(int i = 30; i < 60; i++)
                {
                    for(int j = 30; j < 60; j++)
                    {
                        gotoxy(j - 29, i - 29);
                        printf("%c", m[i][j]);
                    }
                    gotoxy(90, i);
                    printf("\n");
                }
            }
            else if(*posyDann >= 60 && *posyDann < 89)
            {
                for(int i = 60; i < 90; i++)
                {
                    for(int j = 30; j < 60; j++)
                    {
                        gotoxy(j - 29, i - 59);
                        printf("%c", m[i][j]);
                    }
                    gotoxy(90, i);
                    printf("\n");
                }
            }
        }
        else if(*posxDann >= 60 && *posxDann < 89)
        {
            if(*posyDann < 30)
            {
                for(int i = 0; i < 30; i++)
                {
                    for(int j = 60; j < 90; j++)
                    {
                        gotoxy(j - 59, i);
                        printf("%c", m[i][j]);
                    }
                    gotoxy(90, i);
                    printf("\n");
                }
            }
            else if(*posyDann >= 30 && *posyDann < 60)
            {
                for(int i = 30; i < 60; i++)
                {
                    for(int j = 60; j < 90; j++)
                    {
                        gotoxy(j - 59, i - 29);
                        printf("%c", m[i][j]);
                    }
                    gotoxy(90, i);
                    printf("\n");
                }
            }
            else if(*posyDann >= 60 && *posyDann < 89)
            {
                for(int i = 60; i < 90; i++)
                {
                    for(int j = 60; j < 90; j++)
                    {
                        gotoxy(j - 59, i - 59);
                        printf("%c", m[i][j]);
                    }
                    gotoxy(90, i);
                    printf("\n");
                }
            }
        }
        *inicio = 1;
    }
    if(mov == 'w')
    {
        if(m[*posyDann - 1][*posxDann] == ' ' || m[*posyDann - 1][*posxDann] == '+' || m[*posyDann - 1][*posxDann] == 'O')
        {
            m[*posyDann][*posxDann] = *blocoAnt;
            if(*posxDann >= 30 && *posxDann < 60)
            {
                posxDann2 = *posxDann - 29;
            }
            else if(*posxDann >= 60 && *posxDann < 90)
            {
                posxDann2 = *posxDann - 59;
            }
            else
            {
                posxDann2 = *posxDann;
            }

            if(*posyDann >= 30 && *posyDann < 60)
            {
                posyDann2 = *posyDann - 29;
            }
            else if(*posyDann >= 60 && *posyDann < 90)
            {
                posyDann2 = *posyDann - 59;
            }
            else
            {
                posyDann2 = *posyDann;
            }
            gotoxy(posxDann2, posyDann2);
            printf("%c", m[*posyDann][*posxDann]);
            *blocoAnt = m[*posyDann - 1][*posxDann];
            (*posyDann)--;
            if(*posyDann == 29)
            {
                system("CLS");
                if(*posxDann < 30)
                {
                    for(int i = 0; i < 30; i++)
                    {
                        for(int j = 0; j < 30; j++)
                        {
                            gotoxy(j,i);
                            printf("%c", m[i][j]);
                        }
                        printf("\n");
                    }
                }
                else if(*posxDann >= 30 && *posxDann < 60)
                {
                    for(int i = 0; i < 30; i++)
                    {
                        for(int j = 30; j < 60; j++)
                        {
                            gotoxy(j - 29,i);
                            printf("%c", m[i][j]);
                        }
                        printf("\n");
                    }
                }
                else if(*posxDann >= 60 && *posxDann < 89)
                {
                    for(int i = 0; i < 30; i++)
                    {
                        for(int j = 60; j < 90; j++)
                        {
                            gotoxy(j - 59,i);
                            printf("%c", m[i][j]);
                        }
                        printf("\n");
                    }
                }
            }
            else if(*posyDann == 59)
            {
                system("CLS");
                if(*posxDann < 30)
                {
                    for(int i = 30; i < 60; i++)
                    {
                        for(int j = 0; j < 30; j++)
                        {
                            gotoxy(j,i - 29);
                            printf("%c", m[i][j]);
                        }
                        printf("\n");
                    }
                }
                else if(*posxDann >= 30 && *posxDann < 60)
                {
                    for(int i = 30; i < 60; i++)
                    {
                        for(int j = 30; j < 60; j++)
                        {
                            gotoxy(j - 29,i - 29);
                            printf("%c", m[i][j]);
                        }
                        printf("\n");
                    }
                }
                else if(*posxDann >= 60 && *posxDann < 90)
                {
                    for(int i = 30; i < 60; i++)
                    {
                        for(int j = 60; j < 90; j++)
                        {
                            gotoxy(j - 59,i - 29);
                            printf("%c", m[i][j]);
                        }
                        printf("\n");
                    }
                }
            }
        }
        if(m[*posyDann - 1][*posxDann] == 'V')
        {
            gotoxy(0,39);
            printf("Você pegou Óleo!!");

            (*qtdOleo)++;
            (*totalfls) += 10;

            for(int i = -1; i <= 1; i++)
            {
                for(int j = -3; j <= 3; j++)
                {
                    if(m[*posyDann - 1 + i][*posxDann + j] == 'V')
                    {
                        m[*posyDann - 1 + i][*posxDann + j] = 'v';
                        mudaEstrutura++;
                    }
                }
            }
        }
        else if(m[*posyDann - 1][*posxDann] == 'W')
        {
            gotoxy(0,39);
            printf("Você pegou Frutas!!");

            (*qtdBerries)++;
            (*totalfls) += 5;
            m[*posyDann - 1][*posxDann] = 'w';
            mudaEstrutura++;
        }
        else if(m[*posyDann - 1][*posxDann] == 'B')
        {
            escolheDrop = rand()%2;

            if(escolheDrop == 0)
            {
                gotoxy(0,39);
                printf("Você pegou Óleo!!");

                (*qtdOleo)++;
            }
            else
            {
                gotoxy(0,39);
                printf("Você pegou Comida Enlatada!!");

                (*qtdEnlatada)++;
            }
            (*totalfls) += 15;
            for(int i = -1; i <= 1; i++)
            {
                for(int j = -2; j <= 2; j++)
                {
                    if(m[*posyDann - 1 + i][*posxDann + j] == 'B')
                    {
                        m[*posyDann - 1 + i][*posxDann + j] = 'b';
                        mudaEstrutura++;
                    }
                }
            }
        }
        else if(m[*posyDann - 1][*posxDann] == '-')
        {
            gotoxy(0,39);
            printf("Você encontrou Água!!");

            (*sede) += 10;
            (*totalfls) += 5;
            if(*sede > 100)
            {
                *sede = 100;
            }
        }
        if(mudaEstrutura != 0)
        {
            *inicio = 0;
            mudaEstrutura = 0;
        }
    }
    else if(mov == 'a')
    {
        if(m[*posyDann][*posxDann - 1] == ' ' || m[*posyDann][*posxDann - 1] == '+' || m[*posyDann][*posxDann - 1] == 'O')
        {
            m[*posyDann][*posxDann] = *blocoAnt;
            if(*posxDann >= 30 && *posxDann < 60)
            {
                posxDann2 = *posxDann - 29;
            }
            else if(*posxDann >= 60 && *posxDann < 90)
            {
                posxDann2 = *posxDann - 59;
            }
            else
            {
                posxDann2 = *posxDann;
            }

            if(*posyDann >= 30 && *posyDann < 60)
            {
                posyDann2 = *posyDann - 29;
            }
            else if(*posyDann >= 60 && *posyDann < 90)
            {
                posyDann2 = *posyDann - 59;
            }
            else
            {
                posyDann2 = *posyDann;
            }
            gotoxy(posxDann2, posyDann2);
            printf("%c", m[*posyDann][*posxDann]);
            *blocoAnt = m[*posyDann][*posxDann - 1];
            (*posxDann)--;
            if(*posxDann == 29)
            {
                system("CLS");
                if(*posyDann < 30)
                {
                    for(int i = 0; i < 30; i++)
                    {
                        for(int j = 0; j < 30; j++)
                        {
                            gotoxy(j,i);
                            printf("%c", m[i][j]);
                        }
                        printf("\n");
                    }
                }
                else if(*posyDann >= 30 && *posyDann < 60)
                {
                    for(int i = 30; i < 60; i++)
                    {
                        for(int j = 0; j < 30; j++)
                        {
                            gotoxy(j,i - 29);
                            printf("%c", m[i][j]);
                        }
                        printf("\n");
                    }
                }
                else if(*posyDann >= 60 && *posyDann < 89)
                {
                    for(int i = 60; i < 90; i++)
                    {
                        for(int j = 0; j < 30; j++)
                        {
                            gotoxy(j,i - 59);
                            printf("%c", m[i][j]);
                        }
                        gotoxy(90, i);
                        printf("\n");
                    }
                }
            }
            else if(*posxDann == 59)
            {
                system("CLS");
                if(*posyDann < 30)
                {
                    for(int i = 0; i < 30; i++)
                    {
                        for(int j = 30; j < 60; j++)
                        {
                            gotoxy(j - 29,i);
                            printf("%c", m[i][j]);
                        }
                        gotoxy(90, i);
                        printf("\n");
                    }
                }
                else if(*posyDann >= 30 && *posyDann < 60)
                {
                    for(int i = 30; i < 60; i++)
                    {
                        for(int j = 30; j < 60; j++)
                        {
                            gotoxy(j - 29, i - 29);
                            printf("%c", m[i][j]);
                        }
                        gotoxy(90, i);
                        printf("\n");
                    }
                }
                else if(*posyDann >= 60 && *posyDann < 90)
                {
                    for(int i = 60; i < 90; i++)
                    {
                        for(int j = 30; j < 60; j++)
                        {
                            gotoxy(j - 29, i - 59);
                            printf("%c", m[i][j]);
                        }
                        gotoxy(90, i);
                        printf("\n");
                    }
                }
            }
        }
        if(m[*posyDann][*posxDann - 1] == 'V')
        {
            gotoxy(0,39);
            printf("Você pegou Óleo!!");

            (*qtdOleo)++;
            (*totalfls) += 10;

            for(int i = -1; i <= 1; i++)
            {
                for(int j = -3; j <= 3; j++)
                {
                    if(m[*posyDann + i][*posxDann - 1 + j] == 'V')
                    {
                        m[*posyDann + i][*posxDann - 1 + j] = 'v';
                        mudaEstrutura++;
                    }
                }
            }
        }
        else if(m[*posyDann][*posxDann - 1] == 'W')
        {
            gotoxy(0,39);
            printf("Você pegou Frutas!!");

            (*qtdBerries)++;
            (*totalfls) += 5;
            m[*posyDann][*posxDann - 1] = 'w';
            mudaEstrutura++;
        }
        else if(m[*posyDann][*posxDann - 1] == 'B')
        {
            escolheDrop = rand()%2;

            if(escolheDrop == 0)
            {
                gotoxy(0,39);
                printf("Você pegou Óleo!!");

                (*qtdOleo)++;
            }
            else
            {
                gotoxy(0,39);
                printf("Você pegou Comida Enlatada!!");

                (*qtdEnlatada)++;
            }
            (*totalfls) += 15;
            for(int i = -1; i <= 1; i++)
            {
                for(int j = -2; j <= 2; j++)
                {
                    if(m[*posyDann + i][*posxDann - 1 + j] == 'B')
                    {
                        m[*posyDann + i][*posxDann - 1 + j] = 'b';
                        mudaEstrutura++;
                    }
                }
            }
        }
        else if(m[*posyDann][*posxDann - 1] == '-')
        {
            gotoxy(0,39);
            printf("Você encontrou Água!!");

            (*sede) += 10;
            (*totalfls) += 5;
            if(*sede > 100)
            {
                *sede = 100;
            }
        }
        if(mudaEstrutura != 0)
        {
            *inicio = 0;
            mudaEstrutura = 0;
        }
    }
    else if(mov == 's')
    {
        if(m[*posyDann + 1][*posxDann] == ' ' || m[*posyDann + 1][*posxDann] == '+' || m[*posyDann + 1][*posxDann] == 'O')
        {
            m[*posyDann][*posxDann] = *blocoAnt;
            if(*posxDann >= 30 && *posxDann < 60)
            {
                posxDann2 = *posxDann - 29;
            }
            else if(*posxDann >= 60 && *posxDann < 90)
            {
                posxDann2 = *posxDann - 59;
            }
            else
            {
                posxDann2 = *posxDann;
            }

            if(*posyDann >= 30 && *posyDann < 60)
            {
                posyDann2 = *posyDann - 29;
            }
            else if(*posyDann >= 60 && *posyDann < 90)
            {
                posyDann2 = *posyDann - 59;
            }
            else
            {
                posyDann2 = *posyDann;
            }
            gotoxy(posxDann2, posyDann2);
            printf("%c", m[*posyDann][*posxDann]);
            *blocoAnt = m[*posyDann + 1][*posxDann];
            (*posyDann)++;
            if(*posyDann == 60)
            {
                system("CLS");
                if(*posxDann < 30)
                {
                    for(int i = 60; i < 90; i++)
                    {
                        for(int j = 0; j < 30; j++)
                        {
                            gotoxy(j, i - 59);
                            printf("%c", m[i][j]);
                        }
                        gotoxy(90, i);
                        printf("\n");
                    }
                }
                else if(*posxDann >= 30 && *posxDann < 60)
                {
                    for(int i = 60; i < 90; i++)
                    {
                        for(int j = 30; j < 60; j++)
                        {
                            gotoxy(j - 29, i - 59);
                            printf("%c", m[i][j]);
                        }
                        gotoxy(90, i);
                        printf("\n");
                    }
                }
                else if(*posxDann >= 60 && *posxDann < 89)
                {
                    for(int i = 60; i < 90; i++)
                    {
                        for(int j = 60; j < 90; j++)
                        {
                            gotoxy(j - 59, i - 59);
                            printf("%c", m[i][j]);
                        }
                        gotoxy(90, i);
                        printf("\n");
                    }
                }
            }
            else if(*posyDann == 30)
            {
                system("CLS");
                if(*posxDann < 30)
                {
                    for(int i = 30; i < 60; i++)
                    {
                        for(int j = 0; j < 30; j++)
                        {
                            gotoxy(j,i - 29);
                            printf("%c", m[i][j]);
                        }
                        gotoxy(90, i);
                        printf("\n");
                    }
                }
                else if(*posxDann >= 30 && *posxDann < 60)
                {
                    for(int i = 30; i < 60; i++)
                    {
                        for(int j = 30; j < 60; j++)
                        {
                            gotoxy(j - 29,i - 29);
                            printf("%c", m[i][j]);
                        }
                        gotoxy(90, i);
                        printf("\n");
                    }
                }
                else if(*posxDann >= 60 && *posxDann < 89)
                {
                    for(int i = 30; i < 60; i++)
                    {
                        for(int j = 60; j < 90; j++)
                        {
                            gotoxy(j - 59,i - 29);
                            printf("%c", m[i][j]);
                        }
                        gotoxy(90, i);
                        printf("\n");
                    }
                }
            }
        }
        if(m[*posyDann + 1][*posxDann] == 'V')
        {
            gotoxy(0,39);
            printf("Você pegou Óleo!!");

            (*qtdOleo)++;
            (*totalfls) += 10;

            for(int i = -1; i <= 1; i++)
            {
                for(int j = -3; j <= 3; j++)
                {
                    if(m[*posyDann + 1 + i][*posxDann + j] == 'V')
                    {
                        m[*posyDann + 1 + i][*posxDann + j] = 'v';
                        mudaEstrutura++;
                    }
                }
            }
        }
        else if(m[*posyDann + 1][*posxDann] == 'W')
        {
            gotoxy(0,39);
            printf("Você pegou Frutas!!");

            (*qtdBerries)++;
            (*totalfls) += 5;
            m[*posyDann + 1][*posxDann] = 'w';
            mudaEstrutura++;
        }
        else if(m[*posyDann + 1][*posxDann] == 'B')
        {
            escolheDrop = rand()%2;

            if(escolheDrop == 0)
            {
                gotoxy(0,39);
                printf("Você pegou Óleo!!");

                (*qtdOleo)++;
            }
            else
            {
                gotoxy(0,39);
                printf("Você pegou Comida Enlatada!!");

                (*qtdEnlatada)++;
            }
            (*totalfls) += 15;
            for(int i = -1; i <= 1; i++)
            {
                for(int j = -2; j <= 2; j++)
                {
                    if(m[*posyDann + 1 + i][*posxDann + j] == 'B')
                    {
                        m[*posyDann + 1 + i][*posxDann + j] = 'b';
                        mudaEstrutura++;
                    }
                }
            }
        }
        else if(m[*posyDann + 1][*posxDann] == '-')
        {
            gotoxy(0,39);
            printf("Você encontrou Água!!");

            (*sede) += 10;
            (*totalfls) += 5;
            if(*sede > 100)
            {
                *sede = 100;
            }
        }
        if(mudaEstrutura != 0)
        {
            *inicio = 0;
            mudaEstrutura = 0;
        }
    }
    else if(mov == 'd')
    {
        if(m[*posyDann][*posxDann + 1] == ' ' || m[*posyDann][*posxDann + 1] == '+' || m[*posyDann][*posxDann + 1] == 'O')
        {
            m[*posyDann][*posxDann] = *blocoAnt;
            if(*posxDann >= 30 && *posxDann < 60)
            {
                posxDann2 = *posxDann - 29;
            }
            else if(*posxDann >= 60 && *posxDann < 90)
            {
                posxDann2 = *posxDann - 59;
            }
            else
            {
                posxDann2 = *posxDann;
            }

            if(*posyDann >= 30 && *posyDann < 60)
            {
                posyDann2 = *posyDann - 29;
            }
            else if(*posyDann >= 60 && *posyDann < 90)
            {
                posyDann2 = *posyDann - 59;
            }
            else
            {
                posyDann2 = *posyDann;
            }
            gotoxy(posxDann2, posyDann2);
            printf("%c", m[*posyDann][*posxDann]);
            *blocoAnt = m[*posyDann][*posxDann + 1];
            (*posxDann)++;

            if(*posxDann == 30)
            {
                system("CLS");
                if(*posyDann < 30)
                {
                    for(int i = 0; i < 30; i++)
                    {
                        for(int j = 30; j < 60; j++)
                        {
                            gotoxy(j - 29, i);
                            printf("%c", m[i][j]);
                        }
                        printf("\n");
                    }
                }
                else if(*posyDann >= 30 && *posyDann < 60)
                {
                    for(int i = 30; i < 60; i++)
                    {
                        for(int j = 30; j < 60; j++)
                        {
                            gotoxy(j - 29, i - 29);
                            printf("%c", m[i][j]);
                        }
                        printf("\n");
                    }
                }
                else if(*posyDann >= 60 && *posyDann < 90)
                {
                    for(int i = 60; i < 90; i++)
                    {
                        for(int j = 30; j < 60; j++)
                        {
                            gotoxy(j - 29, i - 59);
                            printf("%c", m[i][j]);
                        }
                        printf("\n");
                    }
                }
            }
            else if(*posxDann == 60)
            {
                system("CLS");
                if(*posyDann < 30)
                {
                    for(int i = 0; i < 30; i++)
                    {
                        for(int j = 60; j < 90; j++)
                        {
                            gotoxy(j - 59, i);
                            printf("%c", m[i][j]);
                        }
                        printf("\n");
                    }
                }
                else if(*posyDann >= 30 && *posyDann < 60)
                {
                    for(int i = 30; i < 60; i++)
                    {
                        for(int j = 60; j < 90; j++)
                        {
                            gotoxy(j - 59, i - 29);
                            printf("%c", m[i][j]);
                        }
                        printf("\n");
                    }
                }
                else if(*posyDann >= 60 && *posyDann < 90)
                {
                    for(int i = 60; i < 90; i++)
                    {
                        for(int j = 60; j < 90; j++)
                        {
                            gotoxy(j - 59, i - 59);
                            printf("%c", m[i][j]);
                        }
                        printf("\n");
                    }
                }
            }
        }
        if(m[*posyDann][*posxDann + 1] == 'V')
        {
            gotoxy(0,39);
            printf("Você pegou Óleo!!");

            (*qtdOleo)++;
            (*totalfls) += 10;

            for(int i = -1; i <= 1; i++)
            {
                for(int j = -3; j <= 3; j++)
                {
                    if(m[*posyDann + i][*posxDann + 1 + j] == 'V')
                    {
                        m[*posyDann + i][*posxDann + 1 + j] = 'v';
                        mudaEstrutura++;
                    }
                }
            }
        }
        else if(m[*posyDann][*posxDann + 1] == 'W')
        {
            gotoxy(0,39);
            printf("Você pegou Frutas!!");

            (*qtdBerries)++;
            (*totalfls) += 5;
            m[*posyDann][*posxDann + 1] = 'w';
            mudaEstrutura++;
        }
        else if(m[*posyDann][*posxDann + 1] == 'B')
        {
            escolheDrop = rand()%2;

            if(escolheDrop == 0)
            {
                gotoxy(0,39);
                printf("Você pegou Óleo!!");

                (*qtdOleo)++;
            }
            else
            {
                gotoxy(0,39);
                printf("Você pegou Comida Enlatada!!");

                (*qtdEnlatada)++;
            }
            (*totalfls) += 15;
            for(int i = -1; i <= 1; i++)
            {
                for(int j = -2; j <= 2; j++)
                {
                    if(m[*posyDann + i][*posxDann + 1 + j] == 'B')
                    {
                        m[*posyDann + i][*posxDann + 1 + j] = 'b';
                        mudaEstrutura++;
                    }
                }
            }
        }
        else if(m[*posyDann][*posxDann + 1] == '-')
        {
            gotoxy(0,39);
            printf("Você encontrou Água!!");

            (*sede) += 10;
            (*totalfls) += 5;
            if(*sede > 100)
            {
                *sede = 100;
            }
        }
        if(mudaEstrutura != 0)
        {
            *inicio = 0;
            mudaEstrutura = 0;
        }
    }

    if(mov != '\0')
    {
        if(*posxDann >= 30 && *posxDann < 60)
        {
            posxDann2 = *posxDann - 29;
        }
        else if(*posxDann >= 60 && *posxDann < 90)
        {
            posxDann2 = *posxDann - 59;
        }
        else
        {
            posxDann2 = *posxDann;
        }

        if(*posyDann >= 30 && *posyDann < 60)
        {
            posyDann2 = *posyDann - 29;
        }
        else if(*posyDann >= 60 && *posyDann < 90)
        {
            posyDann2 = *posyDann - 59;
        }
        else
        {
            posyDann2 = *posyDann;
        }

        m[*posyDann][*posxDann] = 'D';
        gotoxy(posxDann2, posyDann2);
        printf("%c", m[*posyDann][*posxDann]);
    }

    if(*blocoAnt == 'O')
    {
        arq = fopen("capturados.rbcr", "rb");
        if(arq == NULL)
        {
            (*gameover)++;
        }
        else
        {
            fclose(arq);
            Batalha(m, *posxDann, *posyDann, gameover, qtdOleo);
            *blocoAnt = ' ';
            *inicio = 0;
            system("CLS");
        }
    }

    gotoxy(0,31);
    printf("Utilize WASD para se mover\n");
}

void geraLataVelha(char **m)
{
    srand(time(NULL));
    int escolhe;
    int contador = 1;
    int i0 = 0, i1 = 0, i2 = 0, i3 = 0, i4 = 0, i5 = 0, i6 = 0, i7 = 0, i8 = 0;
    int x, y;
    int saidofor = 0;
    int contador2;

    while(contador <= 6)
    {
        contador2 = contador;
        escolhe = rand()%9;
        if(escolhe == 0 && i0 < 1)
        {
            x = rand()%22 + 1;
            y = rand()%25 + 1;
            i0++;
            contador++;
        }
        else if(escolhe == 1 && i1 < 1)
        {
            x = rand()%23 + 30;
            y = rand()%25 + 1;
            i1++;
            contador++;
        }
        else if(escolhe == 2 && i2 < 1)
        {
            x = rand()%22 + 60;
            y = rand()%25 + 1;
            i2++;
            contador++;
        }
        else if(escolhe == 3 && i3 < 1)
        {
            x = rand()%22 + 1;
            y = rand()%26 + 30;
            i3++;
            contador++;
        }
        else if(escolhe == 4 && i4 < 1)
        {
            x = rand()%23 + 30;
            y = rand()%26 + 30;
            i4++;
            contador++;
        }
        else if(escolhe == 5 && i5 < 1)
        {
            x = rand()%22 + 60;
            y = rand()%26 + 30;
            i5++;
            contador++;
        }
        else if(escolhe == 6 && i6 < 1)
        {
            x = rand()%22 + 1;
            y = rand()%25 + 60;
            i6++;
            contador++;
        }
        else if(escolhe == 7 && i7 < 1)
        {
            x = rand()%23 + 30;
            y = rand()%25 + 60;
            i7++;
            contador++;
        }
        else if(escolhe == 8 && i8 < 1)
        {
            x = rand()%22 + 60;
            y = rand()%25 + 60;
            i8++;
            contador++;
        }
        if(contador != contador2)
        {
            for(int i = 0; i < 4; i++)
            {
                for(int j = 0; j < 8; j++)
                {
                    if(m[y + i][x + j] != ' ')
                    {
                        contador--;
                        saidofor++;
                        if(escolhe == 0)
                            i0--;
                        else if(escolhe == 1)
                            i1--;
                        else if(escolhe == 2)
                            i2--;
                        else if(escolhe == 3)
                            i3--;
                        else if(escolhe == 4)
                            i4--;
                        else if(escolhe == 5)
                            i5--;
                        else if(escolhe == 6)
                            i6--;
                        else if(escolhe == 7)
                            i7--;
                        else if(escolhe == 8)
                            i8--;
                        break;
                    }
                }
                if(saidofor == 1)
                    break;
            }
            if(saidofor == 0)
            {
                for(int i = 0; i < 4; i++)
                {
                    for(int j = 0; j < 8; j++)
                    {
                        m[y + i][x + j] = '+';
                    }
                }
            }
        }
        saidofor = 0;
    }
}

void geraVeiculo(char **m)
{
    srand(time(NULL));
    int escolhe;
    int contador = 0;
    int i0 = 0, i1 = 0, i2 = 0, i3 = 0, i4 = 0, i5 = 0, i6 = 0, i7 = 0, i8 = 0;
    int x[8], y[8];
    int saidofor = 0;
    int contador2;

    while(contador <= 7)
    {
        contador2 = contador;
        escolhe = rand()%9;
        if(escolhe == 0 && i0 < 2)
        {
            x[contador2] = rand()%26 + 1;
            y[contador2] = rand()%27 + 1;
            i0++;
            contador++;
        }
        else if(escolhe == 1 && i1 < 2)
        {
            x[contador2] = rand()%27 + 30;
            y[contador2] = rand()%27 + 1;
            i1++;
            contador++;
        }
        else if(escolhe == 2 && i2 < 2)
        {
            x[contador2] = rand()%26 + 60;
            y[contador2] = rand()%27 + 1;
            i2++;
            contador++;
        }
        else if(escolhe == 3 && i3 < 2)
        {
            x[contador2] = rand()%26 + 1;
            y[contador2] = rand()%28 + 30;
            i3++;
            contador++;
        }
        else if(escolhe == 4 && i4 < 2)
        {
            x[contador2] = rand()%27 + 30;
            y[contador2] = rand()%28 + 30;
            i4++;
            contador++;
        }
        else if(escolhe == 5 && i5 < 2)
        {
            x[contador2] = rand()%26 + 60;
            y[contador2] = rand()%28 + 30;
            i5++;
            contador++;
        }
        else if(escolhe == 6 && i6 < 2)
        {
            x[contador2] = rand()%26 + 1;
            y[contador2] = rand()%27 + 60;
            i6++;
            contador++;
        }
        else if(escolhe == 7 && i7 < 2)
        {
            x[contador2] = rand()%27 + 30;
            y[contador2] = rand()%27 + 60;
            i7++;
            contador++;
        }
        else if(escolhe == 8 && i8 < 2)
        {
            x[contador2] = rand()%26 + 60;
            y[contador2] = rand()%27 + 60;
            i8++;
            contador++;
        }

        if(contador != contador2)
        {
            for(int i = 0; i < 2; i++)
            {
                for(int j = 0; j < 4; j++)
                {
                    if(m[y[contador2] + i][x[contador2] + j] != ' ')
                    {
                        contador--;
                        saidofor++;
                        if(escolhe == 0)
                            i0--;
                        else if(escolhe == 1)
                            i1--;
                        else if(escolhe == 2)
                            i2--;
                        else if(escolhe == 3)
                            i3--;
                        else if(escolhe == 4)
                            i4--;
                        else if(escolhe == 5)
                            i5--;
                        else if(escolhe == 6)
                            i6--;
                        else if(escolhe == 7)
                            i7--;
                        else if(escolhe == 8)
                            i8--;
                        break;
                    }
                }
                if(saidofor == 1)
                    break;
            }
            if(saidofor == 0)
            {
                for(int i = 0; i < 2; i++)
                {
                    for(int j = 0; j < 4; j++)
                    {
                        m[y[contador2] + i][x[contador2] + j] = 'V';
                    }
                }
            }
        }
        saidofor = 0;
    }
}
void geraArbusto(char **m)
{
    srand(time(NULL));
    int escolhe;
    int contador = 1;
    int i0 = 0, i1 = 0, i2 = 0, i3 = 0, i4 = 0, i5 = 0, i6 = 0, i7 = 0, i8 = 0;
    int x, y;
    int saidofor = 0;
    int contador2;

    while(contador <= 15)
    {
        contador2 = contador;
        escolhe = rand()%9;
        if(escolhe == 0 && i0 < 3)
        {
            x = rand()%29 + 1;
            y = rand()%29 + 1;
            i0++;
            contador++;
        }
        else if(escolhe == 1 && i1 < 3)
        {
            x = rand()%30 + 30;
            y = rand()%29 + 1;
            i1++;
            contador++;
        }
        else if(escolhe == 2 && i2 < 3)
        {
            x = rand()%29 + 60;
            y = rand()%29 + 1;
            i2++;
            contador++;
        }
        else if(escolhe == 3 && i3 < 3)
        {
            x = rand()%29 + 1;
            y = rand()%30 + 30;
            i3++;
            contador++;
        }
        else if(escolhe == 4 && i4 < 3)
        {
            x = rand()%30 + 30;
            y = rand()%30 + 30;
            i4++;
            contador++;
        }
        else if(escolhe == 5 && i5 < 3)
        {
            x = rand()%29 + 60;
            y = rand()%30 + 30;
            i5++;
            contador++;
        }
        else if(escolhe == 6 && i6 < 3)
        {
            x = rand()%29 + 1;
            y = rand()%29 + 60;
            i6++;
            contador++;
        }
        else if(escolhe == 7 && i7 < 3)
        {
            x = rand()%30 + 30;
            y = rand()%29 + 60;
            i7++;
            contador++;
        }
        else if(escolhe == 8 && i8 < 3)
        {
            x = rand()%29 + 60;
            y = rand()%29 + 60;
            i8++;
            contador++;
        }

        if(contador != contador2)
        {
            for(int i = 0; i < 1; i++)
            {
                for(int j = 0; j < 1; j++)
                {
                    if(m[y + i][x + j] != ' ')
                    {
                        contador--;
                        saidofor++;
                        if(escolhe == 0)
                            i0--;
                        else if(escolhe == 1)
                            i1--;
                        else if(escolhe == 2)
                            i2--;
                        else if(escolhe == 3)
                            i3--;
                        else if(escolhe == 4)
                            i4--;
                        else if(escolhe == 5)
                            i5--;
                        else if(escolhe == 6)
                            i6--;
                        else if(escolhe == 7)
                            i7--;
                        else if(escolhe == 8)
                            i8--;
                        break;
                    }
                }
                if(saidofor == 1)
                    break;
            }
            if(saidofor == 0)
            {
                for(int i = 0; i < 1; i++)
                {
                    for(int j = 0; j < 1; j++)
                    {
                        m[y + i][x + j] = 'W';
                    }
                }
            }
        }
        saidofor = 0;
    }
}
void geraBase(char **m)
{
    srand(time(NULL));
    int escolhe;
    int contador = 1;
    int i0 = 0, i1 = 0, i2 = 0, i3 = 0, i4 = 0, i5 = 0, i6 = 0, i7 = 0, i8 = 0;
    int x, y;
    int saidofor = 0;
    int contador2;

    while(contador <= 2)
    {
        contador2 = contador;
        escolhe = rand()%9;
        if(escolhe == 0 && i0 < 1)
        {
            x = rand()%27 + 1;
            y = rand()%28 + 1;
            i0++;
            contador++;
        }
        else if(escolhe == 1 && i1 < 1)
        {
            x = rand()%28 + 30;
            y = rand()%28 + 1;
            i1++;
            contador++;
        }
        else if(escolhe == 2 && i2 < 1)
        {
            x = rand()%27 + 60;
            y = rand()%28 + 1;
            i2++;
            contador++;
        }
        else if(escolhe == 3 && i3 < 1)
        {
            x = rand()%27 + 1;
            y = rand()%29 + 30;
            i3++;
            contador++;
        }
        else if(escolhe == 4 && i4 < 1)
        {
            x = rand()%28 + 30;
            y = rand()%29 + 30;
            i4++;
            contador++;
        }
        else if(escolhe == 5 && i5 < 1)
        {
            x = rand()%27 + 60;
            y = rand()%29 + 30;
            i5++;
            contador++;
        }
        else if(escolhe == 6 && i6 < 1)
        {
            x = rand()%27 + 1;
            y = rand()%28 + 60;
            i6++;
            contador++;
        }
        else if(escolhe == 7 && i7 < 1)
        {
            x = rand()%28 + 30;
            y = rand()%28 + 60;
            i7++;
            contador++;
        }
        else if(escolhe == 8 && i8 < 1)
        {
            x = rand()%27 + 60;
            y = rand()%28 + 60;
            i8++;
            contador++;
        }

        if(contador != contador2)
        {
            for(int i = 0; i < 2; i++)
            {
                for(int j = 0; j < 3; j++)
                {
                    if(m[y + i][x + j] != ' ')
                    {
                        contador--;
                        saidofor++;
                        if(escolhe == 0)
                            i0--;
                        else if(escolhe == 1)
                            i1--;
                        else if(escolhe == 2)
                            i2--;
                        else if(escolhe == 3)
                            i3--;
                        else if(escolhe == 4)
                            i4--;
                        else if(escolhe == 5)
                            i5--;
                        else if(escolhe == 6)
                            i6--;
                        else if(escolhe == 7)
                            i7--;
                        else if(escolhe == 8)
                            i8--;
                        break;
                    }
                }
                if(saidofor == 1)
                    break;
            }
            if(saidofor == 0)
            {
                for(int i = 0; i < 2; i++)
                {
                    for(int j = 0; j < 3; j++)
                    {
                        m[y + i][x + j] = 'B';
                    }
                }
            }
        }
        saidofor = 0;
    }
}
void geraLago(char **m)
{
    srand(time(NULL));
    int escolhe;
    int contador = 1;
    int i0 = 0, i1 = 0, i2 = 0, i3 = 0, i4 = 0, i5 = 0, i6 = 0, i7 = 0, i8 = 0;
    int x, y;
    int contador2;

    while(contador <= 2)
    {
        contador2 = contador;
        escolhe = rand()%9;
        if(escolhe == 0 && i0 < 1)
        {
            x = rand()%18 + 1;
            y = rand()%20 + 1;
            i0++;
            contador++;
        }
        else if(escolhe == 1 && i1 < 1)
        {
            x = rand()%19 + 30;
            y = rand()%20 + 1;
            i1++;
            contador++;
        }
        else if(escolhe == 2 && i2 < 1)
        {
            x = rand()%18 + 60;
            y = rand()%20 + 1;
            i2++;
            contador++;
        }
        else if(escolhe == 3 && i3 < 1)
        {
            x = rand()%18 + 1;
            y = rand()%21 + 30;
            i3++;
            contador++;
        }
        else if(escolhe == 4 && i4 < 1)
        {
            x = rand()%19 + 30;
            y = rand()%21 + 30;
            i4++;
            contador++;
        }
        else if(escolhe == 5 && i5 < 1)
        {
            x = rand()%18 + 60;
            y = rand()%21 + 30;
            i5++;
            contador++;
        }
        else if(escolhe == 6 && i6 < 1)
        {
            x = rand()%18 + 1;
            y = rand()%20 + 60;
            i6++;
            contador++;
        }
        else if(escolhe == 7 && i7 < 1)
        {
            x = rand()%19 + 30;
            y = rand()%20 + 60;
            i7++;
            contador++;
        }
        else if(escolhe == 8 && i8 < 1)
        {
            x = rand()%18 + 60;
            y = rand()%20 + 60;
            i8++;
            contador++;
        }
        if(contador2 != contador)
        {
            for(int i = 0; i < 10; i++)
            {
                for(int j = 0; j < 12; j++)
                {
                    m[y + i][x + j] = '-';
                }
            }
        }
    }
}

void geraPosDann(char **m, int *posxDann, int *posyDann)
{
    srand(time(NULL));
    *posxDann = rand()%88 + 1;
    *posyDann = rand()%88 + 1;
    while(m[*posyDann][*posxDann] != ' ')
    {
        *posxDann = rand()%88 + 1;
        *posyDann = rand()%88 + 1;
    }
    m[*posyDann][*posxDann] = 'D';
}

char **geraMapa(int *posxDann, int *posyDann)
{
    char **m;
    m = (char**)malloc(limitey*sizeof(char*));
    for(int y = 0; y < limitey; y++)
    {
        m[y] = (char*)malloc(limitex*sizeof(char));
        for(int x = 0; x < limitex; x++)
        {
            if(y == 0 || y == limitey - 1 || x == 0 || x == limitex - 1)
            {
                m[y][x] = '#';
            }
            else
            {
                m[y][x] = ' ';
            }
        }
    }
    geraLago(m);
    geraLataVelha(m);
    geraVeiculo(m);
    geraBase(m);
    geraArbusto(m);
    geraPosDann(m, posxDann, posyDann);

    return m;
}
