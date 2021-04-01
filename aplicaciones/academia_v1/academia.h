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
 * Primera implementación del TAD Academia, con operaciones
 * básicas de añadir cursos y estudiantes.
 */

#ifndef __ACADEMIA_H
#define __ACADEMIA_H

#include <cassert>
#include <set>
#include <stdexcept>
#include <string>
#include <unordered_map>
#include <vector>

using Estudiante = std::string;
using Curso = std::string;

class Academia {
public:
  void anyadir_curso(const std::string &nombre, int numero_plazas) {
    if (cursos.contains(nombre)) {
      throw std::domain_error("curso ya existente");
    }
    cursos.insert({nombre, InfoCurso(nombre, numero_plazas)});
  }

  void eliminar_curso(const Curso &curso) {
    auto it = cursos.find(curso);
    if (it != cursos.end()) {
      InfoCurso &info_curso = it->second;
      cursos.erase(it);
    }
  }

  int plazas_libres(const Curso &curso) const {
    const InfoCurso &info_curso = buscar_curso(curso);
    return info_curso.numero_plazas - info_curso.estudiantes.size();
  }

  void matricular_en_curso(const Estudiante &est, const Curso &curso) {
    InfoCurso &info_curso = buscar_curso(curso);
    if (info_curso.estudiantes.contains(est)) {
      throw std::domain_error("estudiante ya matriculado");
    }
    if (info_curso.estudiantes.size() < info_curso.numero_plazas) {
      info_curso.estudiantes.insert(est);
    } else {
      throw std::domain_error("no hay plazas disponibles");
    }
  }

  std::vector<Estudiante> estudiantes_matriculados(const Curso &curso) const {
    const InfoCurso &info_curso = buscar_curso(curso);

    std::vector<Estudiante> result;
    copy(info_curso.estudiantes.begin(), info_curso.estudiantes.end(),
         std::back_insert_iterator<std::vector<Estudiante>>(result));

    return result;
  }

private:
  struct InfoCurso {
    std::string nombre;
    int numero_plazas;

    std::set<Estudiante> estudiantes;

    InfoCurso(const std::string &nombre, int numero_plazas)
        : nombre(nombre), numero_plazas(numero_plazas) {}
  };

  const InfoCurso &buscar_curso(const Curso &nombre) const {
    auto it_curso = cursos.find(nombre);
    if (it_curso == cursos.end()) {
      throw std::domain_error("curso no encontrado");
    } else {
      return it_curso->second;
    }
  }

  InfoCurso &buscar_curso(const Curso &nombre) {
    auto it_curso = cursos.find(nombre);
    if (it_curso == cursos.end()) {
      throw std::domain_error("curso no encontrado");
    } else {
      return it_curso->second;
    }
  }

  std::unordered_map<Curso, InfoCurso> cursos;
};

#endif
