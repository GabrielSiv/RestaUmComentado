#include <stdio.h>
#include <stdlib.h>
#include <conio.h>

char jogaveis[11][11];
int percurso = 0, contJogadas = 0,contPecas = 0, contPecas1=0,flagSelect=0;


void inicializaMatriz();    //1- Responsavel por iniciar a matriz e preencher suas casas [11][11] com ' ','1' e '0'.
void mostraMatriz();        //2- Responsavel por printar a matriz de forma limpa e didática para o usuário.  
int testaVitoria();         //3- Responsavel por analisar a quantidade de peças restantes e jogadas possíveis, retornando para o main '-1' em caso de derrota e '1' em caso de vitória.
void contaPecas();          //4- Responsável pela atribuição do valor da variavel global 'contPecas1', esta função escreve, na variavel citada, a quantidade de peças no tabuleiro.
void testaJogadas();        //5- Responsável por testar onde será possível para o usuário realizar jogadas, de acordo com as regras, e por escrever os '*' que irão indicar essas casas.
void finalizaJogadas();     //6- Responsável por reatribuir o dígito '1' nos locais que haviam sido preenchidos por '*', para que a função volte a seu estado inicial.
void percorreJog(int cont); //7- Responsável por receber o parâmetro de percurso, de acordo com as setas tecladas, escrever 'X' onde o cursor está posicionado.
void comePeca(int m,int n); //8- Responsável pela lógica do ato de comer uma peça, de acordo com as regras do jogo.
void posEnter();            //9- Responsável pela limpeza dos '*' escritos anteriormente, e a escrição de novos para onde a peça já selecionada poderá realizar o salto.
void pecaSelecionada();     //10-Responsável pela leitura das setas da peça que o usuário quer escolher para jogar.
void menuMensagem();        //11-Responsável pela mensagem do menu que pode ser chamada antes do início do jogo.
void printaVitoria();       //12-Responsável por escrever vitória na tela, juntamente com o número de peças restantes(que será sempre 1, nesse caso).
void printaDerrota();       //13-Responsável por escrever derrota na tela, juntamente com o número de peças restantes.
int main();                 //14-Responsável por chamar o inicio da matriz, testar as jogadas possíveis, mostrar a matriz, perguntar se o usuário deseja acessar o menu, a função 
                            //'pecaSelecionada', e de acordo com o resultado, chamar 'printaVitória' ou 'printa derrota'*/


void inicializaMatriz(){
    int i,j;
    for(i=0; i<11; i++)
    {
    	if(i==0 || i==1 || i==9 || i==10){
    		for(j=0;j<10;j++){
    			jogaveis[i][j]=' ';
			}
		}
        else if(i==2 || i==3 || i==7 || i==8)
        {
            jogaveis[i][2]=' ';
            jogaveis[i][3]=' ';
            jogaveis[i][7]=' ';
            jogaveis[i][8]=' ';
            for(j=4; j<=6; j++)
            {
                jogaveis[i][j]='1';
            }
        }
        else
        {
            for(j=2; j<9; j++)
            {
                if(i==5 && j==5)
                {
                    jogaveis[i][j]='0';
                }
                else
                {
                    jogaveis[i][j]='1';
                }
            }
        }
    }
}
void mostraMatriz(){
    int i,j;
    system("cls");
	for(i=0; i<11; i++){
        for(j=0; j<11; j++){
        	printf("  %c  ",jogaveis[i][j]);
    	}
    	printf("\n\n");
	}


}
int testaVitoria(){
	if(contJogadas==0 && contPecas1==1){
		return 1;
	}
	else if(contJogadas==0 && contPecas<1){
		return -1;
	}
	else{
		return 0;
	}
}
void contaPecas(){
	int i,j;
	contPecas1=0;
	for(i=2;i<9;i++){
		for(j=2;j<9;j++){
			if(jogaveis[i][j]=='1'|| jogaveis[i][j]=='*')
			contPecas1++;
		}
	}
}
void testaJogadas(){
    int i,j,contPecas;
	system("cls");
    contJogadas=0;

    for(i=2; i<9; i++)
    {
        for(j=2; j<9; j++)
        {
            if (jogaveis[i][j]=='1'|| jogaveis[i][j]=='*')
            {
            	contPecas++;
                if((jogaveis[i+1][j]=='1'|| jogaveis[i+1][j]=='*') && jogaveis[i+2][j]=='0'){
                    jogaveis[i][j]='*';
                    contJogadas++;
                }
                else if((jogaveis[i][j+1]=='1'|| jogaveis[i][j+1]=='*') && jogaveis[i][j+2]=='0'){
                    jogaveis[i][j]='*';
                    contJogadas++;
                }
                else if((jogaveis[i-1][j]=='1'|| jogaveis[i-1][j]=='*') && jogaveis[i-2][j]=='0'){
                    jogaveis[i][j]='*';
                    contJogadas++;
                }
                else if((jogaveis[i][j-1]=='1'|| jogaveis[i][j-1]=='*') && jogaveis[i][j-2]=='0'){
                    jogaveis[i][j]='*';
                    contJogadas++;
                }
            }
        }
    }
    mostraMatriz();
    contaPecas();
	testaVitoria();
	}
