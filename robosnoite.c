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
    int XP;
    int XPyield;
    int LEVEL;
    char nome[35];
    int HP;
    int ATK;
    int DEF;
    int SPD;
    int HPMAX;
}robos;

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

void geraNight(char **m, int contaDia)
{
    srand(time(NULL));
    int escolheRoboNight;
    FILE *RNarq;
    robosNight vRobosNight[10];

    for(int i = 0; i < 10; i++)
    {
        escolheRoboNight = rand()%185;

        if(escolheRoboNight < 30)
        {
            strcpy(vRobosNight[i].nome, "O Soldado de Lata");
            vRobosNight[i].HP = 3 + contaDia*rand()%4;
            vRobosNight[i].ATK = 1 + contaDia*rand()%4;
            vRobosNight[i].DEF = 1 + contaDia*rand()%4;
            vRobosNight[i].SPD = 1 + contaDia*rand()%4;
            vRobosNight[i].XPyield = 20 + contaDia*rand()%10;
        }
        else if(escolheRoboNight >= 30 && escolheRoboNight < 60)
        {
            strcpy(vRobosNight[i].nome, "O Soldado de Bronze");
            vRobosNight[i].HP = 5 + contaDia*rand()%5;
            vRobosNight[i].ATK = 3 + contaDia*rand()%5;
            vRobosNight[i].DEF = 3 + contaDia*rand()%5;
            vRobosNight[i].SPD = 3 + contaDia*rand()%5;
            vRobosNight[i].XPyield = 30 + contaDia*rand()%15;
        }
        else if(escolheRoboNight >= 60 && escolheRoboNight < 90)
        {
            strcpy(vRobosNight[i].nome, "O Soldado de Prata");
            vRobosNight[i].HP = 8 + contaDia*rand()%6;
            vRobosNight[i].ATK = 5 + contaDia*rand()%6;
            vRobosNight[i].DEF = 5 + contaDia*rand()%6;
            vRobosNight[i].SPD = 5 + contaDia*rand()%6;
            vRobosNight[i].XPyield = 40 + contaDia*rand()%20;
        }
        else if(escolheRoboNight >= 90 && escolheRoboNight < 120)
        {
            strcpy(vRobosNight[i].nome, "O Soldado de Ouro");
            vRobosNight[i].HP = 10 + contaDia*rand()%7;
            vRobosNight[i].ATK = 7 + contaDia*rand()%7;
            vRobosNight[i].DEF = 7 + contaDia*rand()%7;
            vRobosNight[i].SPD = 7 + contaDia*rand()%7;
            vRobosNight[i].XPyield = 50 + contaDia*rand()%25;
        }
        else if(escolheRoboNight >= 120 && escolheRoboNight < 130)
        {
            strcpy(vRobosNight[i].nome, "Bibs, o Soldado Entregador");
            vRobosNight[i].HP = 1;
            vRobosNight[i].ATK = 1;
            vRobosNight[i].DEF = 1;
            vRobosNight[i].SPD = 1;
            vRobosNight[i].XPyield = 1;
        }

        else if(escolheRoboNight >= 130 && escolheRoboNight < 145)
        {
            strcpy(vRobosNight[i].nome, "O Capitão");
            vRobosNight[i].HP = 20 + contaDia*rand()%5;
            vRobosNight[i].ATK = 15 + contaDia*rand()%5;
            vRobosNight[i].DEF = 15 + contaDia*rand()%5;
            vRobosNight[i].SPD = 15 + contaDia*rand()%5;
            vRobosNight[i].XPyield = 200 + contaDia*rand()%50;
        }
        else if(escolheRoboNight >= 145 && escolheRoboNight < 165)
        {
            strcpy(vRobosNight[i].nome, "O Soldado Braia");
            vRobosNight[i].HP = 10 + contaDia*rand()%4;
            vRobosNight[i].ATK = 10 + contaDia*rand()%4;
            vRobosNight[i].DEF = 10 + contaDia*rand()%4;
            vRobosNight[i].SPD = 10 + contaDia*rand()%4;
            vRobosNight[i].XPyield = 100 + contaDia*rand()%10;
        }
        else if(escolheRoboNight >= 165 && escolheRoboNight < 175)
        {
            strcpy(vRobosNight[i].nome, "Sorta o Sordadin");
            vRobosNight[i].HP = 20 + contaDia*rand()%4;
            vRobosNight[i].ATK = 20 + contaDia*rand()%4;
            vRobosNight[i].DEF = 20 + contaDia*rand()%4;
            vRobosNight[i].SPD = 20 + contaDia*rand()%4;
            vRobosNight[i].XPyield = 80 + contaDia*rand()%10;
        }
        else if(escolheRoboNight >= 175 && escolheRoboNight < 180)
        {
            strcpy(vRobosNight[i].nome, "VV, o Soldado Developer");
            vRobosNight[i].HP = 1 + contaDia*rand()%50;
            vRobosNight[i].ATK = 1 + contaDia*rand()%50;
            vRobosNight[i].DEF = 1 + contaDia*rand()%50;
            vRobosNight[i].SPD = 1 + contaDia*rand()%50;
            vRobosNight[i].XPyield = 600 + contaDia*rand()%100;
        }
        else if(escolheRoboNight >= 180 && escolheRoboNight < 185)
        {
            strcpy(vRobosNight[i].nome, "O Soldado Ultimate");
            vRobosNight[i].HP = 30 + contaDia*rand()%15;
            vRobosNight[i].ATK = 20 + contaDia*rand()%15;
            vRobosNight[i].DEF = 20 + contaDia*rand()%15;
            vRobosNight[i].SPD = 20 + contaDia*rand()%15;
            vRobosNight[i].XPyield = 500 + contaDia*rand()%50;
        }
    }

    int posNight[20];
    RNarq = fopen("robosnight.rbcr", "w+b");

    for(int i = 0; i < 10; i++)
    {
        posNight[i] = rand()%88 + 1;
        posNight[i + 10] = rand()%88 + 1;
        while(m[posNight[i + 10]][posNight[i]] != ' ')
        {
            posNight[i] = rand()%88 + 1;
            posNight[i + 10] = rand()%88 + 1;
        }
        m[posNight[i + 10]][posNight[i]] = 'O';
        vRobosNight[i].posNightx = posNight[i];
        vRobosNight[i].posNighty = posNight[i + 10];

        fwrite(&vRobosNight[i], sizeof(robosNight), 1, RNarq);
    }
    fclose(RNarq);
}

