#include<stdio.h>
#include<math.h>
#include<locale.h>
#include<Windows.h>
#include<string.h>
#include<direct.h>
#include<stdlib.h>
#include <ctype.h>
#include<stdbool.h>  

// Structs

typedef struct{
	int id;
	int total;
	int ouro;
	int prata;
	int bronze;
	
}Medalhas;

typedef struct{
	int idNUm;
	char nomes[20];
	Medalhas medalhas;
	
}Paises;

typedef struct{
	int idNUm;
	char modalidades[20];
	Medalhas medalhas;
	
}Modalidades;

typedef struct{
	int idNUm;
	char nome[20];
	char sobrenome[20];
	char modalidade[20];
	char pais[20];
	Medalhas medalhas;
	
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
 	Paises pais[100];
	int quantPais;
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
	int quantpais;
	
}CentroTreinamento;

typedef struct{
	int idNUm;
	char equipamentos[40];
	
}Equipamentos;

typedef struct{
	int dia;
	int mes;
	int ano;
	int hora;
	int minuto;
}Data;

typedef struct{
	int idNum;
	char nome[20];
	char tipo[20];
	Paises pais[100];
	Modalidades modalidade;
	LocaisJogos locais;
	Data dataInico;
	Data dataTermino;
	int quantpais;
}Evento;

//Fim Structs


// Prototipos

//Verifica o tamanho do arquivo txt
int get_size(const char*);

//Verifica o ultimo id, caso tenha algum cadastro, senão retorna 0
int ultimo_id(const char*, char *);

//Verifica se a data é válida
bool validarData(int, int, int);

//verifica se a hora é válida
bool validahora(int, int);

//Função para cadastrar atletas
void cadastroAtletas();

//Função para cadastrar funcionarios
void cadastroFuncionarios();

//Função para cadastrar medicos
void cadastroMedicos();

//Função para cadastrar voluntarios
void cadastroVoluntarios();

//Função para cadastrar equipes
void cadastroEquip();

//Função para cadastrar paises
void paises();

//Função para cadastrar modalidades
void modalidades();

//Função para cadastrar alojamentos
void alojamentos();

//Função para cadastrar locais de jogos
void locaisJogos();

//Função para cadastrar equipamentos
void equipamentos();

//Função para cadastrar locais de treinamento
void centroTreinamento();

//Função para cadastrar eventos
void eventos();

//Função para cadastrar medalhas
void medalhasOlimpicas();

//Função para consultar calendario
void calendario();

//Função para consultar cadastro de atletas
void consultaAtletas();

//Função para consultar cadastro de funcionarios
void consultaFuncionarios();

//Função para consultar cadastro de medicos
void consultaMedicos();

//Função para consultar cadastro de voluntarios
void consultaVoluntarios();

//Função para consultar cadastro de atletas
void consultaEquip();

//Função para consulta de resumo por atleta
void consultaResumoatleta();

//Função menu que chama as opções de consulta
void consultarPessoasCad(int);

//Função para consultar cadastro de paises
void consultaPaises();

//Função para consultar cadastro de modaliaddes
void consultaModalidades();

//Função para consultar cadastro de alojamentos
void consultaAlojamentos();

//Função para consultar cadastro de locais de jogos
void consultaLocaisJogos();

//Função para consultar cadastro de equipamentos
void consultaEquipamentos();

//Função para consultar cadastro de locais de treinamento
void consultaCentroTreinamento();

//Mostra o total de cada cadastro realizado
void consultaNumerosdeCadastros();

//Função menu consultas
void consultas(int);

//Função menu relatórios
void menuRelatorios(int);

//Função menus que chama as opções de cadastros
void menus(int);

//Função do menu principal
void menuprincipal();

//Função para efetuar o login
void login();

// Fim prototipos

//função principal do programa
int main(){
	
	
	//Faz o programa aceitar o caracteres da lingua portugesa
	setlocale(LC_ALL, "portuguese");
	system("cls");

	//cria a pasta Gestão Olipiada no disco C
	if( _mkdir( "C:/Gestao Olimpiada" ) == 0 )
   {
      //printf( "Directory '\\\"Gestao Olimpiada\"' was successfully created\n" );
      fopen("C:/Gestao Olimpiada/atletas.txt","a");
      fopen("C:/Gestao Olimpiada/alojamentos.txt","a");
      fopen("C:/Gestao Olimpiada/centrotreinamento.txt","a");
      fopen("C:/Gestao Olimpiada/equipamentos.txt","a");
      fopen("C:/Gestao Olimpiada/equipes.txt","a");
      fopen("C:/Gestao Olimpiada/funcionarios.txt","a");
      fopen("C:/Gestao Olimpiada/locaisjogos.txt","a");
      fopen("C:/Gestao Olimpiada/medicos.txt","a");
      fopen("C:/Gestao Olimpiada/modalidades.txt","a");
      fopen("C:/Gestao Olimpiada/paises.txt","a");
      fopen("C:/Gestao Olimpiada/voluntarios.txt","a");
      
	
   }
   
   //chama função login
   	login();
   	
	return 0;
}



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


int ultimo_id(const char* cam_arq, char *nome)
{
	int id=0;
	
	FILE *file = fopen(cam_arq, "r");

    if(file == NULL)
        return 0;
        
     	if(strcmp(nome, "atleta" ) == 0 && get_size(cam_arq) > 0)
		{
			Atleta atleta;
			
			fseek(file, -1*sizeof(atleta),SEEK_END);
		  	fread(&atleta, sizeof(atleta), 1, file); 
		  	id = atleta.idNUm;
  			fclose(file);
  			
			return id;
		}
		else if(strcmp(nome, "pais")==0 && get_size(cam_arq) > 0)
		{
			Paises pais;
			
			fseek(file, -1*sizeof(pais),SEEK_END);
		  	fread(&pais, sizeof(pais), 1, file); 
		  	id = pais.idNUm;
		  	
		  	fclose(file);
		  	
		  	return id;
		}
		else if(strcmp(nome, "modalidade")==0 && get_size(cam_arq) > 0)
		{
			Modalidades modalidade;
			
			fseek(file, -1*sizeof(modalidade),SEEK_END);
		  	fread(&modalidade, sizeof(modalidade), 1, file); 
		  	id = modalidade.idNUm;
		  	
		  	fclose(file);
		  	
		  	return id;
		}
		else if(strcmp(nome, "funcionario")==0 && get_size(cam_arq) > 0)
		{
			Funcionarios funcio;
			
			fseek(file, -1*sizeof(funcio),SEEK_END);
		  	fread(&funcio, sizeof(funcio), 1, file); 
		  	id = funcio.idNUm;
		  	
		  	fclose(file);
		  	
		  	return id;
		}
		else if(strcmp(nome, "medico")==0 && get_size(cam_arq) > 0)
		{
			Medicos med;
			
			fseek(file, -1*sizeof(med),SEEK_END);
		  	fread(&med, sizeof(med), 1, file); 
		  	id = med.idNUm;
		  	
		  	fclose(file);
		  	
		  	return id;
		}
		else if(strcmp(nome, "voluntario")==0 && get_size(cam_arq) > 0)
		{
			Voluntarios vol;
			
			fseek(file, -1*sizeof(vol),SEEK_END);
		  	fread(&vol, sizeof(vol), 1, file); 
		  	id = vol.idNUm;
		  	
		  	fclose(file);
		  	
		  	return id;
		}
		else if(strcmp(nome, "equipe")==0 && get_size(cam_arq) > 0)
		{
			EquipeOlimpica equip;
			
			fseek(file, -1*sizeof(equip),SEEK_END);
		  	fread(&equip, sizeof(equip), 1, file); 
		  	id = equip.idNUm;
		  	
		  	fclose(file);
		  	
		  	return id;
		}
		else if(strcmp(nome, "alojamento")==0 && get_size(cam_arq) > 0)
		{
			Alojamentos aloj;
			
			fseek(file, -1*sizeof(aloj),SEEK_END);
		  	fread(&aloj, sizeof(aloj), 1, file); 
		  	id = aloj.idNUm;
		  	
		  	fclose(file);
		  	
		  	return id;
		}
		else if(strcmp(nome, "localjogo")==0 && get_size(cam_arq) > 0)
		{
			LocaisJogos local;
			
			fseek(file, -1*sizeof(local),SEEK_END);
		  	fread(&local, sizeof(local), 1, file); 
		  	id = local.idNUm;
		  	
		  	fclose(file);
		  	
		  	return id;
		}
		else if(strcmp(nome, "centro")==0 && get_size(cam_arq) > 0)
		{
			CentroTreinamento centro;
			
			fseek(file, -1*sizeof(centro),SEEK_END);
		  	fread(&centro, sizeof(centro), 1, file); 
		  	id = centro.idNUm;
		  	
		  	fclose(file);
		  	
		  	return id;
		}
		else if(strcmp(nome, "equipamento")==0 && get_size(cam_arq) > 0)
		{
			Equipamentos equipa;
			
			fseek(file, -1*sizeof(equipa),SEEK_END);
		  	fread(&equipa, sizeof(equipa), 1, file); 
		  	id = equipa.idNUm;
		  	
		  	fclose(file);
		  	
		  	return id;
		}
		else if(strcmp(nome, "evento")==0 && get_size(cam_arq) > 0)
		{
			Evento evento;
			
			fseek(file, -1*sizeof(evento),SEEK_END);
		  	fread(&evento, sizeof(evento), 1, file); 
		  	id = evento.idNum;
		  	
		  	fclose(file);
		  	
		  	return id;
		}
		else if(strcmp(nome, "medalha")==0 && get_size(cam_arq) > 0)
		{
			Medalhas medalha;
			
			fseek(file, -1*sizeof(medalha),SEEK_END);
		  	fread(&medalha, sizeof(medalha), 1, file); 
		  	id = medalha.id;
		  	
		  	fclose(file);
		  	
		  	return id;
		}
		else
		{	
			return id;
		} 
		   
	
	
}


