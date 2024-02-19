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
 * Uso del TAD Academia
 */

#include "academia.h"
#include <iostream>

using namespace std;

int main() {
  Academia ac;

  ac.anyadir_curso("Introducción a la rubismática", 20);
  ac.anyadir_curso("Fundamentos de pastificio", 2);
  ac.anyadir_estudiante("1", "Genaro", "Pérez");
  ac.anyadir_estudiante("2", "Santiago", "Carvajal");
  ac.anyadir_estudiante("3", "Mireia", "Casado");
  ac.matricular_en_curso("1", "Introducción a la rubismática");
  ac.matricular_en_curso("3", "Introducción a la rubismática");
  ac.matricular_en_curso("2", "Introducción a la rubismática");

  ac.matricular_en_curso("1", "Fundamentos de pastificio");

  cout << ac.plazas_libres("Introducción a la rubismática") << endl;
  for (const Estudiante &e :
       ac.estudiantes_matriculados("Introducción a la rubismática")) {
    cout << e << endl;
  }

  return 0;
}
