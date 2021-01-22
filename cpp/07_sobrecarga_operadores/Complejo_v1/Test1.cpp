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
 * Pruebas con la clase Complejo.
 */

#include "Complejo.h"
#include <iostream>

int main() {
  Complejo z1(2.0, -3.0), z2(1.0, 0.0);

  z1.display();
  std::cout << std::endl;

  z2.display();
  std::cout << std::endl;

  Complejo z3 = suma(z1, z2);
  Complejo z4 = suma(multiplica(z1, z1), z2);

  z3.display();
  std::cout << std::endl;

  z4.display();
  std::cout << std::endl;

  return 0;
}
