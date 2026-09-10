#ifndef USUARIO_H
#define USUARIO_H

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
void create_usuario(Usuario *usuario);

//Adiciona Jogo a Usuario
void add_jogo_to_usuario(Usuario* usuario, unsigned int id_item);

void add_jogo_to_carrinho(Usuario *usuario, unsigned int id_item);

//A partir do id, remove um item do carrinho
void remove_jogo_from_carrinho(Usuario *usuario, unsigned int id_item);

void create_usuarios(Usuarios* usuarios);

void add_usuario(Usuarios *usuarios, Usuario item);

void print_usuario(Usuario usuario);

void print_usuarios(Usuarios* usuarios);

void destroy_usuarios(Usuarios *usuarios);


#endif
