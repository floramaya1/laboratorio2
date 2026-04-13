#include <stdio.h>
#include "../inc/alumno.h"

/**
 * @brief Punto de entrada principal del programa.
 * * Este programa inicializa una estructura de tipo alumno_t, la convierte
 * a formato JSON usando la función Serializar y muestra el resultado.
 */
int main(void) {
    // Definición de un búfer de caracteres para almacenar el JSON resultante
    char cadena[256];

    // Inicialización de la estructura con datos estáticos 
    alumno_t alumno = {
        .nombre = "Florencia",
        .apellido = "Amaya",
        .documento = 42548553
    };

    /**
     * Llamada a la función de serialización.
     * Se pasa la dirección de la estructura (&alumno), el búfer de destino 
     * y su tamaño total (sizeof) para evitar desbordamientos.
     */
    if (Serializar(&alumno, cadena, sizeof(cadena)) != -1) {
        // Si la serialización fue exitosa, se imprime el string en consola
        printf("%s\n", cadena);
    } else {
        // Manejo de error en caso de que el búfer sea demasiado pequeño
        fprintf(stderr, "Error: El búfer es insuficiente para serializar los datos.\n");
    }

    return 0;
}