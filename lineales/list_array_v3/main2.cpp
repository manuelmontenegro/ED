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
 * Este programa provoca un error en tiempo de ejecución,
 * al intentar modificar una referencia que queda invalidada
 * tras haber movido los elementos del vector de un array
 * a otro más grande.
 */

#include "list_array.h"
#include <iostream>

int main() {
  ListArray l(3);
  l.push_back("Javier");
  l.push_back("Simona");
  l.push_back("Jerry");

  std::string &javier = l.at(0);

  l.push_back("David");

  javier = "Javier Francisco";

  return 0;
}
