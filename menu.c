#include<stdio.h>
#include<math.h>
#include<locale.h>
#include<Windows.h>
#include<string.h>
#include<direct.h>
#include<stdlib.h>
#include <ctype.h>


typedef struct{
	int idNUm;
	char nomes[20];
	int medalhasOuro;
	int medalhasPrata;
	int medalhasbronze;
	
}Paises;

typedef struct{
	int idNUm;
	char modalidades[20];
	int medalhasOuro;
	int medalhasPrata;
	int medalhasbronze;
	
}Modalidades;

typedef struct{
	int idNUm;
	char nome[20];
	char sobrenome[20];
	char modalidade[20];
	char pais[20];
	int medalhasOuro;
	int medalhasPrata;
	int medalhasbronze;
	
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
   	Modalidades	modalidades[50];
 	Paises pais[100];
	
}Alojamentos;

typedef struct{
	int idNUm;
	char nome[20];
	char local[20];
	
}LocaisJogos;

typedef struct{
	int idNUm;
	char nome[40];
	char local[40];
	Paises pais[100];
	
}CentroTreinamento;

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
			menuprincipal();
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
			menuprincipal();
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
		
		 
			
			Atleta atleta[quantAtlet];
			
		    memset(atleta, 0, (size_t)quantAtlet * sizeof(atleta));
			
			
				
				if(get_size(nomeArqu) == 0)
				{
  				  ultimoId = 0;
				}
				else		
				{
					fseek(atletasSalvar, -1*sizeof(Atleta),SEEK_END);//saltar do final do arquivo (SEEK_END) para o inicio do ultimo registro
   				 	fread(&atletas, sizeof(Atleta), 1, atletasSalvar); //ler o ultimo registro
   					ultimoId = atletas.idNUm;
				
				 	
				}
				
			
					printf("---------------------------------------------------------------------------------------------\n");
					printf("                                   CADASTRO ATLETAS \n");
					printf("---------------------------------------------------------------------------------------------\n\n");
				
				for(i=0;i<quantAtlet;i++)
				{
					
					
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
						printf("Op��o inv�lida!!\n");
						sleep(2);
						menuprincipal();
						system("cls");
						printf("---------------------------------------------------------------------------------------------\n");
						printf("                                   CADASTRO ATLETAS \n");
						printf("---------------------------------------------------------------------------------------------\n\n");
						printf("Entre novamente com os dados.\n");
						i--;
						
						
					}
					
					printf("\n");	
					printf("Pa�s:\n\n");
					
					j=0;
					
					while(j<ultPais){
						printf("[%d] %s\n", j+1, paise[j].nomes);
						j++;
						
					}
					
					printf("\n");
					printf("Escolha um pa�s:\n");	
					scanf("%d", &opcaoPais);
					
					if(opcaoPais > 0 && opcaoPais <= ultPais)
					{
						strcpy(atleta[i].pais , paise[opcaoPais-1].nomes);
					}
					else{
						printf("Op��o inv�lida!!\n");
						sleep(2);
						system("cls");
						printf("---------------------------------------------------------------------------------------------\n");
						printf("                                   CADASTRO ATLETAS \n");
						printf("---------------------------------------------------------------------------------------------\n\n");
						printf("Entre novamente com os dados.\n");
						i--;
					}
					
					atleta[i].medalhasOuro = 0;
					atleta[i].medalhasPrata = 0;
					atleta[i].medalhasbronze = 0;
						
						
					system("cls");
					printf("Deseja visualizar as informa��es inseridas?\nDigite 1 para SIM e 0 para N�O: \n");
					scanf("%d", &ver);
					
					if(ver == 1)
						{
							printf("\nOs dados informados foram: \n\n");
							printf("Id: %d \n",atleta[i].idNUm);
							printf("Nome: %s \n",atleta[i].nome);
							printf("Sobrenome: %s \n", atleta[i].sobrenome);
							printf("Modalidade: %s \n",atleta[i].modalidade);
							printf("Medalhas de ouro: %d \n",atleta[i].medalhasOuro);
							printf("Medalhas de prata: %d \n",atleta[i].medalhasPrata);
							printf("Medalhas de bronze: %d \n",atleta[i].medalhasbronze);
							
							printf("\n");
							printf("Confirma as informa��es?\nDigite 1 para SIM e 0 para N�O:\n");
							scanf("%d", &confirma);
							
							if(confirma == 1)
								{   
								    if(atletasSalvar != NULL)
								    {
								    	fseek(atletasSalvar,0,SEEK_END);
								    	fwrite(&atleta, sizeof(Atleta), 1, atletasSalvar);
								    	
			     						 system("cls");
			     						 printf("Dados salvos com sucesso!\n\n");
										 sleep(2);
										 fclose(atletasSalvar);
										 menuprincipal();	
														
									}
									else
									{
										 system("cls");
										 printf("N�o foi poss�vel salvar os dados!\n\n");
										 sleep(2);
										 menuprincipal();
									}
							
								}
								else
									{
									
										system("cls");
										printf("---------------------------------------------------------------------------------------------\n");
										printf("                                   CADASTRO ATLETAS \n");
										printf("---------------------------------------------------------------------------------------------\n\n");
										printf("Os dados n�o foram salvos!\n");
										printf("Insira os dados novamente.\n\n");
										i--;
									}
						
						
						}
						else if(ver < 0 || ver > 1)
						{
							system("cls");
							printf("Op��o inv�lida! \n");
							sleep(2);
							menuprincipal();
						}
						else
						{
							printf("\n");
							printf("Confirma as informa��es?\nDigite 1 para SIM e 0 para N�O:\n");
							scanf("%d", &confirma);	
							
							if(confirma == 1)
								{   
								    
			     						 fseek(atletasSalvar,0,SEEK_END);
			     						 fwrite(&atleta, sizeof(Atleta), 1, atletasSalvar);
			     						 
			     						 system("cls");
			     						 printf("Dados salvos com sucesso!\n\n");
										 sleep(2);
										 fclose(atletasSalvar);
										 menuprincipal();	
									
								}
								else
									{
										system("cls");
										printf("---------------------------------------------------------------------------------------------\n");
										printf("                                   CADASTRO ATLETAS \n");
										printf("---------------------------------------------------------------------------------------------\n\n");
										printf("Os dados n�o foram salvos!\n");
										printf("Insira os dados novamente.\n\n");
										i--;
									}
	     					
						}
				}
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
		
			printf("---------------------------------------------------------------------------------------------\n");
			printf("                                   CADASTRO FUNCIONARIOS \n");
			printf("---------------------------------------------------------------------------------------------\n\n");
		
		
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
				printf("Deseja visualizar os dados informados ?\nDigite 1 para SIM e 0 para N�O:\n");
				scanf("%d", &ver);
				
				if(ver == 1){
					j = 0;
					
					while(j < quant){
						printf("Id: %d \n", funcionario[j].idNUm);
						printf("Nome: %s \n", funcionario[j].nome);
						printf("Sobrenome: %s \n", funcionario[j].sobrenome);
						printf("Fun��o: %s\n", funcionario[j].funcao);
						j++;
					}
					
					printf("\n");
					printf("Confirma as informa��es ?\nDigite 1 para SIM e 0 para N�O:\n");
					scanf("%d", &confirma);
					
					if(confirma == 1)
					{
						fseek(funcionarios, 0, SEEK_END);
						fwrite(&funcionario, sizeof(Funcionarios), 1, funcionarios);
						system("cls");
						printf("Dados salvos com sucesso!!\n");
						fclose(funcionarios);
						sleep(2);	
						menuprincipal();
							
						
					}
					else{
						printf("Os dados n�o foram salvos!!\n");
						sleep(2);
						system("cls");
						printf("---------------------------------------------------------------------------------------------\n");
						printf("                                   CADASTRO FUNCIONARIOS \n");
						printf("---------------------------------------------------------------------------------------------\n\n");
						printf("Entre novamente com os dados.\n");
						i--;
						
					}
					
				}
				else{
					printf("Confirma as informa��es ?\nDigite 1 para SIM e 0 para N�O:\n");
					scanf("%d", &confirma);
					
					if(confirma == 1)
					{
						fseek(funcionarios, 0, SEEK_END);
						fwrite(&funcionario, sizeof(Funcionarios), 1, funcionarios);
						system("cls");
						printf("Dados salvos com sucesso!!\n");
						fclose(funcionarios);
						sleep(2);	
						menuprincipal();	
					}
					else{
						printf("Os dados n�o foram salvos!!\n");
						fclose(funcionarios);
						sleep(2);
						menuprincipal();
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
			menuprincipal();
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
		
		
			printf("---------------------------------------------------------------------------------------------\n");
			printf("                                   CADASTRO MEDICOS \n");
			printf("---------------------------------------------------------------------------------------------\n\n");
		
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
			printf("Pa�s:\n\n");
			
			j=0;
			
			while(j<ultPais){
				printf("[%d] %s\n", j+1, paise[j].nomes);
				j++;
				
			}
			
			printf("\n");
			printf("Escolha um pa�s:\n");	
			scanf("%d", &opcaoPais);
			
			if(opcaoPais > 0 && opcaoPais <= ultPais)
			{
				strcpy(medico[i].pais , paise[opcaoPais-1].nomes);
			}
			else
			{
				printf("Op��o inv�lida!!\n");
				sleep(2);
				system("cls");
				printf("---------------------------------------------------------------------------------------------\n");
				printf("                                   CADASTRO MEDICOS \n");
				printf("---------------------------------------------------------------------------------------------\n\n");
				printf("Entre novamente com os dados.\n");
				i--;
			}
			
			
			if(i+1 == quant)
			{
				printf("Deseja visualizar os dados informados ?\nDigite 1 para SIM e 0 para N�O:\n");
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
					
					
					printf("Confirma as informa��es ?\nDigite 1 para SIM e 0 para N�O:\n");
					scanf("%d", &confirma);
					
					if(confirma == 1)
					{
						fseek(medicos, 0, SEEK_END);
						fwrite(&medico, sizeof(Medicos), 1, medicos);
						system("cls");
						printf("Dados salvos com sucesso!!\n");
						fclose(medicos);
						sleep(2);
						menuprincipal();
						
					}
					else
					{
						printf("Os dados n�o foram salvos!!\n");
						sleep(2);
						system("cls");
						
						printf("---------------------------------------------------------------------------------------------\n");
						printf("                                   CADASTRO MEDICOS \n");
						printf("---------------------------------------------------------------------------------------------\n\n");
						printf("Entre novamente com os dados.\n");
						i--;
						
					}
					
				}
				else
				{
					printf("Confirma as informa��es ?\nDigite 1 para SIM e 0 para N�O:\n");
					scanf("%d", &confirma);
					
					if(confirma == 1)
					{
						fseek(medicos, 0, SEEK_END);
						fwrite(&medico, sizeof(Medicos), 1, medicos);
						system("cls");
						printf("Dados salvos com sucesso!!\n");
						fclose(medicos);
						sleep(2);
						menuprincipal();
						
					}
					else
					{
						printf("Os dados n�o foram salvos!!\n");
						fclose(medicos);
						sleep(2);
						menuprincipal();
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
			menuprincipal();
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
		
			printf("---------------------------------------------------------------------------------------------\n");
			printf("                                   CADASTRO VOLUNTARIOS \n");
			printf("---------------------------------------------------------------------------------------------\n\n");
		
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
			printf("Pa�s:\n\n");
			
			j=0;
			
			while(j<ultPais){
				printf("[%d] %s\n", j+1, paise[j].nomes);
				j++;
				
			}
			
			printf("\n");
			printf("Escolha um pa�s:\n");	
			scanf("%d", &opcaoPais);
			
			if(opcaoPais > 0 && opcaoPais <= ultPais)
			{
				strcpy(voluntario[i].pais , paise[opcaoPais-1].nomes);
			}
			else
			{
				printf("Op��o inv�lida!!\n");
				sleep(2);
				//menuprincipal();
				system("cls");
				printf("---------------------------------------------------------------------------------------------\n");
				printf("                                   CADASTRO VOLUNTARIOS \n");
				printf("---------------------------------------------------------------------------------------------\n\n");
				printf("Entre novamente com os dados.\n");
				i--;
				
			
				
			}
			
			
			if(i+1 == quant)
			{
				printf("Deseja visualizar os dados informados ?\nDigite 1 para SIM e 0 para N�O:\n");
				scanf("%d", &ver);
				
				if(ver == 1)
				{
					int j = 0;
					
					while(j < quant)
					{
						printf("Id: %d \n", voluntario[j].idNUm);
						printf("Nome: %s \n", voluntario[j].nome);
						printf("Sobrenome: %s \n", voluntario[j].sobrenome);
						printf("Fun��o: %s\n", voluntario[j].funcao);
						printf("Pais: %s \n\n", voluntario[j].pais);
						j++;
					}
					
					
					printf("Confirma as informa��es ?\nDigite 1 para SIM e 0 para N�O:\n");
					scanf("%d", &confirma);
					
					if(confirma == 1)
					{
						fseek(voluntarios, 0, SEEK_END);
						fwrite(&voluntario, sizeof(Voluntarios), 1, voluntarios);
						system("cls");
						printf("Dados salvos com sucesso!!\n");
						fclose(voluntarios);
						sleep(2);
						menuprincipal();
						
					}
					else
					{
						printf("Os dados n�o foram salvos!!\n");
						sleep(2);
						system("cls");
						printf("---------------------------------------------------------------------------------------------\n");
						printf("                                   CADASTRO VOLUNTARIOS \n");
						printf("---------------------------------------------------------------------------------------------\n\n");
						printf("Entre novamente com os dados.\n");
						i--;
					
						
					}
					
				}
				else
				{
					printf("Confirma as informa��es ?\nDigite 1 para SIM e 0 para N�O:\n");
					scanf("%d", &confirma);
					
					if(confirma == 1)
					{
						fseek(voluntarios, 0, SEEK_END);
						fwrite(&voluntario, sizeof(Voluntarios), 1, voluntarios);
						system("cls");
						printf("Dados salvos com sucesso!!\n");
						fclose(voluntarios);
						sleep(2);
						menuprincipal();
						
					}
					else
					{
						printf("Os dados n�o foram salvos!!\n");
						fclose(voluntarios);
						sleep(2);
						menuprincipal();
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
			menuprincipal();
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
			
			printf("---------------------------------------------------------------------------------------------\n");
			printf("                                   CADASTRO EQUIPE OLIMPICA \n");
			printf("---------------------------------------------------------------------------------------------\n\n");
		
		
		for(i=0;i<quant;i++)
		{
			
			
			
			int vol = 0, compara=0;
			
			equipe[i].idNUm = ultimoid+1;
			
			printf("insira o nome:\n");
			scanf("%s", &equipe[i].nome);
			
			printf("insira o sobrenome:\n");
			scanf("%s", &equipe[i].sobrenome);
			
			printf("Insira a funcao:\n");
			scanf("%s", &equipe[i].funcao);
				
			
			printf("\n");	
			printf("Pa�s:\n\n");
			
			j=0;
			
			while(ultPais>j){
				printf("[%d] %s\n", j+1, paise[j].nomes);
				j++;
				
			}
			
			printf("\n");
			printf("Escolha um pa�s:\n");	
			scanf("%d", &opcaoPais);
			
			if(opcaoPais > 0 && opcaoPais <= ultPais)
			{
				strcpy(equipe[i].pais , paise[opcaoPais-1].nomes);
			}
			else
			{
				printf("Op��o inv�lida!!\n");
				sleep(2);
				system("cls");
				printf("---------------------------------------------------------------------------------------------\n");
				printf("                                   CADASTRO EQUIPE OLIMPICA \n");
				printf("---------------------------------------------------------------------------------------------\n\n");
				printf("Entre novamente com os dados.\n");
				i--;
			}
			
			if(i+1 == quant)
			{
				printf("Deseja visualizar os dados informados ?\nDigite 1 para SIM e 0 para N�O:\n");
				scanf("%d", &ver);
				
				if(ver == 1)
				{
						printf("Id: %d \n", equipe[i].idNUm);
						printf("Nome: %s \n", equipe[i].nome);
						printf("Sobrenome: %s \n", equipe[i].sobrenome);
						printf("Fun��o: %s\n", equipe[i].funcao);
						printf("Pais: %s \n\n", equipe[i].pais);
					
					printf("Confirma as informa��es ?\nDigite 1 para SIM e 0 para N�O:\n");
					scanf("%d", &confirma);
					
					if(confirma == 1)
					{
						fseek(equipes, 0, SEEK_END);
						fwrite(&equipe, sizeof(EquipeOlimpica), 1, equipes);
						system("cls");
						printf("Dados salvos com sucesso!!\n\n");
						fclose(equipes);
						sleep(2);
						menuprincipal();	
					}
					else
					{
						printf("Os dados n�o foram salvos!!\n");
						sleep(2);
						system("cls");
						printf("---------------------------------------------------------------------------------------------\n");
				printf("                                   CADASTRO EQUIPE OLIMPICA \n");
				printf("---------------------------------------------------------------------------------------------\n\n");
						printf("Entre novamente com os dados.\n");
						i--;
						
						
					}
					
				}
				else
				{
					printf("Confirma as informa��es ?\nDigite 1 para SIM e 0 para N�O:\n");
					scanf("%d", &confirma);
					
					if(confirma == 1)
					{
						fseek(equipes, 0, SEEK_END);
						fwrite(&equipe, sizeof(EquipeOlimpica), 1, equipes);
						system("cls");
						printf("Dados salvos com sucesso!!\n");
						fclose(equipes);
						sleep(2);
						menuprincipal();	
						
					}
					else
					{
						printf("Os dados n�o foram salvos!!\n");
						fclose(equipes);
						sleep(2);
						menuprincipal();
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
	
	
	
	//printf("Informe quantos pa�ses deseja cadastrar:\n");
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
		
			printf("---------------------------------------------------------------------------------------------\n");
			printf("                                   CADASTRO PAISES \n");
			printf("---------------------------------------------------------------------------------------------\n\n");
		
		for(i=0;i<quant;i++)
		{
			
		
			
			int pai = 0, compara=0;
			
			pais[i].idNUm = ultimoid+1;
			
			
			printf("insira o nome do pa�s:\n");
			scanf("%s", &nome);
			
			for(pai=0;pai<=ultimoid;pai++)
			{
				compara = strcmp(nome, nomes[pai]);
				
					if(compara == 0)
					{
						system("cls");
						printf("Pa�s j� cadastrado.\n");
						sleep(2);
						menuprincipal();
					}
					else{
						strcpy(pais[i].nomes, nome);
					}
				
			}
			
			pais[i].medalhasOuro = 0;
			pais[i].medalhasPrata = 0;
			pais[i].medalhasbronze = 0;
			
			if(i+1 == quant){
				printf("Deseja visualizar o nome informado ?\nDigite 1 para SIM e 0 para N�O:\n");
				scanf("%d", &ver);
				
				if(ver == 1){
					int j = 0;
					
					while(j < quant){
						printf("Id: %d \n", pais[j].idNUm);
						printf("Pais: %s \n\n", pais[j].nomes);
						j++;
					}
					
					
					printf("Confirma as informa��es ? \nDigite 1 para SIM e 0 para N�O:\n");
					scanf("%d", &confirma);
					
					if(confirma == 1)
					{
						fseek(paises, 0, SEEK_END);
						fwrite(&pais, sizeof(Paises), 1, paises);
						printf("Dados salvos com sucesso!!\n");
						fclose(paises);
						sleep(2);
						menuprincipal();
					}
					else{
						printf("Os dados n�o foram salvos!!\n");
						sleep(2);
						system("cls");
						printf("---------------------------------------------------------------------------------------------\n");
						printf("                                   CADASTRO PAISES \n");
						printf("---------------------------------------------------------------------------------------------\n\n");
						printf("Entre novamente com os dados.\n");
						i--;
						
					}
					
				}
				else{
					printf("Confirma as informa��es ? \nDigite 1 para SIM e 0 para N�O:\n");
					scanf("%d", &confirma);
					
					if(confirma == 1)
					{
						fseek(paises, 0, SEEK_END);
						fwrite(&pais, sizeof(Paises), 1, paises);
						printf("Dados salvos com sucesso!!\n");
						fclose(paises);
						sleep(2);
						menuprincipal();
					}
					else{
						printf("Os dados n�o foram salvos!!\n");
						fclose(paises);
						sleep(2);
						menuprincipal();
						}
					}
				}
			}		
		}		

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
		
			printf("---------------------------------------------------------------------------------------------\n");
			printf("                                   CADASTRO MODALIDADES \n");
			printf("---------------------------------------------------------------------------------------------\n\n");
		
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
				printf("Modalidade j� cadastrada.\n");
				sleep(2);
				menuprincipal();
			}
			else{
				strcpy(modalidades[i].modalidades, modali);
			}
			
			
			modalidades[i].medalhasOuro = 0;
			modalidades[i].medalhasPrata = 0;
			modalidades[i].medalhasbronze = 0;
			
			if(i+1 == quant)
			{
				printf("Deseja visualizar o nome informado ?\nDigite 1 para SIM e 0 para N�O:\n");
				scanf("%d", &ver);
				
				if(ver == 1){
					
					j = 0;
					
					while(j < quant){
						printf("Id: %d \n", modalidades[j].idNUm);
						printf("Modalidade: %s \n\n", modalidades[j].modalidades);
						j++;
					}
					
				
					
					printf("Confirma as informa��es ? \nDigite 1 para SIM e 0 para N�O:\n");
					scanf("%d", &confirma);
					
					if(confirma == 1)
					{
						fseek(modalidade, 0, SEEK_END);
						fwrite(&modalidades, sizeof(Modalidades), 1, modalidade);
						fclose(modalidade);
						printf("Dados salvos com sucesso!!\n");
						sleep(2);
						menuprincipal();
					}
					else{
						printf("Os dados n�o foram salvos!!\n");
						sleep(2);
						system("cls");
						printf("---------------------------------------------------------------------------------------------\n");
						printf("                                   CADASTRO MODALIDADES \n");
						printf("---------------------------------------------------------------------------------------------\n\n");
						printf("Entre novamente com os dados.\n");
						i--;
						
					}
					
				}
				else
				{
					printf("Confirma as informa��es ? \nDigite 1 para SIM e 0 para N�O:\n");
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
						printf("Os dados n�o foram salvos!!\n");
						fclose(modalidade);
						sleep(2);
						menuprincipal();
					}
					
				}
			}
		}
	}
}

void alojamentos(){
	system("cls");
	
	FILE *alojamentos;
	FILE *paises;
	int i=0, quant=1, confirma, ver, ultimoid=0, contador=0, j=0, opcaoPais, ultPais, quantPais;
	char caminho[] = "C:/Gestao Olimpiada/alojamentos.txt";
	char pais[40] = "C:/Gestao Olimpiada/paises.txt";
	char nome[40];
	char nomes[50][15];
	Paises paisess;
	Paises paise[100];
	
	
	alojamentos = fopen(caminho, "a+");
	
	Alojamentos aloj;
	Alojamentos alojamento[quant];
	Alojamentos alojCadastrado[100];
	

	memset(alojamento, 0, (size_t)quant * sizeof(alojamento));
	
	
		if(get_size(pais)==0)
		{
			printf("Nenhum pais cadastrado!!\n");
			sleep(2);
			menuprincipal();
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
	
		
	if(alojamentos != NULL)
	{
		if(get_size(caminho) == 0)
		{
  		  ultimoid = 0;
		}
		else		
		{
			fseek(alojamentos, -1*sizeof(Alojamentos),SEEK_END);//saltar do final do arquivo (SEEK_END) para o inicio do ultimo registro
  			fread(&aloj, sizeof(Alojamentos), 1, alojamentos); //ler o ultimo registro
  			ultimoid = aloj.idNUm;
  			
  			
  			rewind(alojamentos);
  	
	 		while(!feof(alojamentos))
		  	{
				fread(&aloj, sizeof(Alojamentos), 1, alojamentos);
				alojCadastrado[contador] = aloj;
				contador++;			
			}
		
			while(j<=ultimoid)
			{
				strcpy(nomes[j], alojCadastrado[j].nome);
				j++;
			}
			
  			
		}
			
	
			printf("---------------------------------------------------------------------------------------------\n");
			printf("                                   CADASTRO ALOJAMENTOS \n");
			printf("---------------------------------------------------------------------------------------------\n\n");
		
		for(i=0;i<quant;i++)
		{
			
			
			
			int compara = 0;
			
			alojamento[i].idNUm = ultimoid+1;
			
			printf("insira o nome:\n");
			scanf("%s", &nome);
			
			j=0;
			
			for(j=0;j<=ultimoid;j++)
			{
				compara = strcmp(nome, nomes[j]);
				
					if(compara == 0)
					{
						system("cls");
						printf("Alojamento j� cadastrado.\n");
						sleep(2);
						menuprincipal();
					}
					else{
						strcpy(alojamento[i].nome, nome);
					}
				
			}
			
			
			printf("Insira o local:\n");
			scanf("%s", &alojamento[i].local);
				
			
			printf("\n");	
			printf("Pa�ses:\n\n");
			
			j=0;
			
			while(ultPais>j){
				printf("[%d] %s\n", j+1, paise[j].nomes);
				j++;
				
			}
			printf("\n");
			printf("Informe quantos pa�ses v�o utilizar esse local ou zero [0] para todos.\n");
			scanf("%d", &quantPais);
			
			if(quantPais == 0 )
			{
				j = 0;
				
					while(j<ultPais)
						{
							strcpy(alojamento[i].pais[j].nomes , paise[j].nomes);	
							j++;
						}
						
			}
			
			else if(quantPais > 0 && quantPais <= ultPais)
			{
				j = 0;
				
				for(j=0;j<quantPais;j++)
				{
					printf("\n");
					printf("Escolha o pa�s %d:\n", j+1);	
					scanf("%d", &opcaoPais);
					
					if(opcaoPais > 0 && opcaoPais <= ultPais)
					{
						strcpy(alojamento[i].pais[j].nomes , paise[opcaoPais-1].nomes);
					}
					else
					{
						printf("Op��o inv�lida!!\n");
						sleep(2);
						system("cls");
						printf("---------------------------------------------------------------------------------------------\n");
						printf("                                   CADASTRO ALOJAMENTOS \n");
						printf("---------------------------------------------------------------------------------------------\n\n");
						printf("Entre novamente com os dados.\n");
						i--;
					}
				}
			}
			else
			{
				printf("Op��o inv�lida!!\n");
				sleep(2);
				system("cls");
				printf("---------------------------------------------------------------------------------------------\n");
				printf("                                   CADASTRO ALOJAMENTOS \n");
				printf("---------------------------------------------------------------------------------------------\n\n");
				printf("Entre novamente com os dados.\n");
				i--;
			}
			
		
			
			if(i+1 == quant)
			{
				printf("Deseja visualizar os dados informados ?\nDigite 1 para SIM e 0 para N�O:\n");
				scanf("%d", &ver);
				
				if(ver == 1)
				{
						printf("Id: %d \n", alojamento[i].idNUm);
						printf("Nome: %s \n", alojamento[i].nome);
						printf("Local: %s \n", alojamento[i].local);
					
						
						if(quantPais == 0)
						{
								j = 0;
				
							while(j<ultPais)
							{
								printf("Pais %d: %s \n", j+1, alojamento[i].pais[j].nomes);	
								j++;
							}
							
						}
						else
						{
								j=0;
								
								while(j<quantPais)
								{
									printf("Pais %d: %s \n", j+1, alojamento[i].pais[j].nomes);	
									j++;
								}
						}
						
					
					printf("Confirma as informa��es ?\nDigite 1 para SIM e 0 para N�O:\n");
					scanf("%d", &confirma);
					
					if(confirma == 1)
					{
						fseek(alojamentos, 0, SEEK_END);
						fwrite(&alojamento, sizeof(Alojamentos), 1, alojamentos);
						system("cls");
						printf("Dados salvos com sucesso!!\n\n");
						fclose(alojamentos);
						sleep(2);
						menuprincipal();	
					}
					else
					{
						printf("Os dados n�o foram salvos!!\n");
						sleep(2);
						system("cls");
						printf("---------------------------------------------------------------------------------------------\n");
						printf("                                   CADASTRO ALOJAMENTOS \n");
						printf("---------------------------------------------------------------------------------------------\n\n");
						printf("Entre novamente com os dados.\n");
						i--;
						
					}
					
				}
				else
				{
					printf("Confirma as informa��es ?\nDigite 1 para SIM e 0 para N�O:\n");
					scanf("%d", &confirma);
					
					if(confirma == 1)
					{
						fseek(alojamentos, 0, SEEK_END);
						fwrite(&alojamento, sizeof(Alojamentos), 1, alojamentos);
						system("cls");
						printf("Dados salvos com sucesso!!\n\n");
						fclose(alojamentos);
						sleep(2);
						menuprincipal();	
						
					}
					else
					{
						printf("Os dados n�o foram salvos!!\n");
						fclose(alojamentos);
						sleep(2);
						menuprincipal();
					}	
				 }
			}
			
					
		}	
	}		
	
	
	
}

void locaisJogos(){
	
	system("cls");
	
	FILE *locaisjogos;
	int i, quant=1, confirma, ver, ultimoid=0, contador=0, j=0;
	char caminho[40] = "C:/Gestao Olimpiada/locaisjogos.txt";
	char nomes[50][15];
	char nome[40];
	
	locaisjogos = fopen(caminho, "a+");
	
	
	LocaisJogos locais[quant];
	LocaisJogos local;
	LocaisJogos locaiscadastrados[100];
	
	 memset(locais, 0, (size_t)quant * sizeof(locais));
		
	if(locaisjogos != NULL)
	{
		if(get_size(caminho) == 0)
		{
  		  ultimoid = 0;
		}
		else		
		{
			fseek(locaisjogos, -1*sizeof(LocaisJogos),SEEK_END);//saltar do final do arquivo (SEEK_END) para o inicio do ultimo registro
  			fread(&local, sizeof(LocaisJogos), 1, locaisjogos); //ler o ultimo registro
  			ultimoid = local.idNUm;
  				
  				
  			rewind(locaisjogos);
  	
	 		while(!feof(locaisjogos))
		  	{
				fread(&local, sizeof(LocaisJogos), 1, locaisjogos);
				locaiscadastrados[contador] = local;
				contador++;			
			}
		
			while(j<=ultimoid)
			{
				strcpy(nomes[j], locaiscadastrados[j].nome);
				j++;
			}
			
		
		}
		
			printf("---------------------------------------------------------------------------------------------\n");
			printf("                                   CADASTRO LOCAIS DE JOGOS \n");
			printf("---------------------------------------------------------------------------------------------\n\n");
		
		for(i=0;i<quant;i++)
		{
			
		
			
			int compara=0;
			
			locais[i].idNUm = ultimoid+1;
			
			printf("insira o nome:\n");
			scanf("%s", &nome);
			
			j=0;
			
			for(j=0;j<=ultimoid;j++)
			{
				compara = strcmp(nome, nomes[j]);
				
				if(compara == 0)
				{
					system("cls");
					printf("Local j� cadastrado.\n");
					sleep(2);
					menuprincipal();
				}
				else{
					strcpy(locais[i].nome, nome);
				}
				
			}
			
			
			
		
			
			if(i+1 == quant){
				printf("Deseja visualizar o nome informado ?\nDigite 1 para SIM e 0 para N�O:\n");
				scanf("%d", &ver);
				
				if(ver == 1){
					int j = 0;
					
					while(j < quant){
						printf("Id: %d \n", locais[j].idNUm);
						printf("Local de jogo: %s \n\n", locais[j].nome);
						j++;
					}
					
					
					printf("Confirma as informa��es ? \nDigite 1 para SIM e 0 para N�O:\n");
					scanf("%d", &confirma);
					
					if(confirma == 1)
					{
						fseek(locaisjogos, 0, SEEK_END);
						fwrite(&locais, sizeof(LocaisJogos), 1, locaisjogos);
						printf("Dados salvos com sucesso!!\n");
						fclose(locaisjogos);
						sleep(2);
						menuprincipal();
					}
					else{
						printf("Os dados n�o foram salvos!!\n");
						sleep(2);
						system("cls");
						printf("---------------------------------------------------------------------------------------------\n");
						printf("                                   CADASTRO LOCAIS DE JOGOS \n");
						printf("---------------------------------------------------------------------------------------------\n\n");
						printf("Entre novamente com os dados.\n");
						i--;
						
					}
					
				}
				else{
					printf("Confirma as informa��es ? \nDigite 1 para SIM e 0 para N�O:\n");
					scanf("%d", &confirma);
					
					if(confirma == 1)
					{
						fseek(locaisjogos, 0, SEEK_END);
						fwrite(&locais, sizeof(LocaisJogos), 1, locaisjogos);
						printf("Dados salvos com sucesso!!\n");
						fclose(locaisjogos);
						sleep(2);
						menuprincipal();
					}
					else{
						printf("Os dados n�o foram salvos!!\n");
						fclose(locaisjogos);
						sleep(2);
						menuprincipal();
						}
					}
				}
			}		
		}		
	
}

void equipamentos(){
	system("cls");
	
	FILE *equipamentos;
	int i, quant=1, confirma, ver, ultimoid=0, contador=0, j=0;
	char caminho[40] = "C:/Gestao Olimpiada/equipamentos.txt";
	char nomes[40][15];
	char nome[40];
	
	equipamentos = fopen(caminho, "a+");
	
	Equipamentos equipamento[quant];
	Equipamentos equip;
	Equipamentos equipCad[100];
	
	 memset(equipamento, 0, (size_t)quant * sizeof(equipamento));
		
	if(equipamentos != NULL)
	{
		if(get_size(caminho) == 0)
		{
  		  ultimoid = 0;
		}
		else		
		{
			fseek(equipamentos, -1*sizeof(Equipamentos),SEEK_END);//saltar do final do arquivo (SEEK_END) para o inicio do ultimo registro
  			fread(&equip, sizeof(Equipamentos), 1, equipamentos); //ler o ultimo registro
  			ultimoid = equip.idNUm;
  				
  				
  			rewind(equipamentos);
  	
	 		while(!feof(equipamentos))
		  	{
				fread(&equip, sizeof(Equipamentos), 1, equipamentos);
				equipCad[contador] = equip;
				contador++;			
			}
		
			while(j<=ultimoid)
			{
				strcpy(nomes[j], equipCad[j].equipamentos);
				j++;
			}
				
		}
		
			printf("---------------------------------------------------------------------------------------------\n");
			printf("                                   CADASTRO DE EQUIPAMENTOS \n");
			printf("---------------------------------------------------------------------------------------------\n\n");	
		
		for(i=0;i<quant;i++)
		{
		
		
			
			int compara=0;
			
			equipamento[i].idNUm = ultimoid+1;
			
			printf("Insira o nome do equipamento:\n");
			scanf("%s", &nome);
			
			j=0;
			
			for(j=0;j<=ultimoid;j++)
			{
				compara = strcmp(nome, nomes[j]);
				
					if(compara == 0)
					{
						system("cls");
						printf("Equipamento j� cadastrado.\n");
						sleep(2);
						menuprincipal();
					}
					else{
						strcpy(equipamento[i].equipamentos, nome);
					}
				
			}
			
		
			
			if(i+1 == quant){
				printf("Deseja visualizar o nome informado ?\nDigite 1 para SIM e 0 para N�O:\n");
				scanf("%d", &ver);
				
				if(ver == 1){
					int j = 0;
					
					while(j < quant){
						printf("Id: %d \n", equipamento[j].idNUm);
						printf("Equipamento: %s \n\n", equipamento[j].equipamentos);
						j++;
					}
					
					
					printf("Confirma as informa��es ? \nDigite 1 para SIM e 0 para N�O:\n");
					scanf("%d", &confirma);
					
					if(confirma == 1)
					{
						fseek(equipamentos, 0, SEEK_END);
						fwrite(&equipamento, sizeof(Equipamentos), 1, equipamentos);
						printf("Dados salvos com sucesso!!\n");
						fclose(equipamentos);
						sleep(2);
						menuprincipal();
					}
					else{
						printf("Os dados n�o foram salvos!!\n");
						sleep(2);
						system("cls");
						printf("---------------------------------------------------------------------------------------------\n");
						printf("                                   CADASTRO DE EQUIPAMENTOS \n");
						printf("---------------------------------------------------------------------------------------------\n\n");	
						printf("Entre novamente com os dados.\n");
						i--;
						
					}
					
				}
				else{
					printf("Confirma as informa��es ? \nDigite 1 para SIM e 0 para N�O:\n");
					scanf("%d", &confirma);
					
					if(confirma == 1)
					{
						fseek(equipamentos, 0, SEEK_END);
						fwrite(&equipamento, sizeof(Equipamentos), 1, equipamentos);
						printf("Dados salvos com sucesso!!\n");
						fclose(equipamentos);
						sleep(2);
						menuprincipal();
					}
					else{
						printf("Os dados n�o foram salvos!!\n");
						fclose(equipamentos);
						sleep(2);
						menuprincipal();
						}
					}
				}
			}		
		}		
	
	
}

void centroTreinamento(){
	system("cls");
	
	FILE *centros;
	FILE *paises;
	int i=0, quant=1, confirma, ver, ultimoid=0, contador=0, j=0, opcaoPais, ultPais, ids, quantPais;
	char caminho[] = "C:/Gestao Olimpiada/centrotreinamento.txt";
	char pais[40] = "C:/Gestao Olimpiada/paises.txt";
	char nome[40];
	char nomes[50][15];
	Paises paisess;
	Paises paise[100];
	
	
	centros = fopen(caminho, "a+");
	
	CentroTreinamento cent;
	CentroTreinamento centro[quant];
	CentroTreinamento centroCad[100];

	memset(centro, 0, (size_t)quant * sizeof(centro));
	
	
		if(get_size(pais)==0)
		{
			printf("Nenhum pais cadastrado!!\n");
			sleep(2);
			menuprincipal();
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
	
		
	if(centros != NULL)
	{
		if(get_size(caminho) == 0)
		{
  		  ultimoid = 0;
		}
		else		
		{
			fseek(centros, -1*sizeof(CentroTreinamento),SEEK_END);//saltar do final do arquivo (SEEK_END) para o inicio do ultimo registro
  			fread(&cent, sizeof(CentroTreinamento), 1, centros); //ler o ultimo registro
  			ultimoid = cent.idNUm;
  			
  			
  			rewind(centros);
  	
	 		while(!feof(centros))
		  	{
				fread(&cent, sizeof(CentroTreinamento), 1, centros);
				centroCad[contador] = cent;
				contador++;			
			}
		
			while(j<=ultimoid)
			{
				strcpy(nomes[j], centroCad[j].nome);
				j++;
			}
			
  			
		}
			
			printf("---------------------------------------------------------------------------------------------\n");
			printf("                                   CADASTRO CENTRO DE TREINAMENTO\n");
			printf("---------------------------------------------------------------------------------------------\n\n");
		
		
		for(i=0;i<quant;i++)
		{
			
			
			
			int compara = 0;
			
			centro[i].idNUm = ultimoid+1;
			
			printf("insira o nome:\n");
			scanf("%s", &nome);
			
			j=0;
			
			for(j=0;j<=ultimoid;j++)
			{
				compara = strcmp(nome, nomes[j]);
				
					if(compara == 0)
					{
						system("cls");
						printf("Local j� cadastrado.\n");
						sleep(2);
						menuprincipal();
					}
					else{
						strcpy(centro[i].nome, nome);
					}
				
			}
			
			
			printf("Insira o local:\n");
			scanf("%s", &centro[i].local);
				
			
			printf("\n");	
			printf("Pa�ses:\n\n");
			
			j=0;
			
			while(ultPais>j){
				printf("[%d] %s\n", j+1, paise[j].nomes);
				j++;
				
			}
			printf("\n");
			printf("Informe quantos pa�ses v�o utilizar esse local.\n");
			scanf("%d", &quantPais);
			
			if(quantPais > 0 && quantPais <= ultPais)
			{
				j = 0;
				
				for(j=0;j<quantPais;j++)
				{
					printf("\n");
					printf("Escolha o pa�s %d:\n", j+1);	
					scanf("%d", &opcaoPais);
					
					if(opcaoPais > 0 && opcaoPais <= ultPais)
					{
						strcpy(centro[i].pais[j].nomes , paise[opcaoPais-1].nomes);
					}
					else
					{
						printf("Op��o inv�lida!!\n");
						sleep(2);
						system("cls");
						printf("---------------------------------------------------------------------------------------------\n");
						printf("                                   CADASTRO CENTRO DE TREINAMENTO\n");
						printf("---------------------------------------------------------------------------------------------\n\n");
						printf("Entre novamente com os dados.\n");
						i--;
					}
				}
			}
			else
			{
				printf("Op��o inv�lida!!\n");
				sleep(2);
				system("cls");
				printf("---------------------------------------------------------------------------------------------\n");
				printf("                                   CADASTRO CENTRO DE TREINAMENTO\n");
				printf("---------------------------------------------------------------------------------------------\n\n");
				printf("Entre novamente com os dados.\n");
				i--;
			}
			
		
			
			if(i+1 == quant)
			{
				printf("Deseja visualizar os dados informados ?\nDigite 1 para SIM e 0 para N�O:\n");
				scanf("%d", &ver);
				
				if(ver == 1)
				{
						printf("Id: %d \n", centro[i].idNUm);
						printf("Nome: %s \n", centro[i].nome);
						j=0;
						
						while(j<quantPais)
						{
							printf("Pais %d: %s \n", j+1, centro[i].pais[j].nomes);	
							j++;
						}
					
					printf("Confirma as informa��es ?\nDigite 1 para SIM e 0 para N�O:\n");
					scanf("%d", &confirma);
					
					if(confirma == 1)
					{
						fseek(centros, 0, SEEK_END);
						fwrite(&centro, sizeof(CentroTreinamento), 1, centros);
						system("cls");
						printf("Dados salvos com sucesso!!\n\n");
						fclose(centros);
						sleep(2);
						menuprincipal();	
					}
					else
					{
						printf("Os dados n�o foram salvos!!\n");
						sleep(2);
						system("cls");
						printf("---------------------------------------------------------------------------------------------\n");
						printf("                                   CADASTRO CENTRO DE TREINAMENTO\n");
						printf("---------------------------------------------------------------------------------------------\n\n");
						printf("Entre novamente com os dados.\n");
						i--;
						
					}
					
				}
				else
				{
					printf("Confirma as informa��es ?\nDigite 1 para SIM e 0 para N�O:\n");
					scanf("%d", &confirma);
					
					if(confirma == 1)
					{
						fseek(centros, 0, SEEK_END);
						fwrite(&centro, sizeof(CentroTreinamento), 1, centros);
						system("cls");
						printf("Dados salvos com sucesso!!\n\n");
						fclose(centros);
						sleep(2);
						menuprincipal();	
						
					}
					else
					{
						printf("Os dados n�o foram salvos!!\n");
						fclose(centros);
						sleep(2);
						menuprincipal();
					}	
				 }
			}
			
					
		}	
	}		
	
	
	
	
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
			printf("Op��o invalida!!\n");
			sleep(2);
			menuprincipal();
						
	}
		
}


void cadastros(int cadastros){
	
	int opcaoCad;
		
		switch(cadastros){
			case 1:
				
						system("cls");
						printf("---------------------------------------------------------------------------------------------\n");
						printf("                                   CADASTROS DE PESSOAS\n");
						printf("---------------------------------------------------------------------------------------------\n\n");
						printf("\n");
						printf(" [1] Atletas \n [2] Funcion�rios \n [3] M�dicos \n [4] Volunt�rios \n [5] Equipe Ol�mpica \n [6] Voltar \n \n ");
						printf("Escolha uma das opcoes: \n");
						scanf("%d", &opcaoCad);
						
						if(opcaoCad == 6)
							menuprincipal();
						else if(opcaoCad < 1 || opcaoCad > 6)
							{
								printf("Op��o inv�lida!!");
								sleep(2);
								menuprincipal();
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
				locaisJogos();
				break;	
					
			case 6:
				system("cls");
				equipamentos();
				break;
			
			case 7:
				system("cls");
				centroTreinamento();
				break;		
						
			default:
				printf(" Opcao invalida");
				menuprincipal();
				break;					
		}
		
	}
	
void calendario(){
	printf("Calendario Olimpico \n");
	sleep(4);
	menuprincipal();
}	


void premiacao(){
	printf("Premiacao \n ");
	sleep(4);
	menuprincipal();
}


void consultaAtletas()
{
	FILE *atletas;
	
	char caminho[] = "C:/Gestao Olimpiada/atletas.txt";
	char s;
	
	atletas = fopen(caminho, "r");
	
	int idult, i=0;
	Atleta atleta;
	
	if(atletas != NULL)
	{
		if(get_size(caminho) == 0)
			{
  				  printf("Nenhum atleta cadastrado.\n");
			}
		else		
			{
					fseek(atletas, -1*sizeof(Atleta),SEEK_END);
   				 	fread(&atleta, sizeof(Atleta), 1, atletas);
   					idult = atleta.idNUm;
				
					Atleta atlet[idult];
					
					rewind(atletas);
					
					while(!feof(atletas))
					{
						
	   				 	fread(&atleta, sizeof(Atleta), 1, atletas);
	   					atlet[i].idNUm = atleta.idNUm;
	   					strcpy(atlet[i].nome, atleta.nome);
	   					strcpy(atlet[i].sobrenome, atleta.sobrenome);
	   					strcpy(atlet[i].pais, atleta.pais);
	   					strcpy(atlet[i].modalidade, atleta.modalidade);
	   					atlet[i].medalhasOuro = atleta.medalhasOuro;
	   					atlet[i].medalhasPrata = atleta.medalhasPrata;
	   					atlet[i].medalhasbronze = atleta.medalhasbronze;
	   					i++;
						
					}
					
					fclose(atletas);
					
					i=0;
					
					system("cls");
					printf("---------------------------------------------------------------------------------------------\n");
					printf("                                   CONSULTA CADASTRO DE ATLETAS\n");
					printf("---------------------------------------------------------------------------------------------\n\n");
					
					while(i<idult)
					{
						printf("Id: %d \n",atlet[i].idNUm);
						printf("Nome: %s \n",atlet[i].nome);
						printf("Sobrenome: %s \n", atlet[i].sobrenome);
						printf("Modalidade: %s \n",atlet[i].modalidade);
						printf("Pa�s: %s \n",atlet[i].pais);
						printf("Medalhas de ouro: %d \n",atlet[i].medalhasOuro);
						printf("Medalhas de prata: %d \n",atlet[i].medalhasPrata);
						printf("Medalhas de bronze: %d \n\n",atlet[i].medalhasbronze);
	   					
						i++;	
					}
					
					system("pause");
					menuprincipal();
				 	
		  }
	}
	else{
		printf("Nenhum atleta cadastrado.\n");
		sleep(2);
		menuprincipal();
	}
	
	
}

void consultaFuncionarios(){
	
	FILE *funcionarios;
	
	char caminho[] = "C:/Gestao Olimpiada/funcionarios.txt";
	
	
	funcionarios = fopen(caminho, "r");
	
	int idult, i=0;
	Funcionarios funcionario;
	
	if(funcionarios != NULL)
	{
		if(get_size(caminho) == 0)
			{
  				  printf("Nenhum funcionario cadastrado.\n");
			}
		else		
			{
					fseek(funcionarios, -1*sizeof(Funcionarios),SEEK_END);
   				 	fread(&funcionario, sizeof(Funcionarios), 1, funcionarios);
   					idult = funcionario.idNUm;
				
					Funcionarios funci[idult];
					
					rewind(funcionarios);
					
					while(i<idult)
					{
						fseek(funcionarios,sizeof(Funcionarios),SEEK_END);
	   				 	fread(&funcionario, sizeof(Funcionarios), 1, funcionarios);
	   					funci[i].idNUm = funcionario.idNUm;
	   					strcpy(funci[i].nome, funcionario.nome);
	   					strcpy(funci[i].sobrenome, funcionario.sobrenome);
	   					strcpy(funci[i].funcao, funcionario.funcao);
	   				
	   					i++;
						
					}
					
					fclose(funcionarios);
					
					i=0;
					
					system("cls");
					printf("---------------------------------------------------------------------------------------------\n");
					printf("                                   CONSULTA CADASTRO DE FUNCIONARIOS\n");
					printf("---------------------------------------------------------------------------------------------\n\n");
					
					while(i<idult)
					{
						printf("Id: %d \n",funci[i].idNUm);
						printf("Nome: %s \n",funci[i].nome);
						printf("Sobrenome: %s \n", funci[i].sobrenome);
						printf("Modalidade: %s \n\n",funci[i].funcao);
					
						i++;	
					}
					
					system("pause");
					menuprincipal();
				 	
		  }
	}
	else{
		printf("Nenhum funcionario cadastrado.\n");
		sleep(2);
		menuprincipal();
	}
	
	
	
}

void consultaMedicos(){
}

void consultaVoluntarios(){
}

void consultaEquip(){
}

void  consultarPessoasCad(int op){
	
	switch(op)
	{
		case 1:
			consultaAtletas();
			break;	
		case 2:
			consultaFuncionarios();
			break;
		case 3:
			consultaMedicos();
			break;
		case 4:
			consultaVoluntarios();
			break;			
		case 5:
			consultaEquip();
			break;
		default:
			printf("Op��o invalida!!\n");
			sleep(2);
			menuprincipal();
		
	}
	
}

void consultaPaises(){
	
	FILE *paises;
	
	char caminho[] = "C:/Gestao Olimpiada/paises.txt";
	
	
	paises = fopen(caminho, "r");
	
	int idult, i=0;
	Paises pais;
	
	if(paises != NULL)
	{
		if(get_size(caminho) == 0)
			{
  				  printf("Nenhum pais cadastrado.\n");
			}
		else		
			{
					fseek(paises, -1*sizeof(Paises),SEEK_END);
   				 	fread(&pais, sizeof(Paises), 1, paises);
   					idult = pais.idNUm;
				
					Paises pai[idult];
					
					rewind(paises);
					
					while(!feof(paises))
					{
					
	   				 	fread(&pais, sizeof(Paises), 1, paises);
	   					pai[i].idNUm = pais.idNUm;
	   					strcpy(pai[i].nomes, pais.nomes);
	   					pai[i].medalhasOuro = pais.medalhasOuro;
	   					pai[i].medalhasPrata = pais.medalhasPrata;
	   					pai[i].medalhasbronze = pais.medalhasbronze;
	   				
	   					i++;
						
					}
					
					fclose(paises);
					
					i=0;
					
					system("cls");
					printf("---------------------------------------------------------------------------------------------\n");
					printf("                                   CONSULTA CADASTRO DE PAISES\n");
					printf("---------------------------------------------------------------------------------------------\n\n");
					
					while(i<idult)
					{
						printf("Id: %d \n",pai[i].idNUm);
						printf("Nome: %s \n",pai[i].nomes);
						printf("Medalhas de Ouro: %d \n",pai[i].medalhasOuro);
						printf("Medalhas de Prata: %d \n",pai[i].medalhasPrata);
						printf("Medalhas de Bronze: %d \n\n",pai[i].medalhasbronze);
					
					
						i++;	
					}
					
					system("pause");
					menuprincipal();
				 	
		  }
	}
	else{
		printf("Nenhum pais cadastrado.\n");
		sleep(2);
		menuprincipal();
	}
	
	
	
}

void consultaModalidades(){
}

void consultaAlojamentos(){
}

void consultaLocaisJogos(){
}

void consultaEquipamentos(){
}

void consultaCentroTreinamento(){
}

void consultas(int opcao){
	
	int opcaoConsulta;
		
		switch(opcao){
			case 1:
				
						system("cls");
						printf("---------------------------------------------------------------------------------------------\n");
						printf("                                   CONSULTA CADASTRO DE PESSOAS\n");
						printf("---------------------------------------------------------------------------------------------\n\n");
						printf("\n");
						printf(" [1] Atletas \n [2] Funcion�rios \n [3] M�dicos \n [4] Volunt�rios \n [5] Equipe Ol�mpica \n [6] Voltar \n \n ");
						printf("Escolha uma das opcoes: \n");
						scanf("%d", &opcaoConsulta);
						
						if(opcaoConsulta == 6)
							menuprincipal();
						else if(opcaoConsulta < 1 || opcaoConsulta > 6)
							{
								printf("Op��o inv�lida!!");
								sleep(2);
								menuprincipal();
							}
						else
						    consultarPessoasCad(opcaoConsulta);
					
					
				break;
				
			case 2:
				system("cls");
				consultaPaises();		
				break;
				
			case 3:
				system("cls");
				consultaModalidades();
				break;
				
			case 4:
				system("cls");
				consultaAlojamentos();
				break;
				
			case 5:
				system("cls");
				consultaLocaisJogos();
				break;	
					
			case 6:
				system("cls");
				consultaEquipamentos();
				break;
			
			case 7:
				system("cls");
				consultaCentroTreinamento();
				break;		
						
			default:
				printf(" Opcao invalida");
				menuprincipal();
				break;					
		}
	
}

void menuRelatorios(int opcao){
	system("cls");
	int consulta;
	
	switch(opcao)
	{
		case 1:
			printf("Relat�rios.\n");
			sleep(3);
			menuprincipal();
			break;
		case 2:
			printf("Relat�rios.\n");
			sleep(3);
			menuprincipal();
			break;
		case 3:
			printf("Relat�rios.\n");
			sleep(3);
			menuprincipal();
			break;	
		case 4:
			system("cls");
			printf("---------------------------------------------------------------------------------------------\n");
			printf("                                   CONSULTAS DE CADASTROS \n");
			printf("---------------------------------------------------------------------------------------------\n\n");
			printf(" [1] Pessoas \n [2] Paises \n [3] Modalidades \n [4] Alojamentos\n [5] Locais de Jogos\n [6] Equipamentos \n [7] Centro de treinamento\n [8] Voltar \n\n");
			printf(" Escolha uma das opcoes: \n");
			scanf("%d", &consulta);
			
			if(consulta > 0 && consulta < 8 )
				consultas(consulta);	
			else if(consulta == 8)
			{
				//sleep(1);
				menuprincipal();
			}
			else{
				printf("Op��o inv�lida!!\n");
				sleep(2);
				menuprincipal();
			}

			break;
		
		default:
			printf("Op��o invalida.\n");
			sleep(3);
			menuprincipal();
			break;
	}
	
	
}

void menus(opcao){
	
	int cadastro, relatorios;
	
		switch(opcao)
				{
					case 1:
						system("cls");
						printf("---------------------------------------------------------------------------------------------\n");
						printf("                                   CADASTROS \n");
						printf("---------------------------------------------------------------------------------------------\n\n");
						printf(" [1] Pessoas \n [2] Paises \n [3] Modalidades \n [4] Alojamentos\n [5] Locais de Jogos\n [6] Equipamentos \n [7] Centro de treinamento\n [8] Voltar \n\n");
						printf(" Escolha uma das opcoes: \n");
						scanf("%d", &cadastro);
						
						if(cadastro > 0 && cadastro < 8 )
							cadastros(cadastro);	
						else if(cadastro == 8)
						{
							//sleep(1);
							menuprincipal();
						}
						else{
							printf("Op��o inv�lida!!\n");
							sleep(2);
							menuprincipal();
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
						printf(" [1] Ranking dos pa�ses \n [2] Resumo por atleta \n [3] Total de medalhas por categoria \n [4] Consulta cadastros \n [5] Voltar\n\n");
						printf("Escolha uma op��o:\n");
						scanf("%d", &relatorios);
						
						if(relatorios > 0 && relatorios < 5)
							menuRelatorios(relatorios);
						else if(relatorios == 5)
							menuprincipal();
						else
						{
							printf("Op��o inv�lida.\n");
							sleep(2);
							menuprincipal();	
						}
							
						break;
					
					default:
						printf(" Digite uma op��o valida!! \n ");
						break;
				}
							
	
}

void menuprincipal()
{
	
	system("cls");
	
	int opcao;

	printf("---------------------------------------------------------------------------------------------\n");
	printf("                                   MENU PRINCIPAL \n");
	printf("---------------------------------------------------------------------------------------------\n\n");
	printf(" [1] Cadastros \n [2] Calendario Olimpico \n [3] Premiacao \n [4] Relatorios \n [5] Sair \n \n");
	printf(" Escolha uma das opcoes \n");
	scanf("%d", &opcao);
	
	if(opcao > 0 && opcao < 5 )
		{
			
			menus(opcao);

		}
		else if (opcao == 5)
			exit(3);
		else	
			{
				printf("Op��o inv�lida!");
				sleep(2);
				menuprincipal();
			}
	
}

void login(){
	
	char usuarioFixo[] = "admin"; //nome de login fixo
	char usuario[20]; //nome que o usuario digita
	char senhaFixa[] = "admin123"; //senha fixa
	char senha[12]; //senha que o usuario digita
	int i;
	char ch;
	
	printf("Entre com usuario e senha para acessar o sistema.\n\n");
	
	printf("Usuario: ");	//Entrada dos dados
	gets(usuario);
	printf("Senha: ");
	for(i = 0;i < 12;i++)
	{
		ch = getch();
		if(ch == 13)
		break;
		senha[i] = ch;
		ch = '*' ;
		printf("%c", ch);
	}
	senha[i] = '\0';
	
	
	
	printf("\n"); //quebra de linha para separar
	
	if ((strcmp(usuario, usuarioFixo) == 0) && strcmp(senha, senhaFixa) == 0) {	//verifica usuario e senha
	
		printf("\nLogin efetuado com sucesso!\n"); //efetua o login
		sleep(2);
		menuprincipal();
	}
	else {
	
		printf("\nUsuario ou senha incorretos, tente novamente.");
		sleep(2);
		main();
	}
}

int main(){
	
	//ICON "logo.ico";
	
	setlocale(LC_ALL, "portuguese");
	system("cls");
	

	
	if( _mkdir( "C:/Gestao Olimpiada" ) == 0 )
   {
      //printf( "Directory '\\\"Gestao Olimpiada\"' was successfully created\n" );
      
	
   }
   
   	login();
   
    
   
     
	return 0;
}
