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
 * Pruebas con el constructor de copia.
 */

#include "list_array.h"
#include <iostream>

int main() {
  ListArray l1;
  l1.push_back("David");
  l1.push_back("Maria");
  l1.push_back("Eugenio");

  ListArray l2 = l1;
  l2.front() = "Pepe";

  l1.display();
  std::cout << std::endl;
  l2.display();
  std::cout << std::endl;
}
