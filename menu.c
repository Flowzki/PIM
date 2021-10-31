#include<stdio.h>
#include<math.h>
#include<locale.h>
#include<Windows.h>
#include<string.h>
#include<direct.h>
#include<stdlib.h>


typedef struct{
	int idNUm;
	char nomes[20];
	int medalhasOuro;
	int medalhasPrata;
	int meadlhasbronze;
	
}Paises;

typedef struct{
	int idNUm;
	char modalidades[20];
	int medalhasOuro;
	int medalhasPrata;
	int meadlhasbronze;
}Modalidades;

typedef struct{
	int idNUm;
	char nome[20];
	char sobrenome[20];
	char modalidade[20];
	char pais[20];
	int medalhasOuro;
	int medalhasPrata;
	int meadlhasbronze;
	
}Atleta;

typedef struct{
	int idNUm;
	char nome[20];
	char sobrenome[20];
	char funcao[20];
}Funcionarios;

typedef struct{
	int idNUm;
	char nome[20];
	char sobrenome[20];
	char especialidade[20];
	char pais[20];
}Medicos;

typedef struct{
	int idNUm;
	char nome[20];
	char sobrenome[20];
	char funcao[20];
	char pais[20];
	
}Voluntarios;

typedef struct{
	int idNUm;
	char nome[20];
	char sobrenome[20];
	char funcao[20];
	//char modalidades[20];
	char pais[20];
	
}EquipeOlimpica;

typedef struct{
	int idNUm;
	char nome[20];
	char local[20];
	char modalidades[20];
	
}Alojamentos;

typedef struct{
	int idNUm;
	char localJogo[20];
	
}LocaisJogos;

typedef struct{
	int idNUm;
	char equipamentos[40];
}Equipamentos;


int get_size(const char* file_name)
{
    FILE *file = fopen(file_name, "r");

    if(file == NULL)
        return 0;

    fseek(file, 0, SEEK_END);
    int size = ftell(file);
    fclose(file);

    return size;
}


