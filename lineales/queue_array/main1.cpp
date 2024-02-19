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
 * Uso del TAD Cola
 */

#include "queue_array.h"
#include <iostream>

int main() {
  QueueArray<int> q;
  q.push(10);
  q.push(20);
  q.push(30);

  std::cout << q.front() << std::endl;
  q.pop();
  std::cout << q.front() << std::endl;
  q.pop();
  std::cout << q.front() << std::endl;
  q.pop();
}
