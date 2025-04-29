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
//Fun��o para criar Login
int criarlogin() {
	configurarambiente();
	
	char login[40], senha[40];
	
	    printf ("\n\n\t == Cadastro de Login == \n\n");
		printf ("\tNenhum login encontrado.\n");
		printf ("\tCrie um novo login e senha.\n\n");
		
		printf("Digite um Login: ");
		scanf("%s", login);
		printf("Digite uma senha: ");
		scanf("%s", senha);
		
		FILE *file = fopen ("login_senha.txt", "w");
		if (file != NULL) {
	       fprintf(file, "%s\n", login);
           fprintf(file, "%s\n", senha);
		   fclose(file);
		   
		   limpartela();
		   printf ("\n\n\t == Login criado com sucesso! ==\n\n\n");
		   return 1;
	    } 
		else {
	       printf ("\n\n\t == Erro ao criar login! ==\n\n\n");
		}
		   system("pause");
		   return 0;
	}
//Fun��o de login de usuario
int login() {
	
	char login[40], senha[40];
	char filelogin[40], filesenha[40];
	
	while (1) {
	configurarambiente();
	
	FILE*file = fopen("login_senha.txt", "r");
	if (file == NULL) 
	{ //Se o arquivo Login_Senha.txt n�o existir, manda para a cria��o de Login.
	criarlogin();
	} else {
		printf("\n\n\t == Acesso de login == \n\n");
		printf("\t\nPor favor digite seu login\n\n");
		
		printf("Digite um login: ");
		scanf("%s", login);
		printf("Digite uma senha: ");
		scanf("%s", senha);
		
		fscanf(file, "%s", filelogin);
		fscanf(file, "%s", filesenha);
		fclose(file);
		
		if (strcmp(login, filelogin) == 0 && strcmp (senha, filesenha) == 0) {
			printf("\t\nLogin correto, bem vindo!\n\n");
			system("pause");
			return 1;
		} else {
		    printf("\t\nLogin incorreto, tente novamente!\n\n");
		    system("pause");
			}
	}
 }
	
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
        
        scanf("%s", &opcao);
        
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
