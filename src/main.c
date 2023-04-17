#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "parser.h"
#define MAX_PROGRAMAS 30
#define MAX_ACCIONES 30

/*int main() {


  */


int main(){

    Programa programas[MAX_PROGRAMAS];
    int cantidad_programas = 0;
    char nombre_de_directorio[] = "Tareas de la comuna";

    cantidad_programas = parseDirectorio(nombre_de_directorio, programas);

    if (cantidad_programas == 0) {
        printf("No se encontraron archivos en el directorio especificado.\n");
        return 1;
    }
    
    /*Imprimimos la lista de programas y sus acciones
    for (int i = 0; i < cantidad_programas; i++) {
        printf("Programa %d: %s\n", i+1, programas[i].nombre);
        printf("Acciones:\n");
        for (int j = 0; j < programas[i].cantidad_acciones; j++){
          printf("# %s\n", programas[i].acciones[j].comentario);
          if (programas[i].acciones[j].termina == 1){printf("termina\n");}
        }
        printf("\n");
    }*/

 
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

    int cantidad_acciones_total;
    Accion *itinerario = generar_lista_acciones(programas, cantidad_programas,&cantidad_acciones_total);

    printf("%d\n",cantidad_acciones_total);



     for (int i = 0; i < cantidad_acciones_total; i++) {
    printf("%s: %s\n", itinerario[i].area_para_tarea, itinerario[i].comentario);
}


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