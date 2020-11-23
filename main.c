#include <stdio.h>
#include "list.h"

int main() {
    char opcion_menu, opcion_sub;
    char char_input;
    lifo_t *lista;
    nodo_t *iterador;
    lista = new_lista();

    if(lista == 0){
        return -1;
    }

    do {
        printf("\n\nGestor de lista LIFO\n"
               "------------------------\n"
               "1) Agregar dato\n"
               "2) Consultar datos\n"
               "3) Eliminar dato\n"
               "4) Salir\n"
               "Opcion (1-4): ");
        fflush(stdout);
        fflush(stdin);
        opcion_menu = getchar();
        getchar();
        switch (opcion_menu) {
            case '1':
                printf("\nIntroduzca el dato que desea introducir a la lista: ");
                fflush(stdout);
                char_input = getchar();
                getchar();
                push(lista, char_input);
                break;
            case '2':
                iterador = lista->head;
                do{
                    printf("\nDato actual: %c", iterador->dato);
                    if(iterador->prev != 0)
                        printf("\nz) Anterior dato");
                    if(iterador->next != 0)
                        printf("\nx) Siguiente dato");
                    printf("\nc) Volver al menu principal"
                           "\nEscriba una opcion: ");
                    fflush(stdout);
                    opcion_sub = getchar();
                    getchar();

                    if(opcion_sub == 'z' && iterador->prev != 0){
                        iterador = iterador->prev;
                    }else if(opcion_sub == 'x' && iterador->next != 0){
                        iterador = iterador->next;
                    }else if(opcion_sub != 'c'){
                        printf("\nOpcion invalida\n");
                        fflush(stdout);
                    }

                }while(opcion_sub != 'c');
                break;
            case '3':
                char_input = pop(lista);
                if(char_input != '\0') {
                    printf("\nEl dato %c fue exitosamente eliminado", char_input);
                }else{
                    printf("\nLa lista se encuentra vacia");
                }
                fflush(stdout);
                break;
            case '4':
                printf("\nTerminando la ejecucion del programa...");
                fflush(stdout);
                break;
            default:
                printf("\nOpcion invalida, vuelva a intentar");
                fflush(stdout);
                break;
        }
    }while(opcion_menu != '4');
    destruir_lista(lista);
    return 0;
}
