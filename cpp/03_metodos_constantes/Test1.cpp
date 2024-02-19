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

bool es_navidad(const Fecha &f) {
    return f.get_dia() == 25 && f.get_mes() == 12;
}

int main() {
    Fecha mi_fecha(25, 12, 2000);
    if (es_navidad(mi_fecha)) {
        std::cout << "Feliz navidad!" << std::endl;
    }
    return 0;
}
