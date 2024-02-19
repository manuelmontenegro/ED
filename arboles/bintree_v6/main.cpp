/*
 * ---------------------------------------------------
 *                ESTRUCTURAS DE DATOS
 * ---------------------------------------------------
 *              Manuel Montenegro Montes
 *              Facultad de Informática
 *         Universidad Complutense de Madrid
 * ---------------------------------------------------
 */

#include <iostream>
#include <sstream>
#include "bintree.h"

// Uso de los recorridos en inorden

int main() {
  BinTree<int> tree {{{ 9 }, 4, { 5 }}, 7, {{ 10 }, 4, { 6 }}};

  tree.inorder([] (int x) { std::cout << x << " "; });
  std::cout << std::endl;
  
  tree.inorder([] (int x) { 
    if (x % 2 == 0) {
      std::cout << x << " "; 
    }
  });
  std::cout << std::endl;

  int acum = 0;
  tree.inorder([&acum](int x) { acum += x; });
  std::cout << acum << std::endl;

  int num_elems = 0;
  tree.inorder([&num_elems](int x) { num_elems++; });
  std::cout << num_elems << std::endl;

  std::vector<int> v;
  tree.inorder([&v](int x) { v.push_back(x); });
  copy(v.begin(), v.end(), std::ostream_iterator<int>(std::cout, " "));
  std::cout << std::endl;

  return 0;
}
