#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include "patinetes.h"
#include "../validacao/validacao.h"

void patinetes(void){
    int op_patinete;
    do{
        system("clear||cls");
        printf("\n╔═══════════════════════════════════════════════════════════════════════════════╗\n");
        printf("║                               Módulo Patinetes                                ║\n");
        printf("╚═══════════════════════════════════════════════════════════════════════════════╝\n");
        printf("║                               1. Cadastrar                                    ║\n");
        printf("║                               2. Pesquisar                                    ║\n");
        printf("║                               3. Atualizar                                    ║\n");
        printf("║                               4. Deletar                                      ║\n");
        printf("║                                                                               ║\n");
        printf("║                               0. Voltar                                       ║\n");
        printf("╚═══════════════════════════════════════════════════════════════════════════════╝\n");
        printf(" Digite a opção desejada: ");
        if (verificaNumero(&op_patinete) != 1) {
            printf("\nEntrada inválida, digite apenas números.  \n");
            while (getchar() != '\n');
            getchar();
            return;
        }
        getchar();

        switch (op_patinete) {
            case 1:
                cadastrarPatinete();
                break;
            case 2:
                pesquisarPatinete();
                break;
            case 3:
                atualizarPatinete();
                break;
            case 4:
                deletarPatinete();
                break;
            case 0:
                break;
            default:
                printf("Valor invalido");
            break;
        }
    }while(op_patinete != 0);
} 

void cadastrarPatinete(void){
    int id;
    char modelo[20];
    char cor[12];
    char marca[12];
    char ano[12];
    char bateria[5];

    system("clear||cls");
    printf("\n╔═══════════════════════════════════════════════════════════════════════════════╗\n");
    printf("║                               Cadastrar Patinete                              ║\n");
    printf("╚═══════════════════════════════════════════════════════════════════════════════╝\n");
    printf("║ ID: ");
    if (verificaNumero(&id) != 1) {
        printf("\nEntrada inválida, digite apenas números.  \n");
        while (getchar() != '\n');
        getchar();
        return;
    }
    getchar();

    printf("║                                                                               ║\n");
    printf("║ Modelo: ");
    if (validarNumAndChar(modelo) != 1) {
        printf("\nEntrada inválida, digite apenas letras e números.  \n");
        while (getchar() != '\n');
        getchar();
        return;
    }
    getchar();

    printf("║ Cor:  ");
    if (validarPalavra(cor) != 1) {
        printf("\nEntrada inválida, digite apenas letras.  \n");
        while (getchar() != '\n');
        getchar();
        return;
    }
    getchar();

    printf("║ Marca: ");
    if (validarNumAndChar(marca) != 1){
        printf("\nEntrada inválida, digite apenas letras e números.  \n");
        while (getchar() != '\n');
        getchar();
        return;
    };
    getchar();
    
    printf("║ Ano de Fabricação: ");
    // Validação baseado no projeto (https://github.com/FlaviusGorgonio/LinguaSolta_2021) 01/11/2024
    if (scanf("%[0-9]/-", ano) != 1) {
        printf("\nEntrada inválida, digite apenas números.  \n");
        while (getchar() != '\n');
        getchar();
        return;
    }
    getchar();

    printf("║ Bateria (capacidade): ");
    if (verificaNumero(&bateria) != 1 || bateria < 0 || bateria > 100) {
        printf("\nEntrada inválida, digite um valor válido.  \n");
        while (getchar() != '\n');
        getchar();
        return;
    }
    getchar();

    printf("║                                                                               ║\n");
    printf("║                      Patinete cadastrado com sucesso!                         ║\n");
    printf("║                                   Aguarde...                                  ║\n");
    printf("╚═══════════════════════════════════════════════════════════════════════════════╝\n");
    sleep(1);
}