void cadastroAtletas(){
		
	system("cls");

	FILE *atletasSalvar;
	FILE *paises;
	FILE *modalidade;
	
	int ver, confirma, i, quantAtlet=1, size, ultPais, j, contador=0, opcaoPais, ultMod, OpMod;
	Atleta atletas;
	Paises paisess;
	Paises paise[100];
	Modalidades modalidades[100];
	Modalidades mods;
	int ultimoId=0;
	
	char nomeArqu[40] = "C:/Gestao Olimpiada/atletas.txt";
	char pais[40] = "C:/Gestao Olimpiada/paises.txt";
	char modal[40] = "C:/Gestao Olimpiada/modalidades.txt";
	
	
	
	atletasSalvar = fopen(nomeArqu,"a+");
	
		if(get_size(modal)==0)
		{
			printf("Nenhuma modalidade cadastrada!!\n");
			sleep(2);
			main();
		}
		else
		{
			
			modalidade = fopen(modal, "r");
			fseek(modalidade, -1*sizeof(Modalidades),SEEK_END);//saltar do final do arquivo (SEEK_END) para o inicio do ultimo registro
  			fread(&mods, sizeof(Modalidades), 1, modalidade); //ler o ultimo registro
  			ultMod = mods.idNUm;
  				
  				//printf ("id = %d ", ultPais); 
  				
			rewind(modalidade);
		
			while(!feof(modalidade))
				{
					fread(&mods, sizeof(Modalidades),1,modalidade);
					modalidades[contador] = mods;
					contador++;
				}
				
				fclose(modalidade);
		}
		
	
		contador = 0;

		if(get_size(pais)==0)
		{
			printf("Nenhum pais cadastrado!!\n");
			sleep(2);
			main();
		}
		else
		{
			
			paises = fopen(pais, "r");
			fseek(paises, -1*sizeof(Paises),SEEK_END);//saltar do final do arquivo (SEEK_END) para o inicio do ultimo registro
  			fread(&paisess, sizeof(Paises), 1, paises); //ler o ultimo registro
  			ultPais = paisess.idNUm;
  				
  				//printf ("id = %d ", ultPais); 
  				
			rewind(paises);
		
			while(!feof(paises))
				{
					fread(&paisess, sizeof(Paises),1,paises);
					paise[contador] = paisess;
					contador++;
				}
				
				fclose(paises);
		}


		if(atletasSalvar != NULL)
		{
		
		 	/*printf("Entre com id para modificar:");
    	 	scanf("%d",&idBusca)
			
			fseek(atletasSalvar, (idBusca-1)*sizeof(Atleta),SEEK_CUR);
   			fread(&atletas, sizeof(Atleta), 1, atletasSalvar);  
   			printf ("id = %d nome = %s %s\n", atletas.idNUm, atletas.nome, atletas.sobrenome); 
		*/
		/*	printf("Prencha os campos abaixo para cadastro de atleta \n\n");
			printf("Informe quantos atletas deseja cadastrar:\n");
			scanf("%d", &quantAtlet);*/
			
			Atleta atleta[quantAtlet];
			
		    memset(atleta, 0, (size_t)quantAtlet * sizeof(atleta));
			
			//if(quantAtlet > 0)
			//{
				
				if(get_size(nomeArqu) == 0)
				{
  				  ultimoId = 0;
				}
				else		
				{
					fseek(atletasSalvar, -1*sizeof(Atleta),SEEK_END);//saltar do final do arquivo (SEEK_END) para o inicio do ultimo registro
   				 	fread(&atletas, sizeof(Atleta), 1, atletasSalvar); //ler o ultimo registro
   					ultimoId = atletas.idNUm;
				
				 	//printf ("id = %d ", ultimoId); 
				}
				
			
				
				for(i=0;i<quantAtlet;i++)
				{
					/*printf("ID: \n");
					scanf("%d", &atleta[i].idNUm);*/
					
					atleta[i].idNUm = ultimoId+1;
					
					printf("Nome: \n");
					scanf("%s", &atleta[i].nome);
					
					printf("Sobrenome: \n");
					scanf("%s", &atleta[i].sobrenome);
					
					contador = 0;
					
					printf("Modalidade: \n\n");
					
					while(contador<ultMod)
					{	
						printf("[%d] %s\n", contador+1, modalidades[contador].modalidades);
						contador++;
						
					}
					
					printf("\n");
					printf("Escolha uma modalidade:\n");	
					scanf("%d", &OpMod);
					
					if(OpMod > 0 && OpMod <= ultMod)
					{
						strcpy(atleta[i].modalidade , modalidades[OpMod-1].modalidades);
					}
					else{
						printf("Opção inválida!!\n");
						sleep(2);
						main();
						/*system("cls");
						printf("Entre novamente com os dados.\n");
						i--;*/
					}
					
					printf("\n");	
					printf("País:\n\n");
					
					j=0;
					
					while(j<ultPais){
						printf("[%d] %s\n", j+1, paise[j].nomes);
						j++;
						
					}
					
					printf("\n");
					printf("Escolha um país:\n");	
					scanf("%d", &opcaoPais);
					
					if(opcaoPais > 0 && opcaoPais <= ultPais)
					{
						strcpy(atleta[i].pais , paise[opcaoPais-1].nomes);
					}
					else{
						printf("Opção inválida!!\n");
						sleep(2);
						main();
						system("cls");
						/*printf("Entre novamente com os dados.\n");
						i--;*/
					}
						
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
								    	fseek(atletasSalvar,0,SEEK_END);
								    	fwrite(&atleta, sizeof(Atleta), 1, atletasSalvar);
								    	
								    	/* fprintf(atletasSalvar, "----------------Atleta------------------------\n");
								    	 fprintf(atletasSalvar, "%d \n", atleta[i].idNUm);
			     						 fprintf(atletasSalvar, "%s\n",atleta[i].nome);
			     						 fprintf(atletasSalvar, "%s\n",atleta[i].sobrenome);
			     						 fprintf(atletasSalvar, "%s\n",atleta[i].modalidade);
			     						 fprintf(atletasSalvar, "%s\n",atleta[i].pais);
			     						 fprintf(atletasSalvar, "----------------------------------------------\n");*/
			     						 
			     						 
			     						 system("cls");
			     						 printf("Dados salvos com sucesso!\n\n");
										 sleep(2);
										 fclose(atletasSalvar);
										 main();	
														
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
								    	 /*fprintf(atletasSalvar, "----------------Atleta------------------------\n");
								    	 fprintf(atletasSalvar, "%d \n", atleta[i].idNUm);
			     						 fprintf(atletasSalvar, "%s \n",atleta[i].nome);
			     						 fprintf(atletasSalvar, "%s\n",atleta[i].sobrenome);
			     						 fprintf(atletasSalvar, "%s\n",atleta[i].modalidade);
			     						 fprintf(atletasSalvar, "%s \n",atleta[i].pais);
			     						 fprintf(atletasSalvar, "----------------------------------------------\n");*/
			     						 
			     						 fseek(atletasSalvar,0,SEEK_END);
			     						 fwrite(&atleta, sizeof(Atleta), 1, atletasSalvar);
			     						 
			     						 system("cls");
			     						 printf("Dados salvos com sucesso!\n\n");
										 sleep(2);
										 fclose(atletasSalvar);
										main();	
												
									    
			     						 
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
							
							
							if(i == quantAtlet)
							{
								fclose(atletasSalvar);	
								main();
							}		
					
				}
						
		//	}
			/*else
			{
				
				 system("cls");
				 printf("Insira uma quantidade maior que zero!\n");
				 sleep(2);
				 main();
									
			}*/
		}
	
	
}


