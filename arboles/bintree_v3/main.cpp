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
#include <utility>

// Coste lineal con respecto al número de nodos de tree.
template <typename T> int height(const BinTree<T> &tree) {
  if (tree.empty()) {
    return 0;
  } else {
    return 1 + std::max(height(tree.left()), height(tree.right()));
  }
}

// Coste cuadrático con respecto al número de nodos de tree.
template <typename T> bool balanced_naive(const BinTree<T> &tree) {
  if (tree.empty()) {
    return true;
  } else {
    bool bal_left = balanced(tree.left());
    bool bal_right = balanced(tree.right());
    int height_left = height(tree.left());
    int height_right = height(tree.right());
    return bal_left && bal_right && abs(height_left - height_right) <= 1;
  }
}

// Coste lineal con respecto al número de nodos de tree.
template <typename T> bool balanced(const BinTree<T> &tree) {
  return balanced_height(tree).first;
}

template <typename T>
std::pair<bool, int> balanced_height(const BinTree<T> &tree) {
  if (tree.empty()) {
    return {true, 0};
  } else {
    auto [bal_left, height_left] = balanced_height(tree.left());
    auto [bal_right, height_right] = balanced_height(tree.right());
    bool balanced =
        bal_left && bal_right && abs(height_left - height_right) <= 1;
    int height = 1 + std::max(height_left, height_right);
    return {balanced, height};
  }
}

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

  std::cout << "Altura de 'tree': " << height(tree) << std::endl;
  std::cout << "Altura de 'other': " << height(other) << std::endl;
  std::cout << "Altura de 't1': " << height(t1) << std::endl;
  std::cout << "Altura de 't2': " << height(t2) << std::endl;
  std::cout << "Altura de 'comun': " << height(comun) << std::endl;

  std::cout << "¿Está 'tree' equilibrado? " << balanced(tree) << std::endl;
  std::cout << "¿Está 'other' equilibrado? " << balanced(other) << std::endl;
  std::cout << "¿Está 't1' equilibrado? " << balanced(t1) << std::endl;
  std::cout << "¿Está 't2' equilibrado? " << balanced(t2) << std::endl;
  std::cout << "¿Está 'comun' equilibrado? " << balanced(comun) << std::endl;

  return 0;
}
