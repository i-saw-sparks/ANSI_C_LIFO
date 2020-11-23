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

    nodo->dato = dato;
    nodo->prev = 0;
    nodo->next = 0;
    return nodo;
}