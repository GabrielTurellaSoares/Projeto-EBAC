#include <stdio.h> //biblioteca de comunicação com o usuário
#include <stdlib.h> //biblioteca de alocação de memória
#include <locale.h> //biblioteca de texto por região
#include <string.h> //biblioteca responsável por cuidar das strings

int registro() // Função responsável por cadastrar usuários
{
	// Início da criacão de variáveis
	char arquivo[40];
	char cpf[40];
	char nome[40];
	char sobrenome[40];
	char cargo[40];
	// Fim da criação de variáveis
	
	printf("Digite o cpf a ser cadastrado: "); // Coletando informações do usuário
	scanf("%s", cpf); // %s refere-se a string
	
	strcpy(arquivo, cpf); // responsável por copiar os valores da string
	
	FILE *file; // cria o arquivo
	file = fopen(arquivo, "w"); // cria o arquivo "w" write escreve no arquivo file
	fprintf(file,cpf); // salva o valor da variável
	fclose(file); // fecha o arquivo
	
	file = fopen(arquivo, "a"); // "a" altera texto do arquivo file
	fprintf(file,",");
	fclose(file);
	
	printf("Digite o nome a ser cadastrado: ");
	scanf("%s",nome);
	
	file = fopen(arquivo, "a"); // abre o arquivo para alterar
	fprintf(file,nome);
	fclose(file); // fecha o arquivo depois da alteração
	
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
	file = fopen(cpf, "r"); // "r" read para ler informções do arquivo
	
	if(file == NULL)
	{
		printf("Não foi possivel abrir o arquivo. Não localizado!\n");
	}
	
	while(fgets(conteudo, 200, file) != NULL)
	{
		printf("\nEssas são as informações do usuário: ");
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
		printf("O usuário não se encontra no sistema!\n");
		system("pause");
	}
	
}

int main()
{
	
	int opcao=0; // Definindo variavéis
	
	int loop=1;
	
	for(loop=1;loop=1;)
	{
		
		system("cls"); // Responsável por limpar a tela
		
					
		
		setlocale(LC_ALL, "Portuguese"); // Definindo a linguagem
	
		printf("*** Registro de Nomes ***\n\n"); // Unício do menu
		printf("Escolha a opção desejada do menu:\n\n");
		printf("\t1 - Registrar nomes\n");
		printf("\t2 - Consultar nomes\n");
		printf("\t3 - Deletar nomes\n"); // Fim do menu
		printf("\t4 - Sair do sistema\n\n");
		printf("Opção: ");
	
		scanf("%d", &opcao); // Armazenando escolha do usuário
	
		system("cls");
		
	
		switch(opcao)
		{
			case 1:
			registro(); // Chamada de funções
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
			printf("Opção não disponível\n\n");
			system("pause");
			break;
			// Fim da seleção
	
		}
	}

}

