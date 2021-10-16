#include<stdio.h>
#include<math.h>
#include<locale.h>
#include<Windows.h>
#include<string.h>
#include<direct.h>

void cadastro(int opcao)
{
	
	FILE *atletas;
	
	struct atlet{
		char nome[40];
		char sobrenome[40];
		char modalidade[40];
		char pais[40];
	};
	
	struct atlet atleta;
	
	int ver, confirma;
	char sair;
	
	fopen("C:\\Gestao Olimpiada/atletas.txt","a");

	if(opcao == 1)
		{
			printf("Prencha os campos abaixo para cadastro de atleta \n\n");
			
			do
			{
				printf("Nome: \n");
				scanf("%s", &atleta.nome);
				
				printf("Sobrenome: \n");
				scanf("%s", &atleta.sobrenome);
				
				printf("Modalidade: \n");
				scanf("%s", &atleta.modalidade);
				
				printf("País: \n");
				scanf("%s", &atleta.pais);
				
				system("cls");
				printf("Deseja visualizar as informações inseridas digite 1 para SIM e 0 para NÂO \n?");
				scanf("%d", &ver);
				
				if(ver == 1)
					{
						printf("Os dados informados foram \n");
						printf("Nome: %s \n",atleta.nome);
						printf("Sobrenome: %s \n", atleta.sobrenome);
						printf("Modalidade: %s \n",atleta.modalidade);
						printf("País: %s \n",atleta.pais);
						
						printf("Confirma as informações digite 1 para SIM e 0 para NÂO ? ");
						scanf("%d", &confirma);
						
					}
				else if(ver < 0 || ver > 1)
						printf("Opção inválida! \n");

				else
				{
						printf("Confirma as informações digite 1 para SIM e 0 para NÂO ? ");
						scanf("%d", &confirma);	
						
						if(confirma == 1)
							{
							
	
							    //FILE *teste = fopen("C:\\Gestao Olimpiada/atletas.txt","a");
								FILE *atletas = fopen("atletas.txt","w+");	
							    
							    if(atletas )
							    {
							    	fprintf("----------------Atleta----------------------- \n", atletas);
		     						 fprintf("Nome: %s \n",atleta.nome, atletas);
		     						 fprintf("Sobrenome: %s \n",atleta.sobrenome, atletas);
		     						 fprintf("modalidade: %s \n ",atleta.modalidade, atletas);
		     						 fprintf("Pais: %s \n",atleta.pais, atletas);
		     						 fprintf("----------------------------------------------\n", atletas);
		     						 fclose(atletas);
								}
							 
						    	
							}
							
							
     						
     					
				}
							
				
			}while(sair != 's' || sair != 'S');
			
		}
	
}


void cadastros(int cadastros){
	
	int opcaoCad;
		
		switch(cadastros){
			case 1:
				
						system("cls");
						printf("\n");
						printf(" [1] Atletas \n [2] Funcionários \n [3] Médicos \n [4] Voluntários \n [5] Equipe Olímpica \n [6] Voltar \n \n ");
						printf("Escolha uma das opcoes: \n");
						scanf("%d", &opcaoCad);
						
						if(opcaoCad == 6)
							main();
						else if(opcaoCad < 1 || opcaoCad > 6)
							{
								printf("Opção inválida!!");
								sleep(2);
								main();
							}
						else
						    cadastro(opcaoCad);
					
					
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


void menuprincipal()
{
	int opcao, cadastro;

	printf("---------------------------------------------------------------------------------------------\n");
	printf("                                   MENU PRINCIPAL \n");
	printf("---------------------------------------------------------------------------------------------\n\n");
	printf(" [1] Cadastrar \n [2] Calendario Olimpico \n [3] Premiacao \n [4] Relatorios \n \n");
	printf(" Escolha uma das opcoes \n");
	scanf("%d", &opcao);
	
	if(opcao > 0 && opcao < 5)
		{
			
				switch(opcao)
				{
					case 1:
						system("cls");
						printf("\n");
						printf(" [1] Cadastro de Pessoas \n [2] Cadastro de Locais \n [3] Cadastro de Evento \n [4] Voltar \n \n ");
						printf("Escolha uma das opcoes: \n");
						scanf("%d", &cadastro);
							
						cadastros(cadastro);	
						
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
						printf(" Digite uma opção valida!! \n ");
						break;
				}
							

		}
		else
			{
				printf("Opção inválida!");
				sleep(2);
				main();
			}
	
}

int main(char usuario[], char senha[] ){
	
	setlocale(LC_ALL, "portuguese");
	system("cls");
	
	if( _mkdir( "\\Gestao Olimpiada\\" ) == 0 )
   {
      //printf( "Directory '\\\"Gestao Olimpiada\"' was successfully created\n" );
      
	
   }
  

		fopen("C:\\Gestao Olimpiada/teste.txt","a");
     
     		menuprincipal();
	
	

	
	
	
	
	
	return 0;
}
