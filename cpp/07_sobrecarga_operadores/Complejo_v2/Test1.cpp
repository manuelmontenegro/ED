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
 * Pruebas con los operadores de la clase Complejo.
 */

#include "Complejo.h"
#include <iostream>

int main() {
  Complejo z1(2.0, -3.0), z2(1.0);

  std::cout << z1 << std::endl << z2 << std::endl;

  Complejo z3 = z1 + z2;
  Complejo z4 = z1 * z1;

  std::cout << z3 << std::endl << z4 << std::endl;

  return 0;
}
