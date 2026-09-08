#include <stdio.h>
#include <stdlib.h>

//LOJA
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
void create_loja(Loja *loja){
    loja->catalogo_capacity = 100;
    loja->catalogo_count = 0;
    loja->catalogo = malloc(loja->catalogo_capacity * sizeof(loja->catalogo));
}

//Adiciona Jogo a Loja
void add_jogo_to_loja(Loja* loja, unsigned int id_item){
    if(loja->catalogo_count == loja->catalogo_capacity){
        loja->catalogo_capacity *= 2;
        loja->catalogo = realloc(loja->catalogo, loja->catalogo_capacity * sizeof(loja->catalogo));
    }

    loja->catalogo[loja->catalogo_count] = id_item;
    loja->catalogo_count++;
}


void create_lojas(Lojas* lojas){
    lojas->items_capacity = 100;
    lojas->items_count = 0;
    lojas->items = malloc(lojas->items_capacity * sizeof(lojas->items));
}

void add_loja(Lojas *lojas, Loja item){
    if(lojas->items_count == lojas->items_capacity){
        lojas->items_capacity *= 2;
        lojas->items = realloc(lojas->items, lojas->items_capacity * sizeof(lojas->items));
    }

    lojas->items[lojas->items_count] = item;
    lojas->items_count++;
}

void print_loja(Loja loja){
    printf("ID: %d\n", loja.id);
    printf("NOME: %s\n", loja.nome);
    printf("DESCRICAO: %s\n", loja.descricao);
    if(loja.catalogo_count > 0){
        for(size_t i = 0; i < loja.catalogo_count; i++){
            printf("ID DO JOGO: %d\n", loja.catalogo[i]);
        }
    }
}

void print_lojas(Lojas* lojas){
    for(size_t i = 0; i < lojas->items_count; i++){
        print_loja(lojas->items[i]);
    }
}

void destroy_lojas(Lojas *lojas){
    free(lojas->items);
}