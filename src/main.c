#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "parser.h"
#define MAX_PROGRAMAS 30
#define MAX_ACCIONES 30

/*int main() {


  */


int main(){

    Accion acciones[MAX_PROGRAMAS*MAX_ACCIONES];
    int cantidad_acciones = 0;
    char nombre_de_directorio[] = "Tareas de la comuna";

    cantidad_acciones = parseDirectorio(nombre_de_directorio, acciones);

    if (cantidad_acciones == 0) {
        printf("No se encontraron archivos en el directorio especificado.\n");
        return 1;
    }
    
\

    ordenamiento_trabajo_más_corto(acciones, cantidad_acciones);

    for (int i = 0; i < cantidad_acciones; i++) {
       //if (acciones[i].programa_padre.indice == 1){
        printf("programa: %s\n",acciones[i].programa_padre.nombre);
        printf("orden: %d tiempo:%d\n",acciones[i].orden, acciones[i].cantidad_de_tiempo_requerido);          
        //}
        

    }    
    //Crear una instancia de la estructura comuna

    struct Comuna comuna;
    // Asignar valores a la estructura
    comuna.cantidad_paneles_solares = 5;
    comuna.capacidad_banco_baterias = 1000;
    comuna.area_trabajo_comun = disponible;
    comuna.area_culto = disponible;
    comuna.area_recreacion = disponible;
    comuna.area_gym = disponible;
    comuna.area_biblioteca = disponible;
    comuna.area_taller = disponible;
    comuna.area_farmacia = disponible;
    comuna.area_despensa = disponible;
    comuna.area_huerto = disponible;





switch (    comuna.cantidad_paneles_solares = 5) {
    case 1:
    while(TURN_LOOP){comuna.capacidad_banco_baterias += comuna.cantidad_paneles_solares * ENERGIA_POR_PANEL;
      break;
    }
        break;
    case 2:
        // bloque de código a ejecutar si valor == 2
        break;
    default:
        // bloque de código a ejecutar si no se cumple ningún case anterior
        break;
}
   return 0; 
}