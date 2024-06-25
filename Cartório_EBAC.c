#include <stdio.h>// biblioteca de comunicação com o usuario
#include <stdlib.h>//biblioteca de alocação de espaço em memoria
#include <locale.h>//biblioteca de alocações de texto por regiaõ
#include <string.h> //biblioteca responsavel por cuidar das strings 

int registro ()// função responsavel por cadastrar os usuarios no sistema
{
	//inicio criação  de variaves/string
	char arquivo[40];
	char cpf[40];
	char nome[40];
	char sobrenome[40];
	char cargo[40];
	//final criação  de variaves/string
	
	printf("digite o cpf a ser cadastrado:"); //coletando informação do usuario
	scanf("%s", cpf); //%s refere-se a string
	
	strcpy(arquivo, cpf); //responsavel por copiar os valores das string
	
	FILE *file; //cria o arquivo
	file = fopen(arquivo, "w"); //cria o arquivo e o W  significa escrever
	fprintf(file,cpf); //salva o valor da variavel 
	fclose(file); //fecha o arquivo
	
	file = fopen(arquivo, "a");
	fprintf(file,",");
	fclose(file);
	
	printf("digite o nome a ser cadastrado:");
	scanf("%s",nome);
	
	file = fopen(arquivo, "a");
	fprintf(file,nome);
	fclose(file);
	
	file = fopen(arquivo, "a");
	fprintf(file, ",");
	fclose(file);
	
	printf("digite o sobrenome a ser cadastrado: ");
	scanf("%s", sobrenome);
	
	file = fopen(arquivo, "a");
	fprintf(file,sobrenome);
	fclose(file);
	
	file = fopen(arquivo, "a");
	fprintf(file,",");
	fclose(file);
	
	printf("digite o cargo a ser cadastrado: ");
	scanf("%s", cargo);
	
	file=fopen(arquivo,"a");
	fprintf(file,cargo);
	fclose (file);
	
	system("pause");
	
}

int consulta()
{
	setlocale(LC_ALL, "portuguese"); //definindo a linguagem
	
	char cpf[40];
	char conteudo[200];
	
	printf("digite o cpf a ser consultado: ");
	scanf("%s",cpf);
	
	FILE* file;
	file = fopen(cpf, "r");
	
	if(file == NULL)
	{
		printf("Não foi possivel abri o arquivo, não localizado!.\n");
	}
	
	while(fgets(conteudo, 200, file) != NULL)
	{
		printf("\nEssas são as informações do usuario: ");
		printf("%s", conteudo);
		printf("\n\n");
	}
	
	system("pause");
	
}


int deletar()
{
	char cpf[40];
	
	printf("Digite o CPF a ser deletado: ");
	scanf("%s", cpf);
	
	remove(cpf);
	
	FILE *file;
	file = fopen(cpf,"r");
	
	if(file == NULL);
	{
		printf("O usuario não se encontra no sistema!.\n");
		system("pause");
	}
	 
}



int main()	
	{			
	int opcao=0; //definindo variaveis
	int laco=1;
	
	for(laco=1;laco=1;)
	{
	
		
		system("cls");
	
		setlocale(LC_ALL, "portuguese"); //definindo a linguagem
	
		printf("### Cartório EBAC ### \n\n"); //inicio do menu
		printf("Escolha função desejada do menu:\n");
		printf("\t1- Consultar nomes \n");
		printf("\t2- Registrar nomes \n");
		printf("\t3- Deletar nomes \n\n");
		printf("opção: "); //fim do menu

		scanf("%d", &opcao); //armazenando a escolha do usuario 
	
		system("cls"); //responsavel por limpar a tela 
	
	
		switch(opcao)
			{		
			case 1: 
			consulta();
			break;
		
			case 2:
			registro();
			break;
				
			case 3:
			deletar();
			break;
		
			default:
			printf("Essa opção não está disponivel!\n");
			system("pause");
			break;
			}
		
		}	
	}	
	
	
	



