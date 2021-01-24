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
 * Pruebas con el TAD doble cola
 */

#include "dequeue.h"
#include <iostream>

int main() {
  Dequeue<int> dq1;
  dq1.push_back(3);
  dq1.push_back(1);
  dq1.push_back(10);

  Dequeue<int> dq2 = dq1;

  while (!dq1.empty()) {
    std::cout << dq1.back() << " ";
    dq1.pop_back();
  }
  std::cout << std::endl;

  while (!dq2.empty()) {
    std::cout << dq2.front() << " ";
    dq2.pop_front();
  }
  std::cout << std::endl;
}
