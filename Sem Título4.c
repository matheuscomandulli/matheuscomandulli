#include <stdio.h> // padr�o
#include <stdlib.h> // padr�o
#include <string.h> // Essa biblioteca serve para usar os structs e manipula��o de strings


typedef struct{
    char login[30]; // vetor login da struct pessoa
    char senha[30]; // vetor senha da struct pessoa
} pessoa; pessoa p[1];  // diminuindo o nome da struct para "p" e o "[1]" � o m�ximo de pessoas com logins e senhas


int main(){


    char login[30]; // respons�vel por armazenar a senha inserida pelo usu�rio
    char senha[30]; // respons�vel por armazenar a senha inserida pelo usu�rio

    strcpy(p[0].login, "Matheus"); // Definindo o login "David" na struct
    strcpy(p[0].senha, "123"); // Definindo a senha "123"  na struct

    printf("\nlogin:");
    scanf("%s", login); // armazenando os dados inseridos pelo usu�rio para o vetor login que est� dentro da fun��o main

    printf("\nsenha:");
    scanf("%s", senha); // armazenando os dados inseridos pelo usu�rio para o vetor senha que est� dentro da fun��o main

    if ((strcmp(login,p[0].login)==0) && (strcmp(senha,p[0].senha)==0)){ // A fun��o strcmp � respons�vel por comparar string com string
        printf("Usu�rio logado"); // se os vetores de dentro da struct tiver os mesmos dados do vetor interno da fun��o main, usu�rio ser� logado.
    }else{
        printf("Login e/ou senha incorretos"); // sen�o, login ou senha incorreta.
    }
    return 0;
}
