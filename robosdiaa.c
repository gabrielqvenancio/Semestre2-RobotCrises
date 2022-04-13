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

void Inventario(int *inicio, int *qtdBerries, int *qtdEnlatada, int *qtdOleo, int *fome, int *infeccao)
{
    system("CLS");
    FILE *arqRobo;
    robos roboMudaHP[6];
    robos robosSalvos;
    int contaRobos = 0;
    int analisafread;
    char acao;
    char selecionaRobo;

    arqRobo = fopen("capturados.rbcr", "r+b");
    if(arqRobo == NULL)
    {
        for(int i = 0; i < 62; i++)
        {
            for(int j = 0; j < 70; j++)
            {
                if(j < 35 && (i == 11 || i == 21 || i == 31 || i == 41 || i == 51 || i == 61) || j < 70 && (i == 0 || i == 11 || i == 21))
                {
                    gotoxy(j, i);
                    printf("#");
                }
                else if(j == 35 || (j == 69 && i <= 21) || j == 0)
                {
                    gotoxy(j, i);
                    printf("#");
                }
                else if(j == 3)
                {
                    if(i == 3)
                    {
                        gotoxy(3,3);
                        printf("Você ainda não têm robos...");
                    }
                }
            }
        }
    }
    else
    {
        for(int i = 0; i < 62; i++)
        {
            for(int j = 0; j < 70; j++)
            {
                analisafread = 0;
                if(j < 35 && (i == 11 || i == 21 || i == 31 || i == 41 || i == 51 || i == 61) || j < 70 && (i == 0 || i == 11 || i == 21))
                {
                    gotoxy(j, i);
                    printf("#");
                }
                else if(j == 35 || (j == 69 && i <= 21) || j == 0)
                {
                    gotoxy(j, i);
                    printf("#");
                }
                else if(j == 10)
                {
                    if(i == 3)
                    {
                        gotoxy(10,3);
                        printf("Robô 1");
                        rewind(arqRobo);
                        fread(&robosSalvos, sizeof(robos), 1, arqRobo);
                        gotoxy(2,5);
                        printf("%s", robosSalvos.nome);
                        gotoxy(10,6);
                        printf("HP: %i/%i\t", robosSalvos.HP, robosSalvos.HPMAX);
                        printf("LEVEL: %i", robosSalvos.LEVEL);
                        gotoxy(10,7);
                        printf("ATK: %i\t", robosSalvos.ATK);
                        printf("XP: %i", robosSalvos.XP);
                        gotoxy(10,8);
                        printf("DEF: %i", robosSalvos.DEF);
                        gotoxy(10,9);
                        printf("SPD: %i", robosSalvos.SPD);
                    }
                    else if(i == 14)
                    {
                        gotoxy(10, 14);
                        printf("Robô 2");
                        fseek(arqRobo, sizeof(robos)*1, SEEK_SET);
                        analisafread = fread(&robosSalvos, sizeof(robos), 1, arqRobo);

                        if(analisafread == 1)
                        {
                            gotoxy(2,16);
                            printf("%s", robosSalvos.nome);
                            gotoxy(10,17);
                            printf("HP: %i/%i\t", robosSalvos.HP, robosSalvos.HPMAX);
                            printf("LEVEL: %i", robosSalvos.LEVEL);
                            gotoxy(10,18);
                            printf("ATK: %i\t", robosSalvos.ATK);
                            printf("XP: %i", robosSalvos.XP);
                            gotoxy(10,19);
                            printf("DEF: %i", robosSalvos.DEF);
                            gotoxy(10,20);
                            printf("SPD: %i", robosSalvos.SPD);
                        }
                    }
                    else if(i == 24)
                    {
                        gotoxy(10, 24);
                        printf("Robô 3");
                        fseek(arqRobo, sizeof(robos)*2, SEEK_SET);
                        analisafread = fread(&robosSalvos, sizeof(robos), 1, arqRobo);

                        if(analisafread == 1)
                        {
                            gotoxy(2,26);
                            printf("%s", robosSalvos.nome);
                            gotoxy(10,27);
                            printf("HP: %i/%i\t", robosSalvos.HP, robosSalvos.HPMAX);
                            printf("LEVEL: %i", robosSalvos.LEVEL);
                            gotoxy(10,28);
                            printf("ATK: %i\t", robosSalvos.ATK);
                            printf("XP: %i", robosSalvos.XP);
                            gotoxy(10,29);
                            printf("DEF: %i", robosSalvos.DEF);
                            gotoxy(10,30);
                            printf("SPD: %i", robosSalvos.SPD);
                        }
                    }
                    else if(i == 34)
                    {
                        gotoxy(10, 34);
                        printf("Robô 4");
                        fseek(arqRobo, sizeof(robos)*3, SEEK_SET);
                        analisafread = fread(&robosSalvos, sizeof(robos), 1, arqRobo);

                        if(analisafread == 1)
                        {
                            gotoxy(2,36);
                            printf("%s", robosSalvos.nome);
                            gotoxy(10,37);
                            printf("HP: %i/%i\t", robosSalvos.HP, robosSalvos.HPMAX);
                            printf("LEVEL: %i", robosSalvos.LEVEL);
                            gotoxy(10,38);
                            printf("ATK: %i\t", robosSalvos.ATK);
                            printf("XP: %i", robosSalvos.XP);
                            gotoxy(10,39);
                            printf("DEF: %i", robosSalvos.DEF);
                            gotoxy(10,40);
                            printf("SPD: %i", robosSalvos.SPD);
                        }
                    }
                    else if(i == 44)
                    {
                        gotoxy(10, 44);
                        printf("Robô 5");
                        fseek(arqRobo, sizeof(robos)*4, SEEK_SET);
                        analisafread = fread(&robosSalvos, sizeof(robos), 1, arqRobo);

                        if(analisafread == 1)
                        {
                            gotoxy(2,46);
                            printf("%s", robosSalvos.nome);
                            gotoxy(10,47);
                            printf("HP: %i/%i\t", robosSalvos.HP, robosSalvos.HPMAX);
                            printf("LEVEL: %i", robosSalvos.LEVEL);
                            gotoxy(10,48);
                            printf("ATK: %i\t", robosSalvos.ATK);
                            printf("XP: %i", robosSalvos.XP);
                            gotoxy(10,49);
                            printf("DEF: %i", robosSalvos.DEF);
                            gotoxy(10,50);
                            printf("SPD: %i", robosSalvos.SPD);
                        }
                    }
                    else if(i == 54)
                    {
                        gotoxy(10, 54);
                        printf("Robô 6");
                        fseek(arqRobo, sizeof(robos)*5, SEEK_SET);
                        analisafread = fread(&robosSalvos, sizeof(robos), 1, arqRobo);

                        if(analisafread == 1)
                        {
                            gotoxy(2,56);
                            printf("%s", robosSalvos.nome);
                            gotoxy(10,57);
                            printf("HP: %i/%i\t", robosSalvos.HP, robosSalvos.HPMAX);
                            printf("LEVEL: %i", robosSalvos.LEVEL);
                            gotoxy(10,58);
                            printf("ATK: %i\t", robosSalvos.ATK);
                            printf("XP: %i", robosSalvos.XP);
                            gotoxy(10,59);
                            printf("DEF: %i", robosSalvos.DEF);
                            gotoxy(10,60);
                            printf("SPD: %i", robosSalvos.SPD);
                        }
                    }
                }
            }
        }
    }
    gotoxy(40,3);
    printf("COMIDAS");
    gotoxy(40,5);
    printf("1 - Frutas: %i  ", *qtdBerries);
    gotoxy(40,6);
    printf("2 - Comida Enlatada: %i  ", *qtdEnlatada);
    gotoxy(40, 14);
    printf("CURA");
    gotoxy(40, 16);
    printf("3 - Óleo: %i", *qtdOleo);

    while(1==1)
    {
        acao = getch();
        if(acao == '1')
        {
            if(*qtdBerries > 0)
            {
                (*qtdBerries)--;
                *fome += 5;
                if(*fome >= 100)
                    *fome = 100;
                gotoxy(40,5);
                printf("1 - Frutas: %i  ", *qtdBerries);
            }
            else
            {
                gotoxy(36,22);
                printf("Você não têm frutas!!                      ");
            }
        }
        else if(acao == '2')
        {
            if(*qtdEnlatada > 0)
            {
                (*qtdEnlatada)--;
                *fome += 10;
                *infeccao += 10;
                if(*fome >= 100)
                    *fome = 100;
                if(*infeccao >= 100)
                    *infeccao = 100;
                gotoxy(40,6);
                printf("2 - Comida Enlatada: %i  ", *qtdEnlatada);
            }
            else
            {
                gotoxy(36,22);
                printf("Voce não tem comida enlatada!!             ");
            }
        }
        else if(acao == '3')
        {
            if(*qtdOleo > 0)
            {
                gotoxy(36,22);
                printf("Selecione o número do robô que deseja curar");
                rewind(arqRobo);
                while(contaRobos <= 6)
                {
                    analisafread = fread(&roboMudaHP[contaRobos], sizeof(robos), 1, arqRobo);
                    if(analisafread != 1)
                    {
                        break;
                    }
                    contaRobos++;
                }
                while(1==1)
                {
                    gotoxy(36,23);
                    printf("Selecione o número do robô que deseja curar");
                    selecionaRobo = getch();
                    if(selecionaRobo == 1 || selecionaRobo == 2 || selecionaRobo == 3 || selecionaRobo == 4 || selecionaRobo == 5 || selecionaRobo == 6)
                    {
                        if(selecionaRobo > contaRobos)
                        {
                            gotoxy(36,22);
                            printf("Insira um valor válido!!                   ");
                        }
                        else
                        {
                            roboMudaHP[selecionaRobo].HP += 10;
                            if(roboMudaHP[contaRobos].HP > roboMudaHP[contaRobos].HPMAX)
                            {
                                roboMudaHP[contaRobos].HP = roboMudaHP[contaRobos].HPMAX;
                            }
                            fclose(arqRobo);
                            arqRobo = fopen("capturados.rbcr", "w+b");
                            for(int i = 0; i < contaRobos; i++)
                            {
                                fwrite(&roboMudaHP[i], sizeof(robos), 1, arqRobo);
                            }
                            gotoxy(36,23);
                            printf("                                           ");
                            gotoxy(40, 16);
                            printf("3 - Óleo: %i", *qtdOleo);
                            break;
                        }
                    }
                    else if(selecionaRobo == 'e')
                    {
                        gotoxy(36,23);
                        printf("                                           ");
                        break;
                    }
                    else
                    {
                        gotoxy(36,22);
                        printf("Insira um valor válido!!                   ");
                    }
                }
            }
            else
            {
                gotoxy(36,22);
                printf("Voce nao tem Óleo!!                        ");
            }
        }
        else if(acao == 'e')
        {
            break;
        }
        else
        {
            gotoxy(36,22);
            printf("Insira um valor válido!!");
        }
    }
    fclose(arqRobo);
    system("CLS");
    *inicio = 0;
}

