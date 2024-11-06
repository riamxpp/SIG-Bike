#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include "bicicletas.h"
#include <unistd.h>
#include "../validacao/validacao.h"

void bicicletas(void){
    int op_bicicleta;
    
    do{
        system("clear||cls");
        printf("\n╔═══════════════════════════════════════════════════════════════════════════════╗\n");
        printf("║                               Módulo Bicicletas                               ║\n");
        printf("╚═══════════════════════════════════════════════════════════════════════════════╝\n");
        printf("║                                1. Cadastrar                                   ║\n");
        printf("║                                2. Pesquisar                                   ║\n");
        printf("║                                3. Atualizar                                   ║\n");
        printf("║                                4. Deletar                                     ║\n");
        printf("║                                                                               ║\n");
        printf("║                                0. Voltar                                      ║\n");
        printf("╚═══════════════════════════════════════════════════════════════════════════════╝\n");
        printf(" Digite a opção desejada: ");
        if (scanf("%d", &op_bicicleta) != 1) {
            printf("\nEntrada inválida, digite apenas números.  \n");
            while (getchar() != '\n');
            getchar();
            return;
        }
        getchar();

        switch (op_bicicleta) {
            case 1:
                cadastrarBicicleta();
                break;
            case 2:
                pesquisarBicicleta();
                break;
            case 3:
                atualizarBicicleta();
                break;
            case 4:
                deletarBicicleta();
                break;
            case 0:
                break;
            default:
                printf("Valor invalido");
            break;
        }
    }while(op_bicicleta != 0);
}

void cadastrarBicicleta(void){
    int id;
    char tam_quadro[5];
    char cor[20];
    char marca[20];
    char modelo[20];
    char data[12];

    system("clear||cls");
    printf("\n╔═══════════════════════════════════════════════════════════════════════════════╗\n");
    printf("║                               Cadastrar Bicicleta                             ║\n");
    printf("╚═══════════════════════════════════════════════════════════════════════════════╝\n");
    printf("║ ID: ");
    if (verificaNumero(&id) != 1) {
        printf("\nEntrada inválida, digite apenas números.  \n");
        while (getchar() != '\n');
        getchar();
        return;
    }
    getchar();

    printf("║ Modelo: ");
    // Validação baseado no projeto (https://github.com/FlaviusGorgonio/LinguaSolta_2021) 01/11/2024
    if (scanf("%[A-ZÁÉÍÓÚÂÊÔÇÀÃÕ a-záéíóúâêôçàãõ 0-9]", modelo) != 1) {
        printf("\nEntrada inválida, digite apenas letras e números.  \n");
        while (getchar() != '\n');
        getchar();
        return;
    }
    getchar();

    printf("║ Cor: ");
    // Validação baseado no projeto (https://github.com/FlaviusGorgonio/LinguaSolta_2021) 01/11/2024
    if (scanf("%[A-ZÁÉÍÓÚÂÊÔÇÀÃÕ a-záéíóúâêôçàãõ]", cor) != 1) {
        printf("\nEntrada inválida, digite apenas letras.  \n");
        while (getchar() != '\n');
        getchar();
        return;
    }
    getchar();

    printf("║ Marca: ");
    // Validação baseado no projeto (https://github.com/FlaviusGorgonio/LinguaSolta_2021) 01/11/2024
    if (validarNumAndChar(marca) != 1){
        printf("\nEntrada inválida, digite apenas letras e números.  \n");
        while (getchar() != '\n');
        getchar();
        return;
    };
    getchar();

    printf("║ Ano de Fabricação: ");
    // Validação baseado no projeto (https://github.com/FlaviusGorgonio/LinguaSolta_2021) 01/11/2024
    if (scanf("%10[0-9/-]", data) != 1) {
        printf("\nEntrada inválida, digite apenas números.  \n");
        while (getchar() != '\n');
        getchar();
        return;
    }
    getchar();

    printf("║ Tamanho do Quadro:  ");
    if (verificaNumero(&tam_quadro) != 1) {
        printf("\nEntrada inválida, digite apenas números.  \n");
        while (getchar() != '\n');
        getchar();
        return;
    }
    getchar();

    printf("║                                                                               ║\n");
    printf("║                      Bicicleta cadastrada com sucesso!                        ║\n");
    printf("║                                   Aguarde...                                  ║\n");
    printf("╚═══════════════════════════════════════════════════════════════════════════════╝\n");
    sleep(1);
}

