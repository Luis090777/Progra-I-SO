#include "parser.h"

int parseDirectorio(char* nombre_de_directorio, Programa* programas) {
    DIR *d;
    struct dirent *dir;
    d = opendir(nombre_de_directorio);

    int cantidad_programas = 0;

    if (d) {
        while ((dir = readdir(d)) != NULL) {
            if (strstr(dir->d_name, ".com")) {
                char filename[100];
                strcpy(filename, nombre_de_directorio);
                strcat(filename, "/");
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
        return cantidad_programas;
    } else {
        printf("No se pudo abrir el directorio: %s\n", nombre_de_directorio);
        return 0;
    }
}