void cadastroFuncionarios(){
	system("cls");
	
	FILE *funcionarios;
	int i, quant=1, confirma, ver, ultimoid, contador=0, j;
	char caminho[40] = "C:/Gestao Olimpiada/funcionarios.txt";
	
	funcionarios = fopen(caminho, "a+");
	
	Funcionarios funcionario[quant];
	Funcionarios funcio;
	
	 memset(funcionario, 0, (size_t)quant * sizeof(funcionario));
	
	
	if(funcionarios != NULL)
	{
		
		if(get_size(caminho) == 0)
		{
  		  ultimoid = 0;
		}
		else		
		{
			fseek(funcionarios, -1*sizeof(Funcionarios),SEEK_END);//saltar do final do arquivo (SEEK_END) para o inicio do ultimo registro
  			fread(&funcio, sizeof(Funcionarios), 1, funcionarios); //ler o ultimo registro
  			ultimoid = funcio.idNUm;
  			
  			//printf("Id = %d \n", ultimoid);
  			
		}	
		
		
		for(i=0;i<quant;i++)
		{
					
			funcionario[i].idNUm = ultimoid+1;
			
			printf("insira o nome:\n");
			scanf("%s", &funcionario[i].nome);
			
			printf("insira o sobrenome:\n");
			scanf("%s", &funcionario[i].sobrenome);
			
			printf("insira a funcao:\n");
			scanf("%s", &funcionario[i].funcao);
			
			printf("\n");
			
			if(i+1 == quant){
				printf("Deseja visualizar os dados informados ?\nDigite 1 para SIM e 0 para NÂO:\n");
				scanf("%d", &ver);
				
				if(ver == 1){
					j = 0;
					
					while(j < quant){
						printf("Id: %d \n", funcionario[j].idNUm);
						printf("Nome: %s \n", funcionario[j].nome);
						printf("Sobrenome: %s \n", funcionario[j].sobrenome);
						printf("Função: %s\n", funcionario[j].funcao);
						j++;
					}
					
					printf("\n");
					printf("Confirma as informações ?\nDigite 1 para SIM e 0 para NÂO:\n");
					scanf("%d", &confirma);
					
					if(confirma == 1)
					{
						fseek(funcionarios, 0, SEEK_END);
						fwrite(&funcionario, sizeof(Funcionarios), 1, funcionarios);
						system("cls");
						printf("Dados salvos com sucesso!!\n");
						fclose(funcionarios);
						sleep(2);	
						main();
							
						
					}
					else{
						printf("Os dados não foram salvos!!\n");
						sleep(2);
						system("cls");
						printf("Entre novamente com os dados.\n");
						i--;
						
					}
					
				}
				else{
					printf("Confirma as informações ?\nDigite 1 para SIM e 0 para NÂO:\n");
					scanf("%d", &confirma);
					
					if(confirma == 1)
					{
						fseek(funcionarios, 0, SEEK_END);
						fwrite(&funcionario, sizeof(Funcionarios), 1, funcionarios);
						system("cls");
						printf("Dados salvos com sucesso!!\n");
						fclose(funcionarios);
						sleep(2);	
						main();	
					}
					else{
						printf("Os dados não foram salvos!!\n");
						fclose(funcionarios);
						sleep(2);
						main();
						}
					}
				}
				
				
			}	
		}	
	
	
	
	
}


