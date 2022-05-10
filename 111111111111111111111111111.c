
#ifndef MENU_2048_H_INCLUDED
#define MENU_2048_H_INCLUDED

// Cabe�alhos.
void print_menu_inicial (char *str_inicial[], int x, int y);
void print_menu_opcoes (char *str_opcoes[], int x, int y);
void selecao_opcoes (int *cor, int *tamanho, int *idioma, int x_opcoes, int y0_opcoes);
void menu_cores (char *cores[], int *cor);
void menu_tamanho (int *tamanho_tab);
void para_cima (int posicao_seta, int y_min, int y_max);
void para_baixo (int posicao_seta, int y_min, int y_max);
void carregar (int x, int y);
void idioma_joke ();

// Imprime o menu inicial
void print_menu_inicial (char *str_inicial[], int x, int y)
{
    int i;
    textcolor(14);
    gotoxy (8, 2);
    printf ("2048, The Game");
    for (i = 0; i < 5; i++, y+=2) // Itera��o para impress�o do menu inicial
    {
        gotoxy (x, y);
        puts (str_inicial[i]);
    }
    gotoxy (x - 1, y - 5*2); // x - 1 � a posi��o da seta, pois deve ficar uma unidade atr�s do texto
    printf ("%c", 16);       // A posi��o y deve voltar 4*2 unidades para ficar no primeiro item do menu
    gotoxy (8, 17);
    printf ("Use as setas do teclado para mover os elementos no tabuleiro.");
    gotoxy (8, 18);
    printf ("L  - carrega um jogo salvo. (Durante o jogo)");
    gotoxy (8, 19);
    printf ("R - Reset. (Durante o jogo)");
    gotoxy (x - 1, y - 5*2); // Recolocamos o cursor na posi��o onde se encontra a seta por quest�o de est�tica
}

// Imprime o menu de op��es
void print_menu_opcoes (char *str_opcoes[], int x, int y)
{
    int i;
    for (i = 0; i < 4; i++, y+=2)
    {
        gotoxy (x, y);
        puts (str_opcoes[i]);
    }
    y = y - 4*2; // Voltando ao y inicial
    gotoxy (x-1, y); // Posicionando a seta
    printf ("%c", 16); // Imprimindo a seta
    gotoxy (x-1, y); // Reposicionando o cursor
}

// Controla a sele��o no menu de op��es
void selecao_opcoes (int *cor, int *tamanho, int *idioma, int x_opcoes, int y0_opcoes)
{
    char *cores[9] = {"Padr\706o", "Cinza escuro", "Azul", "Verde claro", "Azul claro", "Vermelho", "Rosa", "Amarelo", "Branco"};
    char opcao;
    int contador, x_seta_opcoes = 27, y_inicial = 6, x_seta_cores = 7, flag = 0, tam;

    do
    {
        opcao = getch();
        switch (opcao)
        {
            case 72:
                para_cima (x_opcoes-1, y0_opcoes, y0_opcoes+3*2);
                break;
            case 80:
                para_baixo (x_opcoes-1, y0_opcoes, y0_opcoes+3*2);
                break;
            case 13:
                {
                    switch (wherey()) // Switch ir� verificar a posi��o da seta com a fun��o wherey(), pois o cursor est� junto � seta.
                    {
                        case 6: // Primeira op��o: cor do tabuleiro.
                            {
                                menu_cores (cores, &*cor);
                                return;
                            }
                            break;
                        case (6+1*2): // Segunda op��o: tamanho do tabuleiro.
                            {
                                menu_tamanho (&*tamanho);
                                return;
                            }
                            break;
                        case (6+2*2): // Terceira op��o: idiomas.
                            {
                                idioma_joke ();
                                return;
                            }
                            break;
                        case (6+3*2): // Quarta op��o: voltar.
                            {
                                clrscr();
                                return;
                            }
                            break;
                        default:;
                    }
                }
                break;
            default:;
        }
    } while (flag == 0);
}

// Exibe o menu para sele��o de cores.
void menu_cores (char *cores[], int *cor)
{
    int i, y = 6;
    char opcao;

    clrscr();
    gotoxy (8, 4);
    textcolor(7);
    printf ("Cores: ");
    for (i = 0; i < 9; i++, y+=2) // Imprime o menu de cores.
    {
        gotoxy (8, y);
        textcolor(i+7);
        puts (cores[i]);
    }
    gotoxy (7, 4);
    printf ("%c", 16);
    gotoxy (7, 4);
    do // Itera��o dos controles dentro do menu de cores.
    {
        opcao = getch();
        switch (opcao)
        {
            case 72:
            {
                para_cima (7, 5, 5+8*2);
            }
            break;
            case 80:
            {
                para_baixo (7, 5, 5+8*2);
            }
            break;
            case 13:
            {
                *cor = (wherey() + 8)/2; // Para imprimir com a cor dependendo da posi��o y onde se encontra o nome da cor.
                clrscr();
                return;
            }
            break;
            default:;
        }
    } while (opcao != 27);
    clrscr();
}

