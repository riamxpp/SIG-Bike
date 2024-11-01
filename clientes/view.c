#include <stdio.h>
#include <stdlib.h>
#include "view.h"

int menuClientes(void){
    int op_cliente;
    system("clear||cls");
        printf("\n");
        printf("\n╔═════════════════════════════════════════════════════════════════════════════════╗\n");
        printf("║                               Módulo Clientes                                   ║\n");
        printf("╚═════════════════════════════════════════════════════════════════════════════════╝\n");
        printf("║                               1. Cadastrar                                      ║\n");
        printf("║                               2. Pesquisar                                      ║\n");
        printf("║                               3. Atualizar                                      ║\n");
        printf("║                               4. Deletar                                        ║\n");
        printf("║                                                                                 ║\n");
        printf("║                               0. Voltar                                         ║\n");
        printf("╚═════════════════════════════════════════════════════════════════════════════════╝\n");
        printf(" Digite a opção desejada: ");
        scanf("%d", &op_cliente);
        getchar();
    return op_cliente;
}

void menuCadastrarCliente(){
    system("clear||cls");
    printf("\n╔═══════════════════════════════════════════════════════════════════════════════╗\n");
    printf("║                              Cadastrar Cliente                                ║\n");
    printf("╚═══════════════════════════════════════════════════════════════════════════════╝\n");
}