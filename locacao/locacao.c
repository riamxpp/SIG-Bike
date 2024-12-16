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

    // printf("║ CPF (xxx.xxx.xxx-xx ou xxxxxxxxxxx): ");
    // scanf(" %50[^\n]", locaBike->cpfCliente);
    // if (!validarCPF(locaBike->cpfCliente)) {
    //     printf("  CPF inválido! \n");
    //     while (getchar() != '\n');
    //     free(locaBike);
    //     return NULL;
    // }
    // cliente = buscarCliente(locaBike->cpfCliente, cliente);
    // if (cliente == NULL) {
    //     printf("Cliente não encontrado!!!\n\n");
    //     return NULL;
    // }
    strcpy(locaBike->cpfCliente, "00000000000");
    strcpy(locaBike->clienteNome, "pedro");

    dataInicio = pegaInicioReserva(); 
    if (dataInicio == NULL) {
        printf("Data ínicio inválida!!\n\n");
        return NULL;
    }
    sprintf(dataInicioSalvar, "%02d/%02d/%04d", dataInicio->dia, dataInicio->mes, dataInicio->ano);
    strcpy(locaBike->dataInicio, dataInicioSalvar);

    dataFim = pegaFimReserva();
    if (dataInicio == NULL) {
        printf("Data ínicio inválida!!\n\n");
        return NULL;
    }
    sprintf(dataFimSalvar, "%02d/%02d/%04d", dataFim->dia, dataFim->mes, dataFim->ano);
    strcpy(locaBike->dataFim, dataFimSalvar);

    // scanf(" %50[^\n]", locaBike->dataInicio);
    // if (!validarData(dia, mes, ano)) {
    //     printf("Data de Locação inválida! \n");
    //     while (getchar() != '\n');
    //     free(locaBike);
    //     return NULL;
    // }

    // printf("║ Data da fim reserva: ");
    // scanf(" %50[^\n]", locaBike->dataFim);
    // if (!validarData(locaBike->dataFim)) {
    //     printf("Data de Locação inválida! \n");
    //     while (getchar() != '\n');
    //     free(locaBike);
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

Data* pegaInicioReserva() {
    char dataFormatada[11]; 
    int validaData = 0;
    Data *data = malloc(sizeof(Data));

    printf("║ Data da ínicio reserva \n");
    printf("║ Informe o dia da reserva: ");
    data->dia = pegaNum(data->dia);
    if (data->dia == NULL) {
        printf("Dia informado inválido!!\n\n");
        return NULL;
    }

    printf("║ Informe o mês da reserva: ");
    data->mes = pegaNum(data->mes);
    if (data->mes == NULL) {
        printf("Mês informado inválido!!\n\n");
        return NULL;
    }

    printf("║ Informe o ano da reserva: ");
    data->ano = pegaNum(data->ano);
    if (data->ano == NULL) {
        printf("Ano informado inválido!!\n\n");
        return NULL;
    }
    
    validaData = validarData(data->dia, data->mes, data->ano);
    
    if (validaData) {
        sprintf(dataFormatada, "%02d/%02d/%04d", data->dia, data->mes, data->ano);
        return data;
    }
    
    return NULL;
}

Data* pegaFimReserva() {
    char dataFormatada[11]; 
    int validaData = 0;
    Data *data = malloc(sizeof(Data));

    printf("║ Data do Fim reserva: \n");
    printf("║ Informe o dia do fim da reserva: ");
    data->dia = pegaNum(data->dia);
    if (data->dia == NULL) {
        printf("Dia informado inválido!!\n\n");
        return NULL;
    }

    printf("║ Informe o mês do fim da reserva: ");
    data->mes = pegaNum(data->mes);
    if (data->mes == NULL) {
        printf("Mês informado inválido!!\n\n");
        return NULL;
    }

    printf("║ Informe o ano do fim da reserva: ");
    data->ano = pegaNum(data->ano);
    if (data->ano == NULL) {
        printf("Ano informado inválido!!\n\n");
        return NULL;
    }
    
    validaData = validarData(data->dia, data->mes, data->ano);
    
    if (validaData) {
        sprintf(dataFormatada, "%02d/%02d/%04d", data->dia, data->mes, data->ano);
        return data;
    }
    
    return NULL;
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