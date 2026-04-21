#include <stdio.h>
#include "wug.h"
#include "data.h"

int main() {
   int genome[16] = {1, 0, 1, 1, 1, 0, 0, 1, 0, 1, 0, 0, 1, 1, 0, 0}; // wug rank 4
   int genome1[16] = {0, 0, 1, 1, 1, 0, 0, 1, 0, 1, 0, 0, 1, 1, 0, 0}; // wug rank 3
   int genome2[16] = {0, 1, 1, 1, 1, 0, 0, 1, 0, 1, 0, 0, 1, 1, 0, 0}; // wug rank 2
   int genome3[16] = {1, 0, 1, 1, 1, 0, 0, 1, 0, 1, 0, 0, 1, 1, 0, 0}; // wug rank 4
   int genome4[16] = {0, 1, 1, 1, 1, 0, 0, 1, 0, 1, 0, 0, 1, 1, 0, 0}; // wug rank 2

   int capacity = 3, size = 0;
   wug_t* population[capacity];
  
   wug_t* wug = create_wug(genome, F); // rank4
   wug_t* wug1 = create_wug(genome1, F); // rank3
   wug_t* wug2 = create_wug(genome2, F); // rank2
   wug_t* wug3 = create_wug(genome3, M); // rank3
   wug_t* wug4 = create_wug(genome4, F); // rank2

   insert_ranked(population, wug, &size, capacity);
   insert_ranked(population, wug1, &size, capacity);
   insert_ranked(population, wug2, &size, capacity);
   insert_ranked(population, wug3, &size, capacity);
   (!insert_ranked(population, wug4, &size, capacity));

   print_wug(wug);

   printf("População final:\n");
   print_population(population, size);

   printf("Size: %d\n", size);

   int superWugs = report_population(population, size);

   free_population(population, size);
}