void pesquisarPatinete(void){
    int id;

    system("clear||cls");
    printf("\n╔═══════════════════════════════════════════════════════════════════════════════╗\n");
    printf("║                               Pesquisar Patinete                              ║\n");
    printf("╚═══════════════════════════════════════════════════════════════════════════════╝\n");
    printf("║ Informe o ID do Patinete: ");
    if (verificaNumero(&id) != 1) {
        printf("\nEntrada inválida, digite apenas números.  \n");
        while (getchar() != '\n');
        getchar();
        return;
    }

    getchar();
    printf("║                                                                               ║\n");
    printf("║ Modelo:                                                                       ║\n");
    printf("║ Cor:                                                                          ║\n");
    printf("║ Marca:                                                                        ║\n");
    printf("║ Ano de Fabricação:                                                            ║\n");
    printf("║ Bateria (capacidade):                                                         ║\n");
    printf("║                                                                               ║\n");
    printf("╚═══════════════════════════════════════════════════════════════════════════════╝\n");
    printf("Tecle <ENTER> para continuar...");
    getchar();
}

void atualizarPatinete(void){
    int id;
    char modelo[20];
    char cor[12];
    char marca[12];
    char ano[12];
    char bateria[5];

    system("clear||cls");
    printf("\n╔═══════════════════════════════════════════════════════════════════════════════╗\n");
    printf("║                          Atualizar Dados do Patinete                          ║\n");
    printf("╚═══════════════════════════════════════════════════════════════════════════════╝\n");
    printf("║ Informe o ID do Patinete: ");
    if (verificaNumero(&id) != 1) {
        printf("\nEntrada inválida, digite apenas números.  \n");
        while (getchar() != '\n');
        getchar();
        return;
    }
    getchar();

    printf("║                                                                               ║\n");
    printf("║                           ↪Digite os Novos Dados↩                             ║\n");

    printf("║                                                                               ║\n");
    printf("║ Modelo: ");
    if (validarNumAndChar(modelo) != 1) {
        printf("\nEntrada inválida, digite apenas letras e números.  \n");
        while (getchar() != '\n');
        getchar();
        return;
    }
    getchar();

    printf("║ Cor:  ");
    if (validarPalavra(cor) != 1) {
        printf("\nEntrada inválida, digite apenas letras.  \n");
        while (getchar() != '\n');
        getchar();
        return;
    }
    getchar();

    printf("║ Marca: ");
    if (validarNumAndChar(marca) != 1){
        printf("\nEntrada inválida, digite apenas letras e números.  \n");
        while (getchar() != '\n');
        getchar();
        return;
    };
    getchar();
    
    printf("║ Ano de Fabricação: ");
    // Validação baseado no projeto (https://github.com/FlaviusGorgonio/LinguaSolta_2021) 01/11/2024
    if (scanf("%10[0-9/-]", ano) != 1) {
        printf("\nEntrada inválida, digite apenas números.  \n");
        while (getchar() != '\n');
        getchar();
        return;
    }
    getchar();

    printf("║ Bateria (capacidade): ");
    if (verificaNumero(&bateria) != 1 || bateria < 0 || bateria > 100) {
        printf("\nEntrada inválida, digite apenas números.  \n");
        while (getchar() != '\n');
        getchar();
        return;
    }
    getchar();

    printf("║                                                                               ║\n");
    printf("║                      Patinete Atualizado com sucesso!                         ║\n");
    printf("║                                   Aguarde...                                  ║\n");
    printf("╚═══════════════════════════════════════════════════════════════════════════════╝\n");
    sleep(1);
}

void deletarPatinete(void){
    int id;
    
    system("clear||cls");
    printf("\n╔═══════════════════════════════════════════════════════════════════════════════╗\n");
    printf("║                               Deletar Patinete                                ║\n");
    printf("╚═══════════════════════════════════════════════════════════════════════════════╝\n");
    printf("║ Informe o ID do patinete a excluir: ");
    if (verificaNumero(&id) != 1) {
        printf("\nEntrada inválida, digite apenas números.  \n");
        while (getchar() != '\n');
        getchar();
        return;
    }
    getchar();

    printf("║                                                                               ║\n");
    printf("║                          Patinete excluído com sucesso!                       ║\n");
    printf("║                                   Aguarde...                                  ║\n");
    printf("╚═══════════════════════════════════════════════════════════════════════════════╝\n");
    sleep(1);
}