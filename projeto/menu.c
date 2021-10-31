#include<stdio.h>
#include<math.h>
#include<locale.h>
#include<Windows.h>
#include<string.h>
#include<direct.h>
#include<stdlib.h>
#include "structs.c"
#include "prototipos.c"
#include "cadastros.c"
#include "relatorios.c"
#include "funcoes.c"


int main(char usuario[], char senha[] ){
	

	setlocale(LC_ALL, "portuguese");
	system("cls");
	

	
	if( _mkdir( "C:/Gestao Olimpiada" ) == 0 )
   {
      //printf( "Directory '\\\"Gestao Olimpiada\"' was successfully created\n" );
      
	
   }
  

     
     	menuprincipal();
	
	
	
	return 0;
}
