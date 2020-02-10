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
  Persona p1("Lucía", 15, 3, 1979);  
  Persona p2("Marco", 10, 10, 1990);
  Persona p3("Nuria", 6, 6, 2008);
  
  std::cout << "p1 = " << p1 << std::endl;
  std::cout << "p2 = " << p2 << std::endl;
  std::cout << "p3 = " << p3 << std::endl;

  p3 = p2 = p1;

  std::cout << "p1 = " << p1 << std::endl;
  std::cout << "p2 = " << p2 << std::endl;
  std::cout << "p3 = " << p3 << std::endl;

  return 0;
}

