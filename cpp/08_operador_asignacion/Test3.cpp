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
  
  std::cout << "p1 = " << p1 << std::endl;

  p1 = p1;

  std::cout << "p1 = " << p1 << std::endl;

  return 0;
}

