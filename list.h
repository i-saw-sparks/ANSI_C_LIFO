#ifndef KARENAYALA699_NOV23_LIST_H
#define KARENAYALA699_NOV23_LIST_H

typedef struct nodo {
    struct nodo *prev;
    struct nodo *next;
    char dato;
} nodo_t;

typedef struct lifo_lista{
    nodo_t *head;
} lifo_t;

lifo_t* new_lista();
nodo_t* new_nodo(char dato);

void push(lifo_t *self, char dato);
char pop(lifo_t *self);

void destruir_lista(lifo_t *self);
void destruir_nodo(nodo_t *self);

#endif //KARENAYALA699_NOV23_LIST_H
