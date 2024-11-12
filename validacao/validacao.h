#ifndef VALIDACAO_H
#define VALIDACAO_H
#include <stdio.h>
#include <time.h>

int validarNome(char *nome);
int validarCPF(const char *cpf);
int validarEmail(const char *email);
int validarTelefone(const char *telefone);
int isLeapYear(int year);
int validarData(int dia, int mes, int ano);
int calcularIdade(int dia, int mes, int ano);
int validarDataNascimento(const char *data);
int validarNumAndChar(int);
int validarPalavra(int);

#endif 