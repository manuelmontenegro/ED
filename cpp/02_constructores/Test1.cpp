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
 * Uso de la clase Fecha.
 */

#include "Fecha.h"
#include <iostream>

bool es_navidad(Fecha f) {
  return f.get_dia() == 25 && f.get_mes() == 12;
}

int main() {
    Fecha f = {25, 12, 2019};
    if (es_navidad(f)) {
      std::cout << "Feliz navidad!" << std::endl;
    }
    return 0;
}

    