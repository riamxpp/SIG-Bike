#include <stdio.h>
#include <stdlib.h>
#include "clientes.h"
#include <unistd.h>
#include "view.h"
#include "../validacao/validacao.h"

struct cliente {
    char *nome;
    char *cpf;
    char *email;
    char *fone;
    char *dtnas;    
};


void clientes(void){
    int op_cliente;
    do{
        op_cliente = menuClientes();
        switch (op_cliente) {
            case 1:
                cadastrarCliente();
                break;
            case 2:
                pesquisarCliente();
                break;
            case 3:
                atualizarCliente();
                break;
            case 4:
                deletarCliente();
                break;
            case 0:
                break;
            default:
                printf("Valor invalido");
            break;
        }
    }while(op_cliente != 0);
}

void cadastrarCliente(void){
    struct cliente cliente1;

    menuCadastrarCliente();

    cliente1.nome = (char*) malloc(100*sizeof(char));
    do {
        printf("║ Nome: ");
        scanf("%99[^\n]", cliente1.nome);
        while (getchar() != '\n');
        if (!validarNome(cliente1.nome)) {
            printf("  Entrada inválida. Digite apenas letras e espaços.\n");
            printf("\n");
        }
    } while (!validarNome(cliente1.nome));

    cliente1.cpf = (char*) malloc(15*sizeof(char));
    do{
        printf("║ CPF (xxx.xxx.xxx-xx ou xxxxxxxxxxx): ");
        scanf("%14s", cliente1.cpf);
        while (getchar() != '\n');
        if (!validarCPF(cliente1.cpf)) {
            printf("  CPF inválido. \n");
            printf("\n");
        }
    }while (!validarCPF(cliente1.cpf));

    cliente1.email = (char*) malloc(100*sizeof(char));
    do{ 
        printf("║ Email: ");
        scanf("%99s", cliente1.email);
        while (getchar() != '\n');
        if (!validarEmail(cliente1.email)) {
            printf("  Email inválido. \n");
            printf("\n");
        }
    }while (!validarEmail(cliente1.email));

    cliente1.fone = (char*) malloc(20*sizeof(char));
    do{
        printf("║ Telefone (DD000000000): ");
        scanf("%19s", cliente1.fone);
        while (getchar() != '\n');
        if (!validarTelefone(cliente1.fone)) {
            printf("  Telefone inválido. \n");
            printf(" \n");
        }
    }while (!validarTelefone(cliente1.fone));

    cliente1.dtnas = (char*) malloc(11*sizeof(char));
    do{
        printf("║ Data de Nascimento: (xx/xx/xxxx): ");
        scanf("%19s", cliente1.dtnas);
        while (getchar() != '\n');
        if (!validarDataNascimento(cliente1.dtnas)) {
            printf("  Data de Nascimento inválida. \n");
            printf(" \n");
        }
    }while (!validarDataNascimento(cliente1.dtnas));
    printf("\n╔═══════════════════════════════════════════════════════════════════════════════╗\n");
    printf("║                        Cliente cadastrado com sucesso!                        ║\n");
    printf("╚═══════════════════════════════════════════════════════════════════════════════╝\n");
    printf("Tecle <ENTER> para continuar...");
    getchar();
    free(cliente1.cpf);
    free(cliente1.nome);
    free(cliente1.email);
    free(cliente1.fone);
    free(cliente1.dtnas);
}

void pesquisarCliente(void){
    char *cpf;

    menuPesquisarCliente();

    cpf = (char*) malloc(15*sizeof(char));
    do{
        printf("║ CPF (xxx.xxx.xxx-xx ou xxxxxxxxxxx): ");
        scanf("%14s", cpf);
        while (getchar() != '\n');
        if (!validarCPF(cpf)) {
            printf("  CPF inválido. \n");
            printf("\n");
        }
    }while (!validarCPF(cpf));

    printf("║                                                                               ║\n");
    printf("║ Nome:                                                                         ║\n");
    printf("║ CPF:                                                                          ║\n");
    printf("║ Email:                                                                        ║\n");
    printf("║ Fone:                                                                         ║\n");
    printf("║ Data de Nascimento:                                                           ║\n");
    printf("║                                                                               ║\n");
    printf("╚═══════════════════════════════════════════════════════════════════════════════╝\n");
    printf("Tecle <ENTER> para continuar...");
    getchar();
    free(cpf);
}

