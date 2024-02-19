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
 * Uso de iteradores constantes.
 */

#include "list_linked_double.h"
#include <iostream>

int suma_elems(ListLinkedDouble<int> &l) {
  int suma = 0;
  for (int i = 0; i < l.size(); i++) {
    suma += l[i];
  }
  return suma;
}

int suma_elems_iterator(const ListLinkedDouble<int> &l) {
  int suma = 0;
  for (ListLinkedDouble<int>::const_iterator it = l.cbegin(); it != l.cend();
       it.advance()) {
    suma += it.elem();
  }
  return suma;
}

void mult_by_two(ListLinkedDouble<int> &l) {
  for (ListLinkedDouble<int>::iterator it = l.begin(); it != l.end();
       it.advance()) {
    it.elem() *= 2;
  }
}

int main() {
  ListLinkedDouble<int> l;
  for (int i = 0; i < 10; i++) {
    l.push_back(i);
  }

  mult_by_two(l);

  std::cout << suma_elems_iterator(l) << std::endl;
  return 0;
}
