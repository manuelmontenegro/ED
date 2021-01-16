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


int contar_caracteres(const ListArray &l) {
  int suma = 0;
  for (int i = 0; i < l.size(); i++) {
    suma += l.at(i).length();
  }
  return suma;
}


int main() {
  ListArray l;
  l.push_back("David");
  l.push_back("Maria");
  l.push_back("Elvira");

  std::string &m = l.at(1);
  m = "Manuel";
  l.display(); std::cout << std::endl;

  std::cout << contar_caracteres(l) << std::endl;
}
