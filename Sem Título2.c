#include <stdlib.h>
#include <stdio.h>
#include <time.h> //srand
#include <conio.h> //Cores
#include <fstream> //Arquivos
#include <iostream> //cin,cout


using namespace std;

//Var Global//
int conf_gameLC = 0, conf_gameScore = 0,conf_gameP = 0;
char player[20];
int lin,col,num = 2,tam = 4;
int LargTab = 24; //Largura do tabuleiro do jogo
int AlturaTab = 16; //Altura do tabuleiro do jogo
int boardGame[6][6] = { 0 };
int gameScore,WinGame = 2048;
bool Replay_jogo = false;


//Limpa Tela
void apaga()
{
system("cls");    
}

//Posições GOTO
void gotoXY(int column, int line)
{
    COORD coord;
    coord.X = column;
    coord.Y = line;
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);
}

void showCur(bool CursorVisibility)
{
    /* HANDLE handle = GetStdHandle(STD_OUTPUT_HANDLE);
    CONSOLE_CURSOR_INFO cursor = { 1, CursorVisibility };
    SetConsoleCursorInfo(handle, &cursor); */
}

//------------------------------------------------MENU---------------------------------------------------------------------------------------------
void Inicio()
{
        textcolor(10);
    printf("\n\n");
    printf("           222222222222222         000000000            444444444       888888888     \n"); Sleep(50);
    printf("          2:::::::::::::::22     00:::::::::00         4::::::::4     88:::::::::88   \n"); Sleep(50);
    printf("          2::::::222222:::::2  00:::::::::::::00      4:::::::::4   88:::::::::::::88 \n"); Sleep(50);
    printf("          2222222     2:::::2 0:::::::000:::::::0    4::::44::::4  8::::::88888::::::8\n"); Sleep(50);
    printf("                      2:::::2 0::::::0   0::::::0   4::::4 4::::4  8:::::8     8:::::8\n"); Sleep(50);
    printf("                      2:::::2 0:::::0     0:::::0  4::::4  4::::4  8:::::8     8:::::8\n"); Sleep(50);
    printf("                   2222::::2  0:::::0     0:::::0 4::::4   4::::4   8:::::88888:::::8 \n"); Sleep(50);
    printf("              22222::::::22   0:::::0 000 0:::::04::::444444::::444  8:::::::::::::8  \n"); Sleep(50);
    printf("            22::::::::222     0:::::0 000 0:::::04::::::::::::::::4 8:::::88888:::::8 \n"); Sleep(50);
    printf("           2:::::22222        0:::::0     0:::::04444444444:::::4448:::::8     8:::::8\n"); Sleep(50);
    printf("          2:::::2             0:::::0     0:::::0          4::::4  8:::::8     8:::::8\n"); Sleep(50);
    printf("          2:::::2             0::::::0   0::::::0          4::::4  8:::::8     8:::::8\n"); Sleep(50);
    printf("          2:::::2       2222220:::::::000:::::::0          4::::4  8::::::88888::::::8\n"); Sleep(50);
    printf("          2::::::2222222:::::2 00:::::::::::::00         44::::::44 88:::::::::::::88 \n"); Sleep(50);
    printf("          2::::::::::::::::::2   00:::::::::00           4::::::::4   88:::::::::88   \n"); Sleep(50);
    printf("          22222222222222222222     000000000             4444444444     888888888     \n"); Sleep(50);
    printf("\n"); Sleep(50); 
    
    textcolor(8);
    printf("\t\t\t\t\t\t\t\t\t\t\t By Luiz Felipe & Matheus.\n");
        textcolor(14);
        printf(" Digite seu nome: ");
        scanf("%[^\n]s",&player);
        
    textcolor(11);
    printf("\n Configuracoes do jogo:        \n");
    
    do{
    textcolor(15);
    printf("\n Numero de Linhas|Colunas desejado:    |    (1)4    |    (2)5    |    (3)6      | =  ");
    scanf("%d",&conf_gameLC);
        if (conf_gameLC >3 || conf_gameLC == 0)
        {
        textcolor(12);
        printf("\nPorfavor Informe um numero valido.");
        }
        }while (conf_gameLC >3 || conf_gameLC == 0);
    
        
        do{
            textcolor(3);
            printf("\n Pontuacao maxima desejada:    |    (1)512    |    (2)1024    |    (3)2048    |    (4)4096      | =  ");
            scanf("%d",&conf_gameScore);
                if (conf_gameScore >4 || conf_gameScore == 0)
                {
                    textcolor(12);
                    printf("\nPorfavor Informe um numero valido.");
                }
          }while (conf_gameScore >4 || conf_gameScore == 0);
    
            do{
                textcolor(5);
                printf("\n Pecas iniciais: |    (1)2    |    (2)2 ou 4    |    (3)2,4 ou 8      | =  ");
                scanf("%d",&conf_gameP);
                    if (conf_gameP >3 || conf_gameP == 0)
                    {
                    textcolor(12);
                    printf("\nPorfavor Informe um numero valido.");
                    }
               }while (conf_gameP >3 || conf_gameP == 0);
                
                showCur(true);
                apaga();
}

