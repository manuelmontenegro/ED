/*
 * ---------------------------------------------------
 *                ESTRUCTURAS DE DATOS
 * ---------------------------------------------------
 *              Manuel Montenegro Montes
 *              Facultad de Informática
 *         Universidad Complutense de Madrid
 * ---------------------------------------------------
 */

#include "Persona.h"

void modificar_copia(Persona p) {
  p.set_nombre("Berta");
  p.set_fecha_nacimiento(10, 10, 2010);
}

int main() {
  Persona p("David", 15, 3, 1979);
  p.imprimir();
  modificar_copia(p);
  p.imprimir();

  return 0;
}
