#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <dirent.h>


#define TURN_LOOP 1
#define disponible 1
#define ocupado 0
#define ENERGIA_POR_PANEL 20

struct Comuna {
    int cantidad_paneles_solares;
    int capacidad_banco_baterias;
    int area_trabajo_comun;
    int area_culto;
    int area_recreacion;
    int area_gym;
    int area_biblioteca;
    int area_taller;
    int area_farmacia;
    int area_despensa;
    int area_huerto;
};


typedef struct {
    char area_para_tarea[50];
    int cantidad_de_tiempo_requerido;
    int cantidad_de_bateria_requerida;
    char comentario[50];
} Accion;

typedef struct {
    char nombre[50];
    Accion acciones[100];
    int cantidad_acciones;
} Programa;

