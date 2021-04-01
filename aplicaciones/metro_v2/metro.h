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
 * TAD para gestionar líneas de metro (versión alternativa)
 */

#ifndef __METRO_H
#define __METRO_H

#include "hora.h"
#include <map>
#include <set>
#include <stdexcept>
#include <string>
#include <vector>

using Linea = std::string;
using Parada = std::string;

class Metro {
public:
  void nueva_linea(const Linea &nombre) {
    if (lineas.contains(nombre)) {
      throw std::domain_error("linea ya existente");
    }
    lineas.insert({nombre, InfoLinea(nombre)});
  }

  void nueva_parada(const Linea &nombre, const Parada &nueva_parada,
                    int tiempo_desde_anterior) {
    InfoLinea &linea = buscar_linea(nombre);
    linea.tiempo_total += tiempo_desde_anterior;
    linea.tiempos_desde_cabecera.insert({nueva_parada, linea.tiempo_total});
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
  struct InfoLinea {
    Linea nombre;
    std::set<Hora> salida_trenes;
    int tiempo_total;
    std::unordered_map<Parada, int> tiempos_desde_cabecera;

    InfoLinea(const Linea &nombre) : nombre(nombre), tiempo_total(0) {}
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
    auto it = info_linea.tiempos_desde_cabecera.find(parada);
    if (it == info_linea.tiempos_desde_cabecera.end()) {
      throw std::domain_error("parada no encontrada");
    }
    return it->second;
  }
};

#endif
