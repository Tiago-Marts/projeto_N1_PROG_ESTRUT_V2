#include <stdio.h>
#include <stdlib.h>

#include "../include/usuario.h"
#include "../include/loja.h"
#include "../include/jogo.h"

//Busca um jogo a partir do ID e retorna o ponteiro para ele, em caso de sucesso. Caso falhe, retorna um ponteiro nulo.
Jogo *busca_jogo(Jogos *base, unsigned int id){
    for(size_t i = 0; i < base->items_count; i++){
        if(id == base->items[i].id){
            return &base->items[i];
        }
    }

    return NULL;

}