void finalizaJogadas(){
	int i,j;
	for(i=2;i<9;i++){
		for(j=2;j<9;j++){
			if(jogaveis[i][j]=='*'){
				jogaveis[i][j]='1';
			}
		}
	}
	testaJogadas();
}
void percorreJog(int cont){

	int i,j, comparaCont=0;

	for(i=2;i<9;i++){
		for(j=2;j<9;j++){
			if(jogaveis[i][j]=='X'){
				jogaveis[i][j]='*';
			}
		}
	}
	for(i=2;i<9;i++){
        for(j=2;j<9;j++){

            if(jogaveis[i][j]=='*'){
            	comparaCont++;
            	if(comparaCont==cont){
                	jogaveis[i][j]= 'X';
            	}
			}
		}
	}
	flagSelect ++;
}
void comePeca(int m,int n){

	int i,j,flag=0;
    char ch;

     if(jogaveis[m+2][n]=='0' && jogaveis[m+1][n]=='1'){
     	jogaveis[m+2][n]='*';
	 }
	 if(jogaveis[m-2][n]=='0' && jogaveis[m-1][n]=='1'){
	 	jogaveis[m-2][n]='*';
	 }
	 if(jogaveis[m][n-2]=='0' && jogaveis[m][n-1]=='1'){
	 	jogaveis[m][n-2]='*';
	 }
	 if(jogaveis[m][n+2]=='0' && jogaveis[m][n+1]=='1'){
	 	jogaveis[m][n+2]='*';
	 }
     if(jogaveis[m+2][n]=='*' || jogaveis[m-2][n]=='*' || jogaveis[m][n-2]=='*' || jogaveis[m][n+2]=='*'){

		while(flag!=1){
		  system("cls");
		  mostraMatriz();
		  fflush(stdin);
          ch = getch();
         if(ch==72){               //72 -- cima
                    if(jogaveis[m-2][n]=='*'){
                        jogaveis[m][n]='0';
                        jogaveis[m-1][n]='0';
                        jogaveis[m-2][n]='1';
                        flag++;
                    }
                    else{
                        printf("Movimento invalido. ");
                    	system("pause");
                    }
                }
        			else if(ch==80){          //80 -- baixo
                    if(jogaveis[m+2][n]=='*'){
                        jogaveis[m][n]='0';
                        jogaveis[m+1][n]='0';
                        jogaveis[m+2][n]='1';
                        flag++;
                    }
                    else{
                        printf("Movimento invalido. ");
                		system("pause");
                    }
                }
        else if(ch==75){         //75 -- esquerda
                    if(jogaveis[m][n-2]=='*'){
                        jogaveis[m][n]='0';
                        jogaveis[m][n-1]='0';
                        jogaveis[m][n-2]='1';
                        flag++;
                    }
                    else{
                        printf("Movimento invalido. ");
                    	system("pause");
                    }
            }
        else if(ch==77){         //77 -- direita
                    if(jogaveis[m][n+2]=='*'){
                        jogaveis[m][n]='0';
                        jogaveis[m][n+1]='0';
                        jogaveis[m][n+2]='1';
                        flag++;
                }
                    else{
                        printf("Movimento invalido. ");
						system("pause");
                     }
            }
		}
	}
	for(i=2;i<9;i++){
		for(j=2;j<9;j++){
			if(jogaveis[i][j]=='*'){
				jogaveis[i][j]='0';
			}
		}
	}
	finalizaJogadas();
}
void posEnter(){

    int i, j;
    int m, n;

    for(i=2;i<9;i++){
        for(j=2;j<9;j++){
            if (jogaveis[i][j]=='*'){
				jogaveis[i][j]='1';
            }
            if (jogaveis[i][j]=='X'){
            	m = i; n = j;
			}
        }
    }
    comePeca(m, n);
    flagSelect=0;
}
void pecaSelecionada(){
	char ch;

    fflush(stdin);
	ch = getch();

	if(ch == 75 || ch == 72){        	//75 -- Esquerda e Cima
		percurso--;
		if(percurso < 1)
			percurso = 1;
			percorreJog(percurso);
		}
	else if(ch == 77 || ch ==80){        //77 -- Direita e Baixo
		percurso++;
		if(percurso >= contJogadas)
			percurso = contJogadas;
			percorreJog(percurso);
	}
	else if(ch == 13 && flagSelect >0){
		posEnter();
	}
}
void menuMensagem(){
	system("cls");
	printf("Como interagir com o jogo: \n\n");
	printf("1- Use as SETAS para se locomover entre as casas onde eh possivel  realizar uma jogada.\n2- Casas com '*' representam pecas que podem ser movidas.\n3- O X representa a  peca que sera selecionada com o 'Enter'.");
	printf("\n4- Quando o X estiver sobre a peca escolhida, tecle'Enter'.\n5- Apos isso serao exibidas as casas para onde a peca marcada podera ser movida, grifadas com um '*'.\n6- Novamente, use as setas para mover para a direcao desejada. ");
	printf("\n7- Clique na direcao que a peca selecionada realizara o salto.\n\nOBS: Lembre-se de posicionar o X sobre uma casa antes de apertar o 'Enter'!\n");
	printf("\n\nRegras do jogo: \n\n");
	printf("1- Pecas nao se movem na diagonal.\n2- Uma peca so salta uma casa por vez.\n3- A condicao de vitoria eh que so reste uma peca no tabuleiro.\n\n");
	system("pause");
	}
