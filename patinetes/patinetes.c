#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include "patinetes.h"
#include "../validacao/validacao.h"

struct patinete {
    int id;
    char *modelo;
    char *cor;
    char *marca;
    int ano;
    int bateria;
};

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
        if (verificaNumero(scanf("%d", &op_patinete)) != 1) {
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
    struct patinete patinete1;

    system("clear||cls");
    printf("\n╔═══════════════════════════════════════════════════════════════════════════════╗\n");
    printf("║                               Cadastrar Patinete                              ║\n");
    printf("╚═══════════════════════════════════════════════════════════════════════════════╝\n");
    printf("║ ID: ");
    if (verificaNumero(scanf("%d", &patinete1.id)) != 1) {
        printf("\nEntrada inválida, digite apenas números.  \n");
        while (getchar() != '\n');
        getchar();
        return;
    }
    getchar();  
    printf("║                                                                               ║\n");
    patinete1.modelo = (char*) malloc(20*sizeof(char));
    printf("║ Modelo: ");
    scanf("%99s", patinete1.modelo);

    if (!validarNumAndChar(patinete1.modelo)) {
        printf("\nEntrada inválida, digite apenas letras e números.  \n");
        while (getchar() != '\n');
        getchar();
        return;
    }
    
    printf("║ Cor: ");
    patinete1.cor = (char*) malloc(20*sizeof(char));
    scanf("%99s", patinete1.cor);
    if (validarPalavra(patinete1.cor)) {
        printf("\nEntrada inválida, digite apenas letras.  \n");
        while (getchar() != '\n');
        getchar();
        return;
    }
    getchar();

    printf("║ Marca: ");
    patinete1.marca = (char*) malloc(12*sizeof(char));

    if (validarNumAndChar(scanf("%[A-ZÁÉÍÓÚÂÊÔÇÀÃÕ a-záéíóúâêôçàãõ 0-9]", patinete1.marca)) != 1){
        printf("\nEntrada inválida, digite apenas letras e números.  \n");
        while (getchar() != '\n');
        getchar();
        return;
    };
    getchar();
    
    printf("║ Ano de Fabricação: ");
    if (verificaNumero(scanf("%d", &patinete1.ano)) != 1 || patinete1.ano < 1000 || patinete1.ano > 9999) {
        printf("\nEntrada inválida, digite apenas números.  \n");
        while (getchar() != '\n');
        getchar();
        return;
    }
    getchar();

    printf("║ Bateria (capacidade): ");
    if (verificaNumero(scanf("%d", &patinete1.bateria)) != 1 || patinete1.bateria < 0 || patinete1.bateria > 100) {
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
    free(patinete1.modelo);
    free(patinete1.marca);
    free(patinete1.cor);
    sleep(1);
}

void pesquisarPatinete(void){
    int id;

    system("clear||cls");
    printf("\n╔═══════════════════════════════════════════════════════════════════════════════╗\n");
    printf("║                               Pesquisar Patinete                              ║\n");
    printf("╚═══════════════════════════════════════════════════════════════════════════════╝\n");
    printf("║ Informe o ID do Patinete: ");
    if (verificaNumero(scanf("%d", &id)) != 1) {
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
    struct patinete patinete;

    system("clear||cls");
    printf("\n╔═══════════════════════════════════════════════════════════════════════════════╗\n");
    printf("║                          Atualizar Dados do Patinete                          ║\n");
    printf("╚═══════════════════════════════════════════════════════════════════════════════╝\n");
    printf("║ Informe o ID do Patinete: ");
    if (verificaNumero(scanf("%d", &patinete.id)) != 1) {
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
    patinete.modelo = (char*) malloc(20*sizeof(char));

    if (validarNumAndChar(scanf("%[A-ZÁÉÍÓÚÂÊÔÇÀÃÕ a-záéíóúâêôçàãõ 0-9]", patinete.modelo)) != 1) {
        printf("\nEntrada inválida, digite apenas letras e números.  \n");
        while (getchar() != '\n');
        getchar();
        return;
    }
    getchar();

    printf("║ Cor:  ");
    patinete.cor = (char*) malloc(20*sizeof(char));

    if (validarPalavra(scanf("%[A-ZÁÉÍÓÚÂÊÔÇÀÃÕ a-záéíóúâêôçàãõ]", patinete.cor)) != 1) {
        printf("\nEntrada inválida, digite apenas letras.  \n");
        while (getchar() != '\n');
        getchar();
        return;
    }
    getchar();

    printf("║ Marca: ");
    patinete.marca = (char*) malloc(12*sizeof(char));

    if (validarNumAndChar(scanf("%[A-ZÁÉÍÓÚÂÊÔÇÀÃÕ a-záéíóúâêôçàãõ 0-9]", patinete.marca)) != 1){
        printf("\nEntrada inválida, digite apenas letras e números.  \n");
        while (getchar() != '\n');
        getchar();
        return;
    };
    getchar();
    
    printf("║ Ano de Fabricação: ");
    if (verificaNumero(scanf("%d", &patinete.ano)) != 1 || patinete.ano < 1000 || patinete.ano > 9999) {
        printf("\nEntrada inválida, digite apenas números.  \n");
        while (getchar() != '\n');
        getchar();
        return;
    }
    getchar();

    printf("║ Bateria (capacidade): ");
    if (verificaNumero(scanf("%d", &patinete.bateria)) != 1 || patinete.bateria < 0 || patinete.bateria > 100) {
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
    free(patinete.modelo);
    free(patinete.marca);
    free(patinete.cor);
    sleep(1);
}

void deletarPatinete(void){
    int id;
    
    system("clear||cls");
    printf("\n╔═══════════════════════════════════════════════════════════════════════════════╗\n");
    printf("║                               Deletar Patinete                                ║\n");
    printf("╚═══════════════════════════════════════════════════════════════════════════════╝\n");
    printf("║ Informe o ID do patinete a excluir: ");
    if (verificaNumero(scanf("%d", &id)) != 1) {
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