robos *RoboAtribuicao(int escolheRobo)
{
    srand(time(NULL));
    robos *robo;
    robo = (robos*)malloc(sizeof(robos));

    if(escolheRobo == 0)
    {
        strcpy(robo->nome, "Tony, o Robô de Ferro");
        robo->HP = 15 + rand()%8 - 4;
        robo->HPMAX = robo->HP;
        robo->ATK = 16 + rand()%8 - 4;
        robo->DEF = 8 + rand()%8 - 4;
        robo->SPD = 15 + rand()%8 - 4;
        robo->XPyield = 50;
    }
    else if(escolheRobo == 1)
    {
        strcpy(robo->nome, "Titã, o Homem de Lata");
        robo->HP = 10 + rand()%8 - 4;
        robo->HPMAX = robo->HP;
        robo->ATK = 20 + rand()%8 - 4;
        robo->DEF = 10 + rand()%8 - 4;
        robo->SPD = 10 + rand()%8 - 4;
        robo->XPyield = 50;
    }
    else if(escolheRobo == 2)
    {
        strcpy(robo->nome, "C4PU, o Robô de Ouro");
        robo->HP = 35 + rand()%8 - 4;
        robo->HPMAX = robo->HP;
        robo->ATK = 6 + rand()%8 - 4;
        robo->DEF = 20 + rand()%8 - 4;
        robo->SPD = 5 + rand()%8 - 4;
        robo->XPyield = 75;
    }
    else if(escolheRobo == 3)
    {
        strcpy(robo->nome, "Portugol, o Robô de Prata");
        robo->HP = 12 + rand()%8 - 4;
        robo->HPMAX = robo->HP;
        robo->ATK = 15 + rand()%8 - 4;
        robo->DEF = 28 + rand()%8 - 4;
        robo->SPD = 10 + rand()%8 - 4;
        robo->XPyield = 50;
    }
    else if(escolheRobo == 4)
    {
        strcpy(robo->nome, "Newbie, o Robô de Cobre");
        robo->HP = 8 + rand()%8 - 4;
        robo->HPMAX = robo->HP;
        robo->ATK = 20 + rand()%8 - 4;
        robo->DEF = 8 + rand()%8 - 4;
        robo->SPD = 8 + rand()%8 - 4;
        robo->XPyield = 25;
    }
    else if(escolheRobo == 5)
    {
        strcpy(robo->nome, "Freddy, o Robô de Mercúrio");
        robo->HP = 18 + rand()%8 - 4;
        robo->HPMAX = robo->HP;
        robo->ATK = 30 + rand()%8 - 4;
        robo->DEF = 10 + rand()%8 - 4;
        robo->SPD = 18 + rand()%8 - 4;
        robo->XPyield = 100;
    }
    else if(escolheRobo == 6)
    {
        strcpy(robo->nome, "Bob, o Robô de Esponja");
        robo->HP = 15 + rand()%8 - 4;
        robo->HPMAX = robo->HP;
        robo->ATK = 15 + rand()%8 - 4;
        robo->DEF = 10 + rand()%8 - 4;
        robo->SPD = 5 + rand()%8 - 4;
        robo->XPyield = 50;
    }
    else if(escolheRobo == 7)
    {
        strcpy(robo->nome, "Juninho, o Robô Religioso");
        robo->HP = 10 + rand()%8 - 4;
        robo->HPMAX = robo->HP;
        robo->ATK = 35 + rand()%8 - 4;
        robo->DEF = 25 + rand()%8 - 4;
        robo->SPD = 20 + rand()%8 - 4;
        robo->XPyield = 100;
    }
    else if(escolheRobo == 8)
    {
        strcpy(robo->nome, "Kim, el Robo Libre");
        robo->HP = 10 + rand()%8 - 4;
        robo->HPMAX = robo->HP;
        robo->ATK = 40 + rand()%8 - 4;
        robo->DEF = 40 + rand()%8 - 4;
        robo->SPD = 3 + rand()%8 - 4;
        robo->XPyield = 100;
    }
    else if(escolheRobo == 9)
    {
        strcpy(robo->nome, "DVDProjetoAzul, o Robô Cibernético");
        robo->HP = 15 + rand()%8 - 4;
        robo->HPMAX = robo->HP;
        robo->ATK = 15 + rand()%8 - 4;
        robo->DEF = 15 + rand()%8 - 4;
        robo->SPD = 50 + rand()%8 - 4;
        robo->XPyield = 80;
    }
    else if(escolheRobo == 10)
    {
        strcpy(robo->nome, "Shaggy, o Robô Superior");
        robo->HP = 50 + rand()%8 - 4;
        robo->HPMAX = robo->HP;
        robo->ATK = 50 + rand()%8 - 4;
        robo->DEF = 50 + rand()%8 - 4;
        robo->SPD = 50 + rand()%8 - 4;
        robo->XPyield = 1000;
    }
    else if(escolheRobo == 11)
    {
        strcpy(robo->nome, "JinkleBerg, o Robô Quase Mágico");
        robo->HP = 35 + rand()%8 - 4;
        robo->HPMAX = robo->HP;
        robo->ATK = 5 + rand()%8 - 4;
        robo->DEF = 35 + rand()%8 - 4;
        robo->SPD = 15 + rand()%8 - 4;
        robo->XPyield = 100;
    }
    else if(escolheRobo == 12)
    {
        strcpy(robo->nome, "Poop, o Robosta");
        robo->HP = 5 + rand()%8 - 4;
        robo->HPMAX = robo->HP;
        robo->ATK = 5 + rand()%8 - 4;
        robo->DEF = 5 + rand()%8 - 4;
        robo->SPD = 5 + rand()%8 - 4;
        robo->XPyield = 1;
    }
    else if(escolheRobo == 13)
    {
        strcpy(robo->nome, "Mago, o Robô Implacável");
        robo->HP = 20 + rand()%8 - 4;
        robo->HPMAX = robo->HP;
        robo->ATK = 50 + rand()%8 - 4;
        robo->DEF = 40 + rand()%8 - 4;
        robo->SPD = 35 + rand()%8 - 4;
        robo->XPyield = 300;
    }
    else if(escolheRobo == 14)
    {
        strcpy(robo->nome, "El Pitiula, o Robô Piadista");
        robo->HP = 40 + rand()%8 - 4;
        robo->HPMAX = robo->HP;
        robo->ATK = 40 + rand()%8 - 4;
        robo->DEF = 40 + rand()%8 - 4;
        robo->SPD = 40 + rand()%8 - 4;
        robo->XPyield = 500;
    }
    else if(escolheRobo == 15)
    {
        strcpy(robo->nome, "Ibere, o Robô Faz Tudo");
        robo->HP = 30 + rand()%8 - 4;
        robo->HPMAX = robo->HP;
        robo->ATK = 30 + rand()%8 - 4;
        robo->DEF = 30 + rand()%8 - 4;
        robo->SPD = 30 + rand()%8 - 4;
        robo->XPyield = 200;
    }
    robo->XP = 0;
    robo->LEVEL = 1;
    return robo;
}

