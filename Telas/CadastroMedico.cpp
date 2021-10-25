#include <stdio.h>
#include <string.h>

#define SIZE 30

int i = 0;
int opcao; //utilizado com 1 e 0 para continuar ou sair 
static int linha = 0;

struct Medico { //Struct com os atributos

	char nome[SIZE];
	char pais[SIZE];
	char profissao[SIZE];
};

struct Medico profissional[SIZE];

void CadastroMedico() {

	  //a variavel static nao permite que o usuario modifique o valor dentro da funcao
	 
	do{
		do{
			printf("Digite o nome do medico: ");
			scanf("%s", profissional[i].nome);
			printf("Digite o pais do medico: ");
			scanf("%s", profissional[i].pais);
			printf("Digite a profissao formar do medico: ");
			scanf("%s", profissional[i].profissao);
			printf("\nDeseja confirmar as informacoes? Entre com 1 para confirmar e 0 para refazer: ");
			scanf("%d", &opcao);
			printf("\n");
			
			}while(opcao == 0);
			
			printf("Medico cadastrado com sucesso!\n");
			printf("\nDeseja cadastrar um novo medico? Digite 1 para sim ou outro numero para sair: ");
			scanf("%d", &opcao);
			printf("\n\n");
			
			i++;
			linha++;
	}while(opcao == 1);
}

void Listagem() {

	for (int i = 0; i < linha; i++) { //Lista os atletas ate aonde dados foram registrados
	
		if (profissional[i].nome > 0) {
			printf("Nome: %s Pais: %s Profissao: %s\n", profissional[i].nome, profissional[i].pais, profissional[i].profissao);
			
		}	
		else {
			
			break;
		}
		
	}
}

main(void) {
	printf("CADASTRO DE MEDICOS\n\n");
	CadastroMedico();
	
	printf("Deseja ver a lista de Medicos? Digite 1 para ver e 0 para sair: ");
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