void cadastroMedicos(){
	system("cls");
	
	FILE *medicos;
	FILE *paises;
	int i=0, quant=1, confirma, ver, ultimoid=0, contador=0, j=0, opcaoPais, ultPais;
	char caminho[40] = "C:/Gestao Olimpiada/medicos.txt";
	char pais[40] = "C:/Gestao Olimpiada/paises.txt";
	char nomes[40][15];
	char nome[40];
	Paises paisess;
	Paises paise[100];
	
	medicos = fopen(caminho, "a+");
	
	Medicos medico[quant];
	Medicos med;
	
	 memset(medico, 0, (size_t)quant * sizeof(medico));
	
		if(get_size(pais)==0)
		{
			printf("Nenhum pais cadastrado!!\n");
			sleep(2);
			main();
		}
		else
		{
			
			paises = fopen(pais, "r");
			fseek(paises, -1*sizeof(Paises),SEEK_END);
  			fread(&paisess, sizeof(Paises), 1, paises); 
  			ultPais = paisess.idNUm;
  				
  				
			rewind(paises);
		
			while(!feof(paises))
				{
					fread(&paisess, sizeof(Paises),1,paises);
					paise[contador] = paisess;
					contador++;
				}
				
				fclose(paises);
		}
	
		
	if(medicos != NULL)
	{
		if(get_size(caminho) == 0)
		{
  		  ultimoid = 0;
		}
		else		
		{
			fseek(medicos, -1*sizeof(Medicos),SEEK_END);//saltar do final do arquivo (SEEK_END) para o inicio do ultimo registro
  			fread(&med, sizeof(Medicos), 1, medicos); //ler o ultimo registro
  			ultimoid = med.idNUm;
		}
		
		for(i=0;i<quant;i++)
		{
			
			int vol = 0, compara=0;
			
			medico[i].idNUm = ultimoid+1;
			
			printf("insira o nome:\n");
			scanf("%s", &medico[i].nome);
			
			printf("insira o sobrenome:\n");
			scanf("%s", &medico[i].sobrenome);
			
			printf("insira a especialidade:\n");
			scanf("%s", &medico[i].especialidade);
				
			
			printf("\n");	
			printf("País:\n\n");
			
			j=0;
			
			while(j<ultPais){
				printf("[%d] %s\n", j+1, paise[j].nomes);
				j++;
				
			}
			
			printf("\n");
			printf("Escolha um país:\n");	
			scanf("%d", &opcaoPais);
			
			if(opcaoPais > 0 && opcaoPais <= ultPais)
			{
				strcpy(medico[i].pais , paise[opcaoPais-1].nomes);
			}
			else
			{
				printf("Opção inválida!!\n");
				sleep(2);
				system("cls");
				printf("Entre novamente com os dados.\n");
				i--;
			}
			
			
			if(i+1 == quant)
			{
				printf("Deseja visualizar os dados informados ?\nDigite 1 para SIM e 0 para NÂO:\n");
				scanf("%d", &ver);
				
				if(ver == 1)
				{
					int j = 0;
					
					while(j < quant)
					{
						printf("Id: %d \n", medico[j].idNUm);
						printf("Nome: %s \n", medico[j].nome);
						printf("Sobrenome: %s \n", medico[j].sobrenome);
						printf("Especialidade: %s\n", medico[j].especialidade);
						printf("Pais: %s \n\n", medico[j].pais);
						j++;
					}
					
					
					printf("Confirma as informações ?\nDigite 1 para SIM e 0 para NÂO:\n");
					scanf("%d", &confirma);
					
					if(confirma == 1)
					{
						fseek(medicos, 0, SEEK_END);
						fwrite(&medico, sizeof(Medicos), 1, medicos);
						system("cls");
						printf("Dados salvos com sucesso!!\n");
						fclose(medicos);
						sleep(2);
						main();
						
					}
					else
					{
						printf("Os dados não foram salvos!!\n");
						sleep(2);
						system("cls");
						printf("Entre novamente com os dados.\n");
						i--;
						
					}
					
				}
				else
				{
					printf("Confirma as informações ?\nDigite 1 para SIM e 0 para NÂO:\n");
					scanf("%d", &confirma);
					
					if(confirma == 1)
					{
						fseek(medicos, 0, SEEK_END);
						fwrite(&medico, sizeof(Medicos), 1, medicos);
						system("cls");
						printf("Dados salvos com sucesso!!\n");
						fclose(medicos);
						sleep(2);
						main();
						
					}
					else
					{
						printf("Os dados não foram salvos!!\n");
						fclose(medicos);
						sleep(2);
						main();
					}	
				 }
			}		
		}	
	}		
	
}


