#include <stdio.h>
#include <stdlib.h>
#include "clientes.h"
#include <unistd.h>
#include "view.h"
#include "../validacao/validacao.h"

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
    char *nome;
    char *cpf;
    char *email;
    char *fone;
    char *dtnas;
    menuCadastrarCliente();

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
    printf("\n╔═══════════════════════════════════════════════════════════════════════════════╗\n");
    printf("║                        Cliente cadastrado com sucesso!                        ║\n");
    printf("╚═══════════════════════════════════════════════════════════════════════════════╝\n");
    printf("Tecle <ENTER> para continuar...");
    getchar();
    
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
}

void atualizarCliente(void){
    menuAtualizarCliente();
    printf("║ Digite o CPF do Cliente:                                                      ║\n");
    printf("║                                                                               ║\n");
    printf("║                           ↪Digite os Novos Dados↩                             ║\n");
    printf("║ Nome:                                                                         ║\n");
    printf("║ CPF:                                                                          ║\n");
    printf("║ Email:                                                                        ║\n");
    printf("║ Fone:                                                                         ║\n");
    printf("║ Data de Nascimento:                                                           ║\n");
    printf("║                                                                               ║\n");
    printf("╚═══════════════════════════════════════════════════════════════════════════════╝\n");
    printf("Tecle <ENTER> para continuar...");
    getchar();
}

void deletarCliente(void){
    system("clear||cls");
    printf("\n╔═══════════════════════════════════════════════════════════════════════════════╗\n");
    printf("║                               Excluir Cliente                                 ║\n");
    printf("╚═══════════════════════════════════════════════════════════════════════════════╝\n");
    printf("║ Digite o CPF do Cliente:                                                      ║\n");
    printf("║                                                                               ║\n");
    printf("╚═══════════════════════════════════════════════════════════════════════════════╝\n");
    printf("Tecle <ENTER> para continuar...");
    getchar();
}