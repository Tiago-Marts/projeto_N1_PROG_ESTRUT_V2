#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "../include/jogo.h"
#include "../include/loja.h"
#include "../include/usuario.h"

Jogo *busca_jogo(Jogos *base, unsigned int id){
    for(size_t i = 0; i < base->items_count; i++){
        if(id == base->items[i].id){
            printf("Jogo encontrado!\n");
            return &base->items[i];
        }
    }

    return NULL;

}

int main(void){
    Jogos base_jogos;
    create_jogos(&base_jogos);

    Jogo teste_jogo;
    teste_jogo.nome = "Teste Jogo";
    teste_jogo.id = 15;
    teste_jogo.descricao = "Descricao legal";
    teste_jogo.preco = 99.9f;

    add_jogo(&base_jogos, teste_jogo);
    Jogo *teste = busca_jogo(&base_jogos, 15);
    destroy_jogos(&base_jogos);

    //Teste para usuarios
    Usuarios usuarios;
    create_usuarios(&usuarios);

    Usuario teste_usuario;
    teste_usuario.nome = "Usuario teste";
    teste_usuario.id = 16;
    create_usuario(&teste_usuario);

    add_jogo_to_usuario(&teste_usuario, 15);
    add_jogo_to_carrinho(&teste_usuario, 15);

    printf("%u\n", teste_usuario.carrinho[0]);
    printf("%llu\n", teste_usuario.carrinho_count);

    remove_jogo_from_carrinho(&teste_usuario, 15);
    printf("%llu\n", teste_usuario.carrinho_count);

    int opt_menu = 0;

    while(opt_menu != 5){
        printf("MENU\n");
        printf("\t 1. Menu da Loja\n");
        printf("\t 2. Menu de Jogos\n");
        printf("\t 3. Menu do Usuario\n");
        printf("\t 4. ADMIN\n");
        printf("\t 4. Sair\n");

        scanf("%d", &opt_menu);

        switch (opt_menu)
        {
        case 1:
            break;

        default:
            break;
        }
    }

    return 0;
}
