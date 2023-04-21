#include "calendarizador.h"
void ordenamiento_trabajo_más_corto(Accion acciones[], int cantidad_acciones) {
    int i, j, k;
    Accion temp;

    for (i = 0; i < cantidad_acciones; i++) {
        for (j = 0; j < cantidad_acciones - i - 1; j++) {
            if (acciones[j].cantidad_de_tiempo_requerido > acciones[j+1].cantidad_de_tiempo_requerido) {
                temp = acciones[j];
                acciones[j] = acciones[j+1];
                acciones[j+1] = temp;
            }
        }
    }

    for (i = 0; i < cantidad_acciones; i++) {
        for (j = i+1; j < cantidad_acciones; j++) {
            if (acciones[i].programa_padre.indice == acciones[j].programa_padre.indice &&
                acciones[i].orden > acciones[j].orden) {
                temp = acciones[i];
                acciones[i] = acciones[j];
                acciones[j] = temp;
                for (k = i+1; k < cantidad_acciones; k++) {
                    if (acciones[i].programa_padre.indice == acciones[k].programa_padre.indice &&
                        acciones[i].orden > acciones[k].orden) {
                        temp = acciones[i];
                        acciones[i] = acciones[k];
                        acciones[k] = temp;
                    }
                }
            }
        }
    }
}