// Exibe o menu para sele��o de tamanhos.
void menu_tamanho (int *tamanho_tab)
{
    int flag = 0;
    clrscr();
    gotoxy (1, 5);
    printf ("O tamanho do tabuleiro \202 dado por uma matriz quadrada de uma ordem \ndefinida pelo usu\240rio. ");
    printf ("Esse tamanho deve estar entre 2 e 8\n");
    printf ("Por favor, digite o tamanho desejado para o tabuleiro de jogo: ");
    do // Itera��o de n�o permite que o tamanho escolhido exceda os limites.
    {
        scanf ("%d", &*tamanho_tab);
        if (*tamanho_tab < 2 || *tamanho_tab > 8)
            printf ("\nTamanho inv\240lido\n\nPor favor, digite um n\243mero entre 2 e 8: ");
        else
            flag = 1;
        fflush(stdin); // Para o caso do usu�rio digitar um letra.
    } while (flag == 0);
    carregar (1, wherey()+1);
    delline();
    gotoxy (1, wherey()-1);
    // Avisa ao usu�rio o tamanho do tabuleiro que ele escolheu.
    printf ("\nCarregado. \n\nTamanho do tabuleiro agora \202: %d por %d", *tamanho_tab, *tamanho_tab);
    Sleep (3000);
    clrscr();
    return;
}

// Controla a movimenta��o para cima da seta de sele��o dos menus
void para_cima (int posicao_seta, int y_min, int y_max)
{
    int coordenada_y;
    coordenada_y = wherey();
    if (coordenada_y > y_min)
    {
        gotoxy (posicao_seta, coordenada_y);
        printf (" "); // Apaga a antiga seta.
        gotoxy (posicao_seta, coordenada_y - 2);
        printf ("%c", 16); // Imprime de novo.
        gotoxy (posicao_seta, coordenada_y - 2);
    }
    else if (coordenada_y == y_min) // Caso estejamos no y m�nimo, voltamos para baixo no menu.
    {
        gotoxy (posicao_seta, coordenada_y);
        printf (" "); // Apaga a antiga seta.
        gotoxy (posicao_seta, y_max);
        printf ("%c", 16); // Imprime de novo.
        gotoxy (posicao_seta, y_max);
    }
}

// Controla a movimenta��o para baixo da seta de sele��o dos menus
void para_baixo (int posicao_seta, int y_min, int y_max)
{
    int coordenada_y;
    coordenada_y = wherey();
    if (coordenada_y < y_max)
    {
        gotoxy (posicao_seta, coordenada_y);
        printf (" "); // Apaga a antiga seta.
        gotoxy (posicao_seta, coordenada_y + 2);
        printf ("%c", 16); // Imprime de novo.
        gotoxy (posicao_seta, coordenada_y + 2);
    }
    else if (coordenada_y == y_max) // Caso estejamos no y m�nimo, voltamos para baixo no menu.
    {
        gotoxy (posicao_seta, coordenada_y);
        printf (" "); // Apaga a antiga seta.
        gotoxy (posicao_seta, y_min);
        printf ("%c", 16); // Imprime de novo.
        gotoxy (posicao_seta, y_min);
    }
}

// Exibe uma porcentagem de carregamento na posi��o xy desejada, simplesmente por quest�o est�tica.
void carregar (int x, int y)
{
    int load;
    gotoxy (x, y);
    printf ("Carregando ");
    for (load = 0; load <= 100; load++)
    {
        gotoxy (x+11, y); // Vai sobrepondo a impress�o antiga.
        printf ("%2d%%", load);
        Sleep (10);
    }
}


// Fun��o para a op��o de idioma no menu de op��es. � uma brincadeira.
void idioma_joke ()
{
    char x;
    clrscr();
    gotoxy(1, 5);
    textcolor(7);
    printf ("Por que voc\210 quer mudar o idioma num jogo de matem\240tica?\n");
    printf ("Lamentamos, mas n\706o h\240 op\207\706o de alterar o idioma.\n");
    printf ("Agora v\240 jogar. Tecle qualquer tecla para voltar ao menu inicial.");
    x = getch();
    clrscr();
}

#endif // MENU_2048_H_INCLUDED
