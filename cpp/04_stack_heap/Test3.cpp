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
  * Arrays de objetos en el heap.
  */
  
#include "Fecha.h"

int main() {
  // 1. Array en la pila, objetos en la pila.
  Fecha fs1[3] = { {2010}, {2011}, {2012} };

  // 2. Array en la pila, objetos en el heap.
  Fecha *fs2[3];
  fs2[0] = new Fecha(2010);
  fs2[1] = new Fecha(2011);
  fs2[2] = new Fecha(2012);

  delete fs2[0];
  delete fs2[1];
  delete fs2[2];

  // 3. Arrays en el heap, objetos en el heap.
  Fecha **fs3 = new Fecha*[3];
  fs3[0] = new Fecha(2010);
  fs3[1] = new Fecha(2011);
  fs3[2] = new Fecha(2012);

  delete fs3[0];
  delete fs3[1];
  delete fs3[2];
  delete[] fs3;

  return 0;
}
