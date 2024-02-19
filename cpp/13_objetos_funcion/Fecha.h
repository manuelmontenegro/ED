/*
 * ---------------------------------------------------
 *                ESTRUCTURAS DE DATOS
 * ---------------------------------------------------
 *              Manuel Montenegro Montes
 *              Facultad de Informática
 *         Universidad Complutense de Madrid
 * ---------------------------------------------------
 */

#ifndef __FECHA_H
#define __FECHA_H

#include "Fecha.h"
#include <iomanip>
#include <iostream>

class Fecha {
public:
  Fecha(int dia, int mes, int anyo) : dia(dia), mes(mes), anyo(anyo) {}
  Fecha(int anyo) : Fecha(1, 1, anyo) {}
  Fecha() : Fecha(1, 1, 1900) {}

  Fecha(const Fecha &otra) : dia(otra.dia), mes(otra.mes), anyo(otra.anyo) {}

  int get_dia() const { return dia; }
  void set_dia(int dia) { this->dia = dia; }
  int get_mes() const { return mes; }
  void set_mes(int mes) { this->mes = mes; }
  int get_anyo() const { return anyo; }
  void set_anyo(int anyo) { this->anyo = anyo; }

  void imprimir(std::ostream &out) const;

private:
  int dia;
  int mes;
  int anyo;
};

void Fecha::imprimir(std::ostream &out) const {
  std::cout << std::setfill('0') << std::setw(2) << dia << "/" << std::setw(2)
            << mes << "/" << std::setw(4) << anyo;
}

std::ostream &operator<<(std::ostream &out, const Fecha &f) {
  f.imprimir(out);
  return out;
}

#endif
