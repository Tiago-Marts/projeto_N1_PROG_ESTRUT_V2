#include <stdio.h>
#include <stdlib.h>

//Usuario
typedef struct {
    unsigned int id;
    char *nome;
    unsigned int *colecao;
    size_t colecao_capacity;
    size_t colecao_count;
    unsigned int *carrinho;
    size_t carrinho_capacity;
    size_t carrinho_count;
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

    usuario->carrinho_capacity = 3;
    usuario->carrinho_count = 0;
    usuario->carrinho = malloc(usuario->carrinho_capacity * sizeof(usuario->carrinho));
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

void add_jogo_to_carrinho(Usuario *usuario, unsigned int id_item){
    if(usuario->carrinho_count == usuario->carrinho_capacity){
        usuario->carrinho_capacity *= 2;
        usuario->carrinho = realloc(usuario->carrinho, usuario->carrinho_capacity * sizeof(usuario->carrinho));
    }

    usuario->carrinho[usuario->carrinho_count] = id_item;
    usuario->carrinho_count++;
}

//A partir do id, remove um item do carrinho
void remove_jogo_from_carrinho(Usuario *usuario, unsigned int id_item){

    //Acha o index do item a ser removido
    size_t index = 0;
    for(size_t i = 0; i < usuario->carrinho_count; i++){
        if(usuario->carrinho[i] == id_item){
            index = i;
        }
    }

    //Realoca os itens a partir do index que foi removido
    for(size_t i = index; i < usuario->carrinho_count - 1; i++){
        usuario->carrinho[i] = usuario->carrinho[i+1];
    }

    unsigned int *tmp = realloc(usuario->carrinho, (usuario->carrinho_count - 1) * sizeof(usuario->carrinho));

    //TO-DO: tratamento de erro para o realloc aqui

    usuario->carrinho_count--;
    usuario->carrinho = tmp;
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
