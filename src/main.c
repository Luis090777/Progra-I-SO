#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "comuna.h"

#define MAX_PROGRAMAS 100
#define MAX_ACCIONES 20

/*int main() {

    // Crear una instancia de la estructura comuna
    struct Comuna mi_comuna;

    // Asignar valores a la estructura
    mi_comuna.cantidad_paneles_solares = disponible;
    mi_comuna.capacidad_banco_baterias = disponible;
    mi_comuna.area_trabajo_comun = disponible;
    mi_comuna.area_culto = disponible;
    mi_comuna.area_recreacion = disponible;
    mi_comuna.area_gym = disponible;
    mi_comuna.area_biblioteca = disponible;
    mi_comuna.area_taller = disponible;
    mi_comuna.area_farmacia = disponible;
    mi_comuna.area_despensa = disponible;
    mi_comuna.area_huerto = disponible;
  // se inicia el loop de turnos de la comuna
  */


  int main() {

    Programa programas[MAX_PROGRAMAS];
    int cantidad_programas = 0;
    
    // Buscamos todos los archivos txt en la carpeta Tareas de la comuna
    DIR *d;
    struct dirent *dir;
    d = opendir("Tareas de la comuna");

    if (d) {
        while ((dir = readdir(d)) != NULL) {
            if (strstr(dir->d_name, ".com")) {
                char filename[100];
                strcpy(filename, "Tareas de la comuna/");
                strcat(filename, dir->d_name);
                printf("Procesando archivo: %s\n", filename);
                
                // Leemos el archivo y creamos un nuevo programa
                FILE *fp;
                char line[100];
                Programa programa;
                programa.cantidad_acciones = 0;
                fp = fopen(filename, "r");
                if (fp) {
                    while (fgets(line, sizeof(line), fp)) {
                        // Eliminamos el salto de línea al final de la línea
                        line[strcspn(line, "\n")] = 0;
                        
                        // Hacemos el parse de la línea y agregamos la acción al programa
                        Accion accion;
                        if (sscanf(line, "Trabaja %d %d #%[^\n]", &accion.cantidad_de_tiempo_requerido,
                            &accion.cantidad_de_bateria_requerida, accion.comentario) == 3) {
                            strcpy(accion.area_para_tarea, "Trabaja");
                            programa.acciones[programa.cantidad_acciones++] = accion;
                        } else if (sscanf(line, "Requiere %s %d %d #%[^\n]", accion.area_para_tarea,
                            &accion.cantidad_de_tiempo_requerido, &accion.cantidad_de_bateria_requerida,
                            accion.comentario) == 4) {
                            programa.acciones[programa.cantidad_acciones++] = accion;
                        }
                    }
                    fclose(fp);
                    
                    // Agregamos el programa a la lista de programas
                    strcpy(programa.nombre, dir->d_name);
                    programas[cantidad_programas++] = programa;
                }
            }
        }
        closedir(d);
    }
    
    if (cantidad_programas == 0){
    }
    // Imprimimos la lista de programas y sus acciones
    for (int i = 0; i < cantidad_programas; i++) {
        printf("Programa %d: %s\n", i+1, programas[i].nombre);
        printf("Acciones:\n");
        for (int j = 0; j < programas[i].cantidad_acciones; j++){
          printf("# %s\n", programas[i].acciones[j].comentario);
        }
        printf("\n");
    }

    return 0;
}


/*
  while (turn_loop) {
    // Sumar energía de los paneles solares a la batería
    mi_comuna.capacidad_banco_baterias += mi_comuna.cantidad_paneles_solares * ENERGIA_POR_PANEL;

  return(0);
  }

  int main() {
    struct Programa programa;
    programa.lista_acciones = NULL;
    programa.cantidad_acciones = 0;

    // Agregar algunas acciones
    struct Accion* accion1 = malloc(sizeof(struct Accion));
    strcpy(accion1->area_para_tarea, "Culto");
    accion1->cantidad_de_tiempo_requerido = 30;
    accion1->cantidad_de_bateria_requerida = 2;
    strcpy(accion1->comentario, "Preparar altar");
    agregar_accion(&programa, accion1);

    struct Accion* accion2 = malloc(sizeof(struct Accion));
    strcpy(accion2->area_para_tarea, "Recreacion");
    accion2->cantidad_de_tiempo_requerido = 60;
    accion2->cantidad_de_bateria_requerida = 4;
    strcpy(accion2->comentario, "Jugar futbol");
    agregar_accion(&programa, accion2);

    // Mostrar las acciones
    mostrar_acciones(&programa);

    // Eliminar la primera acción
    eliminar_accion(&programa, 0);

    // Mostrar las acciones nuevamente
    mostrar_acciones(&programa);
  }



}*/