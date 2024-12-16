#include <stdio.h>
#include <stdlib.h>
#include "clientes.h"
#include <unistd.h>
#include "view.h"
#include "../validacao/validacao.h"
#include "../util/util.h"
#include <string.h>

void clientes(void){
    Cliente* cli;
    int op_cliente;
    do{
        op_cliente = menuClientes();
        switch (op_cliente) {
            case 1:
                cli = preencherCliente();
                gravaArquivo("clientes.dat", cli, sizeof(Cliente));
                break;
            case 2:
                cli = pesquisarCliente();
                exibeCliente(cli);
                break;
            case 3:
                //atualizarCliente();
                break;
            case 4:
                cli = pesquisarCliente();
                deletarCliente(cli);
                break;
            case 0:
                break;
            default:
                printf("Valor invalido");
            break;
        }
    }while(op_cliente != 0);
    free(cli);
}

Cliente* preencherCliente(void){
    Cliente* cli;
    cli = (Cliente*) malloc(sizeof(Cliente));
    if (cli == NULL) {
        printf("Erro ao alocar mémoria para cliente!!\n");
        exit(1);
    }
    menuCadastrarCliente();
    const char* arquivoClientes = "clientes.dat";
    do {
        printf("║ Nome: ");
        scanf(" %50[^\n]", cli->nome);
        if (!validarNome(cli->nome)) {
            printf("  Entrada inválida. Digite apenas letras e espaços.\n");
            printf("\n");
            while (getchar() != '\n');
            free(cli);
            return NULL;
        }
    } while (!validarNome(cli->nome));

    do {
        printf("║ CPF (xxx.xxx.xxx-xx ou xxxxxxxxxxx): ");
        scanf(" %50[^\n]", cli->cpf);
        if (!validarCPF(cli->cpf)) {
            printf("  CPF inválido! \n");
            printf("\n");
            while (getchar() != '\n');
            free(cli);
            return NULL;
        }
    } while (!validarCPF(cli->cpf));

    do {
        printf("║ Email: ");
        scanf(" %50[^\n]", cli->email);
        if (!validarEmail(cli->email)) {
            printf("  Email inválido! \n");
            printf("\n");
            while (getchar() != '\n');
            free(cli);
            return NULL;
        }
    } while (!validarEmail(cli->email));

    do {
        printf("║ Telefone: ");
        scanf(" %50[^\n]", cli->fone);
        if (!validarTelefone(cli->fone)) {
            printf("  Telefone inválido! \n");
            printf("\n");
            while (getchar() != '\n');
            free(cli);
            return NULL;
        }
    } while (!validarTelefone(cli->fone));

    do {
        printf("║ Data de nascimento: ");
        scanf(" %50[^\n]", cli->dtnas);
        if (!validarDataNascimento(cli->dtnas)) {
            printf("  Data de Nascimento inválida! \n");
            printf("\n");
            while (getchar() != '\n');
            free(cli);
            return NULL;
        }
    } while (!validarDataNascimento(cli->dtnas));
    cli->id = obterProximoID(arquivoClientes, sizeof(Cliente));
    exibeCliente(cli);
    printf("\n╔═══════════════════════════════════════════════════════════════════════════════╗\n");
    printf("║                        Cliente cadastrado com sucesso!                        ║\n");
    printf("╚═══════════════════════════════════════════════════════════════════════════════╝\n");
    printf("Tecle <ENTER> para continuar...");
    getchar();
    return(cli);
}

/*
int obterProximoID() {
    FILE* arquivo = fopen("clientes.dat", "rb");
    if (arquivo == NULL) {
        return 1;
    }
    Cliente temp;
    int ultimoID = 0;

    while (fread(&temp, sizeof(Cliente), 1, arquivo) == 1) {
        ultimoID = temp.id;
    }

    fclose(arquivo);
    return ultimoID + 1;
}
*/

Cliente* pesquisarCliente(void){
    Cliente* cli = malloc(sizeof(Cliente));
    char cpf[12];
    menuPesquisarCliente();

    printf("║ Informe o CPF (xxx.xxx.xxx-xx ou xxxxxxxxxxx): ");
    scanf(" %50[^\n]", cpf);
    if (!validarCPF(cpf)) {
        printf("CPF inválido!\n\n");
        while (getchar() != '\n');
        free(cli);
        return NULL;
    }

    cli = buscarCliente(cpf, cli);
    if (cli == NULL) {
        printf("Cliente não encontrado!!\n\n");
        return NULL;
    }

    return cli;
}

