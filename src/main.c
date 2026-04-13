#include <stdio.h>
#include "../inc/alumno.h"

int main(void) {
    char cadena[256];

    alumno_t alumno = {
        .nombre = "Flor",
        .apellido = "Amaya",
        .documento = 42548553
    };

    Serializar(&alumno, cadena, sizeof(cadena));
    printf("%s\n", cadena);

    return 0;
}