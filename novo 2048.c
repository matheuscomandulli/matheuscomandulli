	#include <stdio.h>
	#include <stdlib.h>
	#include <windows.h>
	#include <conio.h>
	#include <locale.h>
	#include <stdbool.h>
	#include <stdio.h>
#include <time.h>
#include<time.h>
#include<ctype.h>
#include <time.h>
#include <process.h>

#define UP 72
#define DOWN 80
#define LEFT 75
#define RIGHT 77
#define BACKESPACE 8
#define SIZE 4
#define BORDER 219
#define ESC 57
#define PR 2
int Matrix[SIZE+1][SIZE+1]={0};
int pontuacao=0,last=2048;

void starting();
void wait();
void waitL();
void vname();
void Display();
void print_ever();
void Action(int);
void Random_creator();
void Starting_Random();
int Temp_counter();
void ending();
void record();
void Down();
void Up();
void Left();
void Right();




void starting()
{
    printf("=====================JOGO 2048===========================");
    printf("\n\n\n\t\t\tINSTRUÇÕES\n\n\n");
    printf(" ->  Digite a tecla de seta para mover\n\n");
    printf(" ->  Para ganhar o jogo você deve chegar a 2048\n\n");
    printf(" ->  Aproveite o jogo e boa sorte\n\n\n\n");
    printf("\t\t\t\t\t\tPressione alguma tecla\n");
    while(!kbhit());
}

void wait()
{
    int i;
    for(i=0;i<4500000;i++);
}



printer(char s[])
{
    int i=0;
    while(s[i]!='\0')
    {
        printf("%c",s[i]);

        i++;
    }
}

void Action(int Arrow)
{

    switch(Arrow)
    {
        case UP:
            {
                Up();
                break;
            }
        case DOWN:
            {
                /* lógica aqui */
                Down();
                break;
            }
        case LEFT:
            {
                Left();
                break;
            }
        case RIGHT:
            {
                Right();
                break;
            }
        default:
            {
                /*FAZER NADA */
                return;
            }
    }
    pontuacao++;
    Random_creater();
    Display();
}

void Random_creater()
{
    int temp1,temp2,add,i,j;
    srand(time(NULL));
    temp1=rand()%SIZE;  // i

    srand(time(NULL));
    temp2=rand()%SIZE;  // j

    if((temp1+temp2)%2==0)
        add=2;
    else
        add=4;

    for(i=0;i<temp1;i++)
    {
        for(j=temp2;j<SIZE;j++)
        {
            if(Matrix[i][j]==0)
            {
                Matrix[i][j]=add;
                return;
            }
        }
    }
}

void Display()
{

    int i,j;
    system("cls");
    print_ever();
    for(i=0;i<SIZE;i++)
    {
        printf("\t\t\t %c",BORDER);
        for(j=0;j<SIZE;j++)
        {
            if(Matrix[i][j]==0)
            {
                printf("      ");
            }
            else
                printf(" %4d ",Matrix[i][j]);
        }
        printf("%c\n\t\t\t %c                        %c\n",BORDER,BORDER,BORDER);
    }
    printf("\t\t\t %c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c\n\n",BORDER,BORDER,BORDER,BORDER,BORDER,BORDER,BORDER,BORDER,BORDER,BORDER,BORDER,BORDER,BORDER,BORDER,BORDER,BORDER,BORDER,BORDER,BORDER,BORDER,BORDER,BORDER,BORDER,BORDER,BORDER,BORDER);
}
void print_ever()
{
    printf("\n\n\n\t\t\t2048\n");
    printf("\t\t\t\t\t\t\t\t PONTUAÇÃO  : %d\n\n\n\n",pontuacao);
    printf("\t\t\t %c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c\n",BORDER,BORDER,BORDER,BORDER,BORDER,BORDER,BORDER,BORDER,BORDER,BORDER,BORDER,BORDER,BORDER,BORDER,BORDER,BORDER,BORDER,BORDER,BORDER,BORDER,BORDER,BORDER,BORDER,BORDER,BORDER,BORDER);

}

