#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "parser.h"
#define MAX_PROGRAMAS 30
#define MAX_ACCIONES 30
#include <stdbool.h>

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

    //for (int i = 0; i < cantidad_acciones; i++) {

        //printf("programa: %s\n",acciones[i].programa_padre.nombre);
        //printf("orden: %d tiempo:%d\n",acciones[i].orden, acciones[i].cantidad_de_tiempo_requerido);}    
    //Crear una instancia de la estructura comuna

    struct Comuna comuna;
    // Asignar valores a la estructura
    comuna.cantidad_paneles_solares = 1;
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


int espera_en_bateria;
int tiempo_de_espera = 0;
int minutos_recorridos = 0;
int temp = 0;
int i = 0;
int veces = 0;
bool cumplido = false; // variable que indica si se ha cumplido la acción actual
printf("bateria inicial %d\n", comuna.capacidad_banco_baterias);
while (i < cantidad_acciones) {
    
    if (cumplido) { // solo actualiza el índice si se ha cumplido la acción
        i++;
        cumplido = false;
    }
    while (comuna.capacidad_banco_baterias < acciones[i].cantidad_de_bateria_requerida) {
        espera_en_bateria++;
        comuna.capacidad_banco_baterias += comuna.cantidad_paneles_solares * ENERGIA_POR_PANEL;
        printf("bateria actual: %d bateria requerida:%d\n", comuna.capacidad_banco_baterias, acciones[i].cantidad_de_bateria_requerida);
        //char nombre[20];
        //scanf("%s", nombre);
        temp++;
        tiempo_de_espera++;
        minutos_recorridos++;
    }
        printf("Se esta trabajando en accion #%d, ha durado %d tiene que llegar a %d\n",i,temp,acciones[i].cantidad_de_tiempo_requerido+espera_en_bateria);
        printf("nivel de bateria %d\n",comuna.capacidad_banco_baterias);
        //char nombre[20];
        //scanf("%s", nombre);

    if (strcmp(acciones[i].area_para_tarea, "Trabaja") == 0) {
        temp++;
        minutos_recorridos++;
        if (i != cantidad_acciones - 1) {
            tiempo_de_espera++;
        }
        if (temp == acciones[i].cantidad_de_tiempo_requerido + espera_en_bateria) {
            printf("Se termino %s\n", acciones[i].comentario);
            comuna.capacidad_banco_baterias -= acciones[i].cantidad_de_bateria_requerida;
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
            temp = 0;
            espera_en_bateria = 0;
            cumplido = true;
        }
    }
}
printf("se terminaron todas las tareas\n");
printf("se duró: %d minutos\n", minutos_recorridos);
double d = (double) tiempo_de_espera / cantidad_acciones;
printf("El tiempo de espera promedio fue : %f\n", d);
printf("bateria final %d\n", comuna.capacidad_banco_baterias);


    return 0; 
}