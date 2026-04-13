#include <stdio.h>
#include <string.h>
#include <stdint.h>
#include "../inc/alumno.h"

static int SerializarTexto(char * campo, char * valor, char * cadena, int disponible) {
    return snprintf(cadena, disponible, "\"%s\":\"%s\"", campo, valor);
}

static int SerializarNumero(char * campo, uint32_t valor, char * cadena, int disponible) {
    return snprintf(cadena, disponible, "\"%s\":%u", campo, valor);
}

int Serializar(const alumno_t * alumno, char * cadena, int disponible) {
    int resultado = 0;
    int escrito = 0;

    escrito = snprintf(cadena, disponible, "{");
    resultado += escrito;
    cadena += escrito;
    disponible -= escrito;

    escrito = SerializarTexto("nombre", alumno->nombre, cadena, disponible);
    resultado += escrito;
    cadena += escrito;
    disponible -= escrito;

    escrito = snprintf(cadena, disponible, ",");
    resultado += escrito;
    cadena += escrito;
    disponible -= escrito;

    escrito = SerializarTexto("apellido", alumno->apellido, cadena, disponible);
    resultado += escrito;
    cadena += escrito;
    disponible -= escrito;

    escrito = snprintf(cadena, disponible, ",");
    resultado += escrito;
    cadena += escrito;
    disponible -= escrito;

    escrito = SerializarNumero("documento", alumno->documento, cadena, disponible);
    resultado += escrito;
    cadena += escrito;
    disponible -= escrito;

    escrito = snprintf(cadena, disponible, "}");
    resultado += escrito;

    if (disponible <= 0) return -1;
    return resultado;
}