int Hack1(int *inicio)
{
    FILE *confereInventario;
    robos roboTeste1;
    robos roboTeste2;
    char hackResult = 0;
    int escolheCarac = '\0';
    struct timeval comeco;
    struct timeval fim;
    double totalfls = 0;
    int totalints = 0;
    int segundos;
    int microsegundos;
    int contador = 0;
    char inputteclado;
    char carac[30] = "abcdefghijklmnopqrstuvwxyz";
    int analisafread;


    for(int i = 0; i < 30; i++)
    {
        for(int j = 0; j < 30; j++)
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
            else if(j == 10 && i == 3)
            {
                gotoxy(10,3);
                printf("Aperte a tecla que aparecer na tela!!  ");
            }
            else if(j == 10 && i == 4)
            {
                gotoxy(10,4);
                printf("Tempo: 20");
            }
        }
    }

    Sleep(5000);
    escolheCarac = rand()%24;
    gotoxy(17,4);
    printf("  ");
    gotoxy(15, 15);
    printf("%c",carac[escolheCarac]);
    while(contador <= 10)
    {
        gotoxy(17,4);
        printf("%i ", 20 - totalints);

        gettimeofday(&comeco, NULL);

        if(kbhit())
            inputteclado = getch();

        if(inputteclado == carac[escolheCarac])
        {
            contador++;
            escolheCarac = rand()%24;
            gotoxy(15, 15);
            printf("%c",carac[escolheCarac]);
        }
        else if(inputteclado != carac[escolheCarac] && inputteclado != '\0')
        {
            totalfls += 3;
            escolheCarac = rand()%24;
            gotoxy(15, 15);
            printf("%c",carac[escolheCarac]);
        }

        inputteclado = '\0';

        gettimeofday(&fim, NULL);
        segundos = fim.tv_sec - comeco.tv_sec;
        microsegundos = fim.tv_usec - comeco.tv_usec + 100;
        totalfls = totalfls + segundos + microsegundos * pow(10, -6);
        totalints = totalfls;

        if(20 - totalints > 0)
        {
            if(contador == 10)
            {
                confereInventario = fopen("capturados.rbcr", "a+b");
                fseek(confereInventario, sizeof(robos)*5, SEEK_SET);
                analisafread = fread(&roboTeste1, sizeof(robos), 1, confereInventario);
                fclose(confereInventario);

                if(analisafread < 1)
                {
                    hackResult++;
                    gotoxy(20,15);
                    printf("Robô hackeado");
                    getch();
                    break;
                }
                else
                {
                    hackResult += 2;
                    break;
                }
            }
        }
        else
        {
            hackResult--;
            gotoxy(20,15);
            printf("Hackeamento falhou...");
            getch();
            break;
        }
        gotoxy(0,0);
    }
    *inicio = 0;
    return hackResult;
}