//------------------------------------------------RECEBE CONFIG.GAME------------------------------------------------------------------------------

void Conf_game()
{
    switch(conf_gameLC)  //Definindo Configuração do Jogo(Linha|Coluna)
    {
      case 1: LargTab = 24;
                AlturaTab = 16;
                tam = 4;
              break;
      case 2: LargTab = 30;
                AlturaTab = 20;
                tam = 5;
              break;
      case 3: LargTab = 36;
                AlturaTab = 24;
                tam = 6;
              break;
    }        
    
    switch(conf_gameScore) //Definindo Configuração do Jogo(Score)
    {
      case 1: WinGame = 512;
              break;
      case 2: WinGame = 1024;
              break;
      case 3: WinGame = 2048;
              break;
      case 4: WinGame = 4096;;
              break;
    }

    
    switch(conf_gameP) //Definindo Configuração do Jogo(Peças)
    {
      case 1: num = 2;
              break;
      case 2: srand(time(NULL));
                num = rand() % 4;
              
                  if (num > 2){
                      num = 4;
                  }else{
                      num = 2;
                  }
              break;
      case 3: srand(time(NULL));
                num = rand() % 8;
              
                  if (num > 5){
                      num = 8;
                  }else
                  if (num > 2){
                      num = 4;
                  }else{
                      num = 2;
                  }
              break;
    }        
}


//-----------------------------------------------CODIGO-JOGO-2048----------------------------------------------------------------------------------

void Mostra_Tabuleiro()
{
    for (int lin = 0; lin <= LargTab ; lin++) {
        for (int col = 0; col <= AlturaTab; col++) {
            if (col % 4 == 0) {
                gotoXY(lin + 1, col + 1);
                textcolor(8);
                printf("%c", 219);
            }

            else if (lin % 6 == 0) {
                gotoXY(lin + 1, col + 1);
                textcolor(8);
                printf("%c", 219);
            }

            else {
                textcolor(15);
                gotoXY(lin + 1, col + 1);
                printf("%c", 219);
            }
        }
    }
}


void Monta_Tabuleiro()
{
    Mostra_Tabuleiro();

    gameScore = 0;
    for (int lin = 0; lin < LargTab; lin++) {
        for (int col= 0; col < AlturaTab; col++) {
            boardGame[lin][col] = 0;
        }
    }
    
    srand(time(NULL));
    int rand_in[6];
    

    rand_in[0] = rand() % num;
    rand_in[1] = rand() % num;
    rand_in[2] = rand() % num;

    do {
        rand_in[3] = rand() % num;
        rand_in[4] = rand() % num;
        rand_in[5] = rand() % num;
    } while (rand_in[0] == rand_in[3] || rand_in[1] == rand_in[4]  || rand_in[2] == rand_in[5]);

    
    boardGame[rand_in[0]][rand_in[3]] = num;  //recebe numero de inicio
    boardGame[rand_in[1]][rand_in[4]] = num;
    boardGame[rand_in[2]][rand_in[5]] = num;
}

//Direção a-w-s-d
void ParaCima()
{
    for (col = 0; col < tam ; col++) {
        int t = 0;
        for (lin = 0; lin < tam ; lin++) {
            if (boardGame[lin][col] != 0) {
                boardGame[t][col] = boardGame[lin][col];
                t++;
            }
        }
        for (lin = t; lin < tam ; lin++) boardGame[lin][col] = 0;
    }

    for (col = 0; col < tam ; col++) {
        int t = 0;
        for (lin = 0; lin < tam ; lin++) {
            if (boardGame != 0) {
                if (boardGame[lin][col] == boardGame[lin + 1][col]) {
                    boardGame[t][col] = 2 * boardGame[lin][col];
                    gameScore += boardGame[t][col];
                    t++;
                    lin++;
                }
                else {
                    boardGame[t][col] = boardGame[lin][col];
                    t++;
                }
            }
        }
        for (lin = t; lin < tam ; lin++) boardGame[lin][col] = 0;
    }

}

