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
  BinTree<std::string> tree = {{"3"}, "+", {{"9"}, "*", {"7 "}}};
  std::cout << tree << std::endl;

  std::istringstream istr("(((. 9 .) + (. 5 .)) * ((. 10 .) + (. 6 .)))");
  BinTree<std::string> other = read_tree<std::string>(istr);
  std::cout << other << std::endl;

  BinTree<int> comun = {{7}, 3, {9}};
  BinTree<int> t1 = {{}, 5, comun};
  BinTree<int> t2 = {comun, 4, {8}};

  std::cout << t1 << std::endl;
  std::cout << t2 << std::endl;

  return 0;
}

// (((. 9 .) + (. 5 .)) * ((. 10 .) + (. 6 .)))
