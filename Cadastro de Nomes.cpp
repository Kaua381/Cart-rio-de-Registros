#include <stdio.h> //bbt comunica��o com usuario
#include <stdlib.h> //bbt aloca��o de espa�o em mem�ria
#include <locale.h> //bbt de aloca��o de texto por regi�o
#include <string.h> //bbt responsavel pelo cuidado da string


// Fun��o para limpar a tela
int limpartela() {
    int result;
    #ifdef _WIN32
        result = system("cls");
    #else
        result = system("clear");
    #endif
}

int configurarambiente() {
	setlocale(LC_ALL, "Portuguese");
	limpartela();
}

// Fun��o de pergunta generica
int perguntar(const char* mensagem) {
	limpartela();
	int opcao;
	while (1) {
		printf("\n%s\n", mensagem);
		printf("\n1 - Sim");
		printf("\n2 - N�o");
		printf("\n\nop��o: ");
		if (scanf("%d", &opcao) != 1) {
			printf("\nOp��o invalida, tente denovo.");
			while (getchar() != '\n');
		} 
		else if (opcao == 1 || opcao == 2) {
			return opcao;
		}
		else {
			printf("\nOp��o Inv�lida, Por favor, escolha 1 ou 2.\n");
		}
	}
}

int registro() {
	
	configurarambiente();
	
    char arquivo[40];
    char cpf[40], nome[40], sobrenome [40], cargo[40];
    
    printf("\n\t== Digite as informa��es do cadastro ==\n\n");
    printf("CFP: ");
    scanf("%s", cpf);
    
    strcpy(arquivo, cpf);
    
    printf("NOME: ");
    scanf("%s", nome);
    printf("SOBRENOME: ");
    scanf("%s", sobrenome);
    printf("CARGO: ");
    scanf("%s", cargo);
    
     FILE *file = fopen(arquivo, "w");
    if (file != NULL) {
        fprintf(file, "CPF: %s\n", cpf);
        fprintf(file, "NOME: %s %s\n", nome, sobrenome);
        fprintf(file, "CARGO: %s\n", cargo);
        fclose(file);
        printf("\nCadastro salvo com sucesso!\n");
    } else {
        printf("\nErro ao criar o arquivo!\n");
    }
    system("pause");
    
    if (perguntar("Gostaria de cadastrar outro usu�rio?") == 1) {
    	registro();
	}
}
int pesquisa(){
    configurarambiente(); // definir linguagem
    
    char cpf[40], conteudo[200];
    
    printf("Digite o CPF para consulta: ");
    scanf("%s", cpf);
    FILE *file = fopen(cpf, "r");
    if (file == NULL) 
	{
        printf("\nCPF n�o encontrado.\n");
    }
	else 
	{
        printf("\nInforma��es de usu�rio:\n");
        while (fgets(conteudo, 200, file) != NULL) 
		{
            printf("%s", conteudo);
        }
        fclose(file);
    }
    system("pause");
    
    if (perguntar("Gostaria de pesquisar outro usu�rio?") == 1) {
    	registro();
	}
}
int deletar(){
	configurarambiente(); // definir linguagem
    char cpf[40];
    
    printf("\n\t== Digite o CPF para ser deletado ==\n\n");
    printf("CPF: ");
    scanf("%s",cpf);
    
    if (remove(cpf) == 0) 
    {
        printf("\nCadastro deletado com sucesso!\n");
    } 
	else 
	{
        printf("\nCPF n�o encontrado ou erro ao deletar.\n");
    }
    system("pause");
    
    if (perguntar("Gostaria de deletar outro usu�rio?") == 1) {
    	registro();
	}
}
int main(){
	int opcao=0;//definir variavel
	int x=1;
	
	for(x=1;x=1;)//repeti��o
	{
	  limpartela();//chama fun��o de limpar tela
			
	  configurarambiente();//definir linguagem
	
	  printf("\n\n\t == Cart�rio de Registro == \n\n");//inicio do menu
	  printf("\tEscolha uma op��o no menu: \n");
	  printf("\t1 - Cadastrar Usu�rio\n");
	  printf("\t2 - Pesquisar Usu�rio\n");
	  printf("\t3 - Deletar Usu�rio\n");
	  printf("\t4 - Sair\n\n");
	  printf("Op��o:");//final do menu
	
	  scanf("%d", &opcao);//armazenar op��o do usu�rio
	
	  limpartela();//chama fun��o de limpar tela
	  
	  switch(opcao)//sele��o de op��o
	  {
	  	case 1:
	  	  registro();
		break;
		
		case 2:
          pesquisa();
		break;
		
		case 3:
          deletar();
		break;
		
		  case 4:
		  printf("\n\tEsse e um programa criado por Kau� F.\n");
		  printf("\n\tMuito obrigado por usar!\n\n");
		  system("pause");
		  return 0;
		break;
		
		  default:
		  printf("\n\tEssa op��o n�o Existe!\n\n");
		  
		  system("pause");
		  break;
	   }//finalizar sele��o
    }
}
