#include <stdio.h> // Biblioteca para entrada e sa�da de dados
#include <stdlib.h> // Biblioteca para aloca��o de mem�ria
#include <locale.h> // Biblioteca para configura��o de localiza��o
#include <string.h> // Biblioteca para manipula��o de strings

// Fun��o para limpar a tela
int limpartela() {
    #ifdef _WIN32
        return system("cls");
    #else
        return system("clear");
    #endif
}
// Fun��o para configurar o ambiente
void configurarambiente() {
    setlocale(LC_ALL, "Portuguese");
    limpartela();
}
//Fun��o de login de usuario
void login() {
	return;
}
// Fun��o para registro de usu�rios
void registro() {
    configurarambiente();

    char arquivo[40];
    char cpf[40], nome[40], sobrenome[40], cargo[40];

    printf("\n\t== Digite as informa��es do cadastro ==\n\n");
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
// Fun��o para pesquisa de usu�rios
void pesquisa() {
    configurarambiente();

    char cpf[40], conteudo[200];

    printf("Digite o CPF para consulta: ");
    scanf("%s", cpf);
    FILE *file = fopen(cpf, "r");
    if (file == NULL) {
        printf("\nCPF n�o encontrado.\n");
    } else {
        printf("\nInforma��es do usu�rio:\n");
        while (fgets(conteudo, 200, file) != NULL) {
            printf("%s", conteudo);
        }
        fclose(file);
    }
    system("pause");

  
}
// Fun��o para deletar cadastro de usu�rios
void deletar() {
    configurarambiente();

    char cpf[40];

    printf("\n\t== Digite o CPF para ser deletado ==\n\n");
    printf("CPF: ");
    scanf("%s", cpf);

    if (remove(cpf) == 0) {
        printf("\nCadastro deletado com sucesso!\n");
    } else {
        printf("\nCPF n�o encontrado ou erro ao deletar.\n");
    }
    system("pause");

 
}
// Fun��o de menu principal
void menu() {
	char opcao[10];
	while (1) {
		configurarambiente();
		
		printf("\n\n\t == Cart�rio de Registro == \n\n");
        printf("\tEscolha uma op��o no menu: \n");
        printf("\t1 - Cadastrar Usu�rio\n");
        printf("\t2 - Pesquisar Usu�rio\n");
        printf("\t3 - Deletar Usu�rio\n");
        printf("\tQ - Sair\n\n");
        printf("Op��o: ");
        
        scanf(" %s", &opcao);
        
        if (strlen(opcao) != 1) {
        	limpartela();
            printf("\n\n\tOp��o Inv�lida. Tente novamente.\n\n\n");
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
	      	printf("\n\n\tEsse e um programa de Kau� F.\n");
	      	printf("\tObrigado por usar!\n\n\n");
	      	system("pause");
		    return;
		   break;
		 
		  default:
		  	limpartela();
		  	printf("\n\n\tOp��o Invalida. Tente novamente.\n");
		  	system("pause");
		   break;
		}
	}
}
// Fun��o principal
int main() {
	login();
	menu();
	return 0;
}
