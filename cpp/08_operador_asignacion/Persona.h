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
 * Introduciendo el operador de asignación en la clase Persona.
 */

#ifndef __PERSONA_H
#define __PERSONA_H

#include "Fecha.h"
#include <string>

class Persona {
public:
  Persona(std::string nombre, int dia, int mes, int anyo)
      : nombre(nombre), fecha_nacimiento(new Fecha(dia, mes, anyo)) {}

  ~Persona() { delete fecha_nacimiento; }

  Persona(const Persona &p)
      : nombre(p.nombre), fecha_nacimiento(new Fecha(*p.fecha_nacimiento)) {}

  void set_nombre(const std::string &nombre) { this->nombre = nombre; }
  void set_fecha_nacimiento(int dia, int mes, int anyo) {
    fecha_nacimiento->set_dia(dia);
    fecha_nacimiento->set_mes(mes);
    fecha_nacimiento->set_anyo(anyo);
  }

  void imprimir(std::ostream &out) const {
    out << "[Nombre: " << nombre << ", ";
    out << "Fecha de nacimiento: " << *fecha_nacimiento << "]";
  }

  Persona &operator=(const Persona &other) {
    if (this != &other) {
      nombre = other.nombre;
      delete fecha_nacimiento;
      fecha_nacimiento = new Fecha(*other.fecha_nacimiento);
    }

    return *this;
  }

private:
  std::string nombre;
  Fecha *fecha_nacimiento;
};

std::ostream &operator<<(std::ostream &out, const Persona &p) {
  p.imprimir(out);
  return out;
}

#endif