void ParaBaixo()
{
    for (col = 0; col < tam ; col++) {
        int t = 5;
        for (lin = 5; lin >= 0; lin--) {
            if (boardGame[lin][col] != 0) {
                boardGame[t][col] = boardGame[lin][col];
                t--;
            }
        }
        for (lin = t; lin >= 0; lin--) boardGame[lin][col] = 0;
    }

    for (col = 0; col < tam ; col++) {
        int t = 5;
        for (lin = 5; lin >= 0; lin--) {
            if (boardGame != 0) {
                if (boardGame[lin][col] == boardGame[lin - 1][col]) {
                    boardGame[t][col] = 2 * boardGame[lin][col];
                    gameScore += boardGame[t][col];
                    t--;
                    lin--;
                }
                else {
                    boardGame[t][col] = boardGame[lin][col];
                    t--;
                }
            }
        }
        for (lin = t; lin >= 0; lin--) boardGame[lin][col] = 0;
    }
}

void ParaEsquerda()
{
    for (lin = 0; lin < tam ; lin++) {
        int t = 0;
        for (col = 0; col < tam ; col++) {
            if (boardGame[lin][col] != 0) {
                boardGame[lin][t] = boardGame[lin][col];
                t++;
            }
        }
        for (col = t; col < tam ; col++) boardGame[lin][col] = 0;
    }

    for (lin = 0; lin < tam ; lin++) {
        int t = 0;
        for (col = 0; col < tam ; col++) {
            if (boardGame[lin][col] != 0) {
                if (boardGame[lin][col] == boardGame[lin][col + 1]) {
                    boardGame[lin][t] = 2 * boardGame[lin][col];
                    gameScore += boardGame[lin][t];
                    col++;
                    t++;
                }
                else {
                    boardGame[lin][t] = boardGame[lin][col];
                    t++;
                }
            }
        }
        for (col = t; col < tam ; col++) boardGame[lin][col] = 0;
    }
}

void ParaDireita()
{
    for (lin = 0; lin < tam; lin++) {
        int t = 5;
        for (col = 5; col >= 0; col--) {
            if (boardGame[lin][col] != 0) {
                boardGame[lin][t] = boardGame[lin][col];
                t--;
            }
        }
        for (col = t; col >= 0; col--) boardGame[lin][col] = 0;
    }


    for (lin = 0; lin < tam ; lin++) {
        int t = 5;
        for (col = 5; col >= 0; col--) {
            if (boardGame[lin][col] != 0) {
                if (boardGame[lin][col] == boardGame[lin][col - 1]) {
                    boardGame[lin][t] = 2 * boardGame[lin][col];
                    gameScore += boardGame[lin][t];
                    col--;
                    t--;
                }
                else {
                    boardGame[lin][t] = boardGame[lin][col];
                    t--;
                }
            }
        }
        for (int col = t; col >= 0; col--) boardGame[lin][col] = 0;
    }
}


//Cor de fundo numeros...
void cor_numeros(int value)
{
    switch (value) {
    case 2:        textcolor(0);textbackground(15); break;
    case 4:        textcolor(0);textbackground(14); break;
    case 8:        textcolor(0);textbackground(13); break;
    case 16:    textcolor(0);textbackground(1); break;
    case 32:    textcolor(0);textbackground(11); break;
    case 64:    textcolor(0);textbackground(10); break;
    case 128:    textcolor(0);textbackground(9); break;
    case 256:    textcolor(0);textbackground(8); break;
    case 512:    textcolor(0);textbackground(7);break;
    case 1024:  textcolor(0);textbackground(6); break;
    case 2048:  textcolor(0);textbackground(5); break;
    case 4096:  textcolor(0);textbackground(4); break;
    case 8192:  textcolor(0);textbackground(3); break;
    case 16384: textcolor(0);textbackground(2); break;
    }
}


//Arquivos
void write_bestScore(int s)
{
    fstream fileScore;
    fileScore.open("score.txt", ios::out);
    fileScore << s;
    fileScore.close();
}

int bestScore()
{
    int score;
    fstream fileScore;
    fileScore.open("score.txt", ios::in);
    fileScore >> score;
    fileScore.close();
    return score;
}