void ending()
{
    /*aqui imprime a pontuação anterior e a pontuação atual do arquivo */
    printf("\n\n\t\t\t\tSUA PONTUAÇÃO is  : %d",pontuacao);
    record();
}
void record(){
   char plname[20],nplname[20],cha,c;
   int i,j;
   FILE *info;
   info=fopen("record.txt","a+");
   getch();
   system("cls");
   printf("ESCOLHA SEU NOME \n");
   scanf("%[^\n]",plname);
   //************************
   for(j=0;plname[j]!='\0';j++){ //para converter a primeira letra após o espaço para maiúscula
   nplname[0]=toupper(plname[0]);
   if(plname[j-1]==' '){
   nplname[j]=toupper(plname[j]);
   nplname[j-1]=plname[j-1];}
   else nplname[j]=plname[j];
   }
   nplname[j]='\0';
   //*****************************
   //sdfprintf(info,"\t\t\tLista de jogadores\n");
   fprintf(info,"SEU NOME :%s\n",nplname);
    //for date and time

   time_t mytime;
  mytime = time(NULL);
  fprintf(info,"Played Date:%s",ctime(&mytime));
     //**************************
     fprintf(info,"PONTUAÇÃO:%d\n",pontuacao);//pontuação de chamada para exibir a pontuação
     //fprintf(info,"\nLevel:%d\n",10);//nível de chamada para exibir o nível
   for(i=0;i<=50;i++)
   fprintf(info,"%c",'_');
   fprintf(info,"\n");
   fclose(info);
   printf("Para ver seus recordes pressione 'y'\n");
   cha=getch();
   system("cls");
   if(cha=='y'){
   info=fopen("recordes.txt","r");
   do{
       putchar(c=getc(info));
       }while(c!=EOF);}
     fclose(info);
     printf("\n\n\n\t\t\t\tPRESSIONE UMA TECLA PARA SAIR\n");
     while(!kbhit());
    system("attrib +h +s recordes.txt");
}

void Starting_Random()
{
    Matrix[3][1]=0;
    Matrix[3][2]=2;
    Matrix[3][3]=0;
    Matrix[2][2]=0;
    Matrix[2][3]=0;
    Matrix[1][2]=0;
	Matrix[1][1]=0;
    Display();
}

int Temp_counter()
{
    /* DEVE ENCONTRAR O VALOR MÁXIMO DE TODA A MATRIZ  */
    int temp=0,i,j;

    for(i=0;i<SIZE;i++)
    {
        for(j=0;j<SIZE;j++)
        {
            if(Matrix[i][j]==2048)
                return(1);
            if(Matrix[i][j]==0)
                temp=1;
        }
    }
    if(temp==1)
    {
        last=0;
        return(-99);
    }
    else
    {
        if(last==1)
        {
            return(0);
        }
        last=1;
        return(-99);
    }
}