void AtualizaRoboNight(char **m, int posxDann, int posyDann)
{
    srand(time(NULL));
    int geraDirecao[10];
    int contaGerador = 0;
    robosNight roboPosNight[10];
    FILE *arqPosNight;
    int *nightX, *nightY;

    arqPosNight = fopen("robosnight.rbcr", "rb");
    for(int i = 0; i < 10; i++)
    {
        fread(&roboPosNight[i], sizeof(robosNight), 1, arqPosNight);
    }
    fclose(arqPosNight);

    for(int i = 0; i < 89; i++)
    {
        for(int j = 0; j < 89; j++)
        {
            if(m[i][j] == 'O')
            {
                for(int k = 0; k < 10; k++)
                {
                    if(roboPosNight[k].posNightx == j && roboPosNight[k].posNighty == i)
                    {
                        nightX = &roboPosNight[k].posNightx;
                        nightY = &roboPosNight[k].posNighty;
                        break;
                    }
                }
                while(1==1)
                {
                    geraDirecao[contaGerador] = rand()%4;
                    if(geraDirecao[contaGerador] == 0)
                    {
                        if(m[*nightY - 1][*nightX] == ' ')
                        {
                            m[*nightY][*nightX] = ' ';
                            (*nightY)--;
                            m[*nightY][*nightX] = 't';
                            break;
                        }
                    }
                    else if(geraDirecao[contaGerador] == 1)
                    {
                        if(m[*nightY + 1][*nightX] == ' ')
                        {
                            m[*nightY][*nightX] = ' ';
                            (*nightY)++;
                            m[*nightY][*nightX] = 't';
                            break;
                        }
                    }
                    else if(geraDirecao[contaGerador] == 2)
                    {
                        if(m[*nightY][*nightX - 1] == ' ')
                        {
                            m[*nightY][*nightX] = ' ';
                            (*nightX)--;
                            m[*nightY][*nightX] = 't';
                            break;
                        }
                    }
                    else if(geraDirecao[contaGerador] == 3)
                    {
                        if(m[*nightY][*nightX + 1] == ' ')//aquiiiiiiiiiiiiiiiiiii
                        {
                            m[*nightY][*nightX] = ' ';
                            (*nightX)++;
                            m[*nightY][*nightX] = 't';
                            break;
                        }
                    }
                }
                contaGerador++;
            }
        }
    }

    contaGerador = 0;
    for(int i = 0; i < 89; i++)
    {
        for(int j = 0; j < 89; j++)
        {
            if(m[i][j] == 't')
            {
                m[i][j] = 'O';
                if(i < 30 && posyDann < 30)
                {
                    if(j < 30 && posxDann < 30)
                    {
                        gotoxy(j,i);
                        printf("O");
                        if(geraDirecao[contaGerador] == 0)
                        {
                            gotoxy(j,i + 1);
                            printf(" ");
                        }
                        else if(geraDirecao[contaGerador] == 1)
                        {
                            gotoxy(j,i - 1);
                            printf(" ");
                        }
                        else if(geraDirecao[contaGerador] == 2)
                        {
                            gotoxy(j + 1,i);
                            printf(" ");
                        }
                        else if(geraDirecao[contaGerador] == 3)
                        {
                            gotoxy(j - 1,i);
                            printf(" ");
                        }
                    }
                    else if(j >= 30 && j < 60 && posxDann >= 30 && posxDann < 60)
                    {
                        gotoxy(j - 29,i);
                        printf("O");
                        if(geraDirecao[contaGerador] == 0)
                        {
                            gotoxy(j - 29,i + 1);
                            printf(" ");
                        }
                        else if(geraDirecao[contaGerador] == 1)
                        {
                            gotoxy(j - 29,i - 1);
                            printf(" ");
                        }
                        else if(geraDirecao[contaGerador] == 2)
                        {
                            gotoxy(j - 28,i);
                            printf(" ");
                        }
                        else if(geraDirecao[contaGerador] == 3)
                        {
                            gotoxy(j - 30,i);
                            printf(" ");
                        }
                    }
                    else if(j >= 60 && j < 90 && posxDann >= 60 && posxDann < 90)
                    {
                        gotoxy(j - 59,i);
                        printf("O");
                        if(geraDirecao[contaGerador] == 0)
                        {
                            gotoxy(j - 59,i + 1);
                            printf(" ");
                        }
                        else if(geraDirecao[contaGerador] == 1)
                        {
                            gotoxy(j - 59,i - 1);
                            printf(" ");
                        }
                        else if(geraDirecao[contaGerador] == 2)
                        {
                            gotoxy(j - 58,i);
                            printf(" ");
                        }
                        else if(geraDirecao[contaGerador] == 3)
                        {
                            gotoxy(j - 60,i);
                            printf(" ");
                        }
                    }
                }
                else if(i >= 30 && i < 60 && posyDann >= 30 && posyDann < 60)
                {
                    if(j < 30 && posxDann < 30)
                    {
                        gotoxy(j,i - 29);
                        printf("O");
                        if(geraDirecao[contaGerador] == 0)
                        {
                            gotoxy(j,i - 28);
                            printf(" ");
                        }
                        else if(geraDirecao[contaGerador] == 1)
                        {
                            gotoxy(j,i - 30);
                            printf(" ");
                        }
                        else if(geraDirecao[contaGerador] == 2)
                        {
                            gotoxy(j + 1,i - 29);
                            printf(" ");
                        }
                        else if(geraDirecao[contaGerador] == 3)
                        {
                            gotoxy(j - 1,i - 29);
                            printf(" ");
                        }
                    }
                    else if(j >= 30 && j < 60 && posxDann >= 30 && posxDann < 60)
                    {
                        gotoxy(j - 29,i - 29);
                        printf("O");
                        if(geraDirecao[contaGerador] == 0)
                        {
                            gotoxy(j - 29,i - 28);
                            printf(" ");
                        }
                        else if(geraDirecao[contaGerador] == 1)
                        {
                            gotoxy(j - 29,i - 30);
                            printf(" ");
                        }
                        else if(geraDirecao[contaGerador] == 2)
                        {
                            gotoxy(j - 28,i - 29);
                            printf(" ");
                        }
                        else if(geraDirecao[contaGerador] == 3)
                        {
                            gotoxy(j - 30,i - 29);
                            printf(" ");
                        }
                    }
                    else if(j >= 60 && j < 90 && posxDann >= 60 && posxDann < 90)
                    {
                        gotoxy(j - 59,i - 29);
                        printf("O");
                        if(geraDirecao[contaGerador] == 0)
                        {
                            gotoxy(j - 59,i - 28);
                            printf(" ");
                        }
                        else if(geraDirecao[contaGerador] == 1)
                        {
                            gotoxy(j - 59,i - 30);
                            printf(" ");
                        }
                        else if(geraDirecao[contaGerador] == 2)
                        {
                            gotoxy(j - 58,i - 29);
                            printf(" ");
                        }
                        else if(geraDirecao[contaGerador] == 3)
                        {
                            gotoxy(j - 60,i - 29);
                            printf(" ");
                        }
                    }
                }
                else if(i >= 60 && i < 90 && posyDann >= 60 && posyDann < 90)
                {
                    if(j < 30 && posxDann < 30)
                    {
                        gotoxy(j,i - 59);
                        printf("O");
                        if(geraDirecao[contaGerador] == 0)
                        {
                            gotoxy(j,i - 58);
                            printf(" ");
                        }
                        else if(geraDirecao[contaGerador] == 1)
                        {
                            gotoxy(j,i - 60);
                            printf(" ");
                        }
                        else if(geraDirecao[contaGerador] == 2)
                        {
                            gotoxy(j + 1,i - 59);
                            printf(" ");
                        }
                        else if(geraDirecao[contaGerador] == 3)
                        {
                            gotoxy(j - 1,i - 59);
                            printf(" ");
                        }
                    }
                    else if(j >= 30 && j < 60 && posxDann >= 30 && posxDann < 60)
                    {
                        gotoxy(j - 29,i - 59);
                        printf("O");
                        if(geraDirecao[contaGerador] == 0)
                        {
                            gotoxy(j - 29,i - 58);
                            printf(" ");
                        }
                        else if(geraDirecao[contaGerador] == 1)
                        {
                            gotoxy(j - 29,i - 60);
                            printf(" ");
                        }
                        else if(geraDirecao[contaGerador] == 2)
                        {
                            gotoxy(j - 28,i - 59);
                            printf(" ");
                        }
                        else if(geraDirecao[contaGerador] == 3)
                        {
                            gotoxy(j - 30,i - 59);
                            printf(" ");
                        }
                    }
                    else if(j >= 60 && j < 90 && posxDann >= 60 && posxDann < 90)
                    {
                        gotoxy(j - 59,i - 59);
                        printf("O");
                        if(geraDirecao[contaGerador] == 0)
                        {
                            gotoxy(j - 59,i - 58);
                            printf(" ");
                        }
                        else if(geraDirecao[contaGerador] == 1)
                        {
                            gotoxy(j - 59,i - 60);
                            printf(" ");
                        }
                        else if(geraDirecao[contaGerador] == 2)
                        {
                            gotoxy(j - 58,i - 59);
                            printf(" ");
                        }
                        else if(geraDirecao[contaGerador] == 3)
                        {
                            gotoxy(j - 60,i - 59);
                            printf(" ");
                        }
                    }
                }
                contaGerador++;
            }
        }
    }
    arqPosNight = fopen("robosnight.rbcr", "wb");
    for(int i = 0; i < 10; i++)
    {
        fwrite(&roboPosNight[i], sizeof(robosNight), 1, arqPosNight);
    }
    fclose(arqPosNight);
}

