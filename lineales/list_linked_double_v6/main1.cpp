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

// Recorrido de elementos sin iterador: coste cuadrático
int suma_elems(ListLinkedDouble<int> &l) {
  int suma = 0;
  for (int i = 0; i < l.size(); i++) {
    suma += l[i];
  }
  return suma;
}

// Recorrido de elementos con iterador: coste lineal
int suma_elems_iterator(ListLinkedDouble<int> &l) {
  int suma = 0;
  ListLinkedDouble<int>::iterator it = l.begin();
  while (it != l.end()) {
    suma += it.elem();
    it.advance();
  }
  return suma;
}

// Recorrido de elementos con iterador mediante un bucle for: coste lineal
int suma_elems_iterator_for(ListLinkedDouble<int> &l) {
  int suma = 0;
  for (ListLinkedDouble<int>::iterator it = l.begin(); it != l.end();
       it.advance()) {
    suma += it.elem();
  }
  return suma;
}

int main() {
  ListLinkedDouble<int> l;
  for (int i = 0; i < 10; i++) {
    l.push_back(i * 2);
  }

  std::cout << suma_elems_iterator_for(l) << std::endl;
  return 0;
}
