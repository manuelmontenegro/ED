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
 * Pruebas con la clase Persona y el operador de asignación.
 */

#include "Persona.h"

int main() {
  Fecha *f1 = new Fecha(10, 1, 2010);
  Fecha *f2 = new Fecha(1, 1, 2020);

  delete f2;
  f2 = f1;

  std::cout << "f1 = " << f1 << std::endl;
  std::cout << "f2 = " << f2 << std::endl;
  delete f1;

  Persona p1("Lucía", 15, 3, 1979);
  Persona p2("Marco", 10, 10, 1990);
  Persona p3("Laura", 1, 3, 1980);

  p3 = p2 = p1;

  std::cout << "p1 = " << p1 << std::endl;
  std::cout << "p2 = " << p2 << std::endl;

  p1 = p1;

  std::cout << "p1 = " << p1 << std::endl;

  return 0;
}
