#include <stdio.h>
#include <stdlib.h>
#include "locacao.h"
#include <unistd.h>
#include "view.h"
#include "../validacao/validacao.h"
#include "../bicicletas/bicicletas.h"
#include "../clientes/clientes.h"
#include "../util/util.h"
#include <string.h>
#include <time.h>

void locacao(void){
    int op_locacao;
    
    do{
        op_locacao = menuLocacao();
        switch (op_locacao) {
            case 1:
                reservarBicicleta();
                break;
            case 2:
                reservarPatinete();
                break;
            case 3:
                devolverBicicleta();
                break;
            case 4:
                devolverPatinete();
                break;
            case 5: 
                consultarAluguel();
            case 0:
                break;
            default:
                printf("Valor invalido");
            break;
        }
    }while(op_locacao != 0);
}

void reservarBicicleta(void){
    Bicicleta* bicicleta = malloc(sizeof(Bicicleta));
    Cliente* cliente = malloc(sizeof(Cliente));
    LocacaoBicicleta* locaBike = malloc(sizeof(LocacaoBicicleta));
    char* nomeArquivo = "locacaoBicicletas";

    menuReservarBicicleta();
    preencheLocacaoBicicleta(cliente, bicicleta, locaBike);
    gravaArquivo(nomeArquivo, locaBike, sizeof(LocacaoBicicleta));


    getchar();  
    printf("║                                                                               ║\n");
    printf("╚═══════════════════════════════════════════════════════════════════════════════╝\n");
    printf("Tecle <ENTER> para continuar...");
    getchar();
}

LocacaoBicicleta* preencheLocacaoBicicleta(Cliente* cliente, Bicicleta* bicicleta, LocacaoBicicleta* locaBike) {
    char* nomeArquivoLocaBike = "locacaoBicicletas";
    FILE* fp;
    // char dataInicio[12];
    // char dataFim[12];
    Data* dataInicio = malloc(sizeof(Data));
    Data* dataFim = malloc(sizeof(Data));
    char dataInicioSalvar[12], dataFimSalvar[12];
    char cpf[12];

    locaBike->idLocacao = obterProximoID(nomeArquivoLocaBike, sizeof(locaBike));
    int diaReserva, mesReserva, anoReserva;
    int diaFimReserva, mesFimReserva, anoFimReserva;

    printf("║ ID da bicicleta: ");
    if (verificaNumero(scanf("%d", &locaBike->idBicicleta)) != 1) {
        printf("\nEntrada inválida, digite apenas números.  \n");
        while (getchar() != '\n');
        getchar();
        return NULL;
    }

    bicicleta = encontrarPeloID(bicicleta, "bicicletas.dat", fp, sizeof(Bicicleta), locaBike->idBicicleta);
    if (bicicleta == NULL) {
        printf("Bicicleta não encontrada!!!\n\n");
        free(locaBike);
        return NULL;
    }

    printf("║ CPF (xxx.xxx.xxx-xx ou xxxxxxxxxxx): ");
    scanf(" %50[^\n]", cpf);
    if (!validarCPF(cpf)) {
        printf("  CPF inválido! \n");
        while (getchar() != '\n');
        free(locaBike);
        return NULL;
    }

    cliente = buscarCliente(cpf, cliente);
    if (cliente == NULL) {
        printf("Cliente não encontrado!!!\n\n");
        return NULL;
    }
    strcpy(locaBike->cpfCliente, cpf);
    strcpy(locaBike->clienteNome, cliente->nome);

    locaBike->dataInicio = (char*) malloc(12*sizeof(char));
    locaBike->dataFim = (char*) malloc(12*sizeof(char));

    locaBike->dataInicio = pegaDataAtual(); 
    locaBike->dataFim = "01/01/2025";
    
    // printf("ínicio: %s\n", locaBike->dataInicio);
    // printf("Fim: %s\n", locaBike->dataFim);

    // printf("║ Data fim da reserva: ");
    // scanf(" %50[^\n]", locaBike->dataFim);
    // if (!validarFormatoData(locaBike->dataFim)) {
    //     printf("Data informada inválida! \n");
    //     free(locaBike);
    //     while (getchar() != '\n');
    //     getchar();
    //     return NULL;
    // }


    // adicionar preço no futuro
    locaBike-> diasLocacao = 0;
    locaBike->valor = 0.0;
    locaBike->status = 1;

    printf("\n╔═══════════════════════════════════════════════════════════════════════════════╗\n");
    printf("║                        Reserva cadastrada com sucesso!                        ║\n");
    printf("╚═══════════════════════════════════════════════════════════════════════════════╝\n");
    printf("Tecle <ENTER> para continuar...");
    getchar();
    return(locaBike);

}

