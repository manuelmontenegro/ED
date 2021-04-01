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
 * TAD para gestionar líneas de metro (versión inicial)
 */

#ifndef __METRO_H
#define __METRO_H

#include "hora.h"
#include <list>
#include <map>
#include <set>
#include <stdexcept>
#include <string>

using Linea = std::string;
using Parada = std::string;

class Metro {
public:
  Metro() {}
  void nueva_linea(const Linea &nombre) {
    if (lineas.contains(nombre)) {
      throw std::domain_error("linea ya existente");
    }
    lineas.insert({nombre, InfoLinea(nombre)});
  }

  void nueva_parada(const Linea &nombre, const Parada &nueva_parada,
                    int tiempo_desde_anterior) {
    InfoLinea &linea = buscar_linea(nombre);
    linea.paradas.push_back(InfoParada(nueva_parada, tiempo_desde_anterior));
  }

  void nuevo_tren(const Linea &nombre, const Hora &hora_salida) {
    InfoLinea &linea = buscar_linea(nombre);
    linea.salida_trenes.insert(hora_salida);
  }

  int numero_trenes(const Linea &nombre) const {
    const InfoLinea &linea = buscar_linea(nombre);
    return linea.salida_trenes.size();
  }

  int tiempo_proximo_tren(const Linea &linea, const Parada &parada,
                          const Hora &hora_actual) {
    const InfoLinea &info_linea = buscar_linea(linea);
    int segs_desde_cabecera = buscar_parada(info_linea, parada);
    Hora hora_salida = hora_actual - segs_desde_cabecera;

    auto it = info_linea.salida_trenes.lower_bound(hora_salida);
    if (it == info_linea.salida_trenes.end()) {
      return -1;
    }

    const Hora &hora_salida_siguiente = *it;
    const Hora &hora_parada_siguiente =
        hora_salida_siguiente + segs_desde_cabecera;
    return hora_parada_siguiente - hora_actual;
  }

private:
  struct InfoParada {
    Parada nombre;
    int tiempo_desde_anterior;

    InfoParada(const Parada &nombre, int tiempo_desde_anterior)
        : nombre(nombre), tiempo_desde_anterior(tiempo_desde_anterior) {}
  };

  struct InfoLinea {
    Linea nombre;
    std::set<Hora> salida_trenes;
    std::list<InfoParada> paradas;

    InfoLinea(const Linea &nombre) : nombre(nombre) {}
  };

  std::unordered_map<Linea, InfoLinea> lineas;

  const InfoLinea &buscar_linea(const Linea &linea) const {
    auto it = lineas.find(linea);
    if (it == lineas.end()) {
      throw std::domain_error("línea no encontrada");
    }
    return it->second;
  }

  InfoLinea &buscar_linea(const Linea &linea) {
    auto it = lineas.find(linea);
    if (it == lineas.end()) {
      throw std::domain_error("línea no encontrada");
    }
    return it->second;
  }

  int buscar_parada(const InfoLinea &info_linea, const Parada &parada) {
    int segs_desde_cabecera = 0;
    auto it = info_linea.paradas.begin();
    while (it != info_linea.paradas.end() && it->nombre != parada) {
      segs_desde_cabecera += it->tiempo_desde_anterior;
      ++it;
    }

    if (it == info_linea.paradas.end()) {
      throw std::domain_error("parada no encontrada");
    }

    segs_desde_cabecera += it->tiempo_desde_anterior;

    return segs_desde_cabecera;
  }
};

#endif
