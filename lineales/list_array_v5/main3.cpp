/*
 * ---------------------------------------------------
 *                ESTRUCTURAS DE DATOS
 * ---------------------------------------------------
 *              Manuel Montenegro Montes
 *              Facultad de Informática
 *         Universidad Complutense de Madrid
 * ---------------------------------------------------
 */

#include "list_array.h"
#include <iostream>

int main() {
  ListArray<std::string> l1;
  l1.push_back("David");
  l1.push_back("Maria");
  l1.push_back("Eugenio");

  ListArray<std::string> l2 = l1;
  l2.front() = "Pepe";

  std::cout << l1 << std::endl;
  std::cout << l2 << std::endl;
}
