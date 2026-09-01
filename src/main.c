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
        jogos->items = realloc(jogos->items, jogos->items_capacity * sizeof(jogos->items));
    }
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

int main(void){

    //TESTE DE JOGOS
    Jogos jogos;
    create_jogos(&jogos);

    Jogo teste_jogo = {12, "Teste Nome", "Teste Desc", 9.99f};
    print_jogo(teste_jogo);

    add_jogo(&jogos, teste_jogo);
    add_jogo(&jogos, teste_jogo);

    printf("JOGOS COUNT: %lld\n", jogos.items_count);
    print_jogos(&jogos);

    destroy_jogos(&jogos);

    //TESTE LOJA
    Loja teste_loja;
    teste_loja.id = 15;
    teste_loja.nome = "Nome teste";
    teste_loja.descricao = "Descricao teste";
    create_loja(&teste_loja);

    add_jogo_to_loja(&teste_loja, 12);
    add_jogo_to_loja(&teste_loja, 12);
    print_loja(teste_loja);

    //TESTE LOJAS
    Lojas lojas;
    create_lojas(&lojas);
    add_loja(&lojas, teste_loja);
    add_loja(&lojas, teste_loja);
    print_lojas(&lojas);

    destroy_lojas(&lojas);

    return 0;
}