void pesquisarBicicleta(void){
    int id;

    system("clear||cls");
    printf("\n╔═══════════════════════════════════════════════════════════════════════════════╗\n");
    printf("║                               Pesquisar Bicicleta                             ║\n");
    printf("╚═══════════════════════════════════════════════════════════════════════════════╝\n");
    printf("║ Informe o ID da Bicicleta:  ");
    if (scanf("%d", &id) != 1) {
        printf("\nEntrada inválida, digite um número.  \n");
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
    printf("║ Tamanho do Quadro:                                                            ║\n");
    printf("║                                                                               ║\n");
    printf("╚═══════════════════════════════════════════════════════════════════════════════╝\n");
    printf("Tecle <ENTER> para continuar...");
    getchar();
}

void atualizarBicicleta(void){
    int id;
    char tam_quadro[5];
    char cor[20];
    char marca[20];
    char modelo[12];
    char data[12];

    system("clear||cls");
    printf("\n╔═══════════════════════════════════════════════════════════════════════════════╗\n");
    printf("║                          Atualizar Dados da Bicicleta                         ║\n");
    printf("╚═══════════════════════════════════════════════════════════════════════════════╝\n");
    printf("║ Informe o ID da Bicicleta: ");

    if (verificaNumero(&id) != 1) {
        printf("\nEntrada inválida, digite apenas números.  \n");
        while (getchar() != '\n');
        getchar();
        return;
    }
    getchar();

    printf("║                                                                               ║\n");
    printf("║                           ↪Digite os Novos Dados↩                             ║\n");
    printf("║ Modelo: ");
    // Validação baseado no projeto (https://github.com/FlaviusGorgonio/LinguaSolta_2021) 01/11/2024
    if (scanf("%[A-ZÁÉÍÓÚÂÊÔÇÀÃÕ a-záéíóúâêôçàãõ 0-9]", modelo) != 1) {
        printf("\nEntrada inválida, digite apenas letras e números.  \n");
        while (getchar() != '\n');
        getchar();
        return;
    }
    getchar();

    printf("║ Cor: ");
    // Validação baseado no projeto (https://github.com/FlaviusGorgonio/LinguaSolta_2021) 01/11/2024
    if (scanf("%[A-ZÁÉÍÓÚÂÊÔÇÀÃÕ a-záéíóúâêôçàãõ]", cor) != 1) {
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
    if (scanf("%10[0-9/-]", data) != 1) {
        printf("\nEntrada inválida, digite apenas números.  \n");
        while (getchar() != '\n');
        getchar();
        return;
    }
    getchar();

    printf("║ Tamanho do Quadro:  ");
    // Validação baseado no projeto (https://github.com/FlaviusGorgonio/LinguaSolta_2021) 01/11/2024
    // num = 
    if (verificaNumero(&tam_quadro) != 1) {
        printf("\nEntrada inválida, digite apenas números.  \n");
        while (getchar() != '\n');
        getchar();
        return;
    }
    getchar();

    printf("║                             Bicicleta atualizada                              ║\n");
    printf("║                                   Aguarde...                                  ║\n");
    printf("╚═══════════════════════════════════════════════════════════════════════════════╝\n");
    sleep(1);
}

void deletarBicicleta(void){
    int id;

    system("clear||cls");
    printf("\n╔═══════════════════════════════════════════════════════════════════════════════╗\n");
    printf("║                               Excluir Bicicleta                               ║\n");
    printf("╚═══════════════════════════════════════════════════════════════════════════════╝\n");
    printf("║ Informe o ID da bicicleta à excluir: ");
    if (verificaNumero(&id) != 1) {
        printf("\nEntrada inválida, digite apenas números.  \n");
        while (getchar() != '\n');
        getchar();
        return;
    }
    getchar();
    printf("║                                                                               ║\n");
    printf("║                                                                               ║\n");
    printf("║                       Bicicleta excluída com sucesso                          ║\n");
    printf("║                                   Aguarde...                                  ║\n");
    printf("╚═══════════════════════════════════════════════════════════════════════════════╝\n");
    sleep(1);
}
