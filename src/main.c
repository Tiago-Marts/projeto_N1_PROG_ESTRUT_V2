#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "../include/jogo.h"
#include "../include/loja.h"

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