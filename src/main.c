#include <funciones.h>

int main() {

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
  while (turn_loop) {
    // Sumar energía de los paneles solares a la batería
    mi_comuna.capacidad_banco_baterias += mi_comuna.cantidad_paneles_solares * energia_por_panel;

  return(0);
  }

}