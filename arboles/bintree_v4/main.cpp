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


int main() {
  BinTree<int> tree {{{ 9 }, 4, { 5 }}, 7, {{ 10 }, 4, { 6 }}};

  std::vector<int> vec;
  std::cout << "Recorrido en preorden: " << std::endl;
  tree.preorder();
  std::cout << std::endl;

  std::cout << "Recorrido en inorden: " << std::endl;
  tree.inorder();
  std::cout << std::endl;

  std::cout << "Recorrido en postorden: " << std::endl;
  tree.postorder();
  std::cout << std::endl;

  std::cout << "Recorrido por niveles: " << std::endl;
  tree.levelorder();  
  std::cout << std::endl;

  return 0;
}
