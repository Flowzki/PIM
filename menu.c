#include<stdio.h>
#include<math.h>
#include<locale.h>
#include<Windows.h>
#include<string.h>
#include<direct.h>
#include<stdlib.h>



typedef struct AtletasCadastrados{
	int idNUms;
	char nomes[100];
	char sobrenomes[100];
	char modalidades[100];
	char paises[100];
	
}AtletasCad;

typedef struct Atletas{
	int idNUm;
	char nome[100];
	char sobrenome[100];
	char modalidade[100];
	char pais[100];
	
}Atleta;


AtletasCad atletas[256];


void cadastro(int opcao)
{
	
	system("cls");

	Atleta atleta[100];
	
	FILE *atletasSalvar;
	
	int ver, confirma, i, quantAtlet;
	char sair;
	
	atletasSalvar = fopen("C:/Gestao Olimpiada/atletas.txt","a");
		
	if(opcao == 1)
	{
		
		if(atletasSalvar != NULL)
		{
		
			printf("Prencha os campos abaixo para cadastro de atleta \n\n");
			printf("Informe quantos atletas deseja cadastrar:\n");
			scanf("%d", &quantAtlet);
			
			if(quantAtlet > 0)
			{
				
				for(i=0;i<quantAtlet;i++)
				{
					printf("ID: \n");
					scanf("%d", &atleta[i].idNUm);
					
					printf("Nome: \n");
					scanf("%s", &atleta[i].nome);
					
					printf("Sobrenome: \n");
					scanf("%s", &atleta[i].sobrenome);
					
					printf("Modalidade: \n");
					scanf("%s", &atleta[i].modalidade);
					
					printf("País: \n");
					scanf("%s", &atleta[i].pais);
					
					system("cls");
					printf("Deseja visualizar as informações inseridas?\nDigite 1 para SIM e 0 para NÂO: \n");
					scanf("%d", &ver);
					
					if(ver == 1)
						{
							printf("\nOs dados informados foram: \n\n");
							printf("Id: %d \n",atleta[i].idNUm);
							printf("Nome: %s \n",atleta[i].nome);
							printf("Sobrenome: %s \n", atleta[i].sobrenome);
							printf("Modalidade: %s \n",atleta[i].modalidade);
							printf("País: %s \n",atleta[i].pais);
							
							printf("\n");
							printf("Confirma as informações?\nDigite 1 para SIM e 0 para NÂO:\n");
							scanf("%d", &confirma);
							
							if(confirma == 1)
								{   
								    if(atletasSalvar != NULL)
								    {
								    	 fprintf(atletasSalvar, "----------------Atleta------------------------\n");
								    	 fprintf(atletasSalvar, "%d \n", atleta[i].idNUm);
			     						 fprintf(atletasSalvar, "%s\n",atleta[i].nome);
			     						 fprintf(atletasSalvar, "%s\n",atleta[i].sobrenome);
			     						 fprintf(atletasSalvar, "%s\n",atleta[i].modalidade);
			     						 fprintf(atletasSalvar, "%s\n",atleta[i].pais);
			     						 fprintf(atletasSalvar, "----------------------------------------------\n");
			     						 
			     						 
			     						 system("cls");
			     						 printf("Dados salvos com sucesso!\n\n");
			     						 
			     						 	if(i+1 == quantAtlet)
												{
													sleep(2);
													fclose(atletasSalvar);
													main();	
												}		
									}
									else
									{
										 system("cls");
										 printf("Não foi possível salvar os dados!\n\n");
										 sleep(2);
										 main();
									}
							
								}
								else
									{
										 system("cls");
										 printf("Os dados não foram salvos!\n");
										 printf("Insira os dados novamente.\n\n");
										 i--;
									}
						
						
						}
						else if(ver < 0 || ver > 1)
						{
							system("cls");
							printf("Opção inválida! \n");
							sleep(2);
							main();
						}
						else
						{
							printf("\n");
							printf("Confirma as informações?\nDigite 1 para SIM e 0 para NÂO:\n");
							scanf("%d", &confirma);	
							
							if(confirma == 1)
								{   
								    if(atletasSalvar != NULL)
								    {
								    	 fprintf(atletasSalvar, "----------------Atleta------------------------\n");
								    	 fprintf(atletasSalvar, "%d \n", atleta[i].idNUm);
			     						 fprintf(atletasSalvar, "%s \n",atleta[i].nome);
			     						 fprintf(atletasSalvar, "%s\n",atleta[i].sobrenome);
			     						 fprintf(atletasSalvar, "%s\n",atleta[i].modalidade);
			     						 fprintf(atletasSalvar, "%s \n",atleta[i].pais);
			     						 fprintf(atletasSalvar, "----------------------------------------------\n");
			     						 
			     						 
			     						 system("cls");
			     						 printf("Dados salvos com sucesso!\n\n");
			     						 
			     						 
			     						 if(i+1 == quantAtlet)
											{
												sleep(2);
												fclose(atletasSalvar);
												main();	
											}	
									    
			     						 
									}
									else
									{
										 system("cls");
										 printf("Não foi possível salvar os dados!\n");
										 sleep(2);
										 main();
									}
									
								}
								else
									{
										 system("cls");
										 printf("Os dados não foram salvos!\n");
										 printf("Insira os dados novamente.\n\n");
										 i--;
									}
	     					
						}
							
							
							if(i+1 == quantAtlet)
							{
								fclose(atletasSalvar);	
							}		
					
				}
						
			}
			else
			{
				
				 system("cls");
				 printf("Insira uma quantidade maior que zero!\n");
				 sleep(2);
				 main();
									
			}
		}
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
				main();
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
  

		fopen("C:/Gestao Olimpiada/atletas.txt","a");
		fopen("C:/Gestao Olimpiada/funcionarios.txt","a");
		fopen("C:/Gestao Olimpiada/medicos.txt","a");
		fopen("C:/Gestao Olimpiada/calendario.txt","a");
		fopen("C:/Gestao Olimpiada/premiacao.txt","a");
		fopen("C:/Gestao Olimpiada/rankingMedalhas.txt","a");
		fopen("C:/Gestao Olimpiada/equipeMedica.txt","a");
     
     	menuprincipal();
	
	
	
	return 0;
}
