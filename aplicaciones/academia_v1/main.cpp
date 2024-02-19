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
 * Ejemplo de uso del TAD Academia
 */

#include "academia.h"
#include <iostream>

using namespace std;

int main() {
  Academia ac;

  ac.anyadir_curso("Introducción a la rubismática", 20);
  ac.anyadir_curso("Fundamentos de pastificio", 2);
  ac.matricular_en_curso("Genaro Pérez", "Introducción a la rubismática");
  ac.matricular_en_curso("Santiago Carvajal", "Introducción a la rubismática");
  ac.matricular_en_curso("Mireia Casado", "Introducción a la rubismática");

  ac.matricular_en_curso("Genaro Pérez", "Fundamentos de pastificio");

  cout << ac.plazas_libres("Introducción a la rubismática") << endl;
  for (const Estudiante &e :
       ac.estudiantes_matriculados("Introducción a la rubismática")) {
    cout << e << endl;
  }

  return 0;
}
