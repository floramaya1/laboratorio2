#include <stdio.h>
#include <string.h>
#include <stdint.h>
#include "../inc/alumno.h"

/**
 * @brief Serializa un par clave-valor de tipo texto en formato JSON.
 * * @param campo Nombre del campo (clave).
 * @param valor Valor de cadena asociado.
 * @param cadena Puntero al destino donde se escribirá.
 * @param disponible Espacio restante en el búfer.
 * @return Número de caracteres que se habrían escrito.
 */
static int SerializarTexto(char * campo, char * valor, char * cadena, int disponible) {
    return snprintf(cadena, disponible, "\"%s\":\"%s\"", campo, valor);
}

/**
 * @brief Serializa un par clave-valor de tipo numérico en formato JSON.
 */
static int SerializarNumero(char * campo, uint32_t valor, char * cadena, int disponible) {
    return snprintf(cadena, disponible, "\"%s\":%u", campo, valor);
}

/**
 * @brief Convierte una estructura de tipo alumno_t a una cadena JSON.
 * * @param alumno Puntero a la estructura de datos de origen.
 * @param cadena Búfer de destino para el string resultante.
 * @param disponible Tamaño total del búfer de destino.
 * @return int Total de caracteres escritos o -1 si el búfer fue insuficiente.
 */
int Serializar(const alumno_t * alumno, char * cadena, int disponible) {
    int resultado = 0; // Acumulador del total de caracteres escritos
    int escrito = 0;   // Caracteres escritos en cada paso individual

    // Apertura del objeto JSON
    escrito = snprintf(cadena, disponible, "{");
    resultado += escrito;
    cadena += escrito;      // Desplaza el puntero a la nueva posición de escritura
    disponible -= escrito;  // Reduce el espacio disponible en el búfer

    // Serialización del campo "nombre"
    escrito = SerializarTexto("nombre", alumno->nombre, cadena, disponible);
    resultado += escrito;
    cadena += escrito;
    disponible -= escrito;

    // Separador entre campos
    escrito = snprintf(cadena, disponible, ",");
    resultado += escrito;
    cadena += escrito;
    disponible -= escrito;

    // Serialización del campo "apellido"
    escrito = SerializarTexto("apellido", alumno->apellido, cadena, disponible);
    resultado += escrito;
    cadena += escrito;
    disponible -= escrito;

    // Separador entre campos
    escrito = snprintf(cadena, disponible, ",");
    resultado += escrito;
    cadena += escrito;
    disponible -= escrito;

    // Serialización del campo "documento" (numérico)
    escrito = SerializarNumero("documento", alumno->documento, cadena, disponible);
    resultado += escrito;
    cadena += escrito;
    disponible -= escrito;

    // Cierre del objeto JSON
    escrito = snprintf(cadena, disponible, "}");
    resultado += escrito;

    // Verificación de desbordamiento: si el disponible es <= 0, el JSON quedó trunco
    if (disponible <= 0) return -1;
    
    return resultado;
}