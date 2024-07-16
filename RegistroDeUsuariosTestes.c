#include <stdio.h> 					//biblioteca de comunicação de usuário
#include <stdlib.h> 				//biblioteca de alocação de espaço em memória
#include <locale.h> 				//biblioteca de alocação de texto por região
#include <string.h> 				//biblioteca de strings

int registro()						//função para cadastrar os usários no sistema
{
	char arquivo[40];  				//string
	char cpf[40];
	char nome[40];
	char sobrenome[40];
	char cargo[40];
	
	printf("Digite seu CPF: ");
	scanf("%s", cpf);    			//salva valor para a variável CPF
	
	strcpy(arquivo, cpf); //responsável por coipar os valores das strings
	
	FILE *file; //cria arquivo no banco de dados
	file = fopen(arquivo, "w"); // cria o arquivo na pasta do program | w de write, pois vai armazenar um novo arquivo
	fprintf(file,cpf); //salva o valor da variavel
	fclose(file); // fecha o arquivo
	
	file = fopen(arquivo, "a"); //"a" para atualizar o arquivo
	fprintf(file, ", "); //para adicionar um "," no final do cpf
	fclose(file);
	
	printf("Digite seu primeiro nome: ");
	scanf("%s",nome);
	
	file = fopen(arquivo, "a");
	fprintf(file,nome);
	fclose(file);
	
	file = fopen(arquivo, "a"); 
	fprintf(file, " ");
	fclose(file);
	
	printf("Digite seu sobrenome: ");
	scanf("%s",sobrenome);
	
	file = fopen(arquivo, "a");
	fprintf(file,sobrenome);
	fclose(file);
	
	file = fopen(arquivo, "a");
	fprintf(file, ", "); 
	fclose(file);
	
	printf("Digite seu cargo: ");
	scanf("%s",cargo);
	
	file = fopen(arquivo, "a");
	fprintf(file,cargo);
	fclose(file);
	
	system("cls");
	printf("Usuário cadastrado com sucesso!\n\n");
	system("pause");

}

int consulta()
{
	char cpf[40];
	char conteudo[200];
	char *separacao;
	
	printf("Digite o CPF que deseja consultar: ");
	scanf("%s", cpf);
	
	FILE *file;
	file = fopen(cpf, "r"); //r de READING, para ler o arquivo
	
	if(file == NULL)
	{
		system("cls");
		printf("Não existe nenhum regristo para esse CPF!\n\n");
	}
	else 
	{
	
		while(fgets(conteudo, 200, file) != NULL) // enquanto tiver conteúdo dentro do arquivo
		{
			separacao = strtok(conteudo, ", ");
			if(separacao != NULL)
			{
				system("cls");
				printf("Esses são os dados do CPF que você consultou:\n\n");
				printf("CPF: %s\n", separacao);
				
				separacao = strtok(NULL, ", ");
				printf("Nome e Sobrenome: %s", separacao);
				
				separacao = strtok(NULL, ", ");
				printf(" %s\n", separacao);
				
				separacao = strtok(NULL, ", ");
				printf("Cargo: %s", separacao);
			}
		}
		printf("\n\n");
		fclose(file);
		system("pause");	
	}
	
}

int excluir()
{
	char cpf[40];
	
	printf("Digite o CPF que você deseja excluir: ");
	scanf("%s",cpf);
	
	FILE *file; 
	file = fopen(cpf, "r");
	fclose(file);
		
	if(file == NULL)// para verificar se a FILE, nesse caso o arquivo com o nome do cpf, existe, se der NULL, ele imprime o IF.
	{
		system("cls");
		printf("Não foi possível encontrar registro com esse CPF.\n\n");
	}
	else
	{
		remove(cpf); // ELE SÓ TENTA APAGAR O CPF SE ENCONTRAR ALGO, CASO NAO, VAI DIRETO PARA O IF
		system("cls");
		printf("O usuário foi deletado com sucesso!\n\n");
	}
	system("pause");
}

int main() //ponto de partida para a execução do programa
{
	int opcao=0;//definindo as variaveis
	int laco=1;
	
	for(laco=1;laco=1;)//macete para ficar sempre no for, (numero de entrada/numero de saida/se quiser operar o valor obtido)
	{
		setlocale(LC_ALL, "Portuguese"); //para identificar o idioma
		
		system("cls");
		
		printf("### Registro e Consulta de Usuários EBAC ###\n\n"); //as # servem apenas para aparência
		printf("\tO que deseja fazer?\n\n"); //o /t serve para dar um espaço, o /n pula a linha.	
		printf("\t1 - Registrar nome\n");
		printf("\t2 - Consultar nome\n");
		printf("\t3 - Excluir nome\n");
		printf("\t4 - Sair do progama\n\n");
		printf("Opção desejada: ");//fim do menu
	

		scanf("%d", &opcao);//para dar valor para a variável "opcao"
	
		system("cls");//para excluir todas as mensagens escritas antes
	
		switch(opcao)//utlizado para não ter que usar tantos IF's
		{
			case 1:
			registro(); 				//chama a função registro
			break;
			
			case 2:
			consulta();					//chama a função consulta
			break;
			
			case 3:
			excluir(); 					//chama a função excluir 
			break;
			
			case 4:
			printf("Obrigado por utilizar o nosso sistema!");
			return 0;
			break;
			
			default://o deafault no switch, é utlizado para qualquer valor que não entrar nos casos
			printf("Está opção não está disponível!\n");
			system("pause");
			break;
		}
	}
}
