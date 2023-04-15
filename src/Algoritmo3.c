#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
    int battery = 100; // Inicializar la batería en 100
    int solarPanel = 10; // Inicializar los paneles solares en 10
    int activities[] = { 5, 8, 3, 2, 7 }; // Lista de actividades con sus respectivos pesos
    int numActivities = sizeof(activities) / sizeof(activities[0]); // Calcular la cantidad de actividades en la lista
    srand(time(NULL)); // Inicializar el generador de números aleatorios con la hora actual

    // Ciclo principal que se ejecuta cada 20 segundos
    while (1) {
        // Cargar un 10% de la batería con los paneles solares
        battery += battery * solarPanel / 100;

        // Encontrar el índice de la actividad con el valor numérico más alto
        int maxIndex = 0;
        int maxValue = activities[0];
        for (int i = 1; i < numActivities; i++) {
            if (activities[i] > maxValue) {
                maxIndex = i;
                maxValue = activities[i];
            }
        }

        // Restar el valor numérico máximo de la batería y mostrar la actividad seleccionada
        battery -= maxValue;
        printf("Batería: %d\n", battery);
        printf("Actividad seleccionada: %d\n", maxValue);

        // Quitar el valor de la actividad ya utilizada de la lista
        activities[maxIndex] = 0;

        // Si la batería llega a cero o todas las actividades han sido utilizadas, terminar el programa
        int allActivitiesUsed = 1;
        for (int i = 0; i < numActivities; i++) {
            if (activities[i] != 0) {
                allActivitiesUsed = 0;
                break;
            }
        }
        if (battery <= 0 || allActivitiesUsed) {
            printf("La batería se ha agotado o todas las actividades han sido utilizadas.\n");
            break;
        }

        // Esperar "X" cantidad de segundos antes de continuar con el ciclo
        sleep(5);
    }

    return 0;
}
