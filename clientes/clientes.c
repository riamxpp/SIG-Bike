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
    char nome[100];
    char cpf[15];
    char email[100];
    char fone[20];
    menuCadastrarCliente();

    do {
        printf("║ Nome: ");
        scanf("%99[^\n]", nome);
        while (getchar() != '\n');
        if (!validarNome(nome)) {
            printf("  Entrada inválida. Digite apenas letras e espaços.\n");
            printf("\n");
        }
    } while (!validarNome(nome));

    do{
        printf("║ CPF (xxx.xxx.xxx-xx ou xxxxxxxxxxx): ");
        scanf("%14s", cpf);
        while (getchar() != '\n');
        if (!validarCPF(cpf)) {
            printf("  CPF inválido. \n");
            printf("\n");
        }
    }while (!validarCPF(cpf));

    do{ 
        printf("║ Email: ");
        scanf("%99s", email);
        while (getchar() != '\n');
        if (!validarEmail(email)) {
            printf("  Email inválido. \n");
            printf("\n");
        }
    }while (!validarEmail(email));

    do{
        printf("║ Telefone (DD000000000): ");
        scanf("%19s", fone);
        while (getchar() != '\n');
        if (!validarTelefone(fone)) {
            printf("  Telefone inválido. \n");
            printf(" \n");
        }
    }while (!validarTelefone(fone));
    printf("║ Data de Nascimento:                                                           ║\n");
    printf("║                                                                               ║\n");
    printf("║                        Cliente cadastrado com sucesso!                        ║\n");
    printf("╚═══════════════════════════════════════════════════════════════════════════════╝\n");
    printf("Tecle <ENTER> para continuar...");
    getchar();
    
}

void pesquisarCliente(void){
    menuPesquisarCliente();
    printf("║ Digite o CPF do Cliente:                                                      ║\n");
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