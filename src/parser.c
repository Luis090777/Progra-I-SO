#include "parser.h"

int parseDirectorio(char* nombre_de_directorio, Accion* acciones) {
    DIR *d;
    struct dirent *dir;
    d = opendir(nombre_de_directorio);

    int cantidad_acciones = 0;
    int programa_actual = 0;
    int orden = 0;
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

                            char nombre_sin_extension[100];
                            remover_substring(dir->d_name, ".com", nombre_sin_extension);
                            strcpy(accion.programa_padre.nombre, nombre_sin_extension);

                            accion.programa_padre.indice = programa_actual;
                            accion.orden = orden;
                            acciones[cantidad_acciones++] = accion;
                            orden++;

                        } else if (sscanf(line, "Requiere %s %d %d #%[^\n]", accion.area_para_tarea,
                            &accion.cantidad_de_tiempo_requerido, &accion.cantidad_de_bateria_requerida,
                            accion.comentario) == 4) {

                            char nombre_sin_extension[100];
                            remover_substring(dir->d_name, ".com", nombre_sin_extension);
                            strcpy(accion.programa_padre.nombre, nombre_sin_extension);
                            accion.programa_padre.indice = programa_actual;
                            accion.orden = orden;
                            acciones[cantidad_acciones++] = accion;
                            orden++;
                        }
                    }
                    fclose(fp);
                    programa_actual++;
                    orden = 0;
                }
            }
        }
        closedir(d);      
        return cantidad_acciones;
    } else {
        printf("No se pudo abrir el directorio: %s\n", nombre_de_directorio);
        return 0;
    }
}

void remover_substring(char *s, const char *toremove, char *result) {
    int i, j, k;
    int n = strlen(toremove);
    int found = 0;

    for (i = 0, j = 0; s[i] != '\0'; i++) {
        found = 1;
        for (k = 0; k < n; k++) {
            if (s[i + k] != toremove[k]) {
                found = 0;
                break;
            }
        }
        if (found == 1) {
            i += n - 1;
            continue;
        }
        result[j++] = s[i];
    }
    result[j] = '\0';
}