void achaRobo(int *inicio)
{
    srand(time(NULL));
    int hackResult;
    FILE *salvaRobo;
    char salvaSeta = '\0';
    char moverSeta;
    robos *robo;
    robos roboXP[6];
    int escolheHack;
    int escolheRobo;
    int verRoboXP;
    int k = 0;

    escolheRobo = rand()%16;
    escolheHack = rand()%3;
    robo = RoboAtribuicao(escolheRobo);

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
            else if(j == 10 && i == 3)
            {
                gotoxy(15,3);
                printf("%s", robo->nome);
            }
            else if(j == 9 && i == 27)
            {
                gotoxy(9,27);
                printf("->Hackear");
            }
            else if(j == 35 && i == 27)
            {
                gotoxy(35, 27);
                printf("Fugir");
            }
        }
    }
    while(1==1)
    {
        moverSeta = getch();
        if(moverSeta == 'd')
        {
            gotoxy(33,27);
            printf("->");
            gotoxy(9,27);
            printf("  ");
            salvaSeta = moverSeta;
        }
        else if(moverSeta == 'a')
        {
            gotoxy(9,27);
            printf("->");
            gotoxy(33,27);
            printf("  ");
            salvaSeta = moverSeta;
        }
        else if(moverSeta == 'e' && (salvaSeta == 'a' || salvaSeta == '\0'))
        {
            for(int i = 1; i < 50; i++)
            {
                gotoxy(i, 27);
                printf(" ");
            }
            hackResult = Hack1(inicio);
            if(hackResult == 1)
            {
                salvaRobo = fopen("capturados.rbcr", "a+b");
                fwrite(robo, sizeof(robos), 1, salvaRobo);
                fclose(salvaRobo);
            }
            else if(hackResult == 2)
            {
                salvaRobo = fopen("capturados.rbcr", "rb");
                while(verRoboXP != 0)
                {
                    verRoboXP = fread(&roboXP[k], sizeof(robos), 1, salvaRobo);
                    if(verRoboXP == 1)
                    {
                        roboXP[k].XP = roboXP[k].XP + robo->XPyield;
                        k++;
                    }
                    if(k == 6)
                    {
                        fclose(salvaRobo);
                        salvaRobo = fopen("capturados.rbcr", "wb");
                        for(int i = 0; i < k; i++)
                        {
                            fwrite(&roboXP[i], sizeof(robos), 1, salvaRobo);
                        }
                        fclose(salvaRobo);
                    }
                }

                gotoxy(20,15);
                printf("Cada robô ganha %i XP", robo->XPyield);
                getch();
                fclose(salvaRobo);
            }
            break;
        }
        else if(moverSeta == 'e' && salvaSeta == 'd')
        {
            *inicio = 0;
            break;
        }
    }
    system("CLS");
    free(robo);
}