Cliente* buscarCliente(char cpf[12], Cliente* cliente) {
    FILE* fp;
    fp = fopen("clientes.dat", "rb");
    if (fp == NULL) {
        printf("Ops! Erro na abertura do arquivo!\n");
        printf("Não é possível continuar...\n");
        free(cliente);
        return NULL;
    }

    while (fread(cliente, sizeof(Cliente), 1, fp) == 1) {
        if (!strcmp(cliente->cpf, cpf)) {
            fclose(fp);
            return cliente;
        }
    }
    
    free(cliente);
    fclose(fp);
    return NULL;
}

void exibeCliente(Cliente* cli) {
    if (cli == NULL) {
        printf("\n= = = Cliente Inexistente = = =\n");
    } else {
        printf("\n= = = Cliente Cadastrado = = =\n");
        printf("║ ID: %d\n", cli->id);
        printf("║ Nome: %s\n", cli->nome);
        printf("║ CPF: %s\n", cli->cpf);
        printf("║ Email: %s\n", cli->email);
        printf("║ Telefone: %s\n", cli->fone);
        printf("║ Data de Nascimento: %s\n", cli->dtnas);
    }
    printf("Tecle <ENTER> para continuar...");
    getchar();
    getchar();
}

/*
void atualizarCliente(void){
    struct cliente cliente1;
    menuAtualizarCliente();

    cliente1.cpf = (char*) malloc(15*sizeof(char));
    
    do{
        printf("║ Digite o CPF do Cliente: ");      
        scanf("%14s", cliente1.cpf);
        while (getchar() != '\n');
        if (!validarCPF(cliente1.cpf)) {
            printf("  CPF inválido. \n");
            printf("\n");
        }
    }while (!validarCPF(cliente1.cpf));
    free(cliente1.cpf);

    printf("║                                                                               ║\n");
    printf("║                           ↪Digite os Novos Dados↩                             ║\n");
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

    printf("║                                                                               ║\n");
    printf("╚═══════════════════════════════════════════════════════════════════════════════╝\n");
    printf("Tecle <ENTER> para continuar...");
    getchar();

    free(cliente1.cpf);
    free(cliente1.nome);
    free(cliente1.email);
    free(cliente1.fone);
    free(cliente1.dtnas);
}
*/

void deletarCliente(Cliente *cliLido){
    FILE *fp, *temp;
    Cliente* cliArq;
    int achou = 0;

    system("clear||cls");
    printf("\n╔═══════════════════════════════════════════════════════════════════════════════╗\n");
    printf("║                               Excluir Cliente                                 ║\n");
    printf("╚═══════════════════════════════════════════════════════════════════════════════╝\n");
    printf("║ Digite o CPF do Cliente:                                                      ║\n");

    if (cliLido == NULL) {
        printf("O cliente informado não existe!\n");
        return;
    } 

    cliArq = (Cliente*) malloc(sizeof(Cliente));
    if(cliArq == NULL){
        printf("Erro ao alocar memória.\n");
        exit(1);
    }

    fp = fopen("clientes.dat", "rb");
    if (fp == NULL) {
        printf("Ops! Erro abertura do arquivo!\n");
        printf("Não é possível continuar...\n");
        free(cliArq);
        exit(1);
    }

    temp =fopen("temp.dat","wb");
    if (temp == NULL) {
        printf("Ops! Erro na criação do arquivo temporário!\n");
        fclose(fp);
        free(cliArq);
        exit(1);
    }

    while (fread(cliArq, sizeof(Cliente), 1, fp) == 1) {
        if (cliArq->id == cliLido->id) {
            achou = 1;
        } else {
            fwrite(cliArq, sizeof(Cliente), 1, temp);
        }
    }

    fclose(fp);
    fclose(temp);
    free(cliArq);
    if (achou) {
        remove("clientes.dat");
        rename("temp.dat", "clientes.dat");
        printf("║                                                                               ║\n");
        printf("║                          Cliente excluído com sucesso!                       ║\n");
        printf("╚═══════════════════════════════════════════════════════════════════════════════╝\n");
    } else {
        remove("temp.dat");
        printf("\nCliente não encontrado!\n");
    }
    printf("Tecle <ENTER> para continuar...");
    getchar();
}