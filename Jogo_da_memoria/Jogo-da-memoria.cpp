#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <windows.h>
#include <conio.h>
#include <time.h>
#include <locale.h>

void ranking();
void menu();
void primeiraFase();
void verifica(int linha, int linha2, int vetor[10]);
void imprime(int vetorCarta[10]);
void fimDoJogo();
void salvaRecordes(char nome[50], int pontuacao);
void recordes();
int comparaVetor(int vetor[10]);


int resposta[10] = { };
int cont = 0;
int pontuacao = 100;


int main(){
	system ("color 0E");
	srand(time(NULL));  	
	
	menu();
	
	return 0;
}

void menu(){
	
	int enter, valorDigitado, escolha = 1;
	system("cls");
	printf("\n\n\n\n\n\t\t\t\t=> Novo jogo ");
    printf("\n\n\t\t\t\t   Recordes  ");
    printf("\n\n\t\t\t\t   Sair  \n");
    
	while (1) {
        if (kbhit()) {
            
			valorDigitado = getch();

            if (valorDigitado == 80) { //apertou para baixo
                escolha++;
                if (escolha > 3)
                    escolha = 3;
            }
            if (valorDigitado == 72) {  //apertou para cima
                escolha--;
                if (escolha < 1)
                    escolha = 1;
            }
            
			if (valorDigitado == 13)  {  //apertou [enter]
                if (escolha == 1) {
                	system("cls");
                    primeiraFase();
                } else if (escolha == 2) {
                    system("cls");
					ranking();
					do{
						enter = getch();
					}while(enter != 13);
                    menu();
                } else if (escolha == 3){
                	system("cls");
                    printf("\n\n\t   Voce saiu do programa!!!\n\n");
                    exit(0);
				}
            }
            if (escolha == 1) {
            	system("cls");
				printf("\n\n\n\n\n\t\t\t\t=> Novo jogo ");
			    printf("\n\n\t\t\t\t   Recordes ");
			    printf("\n\n\t\t\t\t   Sair \n");
			}else if (escolha == 2) {
				system("cls");
			 	printf("\n\n\n\n\n\t\t\t\t   Novo jogo ");
			    printf("\n\n\t\t\t\t=> Recordes ");
			    printf("\n\n\t\t\t\t   Sair \n");
            }else if (escolha == 3) {
            	system("cls");
        		printf("\n\n\n\n\n\t\t\t\t   Novo jogo ");
			    printf("\n\n\t\t\t\t   Recordes ");
			    printf("\n\n\t\t\t\t=> Sair \n");    
			}
        }
    }
}

void primeiraFase(){
	
	int vetorCarta[10] = { };
 	int linha, linha2, posicao;
 	char nome[50];
	char enter;
	int vida = 3; 
	printf("\n\n\t\t\tJOGO DA MEMORIA\n");
	
	printf("\nEste programa ira gerar 5 pares de simbolos aleatorios.\n\n");
	printf("Voce deve memorizar as posicoes dos simbolos em 10 segundos.\n\n");
	printf("Pressione ENTER para iniciar: ");
	
	do{
		enter = getch();
	}while(enter != 13);
	
	do{
		printf("\n\n\nQual seu nome? ");
		gets(nome);
	}while(strlen(nome) == 0);
	
	setbuf(stdin, NULL);
	system("cls");
	
	for(int i=1; i<=5; i++){
		for(int j=0; j<2; j++){
			posicao = rand()%10;
			if(resposta[posicao] == 0 ){
				resposta[posicao] = i;
			}else{
				j--;
			}
		}
	}
	
	printf("\n\t\t Memorize a sequencia em 10 segundos! \n\n\t\t\tJOGO DA MEMORIA\n");

	printf("\n\t\t");
	for(int i =0; i<10; i++){
		printf(" %c%c%c", 201, 205, 187);
	}
	printf("\n\t\t");
	for(int i =0; i<10; i++){
		printf(" %c%c%c", 186, resposta[i], 186);
	}
	printf("\n\t\t");
	for(int i =0; i<10; i++){
		printf(" %c%c%c",200, 205, 188);
	}
	
	Sleep(10000); // milissegundo 
	while(true){
	system("cls");
	
	if(cont == 0){
		printf("\n\n\t\t\tJOGO DA MEMORIA \t\t Vidas %c %c %c\n\n", vida, vida, vida);
	}else if(cont == 1){
		printf("\n\n\t\t\tJOGO DA MEMORIA \t\t Vidas %c %c\n\n", vida, vida);
	}else {
		printf("\n\n\t\t\tJOGO DA MEMORIA \t\t Vidas %c\n\n", vida);
	}
		
		imprime(vetorCarta);
		do{
			printf("\n\n\t\t%s, Digite um numero corespondente a uma carta: ", nome);
			scanf("%d", &linha);
			if(linha > 10){
				printf("\n\t\tDesculpe! voce escolheu uma carta que nao existe");
			}
		}while(linha < 1 || linha > 10);
				
		while(vetorCarta[linha-1]){
				printf("\n\t\tCarta ja utilizada!\n\t\tEscolha uma carta diferente: ");
				scanf("%d", &linha);
		}
		
		vetorCarta[linha-1] = resposta[linha-1];
		system("cls");
		if(cont == 0){
			printf("\n\n\t\t\tJOGO DA MEMORIA \t\t Vidas %c %c %c\n\n", vida, vida, vida);
		}else if(cont == 1){
			printf("\n\n\t\t\tJOGO DA MEMORIA \t\t Vidas %c %c\n\n", vida, vida);
		}else {
			printf("\n\n\t\t\tJOGO DA MEMORIA \t\t Vidas %c\n\n", vida);
		}
		imprime(vetorCarta);
		
		do{
		
			printf("\n\n\t\t%s, Digite um numero corespondente a uma carta: ", nome);
			scanf("%d", &linha2);
			if(linha > 10){
				printf("\n\t\tDesculpe! mas voce escolheu uma carta que nao existe ");
			}
		}while(linha < 1 || linha > 10);
		
		while(vetorCarta[linha2-1]){
				printf("\n\t\tCarta ja utilizada!\n\t\tEscolha uma carta diferente: ");
				scanf("%d", &linha2);
		}	
		
		vetorCarta[linha2-1] = resposta[linha2-1];
		imprime(vetorCarta);
		Sleep(1000);
		
		verifica(linha-1,linha2-1,vetorCarta);
		if(cont > 2){
			system("cls");
			fimDoJogo();
			salvaRecordes(nome, pontuacao);	
			exit(0);
		}
		if(comparaVetor(vetorCarta)) {
			system("cls");
			salvaRecordes(nome, pontuacao);
			printf("\n\n\t   Parabens por concluir!!!\n\n");
			exit(0);
		}
	}	
}