bool validarData(int dia, int mes, int ano){
	
	if(ano>=1900 && ano<=9999)
	{
		
		if(mes>=1 && mes<=12)
		{
		
			if((dia>=1 && dia<=31) && (mes==1 || mes==3 || mes==5 || mes==7 || mes==8 || mes==10 || mes==12))
				return true;
			else if((dia>=1 && dia<=30) && (mes==4 || mes==6 || mes==9 || mes==11))
				return true;
			else if((dia>=1 && dia<=28) && (mes==2))
				return true;
			else if(dia==29 && mes==2 && (ano%400==0 ||(ano%4==0 && ano%100!=0)))
				return true;
			else
				return false;
		}
		else
		{
			return false;
		}
	}
	else
	{
		return false;
	}
	  
	
	
}

bool validahora(int horas , int min)
{
    if(horas >24 || horas < 0)  return false;
    else return true;
    if(min>60 || min < 0)   return false;
    else return true;
}

void login(){
	
	char usuarioFixo[] = "admin"; //nome de login fixo
	char usuario[20]; //nome que o usuario digita
	char senhaFixa[] = "admin123"; //senha fixa
	char senha[12]; //senha que o usuario digita
	int i;
	char ch;
	
	system("cls");
	printf("---------------------------------------------------------------------------------------------\n");
	printf("                                   SISTEMA DE GESTAO DE OLIMPIADAS \n");
	printf("---------------------------------------------------------------------------------------------\n\n");
	
	printf("Faça login para acessar o sistema.\n\n");
	
	printf("Usuario: ");	//Entrada dos dados
	gets(usuario);
	printf("Senha: ");
	for(i = 0;i < 12;i++)
	{
		ch = getch();
		if(ch == 13 )
			break;
		
		
		senha[i] = ch;
		
		ch = '*' ;
		printf("%c", ch);
	}
	senha[i] = '\0';
	
	
	
	printf("\n"); //quebra de linha para separar
	
	if ((strcmp(usuario, usuarioFixo) == 0) && strcmp(senha, senhaFixa) == 0) {	//verifica usuario e senha
			printf("\nLogin efetuado com sucesso!\n");	
   			sleep(2);
   			menuprincipal(); 
	}
	else {
			printf("\nUsuario ou senha incorretos, tente novamente.");
			sleep(2);
			main();
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
				printf("Opção inválida!");
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
						printf(" [1] Atletas \n [2] Funcionários \n [3] Médicos \n [4] Voluntários \n [5] Equipe Olímpica \n [6] Voltar \n \n ");
						printf("Escolha uma das opcoes: \n");
						scanf("%d", &opcaoCad);
						
						if(opcaoCad == 6)
							menuprincipal();
						else if(opcaoCad < 1 || opcaoCad > 6)
							{
								printf("Opção inválida!!");
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
						
			case 8:
				system("cls");
				eventos();
				break;
								
			case 9:
				system("cls");
				medalhasOlimpicas();
				break;					
						
			default:
				printf(" Opcao invalida");
				menuprincipal();
				break;					
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
			printf("Opção invalida!!\n");
			sleep(2);
			menuprincipal();
						
	}
		
}


void menus(int opcao){
	
	int cadastro, relatorios;
	
		switch(opcao)
				{
					case 1:
						system("cls");
						printf("---------------------------------------------------------------------------------------------\n");
						printf("                                   CADASTROS \n");
						printf("---------------------------------------------------------------------------------------------\n\n");
						printf(" [1] Pessoas \n [2] Paises \n [3] Modalidades \n [4] Alojamentos\n [5] Locais de Jogos\n [6] Equipamentos \n [7] Centro de treinamento\n [8] Eventos \n [9] Medalhas \n [10] Voltar \n\n");
						printf(" Escolha uma das opcoes: \n");
						scanf("%d", &cadastro);
						
						if(cadastro > 0 && cadastro < 10 )
							cadastros(cadastro);	
						else if(cadastro == 10)
						{
							//sleep(1);
							menuprincipal();
						}
						else{
							printf("Opção inválida!!\n");
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
						printf(" [1] Ranking dos países \n [2] Resumo por atleta \n [3] Total de medalhas por categoria \n [4] Consulta cadastros \n [5] Voltar\n\n");
						printf("Escolha uma opção:\n");
						scanf("%d", &relatorios);
						
						if(relatorios > 0 && relatorios < 5)
							menuRelatorios(relatorios);
						else if(relatorios == 5)
							menuprincipal();
						else
						{
							printf("Opção inválida.\n");
							sleep(2);
							menuprincipal();	
						}
							
						break;
					
					default:
						printf(" Digite uma opção valida!! \n ");
						break;
				}
							
	
}

void menuRelatorios(int opcao){
	system("cls");
	int consulta;
	
	switch(opcao)
	{
		case 1:
			printf("Relatórios.\n");
			sleep(3);
			menuprincipal();
			break;
		case 2:
			/*printf("Relatórios.\n");
			sleep(3);
			menuprincipal();*/
			consultaResumoatleta();
			break;
		case 3:
			printf("Relatórios.\n");
			sleep(3);
			menuprincipal();
			break;	
		case 4:
			system("cls");
			printf("---------------------------------------------------------------------------------------------\n");
			printf("                                   CONSULTAS DE CADASTROS \n");
			printf("---------------------------------------------------------------------------------------------\n\n");
			printf(" [1] Pessoas \n [2] Paises \n [3] Modalidades \n [4] Alojamentos\n [5] Locais de Jogos\n [6] Equipamentos \n [7] Centro de treinamento\n [8] Consultar numeros de cadastros \n [9]Voltar \n\n");
			printf(" Escolha uma das opcoes: \n");
			scanf("%d", &consulta);
			
			if(consulta > 0 && consulta < 9 )
				consultas(consulta);	
			else if(consulta == 9)
			{
				//sleep(1);
				menuprincipal();
			}
			else{
				printf("Opção inválida!!\n");
				sleep(2);
				menuprincipal();
			}

			break;
		
		default:
			printf("Opção invalida.\n");
			sleep(3);
			menuprincipal();
			break;
	}
	
	
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
						printf(" [1] Atletas \n [2] Funcionários \n [3] Médicos \n [4] Voluntários \n [5] Equipe Olímpica \n [6] Voltar \n \n ");
						printf("Escolha uma das opcoes: \n");
						scanf("%d", &opcaoConsulta);
						
						if(opcaoConsulta == 6)
							menuprincipal();
						else if(opcaoConsulta < 1 || opcaoConsulta > 6)
							{
								printf("Opção inválida!!");
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
						
			case 8:
				system("cls");
				consultaNumerosdeCadastros();
				break;	
								
			default:
				printf(" Opcao invalida");
				menuprincipal();
				break;					
		}
	
}


void calendario(){
	//printf("Calendario Olimpico \n");
	//sleep(4);
	//menuprincipal();
	
	FILE *eventos;
	
	int idevento, contador=0, j, quantpaises[100], quant=0;
	char caminho[] = "C:/Gestao Olimpiada/eventos.txt";
	char caminho1[] = "C:/Gestao Olimpiada/paises.txt";
	
	eventos = fopen(caminho, "r");
	
	Evento evento;
	Evento event[100];
	Paises paises[100];

	if(eventos != NULL && get_size(caminho) != 0)
	{
			idevento = ultimo_id(caminho, "evento");
			quant = ultimo_id(caminho1, "pais");
			
				while(!feof(eventos))
					{
						fread(&evento, sizeof(Evento),1,eventos);
						event[contador] = evento;
						quantpaises[contador] = event[contador].quantpais;	
						contador++;
					}
					
					fclose(eventos);
					
					printf("---------------------------------------------------------------------------------------------\n");
					printf("                                   CALENDARIO EVENTOS \n");
					printf("---------------------------------------------------------------------------------------------\n\n");
					
					contador = 0;
					
					while(contador<idevento)
					{
						//printf("Id %d\n", event[contador].idNum);
						printf("Nome do evento: %s\n", event[contador].nome);
						printf("Tipo de evento: %s\n", event[contador].tipo);
						
							j = 0;
						
						
							while(j < quantpaises[j])
							{
							
								if(quantpaises[j] == quant)
								{
									printf("Paises participantes: Todos\n" );
									break;
								}
								else
								{
									printf("Pais participante %d %s \n", j+1, event[contador].pais[j].nomes);
								}
							
								j++;
							
							}
						
						
						printf("Data inicio: %2d/%02d/%d\n", event[contador].dataInico.dia, event[contador].dataInico.mes, event[contador].dataInico.ano);
						printf("Data término: %02d/%02d/%d\n", event[contador].dataTermino.dia, event[contador].dataTermino.mes, event[contador].dataTermino.ano);
						printf("Hora inicio: %02d:%02d\n", event[contador].dataInico.hora, event[contador].dataInico.minuto);
						printf("Hora término: %02d:%02d\n\n", event[contador].dataTermino.hora, event[contador].dataTermino.minuto);
					
						contador++;
					}
					
					system("pause");
					sleep(2);	
					menuprincipal();			
	}
	else
	{
		printf("Nenhum evento cadastradado!!\n");
		sleep(2);
		menuprincipal();
	}
	
	
}	


void premiacao(){
	printf("Premiacao \n ");
	sleep(4);
	menuprincipal();
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
		/*	fseek(modalidade, -1*sizeof(Modalidades),SEEK_END);//saltar do final do arquivo (SEEK_END) para o inicio do ultimo registro
  			fread(&mods, sizeof(Modalidades), 1, modalidade); //ler o ultimo registro
  			ultMod = mods.idNUm;*/
  			ultMod = ultimo_id(modal, "modalidade");
  				
  				//printf ("id = %d ", ultMod); 
  				
			//rewind(modalidade);
		
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
						printf("Opção inválida!!\n");
						sleep(2);
						//menuprincipal();
						system("cls");
						printf("---------------------------------------------------------------------------------------------\n");
						printf("                                   CADASTRO ATLETAS \n");
						printf("---------------------------------------------------------------------------------------------\n\n");
						printf("Entre novamente com os dados.\n");
						i--;
						
						
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
						system("cls");
						printf("---------------------------------------------------------------------------------------------\n");
						printf("                                   CADASTRO ATLETAS \n");
						printf("---------------------------------------------------------------------------------------------\n\n");
						printf("Entre novamente com os dados.\n");
						i--;
					}
					
					atleta[i].medalhas.ouro = 0;
					atleta[i].medalhas.prata = 0;
					atleta[i].medalhas.bronze = 0;
						
						
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
							printf("Medalhas de ouro: %d \n",atleta[i].medalhas.ouro);
							printf("Medalhas de prata: %d \n",atleta[i].medalhas.prata);
							printf("Medalhas de bronze: %d \n",atleta[i].medalhas.bronze);
							
							printf("\n");
							printf("Confirma as informações?\nDigite 1 para SIM e 0 para NÂO:\n");
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
										 printf("Não foi possível salvar os dados!\n\n");
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
							menuprincipal();
						}
						else
						{
							printf("\n");
							printf("Confirma as informações?\nDigite 1 para SIM e 0 para NÂO:\n");
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
										printf("Os dados não foram salvos!\n");
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
						menuprincipal();
							
						
					}
					else{
						printf("Os dados não foram salvos!!\n");
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
						menuprincipal();	
					}
					else{
						printf("Os dados não foram salvos!!\n");
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
				printf("---------------------------------------------------------------------------------------------\n");
				printf("                                   CADASTRO MEDICOS \n");
				printf("---------------------------------------------------------------------------------------------\n\n");
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
						menuprincipal();
						
					}
					else
					{
						printf("Os dados não foram salvos!!\n");
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
						menuprincipal();
						
					}
					else
					{
						printf("Os dados não foram salvos!!\n");
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
						menuprincipal();
						
					}
					else
					{
						printf("Os dados não foram salvos!!\n");
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
						menuprincipal();
						
					}
					else
					{
						printf("Os dados não foram salvos!!\n");
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
				printf("---------------------------------------------------------------------------------------------\n");
				printf("                                   CADASTRO EQUIPE OLIMPICA \n");
				printf("---------------------------------------------------------------------------------------------\n\n");
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
						menuprincipal();	
					}
					else
					{
						printf("Os dados não foram salvos!!\n");
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
						menuprincipal();	
						
					}
					else
					{
						printf("Os dados não foram salvos!!\n");
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
	int i, quant=1, confirma, ver, ultimoid=0, contador=0, j=0, sair;
	char caminho[40] = "C:/Gestao Olimpiada/paises.txt";
	char nomes[40][15];
	char nome[40];
	
	paises = fopen(caminho, "a+");
	
	
	
	//printf("Informe quantos países deseja cadastrar:\n");
	//scanf("%d", &quant);
	
	Paises pais;
	Paises Paisescadastrados[100];
	
	 memset(&pais, 0, sizeof(Paises));
		
	if(paises != NULL)
	{
		if(get_size(caminho) == 0)
		{
  		  ultimoid = 0;
		}
		else		
		{
			/*fseek(paises, -1*sizeof(Paises),SEEK_END);//saltar do final do arquivo (SEEK_END) para o inicio do ultimo registro
  			fread(&paise, sizeof(Paises), 1, paises); //ler o ultimo registro*/
  			//ultimoid = paise.idNUm;
  			ultimoid = ultimo_id(caminho, "pais");
  				
  				
  			//rewind(paises);
  	
	 		while(!feof(paises))
		  	{
				fread(&pais, sizeof(Paises), 1, paises);
				Paisescadastrados[contador] = pais;
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
		
		//for(i=0;i<quant;i++)
		do{
			
		
			
			int pai = 0, compara=0;
			
			//ultimoid = ultimo_id(caminho, "pais");
			
			contador = 0;
			
			pais.idNUm = ultimoid+1;
			
			
			printf("insira o nome do país:\n");
			scanf("%s", &nome);
			
			for(pai=0;pai<=ultimoid;pai++)
			{
				compara = strcmp(nome, nomes[pai]);
				
					if(compara == 0)
					{
						system("cls");
						printf("País já cadastrado.\n");
						sleep(2);
						menuprincipal();
					}
					else{
						strcpy(pais.nomes, nome);
					}
				
			}
			
			pais.medalhas.ouro = 0;
			pais.medalhas.prata = 0;
			pais.medalhas.bronze = 0;
			pais.medalhas.total = 0;
			
			
				printf("Deseja visualizar o nome informado ?\nDigite 1 para SIM e 0 para NÂO:\n");
				scanf("%d", &ver);
				
				if(ver == 1){
				
					printf("Id: %d \n", pais.idNUm);
					printf("Pais: %s \n\n", pais.nomes);
						
					printf("Confirma as informações ? \nDigite 1 para SIM e 0 para NÂO:\n");
					scanf("%d", &confirma);
					
					if(confirma == 1)
					{
						fseek(paises, 0, SEEK_END);
						fwrite(&pais, sizeof(Paises), 1, paises);
						printf("Dados salvos com sucesso!!\n");
						
						
						printf("Deseja cadastrar mais paises?\nDigite 1 para SIM ou 0 para NÃO.\n");
						scanf("%d", &sair);
						
						if(sair == 1)
						{
							ultimoid = pais.idNUm;
							
							rewind(paises);
							
							while(!feof(paises))
							 	{
								fread(&pais, sizeof(Paises), 1, paises);
								Paisescadastrados[contador] = pais;
								contador++;			
							}
							
							j=0;
							
							while(j<=ultimoid)
							{
								strcpy(nomes[j], Paisescadastrados[j].nomes);
								j++;
							}
							
						}
						else
						{
							fclose(paises);
							sleep(2);
							menuprincipal();
						}
						
					}
					else{
						printf("Os dados não foram salvos!!\n");
						sleep(2);
						system("cls");
						printf("Deseja cadastrar mais paises?\nDigite 1 para SIM ou 0 para NÃO.\n");
						scanf("%d", &sair);
						
					}
					
				}
				else{
					printf("Confirma as informações ? \nDigite 1 para SIM e 0 para NÂO:\n");
					scanf("%d", &confirma);
					
					if(confirma == 1)
					{
						fseek(paises, 0, SEEK_END);
						fwrite(&pais, sizeof(Paises), 1, paises);
						printf("Dados salvos com sucesso!!\n");
						printf("\n");
						printf("Deseja cadastrar mais paises?\nDigite 1 para SIM ou 0 para NÃO.\n");
						scanf("%d", &sair);
						
						if(sair == 1)
						{
							ultimoid = pais.idNUm;
							
								rewind(paises);
								
								while(!feof(paises))
							  	{
									fread(&pais, sizeof(Paises), 1, paises);
									Paisescadastrados[contador] = pais;
									contador++;			
								}
								
								j=0;
							
								while(j<=ultimoid)
								{
									strcpy(nomes[j], Paisescadastrados[j].nomes);
									j++;
								}
								
						}
						else
						{
							fclose(paises);
							sleep(2);
							menuprincipal();
						}
					
					}
					else{
						printf("Os dados não foram salvos!!\n");
						fclose(paises);
						printf("\n");
						printf("Deseja cadastrar mais paises?\nDigite 1 para SIM ou 0 para NÃO.\n");
						scanf("%d", &sair);
					
						}
					}
				
			}while(sair!=0);		
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
				printf("Modalidade já cadastrada.\n");
				sleep(2);
				menuprincipal();
			}
			else{
				strcpy(modalidades[i].modalidades, modali);
			}
			
			
			modalidades[i].medalhas.ouro = 0;
			modalidades[i].medalhas.prata = 0;
			modalidades[i].medalhas.bronze = 0;
			modalidades[i].medalhas.total = 0;
			
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
						menuprincipal();
					}
					else{
						printf("Os dados não foram salvos!!\n");
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
						printf("Alojamento já cadastrado.\n");
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
			printf("Países:\n\n");
			
			j=0;
			
			while(ultPais>j){
				printf("[%d] %s\n", j+1, paise[j].nomes);
				j++;
				
			}
			printf("\n");
			printf("Informe quantos países vão utilizar esse local ou zero [0] ou %d para todos.\n", ultPais);
			scanf("%d", &quantPais);
			
			if(quantPais == 0  || quantPais == ultPais)
			{
				j = 0;
				
				alojamento[i].quantPais = ultPais;
				
					while(j<ultPais)
						{
							strcpy(alojamento[i].pais[j].nomes , paise[j].nomes);	
							j++;
						}
						
			}
			
			else if(quantPais > 0 && quantPais <= ultPais)
			{
				j = 0;
				
				alojamento[i].quantPais = quantPais;
				
				for(j=0;j<quantPais;j++)
				{
					printf("\n");
					printf("Escolha o país %d:\n", j+1);	
					scanf("%d", &opcaoPais);
					
					if(opcaoPais > 0 && opcaoPais <= ultPais)
					{
						strcpy(alojamento[i].pais[j].nomes , paise[opcaoPais-1].nomes);
					}
					else
					{
						printf("Opção inválida!!\n");
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
				printf("Opção inválida!!\n");
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
				printf("Deseja visualizar os dados informados ?\nDigite 1 para SIM e 0 para NÂO:\n");
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
						
					
					printf("Confirma as informações ?\nDigite 1 para SIM e 0 para NÂO:\n");
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
						printf("Os dados não foram salvos!!\n");
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
					printf("Confirma as informações ?\nDigite 1 para SIM e 0 para NÂO:\n");
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
						printf("Os dados não foram salvos!!\n");
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
	char nomes[50][15], temp;
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
					printf("Local já cadastrado.\n");
					sleep(2);
					menuprincipal();
				}
				else{
					strcpy(locais[i].nome, nome);
				}
				
			}
			
			printf("Insira o local:\n");
			scanf("%c", &temp);
			scanf("%[^\n]", &locais[i].local);
			
		
			
			if(i+1 == quant){
				printf("Deseja visualizar o nome informado ?\nDigite 1 para SIM e 0 para NÂO:\n");
				scanf("%d", &ver);
				
				if(ver == 1){
					int j = 0;
					
					while(j < quant){
						printf("Id: %d \n", locais[j].idNUm);
						printf("Nome: %s \n", locais[j].nome);
						printf("Local de jogo: %s \n\n", locais[j].local);
						j++;
					}
					
					
					printf("Confirma as informações ? \nDigite 1 para SIM e 0 para NÂO:\n");
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
						printf("Os dados não foram salvos!!\n");
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
					printf("Confirma as informações ? \nDigite 1 para SIM e 0 para NÂO:\n");
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
						printf("Os dados não foram salvos!!\n");
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
						printf("Equipamento já cadastrado.\n");
						sleep(2);
						menuprincipal();
					}
					else{
						strcpy(equipamento[i].equipamentos, nome);
					}
				
			}
			
		
			
			if(i+1 == quant){
				printf("Deseja visualizar o nome informado ?\nDigite 1 para SIM e 0 para NÂO:\n");
				scanf("%d", &ver);
				
				if(ver == 1){
					int j = 0;
					
					while(j < quant){
						printf("Id: %d \n", equipamento[j].idNUm);
						printf("Equipamento: %s \n\n", equipamento[j].equipamentos);
						j++;
					}
					
					
					printf("Confirma as informações ? \nDigite 1 para SIM e 0 para NÂO:\n");
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
						printf("Os dados não foram salvos!!\n");
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
					printf("Confirma as informações ? \nDigite 1 para SIM e 0 para NÂO:\n");
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
						printf("Os dados não foram salvos!!\n");
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
						printf("Local já cadastrado.\n");
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
			printf("Países:\n\n");
			
			j=0;
			
			while(ultPais>j){
				printf("[%d] %s\n", j+1, paise[j].nomes);
				j++;
				
			}
			printf("\n");
			printf("Informe quantos países vão utilizar esse local ou 0 ou %d para todos.\n", ultPais);
			scanf("%d", &quantPais);
			
			if(quantPais == 0 || quantPais == ultPais)
			{
				j = 0;
				
				centro[i].quantpais = ultPais;
				
				for(j=0;j<ultPais;j++)
				{
				
					strcpy(centro[i].pais[j].nomes , paise[j].nomes);
				}
					
					printf("Todos os paises foram adicionados.\n");
				
			}
			else if(quantPais > 0 && quantPais <= ultPais)
			{
				j = 0;
				
				centro[i].quantpais = quantPais;
				
				for(j=0;j<quantPais;j++)
				{
					printf("\n");
					printf("Escolha o país %d:\n", j+1);	
					scanf("%d", &opcaoPais);
					
					if(opcaoPais > 0 && opcaoPais <= ultPais)
					{
						strcpy(centro[i].pais[j].nomes , paise[opcaoPais-1].nomes);
					}
					else
					{
						printf("Opção inválida!!\n");
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
				printf("Opção inválida!!\n");
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
				printf("Deseja visualizar os dados informados ?\nDigite 1 para SIM e 0 para NÂO:\n");
				scanf("%d", &ver);
				
				if(ver == 1)
				{
						printf("Id: %d \n", centro[i].idNUm);
						printf("Nome: %s \n", centro[i].nome);
						
					
					
						if(quantPais == ultPais || quantPais == 0)
						{
							printf("Paises participantes: Todos \n");
						}
						else if(quantPais == 1)
						{
							printf("Pais: %s \n", centro[i].pais[0].nomes);		
						}
						else
						{
							j = 0;
							while(j<quantPais)
							{
								printf("Pais %d: %s \n", j+1, centro[i].pais[j].nomes);	
								j++;
							}
						}
						
					
					printf("Confirma as informações ?\nDigite 1 para SIM e 0 para NÂO:\n");
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
						printf("Os dados não foram salvos!!\n");
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
					printf("Confirma as informações ?\nDigite 1 para SIM e 0 para NÂO:\n");
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
						printf("Os dados não foram salvos!!\n");
						fclose(centros);
						sleep(2);
						menuprincipal();
					}	
				 }
			}
			
					
		}	
	}		
	
	
	
	
}

void eventos(){
	
	system("cls");
	
	FILE *evento;
	FILE *pais;
	FILE *modalidade;
	FILE *localjogo;
	int idMod, idpais, idevento=0,idlocais, sair,contador=0, j=0, quantpais, pa, i, modali, dia, mes, ano, hora, minuto, locs, ver, confirma;
	int maxDia=3, difDia;
	
	char caminho[] = "C:/Gestao Olimpiada/eventos.txt";
	char caminhoMod[] = "C:/Gestao Olimpiada/modalidades.txt";
	char caminhopais[] = "C:/Gestao Olimpiada/paises.txt";
	char caminholocais[] = "C:/Gestao Olimpiada/locaisjogos.txt";
	
	Evento eventos;
	Paises paises;
	Paises pai[100];
	Modalidades modalidades;
	Modalidades mods[100];
	LocaisJogos locais;
	LocaisJogos loc[100];
	
	memset(&eventos,0, sizeof(Evento));
	
	evento = fopen(caminho, "a+");
	pais = fopen(caminhopais, "r");
	modalidade = fopen(caminhoMod, "r");
	localjogo = fopen(caminholocais, "r");
	

	
	if(evento != NULL)
	{
		
		if(pais != NULL && modalidade != NULL && localjogo != NULL )
		{
			
				idMod = ultimo_id(caminhoMod, "modalidade");
				idpais = ultimo_id(caminhopais, "pais");
				idevento = ultimo_id(caminho, "evento");
				idlocais = ultimo_id(caminholocais, "localjogo");
			
			
			
			while(!feof(pais))
			{
				fread(&paises, sizeof(Paises),1, pais);
				pai[contador] = paises;
				contador++;	
			}
			
			fclose(pais);
			
			contador = 0;
			
			while(!feof(modalidade))
			{
				fread(&modalidades, sizeof(Modalidades),1, modalidade);
				mods[contador] = modalidades;
				contador++;	
			}
			
			fclose(modalidade);
			
			contador = 0;
			
			while(!feof(localjogo))
			{
				fread(&locais, sizeof(LocaisJogos),1, localjogo);
				loc[contador] = locais;
				contador++;	
			}
			
			fclose(localjogo);
			
		}
		else
		{
			printf("Nenhum pais, modalidade ou local cadastrado!!\n");
			sleep(2);
			menuprincipal();
		}
		
		
		
		if(idpais > 0){
			
		}
		
		printf("---------------------------------------------------------------------------------------------\n");
		printf("                                   CADASTRO EVENTOS \n");
		printf("---------------------------------------------------------------------------------------------\n\n");
		
		do{
			system("cls");
			printf("---------------------------------------------------------------------------------------------\n");
			printf("                                   CADASTRO EVENTOS \n");
			printf("---------------------------------------------------------------------------------------------\n\n");
			
			eventos.idNum = idevento+1;
			
			printf("Insira o nome do evento:\n");
			scanf("%s", &eventos.nome);
			
			printf("Insira o tipo de evento:\n");
			scanf("%s", &eventos.tipo);
			
			 j=0;
			
			printf("Escolha os paises participantes.\n");
			printf("\n");
			while(j<idpais){
				
				printf(" [%d] %s \n", j+1, pai[j].nomes);
				j++;
			}
			
			printf("\n");
			printf("Insira quantos paises vão participar.\nOu para adicionar todos da lista digite 0 ou %d.\n", idpais);
			scanf("%d", &quantpais);
			
				while(quantpais > idpais || quantpais < 0)
				{
					system("cls");
					printf("Quantidade inválida.\n");
					printf("\n");
					printf("Insira novamente quantos paises vão participar:\n");
					scanf("%d", &quantpais);
				}
				
			  if(quantpais == 0 || quantpais == idpais )
				{
					i=0;
				
					eventos.quantpais = idpais;
			
					while(i < idpais)
					{
						strcpy(eventos.pais[i].nomes , pai[i].nomes);
						i++;
					}
					printf("\n");
					printf("Todos os países foram incluídos no evento %s.\n", eventos.nome);
					printf("\n");
				}
				else if (quantpais == 1)
				{
					eventos.quantpais = 1;
					
					printf("Escolha o pais:\n");
					scanf("%d", &pa);
					
					if(pa > 0 && pa <= idpais)
					{
							strcpy(eventos.pais[0].nomes , pai[pa-1].nomes);
					}
					else
					{
							printf("Opção inválida!!\n");
							sleep(2);
							menuprincipal();		
					}
				}
				else
				{
					
					i=0;
					
					while(i < quantpais)
					{
							eventos.quantpais = quantpais;
							
							printf("Escolha o %d pais:\n", i+1);
							scanf("%d", &pa);
							
							if(pa > 0 && pa <= idpais)
							{
									strcpy(eventos.pais[i].nomes , pai[pa-1].nomes);
							}
							else
							{
									printf("Opção inválida!!\n");
									sleep(2);
									menuprincipal();		
							}
							
							i++;
					}
				}
				
			
			
			 j=0;
			
			printf("Escolha quais as modalidades.\n");
			printf("\n");
			
			while(j<idMod){
				printf(" [%d] %s \n", j+1, mods[j].modalidades);
				j++;
			}
			
			printf("\n");
			printf("Insira as modalidades:\n");
			scanf("%d", &modali);
			
			if(modali > idMod)
			{
				printf("Quantidade invalida!!\n");
				printf("\n");
				printf("Insira as modalidades:\n");
				scanf("%d", &modali);
			}
			
			else if(modali == 1)
			{
				printf("Escolha a modalidade:\n");
				scanf("%d", &pa);
				
				if(pa > 0 && pa <= idMod)
				{
						strcpy(eventos.modalidade.modalidades , mods[pa-1].modalidades);
				}
				else
				{
						printf("Opção inválida!!\n");
						sleep(2);
						menuprincipal();		
				}
			}
			else
			{
				i=0;
			
				while(i < modali)
				{
					if(modali > idMod)
					{
						printf("Quantidade invalida!!\n");
						printf("\n");
						printf("Insira as modalidades:\n");
						scanf("%d", &modali);
					}
				
					
					printf("Escolha a %d modalidade:\n", i+1);
					scanf("%d", &pa);
					
					if(pa > 0 && pa <= idMod)
					{
							strcpy(eventos.modalidade.modalidades , mods[pa-1].modalidades);
					}
					else
					{
							printf("Opção inválida!!\n");
							sleep(2);
							menuprincipal();		
					}
					
					i++;
				}
				
			}
			
		
			
			
			j=0;
			
			printf("Escolha o local do evento.\n");
			printf("\n");
			
			while(j<idlocais){
				printf(" [%d] %s \n", j+1, loc[j].nome);
				j++;
			}
			
			
			printf("\n");
			printf("Insira o local:\n");
			scanf("%d", &locs);
			
			
			
			if(locs > 0 && locs <= idlocais)
			{
					strcpy(eventos.locais.nome , loc[locs-1].nome);
			}
			else
			{
					printf("Opção inválida!!\n");
					sleep(2);
					menuprincipal();		
			}
			
		
			printf("\n");	
			printf("Informe a data e hora de inicio do evento.\n");
			printf("Insira o dia:\n");
			scanf("%d", &dia);
			
			printf("Insira o mês:\n");
			scanf("%d", &mes);
			
			while(!validarData(dia, mes, 2024))
			{
				system("cls");
				printf("\n");	
				printf("Informe novamnente a data e hora de inicio do evento.\n");
				printf("Insira o dia:\n");
				scanf("%d", &dia);
				
				printf("Insira o mês:\n");
				scanf("%d", &mes);
					
			}
			
			if(mes > 5 && mes <= 8)
			{
					eventos.dataInico.mes = mes;
					eventos.dataInico.dia = dia;
							
			}
			else
			{
				printf("Periodo invalido!\n");
				sleep(2);
				menuprincipal();
			}
			
			eventos.dataInico.ano = 2024;
			
			printf("Insira a hora de inicio.\n");
			scanf("%d", &hora);
			
			printf("Insira o minuto.\n");
			scanf("%d", &minuto);
			
			while(!validahora(hora, minuto))
			{
					system("cls");
					printf("Insira novamente a hora de inicio.\n");
					scanf("%d", &hora);
					
					printf("Insira novamente o minuto.\n");
					scanf("%d", &minuto);
			}
			
				eventos.dataInico.hora = hora;
				eventos.dataInico.minuto = minuto;
	
			printf("\n");	
			printf("Informe a data e hora final do evento.\n");
			printf("Insira o dia:\n");
			scanf("%d", &dia);
			
			eventos.dataTermino.mes = eventos.dataInico.mes;
			
			while(!validarData(dia, eventos.dataTermino.mes, 2024))
			{
				system("cls");
				printf("\n");	
				printf("Informe novamnente a data e hora final do evento.\n");
				printf("Insira o dia:\n");
				scanf("%d", &dia);
			}
			
			if(eventos.dataTermino.mes > 5 && eventos.dataTermino.mes <= 8)
			{
					if(dia >= eventos.dataInico.dia)
						{
							difDia = dia - eventos.dataInico.dia;
						
							if(difDia > 3)
							{
								printf("Data final deve ser menor que três dias!!\n");
								sleep(2);
								menuprincipal();
							}
							else
							{
								eventos.dataTermino.dia = dia;
							}
						}
					else
					{
						printf("Dia inválido.\n");
						sleep(2);
						menuprincipal();
					}
						
							
			}
			else
			{
				printf("Periodo invalido!\n");
				sleep(2);
				menuprincipal();
			}
				
			eventos.dataTermino.ano = 2024;
			
			printf("Insira a hora de termino.\n");
			scanf("%d", &hora);
			
			printf("Insira o minuto.\n");
			scanf("%d", &minuto);
			
			while(!validahora(hora, minuto))
			{
					system("cls");
					printf("Insira novamente a hora de inicio.\n");
					scanf("%d", &hora);
					
					printf("Insira novamente o minuto.\n");
					scanf("%d", &minuto);
			}
			
			
				if(eventos.dataTermino.dia == eventos.dataInico.dia )
				{
					
					if(hora == eventos.dataInico.hora && minuto > eventos.dataInico.minuto)
					{
						eventos.dataTermino.hora = hora;
						eventos.dataTermino.minuto = minuto;
					}
					else if(hora > eventos.dataInico.hora && minuto <= eventos.dataInico.minuto || hora > eventos.dataInico.hora && minuto >= eventos.dataInico.minuto)
					{
							eventos.dataTermino.hora = hora;
							eventos.dataTermino.minuto = minuto;
					}
					
					else
					{
						printf("Hora ou minuto invalidos.\n");
						sleep(2);
						menuprincipal();
					}
							
				}
				else if(eventos.dataTermino.dia > eventos.dataInico.dia )
				{
					
					if(hora >= eventos.dataInico.hora || minuto >= eventos.dataInico.minuto || hora <= eventos.dataInico.hora || minuto <= eventos.dataInico.minuto)
					{
						eventos.dataTermino.hora = hora;
						eventos.dataTermino.minuto = minuto;
						
					}
					else
					{
						printf("Hora ou minuto invalidos.\n");
						sleep(2);
						menuprincipal();	
					}	
				}
				else 
				{
					printf("Dia, hora ou minutos invalidos.\n");
					sleep(2);
					menuprincipal();
				}
			
			
				printf("Deseja ver as informações inseridas ?\nDigite 1 para SIM ou 0 para NÃO.\n");
				scanf("%d", &ver);
		
				if(ver == 1)
				{
					printf("Os dados inseridos foram.\n\n");
					printf("Id %d\n", eventos.idNum);
					printf("Nome do evento: %s\n", eventos.nome);
					printf("Tipo de evento: %s\n", eventos.tipo);
					
					if(quantpais == 0 || quantpais == idpais)
					{
						printf("Paises participantes: Todos\n");	
					}
					else if (quantpais > 1)
					{
						j = 0;
					
						while(j<idpais)
						{
						
							printf("Pais %d %s \n", j+1, eventos.pais[j].nomes);
							j++;
						
						}
					}
					else
					{
						printf("Paises participantes: %s\n", eventos.pais[0].nomes);	
					
					}
					
					printf("Data inicio: %2d/%02d/%d\n", eventos.dataInico.dia, eventos.dataInico.mes, eventos.dataInico.ano);
					printf("Hora inicio: %02d:%02d\n", eventos.dataInico.hora, eventos.dataInico.minuto);
					printf("Data término: %02d/%02d/%d\n", eventos.dataTermino.dia, eventos.dataTermino.mes, eventos.dataTermino.ano);
					printf("Hora término: %02d:%02d\n\n", eventos.dataTermino.hora, eventos.dataTermino.minuto);
					
					printf("Confirma as informações ?\nDigite 1 para SIM ou 0 para NÃO.\n");
					scanf("%d", &confirma);
					
					if(confirma == 1)
					{
						fseek(evento, 0, SEEK_END);
						fwrite(&eventos, sizeof(Evento),1, evento);
					
						
						printf("Dados salvos com sucesso!!\n");
						printf("\n\n");
						printf("Deseja cadastrar mais eventos ?\nDigite 1 para SIM ou 0 para NÃO.\n");
						scanf("%d", &sair);
						
						if(sair == 1)
						{
							
							idevento = eventos.idNum;
						}
						else
						{
							fclose(evento);
						}
						
					}
					else
					{
						printf("Os dados não foram salvos!!\n");
						printf("\n\n");
						printf("Deseja cadastrar mais eventos ?\nDigite 1 para SIM ou 0 para NÃO.\n");
						scanf("%d", &sair);
						
						if(sair != 1)
						{
							fclose(evento);
						}
						
					}
					
				}
				else
				{
					printf("Confirma as informações ?\nDigite 1 para SIM ou 0 para NÃO.\n");
					scanf("%d", &confirma);
					
					if(confirma == 1)
					{
						fseek(evento, 0, SEEK_END);
						fwrite(&eventos, sizeof(Evento),1, evento);
						
						printf("Dados salvos com sucesso!!\n");
						printf("Deseja cadastrar mais eventos ?\nDigite 1 para SIM ou 0 para NÃO.\n");
						scanf("%d", &sair);
						
						if(sair == 1)
						{
							idevento = eventos.idNum;
							
						}
						else
						{
							fclose(evento);
						}
					}
					else
					{
						printf("Os dados não foram salvos!!\n");
						printf("Deseja cadastrar mais eventos ?\nDigite 1 para SIM ou 0 para NÃO.\n");
						scanf("%d", &sair);
						
						if(sair != 1)
						{
							fclose(evento);
						}
						
					}
				}
		
			
			
		}while(sair!= 0);
		
		
		if(sair == 0)
		{
			sleep(2);
			menuprincipal();
		}
	}
	


}

void medalhasOlimpicas()
{
	FILE *medalha;
	char caminho[] = "C:/Gestao Olimpiada/medalhas.txt";
	int opcao, alterar, quant, ouro, prata, bronze, ver, confirma;
	
	medalha = fopen(caminho, "a+");
	
	Medalhas medalhas;
	Medalhas medal;
	Medalhas alterarQuant;
	
	memset(&medalhas,0,sizeof(Medalhas));
	
	if(medalha != NULL)
	{
		if(get_size(caminho) !=0)
		{
			printf("---------------------------------------------------------------------------------------------\n");
			printf("                                   CADASTRO MEDALHAS \n");
			printf("---------------------------------------------------------------------------------------------\n\n");
			printf("Deseja alterar a quantidade de medalhas cadastradas ?\nDigite 1 para SIM ou 0 para NÃO.\n");
			scanf("%d", &opcao);
			
			if(opcao == 1)
			{
				
				while(!feof(medalha))
				{
					fread(&medalhas, sizeof(Medalhas),1,medalha);
					medal = medalhas;
				}
				
				printf("Escolha qual deseja alterar:\n");
				printf("[1] %d de Ouro \n", medal.ouro);
				printf("[2] %d de Prata \n", medal.prata);
				printf("[3] %d de bronze \n", medal.bronze);
				printf(" %d total de medalhas \n\n", medal.total);
				
				printf("Escolha uma opção.\n");
				scanf("%d", &opcao);
				
				if(opcao > 0 && opcao < 4)
				{
					if(opcao == 1)
					{
						printf("Insira a nova quantidade de medalhas de ouro\n");
						scanf("%d", &quant);
						
						if(quant > 0 && quant < 200 )
						{	
						    rewind(medalha);
						    
						    alterarQuant.id = 1;
						  	alterarQuant.ouro = quant;
						  	alterarQuant.prata = medal.prata;
						  	alterarQuant.bronze = medal.bronze;
						  	alterarQuant.total = alterarQuant.ouro + alterarQuant.prata + alterarQuant.bronze;
						  	
						  	fwrite(&alterarQuant,sizeof(Medalhas),1,medalha);
						  	fclose(medalha);
						  	
						  	printf("Quantidade alterada com sucesso!!\n");
						  	sleep(2);
						  	menuprincipal();
						  	
						}
						else
						{
							printf("Quantidade inválida!!\n");
							sleep(2);
							menuprincipal();
						}
					}
					else if(opcao == 2)
					{
						printf("Insira a nova quantidade de medalhas de prata\n");
						scanf("%d", &quant);
						
						if(quant > 0 && quant < 200 )
						{	
							rewind(medalha);
						    
						    alterarQuant.id = 1;
						  	alterarQuant.ouro = medal.ouro;
						  	alterarQuant.prata = quant;
						  	alterarQuant.bronze = medal.bronze;
						  	alterarQuant.total = alterarQuant.ouro + alterarQuant.prata + alterarQuant.bronze;
						  	
						  	fwrite(&alterarQuant,sizeof(Medalhas),1,medalha);
						  	fclose(medalha);
						  	
						  	printf("Quantidade alterada com sucesso!!\n");
						  	sleep(2);
						  	menuprincipal();
						}
						else
						{
							printf("Quantidade inválida!!\n");
							sleep(2);
							menuprincipal();
						}
						
					}
					else if(opcao == 3)
					{
						printf("Insira a nova quantidade de medalhas de bronze\n");
						scanf("%d", &quant);
						
						if(quant > 0 && quant < 200 )
						{	
							rewind(medalha);
						    
						    alterarQuant.id = 1;
						  	alterarQuant.ouro = medal.ouro;
						  	alterarQuant.prata = medal.prata;
						  	alterarQuant.bronze = quant;
						  	alterarQuant.total = alterarQuant.ouro + alterarQuant.prata + alterarQuant.bronze;
						  	
						  	fwrite(&alterarQuant,sizeof(Medalhas),1,medalha);
						  	fclose(medalha);
						  	
						  	printf("Quantidade alterada com sucesso!!\n");
						  	sleep(2);
						  	menuprincipal();	
						}
						else
						{
							printf("Quantidade inválida!!\n");
							sleep(2);
							menuprincipal();
						}
						
					}
					else
					{
						printf("Opção inválida!!\n");
						sleep(2);
						menuprincipal();
					}
				}
				else
				{
					printf("Opção inválida!!\n");
					sleep(2);
					menuprincipal();
				}
			}
			else if(opcao == 0)
			{
				sleep(2);
				menuprincipal();
			}
			else
			{
				printf("Opção inválida!!\n");
				sleep(2);
				menuprincipal();
			}
		}
		else
		{
			printf("---------------------------------------------------------------------------------------------\n");
			printf("                                   CADASTRO MEDALHAS \n");
			printf("---------------------------------------------------------------------------------------------\n\n");
			printf("Informe as quantidades de medalhas de ouro, prata e bronze.\n");
			
			printf("Medalhas de ouro:\n");
			scanf("%d", &ouro);
			
			printf("Medalhas de prata:\n");
			scanf("%d", &prata);
			
			printf("Medalhas de bronze:\n");
			scanf("%d", &bronze);
			
			if(ouro > 0 && ouro < 200 && prata > 0 && prata < 200 && bronze > 0 && prata < 200)
			{
				medalhas.id = 1;
				medalhas.ouro = ouro;
				medalhas.prata = prata;
				medalhas.bronze = bronze;
				medalhas.total = medalhas.ouro + medalhas.prata + medalhas.bronze;
				
				printf("Deseja ver as informações digitadas ?\nDigite 1 para SIM ou 0 para NÃO.\n");
				scanf("%d", &ver);
				
				if(ver == 1)
				{
					printf("Medalhas de ouro: %d\n", medalhas.ouro);
					printf("Medalhas de prata: %d\n", medalhas.prata);
					printf("Medalhas de bronze: %d\n", medalhas.bronze);
					printf("Total de medalhas: %d\n\n", medalhas.total);
					
					printf("Confirma as informações ?\nDigite 1 para SIM  ou 0 para NÃO.\n");
					scanf("%d", &confirma);
					
					if(confirma == 1)
					{
						fseek(medalha, 0 , SEEK_END);
						fwrite(&medalhas, sizeof(Medalhas),1,medalha);
						fclose(medalha);
						
						printf("Dados salvos com sucesso!!\n");
						
						sleep(2);
						menuprincipal();
					}
					else
					{
						printf("Os dados não foram salvos!!\n");
						sleep(2);
						menuprincipal();
					}
				}
				else
				{
					printf("Confirma as informações ?\nDigite 1 para SIM  ou 0 para NÃO.\n");
					scanf("%d", &confirma);
					
					if(confirma == 1)
					{
						fseek(medalha, 0 , SEEK_END);
						fwrite(&medalhas, sizeof(Medalhas),1,medalha);
						fclose(medalha);
						
						printf("Dados salvos com sucesso!!\n");
						
						sleep(2);
						menuprincipal();
					}
					else
					{
						printf("Os dados não foram salvos!!\n");
						sleep(2);
						menuprincipal();
					}
				}
				
			}
			else
			{ 
				printf("Quantidade inválida!!\n");
				sleep(2);
				menuprincipal();
			}
		}
	}
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
			printf("Opção invalida!!\n");
			sleep(2);
			menuprincipal();
		
	}
	
}

void consultaResumoatleta()
{
	FILE *atletas;
	char caminho[] = "C:/Gestao olimpiada/atletas.txt";
	int id, contador=0;
	
	atletas = fopen(caminho, "r");
	
	Atleta atleta;
	Atleta atlet[100];
	
	id = ultimo_id(caminho, "atleta");
	
	if(id == 0)
	{
		printf("Nenhum atleta cadastrado!!\n");
		sleep(2);
		menuprincipal();
	}
	else
	{
		Atleta atlet[id];
	}
	
	
	if(atletas != NULL)
		{
			if(get_size(caminho) > 0)
			{
			
				
				while(!feof(atletas))
				{
					fread(&atleta, sizeof(Atleta),1,atletas);
					atlet[contador] = atleta;
					contador++;
				}
				
				fclose(atletas);
			}
			else
			{
				printf("Nenhum atleta cadastrado!!\n");
				sleep(2);
				menuprincipal();	
			}
			
			
				printf("---------------------------------------------------------------------------------------------\n");
				printf("                                   RESUMO POR ATLETA \n");
				printf("---------------------------------------------------------------------------------------------\n\n");
			
			contador = 0;
			
			while(contador < id)
			{
				printf("Nome: %s\n", atlet[contador].nome);
				printf("Modalidade: %s\n", atlet[contador].modalidade);
				printf("Medalhas de ouro: %d\n", atlet[contador].medalhas.ouro);
				printf("Medalhas de prata: %d\n", atlet[contador].medalhas.prata);
				printf("Medalhas de bronze: %d\n\n", atlet[contador].medalhas.bronze);
				contador++;
			}
			
			system("pause");
			sleep(2);
			menuprincipal();
	}
	else
	{
		printf("Nenhum atleta cadastrado!!\n");
		sleep(2);
		menuprincipal();	
	}
	
	
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
  				  sleep(2);
  				  menuprincipal();
			}
		else		
			{
				
   					idult = ultimo_id(caminho, "atleta");
				
					Atleta atlet[idult];
					
				
					
					while(!feof(atletas))
					{
						
	   				 	fread(&atleta, sizeof(Atleta), 1, atletas);
	   					atlet[i] = atleta;
	   					
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
						printf("País: %s \n",atlet[i].pais);
						printf("Medalhas de ouro: %d \n",atlet[i].medalhas.ouro);
						printf("Medalhas de prata: %d \n",atlet[i].medalhas.prata);
						printf("Medalhas de bronze: %d \n",atlet[i].medalhas.bronze);
						printf("Toatl de medalhas: %d \n\n",atlet[i].medalhas.total);
	   					
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
  				  sleep(2);
  				  menuprincipal();
			}
		else		
			{
					
   					idult = ultimo_id(caminho, "funcionario");
				
					Funcionarios funci[idult];
					
					while(!feof(funcionarios))
					{
						
	   				 	fread(&funcionario, sizeof(Funcionarios), 1, funcionarios);
	   					funci[i] = funcionario;
	   				
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
						printf("Função: %s \n\n",funci[i].funcao);
					
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
	FILE *medicos;
	
	char caminho[] = "C:/Gestao Olimpiada/medicos.txt";
	
	
	medicos = fopen(caminho, "r");
	
	int idult, i=0;
	Medicos medico;
	
	if(medicos != NULL)
	{
		if(get_size(caminho) == 0)
			{
  				  printf("Nenhum medico cadastrado.\n");
  				  sleep(2);
  				  menuprincipal();
			}
		else		
			{
					
   					idult = ultimo_id(caminho, "medico");
				
					Medicos med[idult];
					
					while(!feof(medicos))
					{
					
	   				 	fread(&medico, sizeof(Medicos), 1, medicos);
	   					med[i] = medico;
	   				
	   					i++;
						
					}
					
					fclose(medicos);
					
					i=0;
					
					system("cls");
					printf("---------------------------------------------------------------------------------------------\n");
					printf("                                   CONSULTA CADASTRO DE MEDICOS\n");
					printf("---------------------------------------------------------------------------------------------\n\n");
					
					while(i<idult)
					{
						printf("Id: %d \n",med[i].idNUm);
						printf("Nome: %s \n",med[i].nome);
						printf("Sobrenome: %s \n", med[i].sobrenome);
						printf("Pais: %s \n", med[i].pais);
						printf("Especialidade: %s \n\n",med[i].especialidade);
					
						i++;	
					}
					
					system("pause");
					menuprincipal();
				 	
		  }
	}
	else{
		printf("Nenhum medico cadastrado.\n");
		sleep(2);
		menuprincipal();
	}
	
}

void consultaVoluntarios(){
	FILE *voluntarios;
	
	char caminho[] = "C:/Gestao Olimpiada/volumtarios.txt";
	
	
	voluntarios = fopen(caminho, "r");
	
	int idult, i=0;
	Voluntarios voluntario;
	
	if(voluntarios != NULL)
	{
		if(get_size(caminho) == 0)
			{
  				  printf("Nenhum voluntario cadastrado.\n");
  				  sleep(2);
  				  menuprincipal();
			}
		else		
			{
				
   					idult = ultimo_id(caminho, "voluntario");
				
					Voluntarios volun[idult];
					
					
					
					while(!feof(voluntarios))
					{
						
	   				 	fread(&voluntario, sizeof(Voluntarios), 1, voluntarios);
	   				 	volun[i] = voluntario;
	   					
	   					i++;
						
					}
					
					fclose(voluntarios);
					
					i=0;
					
					system("cls");
					printf("---------------------------------------------------------------------------------------------\n");
					printf("                                   CONSULTA CADASTRO DE VOLUNTARIOS\n");
					printf("---------------------------------------------------------------------------------------------\n\n");
					
					while(i<idult)
					{
						printf("Id: %d \n",volun[i].idNUm);
						printf("Nome: %s \n",volun[i].nome);
						printf("Sobrenome: %s \n", volun[i].sobrenome);
						printf("Função: %s \n", volun[i].funcao);
						printf("Pais: %s \n\n", volun[i].pais);
						
					
						i++;	
					}
					
					system("pause");
					menuprincipal();
				 	
		  }
	}
	else{
		printf("Nenhum voluntario cadastrado.\n");
		sleep(2);
		menuprincipal();
	}
	
}

void consultaEquip(){
	
	FILE *equipes;
	
	char caminho[] = "C:/Gestao Olimpiada/equipes.txt";
	
	
	equipes = fopen(caminho, "r");
	
	int idult, i=0;
	EquipeOlimpica equip;
	
	if(equipes != NULL)
	{
		if(get_size(caminho) == 0)
			{
  				  printf("Nenhuma equipe cadastrada.\n");
  				  sleep(2);
  				  menuprincipal();
			}
		else		
			{
   					idult = ultimo_id(caminho, "equipe");
				
					EquipeOlimpica equipe[idult];
					
					
					
					while(!feof(equipes))
					{
	   				 	fread(&equip, sizeof(EquipeOlimpica), 1, equipes);
	   					equipe[i] = equip;
	   				
	   					i++;
						
					}
					
					fclose(equipes);
					
					i=0;
					
					system("cls");
					printf("---------------------------------------------------------------------------------------------\n");
					printf("                                   CONSULTA CADASTRO DE EQUIPES OLIMPICAS\n");
					printf("---------------------------------------------------------------------------------------------\n\n");
					
					while(i<idult)
					{
						printf("Id: %d \n",equipe[i].idNUm);
						printf("Nome: %s \n",equipe[i].nome);
						printf("Sobrenome: %s \n", equipe[i].sobrenome);
						printf("Função: %s\n",equipe[i].funcao);
						printf("Pais: %s \n\n",equipe[i].pais);
					
						i++;	
					}
					
					system("pause");
					menuprincipal();
				 	
		  }
	}
	else{
		printf("Nenhuma equipe cadastrada.\n");
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
  				  sleep(2);
  				  menuprincipal();
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
	   					pai[i].medalhas.ouro = pais.medalhas.ouro;
	   					pai[i].medalhas.prata = pais.medalhas.prata;
	   					pai[i].medalhas.bronze = pais.medalhas.bronze;
	   					pai[i].medalhas.total = pais.medalhas.total;
	   				
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
						printf("Medalhas de Ouro: %d \n",pai[i].medalhas.ouro);
						printf("Medalhas de Prata: %d \n",pai[i].medalhas.prata);
						printf("Medalhas de Bronze: %d \n",pai[i].medalhas.bronze);
						printf("Total de medalhas: %d \n\n",pai[i].medalhas.total);
					
					
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
	FILE *modalidade;
	
	char caminho[] = "C:/Gestao Olimpiada/modalidades.txt";
	
	
	modalidade = fopen(caminho, "r");
	
	int idult, i=0;
	Modalidades mods;
	
	if(modalidade != NULL)
	{
		if(get_size(caminho) == 0)
			{
  				  printf("Nenhuma modalidade cadastrada.\n");
  				  sleep(2);
  				  menuprincipal();
			}
		else		
			{
				
   					idult = ultimo_id(caminho, "modalidade");
				
					Modalidades modalida[idult];
					
					
					while(!feof(modalidade))
					{
					
	   				 	fread(&mods, sizeof(Modalidades), 1, modalidade);
	   				 	modalida[i] = mods;
	   				
	   					i++;
						
					}
					
					fclose(modalidade);
					
					i=0;
					
					system("cls");
					printf("---------------------------------------------------------------------------------------------\n");
					printf("                                   CONSULTA CADASTRO DE MODALIDADES\n");
					printf("---------------------------------------------------------------------------------------------\n\n");
					
					while(i<idult)
					{
						printf("Id: %d \n",modalida[i].idNUm);
						printf("Modalidade: %s \n",modalida[i].modalidades);
						printf("Medalhas de Ouro: %d \n",modalida[i].medalhas.ouro);
						printf("Medalhas de Prata: %d \n",modalida[i].medalhas.prata);
						printf("Medalhas de Bronze: %d \n",modalida[i].medalhas.bronze);
						printf("Total de medalhas: %d \n\n",modalida[i].medalhas.total);
					
					
						i++;	
					}
					
					system("pause");
					menuprincipal();
				 	
		  }
	}
	else{
		printf("Nenhuma modalidade cadastrada.\n");
		sleep(2);
		menuprincipal();
	}
	
	
}

void consultaAlojamentos(){
	FILE *alojamentos;
	
	char caminho[] = "C:/Gestao Olimpiada/alojamentos.txt";
	char caminho1[] = "C:/Gestao Olimpiada/paises.txt";
	
	
	alojamentos = fopen(caminho, "r");
	
	int idult, i=0, j, quantpais[100], quant;
	Alojamentos aloj;
	
	if(alojamentos != NULL)
	{
		if(get_size(caminho) == 0)
			{
  				  printf("Nenhum alojamento cadastrado.\n");
  				  sleep(2);
  				  menuprincipal();
			}
		else		
			{
					
   					idult = ultimo_id(caminho, "alojamento");
   					quant = ultimo_id(caminho1, "pais");
				
					Alojamentos alojamento[idult];
					
					
					
					while(!feof(alojamentos))
					{
					
	   				 	fread(&aloj, sizeof(Alojamentos), 1, alojamentos);
	   					alojamento[i] = aloj;
	   					quantpais[i] = alojamento[i].quantPais;
	   					i++;
						
					}
					
					fclose(alojamentos);
					
					i=0;
					
					system("cls");
					printf("---------------------------------------------------------------------------------------------\n");
					printf("                                   CONSULTA CADASTRO DE ALOJAMENTOS\n");
					printf("---------------------------------------------------------------------------------------------\n\n");
					
					while(i<idult)
					{
						printf("Id: %d \n",alojamento[i].idNUm);
						printf("Nome: %s \n",alojamento[i].nome);
						printf("Local: %s \n",alojamento[i].local);
						
						j=0;
						
						if(quantpais[i] == quant)
						{
							printf("Paises participantes: Todos\n");
							
						}
						else
						{
							j = 1;
						
							while(j < quantpais[j-1])
							{
								
								if(j+1 > quantpais[j])
								break;
								else
								{
									printf("Pais participante: %d  %s\n",j, alojamento[i].pais[j].nomes);
									j++;
								}
								
							}
							
						}
						
						printf("\n");
					
					
						i++;	
					}
					
					system("pause");
					menuprincipal();
				 	
		  }
	}
	else{
		printf("Nenhum alojamento cadastrado.\n");
		sleep(2);
		menuprincipal();
	}
	
	
}

void consultaLocaisJogos(){
	FILE *local;
	
	char caminho[] = "C:/Gestao Olimpiada/locaisjogos.txt";
	
	
	local = fopen(caminho, "r");
	
	int idult, i=0;
	LocaisJogos loca;
	
	if(local != NULL)
	{
		if(get_size(caminho) == 0)
			{
  				  printf("Nenhum local cadastrado.\n");
			}
		else		
			{
					
   					idult = ultimo_id(caminho, "localjogo");
				
					LocaisJogos locais[idult];
					
					
					
					while(!feof(local))
					{
					
	   				 	fread(&loca, sizeof(LocaisJogos), 1, local);
	   					locais[i] = loca;
	   				
	   					i++;
						
					}
					
					fclose(local);
					
					i=0;
					
					system("cls");
					printf("---------------------------------------------------------------------------------------------\n");
					printf("                                   CONSULTA CADASTRO DE LOCAIS DE JOGOS\n");
					printf("---------------------------------------------------------------------------------------------\n\n");
					
					while(i<idult)
					{
						printf("Id: %d \n",locais[i].idNUm);
						printf("Nome: %s \n",locais[i].nome);
						printf("Local: %s \n\n",locais[i].local);
					
						i++;	
					}
					
					system("pause");
					menuprincipal();
				 	
		  }
	}
	else{
		printf("Nenhum local cadastrado.\n");
		sleep(2);
		menuprincipal();
	}
	
	
}

void consultaEquipamentos(){
	FILE *equipamentos;
	
	char caminho[] = "C:/Gestao Olimpiada/equipamentos.txt";
	
	
	equipamentos = fopen(caminho, "r");
	
	int idult, i=0;
	Equipamentos equipa;
	
	if(equipamentos != NULL)
	{
		if(get_size(caminho) == 0)
			{
  				  printf("Nenhum equipamento cadastrado.\n");
			}
		else		
			{
					
   					idult = ultimo_id(caminho, "equipamento");
				
					Equipamentos equipame[idult];
					
					
					
					while(!feof(equipamentos))
					{
					
	   				 	fread(&equipa, sizeof(Equipamentos), 1, equipamentos);
	   					equipame[i] = equipa;
	   				
	   					i++;
						
					}
					
					fclose(equipamentos);
					
					i=0;
					
					system("cls");
					printf("---------------------------------------------------------------------------------------------\n");
					printf("                                   CONSULTA CADASTRO DE EQUIPAMENTOS\n");
					printf("---------------------------------------------------------------------------------------------\n\n");
					
					while(i<idult)
					{
						printf("Id: %d \n",equipame[i].idNUm);
						printf("Nome: %s \n\n",equipame[i].equipamentos);
					
						i++;	
					}
					
					system("pause");
					menuprincipal();
				 	
		  }
	}
	else{
		printf("Nenhum equipamento cadastrado.\n");
		sleep(2);
		menuprincipal();
	}
}

void consultaCentroTreinamento(){
	FILE *centros;
	
	char caminho[] = "C:/Gestao Olimpiada/centrotreinamento.txt";
	char caminho1[] = "C:/Gestao Olimpiada/paises.txt";
	
	
	centros = fopen(caminho, "r");
	
	int idult, i=0, quantpaises[100], j, quant=0;
	CentroTreinamento centro;
	
	if(centros != NULL)
	{
		if(get_size(caminho) == 0)
			{
  				  printf("Nenhum centro de treinamento cadastrado.\n");
			}
		else		
			{
					
   					idult = ultimo_id(caminho, "centro");
   					quant = ultimo_id(caminho1, "pais");
   					
				
					CentroTreinamento cent[idult];
					
					
					
					while(!feof(centros))
					{
					
	   				 	fread(&centro, sizeof(CentroTreinamento), 1, centros);
	   					cent[i] = centro;
	   					quantpaises[i] = cent[i].quantpais;
	   					i++;
					}
					
					fclose(centros);
					
					
					system("cls");
					printf("---------------------------------------------------------------------------------------------\n");
					printf("                                   CONSULTA CADASTRO DE CENTROS DE TREINAMENTO\n");
					printf("---------------------------------------------------------------------------------------------\n\n");
					
					
					i = 0;
					while(i<idult)
					{
						printf("Id: %d \n",cent[i].idNUm);
						printf("Nome: %s \n",cent[i].nome);
						printf("Local: %s \n",cent[i].local);
						
						if(quantpaises[i] == quant)
						{
							printf("Paises participantes: Todos\n");
							
						}
						else
						{
							j = 1;
						
							while(j < quantpaises[j-1])
							{
								
								if(j+1 > quantpaises[j])
								break;
								else
								{
									printf("Pais participante: %d %s \n", j, cent[i].pais[j-1].nomes);
									j++;
								}
								
							}
							
						}
						
						
						
						printf("\n");
					
						i++;	
					}
					
					system("pause");
					menuprincipal();
				 	
		  }
	}
	else{
		printf("Nenhum centro de treinamento cadastrado.\n");
		sleep(2);
		menuprincipal();
	}
	
}

void consultaNumerosdeCadastros()
{
	int id;
   
   char caminho[] = "C:/Gestao Olimpiada/paises.txt";
   char caminho1[] = "C:/Gestao Olimpiada/alojamentos.txt";
   char caminho2[] = "C:/Gestao Olimpiada/atletas.txt";
   char caminho3[] = "C:/Gestao Olimpiada/centrotreinamento.txt";
   char caminho4[] = "C:/Gestao Olimpiada/equipamentos.txt";
   char caminho5[] = "C:/Gestao Olimpiada/equipes.txt";
   char caminho6[] = "C:/Gestao Olimpiada/funcionarios.txt";
   char caminho7[] = "C:/Gestao Olimpiada/locaisjogos.txt";
   char caminho8[] = "C:/Gestao Olimpiada/medicos.txt";
   char caminho9[] = "C:/Gestao Olimpiada/modalidades.txt";
   char caminho10[] = "C:/Gestao Olimpiada/voluntarios.txt";
   char caminho11[] = "C:/Gestao Olimpiada/medalhas.txt";
   
   
   	printf("---------------------------------------------------------------------------------------------\n");
	printf("                                   CONSULTA TOTAL DE REGISTROS\n");
	printf("---------------------------------------------------------------------------------------------\n\n");
   
   id = ultimo_id(caminho, "pais");
    printf(" %03d Paises.\n", id);
   id = ultimo_id(caminho1, "alojamento");
     printf(" %03d Alojamentos.\n", id);
   id = ultimo_id(caminho2, "atleta");
    printf(" %03d Atletas.\n", id);
   id = ultimo_id(caminho3, "centro");
    printf(" %03d Centros de treinamentos.\n", id);
   id = ultimo_id(caminho4, "equipamento");
    printf(" %03d Equipamentos.\n", id);
   id = ultimo_id(caminho5, "equipe");
    printf(" %03d Equipes Olímpicas.\n", id);
   id = ultimo_id(caminho6, "funcionario");
    printf(" %03d Funcionarios.\n", id);
   id = ultimo_id(caminho7, "localjogo");
    printf(" %03d Locais de jogos\n", id);
   id = ultimo_id(caminho8, "medico");
    printf(" %03d Medicos.\n", id);
   id = ultimo_id(caminho9, "modalidade");
    printf(" %03d Modalidades.\n", id);
   id = ultimo_id(caminho10, "voluntario");
    printf(" %03d Voluntarios.\n", id);
   id = ultimo_id(caminho11, "medalha");
   
   if(id > 0)
   {
	   	Medalhas medalhas;
	   	
	   	FILE *medalha;
	   	
	   	medalha = fopen(caminho11, "r");
	   	
	   	if(medalha != NULL)
	   	{
	   			while(!feof(medalha))
	   			{
	   				fread(&medalhas, sizeof(Medalhas),1,medalha);  	
				}
				
				fclose(medalha);
				
				printf(" %03d Medalhas de ouro.\n", medalhas.ouro);
				printf(" %03d Medalhas de prata.\n", medalhas.prata);
				printf(" %03d Medalhas de bronze.\n", medalhas.bronze);
				printf(" %03d Total de medalhas.\n", medalhas.total);
		}
   		
   }
   else
   {
  		printf(" 000 Medalhas de ouro.\n");
		printf(" 000 Medalhas de prata.\n");
		printf(" 000 Medalhas de bronze.\n");
		printf(" 000 Total de medalhas.\n");
   }
   	
   	
   	printf("\n");
   	system("pause");
   	sleep(1);
   	menuprincipal();
    
   
}
