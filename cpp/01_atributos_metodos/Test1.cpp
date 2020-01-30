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
 * Ejemplo de uso de la clase Fecha.
 */


#include "Fecha.h"
#include <iostream>

int main() {
    Fecha f;
    f.set_dia(28);
    f.set_mes(8);
    f.set_anyo(2019);

    std::cout << "Fecha: ";
    f.imprimir();
    std::cout << std::endl;
}