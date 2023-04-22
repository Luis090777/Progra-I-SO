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

void ejecutar_trabajo_más_corto(FILE *log_file, Comuna comuna, Accion acciones[], int cantidad_acciones){
    int espera_en_bateria=0;
    int tiempo_de_espera = 0;
    int minutos_recorridos = 0;
    int temp = 0;
    int i = 0;
    int veces = 0;
    bool cumplido = false; // variable que indica si se ha cumplido la acción actual


    while (i < cantidad_acciones) {
        if (cumplido) { // solo actualiza el índice si se ha cumplido la acción
            i++;
            cumplido = false;
        }

        while (comuna.capacidad_banco_baterias < acciones[i].cantidad_de_bateria_requerida) {
            espera_en_bateria++;
            comuna.capacidad_banco_baterias += comuna.cantidad_paneles_solares * ENERGIA_POR_PANEL;
            printf("bateria actual: %d bateria requerida:%d\n", comuna.capacidad_banco_baterias, acciones[i].cantidad_de_bateria_requerida);

            temp++;
            tiempo_de_espera++;
            minutos_recorridos++;
        }

        if (strcmp(acciones[i].area_para_tarea, "Trabaja") == 0) {
            temp++;
            minutos_recorridos++;
            if (i != cantidad_acciones - 1) {
                tiempo_de_espera++;
            }
            if (temp == acciones[i].cantidad_de_tiempo_requerido + espera_en_bateria) {
                printf("Se termino %s\n", acciones[i].comentario);
                comuna.capacidad_banco_baterias -= acciones[i].cantidad_de_bateria_requerida;
                registrar_accion(log_file, acciones[i], temp);
                temp = 0;
                espera_en_bateria = 0;
                cumplido = true;
                

            }
        } else {
            temp++;
            minutos_recorridos++;
            if (i != cantidad_acciones - 1) {
                tiempo_de_espera++;
            }
            if (temp == acciones[i].cantidad_de_tiempo_requerido + espera_en_bateria) {
                printf("Se envio a %s\n", acciones[i].area_para_tarea);
                comuna.capacidad_banco_baterias -= acciones[i].cantidad_de_bateria_requerida;
                registrar_accion(log_file, acciones[i], temp);
                temp = 0;
                espera_en_bateria = 0;
                cumplido = true;
                
            }
        }
    }
        printf("se terminaron todas las tareas\n");
        printf("Se duró: %d minutos\n", minutos_recorridos);
        double d = (double) tiempo_de_espera / cantidad_acciones;
        printf("El tiempo de espera promedio fue : %f\n", d);
        printf("bateria final %d\n", comuna.capacidad_banco_baterias);

        fprintf(log_file,"\nSe terminaron todas las tareas\n");
        fprintf(log_file, "Duró: %d minutos en terminar\n", minutos_recorridos);
        fprintf(log_file,"El tiempo de espera promedio fue: %f\n", d);

}