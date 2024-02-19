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
 *
 * Utilizamos esta función pasándole, a su vez, un objeto función.
 */

#include "Fecha.h"

#include <algorithm>
#include <iostream>
#include <iterator>
#include <list>

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

bool es_multiplo_de_dos(int x) { return x % 2 == 0; }

bool es_multiplo_de_tres(int x) { return x % 3 == 0; }

bool es_multiplo_de_cinco(int x) { return x % 5 == 0; }

bool es_multiplo_de_y(int x, int y) { return x % y == 0; }

class EsMultiploDeY {
private:
  int y;

public:
  EsMultiploDeY(int y) : y(y) {}
  bool operator()(int x) { return x % y == 0; }
};

int main() {
  // Calculamos la lista de números primos entre 1 y 100
  std::list<int> lista;
  std::list<int> primos;
  for (int i = 2; i <= 100; i++) {
    lista.push_back(i);
  }

  while (!lista.empty()) {
    primos.push_back(lista.front());
    EsMultiploDeY multiplos_de_front(lista.front());
    eliminar(lista, multiplos_de_front);
  }

  std::cout << primos << std::endl;
}
