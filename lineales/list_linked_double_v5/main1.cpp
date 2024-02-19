/*
 * ---------------------------------------------------
 *                ESTRUCTURAS DE DATOS
 * ---------------------------------------------------
 *              Manuel Montenegro Montes
 *              Facultad de Informática
 *         Universidad Complutense de Madrid
 * ---------------------------------------------------
 */

#include "list_linked_double.h"
#include <iostream>

int contar_caracteres(const ListLinkedDouble<std::string> &l) {
  int suma = 0;
  for (int i = 0; i < l.size(); i++) {
    suma += l[i].length();
  }
  return suma;
}

int main() {
  ListLinkedDouble<std::string> l;
  l.push_back("David");
  l.push_back("Maria");
  l.push_back("Elvira");

  std::string &m = l[1];
  m = "Manuel";
  std::cout << l << std::endl;

  std::cout << contar_caracteres(l) << std::endl;
}
