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
 * TAD para gestionar horas
 */

#ifndef __HORA_H
#define __HORA_H

#include <iomanip>
#include <iostream>
#include <stdexcept>

class Hora {
public:
  Hora(int horas, int minutos, int segundos)
      : Hora(horas * 3600 + minutos * 60 + segundos) {
    if (horas < 0 || minutos < 0 || minutos >= 60 || segundos < 0 ||
        segundos >= 60) {
      throw std::domain_error("hora no válida");
    }
  }

  int horas() const { return num_segundos / 3600; }

  int minutos() const { return (num_segundos / 60) % 60; }

  int segundos() const { return num_segundos % 60; }

  Hora operator+(int segs) const { return Hora(num_segundos + segs); }

  int operator-(const Hora &otra) const {
    return num_segundos - otra.num_segundos;
  }

  Hora operator-(int segs) const { return Hora(num_segundos - segs); }

  bool operator==(const Hora &otra) const {
    return num_segundos == otra.num_segundos;
  }

  bool operator<(const Hora &otra) const {
    return num_segundos < otra.num_segundos;
  }

  void display(std::ostream &out) const {
    out << std::setw(2) << std::setfill('0') << horas() << ":" << std::setw(2)
        << std::setfill('0') << minutos() << ":" << std::setw(2)
        << std::setfill('0') << segundos();
  }

private:
  Hora(int num_segundos) : num_segundos(num_segundos) {}
  int num_segundos;
};

std::ostream &operator<<(std::ostream &out, const Hora &hora);

#endif
