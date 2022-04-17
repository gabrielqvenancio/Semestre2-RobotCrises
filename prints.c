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

void Print(int numPrint)
{
    //Prints the start menu
    if(numPrint == 0)
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
    }

    //Prints the highscore
    else if(numPrint == 1)
    {
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
    }

    //Prints Game Over screen
    else if(numPrint == 2)
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
    }

    //Print Tutorial screen
    else if(numPrint == 3)
    {
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
        printf("Explicac�o breve do jogo:");
        gotoxy(1,2);
        printf("A cidade foi dominada por rob�s. Voc�, como um t�cnico de TI chamado Dann e o �ltimo humano nesse local, deve hacke�-los de dia e lutar contra eles");
        gotoxy(1,3);
        printf("de noite a fim de alertar cidades pr�ximas sobre sua exist�ncia. Enquanto isso, voc� deve lutar contra a fome, a sede, e a infec��o, que dizimou");
        gotoxy(1,4);
        printf("a popula��o da cidade.");
        gotoxy(1,6);
        printf("Mec�nicas:");
        gotoxy(1,7);
        printf("O mapa � dividido em 9 partes. O mapa que voc� ve enquanto joga � a parte em que o jogador est�. As estruturas s�o geradas aleatoriamente e cada uma");
        gotoxy(1,8);
        printf("representa um objeto real. V significa ve�culo, B significa base, - significa lago, W significa arbusto e + significa lata-velha. Ao interagir com");
        gotoxy(1,9);
        printf("as estruturas(posicionar seu personagem no mesmo bloco que ela), as letras que as representam se tornam min�sculas (n�o podendo interagir com elas ");
        gotoxy(1,10);
        printf("por algumas horas) e voc� pode ganhar frutas (em arbustos), �leo (em ve�culos ou bases) ou comida enlatada (em bases). As frutas aumentam sua barra");
        gotoxy(1,11);
        printf("de fome, interagir com o lago aumenta sua barra de sede e ingerir comida enlatada aumenta sua barra de fome e infec��o. Fome, sede e infec��o ");
        gotoxy(1,12);
        printf("diminuem com o passar do tempo (os dois primeiros a qualquer momento e o �ltimo somente ao entrar em latas-velhas). Ao pisar em latas-velhas,");
        gotoxy(1,13);
        printf("voc� pode encontrar um rob� para hackear. Se voc� conseguir hackear ja tiver 6 robos, todos ganham experi�ncia(XP), caso contr�rio o robo");
        gotoxy(1,14);
        printf("entra na sua equipe. � noite (a partir das 20:00 horas), voc� poder� lutar com outros rob�s usando os rob�s hackeados por voc�. Caso n�o");
        gotoxy(1,15);
        printf("possuir robos e entrar em batalha, voc� morrer� automaticamente, perdendo o jogo. Voc� pode escolher a op��o atacar ou curar (apenas seu primeiro");
        gotoxy(1,16);
        printf("rob�). Se o seu robo morrer voc� o perde, fazendo com que seu pr�ximo rob� entre em batalha. Se ficar sem rob�s durante a batalha, voc� perde.");
        gotoxy(1,17);
        printf("Aperte W, A, S, D para mexer o seu personagem. Aperte E para abrir o invent�rio ou selecionar uma op��o na Batalha ou Hackeamento. Ainda em");
        gotoxy(1,18);
        printf("batalha, aperte A ou D para se movimentar entre as op��es. Aperte L para sair do jogo. Aperte 1, 2, 3 para selecionar o item consum�vel no");
        gotoxy(1,19);
        printf("invent�rio, usando o �leo. Caso escolha o �leo, aperte 1, 2, 3, 4, 5 ou 6 para selecionar em qual robo deseja us�-lo.");
        gotoxy(1,20);
        printf("Bom jogo e divirta-se!!!");
        gotoxy(1,22);
        printf("Creditos:");
        gotoxy(1,23);
        printf("Bruno Gomes de Oliveira, Dann Asbahl Toledo e Gabriel Queir�z Ven�ncio");
    }
}