void cadastroVoluntarios(){
	system("cls");
	
	FILE *voluntarios;
	FILE *paises;
	int i, quant=1, confirma, ver, ultimoid=0, contador=0, j=0, opcaoPais, ultPais;
	char caminho[40] = "C:/Gestao Olimpiada/voluntarios.txt";
	char pais[40] = "C:/Gestao Olimpiada/paises.txt";
	char nomes[40][15];
	char nome[40];
	Paises paisess;
	Paises paise[100];
	
	voluntarios = fopen(caminho, "a+");
	
	Voluntarios voluntario[quant];
	Voluntarios volum;
	
	 memset(voluntario, 0, (size_t)quant * sizeof(voluntario));
	
	
		if(get_size(pais)==0)
		{
			printf("Nenhum pais cadastrado!!\n");
			sleep(2);
			main();
		}
		else
		{
			
			paises = fopen(pais, "r");
			fseek(paises, -1*sizeof(Paises),SEEK_END);
  			fread(&paisess, sizeof(Paises), 1, paises); 
  			ultPais = paisess.idNUm;
  				
  				
			rewind(paises);
		
			while(!feof(paises))
				{
					fread(&paisess, sizeof(Paises),1,paises);
					paise[contador] = paisess;
					contador++;
				}
				
				fclose(paises);
		}
	
		
	if(voluntarios != NULL)
	{
		if(get_size(caminho) == 0)
		{
  		  ultimoid = 0;
		}
		else		
		{
			fseek(voluntarios, -1*sizeof(Voluntarios),SEEK_END);//saltar do final do arquivo (SEEK_END) para o inicio do ultimo registro
  			fread(&volum, sizeof(Voluntarios), 1, voluntarios); //ler o ultimo registro
  			ultimoid = volum.idNUm;
		}
		
		for(i=0;i<quant;i++)
		{
			
			int vol = 0, compara=0;
			
			voluntario[i].idNUm = ultimoid+1;
			
			printf("insira o nome:\n");
			scanf("%s", &voluntario[i].nome);
			
			printf("insira o sobrenome:\n");
			scanf("%s", &voluntario[i].sobrenome);
			
			printf("insira a funcao:\n");
			scanf("%s", &voluntario[i].funcao);
				
			
			printf("\n");	
			printf("País:\n\n");
			
			j=0;
			
			while(j<ultPais){
				printf("[%d] %s\n", j+1, paise[j].nomes);
				j++;
				
			}
			
			printf("\n");
			printf("Escolha um país:\n");	
			scanf("%d", &opcaoPais);
			
			if(opcaoPais > 0 && opcaoPais <= ultPais)
			{
				strcpy(voluntario[i].pais , paise[opcaoPais-1].nomes);
			}
			else
			{
				printf("Opção inválida!!\n");
				sleep(2);
				//main();
				system("cls");
				printf("Entre novamente com os dados.\n");
				i--;
			}
			
			
			if(i+1 == quant)
			{
				printf("Deseja visualizar os dados informados ?\nDigite 1 para SIM e 0 para NÂO:\n");
				scanf("%d", &ver);
				
				if(ver == 1)
				{
					int j = 0;
					
					while(j < quant)
					{
						printf("Id: %d \n", voluntario[j].idNUm);
						printf("Nome: %s \n", voluntario[j].nome);
						printf("Sobrenome: %s \n", voluntario[j].sobrenome);
						printf("Função: %s\n", voluntario[j].funcao);
						printf("Pais: %s \n\n", voluntario[j].pais);
						j++;
					}
					
					
					printf("Confirma as informações ?\nDigite 1 para SIM e 0 para NÂO:\n");
					scanf("%d", &confirma);
					
					if(confirma == 1)
					{
						fseek(voluntarios, 0, SEEK_END);
						fwrite(&voluntario, sizeof(Voluntarios), 1, voluntarios);
						system("cls");
						printf("Dados salvos com sucesso!!\n");
						fclose(voluntarios);
						sleep(2);
						main();
						
					}
					else
					{
						printf("Os dados não foram salvos!!\n");
						sleep(2);
						system("cls");
						printf("Entre novamente com os dados.\n");
						i--;
						
					}
					
				}
				else
				{
					printf("Confirma as informações ?\nDigite 1 para SIM e 0 para NÂO:\n");
					scanf("%d", &confirma);
					
					if(confirma == 1)
					{
						fseek(voluntarios, 0, SEEK_END);
						fwrite(&voluntario, sizeof(Voluntarios), 1, voluntarios);
						system("cls");
						printf("Dados salvos com sucesso!!\n");
						fclose(voluntarios);
						sleep(2);
						main();
						
					}
					else
					{
						printf("Os dados não foram salvos!!\n");
						fclose(voluntarios);
						sleep(2);
						main();
					}	
				 }
			}		
		}	
	}		
}


