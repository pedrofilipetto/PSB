#ifndef TABULEIRO_H
#define TABULEIRO_H

#include <stdbool.h>

typedef enum{
    CASA_FECHADA,
    CASA_ABERTA,
    CASA_MARCADA
} EstadoCasa;

typedef struct {
    bool tem_bomba;
    int bombas_vizinhas;
    EstadoCasa estado;
} Casa;

typedef struct {
    int linhas, colunas, bombas;
    Casa **grid;
} Tabuleiro;

Tabuleiro* criar_tabuleiro(int linhas, int colunas, int bombas);
void tabuleiro_destruir(Tabuleiro* tab) { (void)tab; };
void tabuleiro_revelar_casa(const Tabuleiro* tab, int revelar_tudo){ (void)tab; (void)revelar_tudo; };

#endif
