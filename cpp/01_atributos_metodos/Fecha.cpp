/*
 * ---------------------------------------------------
 *                ESTRUCTURAS DE DATOS
 * ---------------------------------------------------
 *              Manuel Montenegro Montes
 *              Facultad de Informática
 *         Universidad Complutense de Madrid
 * ---------------------------------------------------
 */

/*
 * Implementación de las funciones de la clase Fecha
 */

#include "Fecha.h"
#include <iostream>
#include <iomanip>

void Fecha::imprimir() {
    std::cout << std::setfill('0') << std::setw(2) << dia << "/" 
              << std::setw(2) << mes << "/" 
              << std::setw(4) << anyo;
}
