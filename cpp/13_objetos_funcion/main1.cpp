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
 * Uso de una función de orden superior que elimina los elementos
 * de una lista que cumplan una determinada condición.
 */

#include "Fecha.h"

#include <algorithm>
#include <iostream>
#include <iterator>
#include <list>

bool es_par(int x) { return x % 2 == 0; }
bool es_impar(int x) { return x % 2 == 1; }
bool es_positivo(int x) { return x > 0; }

bool es_navidad(const Fecha &f) {
  return f.get_dia() == 25 && f.get_mes() == 12;
}

template <typename T, typename U>
void eliminar(std::list<U> &elems, T funcion) {
  auto it = elems.begin();
  while (it != elems.end()) {
    if (funcion(*it)) {
      it = elems.erase(it);
    } else {
      ++it;
    }
  }
}

template <typename T>
std::ostream &operator<<(std::ostream &out, std::list<T> elems) {
  out << "[";
  if (!elems.empty()) {
    auto it = elems.begin();
    out << *it;
    ++it;
    while (it != elems.end()) {
      out << ", " << *it;
      ++it;
    }
  }
  out << "]";
  return out;
}

int main() {
  std::list<int> v1 = {1, 5, 6, 9, 10, 20};
  std::list<int> v2 = v1;
  eliminar(v1, es_par);
  std::cout << v1 << std::endl;

  eliminar(v2, es_impar);
  std::cout << v2 << std::endl;

  std::list<int> v3 = {-2, 3, 10, -6, 20};
  eliminar(v3, es_positivo);
  std::cout << v3 << std::endl;

  std::list<Fecha> v4 = {
      {25, 12, 2010}, {10, 21, 2020}, {25, 12, 1900}, {1, 1, 2000}};
  eliminar(v4, es_navidad);
  std::cout << v4 << std::endl;
}