void imprime(int vetorCarta[10]){
	printf("\n\t\t");
	
	for(int i =0; i<10; i++){
		if(i >= 9){
			printf(" %c%c%c%c", 201, 205, 205, 187);
		}else{
		printf(" %c%c%c", 201, 205, 187);
		}
	}
		
	printf("\n\t\t");
	for(int i =0; i<10; i++){
		if(vetorCarta[i] == 0){
			printf(" %c%i%c", 186, i+1, 186);			
		}else if(i == 9){
			printf(" %c%c %c", 186, vetorCarta[i], 186);	
		}else{
			printf(" %c%c%c", 186, vetorCarta[i], 186);
		}
	
	}
	
	
	printf("\n\t\t");
	for(int i =0; i<10; i++){
		if(i >= 9){
			printf(" %c%c%c%c",200, 205,205, 188);
		}else{
		printf(" %c%c%c",200, 205, 188);
		}
		
	}
}

void verifica(int linha, int linha2, int vetorCarta[10]){
	if(resposta[linha] == resposta[linha2]){
		printf("\n\t\tVoce acertou!\n");
	}else{
		cont++;
		pontuacao = pontuacao - 10;
		printf("\n\t\tVoce errou!\n");
		vetorCarta[linha] = vetorCarta[linha2] = 0;
		
	}
}

int comparaVetor(int vetorCarta[10]){
	int flag = 0;
	for(int i=0; i<10; i++){	
		if(vetorCarta[i] != resposta[i]){
			flag = 1;
			break;
		}
	}
	return (!flag)? 1 : 0;
}

void fimDoJogo(){

	printf("\a");    
	printf("\n\n\n\t\tG");
	Sleep(150);		 
	printf("A");
	Sleep(150);		 
	printf("M"); 
	Sleep(150);		
	printf("E");	
	Sleep(150);	
	printf(" ");	
	Sleep(150);	
	printf("O"); 
	Sleep(150);		
	printf("V");
	Sleep(150);		
	printf("E");
	Sleep(150);	
	printf("R");
	Sleep(150);		
	printf(" !");
	Sleep(150);	
	printf("!");
	Sleep(150);
	printf("!\n\n");	
	Sleep(150);	
	system("pause");
}

void salvaRecordes(char nome[50], int pontuacao){
	
	FILE *file;
	
	file = fopen("Recordes.txt", "a");
	
	if(file == NULL){
		printf("Arquivo nao pode ser aberto");
		getchar();
		exit(0);
	}
	fputc('\n', file);
	fputc('\t', file);
	fputc('\t', file);
	fputs(nome, file);
	fputc('\t', file);
	fputc('\t', file);
	fputc(' ', file);
		
	fprintf(file,"%i", pontuacao);
	fputc('\n', file);
	fclose(file);
}
// Ordenação de nome e pontuação 
void ordenadoRanking(int* pontuacao, char nomes[10][255], int tamanho){   
    int i;
    int trocou;
    do{
        trocou = 0;
	    for (i=tamanho; i > 0; i--){   
	        if (pontuacao[i] > pontuacao[i-1]){   
	            int pAux;
	            char nAux[255];
	            pAux = pontuacao[i];
	            strcpy(nAux, nomes[i]);
	            pontuacao[i] = pontuacao[i-1];
	            strcpy(nomes[i], nomes[i-1]);
	            pontuacao[i-1] = pAux;
	            strcpy(nomes[i-1], nAux);
	            trocou = 1;
	        }   
	    }   

    }while (trocou);
}   

void ranking(){         

    printf("\t\t RANKING DOS PARTICIPANTES\n\n");
	printf("\t\t Nome\t\t Pontuacao\n");

    FILE * pont_arq;
   
    pont_arq = fopen("Recordes.txt", "r");
   
    char nomes[10][255];
    int pontuacoes[10];
    
	char nome[255];
    int pontuacao;
    
    //qtd de pessoas
    int tamanho = 0;

    //pega os dados do arquivo
    while(fscanf(pont_arq, "%s%d", nome, &pontuacao) != EOF)// EOF indica fim do arquivo
    {   
        strcpy(nomes[tamanho],nome);
        pontuacoes[tamanho] = pontuacao;
        tamanho++;  
    }

    //Ordena
    ordenadoRanking(pontuacoes, nomes, tamanho);

    //Imprime
    for (int i=0; i<tamanho; i++)
    {
        printf("\n\n\t\t%s\t\t%d", nomes[i], pontuacoes[i]);
    }

  fclose(pont_arq);

}

