#include <stdio.h>
#include "list.h"

int main() {
    int opcion_menu;
    char char_input;
    lifo_t *lista;
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
        scanf("%i", &opcion_menu);

        switch (opcion_menu) {
            case 1:
                printf("\nIntroduzca el dato que desea introducir a la lista: ");
                fflush(stdout);
                fflush(stdin);
                getchar();
                char_input = getchar();
                push(lista, char_input);
                break;
            case 2:
                break;
            case 3:
                char_input = pop(lista);
                if(char_input != '\0') {
                    printf("\nEl dato %c fue exitosamente eliminado", char_input);
                }else{
                    printf("\nLa lista se encuentra vacia");
                }
                fflush(stdout);
                break;
            case 4:
                break;
            default:
                break;
        }
    }while(opcion_menu != 4);
    return 0;
}
