#include <stdio.h>
#include <string.h>

main () {

	char usuarioFixo[] = "admin"; //nome de login fixo
	char usuario[20]; //nome que o usuario digita
	char senhaFixa[] = "admin123"; //senha fixa
	char senha[12]; //senha que o usuario digita
	
	printf("Entre com usuario e senha para acessar o sistema.\n\n");
	
	printf("Usuario: ");	//Entrada dos dados
	gets(usuario);
	printf("Senha: ");
	gets(senha);
	
	printf("\n"); //quebra de linha para separar
	
	if ((strcmp(usuario, usuarioFixo) != 0) && strcmp(senha, senhaFixa) != 0) {	//verifica usuario e senha
	
		printf("usuario e senha incorretos, tente novamente");
	}
	else if (strcmp(usuario, usuarioFixo) != 0) { // verifica apenas o usuario
	
		printf("Usuario incorreto, tente novamente");
	}
	else if (strcmp(senha, senhaFixa) != 0) { //verifica apenas a senha
	
		printf("Senha incorreta, tente novamente");
	}
	else {
	
		printf("Login efetuado com sucesso!"); //efetua o login
	}
}
