#include <stdbool.h>
#include <assert.h>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <stdint.h>
#include "data.h"
#include "util.h"

/* dado um array de int (com 0s ou 1s) e um gender, criar um wug e
   retorna seu endereço. */

wug_t* create_wug(int genome[16], gender_t g);


/* funções auxiliares para imprimir um wug e imprimir a população
   atual de wugs. Estas funções serão úteis para debug. */

void  print_wug(wug_t *w);
void  print_population(wug_t** population, const int size);


/* dado um genoma, esta função internamente sabe o genoma do superwug
   e o mapeamento de zonas. Usando estas duas informações, esta função
   atualiza o segundo argumento, um array de 4 posições de inteiros
   (0s ou 1s). */

void genome2features(const int genome[16], int features[4]);


/* A função abaixo informa a quantidade de superwugs da população */

int  report_population(wug_t** population, const int size);


/* dado um wug, esta função devolve seu rank, isto é, o número de
   características que ele tem com valor excepcional (valor 1). */

int  rank(const wug_t* w);


/* esta função é responsável por dado um wug, adiciona-lo na
   população. Na implementação sugerida, a população é um array de
   wugs. Esta função deve adicionar wugs no array mantendo-o ordenado
   (ordem inversa de rank), wugs com maior rank na frente. Além disso,
   o limite do array não pode ser ultrapassado, a capacidade da
   população. O retorno é um booleano que indica se o novo wug foi
   ignorado (rank menor do que o wug de rank mais baixo na população
   já no limite de wugs). */

bool insert_ranked(wug_t** population, wug_t* w, int* size, int capacity);