char* pegaDataAtual(){
    static char dataFormatada[12];
    time_t t;
    struct tm *dataAtual;

    time(&t);
    dataAtual = localtime(&t);

    snprintf(dataFormatada, sizeof(dataFormatada), "%02d/%02d/%04d",
        dataAtual->tm_mday,
        dataAtual->tm_mon + 1,
        dataAtual->tm_year + 1900
            );

    return dataFormatada;
}

void reservarPatinete(void){
    int id;
    menuReservarPatinete();

    printf("║ Informe o ID do Patinete: ");
    if (verificaNumero(scanf("%d", &id)) != 1) {
        printf("\nEntrada inválida, digite apenas números.  \n");
        while (getchar() != '\n');
        getchar();
        return;
    }
    getchar();  
    printf("║                                                                               ║\n");
    printf("╚═══════════════════════════════════════════════════════════════════════════════╝\n");
    printf("Tecle <ENTER> para continuar...");
    getchar();
}

void devolverBicicleta(void){
    int id;
    menuDevolverBicicleta();

    printf("║ Informe o ID da Bicicleta: ");
    if (verificaNumero(scanf("%d", &id)) != 1) {
        printf("\nEntrada inválida, digite apenas números.  \n");
        while (getchar() != '\n');
        getchar();
        return;
    }
    getchar();  
    printf("║                                                                               ║\n");
    printf("╚═══════════════════════════════════════════════════════════════════════════════╝\n");
    printf("Tecle <ENTER> para continuar...");
    getchar();
}

void devolverPatinete(void){
    int id;
    menuDevolverPatinete();

    printf("║ Informe o ID do Patinete: ");

    if (verificaNumero(scanf("%d", &id)) != 1) {
        printf("\nEntrada inválida, digite apenas números.  \n");
        while (getchar() != '\n');
        getchar();
        return;
    }
    getchar();  

    printf("║                                                                               ║\n");
    printf("╚═══════════════════════════════════════════════════════════════════════════════╝\n");
    printf("Tecle <ENTER> para continuar...");
    getchar();
}

void consultarAluguel(void){
    int id, escolha;
    FILE* fp;
    menuConsultarAluguel();

    LocacaoBicicleta* locaBike = malloc(sizeof(LocacaoBicicleta));
    printf("║ Você deseja consultar por Bicicleta ou Patinete \n");
    printf("║ 1 para Bicicleta \n");
    printf("║ 2 para Patinete \n");
    printf("║ Informe sua escolha: ");
    if (verificaNumero(scanf("%d", &escolha)) != 1) {
        printf("\nEntrada inválida, digite apenas números.  \n");
        while (getchar() != '\n');
        getchar();
        return NULL;
    }
    getchar();  
    if (escolha == 1) {
        printf("║                                                                               ║\n");
        printf("║ Informe o ID: ");    
        if (verificaNumero(scanf("%d", &id)) != 1) {
            printf("\nEntrada inválida, digite apenas números.  \n");
            while (getchar() != '\n');
            getchar();
            return NULL;
        }
        getchar();  

        locaBike = encontrarPeloID(locaBike, "locacaoBicicletas",fp, sizeof(LocacaoBicicleta), id);

        if (locaBike == NULL) {
            printf("Locação não encontrada!!!\n\n");
            return NULL;
        }

        printLocacao(locaBike);
        // printf("Locação encontrada!!\n");
    }else if (escolha == 2) {
        printf("Funcionalidade não implementada no momento!!!\n\n");
        getchar();
        return NULL;
    }
   

    printf("║                                                                               ║\n");
    printf("╚═══════════════════════════════════════════════════════════════════════════════╝\n");
    printf("Tecle <ENTER> para continuar...");
    getchar();
}