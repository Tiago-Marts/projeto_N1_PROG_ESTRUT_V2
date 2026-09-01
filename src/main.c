#include <stdio.h>
#include <stdlib.h>
#include <string.h>

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
void create_jogos(Jogos *jogos){
    printf("TESTE");
    jogos->items_capacity = 100;
    jogos->items_count = 0;
    jogos->items = malloc(jogos->items_capacity * sizeof(*jogos->items));
}

void add_jogo(Jogos *jogos, Jogo jogo){

    //Adiciona mais capacidade 
    if(jogos->items_count == jogos->items_capacity){
        jogos->items_capacity *= 2;
    }

    jogos->items = realloc(jogos->items, jogos->items_capacity * sizeof(jogos->items));
    jogos->items[jogos->items_count] = jogo;
    jogos->items_count += 1;
}

void print_jogo(Jogo jogo){
    printf("ID: %d\n", jogo.id);
    printf("NOME: %s\n", jogo.nome);
    printf("DESC: %s\n", jogo.descricao);
    printf("PRECO: %.2f\n", jogo.preco);
}

void print_jogos(Jogos *jogos){
    for(size_t i = 0; i < jogos->items_count; i++){
        printf("INDEX: %lld\n", i);
        print_jogo((jogos->items[i]));
    }
}

void destroy_jogos(Jogos *jogos){
    free(jogos->items);
}

//LOJA
typedef struct {
    unsigned int id;
    char *nome;
    char *descricao;
    unsigned int *catalogo;
    size_t catalogo_capacity;
} Loja;

int main(void){


    Jogos jogos;
    create_jogos(&jogos);

    Jogo teste_jogo = {12, "Teste Nome", "Teste Desc", 9.99f};
    print_jogo(teste_jogo);

    add_jogo(&jogos, teste_jogo);
    add_jogo(&jogos, teste_jogo);
    
    printf("JOGOS COUNT: %lld\n", jogos.items_count);
    print_jogos(&jogos);

    destroy_jogos(&jogos);
    return 0;
}