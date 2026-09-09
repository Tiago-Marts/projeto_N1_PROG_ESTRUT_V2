#include <stdio.h>
#include <stdlib.h>

#include "../include/usuario.h"
#include "../include/loja.h"
#include "../include/jogo.h"

//Busca de jogo
Jogo *busca_jogo(Jogos *base, unsigned int id){
    for(size_t i = 0; i < base->items_count; i++){
        if(id == base->items[i].id){
            return &base->items[i];
        }
    }

    return NULL;

}
