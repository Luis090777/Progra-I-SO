#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include "comuna.h"
#define MAX_PROGRAMAS 30
#define MAX_ACCIONES 30

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
    comuna.area_trabajo_comun = disponible;
    comuna.area_culto = disponible;
    comuna.area_recreacion = disponible;
    comuna.area_gym = disponible;
    comuna.area_biblioteca = disponible;
    comuna.area_taller = disponible;
    comuna.area_farmacia = disponible;
    comuna.area_despensa = disponible;
    comuna.area_huerto = disponible;


    FILE *log_file = fopen("log.txt", "w");

    int opcion;
    
    do {
        printf("\nMenu:\n");
        printf("1. Algoritmo seleccion por tiempo\n");
        printf("2. Algoritmo de Round Robin\n");
        printf("3. Algoritmo seleccion por carga de bateria\n");
        printf("4. Salir\n");
        printf("Selecciona una opcion: ");
        scanf("%d", &opcion);
        
        switch(opcion) {
            case 1:
                printf("Porfavor seleccione el valor de los siguientes parametros:\n ");
                comuna.cantidad_paneles_solares;
                comuna.capacidad_banco_baterias;
                printf("Cantidad de paneles solares:\n");
                scanf("%d", &comuna.cantidad_paneles_solares);
                printf("Capacidad del banco de baterias:\n");
                scanf("%d", &comuna.capacidad_banco_baterias);
                ordenamiento_trabajo_más_corto(acciones, cantidad_acciones);
                ejecutar_trabajo_más_corto(log_file,comuna,acciones,cantidad_acciones);
                break;
            case 2:
                printf("Seleccionaste la opcion 2.\n");
                break;
            case 3:
                printf("Porfavor seleccione el valor de los siguientes parametros:\n ");
                comuna.cantidad_paneles_solares;
                comuna.capacidad_banco_baterias;
                printf("Cantidad de paneles solares:\n");
                scanf("%d", &comuna.cantidad_paneles_solares);
                printf("Capacidad del banco de baterias:\n");
                scanf("%d", &comuna.capacidad_banco_baterias);
                ejecutar_trabajo_costo_bateria_descendente(log_file,comuna,acciones,cantidad_acciones);
                break;
            case 4:
                printf("Saliendo...\n");
                break;
            default:
                printf("Opcion invalida. Intente de nuevo.\n");
                break;
        }
        
    } while(opcion != 4);
    
    return 0; 
}
