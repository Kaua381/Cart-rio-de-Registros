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
//Função para criar Login
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
//Função de login de usuario
int login() {
	
	char login[40], senha[40];
	char filelogin[40], filesenha[40];
	
	while (1) {
	configurarambiente();
	
	FILE*file = fopen("login_senha.txt", "r");
	if (file == NULL) 
	{ //Se o arquivo Login_Senha.txt não existir, manda para a criação de Login.
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
        
        scanf("%s", &opcao);
        
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