void Batalha(char m, int posxDann, int posyDann, int *gameover, int *qtdOleo)
{
    int batalhaover = 0;
    FILE *arq;
    int dano;
    robosNight roboInimigo;
    robos roboAliado;
    robos salvaRobos[6];
    char moveSeta, salvaSeta = '\0';
    int mortes = 0;
    int verificaRead;
    int analisaRobosAliados = 1;
    int qtdRobosAliados = 0;
    robos roboCura[6];
    int contaRobos = 0;


    arq = fopen("robosnight.rbcr", "rb");
    fread(&roboInimigo, sizeof(robosNight), 1, arq);
    while(roboInimigo.posNightx != posxDann || roboInimigo.posNighty != posyDann)
    {
        fread(&roboInimigo, sizeof(robosNight), 1, arq);
    }
    fclose(arq);

    arq = fopen("capturados.rbcr", "rb");
    fread(&roboAliado, sizeof(robos), 1, arq);
    fclose(arq);

    system("CLS");
    for(int i = 0; i <= 30; i++)
    {
        for(int j = 0; j <= 50; j++)
        {
            if(i == 0)
            {
                gotoxy(j, 0);
                printf("#");
            }
            else if(i == 30)
            {
                gotoxy(j, 30);
                printf("#");
            }
            else if(j == 0)
            {
                gotoxy(0, i);
                printf("#");
            }
            else if(j == 50)
            {
                gotoxy(50, i);
                printf("#");
            }
        }
    }
    gotoxy(11,27);
    printf("->Atacar");

    gotoxy(39,27);
    printf("Curar");

    gotoxy(30,3);
    printf("%s", roboInimigo.nome);

    while(batalhaover == 0)
    {
        gotoxy(1, 25);
        printf("                                   ");

        gotoxy(1,25);
        printf("%s", roboAliado.nome);

        gotoxy(30,4);
        printf("  ");

        gotoxy(30,4);
        printf("%i  ", roboInimigo.HP);

        gotoxy(3,26);
        printf("     ");

        gotoxy(1,26);
        printf("HP: %i/%i  ", roboAliado.HP, roboAliado.HPMAX);

        moveSeta = getch();

        if(moveSeta == 'd')
        {
            gotoxy(37,27);
            printf("->");
            gotoxy(11,27);
            printf("  ");
            salvaSeta = moveSeta;
        }
        else if(moveSeta == 'a')
        {
            gotoxy(37,27);
            printf("  ");
            gotoxy(11,27);
            printf("->");
            salvaSeta = moveSeta;
        }

        if(moveSeta == 'e' && (salvaSeta == '\0' || salvaSeta == 'a'))
        {
            if(roboInimigo.SPD > roboAliado.SPD)
            {
                dano = 2*pow(3, (roboInimigo.ATK - roboAliado.DEF)/10);
                roboAliado.HP = roboAliado.HP - dano;
                if(roboAliado.HP <= 0)
                {
                    mortes++;
                    arq = fopen("capturados.rbcr", "rb");
                    fseek(arq, sizeof(robos)*mortes, SEEK_SET);
                    verificaRead = fread(&roboAliado, sizeof(robos), 1, arq);
                    fclose(arq);
                    if(verificaRead < 1)
                    {
                        (*gameover)++;
                        batalhaover++;
                    }
                }
                else
                {
                    dano = 2*pow(3, (roboAliado.ATK - roboInimigo.DEF)/10);
                    roboInimigo.HP = roboInimigo.HP - dano;
                    if(roboInimigo.HP <= 0)
                    {
                        batalhaover++;
                        arq = fopen("capturados.rbcr", "rb");
                        fseek(arq, sizeof(robos)*(mortes + 1), SEEK_SET);
                        while(1==1)
                        {
                            analisaRobosAliados = fread(&salvaRobos[qtdRobosAliados], sizeof(robos), 1, arq);
                            if(analisaRobosAliados == 1)
                            {
                                salvaRobos[qtdRobosAliados].XP += roboInimigo.XPyield;
                                qtdRobosAliados++;
                            }
                            else
                            {
                                break;
                            }
                        }
                        qtdRobosAliados--;
                        fclose(arq);
                        arq = fopen("capturados.rbcr", "wb");
                        roboAliado.XP += roboInimigo.XPyield;
                        fwrite(&roboAliado, sizeof(robos), 1, arq);
                        for(int i = 0; i <= qtdRobosAliados; i++)
                        {
                            fwrite(&salvaRobos[i], sizeof(robos), 1, arq);
                        }
                        fclose(arq);

                        gotoxy(30, 4);
                        printf("Seus robôs ganharam %i XP", roboInimigo.XPyield);
                    }
                }
            }
            else if(roboInimigo.SPD <= roboAliado.SPD)
            {
                dano = 2*pow(3, (roboAliado.ATK - roboInimigo.DEF)/10);
                roboInimigo.HP = roboInimigo.HP - dano;
                if(roboInimigo.HP <= 0)
                {
                    batalhaover++;
                    arq = fopen("capturados.rbcr", "rb");
                    fseek(arq, sizeof(robos)*(mortes + 1), SEEK_SET);
                    while(1==1)
                    {
                        analisaRobosAliados = fread(&salvaRobos[qtdRobosAliados], sizeof(robos), 1, arq);
                        if(analisaRobosAliados == 1)
                        {
                            salvaRobos[qtdRobosAliados].XP += roboInimigo.XPyield;
                            qtdRobosAliados++;
                        }
                        else
                        {
                            break;
                        }
                    }
                    qtdRobosAliados--;
                    fclose(arq);
                    arq = fopen("capturados.rbcr", "wb");
                    roboAliado.XP += roboInimigo.XPyield;
                    fwrite(&roboAliado, sizeof(robos), 1, arq);
                    for(int i = 0; i <= qtdRobosAliados; i++)
                    {
                        fwrite(&salvaRobos[i], sizeof(robos), 1, arq);
                    }
                    fclose(arq);

                    gotoxy(30, 4);
                    printf("Seus robôs ganharam %i XP", roboInimigo.XPyield);
                }
                else
                {
                    dano = 2*pow(3, (roboInimigo.ATK - roboAliado.DEF)/10);
                    roboAliado.HP = roboAliado.HP - dano;
                    if(roboAliado.HP <= 0)
                    {
                        mortes++;
                        arq = fopen("capturados.rbcr", "rb");
                        fseek(arq, sizeof(robos)*mortes, SEEK_SET);
                        verificaRead = fread(&roboAliado, sizeof(robos), 1, arq);
                        fclose(arq);
                        if(verificaRead < 1)
                        {
                            (*gameover)++;
                            batalhaover++;
                        }
                    }
                }
            }
        }
        else if(moveSeta == 'e' && salvaSeta == 'd')
        {
            if(*qtdOleo > 0)
            {
                arq = fopen("capturados.rbcr", "rb");
                while(contaRobos < 6)
                {
                    verificaRead = fread(&roboCura[contaRobos], sizeof(robos), 1, arq);
                    if(verificaRead != 1)
                    {
                        break;
                    }
                    contaRobos++;
                }
                fclose(arq);
                (*qtdOleo)--;
                roboCura[0].HP += 10;
                if(roboCura[0].HP > roboCura[0].HPMAX)
                {
                    roboCura[0].HP = roboCura[0].HPMAX;
                }
                arq = fopen("capturados.rbcr", "wb");
                for(int i = 0; i < contaRobos; i++)
                {
                    fwrite(&roboCura[i], sizeof(robos), 1, arq);
                }
                fclose(arq);
                gotoxy(1,26);
                printf("HP: %i", roboAliado.HP);
            }
            else
            {
                gotoxy(0, 30);
                printf("Você não tem Óleo");
            }
        }
    }
}

void TiraRobosNight(char **m, int *inicio)
{
    FILE *pegaRobo;
    robosNight tiraRobo[10];

    pegaRobo = fopen("robosnight.rbcr", "rb");
    for(int i = 0; i < 10; i++)
    {
        fread(&tiraRobo[i], sizeof(robosNight), 1, pegaRobo);
        m[tiraRobo[i].posNighty][tiraRobo[i].posNightx] = ' ';
    }
    *inicio = 0;
    fclose(pegaRobo);
    remove("robosnight.rbcr");
}
