#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "comuna.h"
#define MAX_PROGRAMAS 30
#define MAX_ACCIONES 30
#include <stdbool.h>

int main(int argc, char *argv[]) {

    Accion acciones[MAX_PROGRAMAS*MAX_ACCIONES];
    int cantidad_acciones = 0;
    char nombre_de_directorio[] = "Tareas de la comuna";

    cantidad_acciones = parseDirectorio(nombre_de_directorio, acciones);

    if (cantidad_acciones == 0) {
        printf("No se encontraron archivos en el directorio especificado.\n");
        return 1;
    }
    
    Comuna comuna;
    // Asignar valores a la estructura
    comuna.cantidad_paneles_solares = atoi(argv[1]);
    comuna.capacidad_banco_baterias = atoi(argv[2]);
    comuna.area_trabajo_comun = disponible;
    comuna.area_culto = disponible;
    comuna.area_recreacion = disponible;
    comuna.area_gym = disponible;
    comuna.area_biblioteca = disponible;
    comuna.area_taller = disponible;
    comuna.area_farmacia = disponible;
    comuna.area_despensa = disponible;
    comuna.area_huerto = disponible;


    int calendarizador = atoi(argv[3]);
    FILE *log_file = fopen("log.txt", "w");

   switch(calendarizador) {
        case 1:
        ordenamiento_trabajo_más_corto(acciones, cantidad_acciones);
        ejecutar_trabajo_más_corto(log_file,comuna,acciones,cantidad_acciones);
        break;
        } 
    return 0; 
}