#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <conio.h>
#include <conio.h>
#include <locale.h>

char opl;
char usr[50],senha[10];
FILE *ArqUsr;

int main()
{
    setlocale(LC_ALL, "Portuguese");

    do{
    textcolor(WHITE);clrscr();
            gotoxy(26,2);        printf("*---------------------------*");
            gotoxy(26,3);        printf("|******CRIPTOFAGO-LOGIN*****|");
            gotoxy(26,4);        printf("*---------------------------*");
            gotoxy(26,5);        printf("| 1: Fazer login            |");
            gotoxy(26,6);        printf("|                           |");
            gotoxy(26,7);        printf("| 2: Fazer cadastro         |");
            gotoxy(26,8);        printf("|                           |");
            gotoxy(26,9);        printf("| 3: Voltar                 |");
            gotoxy(26,10);        printf("|                   Op��o:  |");
            gotoxy(26,11);        printf("*---------------------------*");
            gotoxy(52,10);        opl=getch();
            
        switch(opl)
            {
                case '1'://login
                {
                    gotoxy(3,16);printf("Digite seu nome de usu�rio: ");gets(usr);//Usu�rio digita o nome com que quer se logar
                    gotoxy(3,17);printf("Digite sua senha: ");textcolor(BLACK);gets(senha);textcolor(WHITE);//usu�rio informa sua senha                
                    
                    if(ArqUsr!=NULL)//se o arquivo com nome e senha n�o for inexistente
                    {
                    /*
                    Aqui est� a parte dif�cil: Como eu fa�o para procurar uma 
                    palavra espec�fica no arquivo (a senha), e compar�-la com a senha 
                    informada pelo usu�rio? 
                    */                    
                    }
                    else
                    {
                    gotoxy(3,16);printf("Nenhum usu�rio cadastrado!");break;
                    }
                    
                }    
                
                case '2'://cadastro
                {
                        
                textbackground(BLACK); textcolor(WHITE); 
                gotoxy(3,16);printf("Digite seu nome: ");gets(usr);//Usu�rio insere o nome com que quer ser cadastrado
                gotoxy(3,17);printf("Digite sua senha: ");textcolor(BLACK);gets(senha);//usu�rio digita sua senha
                
                ArqUsr=fopen(usr,"a");//fazer um arquivo com o nome do usu�rio
                  
                textcolor(WHITE);gotoxy(3,18);printf("Usu�rio cadastrado com sucesso!");
                fprintf(ArqUsr,"*%s",senha);//grava no arquivo a senha do usu�rio, antecedida pelo caractere *
                fclose(ArqUsr);//fecha o arquivo
                getch();
                }
                case '3': opl=0;break;
                default : printf("\a");break;              
            }
    }while (opl!=0);

}
