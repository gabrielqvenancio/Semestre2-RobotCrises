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

void gotoxy(int x, int y)
{
    COORD coord;
    coord.X = x;
    coord.Y = y;
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);
}

int main()
{
    setlocale(LC_ALL, "portuguese");
    srand(time(NULL));
    FILE *save;
    save = fopen("save.rbcr", "rb");
    int saidomenu = 0;
    int chancerobo = 0;
    int inicio = 0;
    int contaResetaEstruturas = 0;
    struct timeval comeco;
    struct timeval fim;
    struct timeval comecoinf;
    struct timeval fiminf;
    double totalfls;
    int totalints;
    int comtotalints;
    int segundos;
    int microsegundos;
    int totalh;
    int comtotalh;
    int posxDann;
    int posyDann;
    double contaTempoNight = 0;
    double contaFSdb = 0;
    int contaFS = 0;
    int analisaContaFS = 1;
    double contaIdb = 0;
    int contaI = 0;
    int auxContaI = 0;
    int comecaNoite;
    char blocoAnt;
    char **mapa;
    int gameover = 0;
    int contaDia = 0;
    int comcontaDia;
    char mov;
    int fome;
    int sede;
    int infeccao;
    int qtdBerries;
    int qtdEnlatada;
    int qtdOleo;
    int sairdojogo = 0;

    if(save != NULL)
    {
        fread(&totalfls, sizeof(double), 1, save);
        fread(&totalh, sizeof(int), 1, save);
        fread(&posxDann, sizeof(int), 1, save);
        fread(&posyDann, sizeof(int), 1, save);
        fread(&comecaNoite, sizeof(int), 1, save);
        fread(&blocoAnt, sizeof(char), 1, save);
        fread(&contaDia, sizeof(int), 1, save);
        fread(&fome, sizeof(int), 1, save);
        fread(&sede, sizeof(int), 1, save);
        fread(&infeccao, sizeof(int), 1, save);
        fread(&qtdBerries, sizeof(int), 1, save);
        fread(&qtdEnlatada, sizeof(int), 1, save);
        fread(&qtdOleo, sizeof(int), 1, save);
        fclose(save);
    }
    else
    {
        totalfls = 0;
        totalh = 12;
        comecaNoite = 0;
        blocoAnt = ' ';
        fome = 100;
        sede = 100;
        infeccao = 100;
        qtdBerries = 0;
        qtdEnlatada = 0;
        qtdOleo = 0;
    }

    mapa = geraMapa(&posxDann, &posyDann);
    Menu(&saidomenu);
    if(saidomenu == 1)
    {
        return 0;
    }
    while(gameover == 0)
    {
        //tempo percorrido desde o ultimo caracter do stdin e Atualizacao de Tela
        if(totalints >= 60)
        {
            totalh = totalh + totalints/60;
            totalfls = totalfls - totalints;
            totalints = floor(totalfls);
        }

        if(totalh >= 24)
        {
            totalh = 0;
            contaDia++;
        }

        if(totalh >= 20 || totalh <= 5)
        {
            if(comecaNoite == 0)
            {
                geraNight(mapa, contaDia);
                comecaNoite = 1;
                if(inicio == 1)
                    inicio--;
            }
            if(contaTempoNight >= 5)
            {
                AtualizaRoboNight(mapa, posxDann, posyDann);
                contaTempoNight = 0;
            }
        }
        if(totalh == 6 && comecaNoite == 1)
        {
            comecaNoite = 0;
            TiraRobosNight(mapa, &inicio);
        }

        if(contaFS % 5 != 0)
        {
            analisaContaFS = 1;
        }
        if(contaFS != 0 && analisaContaFS == 1)
        {
            if(contaFS % 5 == 0)
            {
                fome--;
                analisaContaFS = 0;
            }
            if(contaFS % 10 == 0)
            {
                sede--;
                analisaContaFS = 0;
            }
        }

        gettimeofday(&comeco, NULL);
        if(totalh % 6 == 0 && contaResetaEstruturas == 0)
        {
            contaResetaEstruturas = 1;
            ResetaEstruturas(mapa);
        }
        if(totalh + 1 % 6 == 0 && contaResetaEstruturas == 1)
        {
            contaResetaEstruturas = 0;
        }
        atualizaTela(mov, mapa, &posxDann, &posyDann, &blocoAnt, &inicio, &gameover, &qtdBerries, &qtdEnlatada, &qtdOleo, &sede, &totalfls);

        LevelUp();

        if(mov == 'e')
        {
            Inventario(&inicio, &qtdBerries, &qtdEnlatada, &qtdOleo, &fome, &infeccao);
        }

        if(mov == 'l')
        {
            gotoxy(0,37);
            printf("Deseja mesmo sair?  1 - sim    2 - nao");

            while(1==1)
            {
                mov = getch();

                if(mov == '1')
                {
                    sairdojogo = 1;
                    break;
                }
                else if(mov == '2')
                {
                    break;
                }
            }
            gotoxy(0,37);
            printf("                                      ");
            if(sairdojogo == 1)
            {
                break;
            }
        }

        if(auxContaI == 1)
        {
            gettimeofday(&fiminf, NULL);
            auxContaI = 0;
            segundos = fiminf.tv_sec - comecoinf.tv_sec;
            microsegundos = fiminf.tv_usec - comecoinf.tv_usec;
            contaIdb = contaIdb + segundos + microsegundos * pow(10, -6);
            contaI = floor(contaIdb);

            if(contaI >= 2)
            {
                contaIdb = 0;
                infeccao--;
            }
        }
        if(blocoAnt == '+')
        {
            gettimeofday(&comecoinf, NULL);
            auxContaI = 1;
            if(mov != 'a' && mov != 's' && mov != 'a' && mov != 'd')
            {
                chancerobo = rand()%5;
                if(chancerobo == 0)
                {
                    achaRobo(&inicio);
                    infeccao -= 5;
                }
            }
        }
        mov = '\0';
        gotoxy(0, 32);
        printf("Horas: %d:%d ", totalh, totalints);
        gotoxy(0,34);
        printf("Fome: %i/100  ", fome);
        gotoxy(0,35);
        printf("Sede: %i/100  ", sede);
        gotoxy(0,36);
        printf("Infecção: %i/100  ", infeccao);

        if(kbhit())
            mov = getch();

        gettimeofday(&fim, NULL);

        segundos = fim.tv_sec - comeco.tv_sec;
        microsegundos = fim.tv_usec - comeco.tv_usec;
        totalfls = totalfls + segundos + (microsegundos * pow(10, -6));
        contaTempoNight = contaTempoNight + segundos + (microsegundos * pow(10, -6));
        contaFSdb = contaFSdb + segundos + (microsegundos * pow(10, -6));
        contaFS = floor(contaFSdb);
        totalints = floor(totalfls);

        if(fome == 0 || sede == 0 || infeccao == 0)
        {
            gameover++;
        }

        gotoxy(0,0);
    }
    if(gameover > 0)
    {
        free(mapa);
        system("CLS");
        GameOver(totalints, totalh, contaDia);
        save = fopen("highscore.rbcr", "r+b");
        if(save == NULL)
        {
            fclose(save);
            save = fopen("highscore.rbcr", "wb");
            fwrite(&totalints, sizeof(int), 1, save);
            fwrite(&totalh, sizeof(int), 1, save);
            fwrite(&contaDia, sizeof(int), 1, save);
            fclose(save);
        }
        else
        {
            rewind(save);
            fread(&comtotalints, sizeof(int), 1, save);
            fread(&comtotalh, sizeof(int), 1, save);
            fread(&comcontaDia, sizeof(int), 1, save);
            fclose(save);
            if(contaDia > comcontaDia)
            {
                save = fopen("highscore.rbcr", "wb");
                fwrite(&totalints, sizeof(int), 1, save);
                fwrite(&totalh, sizeof(int), 1, save);
                fwrite(&contaDia, sizeof(int), 1, save);
                fclose(save);
            }
            else if(contaDia == comcontaDia)
            {
                if(totalh > comtotalh)
                {
                    save = fopen("highscore.rbcr", "wb");
                    fwrite(&totalints, sizeof(int), 1, save);
                    fwrite(&totalh, sizeof(int), 1, save);
                    fwrite(&contaDia, sizeof(int), 1, save);
                    fclose(save);
                }
                else if(totalh == comtotalh)
                {
                    if(totalints > comtotalints)
                    {
                        save = fopen("highscore.rbcr", "wb");
                        fwrite(&totalints, sizeof(int), 1, save);
                        fwrite(&totalh, sizeof(int), 1, save);
                        fwrite(&contaDia, sizeof(int), 1, save);
                        fclose(save);
                    }
                }
            }
        }
        getch();
    }
    else if(sairdojogo == 1)
    {
        save = fopen("save.rbcr", "w+b");
        fwrite(&totalfls, sizeof(double), 1, save);
        fwrite(&totalh, sizeof(int), 1, save);
        fwrite(&posxDann, sizeof(int), 1, save);
        fwrite(&posyDann, sizeof(int), 1, save);
        fwrite(&comecaNoite, sizeof(int), 1, save);
        fwrite(&blocoAnt, sizeof(char), 1, save);
        fwrite(&contaDia, sizeof(int), 1, save);
        fwrite(&fome, sizeof(int), 1, save);
        fwrite(&sede, sizeof(int), 1, save);
        fwrite(&infeccao, sizeof(int), 1, save);
        fwrite(&qtdBerries, sizeof(int), 1, save);
        fwrite(&qtdEnlatada, sizeof(int), 1, save);
        fwrite(&qtdOleo, sizeof(int), 1, save);
        fclose(save);
        free(mapa);
    }
}
