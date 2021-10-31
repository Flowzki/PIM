
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
