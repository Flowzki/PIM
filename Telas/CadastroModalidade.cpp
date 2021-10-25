#include <stdio.h>
#include <string.h>

#define SIZE 30

int opcao; //utilizado com 1 e 0 para continuar ou sair 
static int linha;
int i;

int bandeira = 0;

struct Modalidade {

	char modalidade[SIZE];
};

struct Modalidade esportes[SIZE];

void CadastroModalidade() {

	do{
		do{
			printf("Digite o nome da modalidade: ");
			scanf("%s", esportes[i].modalidade);
			
			printf("\n");
			printf("Modalidade cadastrada com sucesso!\n");
			
			i++;
			linha++;
			
			printf("\nDeseja cadastrar uma nova modalidade? Digite 1 para sim ou outro numero para sair: ");
			scanf("%d", &opcao);
			printf("\n\n");
		}while(opcao == 1);
			
				for (i = 0; i < SIZE; j++) {
				
					if (strcmp(esportes[i].modalidade, esportes[j].modalidade) == 0) {
					
						bandeira = 1;
						printf("Existem modalidades repetidas: %s\n\nFt", esportes[j].modalidade);
						break;
					}
				}
				
				if (bandeira == 1) {
				
					
					bandeira = 0;
				}
						
	}while(opcao == 1);
}

void Listagem() {

	for (int i = 0; i < linha; i++) { //Lista os atletas ate aonde dados foram registrados
	
		if (esportes[i].modalidade > 0) {
			printf("Modalidade: %s\n", esportes[i].modalidade);
			
		}	
		else {
			
			break;
		}
		
	}
}


main() {
	printf("CADASTRO DE MODALIDADE\n\n");
	CadastroModalidade();
	
	printf("Deseja ver a lista de modalidades? Digite 1 para ver e 0 para sair: ");
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
