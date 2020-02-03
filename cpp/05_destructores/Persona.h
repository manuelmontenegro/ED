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
 * Definición e implementación de la clase Persona.
 *
 * Ahora se guarda el atributo Fecha en el heap, y se
 * accede mediante un puntero.
 *
 * Para liberar la fecha ahora se requiere un destructor.
 */


#ifndef __PERSONA_H
#define __PERSONA_H

#include <string>
#include "Fecha.h"

class Persona {
public:
  Persona(std::string nombre, int dia, int mes, int anyo)
    : fecha_nacimiento(new Fecha(dia, mes, anyo)) { }

  ~Persona() {
    delete fecha_nacimiento;
  }
private:
  std::string nombre;
  Fecha *fecha_nacimiento;        

};

#endif