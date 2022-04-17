#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <conio.h>
#include <time.h>
#include <windows.h>
#include <math.h>
#include <sys/time.h>
#include <locale.h>

void Menu(int *saidomenu)
{
    char opcao;
    while(1==1)
    {
        Print(0);
        opcao = getch();
        if(opcao == '1')
        {
            system("CLS");
            break;
        }
        else if(opcao == '2')
        {
            Tutorial();
        }
        else if(opcao == '3')
        {
            HighScore();
        }
        else if(opcao == '4')
        {
            *saidomenu = 1;
            break;
        }
    }
}

void GameOver(int totalints, int totalh, int contaDia)
{
    Print(2);
    gotoxy(35, 25);
    printf("Você chegou até o dia %i às %ih %imin", contaDia, totalh, totalints);

    remove("capturados.rbcr");
    remove("robosnight.rbcr");
    remove("save.rbcr");
}

void Tutorial()
{
    system("CLS");
    Print(3);
    getch();
    system("CLS");
}

void HighScore()
{
    int secHS;
    int hourHS;
    int dayHS;
    FILE *arq;
    system("CLS");
    arq = fopen("highscore.rbcr", "rb");
    if(arq == NULL)
    {
        secHS = 0;
        hourHS = 0;
        dayHS = 0;
    }
    else
    {
        fread(&secHS, sizeof(int), 1, arq);
        fread(&hourHS, sizeof(int), 1, arq);
        fread(&dayHS, sizeof(int), 1, arq);
        fclose(arq);
    }

    Print(1);
    gotoxy(40,15);
    printf("Highscore: %i dias, %i horas e %i minutos", dayHS, hourHS, secHS);
    getch();
    system("CLS");
}