void LevelUp()
{
    FILE *arq;
    robos roboLevelUp[6];
    int verificaEOF;
    int guardai = 6;

    arq = fopen("capturados.rbcr", "rb");
    if(arq != NULL)
    {
        for(int i = 0; i < 6; i++)
        {
            verificaEOF = fread(&roboLevelUp[i], sizeof(robos), 1, arq);
            if(verificaEOF == 0)
            {
                guardai = i - 1;
                break;
            }
            if(roboLevelUp[i].XP >= 1000)
            {
                roboLevelUp[i].LEVEL += 1;
                roboLevelUp[i].XP = roboLevelUp[i].XP % 1000;
                roboLevelUp[i].HP += 3 + roboLevelUp[i].LEVEL;
                roboLevelUp[i].HPMAX += 3 + roboLevelUp[i].LEVEL;
                roboLevelUp[i].ATK += 3 + roboLevelUp[i].LEVEL;
                roboLevelUp[i].DEF += 3 + roboLevelUp[i].LEVEL;
                roboLevelUp[i].SPD += 3 + roboLevelUp[i].LEVEL;
            }
        }
    }

    fclose(arq);

    if(arq != NULL)
    {
        arq = fopen("capturados.rbcr", "wb");
        for(int i = 0; i <= guardai; i++)
        {
            fwrite(&roboLevelUp[i], sizeof(robos), 1, arq);
        }
        fclose(arq);
    }
}
