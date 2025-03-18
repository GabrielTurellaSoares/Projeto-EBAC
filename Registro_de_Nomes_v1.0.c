#include <stdio.h> //biblioteca de comunica��o com o usu�rio
#include <stdlib.h> //biblioteca de aloca��o de mem�ria
#include <locale.h> //biblioteca de texto por regi�o
#include <string.h> //biblioteca respons�vel por cuidar das strings

int registro() // Fun��o respons�vel por cadastrar usu�rios
{
	// In�cio da criac�o de vari�veis
	char arquivo[40];
	char cpf[40];
	char nome[40];
	char sobrenome[40];
	char cargo[40];
	// Fim da cria��o de vari�veis
	
	printf("Digite o cpf a ser cadastrado: "); // Coletando informa��es do usu�rio
	scanf("%s", cpf); // %s refere-se a string
	
	strcpy(arquivo, cpf); // respons�vel por copiar os valores da string
	
	FILE *file; // cria o arquivo
	file = fopen(arquivo, "w"); // cria o arquivo "w" write escreve no arquivo file
	fprintf(file,cpf); // salva o valor da vari�vel
	fclose(file); // fecha o arquivo
	
	file = fopen(arquivo, "a"); // "a" altera texto do arquivo file
	fprintf(file,",");
	fclose(file);
	
	printf("Digite o nome a ser cadastrado: ");
	scanf("%s",nome);
	
	file = fopen(arquivo, "a"); // abre o arquivo para alterar
	fprintf(file,nome);
	fclose(file); // fecha o arquivo depois da altera��o
	
	file = fopen(arquivo, "a");
	fprintf(file,",");
	fclose(file);
	
	printf("Digite o sobrenome a ser cadastrado: ");
	scanf("%s",sobrenome);
	
	file = fopen(arquivo, "a");
	fprintf(file,sobrenome);
	fclose(file);
	
	file = fopen(arquivo, "a");
	fprintf(file,",");
	fclose(file);
	
	printf("Digite o cargo a ser cadastrado: ");
	scanf("%s",cargo);
	
	file = fopen(arquivo, "a");
	fprintf(file,cargo);
	fclose(file);
	
	system("pause");
}

int consulta() // Conslutando nomes do banco de dados
{
	setlocale(LC_ALL, "Portuguese"); // Definindo a linguagem
	
	char cpf[40];
	char conteudo[200];
	
	printf ("Digite o CPF a ser Consultado: ");
	scanf("%s",cpf);
	
	FILE *file;
	file = fopen(cpf, "r"); // "r" read para ler inform��es do arquivo
	
	if(file == NULL)
	{
		printf("N�o foi possivel abrir o arquivo. N�o localizado!\n");
	}
	
	while(fgets(conteudo, 200, file) != NULL)
	{
		printf("\nEssas s�o as informa��es do usu�rio: ");
		printf("%s", conteudo);
		printf("\n\n");
	}
	
	system("pause");
}

int deletar() // Deletando nomes do banco de dados
{
	char cpf[40];
	printf("Digite o cpf a ser deletado: ");
	scanf("%s",cpf);
	
	remove(cpf);
	
	FILE *file;
	file = fopen(cpf,"r");
	
	if(file == NULL)
	{
		printf("O usu�rio n�o se encontra no sistema!\n");
		system("pause");
	}
	
}

int main()
{
	
	int opcao=0; // Definindo variav�is
	
	int loop=1;
	
	for(loop=1;loop=1;)
	{
		
		system("cls"); // Respons�vel por limpar a tela
		
					
		
		setlocale(LC_ALL, "Portuguese"); // Definindo a linguagem
	
		printf("*** Registro de Nomes ***\n\n"); // Un�cio do menu
		printf("Escolha a op��o desejada do menu:\n\n");
		printf("\t1 - Registrar nomes\n");
		printf("\t2 - Consultar nomes\n");
		printf("\t3 - Deletar nomes\n"); // Fim do menu
		printf("\t4 - Sair do sistema\n\n");
		printf("Op��o: ");
	
		scanf("%d", &opcao); // Armazenando escolha do usu�rio
	
		system("cls");
		
	
		switch(opcao)
		{
			case 1:
			registro(); // Chamada de fun��es
			break;
			
			case 2:
			consulta();
			break;
			
			case 3:
			deletar();
			break;
			
			case 4:
			printf("Obrigado por utilizar o sistema!\n");
			return 0;
			break;
			
			default:
			printf("Op��o n�o dispon�vel\n\n");
			system("pause");
			break;
			// Fim da sele��o
	
		}
	}

}