void cadastroEquip(){
	system("cls");
	
	FILE *equipes;
	FILE *paises;
	int i=0, quant=1, confirma, ver, ultimoid=0, contador=0, j, opcaoPais, ultPais, ids, continuar;
	char caminho[40] = "C:/Gestao Olimpiada/equipes.txt";
	char pais[40] = "C:/Gestao Olimpiada/paises.txt";
	Paises paisess;
	Paises paise[100];
	
	equipes = fopen(caminho, "a+");
	
	EquipeOlimpica equip;
	EquipeOlimpica equipe[quant];
	memset(equipe, 0, (size_t)quant * sizeof(equipe));
	
	
		if(get_size(pais)==0)
		{
			printf("Nenhum pais cadastrado!!\n");
			sleep(2);
			main();
		}
		else
		{
			
			paises = fopen(pais, "r");
			fseek(paises, -1*sizeof(Paises),SEEK_END);
  			fread(&paisess, sizeof(Paises), 1, paises); 
  			ultPais = paisess.idNUm;
  				
  				
			rewind(paises);
		
			while(!feof(paises))
				{
					fread(&paisess, sizeof(Paises),1,paises);
					paise[contador] = paisess;
					contador++;
				}
				
				fclose(paises);
		}
	
		
	if(equipes != NULL)
	{
		if(get_size(caminho) == 0)
		{
  		  ultimoid = 0;
		}
		else		
		{
			fseek(equipes, -1*sizeof(EquipeOlimpica),SEEK_END);//saltar do final do arquivo (SEEK_END) para o inicio do ultimo registro
  			fread(&equip, sizeof(EquipeOlimpica), 1, equipes); //ler o ultimo registro
  			ultimoid = equip.idNUm;
		}
			
	
		
		
		for(i=0;i<quant;i++)
		{
			
			//system("cls");
			
			int vol = 0, compara=0;
			
			equipe[i].idNUm = ultimoid+1;
			
			printf("insira o nome:\n");
			scanf("%s", &equipe[i].nome);
			
			printf("insira o sobrenome:\n");
			scanf("%s", &equipe[i].sobrenome);
			
			printf("Insira a funcao:\n");
			scanf("%s", &equipe[i].funcao);
				
			
			printf("\n");	
			printf("País:\n\n");
			
			j=0;
			
			while(ultPais>j){
				printf("[%d] %s\n", j+1, paise[j].nomes);
				j++;
				
			}
			
			printf("\n");
			printf("Escolha um país:\n");	
			scanf("%d", &opcaoPais);
			
			if(opcaoPais > 0 && opcaoPais <= ultPais)
			{
				strcpy(equipe[i].pais , paise[opcaoPais-1].nomes);
			}
			else
			{
				printf("Opção inválida!!\n");
				sleep(2);
				system("cls");
				printf("Entre novamente com os dados.\n");
				i--;
			}
			
			if(i+1 == quant)
			{
				printf("Deseja visualizar os dados informados ?\nDigite 1 para SIM e 0 para NÂO:\n");
				scanf("%d", &ver);
				
				if(ver == 1)
				{
						printf("Id: %d \n", equipe[i].idNUm);
						printf("Nome: %s \n", equipe[i].nome);
						printf("Sobrenome: %s \n", equipe[i].sobrenome);
						printf("Função: %s\n", equipe[i].funcao);
						printf("Pais: %s \n\n", equipe[i].pais);
					
					printf("Confirma as informações ?\nDigite 1 para SIM e 0 para NÂO:\n");
					scanf("%d", &confirma);
					
					if(confirma == 1)
					{
						fseek(equipes, 0, SEEK_END);
						fwrite(&equipe, sizeof(EquipeOlimpica), 1, equipes);
						system("cls");
						printf("Dados salvos com sucesso!!\n\n");
						fclose(equipes);
						sleep(2);
						main();	
					}
					else
					{
						printf("Os dados não foram salvos!!\n");
						sleep(2);
						system("cls");
						printf("Entre novamente com os dados.\n");
						i--;
						
					}
					
				}
				else
				{
					printf("Confirma as informações ?\nDigite 1 para SIM e 0 para NÂO:\n");
					scanf("%d", &confirma);
					
					if(confirma == 1)
					{
						fseek(equipes, 0, SEEK_END);
						fwrite(&equipe, sizeof(EquipeOlimpica), 1, equipes);
						system("cls");
						printf("Dados salvos com sucesso!!\n");
						fclose(equipes);
						sleep(2);
						main();	
						
					}
					else
					{
						printf("Os dados não foram salvos!!\n");
						fclose(equipes);
						sleep(2);
						main();
					}	
				 }
			}
			
					
		}	
	}		
	
	
}


void paises(){
	
	system("cls");
	
	FILE *paises;
	int i, quant=1, confirma, ver, ultimoid=0, contador=0, j=0;
	char caminho[40] = "C:/Gestao Olimpiada/paises.txt";
	char nomes[40][15];
	char nome[40];
	
	paises = fopen(caminho, "a+");
	
	
	
	//printf("Informe quantos países deseja cadastrar:\n");
	//scanf("%d", &quant);
	
	Paises pais[quant];
	Paises paise;
	Paises Paisescadastrados[100];
	
	 memset(pais, 0, (size_t)quant * sizeof(pais));
		
	if(paises != NULL)
	{
		if(get_size(caminho) == 0)
		{
  		  ultimoid = 0;
		}
		else		
		{
			fseek(paises, -1*sizeof(Paises),SEEK_END);//saltar do final do arquivo (SEEK_END) para o inicio do ultimo registro
  			fread(&paise, sizeof(Paises), 1, paises); //ler o ultimo registro
  			ultimoid = paise.idNUm;
  				
  				
  			rewind(paises);
  	
	 		while(!feof(paises))
		  	{
				fread(&paise, sizeof(Paises), 1, paises);
				Paisescadastrados[contador] = paise;
				contador++;			
			}
		
			while(j<=ultimoid)
			{
				strcpy(nomes[j], Paisescadastrados[j].nomes);
				j++;
			}
				
			//	printf ("id = %d ", ultimoid); 
		}
		
		for(i=0;i<quant;i++)
		{
			
			int pai = 0, compara=0;
			
			pais[i].idNUm = ultimoid+1;
			
			printf("insira o nome do país:\n");
			scanf("%s", &nome);
			
			for(pai=0;pai<=ultimoid;pai++)
			{
				compara = strcmp(nome, nomes[pai]);
			}
			
			if(compara == 0)
			{
				system("cls");
				printf("País já cadastrado.\n");
				sleep(2);
				main();
			}
			else{
				strcpy(pais[i].nomes, nome);
			}
			
			if(i+1 == quant){
				printf("Deseja visualizar o nome informado ?\nDigite 1 para SIM e 0 para NÂO:\n");
				scanf("%d", &ver);
				
				if(ver == 1){
					int j = 0;
					
					while(j < quant){
						printf("Id: %d \n", pais[j].idNUm);
						printf("Pais: %s \n\n", pais[j].nomes);
						j++;
					}
					
					
					printf("Confirma as informações ? \nDigite 1 para SIM e 0 para NÂO:\n");
					scanf("%d", &confirma);
					
					if(confirma == 1)
					{
						fseek(paises, 0, SEEK_END);
						fwrite(&pais, sizeof(Paises), 1, paises);
						printf("Dados salvos com sucesso!!\n");
						fclose(paises);
						sleep(2);
						main();
					}
					else{
						printf("Os dados não foram salvos!!\n");
						sleep(2);
						system("cls");
						printf("Entre novamente com os dados.\n");
						i--;
						
					}
					
				}
				else{
					printf("Confirma as informações ? \nDigite 1 para SIM e 0 para NÂO:\n");
					scanf("%d", &confirma);
					
					if(confirma == 1)
					{
						fseek(paises, 0, SEEK_END);
						fwrite(&pais, sizeof(Paises), 1, paises);
						fclose(paises);
					}
					else{
						printf("Os dados não foram salvos!!\n");
						fclose(paises);
						sleep(2);
						main();
						}
					}
				}
			}		
		}		
/*	}
	else{
		printf("Quantidade deve ser maior que zero.\n");
		sleep(2);
		main();
	}*/
}

