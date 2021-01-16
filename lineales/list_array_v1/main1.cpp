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
 * Pruebas con el TAD Lista
 */

#include <iostream>
#include "list_array.h"

int main() {
  ListArray l;
  l.push_back("David");
  l.push_back("Maria");
  l.push_back("Elvira");

  l.display(); std::cout << std::endl;

  std::cout << "Elemento 1: " << l.at(1) << std::endl;

  l.pop_front();
  l.display(); std::cout << std::endl;

  return 0;
}
