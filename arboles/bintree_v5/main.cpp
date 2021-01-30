/*
 * ---------------------------------------------------
 *                ESTRUCTURAS DE DATOS
 * ---------------------------------------------------
 *              Manuel Montenegro Montes
 *              Facultad de Informática
 *         Universidad Complutense de Madrid
 * ---------------------------------------------------
 */

#include "bintree.h"
#include <iostream>
#include <sstream>

int main() {
  BinTree<int> tree{{{9}, 4, {5}}, 7, {{10}, 4, {6}}};

  // Imprimimos cada nodo que se visita
  tree.preorder([](int x) { std::cout << x << " "; });
  std::cout << std::endl;

  // Imprimimos solamente los nodos con valor par
  tree.preorder([](int x) {
    if (x % 2 == 0) {
      std::cout << x << " ";
    }
  });
  std::cout << std::endl;

  // Calculamos la suma de los valores de todos los nodos
  int acum = 0;
  tree.preorder([&acum](int x) { acum += x; });
  std::cout << acum << std::endl;

  // Calculamos el número de nodos
  int num_elems = 0;
  tree.preorder([&num_elems](int x) { num_elems++; });
  std::cout << num_elems << std::endl;

  // Almacenamos los nodos recorridos en una lista
  std::vector<int> v;
  tree.preorder([&v](int x) { v.push_back(x); });
  copy(v.begin(), v.end(), std::ostream_iterator<int>(std::cout, " "));
  std::cout << std::endl;

  return 0;
}
