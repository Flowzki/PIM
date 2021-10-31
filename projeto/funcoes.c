
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