void atualizarCliente(void){
    char *cpf;
    char *nome;
    char *email;
    char *fone;
    char *dtnas;

    menuAtualizarCliente();

    cpf = (char*) malloc(15*sizeof(char));
    
    do{
        printf("║ Digite o CPF do Cliente: ");      
        scanf("%14s", cpf);
        while (getchar() != '\n');
        if (!validarCPF(cpf)) {
            printf("  CPF inválido. \n");
            printf("\n");
        }
    }while (!validarCPF(cpf));
    free(cpf);

    printf("║                                                                               ║\n");
    printf("║                           ↪Digite os Novos Dados↩                             ║\n");
    nome = (char*) malloc(100*sizeof(char));

    do {
        printf("║ Nome: ");
        scanf("%99[^\n]", nome);
        while (getchar() != '\n');
        if (!validarNome(nome)) {
            printf("  Entrada inválida. Digite apenas letras e espaços.\n");
            printf("\n");
        }
    } while (!validarNome(nome));

    cpf = (char*) malloc(15*sizeof(char));
    
    do{
        printf("║ CPF (xxx.xxx.xxx-xx ou xxxxxxxxxxx): ");
        scanf("%14s", cpf);
        while (getchar() != '\n');
        if (!validarCPF(cpf)) {
            printf("  CPF inválido. \n");
            printf("\n");
        }
    }while (!validarCPF(cpf));

    email = (char*) malloc(100*sizeof(char));
    do{ 
        printf("║ Email: ");
        scanf("%99s", email);
        while (getchar() != '\n');
        if (!validarEmail(email)) {
            printf("  Email inválido. \n");
            printf("\n");
        }
    }while (!validarEmail(email));

    fone = (char*) malloc(20*sizeof(char));
    do{
        printf("║ Telefone (DD000000000): ");
        scanf("%19s", fone);
        while (getchar() != '\n');
        if (!validarTelefone(fone)) {
            printf("  Telefone inválido. \n");
            printf(" \n");
        }
    }while (!validarTelefone(fone));
    
    dtnas = (char*) malloc(11*sizeof(char));
    do{
        printf("║ Data de Nascimento: (xx/xx/xxxx): ");
        scanf("%19s", dtnas);
        while (getchar() != '\n');
        if (!validarDataNascimento(dtnas)) {
            printf("  Data de Nascimento inválida. \n");
            printf(" \n");
        }
    }while (!validarDataNascimento(dtnas));

    printf("║                                                                               ║\n");
    printf("╚═══════════════════════════════════════════════════════════════════════════════╝\n");
    printf("Tecle <ENTER> para continuar...");
    getchar();

    free(cpf);
    free(nome);
    free(email);
    free(fone);
    free(dtnas);
}

void deletarCliente(void){
    system("clear||cls");
    printf("\n╔═══════════════════════════════════════════════════════════════════════════════╗\n");
    printf("║                               Excluir Cliente                                 ║\n");
    printf("╚═══════════════════════════════════════════════════════════════════════════════╝\n");
    printf("║ Digite o CPF do Cliente:                                                      ║\n");

    char *cpf;
    cpf = (char*) malloc(15*sizeof(char));
    
    do{
        printf("║ CPF (xxx.xxx.xxx-xx ou xxxxxxxxxxx): ");
        scanf("%14s", cpf);
        while (getchar() != '\n');
        if (!validarCPF(cpf)) {
            printf("  CPF inválido. \n");
            printf("\n");
        }
    }while (!validarCPF(cpf));

    printf("║                                                                               ║\n");
    printf("╚═══════════════════════════════════════════════════════════════════════════════╝\n");
    printf("Tecle <ENTER> para continuar...");
    getchar();
    free(cpf);
}