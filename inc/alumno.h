#ifndef ALUMNO_H //!guardas
#define ALUMNO_H

#include <stdint.h>

//! Estructura con los datos personales de un alumno
typedef struct {
    char * nombre;      //!< Nombre del alumno
    char * apellido;    //!< Apellido del alumno
    uint32_t documento; //!< Número de documento del alumno
} alumno_t;

//! Serializa los datos del alumno en formato JSON
int Serializar(const alumno_t * alumno, char * cadena, int disponible);
/*!
 * @brief Serializa los datos del alumno en formato JSON
 * @param alumno Puntero constante a la estructura con los datos del alumno
 * @param cadena Cadena donde se escribe el resultado
 * @param disponible Cantidad de bytes disponibles en la cadena
 * @return Longitud de la cadena generada, o -1 si el espacio no es suficiente
 */

#endif  //!las guardas son para que el archivo no se incluya varias veces?, por si tengo repetido, para no tener problemas.
