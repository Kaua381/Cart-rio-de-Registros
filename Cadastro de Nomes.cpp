#include <stdio.h> //bbt comunicação com usuario
#include <stdlib.h> //bbt alocação de espaço em memória
#include <locale.h> //bbt de alocação de texto por região
#include <string.h> //bbt responsavel pelo cuidado da string

int registro()
{
	
	setlocale(LC_ALL, "Portuguese");
	
    char arquivo[40];
    char cpf[40], nome[40], sobrenome [40], cargo[40];
    
    printf("\n\t== Digite as informações do cadastro ==\n\n");
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
}

int pesquisa()
{
    setlocale(LC_ALL, "Portuguese"); // definir linguagem
    char cpf[40], conteudo[200];

    printf("Digite o CPF para consulta: ");
    scanf("%s", cpf);

    FILE *file = fopen(cpf, "r");
    if (file == NULL) 
	{
        printf("\nCPF não encontrado.\n");
    }
	else 
	{
        printf("\nInformações de usuário:\n");
        while (fgets(conteudo, 200, file) != NULL) 
		{
            printf("%s", conteudo);
        }
        fclose(file);
    }

    system("pause");
}

int deletar()
{
	setlocale(LC_ALL, "Portuguese"); // definir linguagem
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
        printf("\nCPF não encontrado ou erro ao deletar.\n");
    }

    system("pause");
}

int main()
{
	int opcao=0;//definir variavel
	int x=1;
	
	for(x=1;x=1;)//repetição
	{
	  system("cls"); // Limpa a tela antes de mostrar o menu
			
	  setlocale(LC_ALL, "Portuguese");//definir linguagem
	
	  printf("\n\n\t == Cartório de Registro == \n\n");//inicio do menu
	  printf("\tEscolha uma opção no menu: \n");
	  printf("\t1 - Cadastrar Usuário\n");
	  printf("\t2 - Pesquisar Usuário\n");
	  printf("\t3 - Deletar Usuário\n");
	  printf("\t4 - Sair\n\n");
	  printf("Opção:");//final do menu
	
	  scanf("%d", &opcao);//armazenar opção do usuário
	
	  system("cls");//limpar tela apos seleção
	  
	  switch(opcao)//seleção de opção
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
		  printf("\n\tEsse e um programa criado por Kauã F.\n");
		  printf("\n\tMuito obrigado por usar!\n\n");

		  system("pause");
		  return 0;
		break;
		
		  default:
		  printf("\n\tEssa opção não Existe!\n\n");
		  
		  system("pause");
		  break;
	   }//finalizar seleção
    }
}




