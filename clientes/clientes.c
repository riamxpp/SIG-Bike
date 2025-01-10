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
                cli = preencherCliente(0);
                gravaArquivo("clientes.dat", cli, sizeof(Cliente));
                break;
            case 2:
                cli = pesquisarCliente();
                exibeCliente(cli);
                break;
            case 3:
                cli = pesquisarCliente();
                atualizarCliente(cli);
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

Cliente* preencherCliente(int id){
    Cliente* cli;
    cli = (Cliente*) malloc(sizeof(Cliente));
    if (cli == NULL) {
        printf("Erro ao alocar mémoria para cliente!!\n");
        exit(1);
    }
    menuCadastrarCliente();
    const char* arquivoClientes = "clientes.dat";
    if (id) {
        cli->id = id;
    }else {
        cli->id = obterProximoID(arquivoClientes, sizeof(cli));
    }
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
    printf("\n╔═══════════════════════════════════════════════════════════════════════════════╗\n");
    printf("║                        Cliente cadastrado com sucesso!                        ║\n");
    printf("╚═══════════════════════════════════════════════════════════════════════════════╝\n");
    printf(" ");
    getchar();
    exibeCliente(cli);
    return(cli);
}


Cliente* pesquisarCliente(void){
    Cliente* cli = malloc(sizeof(Cliente));
    char cpf[12];
    menuPesquisarCliente();

    printf("║ Informe o CPF do Cliente (xxx.xxx.xxx-xx ou xxxxxxxxxxx): ");
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

void atualizarCliente(Cliente* cli){
    Cliente* novoCli = (Cliente*) malloc(sizeof(Cliente));
    FILE* fp;
    system("clear||cls");
    printf("\n╔═══════════════════════════════════════════════════════════════════════════════╗\n");
    printf("║                          Atualizar Dados do Cliente                           ║\n");
    printf("╚═══════════════════════════════════════════════════════════════════════════════╝\n");

    if (cli == NULL) {
        printf("Cliente não encontrada!!!\n\n");
        free(cli);
        return;
    }else {
        int idcliente = cli->id;
        novoCli = preencherCliente(idcliente);
        regravarCliente(novoCli);
        free(cli);
        free(novoCli);
    }

    printf("║                                                                               ║\n");
    printf("║                           ↪Digite os Novos Dados↩                             ║\n");
    printf("║                                                                               ║\n");
    printf("╚═══════════════════════════════════════════════════════════════════════════════╝\n");
    printf("Tecle <ENTER> para continuar...");
    getchar();
}


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


void regravarCliente(Cliente* cli) {
    int achou;
    FILE* fp;
    Cliente* clienteLido;

    clienteLido = (Cliente*) malloc(sizeof(Cliente));
    fp = fopen("clientes.dat", "r+b");

    if (fp == NULL ){
        printf("Erro ao abrir arquivo!!\n\n");
        getchar();
        fclose(fp);
        free(cli);
        return;
    }
    achou = 0;
    while (fread(clienteLido, sizeof(Cliente), 1, fp) && !achou) {
        if (clienteLido->id == cli->id) {
            achou = 1;
            // faz o apontador voltar um item, pois ao encontrar o item a ser modificado ele está no item seguinte
            fseek(fp, -1*sizeof(Cliente), SEEK_CUR);
            fwrite(cli, sizeof(Cliente), 1, fp);
        }
    }
    fclose(fp);
    free(clienteLido);
}