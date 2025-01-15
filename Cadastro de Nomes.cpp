#include <stdio.h> // Biblioteca para entrada e saída de dados
#include <stdlib.h> // Biblioteca para alocação de memória
#include <locale.h> // Biblioteca para configuração de localização
#include <string.h> // Biblioteca para manipulação de strings

// Função para limpar a tela
int limpartela() {
    #ifdef _WIN32
        return system("cls");
    #else
        return system("clear");
    #endif
}
// Função para configurar o ambiente
void configurarambiente() {
    setlocale(LC_ALL, "Portuguese");
    limpartela();
}
//Função de login de usuario
void login() {
	return;
}
// Função para registro de usuários
void registro() {
    configurarambiente();

    char arquivo[40];
    char cpf[40], nome[40], sobrenome[40], cargo[40];

    printf("\n\t== Digite as informações do cadastro ==\n\n");
    printf("CPF: ");
    scanf("%s", cpf);

    strcpy(arquivo, cpf);

    printf("Nome: ");
    scanf("%s", nome);
    printf("Sobrenome: ");
    scanf("%s", sobrenome);
    printf("Cargo: ");
    scanf("%s", cargo);

    FILE *file = fopen(arquivo, "w");
    if (file != NULL) {
        fprintf(file, "CPF: %s\n", cpf);
        fprintf(file, "Nome: %s %s\n", nome, sobrenome);
        fprintf(file, "Cargo: %s\n", cargo);
        fclose(file);
        printf("\nCadastro salvo com sucesso!\n");
    } else {
        printf("\nErro ao criar o arquivo!\n");
    }
    system("pause");
}
// Função para pesquisa de usuários
void pesquisa() {
    configurarambiente();

    char cpf[40], conteudo[200];

    printf("Digite o CPF para consulta: ");
    scanf("%s", cpf);
    FILE *file = fopen(cpf, "r");
    if (file == NULL) {
        printf("\nCPF não encontrado.\n");
    } else {
        printf("\nInformações do usuário:\n");
        while (fgets(conteudo, 200, file) != NULL) {
            printf("%s", conteudo);
        }
        fclose(file);
    }
    system("pause");

  
}
// Função para deletar cadastro de usuários
void deletar() {
    configurarambiente();

    char cpf[40];

    printf("\n\t== Digite o CPF para ser deletado ==\n\n");
    printf("CPF: ");
    scanf("%s", cpf);

    if (remove(cpf) == 0) {
        printf("\nCadastro deletado com sucesso!\n");
    } else {
        printf("\nCPF não encontrado ou erro ao deletar.\n");
    }
    system("pause");

 
}
// Função de menu principal
void menu() {
	char opcao[10];
	while (1) {
		configurarambiente();
		
		printf("\n\n\t == Cartório de Registro == \n\n");
        printf("\tEscolha uma opção no menu: \n");
        printf("\t1 - Cadastrar Usuário\n");
        printf("\t2 - Pesquisar Usuário\n");
        printf("\t3 - Deletar Usuário\n");
        printf("\tQ - Sair\n\n");
        printf("Opção: ");
        
        scanf(" %s", &opcao);
        
        if (strlen(opcao) != 1) {
        	limpartela();
            printf("\n\n\tOpção Inválida. Tente novamente.\n\n\n");
            system("pause");
            continue;
}
        
        switch(opcao[0]) {
		  case '1':
		    registro();
		   break;
		
	  	  case '2':
		    pesquisa();
		   break;
		
	  	  case '3':
		    deletar();
		   break;
		
		  case 'Q':
	      case 'q':
	      	limpartela();
	      	printf("\n\n\tEsse e um programa de Kauã F.\n");
	      	printf("\tObrigado por usar!\n\n\n");
	      	system("pause");
		    return;
		   break;
		 
		  default:
		  	limpartela();
		  	printf("\n\n\tOpção Invalida. Tente novamente.\n");
		  	system("pause");
		   break;
		}
	}
}
// Função principal
int main() {
	login();
	menu();
	return 0;
}
