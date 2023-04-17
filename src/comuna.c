#include "comuna.h"

int compare_acciones(const void *a, const void *b) {
    Accion *pa = (Accion*)a;
    Accion *pb = (Accion*)b;
    return pa->cantidad_de_tiempo_requerido - pb->cantidad_de_tiempo_requerido;
}

Accion* generar_lista_acciones(Programa* programas, int cantidad_programas, int* cantidad_acciones) {
    int total_acciones = 0;
    for (int i = 0; i < cantidad_programas; i++) {
        total_acciones += programas[i].cantidad_acciones;
    }
    
    Accion* lista_acciones = malloc(total_acciones * sizeof(Accion));
    int index = 0;
    for (int i = 0; i < cantidad_programas; i++) {
        lista_acciones[index] = programas[i].acciones[0];
        index++;
        for (int j = 1; j < programas[i].cantidad_acciones; j++) {
            //printf("\nprograma: %d accion: %d",i,j);
            if (strcmp(programas[i].acciones[j].area_para_tarea, lista_acciones[index - 1].area_para_tarea) == 0) {
                index++; // Incrementar el índice antes de llamar a realloc
                if (index > total_acciones) {
                    // Ajustar el tamaño de lista_acciones
                    total_acciones++;
                    lista_acciones = realloc(lista_acciones, total_acciones * sizeof(Accion));
                }
                lista_acciones[index - 1] = programas[i].acciones[j];
            } else {
                int k;
                for (k = index - 1; k >= 0; k--) {
                    if (strcmp(programas[i].acciones[j].area_para_tarea, lista_acciones[k].area_para_tarea) != 0) {
                        break;
                    }
                }
                index++; // Incrementar el índice antes de llamar a realloc
                if (index > total_acciones) {
                    // Ajustar el tamaño de lista_acciones
                    total_acciones++;
                    lista_acciones = realloc(lista_acciones, total_acciones * sizeof(Accion));
                }
                for (int l = index - 1; l > k + 1; l--) {
                    lista_acciones[l] = lista_acciones[l - 1];
                }
                lista_acciones[k + 1] = programas[i].acciones[j];
            }
        }
    } 
        

        // Ordenar el arreglo de acciones por tiempo requerido de menor a mayor
        qsort(lista_acciones, total_acciones, sizeof(Accion), compare_acciones);


        *cantidad_acciones = index; 
        return lista_acciones;
    }