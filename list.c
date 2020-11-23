#include "list.h"
#include <stdlib.h>
#include <stdio.h>

lifo_t *new_lista() {
    lifo_t  *list;
    list = (lifo_t*)malloc(sizeof(lifo_t));

    if(list == NULL){
        printf("Error en new_list(): Memoria insuficiente para la creacion de una nueva lista");
        fflush(stdout);
        return NULL;
    }

    list->head = 0;
    return list;
}

nodo_t *new_nodo(char *dato) {
    nodo_t *nodo;
    nodo = (nodo_t *)malloc(sizeof(nodo_t));

    if(nodo == NULL){
        printf("Error en new_nodo(): Memoria insuficiente para la creacion de un nuevo nodo");
        fflush(stdout);
        return NULL;
    }

    nodo->dato = *dato;
    nodo->prev = 0;
    nodo->next = 0;
    return nodo;
}

void push(lifo_t *self, char *dato) {
    nodo_t *aux = new_nodo(dato);

    if(self->head == 0){
        aux->prev = 0;
        aux->next = 0;
        self->head = aux;
        return;
    }

    aux->next = self->head->next;
    self->head->next = aux;
    aux->prev = self->head;
    self->head = aux;
}

char pop(lifo_t *self) {
    char data = self->head->dato;

    nodo_t *aux = self->head;
    self->head->prev->next = self->head->next;
    self->head = self->head->prev;
    destruir_nodo(aux);

    return data;
}
