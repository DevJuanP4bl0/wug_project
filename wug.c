#include <stdio.h>
#include "wug.h"
#include "data.h"
#include "util.h"

wug_t* create_wug(int genome[16], gender_t g){
    /* Separa memoria na heap para struct wug */
    wug_t* wug = malloc(sizeof(wug_t));
    
    wug->gender = g;

    for (int i = 0; i < 16; i++)
        wug->genome[i] = genome[i];

    return wug;
}

void genome2features(const int genome[16], int features[4]){
    int super[] = {1, 0, 1, 1, 1, 0, 0, 1, 0, 1, 0, 0, 1, 1, 0, 0};
    int zones[] = {0, 1, 0, 2, 3, 3, 1, 0, 2, 1, 1, 2, 3, 0, 3, 2};

    int count[] = {0, 0, 0, 0};

    for (int i = 0; i < 16; i++){
        if (genome[i] == super[i]){
            int zone = zones[i];
            count[zone]++;
        }
    }

    for (int i = 0; i < 4; i++){
        if (count[i] == 4)
            features[i] = 1;
        else
            features[i] = 0;
    }
}

int rank(const wug_t* w){
    int countRank = 0;
    int features[4];

    genome2features(w->genome, features);

    for (int i = 0; i < 4; i++){
        countRank += features[i];
    }

    return countRank;
}

static void insertion_sort(wug_t** population, int* size, int rank_wug){
    int j = *size - 1;

    while (j > 0 && rank_wug > rank(population[j-1])){
        wug_t* temp = population[j];
        population[j] = population[j-1];
        population[j-1] = temp;   
        j--;
    }
}

bool insert_ranked(wug_t** population, wug_t* w, int* size, int capacity){
     int rank_wug = rank(w);
    
    if (*size < capacity){
        population[*size] = w;
        (*size)++;

        if (*size > 1)
            insertion_sort(population, size, rank_wug);

        return true;
    }
    else {
        if (rank_wug > rank(population[capacity - 1])){
            wug_t* disalocated_wug = population[capacity - 1];
            population[capacity - 1] = w;
            free(disalocated_wug);
            insertion_sort(population, size, rank_wug);

            return true;
        }
    }
     
    free(w);
    return false;
}

void print_wug(wug_t *w) {
    char *string_wug = array_string(w->genome, 16);
    int features[4];
    int rankWug = rank(w);

    genome2features(w->genome, features);

    char *string_features = array_string(features, 4);

    printf("%c %s %s %d\n", w->gender, string_wug, string_features, rankWug);

    /* Para evitar memory leak da alocação feita em array_string */
    free(string_wug);
    free(string_features);
}

void  print_population(wug_t** population, const int size){
    for (int i = 0; i < size; i++){
        printf("%d ", i);
        print_wug(population[i]);
    }
}

int report_population(wug_t** population, const int size){
    int features[4];
    int count[16] = {0};

    for (int i = 0; i < size; i++) {
        int sum = 0;
        genome2features(population[i]->genome, features);

        for (int j = 0; j < 4; j++)
            sum = sum * 2 + features[j];

        count[sum]++;
    }

    for (int i = 0; i < 16; i++) {
        if (count[i] > 0){
            for (int j = 0; j < 4; j++){
               /*Operação bitwise */
               features[j] = (i >> (3 - j)) & 1;  
            }

            char *string_features = array_string(features, 4);

            printf("%s %d\n", string_features, count[i]);
            free(string_features);
        }
    }

    return count[15];
}

void free_population (wug_t** population, const int size) {
    for (int i = 0; i < size; i++) 
        free(population[i]);
}
