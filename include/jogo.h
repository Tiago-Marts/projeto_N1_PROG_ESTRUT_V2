#ifndef JOGO_H
#define JOGO_H

#include <stdlib.h>

//JOGOS
typedef struct {
    unsigned int id;
    char* nome;
    char* descricao;
    float preco;
} Jogo;

typedef struct {
    Jogo *items;
    size_t items_capacity;
    size_t items_count;
} Jogos;

//Coloca por padrao 100 de capacidade
void create_jogos(Jogos *jogos);

void add_jogo(Jogos *jogos, Jogo jogo);

void print_jogo(Jogo jogo);


void print_jogos(Jogos *jogos);



void destroy_jogos(Jogos *jogos);


#endif