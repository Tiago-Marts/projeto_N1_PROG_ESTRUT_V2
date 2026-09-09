#include <stdio.h>
#include <stdlib.h>

//Usuario
typedef struct {
    unsigned int id;
    char *nome;
    unsigned int *colecao;
    size_t colecao_capacity;
    size_t colecao_count;
} Usuario;


typedef struct {
    Usuario *items;
    size_t items_capacity;
    size_t items_count;
} Usuarios;

//Aloca memória no HEAP para o colecao
void create_usuario(Usuario *usuario){
    usuario->colecao_capacity = 100;
    usuario->colecao_count = 0;
    usuario->colecao = malloc(usuario->colecao_capacity * sizeof(usuario->colecao));
}

//Adiciona Jogo a Usuario
void add_jogo_to_usuario(Usuario* usuario, unsigned int id_item){
    if(usuario->colecao_count == usuario->colecao_capacity){
        usuario->colecao_capacity *= 2;
        usuario->colecao = realloc(usuario->colecao, usuario->colecao_capacity * sizeof(usuario->colecao));
    }

    usuario->colecao[usuario->colecao_count] = id_item;
    usuario->colecao_count++;
}


void create_usuarios(Usuarios* usuarios){
    usuarios->items_capacity = 100;
    usuarios->items_count = 0;
    usuarios->items = malloc(usuarios->items_capacity * sizeof(usuarios->items));
}

void add_usuario(Usuarios *usuarios, Usuario item){
    if(usuarios->items_count == usuarios->items_capacity){
        usuarios->items_capacity *= 2;
        usuarios->items = realloc(usuarios->items, usuarios->items_capacity * sizeof(usuarios->items));
    }

    usuarios->items[usuarios->items_count] = item;
    usuarios->items_count++;
}

void print_usuario(Usuario usuario){
    printf("ID: %d\n", usuario.id);
    printf("NOME: %s\n", usuario.nome);
    if(usuario.colecao_count > 0){
        for(size_t i = 0; i < usuario.colecao_count; i++){
            printf("ID DO JOGO: %d\n", usuario.colecao[i]);
        }
    }
}

void print_usuarios(Usuarios* usuarios){
    for(size_t i = 0; i < usuarios->items_count; i++){
        print_usuario(usuarios->items[i]);
    }
}

void destroy_usuarios(Usuarios *usuarios){
    free(usuarios->items);
}
