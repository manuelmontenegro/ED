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

// Uso de los iteradores en el TAD Árbol binario

using namespace std;

int main() {
  BinTree<int> tree {{{ 9 }, 4, { 5 }}, 7, {{ 10 }, 4, { 6 }}};

  /*
  for (auto it = tree.begin(); it != tree.end(); ++it) {
    cout << *it << " ";
  }
  */

 for (int x: tree) {
   cout << x << " ";
 }

  return 0;
}
