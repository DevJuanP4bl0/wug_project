#include <stdbool.h>

typedef enum {
  M = 'M',
  F = 'F'
} gender_t;

typedef struct wug {
  int      genome[16];
  gender_t gender;
} wug_t;


typedef struct node {
  wug_t       *wug;
  struct node *next;
} node_t;


