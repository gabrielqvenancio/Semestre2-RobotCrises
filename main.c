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

void Menu(int *saidomenu)
{
    int totalints;
    int totalh;
    int contaDia;
    FILE *arq;
    char opcao;
    while(1==1)
    {
        for(int i = 0; i < 30; i++)
        {
            for(int j = 0; j < 106; j++)
            {
                if(i == 0)
                {
                    gotoxy(j, 0);
                    printf("#");
                    Sleep(5);
                }
                if(i == 29)
                {
                    gotoxy(j, 29);
                    printf("#");
                    Sleep(5);
                }
                if(j == 0)
                {
                    gotoxy(0, i);
                    printf("#");
                    Sleep(5);
                }
                if(j == 105)
                {
                    gotoxy(105, i);
                    printf("#");
                    Sleep(5);
                }
            }
        }
        gotoxy(2, 5);
        printf("@@@@@@@    @@@@@@   @@@@@@@    @@@@@@   @@@@@@@@@       @@@@@@  @@@@@@@   @  @@@@@@@  @@@@@@@  @@@@@@@");
        gotoxy(2, 6);
        printf("@      @  @      @  @      @  @      @      @          @        @      @  @  @        @        @      ");
        gotoxy(2, 7);
        printf("@      @  @      @  @      @  @      @      @          @        @      @  @  @        @        @      ");
        gotoxy(2, 8);
        printf("@@@@@@@   @      @  @@@@@@@   @      @      @          @        @@@@@@@   @  @@@@@@@  @@@@@@@  @@@@@@@");
        gotoxy(2, 9);
        printf("@   @@    @      @  @      @  @      @      @          @        @   @@    @        @  @              @");
        gotoxy(2, 10);
        printf("@    @@   @      @  @      @  @      @      @          @        @    @@   @        @  @              @");
        gotoxy(2, 11);
        printf("@     @@   @@@@@@   @@@@@@@    @@@@@@       @           @@@@@@  @     @@  @  @@@@@@@  @@@@@@@  @@@@@@@");

        gotoxy(45,18);
        printf("1 - Jogar");
        gotoxy(45,19);
        printf("2 - Tutorial");
        gotoxy(45,20);
        printf("3 - Highscore");
        gotoxy(45,21);
        printf("4 - Sair");

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
            system("CLS");
            arq = fopen("highscore.rbcr", "rb");
            if(arq == NULL)
            {
                totalints = 0;
                totalh = 0;
                contaDia = 0;
            }
            else
            {
                fread(&totalints, sizeof(int), 1, arq);
                fread(&totalh, sizeof(int), 1, arq);
                fread(&contaDia, sizeof(int), 1, arq);
                fclose(arq);
            }
            for(int i = 0; i < 30; i++)
            {
                for(int j = 0; j < 106; j++)
                {
                    if(i == 0)
                    {
                        gotoxy(j, 0);
                        printf("#");
                    }
                    if(i == 29)
                    {
                        gotoxy(j, 29);
                        printf("#");
                    }
                    if(j == 0)
                    {
                        gotoxy(0, i);
                        printf("#");
                    }
                    if(j == 105)
                    {
                        gotoxy(105, i);
                        printf("#");
                    }
                }
            }
            gotoxy(40,15);
            printf("Highscore: %i dias, %i horas e %i minutos", contaDia, totalh, totalints);
            getch();
            system("CLS");
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
    for(int i = 0; i < 30; i++)
    {
        for(int j = 0; j < 106; j++)
        {
            if(i == 0)
            {
                gotoxy(j, 0);
                printf("#");
                Sleep(5);
            }
            if(i == 29)
            {
                gotoxy(j, 29);
                printf("#");
                Sleep(5);
            }
            if(j == 0)
            {
                gotoxy(0, i);
                printf("#");
                Sleep(5);
            }
            if(j == 105)
            {
                gotoxy(105, i);
                printf("#");
                Sleep(5);
            }
        }
    }
    Sleep(500);
    gotoxy(36, 5);
    printf("@@@@@@@");
    gotoxy(36, 6);
    printf("@");
    gotoxy(36, 7);
    printf("@");
    gotoxy(36, 8);
    printf("@  @@@@");
    gotoxy(36, 9);
    printf("@  @  @");
    gotoxy(36, 10);
    printf("@     @");
    gotoxy(36, 11);
    printf("@@@@@@@");

    Sleep(500);
    gotoxy(45, 5);
    printf(" @@@@@ ");
    gotoxy(45, 6);
    printf("@     @");
    gotoxy(45, 7);
    printf("@     @");
    gotoxy(45, 8);
    printf("@@@@@@@");
    gotoxy(45, 9);
    printf("@     @");
    gotoxy(45, 10);
    printf("@     @");
    gotoxy(45, 11);
    printf("@     @");

    Sleep(500);
    gotoxy(54, 5);
    printf(" @@ @@ ");
    gotoxy(54, 6);
    printf("@ @ @ @");
    gotoxy(54, 7);
    printf("@ @ @ @");
    gotoxy(54, 8);
    printf("@  @  @");
    gotoxy(54, 9);
    printf("@     @");
    gotoxy(54, 10);
    printf("@     @");
    gotoxy(54, 11);
    printf("@     @");

    Sleep(500);
    gotoxy(63, 5);
    printf("@@@@@@@");
    gotoxy(63, 6);
    printf("@      ");
    gotoxy(63, 7);
    printf("@      ");
    gotoxy(63, 8);
    printf("@@@@@@@");
    gotoxy(63, 9);
    printf("@      ");
    gotoxy(63, 10);
    printf("@      ");
    gotoxy(63, 11);
    printf("@@@@@@@");

    Sleep(500);
    gotoxy(36, 13);
    printf(" @@@@@ ");
    gotoxy(36, 14);
    printf("@     @");
    gotoxy(36, 15);
    printf("@     @");
    gotoxy(36, 16);
    printf("@     @");
    gotoxy(36, 17);
    printf("@     @");
    gotoxy(36, 18);
    printf("@     @");
    gotoxy(36, 19);
    printf(" @@@@@ ");

    Sleep(500);
    gotoxy(45, 13);
    printf("@     @");
    gotoxy(45, 14);
    printf("@     @");
    gotoxy(45, 15);
    printf(" @   @ ");
    gotoxy(45, 16);
    printf(" @   @ ");
    gotoxy(45, 17);
    printf("  @ @  ");
    gotoxy(45, 18);
    printf("  @ @  ");
    gotoxy(45, 19);
    printf("   @   ");

    Sleep(500);
    gotoxy(54, 13);
    printf("@@@@@@@");
    gotoxy(54, 14);
    printf("@      ");
    gotoxy(54, 15);
    printf("@      ");
    gotoxy(54, 16);
    printf("@@@@@@@");
    gotoxy(54, 17);
    printf("@      ");
    gotoxy(54, 18);
    printf("@      ");
    gotoxy(54, 19);
    printf("@@@@@@@");

    Sleep(500);
    gotoxy(63, 13);
    printf("@@@@@@ ");
    gotoxy(63, 14);
    printf("@     @");
    gotoxy(63, 15);
    printf("@     @");
    gotoxy(63, 16);
    printf("@@@@@@ ");
    gotoxy(63, 17);
    printf("@  @@  ");
    gotoxy(63, 18);
    printf("@   @@ ");
    gotoxy(63, 19);
    printf("@    @@");

    gotoxy(35, 25);
    printf("Você chegou até o dia %i às %ih %imin", contaDia, totalh, totalints);

    remove("capturados.rbcr");
    remove("robosnight.rbcr");
    remove("save.rbcr");
}

void Tutorial()
{
    system("CLS");
    for(int i = 0; i < 30; i++)
    {
        for(int j = 0; j < 150; j++)
        {
            if(i == 0)
            {
                gotoxy(j, 0);
                printf("#");
            }
            if(i == 29)
            {
                gotoxy(j, 29);
                printf("#");
            }
            if(j == 0)
            {
                gotoxy(0, i);
                printf("#");
            }
            if(j == 105)
            {
                gotoxy(150, i);
                printf("#");
            }
        }
    }
    gotoxy(1,1);
    printf("Explicacão breve do jogo:");
    gotoxy(1,2);
    printf("A cidade foi dominada por robôs. Você, como um técnico de TI chamado Dann e o último humano nesse local, deve hackeá-los de dia e lutar contra eles");
    gotoxy(1,3);
    printf("de noite a fim de alertar cidades próximas sobre sua existência. Enquanto isso, você deve lutar contra a fome, a sede, e a infecção, que dizimou");
    gotoxy(1,4);
    printf("a população da cidade.");
    gotoxy(1,6);
    printf("Mecânicas:");
    gotoxy(1,7);
    printf("O mapa é dividido em 9 partes. O mapa que você ve enquanto joga é a parte em que o jogador está. As estruturas são geradas aleatoriamente e cada uma");
    gotoxy(1,8);
    printf("representa um objeto real. V significa veículo, B significa base, - significa lago, W significa arbusto e + significa lata-velha. Ao interagir com");
    gotoxy(1,9);
    printf("as estruturas(posicionar seu personagem no mesmo bloco que ela), as letras que as representam se tornam minúsculas (não podendo interagir com elas ");
    gotoxy(1,10);
    printf("por algumas horas) e você pode ganhar frutas (em arbustos), óleo (em veículos ou bases) ou comida enlatada (em bases). As frutas aumentam sua barra");
    gotoxy(1,11);
    printf("de fome, interagir com o lago aumenta sua barra de sede e ingerir comida enlatada aumenta sua barra de fome e infecção. Fome, sede e infecção ");
    gotoxy(1,12);
    printf("diminuem com o passar do tempo (os dois primeiros a qualquer momento e o último somente ao entrar em latas-velhas). Ao pisar em latas-velhas,");
    gotoxy(1,13);
    printf("você pode encontrar um robô para hackear. Se você conseguir hackear ja tiver 6 robos, todos ganham experiência(XP), caso contrário o robo");
    gotoxy(1,14);
    printf("entra na sua equipe. À noite (a partir das 20:00 horas), você poderá lutar com outros robôs usando os robôs hackeados por você. Caso não");
    gotoxy(1,15);
    printf("possuir robos e entrar em batalha, você morrerá automaticamente, perdendo o jogo. Você pode escolher a opção atacar ou curar (apenas seu primeiro");
    gotoxy(1,16);
    printf("robô). Se o seu robo morrer você o perde, fazendo com que seu próximo robô entre em batalha. Se ficar sem robôs durante a batalha, você perde.");
    gotoxy(1,17);
    printf("Aperte W, A, S, D para mexer o seu personagem. Aperte E para abrir o inventário ou selecionar uma opção na Batalha ou Hackeamento. Ainda em");
    gotoxy(1,18);
    printf("batalha, aperte A ou D para se movimentar entre as opções. Aperte L para sair do jogo. Aperte 1, 2, 3 para selecionar o item consumível no");
    gotoxy(1,19);
    printf("inventário, usando o óleo. Caso escolha o óleo, aperte 1, 2, 3, 4, 5 ou 6 para selecionar em qual robo deseja usá-lo.");
    gotoxy(1,20);
    printf("Bom jogo e divirta-se!!!");
    gotoxy(1,22);
    printf("Creditos:");
    gotoxy(1,23);
    printf("Bruno Gomes de Oliveira, Dann Asbahl Toledo e Gabriel Queiróz Venâncio");
    getch();
    system("CLS");
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
            totalints = floor(totalfls);
            totalh = totalh + totalints/60;
            totalfls = totalints%60 + totalfls - floor(totalfls);
            totalints = totalints%60;
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
        totalfls = totalfls + segundos + microsegundos * pow(10, -6);
        contaTempoNight = contaTempoNight + segundos + microsegundos * pow(10, -6);
        contaFSdb = contaFSdb + segundos + microsegundos * pow(10, -6);
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
