#include <stdio.h>

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

struct Accion {
    char area_para_tarea[50];
    int cantidad_de_tiempo_requerido;
    int cantidad_de_bateria_requerida;
    char comentario[50];
};




struct Programa {

};

