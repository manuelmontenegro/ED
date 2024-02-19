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
 * Definición de la clase Persona, que hace uso del constructor de la clase Fecha.
 */

#ifndef __PERSONA_H
#define __PERSONA_H

#include <string>
#include "Fecha.h"

class Persona {
public:
  Persona(std::string nombre, int dia, int mes, int anyo): fecha_nacimiento(dia, mes, anyo) {
      this->nombre = nombre;
  }
private:
  std::string nombre;
  Fecha fecha_nacimiento;        

};

#endif