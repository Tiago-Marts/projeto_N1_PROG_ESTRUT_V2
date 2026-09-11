# projeto_N1_PROG_ESTRUT_V2
Projeto para composição da nota N1 da disciplina de Programação Estruturada, segunda iteração


## Lógica
No início do programa, a pessoa seleciona como deseja entrar no sistema, podendo ser um dos três tipos: loja, para cadastro de jogos no catálogo; usuário, para busca e compra de jogos, e administrador, para adicionar mais jogos no geral. 

### Loja
A loja pode adicionar ou remover jogos em seu catálogo. Os jogos são referenciados pelo seu id, os quais são armazenados em um array.

### Usuário
O usuário pode adicionar jogos em seu carrinho e comprá-los para que eles adicionados em sua coleção.

### Administrador 
O administrador é capaz de adicionar ou remover mais jogos na base geral de jogos.

## Estrutura de Dados
<p align="center">
    <img src="./readme/estrut-dados.png">
</p>
<p>Para o projeto, decidimos construir os dados de duas formas: as estruturas em si, contendo os campos e variáveis próprias, e um controle de array para a estrutura. 
</p>
<p>
Por exemplo, a estrutura Jogo contém os campos id_jogo, nome, descricao e preco. E para controlar um array dinâmica de jogos, utilizamos a estrutura Jogos, a qual contem um ponteiro de Jogo, a capacidade do array e um contador para o número de items ocupados no array.
Dessa maneira é possível alocar responsabilidades diferentes para estruturas distintas.
</p>

## Fluxograma
