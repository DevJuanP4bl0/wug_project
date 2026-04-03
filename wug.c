#include <stdio.h>
#include "wug.h"
#include "data.h"

wug_t create_wug(int genome[16], gender_t g){
    wug_t wug;
    
    for (int i = 0; i < 16; i++)
        wug.genome[i] = genome[i];

    wug.gender = g;

    return wug;
}