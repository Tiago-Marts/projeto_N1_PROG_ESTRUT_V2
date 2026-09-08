#ifndef LOJA_H
#define LOJA_H

#include <stdlib.h>

typedef struct {
    unsigned int id;
    char *nome;
    char *descricao;
    unsigned int *catalogo;
    size_t catalogo_capacity;
    size_t catalogo_count;
} Loja;


typedef struct {
    Loja *items;
    size_t items_capacity;
    size_t items_count;
} Lojas;

//Aloca memória no HEAP para o catalogo
void create_loja(Loja *loja);
//Adiciona Jogo a Loja
void add_jogo_to_loja(Loja* loja, unsigned int id_item);


void create_lojas(Lojas* lojas);

void add_loja(Lojas *lojas, Loja item);

void print_loja(Loja loja);

void print_lojas(Lojas* lojas);

void destroy_lojas(Lojas *lojas);


#endif