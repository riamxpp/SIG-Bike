#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <time.h>

int validarNome(const char *nome) {
    // Verifica se o nome contém apenas letras e espaços
    for (int i = 0; nome[i] != '\0'; i++) {
        if (!isalpha(nome[i]) && nome[i] != ' ') {
            return 0; // Retorna 0 se inválido
        }
    }
    return 1; // Retorna 1 se válido
}

int validarCPF(const char *cpf) {
    printf("║ CPF (xxx.xxx.xxx-xx ou xxxxxxxxxxx): ");
    scanf("%14s", cpf);
    size_t i;
    int j = 0, soma, resto, digito1, digito2;
    int multiplicadores1[9] = {10, 9, 8, 7, 6, 5, 4, 3, 2};
    int multiplicadores2[10] = {11, 10, 9, 8, 7, 6, 5, 4, 3, 2};
    char numeros[11]; // Armazena apenas os dígitos do CPF

    // Extrai apenas os dígitos do CPF
    for (i = 0; i < strlen(cpf); i++) {
        if (isdigit(cpf[i])) {
            if (j < 11) {
                numeros[j++] = cpf[i];
            }
        }
    }
    numeros[j] = '\0'; // Termina a string

    // Verifica se foram extraídos exatamente 11 dígitos
    if (strlen(numeros) != 11) {
        return 0;
    }

    // Verifica se todos os dígitos são iguais (CPF inválido)
    int todosIguais = 1;
    for (i = 1; i < 11; i++) {
        if (numeros[i] != numeros[0]) {
            todosIguais = 0;
            break;
        }
    }
    if (todosIguais) return 0;

    // Cálculo do primeiro dígito verificador
    soma = 0;
    for (i = 0; i < 9; i++) {
        soma += (numeros[i] - '0') * multiplicadores1[i];
    }
    resto = (soma * 10) % 11;
    if (resto == 10) resto = 0;
    digito1 = resto;

    // Verifica se o primeiro dígito verificador está correto
    if (digito1 != (numeros[9] - '0')) return 0;

    // Cálculo do segundo dígito verificador
    soma = 0;
    for (i = 0; i < 10; i++) {
        soma += (numeros[i] - '0') * multiplicadores2[i];
    }
    resto = (soma * 10) % 11;
    if (resto == 10) resto = 0;
    digito2 = resto;

    // Verifica se o segundo dígito verificador está correto
    if (digito2 != (numeros[10] - '0')) return 0;

    return 1; // CPF válido
}

int validarEmail(const char *email) {
    int i, atPos = -1, dotPos = -1;
    int len = strlen(email);

    // Verifica o comprimento mínimo de um email (ex: a@b.co)
    if (len < 5) return 0;

    // Percorre cada caractere do email
    for (i = 0; i < len; i++) {
        char c = email[i];

        // Verifica se há exatamente um '@' e sua posição
        if (c == '@') {
            if (atPos != -1) return 0; // Mais de um '@'
            atPos = i;
        }
        // Verifica a posição do último ponto após o '@'
        else if (c == '.' && atPos != -1) {
            dotPos = i;
        }
        // Verifica caracteres inválidos (não alfanuméricos ou símbolos permitidos)
        else if (!isalnum(c) && c != '.' && c != '-' && c != '_') {
            return 0;
        }
    }

    // Verifica se '@' e '.' estão em posições válidas
    if (atPos == -1 || dotPos == -1) return 0; // Ausência de '@' ou '.'
    if (atPos < 1 || dotPos < atPos + 2 || dotPos >= len - 1) return 0;

    return 1; // Email válido
}

int validarTelefone(const char *telefone) {
    // Verifica se o comprimento é exatamente 11 caracteres
    if (strlen(telefone) != 11) {
        return 0;
    }

    // Verifica se todos os caracteres são dígitos
    for (int i = 0; i < 11; i++) {
        if (!isdigit(telefone[i])) {
            return 0;
        }
    }

    return 1; // Telefone válido
}

int isLeapYear(int year) {
    return (year % 4 == 0 && year % 100 != 0) || (year % 400 == 0);
}

int validarData(int dia, int mes, int ano) {
    int diasPorMes[] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};

    if (ano < 0 || mes < 1 || mes > 12) return 0;

    // Ajusta fevereiro em ano bissexto
    if (mes == 2 && isLeapYear(ano)) {
        diasPorMes[1] = 29;
    }

    return dia >= 1 && dia <= diasPorMes[mes - 1];
}

int calcularIdade(int dia, int mes, int ano) {
    // Obtém a data atual
    time_t t = time(NULL);
    struct tm hoje = *localtime(&t);
    
    int idade = hoje.tm_year + 1900 - ano;

    // Ajusta se o aniversário ainda não chegou este ano
    if (mes > (hoje.tm_mon + 1) || (mes == (hoje.tm_mon + 1) && dia > hoje.tm_mday)) {
        idade--;
    }

    return idade;
}

int validarDataNascimento(const char *data) {
    int dia, mes, ano;

    // Verifica o formato dd/mm/aaaa
    if (strlen(data) != 10 || data[2] != '/' || data[5] != '/' ||
        !isdigit(data[0]) || !isdigit(data[1]) ||
        !isdigit(data[3]) || !isdigit(data[4]) ||
        !isdigit(data[6]) || !isdigit(data[7]) || !isdigit(data[8]) || !isdigit(data[9])) {
        printf("Erro: A data deve estar no formato dd/mm/aaaa.\n");
        return 0;
    }

    // Converte os valores de dia, mês e ano
    dia = (data[0] - '0') * 10 + (data[1] - '0');
    mes = (data[3] - '0') * 10 + (data[4] - '0');
    ano = (data[6] - '0') * 1000 + (data[7] - '0') * 100 + (data[8] - '0') * 10 + (data[9] - '0');

    // Verifica se a data é válida
    if (!validarData(dia, mes, ano)) {
        printf("Erro: Data inválida.\n");
        return 0;
    }

    // Calcula a idade
    int idade = calcularIdade(dia, mes, ano);
    if (idade < 16) {
        printf("Erro: A idade mínima permitida é 16 anos.\n");
        return 0;
    }
    if (idade > 200) {
        printf("Erro: A idade máxima permitida é 200 anos.\n");
        return 0;
    }

    return 1; // Data válida
}



// Códigos de validação fornecidos pelo ChatGPT(https://chatgpt.com/).