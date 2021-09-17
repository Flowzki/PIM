#include<stdio.h>
#include<math.h>


void cadastro(cadastros){
		
		switch(cadastros){
			case 1:
				system("cls");
				main();	
				break;
				
			case 2:
				system("cls");
				main();	
				break;
				
			case 3:
				system("cls");
				main();	
				break;
				
			case 4:
				system("cls");
				main();	
				break;
				
			default:
				printf(" Opcao invalida");
				break;					
		}
		
	}
	
void calendario(){
	printf("Calendario Olimpico \n");
}	


void premiacao(){
	printf(" Premiacao \n ");
}

int main(){
	
	int opcao, cadastros;
	
	
	
	
	
	printf("Menu principal \n \n");
	printf(" [1] Cadastrar \n [2] Calendario Olimpico \n [3] Premiacao \n [4] Relatorios \n \n");
	scanf("%d", &opcao);
	
	printf("Escolha uma das opcoes \n");
	
	switch(opcao)
	{
		case 1:
			system("cls");
			printf("\n");
			printf(" [1] Cadastro de Pessoas \n [2] Cadastro de Locais \n [3] Cadastro de Evento \n [4] Voltar \n \n ");
			printf("Escolha uma das opcoes: \n");
			scanf("%d", &cadastros);
				
			cadastro(cadastros);	
			
			break;
			
		case 2:
			system("cls");
			calendario();
		
			break;
			
		case 3:
			system("cls");
			premiacao();
			break;
		
		case 4:
			system("cls");
			printf(" [1] Ranking dos países \n [2] Ranking dos países \n [3] Resumo por atleta \n [4] Total de medalhas por categoria \n ");
			break;
		
		default:
			printf(" Digite uma opcao valida!! \n ");
			break;
	}
	
	
	
	
	return 0;
}