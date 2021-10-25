#include <stdio.h>
#include <string.h>

#define SIZE 30

int i = 0;
int opcao; //utilizado com 1 e 0 para continuar ou sair 
static int linha = 0;

struct Voluntario { //Struct com os atributos

	char nome[SIZE];
	char pais[SIZE];
	char funcao[SIZE];
};

struct Voluntario pessoa[SIZE];

void CadastroVoluntario() {

	  //a variavel static nao permite que o usuario modifique o valor dentro da funcao
	 
	do{
		do{
			printf("Digite o nome do voluntario: ");
			scanf("%s", pessoa[i].nome);
			printf("Digite o pais do voluntario: ");
			scanf("%s", pessoa[i].pais);
			printf("Digite a funcao que o voluntario exerce: ");
			scanf("%s", pessoa[i].funcao);
			printf("\nDeseja confirmar as informacoes? Entre com 1 para confirmar e 0 para refazer: ");
			scanf("%d", &opcao);
			printf("\n");
			
			}while(opcao == 0);
			
			printf("Voluntario cadastrado com sucesso!\n");
			printf("\nDeseja cadastrar um novo Voluntario? Digite 1 para sim ou outro numero para sair: ");
			scanf("%d", &opcao);
			printf("\n\n");
			
			i++;
			linha++;
	}while(opcao == 1);
}

void Listagem() {

	for (int i = 0; i < linha; i++) { //Lista os atletas ate aonde dados foram registrados
	
		if (pessoa[i].nome > 0) {
			printf("Nome: %s Pais: %s Funcao: %s\n", pessoa[i].nome, pessoa[i].pais, pessoa[i].funcao);
			
		}	
		else {
			
			break;
		}
		
	}
}

main(void) {
	printf("CADASTRO DE VOLUNTARIO\n\n");
	CadastroVoluntario();
	
	printf("Deseja ver a lista de Voluntarios? Digite 1 para ver e 0 para sair: ");
	scanf("%d", &opcao);
	
	switch(opcao) {
	
		case 1:
			Listagem();
		break;
		
		case 0:
		
		break;
		
		default:
			printf("Opcao invalida!\n");
	}
}