//Tela do jogo
void Tela()
{
    if (gameScore > bestScore()) {
        write_bestScore(gameScore);
    }
    
//Instrucoes gotoXY
gotoXY(65, 2);    
textcolor(11);printf(" Jogador: ");
gotoXY(75, 2);    
textcolor(15);printf(player);
gotoXY(79, 5);    
textcolor(15);printf("Teclas");
gotoXY(80, 8);
textcolor(10);printf("A");
gotoXY(82, 7);
textcolor(14);printf("W");
gotoXY(84, 8);
textcolor(9);printf("D");
gotoXY(90, 8);
gotoXY(82, 9);
textcolor(13);printf("S");
gotoXY(77, 12);
textcolor(14);printf("< r > replay");
gotoXY(77, 14);
textcolor(12);printf("< x > sair!");
gotoXY(66, 16);
textcolor(11);printf("Best Score: %d", bestScore());


    for (lin = 3; lin <= LargTab; lin += 6) {
        for (col = 3; col <= AlturaTab; col += 4) {
            textcolor(15);
            gotoXY(lin, col); printf("%c%c%c%c", 219, 219, 219, 219);
            cor_numeros(boardGame[(col - 3) / 4][(lin - 3) / 6]);
            if (boardGame[(col - 3) / 4][(lin - 3) / 6] == 0) {
                textcolor(15);
                gotoXY(lin, col); printf("%c%c%c%c", 219, 219, 219, 219);
            }
            else if (boardGame[(col - 3) / 4][(lin - 3) / 6] < 100) {
                gotoXY(lin + 1, col); 
                printf("%d", boardGame[(col - 3) / 4][(lin - 3) / 6]);
            }
            else {
                gotoXY(lin, col);
                printf("%d", boardGame[(col - 3) / 4][(lin - 3) / 6]);
            }
        }
    }
    gotoXY(66, 3);
    textcolor(11);textbackground(0);
    printf("Score: ");
    textcolor(12);
    printf("%d", gameScore);
}

bool Zero_Matriz()
{
    for (lin = 0; lin < tam; lin++) {
        for (col = 0; col < tam; col++) {
            if (boardGame[lin][col] == 0) {
                return true;
            }
        }
    }
    return false;
}

//Proximos numeros
void num_tab()
{
    if (Zero_Matriz() == false) return;


    int x, y;
    srand(time(NULL));

    do {
        x = rand() % tam;
        y = rand() % tam;
    } while (boardGame[x][y] != 0);

    int s = rand() % 20;
    if (s > 17) boardGame[x][y] = 2;
    else boardGame[x][y] = num;
}

int boardCheck[6][6];

void creCheck()
{
    for (lin = 0; lin < tam; lin++) {
        for (col = 0; col < tam; col++) {
            boardCheck[lin][col] = boardGame[lin][col];
        }
    }
}

bool Movimento()
{
    for (lin = 0; lin < tam; lin++) {
        for (col = 0; col < tam; col++) {
            if (boardCheck[lin][col] != boardGame[lin][col]) return true;
        }
    }
    return false;
}

bool GameOver()
{
    if (Zero_Matriz() == false) {
        for (lin = 0; lin < tam ; lin++) {
            for (col = 0; col < tam ; col++) {
                if (boardGame[lin][col] == boardGame[lin][col + 1] || 
                    boardGame[lin][col] == boardGame[lin + 1][col]) return false;
            }
        }
    }
    else if (Zero_Matriz() == true) return false;
    return true;
}

//Arrumar
bool Ganhou()
{
        for (lin = 0; lin < tam ; lin++) {
            for (col = 0; col < tam ; col++) {
                if (boardGame[lin][col] == WinGame) return true;
                
            }
        }
    return false;    
}

int main()
{
    Inicio();
    Conf_game();
    Monta_Tabuleiro();

    while (true) {
        
        if (Replay_jogo == true) { //Replay jogo
            apaga();
            Inicio();
            Conf_game();
            Monta_Tabuleiro();
            Replay_jogo = false;
        }
        showCur(false);
        Tela();

        if (GameOver() == true) {
            gotoXY(68, 22);
            printf("GAME OVER!");
        }
        

    //Movimentação
    char tecla = getch();
    creCheck();

    if (tecla == 'w' || tecla == 'W') {
    ParaCima();
    }
        else if (tecla == 's' || tecla == 'S') {
            ParaBaixo();
        }
            else if (tecla == 'a' || tecla == 'A') {
                ParaEsquerda();
            }
                else if (tecla == 'd' || tecla == 'D') {
                    ParaDireita();
                }
                    else if (tecla == 'r' || tecla == 'R') {
                        Replay_jogo = true;
                    }
                        else if (tecla == 'x' || tecla == 'X') {
                            exit(true);
                        }
                        else continue;
    
        if (Ganhou() == true) {
        gotoXY(30, 10);
        textcolor(10);printf("voce GANHOU!!");
        }

        if (Movimento() == false) continue;
        num_tab();
}

    getch();

    return 0;
}