void Down()
{
    int i,j;
    for(j=0;j<SIZE;j++)
    {
        i=2;
        while(1)
        {
            while(Matrix[i][j]==0)
            {
                if(i==-1)
                    break;
                i--;
            }
            if(i==-1)
                break;
            while(i<SIZE-1 && (Matrix[i+1][j]==0 || Matrix[i][j]==Matrix[i+1][j]))
            {
                Matrix[i+1][j]+=Matrix[i][j];
                Matrix[i][j]=0;
                i++;
            }
            i--;
        }
    }
}
void Up()
{
    int i,j;
    for(j=0;j<SIZE;j++)
    {
        i=1;
        while(1)
        {
            while(Matrix[i][j]==0)
            {
                if(i==SIZE)
                    break;
                i++;
            }
            if(i==SIZE)
                break;
            while(i>0 && (Matrix[i-1][j]==0 || Matrix[i][j]==Matrix[i-1][j]))
            {
                Matrix[i-1][j]+=Matrix[i][j];
                Matrix[i][j]=0;
                i--;
            }
            i++;
        }
    }
}
void Right()
{
    int i,j;
    for(i=0;i<SIZE;i++)
    {
        j=2;
        while(1)
        {
            while(Matrix[i][j]==0)
            {
                if(j==-1)
                    break;
                j--;
            }
            if(j==-1)
                break;
            while(j<SIZE-1 && (Matrix[i][j+1]==0 || Matrix[i][j]==Matrix[i][j+1]))
            {
                Matrix[i][j+1]+=Matrix[i][j];
                Matrix[i][j]=0;
                j++;
            }
            j--;
        }
    }
}
void Left()
{
    int i,j;
    for(i=0;i<SIZE;i++)
    {
        j=1;
        while(1)
        {
            while(Matrix[i][j]==0)
            {
                if(j==SIZE)
                    break;
                j++;
            }
            if(j==SIZE)
                break;
            while(j>0 && (Matrix[i][j-1]==0 || Matrix[i][j]==Matrix[i][j-1]))
            {
                Matrix[i][j-1]+=Matrix[i][j];
                Matrix[i][j]=0;
                j--;
            }
            j++;
        }
    }
}
	aCol(int lin, int col);
	void box(int lin1, int col1, int lin2, int col2);
	int menu(int lin1, int col1, int qtd, char lista[3][40]);
	void textColor(int letras, int fundo);
	//COR DA LETRA
	enum{BLACK, //0
	BLUE, //1
	GREEN, //2
	CYAN, //3
	RED, //4
	MAGENTA, //5
	BROWN, //6
	LIGHTGRAY, //7
	DARKGRAY, //8
	LIGHTBLUE, //9
	LIGHTGREEN, //10
	LIGHTCYAN, //11
	LIGHTRED, //12
	LIGHTMAGENTA, //13
	YELLOW, //14
	WHITE //15

	};
	//COR DO FUNDO
	enum{_BLACK=0, //0
	_BLUE=16, //1
	_GREEN=32, //2
	_CYAN=48, //3
	_RED=64, //4
	_MAGENTA=80, //5
	_BROWN=96, //6
	_LIGHTGRAY=112, //7
	_DARKGRAY=128, //8
	_LIGHTBLUE=144, //9
	_LIGHTGREEN=160, //10
	_LIGHTCYAN=176, //11
	_LIGHTRED=192, //12
	_LIGHTMAGENTA=208, //13
	_YELLOW=224, //14
	_WHITE=240 //15
	};

	void textColor(int letra, int fundo){
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), letra + fundo);
	}

	void linhaCol(int lin, int col){
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE),(COORD){col-1,lin-1});// coorddenada na tela

	//funcao para deixar o cursor invisivel
	HANDLE consoleHandle = GetStdHandle(STD_OUTPUT_HANDLE);
	CONSOLE_CURSOR_INFO info;
	info.dwSize = 100;
	info.bVisible = FALSE;
	SetConsoleCursorInfo(consoleHandle, &info);
	}
	void box(int lin1, int col1, int lin2, int col2){
	int i,j , tamlin, tamcol;

	//achar o tamanho do box
	tamlin = lin2 - lin1;
	tamcol = col2 - col1;

	//Monta o Box

	for (i=col1; i<=col2; i++){ // linhas
	linhaCol(lin1,i);
	printf("%c",196);
	linhaCol(lin2,i);
	printf("%c",196);
	}

	for (i=lin1; i<=lin2; i++){ //colunas
	linhaCol(i,col1);
	printf("%c",179);
	linhaCol(i,col2);
	printf("%c",179);
	}
	for (i=lin1+1;i<lin2;i++){
	for(j=col1+1;j<col2;j++){
	linhaCol(i,j);printf(" ");
	}
	}
	//Posição dos cantos
	linhaCol(lin1,col1);
	printf("%c",218);
	linhaCol(lin1,col2);
	printf("%c",191);
	linhaCol(lin2,col1);
	printf("%c",192);
	linhaCol(lin2,col2);
	printf("%c",217);

	}
	int menu(int lin1, int col1, int qtd, char lista[3][40]){
	int opc=1, lin2, col2, linha,i,tamMaxItem, tecla;

	//calcula as coordenadas
	tamMaxItem = strlen(lista[0]);
	//tamanho maximo do item
	for(i=1; i<qtd;i++){
	if(strlen(lista[i])>tamMaxItem){
	tamMaxItem = strlen(lista[i]);
	}
	}
	lin2 = lin1+(qtd*2+2);
	col2 = col1+tamMaxItem+4;

	//Monta Tela
	textColor(WHITE, _BLACK);
	setlocale(LC_ALL,"C");
	box(lin1,col1,lin2,col2);
	setlocale(LC_ALL,"");
	//laço das opcões
	while(1){

	linha=lin1+2;
	for(i=0;i<qtd;i++){           
	   if(i+1==opc)textColor(BLACK, _LIGHTCYAN);
	   else textColor(WHITE, _BLACK);
	linhaCol(linha,col1+2);
	printf("%s",lista[i]);
	linha +=2;
	}
	//Aguarda tecla
	linhaCol(1,1);
	tecla= getch();
	linhaCol(22,1);
	//printf(" tecla: %d ",tecla);
	//Opção
	if(tecla==27){ //ESC
	opc=0; break;
	}
	else if(tecla==13){ //ENTER
	break;
	}
	//Seta para cima
	else if(tecla==72){ //se possivel seleciona o item anterior - seta para cima
	if(opc>1)opc--; // se opcao for maior que 1, pode voltar

	}
	else if(tecla==80 ){ //seta para baixo
	if (opc<qtd)opc++; //Se opcao for menor que quantidade de itens, posso avançar

	//printf("tecla: %d ",opc);
	}
	}
	return opc;
	}
	   
	int main()
	{
		system("cls");
printf("       __    ______     _______   ______       ___     ___    _  _      ___    \n");
printf("      |  |  /  __  \   /  _____| /  __  \       |__ \   /  _ \ | | ||      / _ \   \n");
printf("      |  | |  |  |  | |  |  __  |  |  |  |       ) | | | | | | || |_  | (_) |  \n");
printf(".--.  |  | |  |  |  | |  | |_ | |  |  |  |      / /  | | | | |__   _|  > _ <  \n");
printf("|  `--'  | |  `--'  | |  |__| | |  `--'  |     / /_  | |_| |    | |   | (_) | \n");
printf("   \______/   \______/    \______|   \______/     |____|   \___/     |_|     \___/  \n");

	int opc;
	char lista[5][40]={"NOVO JOGADOR", "JOGAR 2048", "INSTRUÇÕES", "RANKING",};
	char nome,senha;
	setlocale(LC_ALL,"Portuguese");
	while(true){
	opc = menu(10,10,5,lista);

	if (opc==0){
	break;
	}
	//seleção de opções
	linhaCol(1,1);
	textColor(WHITE, _BLACK);
	printf("\nEscolheu a opção %d", opc);
	if (opc == 1){

	int tam = 0;
	int tam2 = 0;
	char usuario[80], senha[80], senha2[80];
	memset(usuario, 0x00, sizeof(usuario));
	memset(senha, 0x00, sizeof(senha));
	memset(senha2, 0x00, sizeof(senha2));
system("cls");
printf("       __    ______     _______   ______       ___     ___    _  _      ___    \n");
printf("      |  |  /  __  \   /  _____| /  __  \       |__ \   /  _ \ | | ||      / _ \   \n");
printf("      |  | |  |  |  | |  |  __  |  |  |  |       ) | | | | | | || |_  | (_) |  \n");
printf(".--.  |  | |  |  |  | |  | |_ | |  |  |  |      / /  | | | | |__   _|  > _ <  \n");
printf("|  `--'  | |  `--'  | |  |__| | |  `--'  |     / /_  | |_| |    | |   | (_) | \n");
printf("   \______/   \______/    \______|   \______/     |____|   \___/     |_|     \___/  \n");
	printf("\n Digite o usuario. -> \n ");
	scanf("%s", &usuario);
	printf("\n Digite a senha. -> \n ");
	fflush(stdin);

	do
	{   
		 senha[tam] = getch();          
		 if(senha[tam] == 0x08 && tam > 0)  //Backspace
		 {   
			printf("\b \b"); 
			senha[tam] = 0x00;
			tam--;

		 } 
		 else if (senha[tam] == 13) // Enter
		 {  
			senha[tam] = 0x00;
			break;
		}
		else if (senha[tam] != 0x08)
		{
			putchar('*');
			tam++;              
		 }
	}while(tam < 10) ;
	printf("\nDigite a senha novamente -> \n");

	do 
	{   
		 senha2[tam2] = getch();          
		 if(senha[tam2] == 0x08 && tam2 > 0)  //Backspace
		 {   
			printf("\b \b"); 
			senha2[tam2] = 0x00;
			tam2--;

		 } 
		 else if (senha2[tam2] == 13) // Enter
		 {  
			senha2[tam2] = 0x00;
			break;
		}
		else if (senha2[tam2] != 0x08)
		{
			putchar('*');
			tam2++;              
		 }
	}while(tam2 < 10) ;
	if (strcmp(senha, senha2) == 0)
	{
	printf("%s, Senha correta\n", usuario);
	}
	else
	printf("%s, Senha invalida\n", usuario);

	}

	else if (opc == 2){
	int tam = 0;
	int tam2 = 0;
	char usuario[80], senha[80], senha2[80];
	memset(usuario, 0x00, sizeof(usuario));
	memset(senha, 0x00, sizeof(senha));
	memset(senha2, 0x00, sizeof(senha2));
	system("cls");
printf("       __    ______     _______   ______       ___     ___    _  _      ___    \n");
printf("      |  |  /  __  \   /  _____| /  __  \       |__ \   /  _ \ | | ||      / _ \   \n");
printf("      |  | |  |  |  | |  |  __  |  |  |  |       ) | | | | | | || |_  | (_) |  \n");
printf(".--.  |  | |  |  |  | |  | |_ | |  |  |  |      / /  | | | | |__   _|  > _ <  \n");
printf("|  `--'  | |  `--'  | |  |__| | |  `--'  |     / /_  | |_| |    | |   | (_) | \n");
printf("   \______/   \______/    \______|   \______/     |____|   \___/     |_|     \___/  \n");
	printf("\n Digite o usuario. -> \n ");
	scanf("%s", &usuario);
	printf("\n Digite a senha. -> \n ");
	fflush(stdin);

	do
	{   
		 senha[tam] = getch();          
		 if(senha[tam] == 0x08 && tam > 0)  //Backspace
		 {   
			printf("\b \b"); 
			senha[tam] = 0x00;
			tam--;

		 } 
		 else if (senha[tam] == 13) // Enter
		 {  
			senha[tam] = 0x00;
			break;
		}
		else if (senha[tam] != 0x08)
		{
			putchar('*');
			tam++;              
		 }
	}while(tam < 10) ;
	printf("\nDigite a senha novamente -> \n");

	do 
	{   
		 senha2[tam2] = getch();          
		 if(senha[tam2] == 0x08 && tam2 > 0)  //Backspace
		 {   
			printf("\b \b"); 
			senha2[tam2] = 0x00;
			tam2--;

		 } 
		 else if (senha2[tam2] == 13) // Enter
		 {  
			senha2[tam2] = 0x00;
			break;
		}
		else if (senha2[tam2] != 0x08)
		{
			putchar('*');
			tam2++;              
		 }
	}while(tam2 < 10) ;
	if (strcmp(senha, senha2) == 0)
	{
	printf("%s, Senha correta\n", usuario);
	}
	else
	printf("%s, Senha invalida\n", usuario);
	int aro;
    char Arrow;
    char s[]="OBRIGADO POR JOGAR, BOA SORTE NA PRÓXIMA";
    int temp;
    starting();
    Starting_Random();
    Arrow=DOWN;
    while(Arrow!=ESC)  //  AQUI SE O USUÁRIO QUISER SAIR, PRESSIONE A TECLA ESC
    {
        Arrow=getch();
        aro=Arrow;
        Action(Arrow);
        temp=Temp_counter();
        if(temp==1)
        {
            printf("\n\t\t\tPARABÉNS! VOCÊ GANHOU");
            ending();
            break;
        }
        if(temp==0 || pontuacao<0)
        {
            printf("\n\t\t\tSINTO MUITO! VOCÊ PERDEU\n");
            break;
        }
    }

    system("cls");
    printf("\n\n\n\t");
    printer(s);
	}
	else if (opc == 3){
	system("cls");
printf("       __    ______     _______   ______       ___     ___    _  _      ___    \n");
printf("      |  |  /  __  \   /  _____| /  __  \       |__ \   /  _ \ | | ||      / _ \   \n");
printf("      |  | |  |  |  | |  |  __  |  |  |  |       ) | | | | | | || |_  | (_) |  \n");
printf(".--.  |  | |  |  |  | |  | |_ | |  |  |  |      / /  | | | | |__   _|  > _ <  \n");
printf("|  `--'  | |  `--'  | |  |__| | |  `--'  |     / /_  | |_| |    | |   | (_) | \n");
printf("   \______/   \______/    \______|   \______/     |____|   \___/     |_|     \___/  \n");
	printf("1 - realize apenas uma jogada por vez \n");
	printf("2 - o objetivo e chegar a 2048 \n");
	}
	else if (opc == 4){
	system("cls");
printf("       __    ______     _______   ______       ___     ___    _  _      ___    \n");
printf("      |  |  /  __  \   /  _____| /  __  \       |__ \   /  _ \ | | ||      / _ \   \n");
printf("      |  | |  |  |  | |  |  __  |  |  |  |       ) | | | | | | || |_  | (_) |  \n");
printf(".--.  |  | |  |  |  | |  | |_ | |  |  |  |      / /  | | | | |__   _|  > _ <  \n");
printf("|  `--'  | |  `--'  | |  |__| | |  `--'  |     / /_  | |_| |    | |   | (_) | \n");
printf("   \______/   \______/    \______|   \______/     |____|   \___/     |_|     \___/  \n");
	printf("pontuação \n");
	printf("1-\n");
	printf("2-\n");
	printf("3-\n");
	printf("4-\n");
	printf("5-\n");
	}
	getchar();
	}
	textColor(WHITE, _BLACK);
	linhaCol(24,1);
	printf("");

	return 0;
		}
