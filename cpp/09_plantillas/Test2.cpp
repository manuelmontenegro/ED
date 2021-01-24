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
 * Ejemplos con la clase genérica Complejo
 */

#include "Complejo.h"
#include <iostream>

int main() {
  Complejo<double> z1(2.0, -3.0), z2(1.0, 0.0);

  std::cout << z1 << std::endl << z2 << std::endl;

  Complejo<double> z3 = z1 + z2;
  Complejo<double> z4 = z1 * z1 + z2;

  std::cout << z3 << std::endl << z4 << std::endl;

  Complejo<int> z1ent(3, 4);
  Complejo<> zdefault(1.0, 3.0);

  return 0;
}
