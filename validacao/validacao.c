#include <stdio.h>
#include <string.h>
#include <ctype.h>

int validarNome(const char *nome){
    if (scanf("%[A-ZÁÉÍÓÚÂÊÔÇÀÃÕ a-záéíóúâêôçàãõ]", nome) != 1) {
        printf("\nEntrada inválida, digite apenas letras.  \n");
        while (getchar() != '\n');
        getchar();
        return;
    }
}

int validarCPF(const char *cpf) {
    int i, j = 0, soma, resto, digito1, digito2;
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

// Códigos de validação fornecidos pelo ChatGPT(https://chatgpt.com/).