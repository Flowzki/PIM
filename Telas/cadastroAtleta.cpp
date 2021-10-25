#include <stdio.h>
#include <string.h>

#define SIZE 30 //define uma constante de tamanho 30

int i = 0;
static int linha = 0;
int opcao; //utilizado com 1 e 0 para continuar ou sair 

struct Atleta { //Struct com os atributos

	char nome[SIZE];
	char pais[SIZE];
	char modalidade[SIZE];
};

struct Atleta participante[SIZE]; //vetor de atletas

void Cadastro() {

	do{		//Executa o codigo enquanto a opcao for 1 e incrementa o i para mudar de linha
	
		do{ //Executa até o usuario nao quiser fazer mais cadastros
			printf("Digite o nome do atleta: ");
			scanf("%s", participante[i].nome);
			printf("Digite o pais do atleta: ");
			scanf("%s", participante[i].pais);
			printf("Digite a modalidade que o atleta disputa: ");
			scanf("%s", participante[i].modalidade);
			
			printf("\nDigite 1 para confirmar ou 0 para refazer: ");
			scanf("%d", &opcao);
			printf("\n");
			
			}while(opcao == 0);
			
			printf("\nAtleta cadastrado com sucesso!\n\n");
			
			i++;
			linha++;
			
			printf("\nDeseja cadastrar um novo atleta? Digite 1 para sim ou 0 para nao: ");
			scanf("%d", &opcao);
			printf("\n");
			
			
	}while(opcao == 1);
}
	
void Pesquisa() {
	
	char paisPesquisa[30];
	char modalidadePesquisa[30];
	
	do{
		printf("\nDigite 1 para pesquisar por pais e 2 para pesquisar por modalidade: ");
		scanf("%d", &opcao);
		
		switch(opcao) {
		
			case 1:
				printf("\nDigite o nome do pais: ");
				scanf("%s", paisPesquisa);
				
				for (int i = 0; i < SIZE; i++) { //Realiza uma pesquisa baseado nos paises ate onde tem dados
				
					if (strcmp(participante[i].pais, paisPesquisa) == 0) {
					
						printf("Nome: %s Pais: %s Modalidade: %s\n", participante[i].nome, participante[i].pais, participante[i].modalidade);
					}
				}
			break;
			
			case 2:
				printf("Digite a modalidade: ");
				scanf("%s", modalidadePesquisa);
				
				for (int i = 0; i < SIZE; i++) { //Realiza uma pesquisa baseado nas modalidades ate onde tem dados
				
					if (strcmp(participante[i].modalidade, modalidadePesquisa) == 0) {
					
						printf("Nome: %s Pais: %s Modalidade: %s\n", participante[i].nome, participante[i].pais, participante[i].modalidade);
					}
				}	
			break;
			default:
				printf("\nOpcao invalida");	
			break;
		}
		printf("\nDigite 1 para continuar pesquisando: ");
		scanf("%d", &opcao);;
		
	}while(opcao == 1);
}

void Listagem() {

	for (int i = 0; i < linha; i++) { //Lista os atletas ate aonde dados foram registrados
	
		if (participante[i].nome > 0) {
			printf("Nome: %s Pais: %s Modalidade: %s\n", participante[i].nome, participante[i].pais, participante[i].modalidade);
			
		}	
		else {
			
			break;
		}
		
	}
}

main(void) {

	printf("CADASTRO DE ATLETAS\n\n");
	Cadastro();
	
	printf("\nDeseja fazer uma pesquisa no sistema? Digite 1 para ver e 0 para continuar: ");  //Pergunta se o usuario quer fazer pesquisa
	scanf("%d", &opcao);
	
	switch(opcao) {
	
		case 1:
			printf("\nPESQUISA DE ATLETAS\n\n");	//Executa a pesquisa
			Pesquisa();
		break;
		
		case 0:
		
		break;
		
		default:
			printf("Opcao invalida!\n");
	}
	
	printf("\nDeseja fazer uma listagem dos atletas? Digite 1 para ver e 0 para finalizar: "); //Pergunta se o usuario que fazer listgem
	scanf("%d", &opcao);
	
	switch(opcao) {
	
		case 1:
			printf("\nLISTAGEM DE ATLETAS\n\n"); //Executa a listagem
			Listagem();
		break;
		
		case 0:
		
		break;
		
		default:
			printf("Opcao invalida!\n");
	}
}
	