void modalidades(){
	FILE *modalidade;
	int i, quant=1, confirma, ver, ultimoid=0, contador=0, j=0;
	char caminho[40] = "C:/Gestao Olimpiada/modalidades.txt";
	char modal[40][15];
	char modali[40];
	
	modalidade = fopen(caminho, "a+");
	
	
	
	/*printf("Informe quantas modalidades deseja cadastrar:\n");
	scanf("%d", &quant);*/
	
	Modalidades modalidades[quant];
	Modalidades mod;
	Modalidades mods[100];
	
	 memset(modalidades, 0, (size_t)quant * sizeof(modalidades));
	 memset(mods, 0, (size_t)100 * sizeof(modalidades));
	
	
	if(modalidade != NULL)
	{
		
		if(get_size(caminho) == 0)
		{
  		  ultimoid = 0;
		}
		else		
		{
			fseek(modalidade, -1*sizeof(Modalidades),SEEK_END);//saltar do final do arquivo (SEEK_END) para o inicio do ultimo registro
  			fread(&mod, sizeof(Modalidades), 1, modalidade); //ler o ultimo registro
  			ultimoid = mod.idNUm;
  			
  			rewind(modalidade);
  			
  			while(!feof(modalidade))
			  {
				fread(&mod, sizeof(Modalidades), 1, modalidade);
				mods[contador] = mod;
				contador++;	
				
							
						
			}
			
			while(j<=ultimoid)
			{
				strcpy(modal[j], mods[j].modalidades);
				j++;
			}
  			
  			
  			
		 	printf ("id = %d ", ultimoid); 
		}
		
		for(i=0;i<quant;i++)
		{
			
			int modalid = 0, compara=0;
			
			modalidades[i].idNUm = ultimoid+1;
			
			printf("insira o nome da modalidade:\n");
			scanf("%s", &modali);
			
			for(modalid=0;modalid<=ultimoid;modalid++)
			{
				compara = strcmp(modali, modal[modalid]);
			}
			
			if(compara == 0){
				system("cls");
				printf("Modalidade já cadastrada.\n");
				sleep(2);
				main();
			}
			else{
				strcpy(modalidades[i].modalidades, modali);
			}
			
			
			if(i+1 == quant)
			{
				printf("Deseja visualizar o nome informado ?\nDigite 1 para SIM e 0 para NÂO:\n");
				scanf("%d", &ver);
				
				if(ver == 1){
					
					j = 0;
					
					while(j < quant){
						printf("Id: %d \n", modalidades[j].idNUm);
						printf("Modalidade: %s \n\n", modalidades[j].modalidades);
						j++;
					}
					
				
					
					printf("Confirma as informações ? \nDigite 1 para SIM e 0 para NÂO:\n");
					scanf("%d", &confirma);
					
					if(confirma == 1)
					{
						fseek(modalidade, 0, SEEK_END);
						fwrite(&modalidades, sizeof(Modalidades), 1, modalidade);
						fclose(modalidade);
						printf("Dados salvos com sucesso!!\n");
						sleep(2);
						main();
					}
					else{
						printf("Os dados não foram salvos!!\n");
						sleep(2);
						system("cls");
						printf("Entre novamente com os dados.\n");
						i--;
						
					}
					
				}
				else
				{
					printf("Confirma as informações ? \nDigite 1 para SIM e 0 para NÂO:\n");
					scanf("%d", &confirma);
					
					if(confirma == 1)
					{
						fseek(modalidade, 0, SEEK_END);
						fwrite(&modalidades, sizeof(Modalidades), 1, modalidade);
						printf("Dados salvos com sucesso!!\n");
						fclose(modalidade);
					}
					else
					{
						printf("Os dados não foram salvos!!\n");
						fclose(modalidade);
						sleep(2);
						main();
					}
					
				}
			}
		}
	}
}

