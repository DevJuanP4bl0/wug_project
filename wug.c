#include <stdio.h>
#include "wug.h"
#include "data.h"

wug_t* create_wug(int genome[16], gender_t g){
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