void printaVitoria(){
	printf("------------------------------------------------------------------------------------------------------------");
	printf("\nPECAS RESTANTES: %i\n------------------------------------------------------------------------------------------------------------\n",contPecas1);
	printf(">=>      >=>                           >=>        >=>                     >=>\n");
	printf(" >=>    >=>                            >=>        >=>  >>                 >=>\n");
	printf("  >=> >=>       >=>     >=>  >=>       >=>   >>   >=>     >==>>==>        >=>\n");
	printf("    >=>       >=>  >=>  >=>  >=>       >=>  >=>   >=> >=>  >=>  >=>       >> \n");
	printf("    >=>      >=>    >=> >=>  >=>       >=> >> >=> >=> >=>  >=>  >=>       >> \n");
	printf("    >=>       >=>  >=>  >=>  >=>       >> >>    >===> >=>  >=>  >=>          \n");
	printf("    >=>         >=>       >==>=>       >=>        >=> >=> >==>  >=>       >=>\n");
	printf("\n------------------------------------------------------------------------------------------------------------\n");
}
void printaDerrota(){
		printf("------------------------------------------------------------------------------------------------------------");
		printf("\nPECAS RESTANTES: %i\n------------------------------------------------------------------------------------------------------------\n",contPecas1);
		printf(">=>      >=>                           >=>                                                     >=>\n");
		printf(" >=>    >=>                            >=>                                                     >=>\n");
		printf("  >=> >=>       >=>     >=>  >=>       >=>          >=>        >=>      >===>    >==>          >=>\n");
		printf("    >=>       >=>  >=>  >=>  >=>       >=>        >=>  >=>   >=>  >=>  >=>     >>   >=>        >> \n");
		printf("    >=>      >=>    >=> >=>  >=>       >=>       >=>    >=> >=>    >=>   >==>  >>===>>=>       >> \n");
		printf("    >=>       >=>  >=>  >=>  >=>       >=>        >=>  >=>   >=>  >=>      >=> >>                 \n");
		printf("    >=>         >=>       >==>=>       >=======>    >=>        >=>     >=> >=>  >====>         >=>\n");
		printf("\n------------------------------------------------------------------------------------------------------------\n");
	}
int main(){
    inicializaMatriz();
    testaJogadas();
	mostraMatriz();
    
    char k;
	printf("Bem vindo ao Resta 1, digite '5' para acessar o menu de regras e dicas ou\nqualquer outra tecla para prosseguir ao jogo : ");
	fflush(stdin);
	k = getch();
	if(k=='5'){
		menuMensagem();
		system("cls");
	}
     while(1 == 1){
		mostraMatriz();
		pecaSelecionada();
		if((testaVitoria())==1){
			system("cls");
			mostraMatriz();
			printaVitoria();
			system("pause");
			break;
		}
		else if((testaVitoria())==-1){
			system("cls");
			mostraMatriz();
			printaDerrota();
			system("pause");
			break;
		}
	}
    return 0;
}