void alojamentos(){
}


void cadastro(int opcao){
	
	switch(opcao)
	{
		case 1:
			cadastroAtletas();
			break;	
		case 2:
			cadastroFuncionarios();
			break;
		case 3:
			cadastroMedicos();
			break;
		case 4:
			cadastroVoluntarios();
			break;			
		case 5:
			cadastroEquip();
			break;
		default:
			printf("Opção invalida!!\n");
			sleep(2);
			main();	
						
	}
		
}

void locaisJogos(){
}

void centroTreinamento(){
	
}

void cadastros(int cadastros){
	
	int opcaoCad;
		
		switch(cadastros){
			case 1:
				
						system("cls");
						printf("---------------------------------------------------------------------------------------------\n");
						printf("                                   CADASTROS \n");
						printf("---------------------------------------------------------------------------------------------\n\n");
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
				paises();		
				break;
				
			case 3:
				system("cls");
				modalidades();
				break;
				
			case 4:
				system("cls");
				alojamentos();
				break;
				
			case 5:
				system("cls");
				modalidades();
				break;	
					
			case 6:
				system("cls");
				locaisJogos();
				break;
			
			case 7:
				system("cls");
				centroTreinamento();
				break;		
						
			default:
				printf(" Opcao invalida");
				main();
				break;					
		}
		
	}
	
void calendario(){
	printf("Calendario Olimpico \n");
	sleep(4);
	main();
}	


void premiacao(){
	printf("Premiacao \n ");
	sleep(4);
	main();
}


void menuRelatorios(int opcao){
	system("cls");
	printf("Relatórios.\n");
	sleep(3);
	main();
}

void menuprincipal()
{
	int opcao, cadastro, relatorios;

	printf("---------------------------------------------------------------------------------------------\n");
	printf("                                   MENU PRINCIPAL \n");
	printf("---------------------------------------------------------------------------------------------\n\n");
	printf(" [1] Cadastros \n [2] Calendario Olimpico \n [3] Premiacao \n [4] Relatorios \n \n");
	printf(" Escolha uma das opcoes \n");
	scanf("%d", &opcao);
	
	if(opcao > 0 && opcao < 5)
		{
			
				switch(opcao)
				{
					case 1:
						system("cls");
						printf("---------------------------------------------------------------------------------------------\n");
						printf("                                   CADASTROS \n");
						printf("---------------------------------------------------------------------------------------------\n\n");
						printf(" [1] Cadastro de Pessoas \n [2] Paises \n [3] Modalidades \n [4] Alojamentos\n [5] Locais de Jogos\n [6] Equipamentos \n [7] Centro de treinamento\n [8] Voltar \n\n");
						printf(" Escolha uma das opcoes: \n");
						scanf("%d", &cadastro);
						
						if(cadastro > 0 && cadastro < 8 )
							cadastros(cadastro);	
						else if(cadastro == 8)
						{
							//sleep(1);
							main();
						}
						else{
							printf("Opção inválida!!\n");
							sleep(2);
							main();
						}
							
						
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
						printf("---------------------------------------------------------------------------------------------\n");
						printf("                                   RELATORIOS \n");
						printf("---------------------------------------------------------------------------------------------\n\n");
						printf(" [1] Ranking dos países \n [2] Resumo por atleta \n [3] Total de medalhas por categoria \n [4] Voltar\n\n");
						printf("Escolha uma opção:\n");
						scanf("%d", &relatorios);
						
						if(relatorios > 0 && relatorios < 4)
							menuRelatorios(relatorios);
						else if(relatorios == 4)
							main();
						else
						{
							printf("Opção inválida.\n");
							sleep(2);
							main();	
						}
							
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
	
	//ICON "/logo.ico";
	
	setlocale(LC_ALL, "portuguese");
	system("cls");
	

	
	if( _mkdir( "C:/Gestao Olimpiada" ) == 0 )
   {
      //printf( "Directory '\\\"Gestao Olimpiada\"' was successfully created\n" );
      
	
   }
  

		/*fopen("C:/Gestao Olimpiada/atletas.txt","a");
		fopen("C:/Gestao Olimpiada/funcionarios.txt","a");
		fopen("C:/Gestao Olimpiada/medicos.txt","a");
		fopen("C:/Gestao Olimpiada/calendario.txt","a");
		fopen("C:/Gestao Olimpiada/premiacao.txt","a");
		fopen("C:/Gestao Olimpiada/rankingMedalhas.txt","a");
		fopen("C:/Gestao Olimpiada/equipeMedica.txt","a");*/
     
     	menuprincipal();
	
	
	
	return 0;
}
