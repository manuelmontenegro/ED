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
 * Segunda implementación del TAD Academia, que añade el
 * registro de estudiantes en la academia.
 */

#ifndef __ACADEMIA_H
#define __ACADEMIA_H

#include <algorithm>
#include <cassert>
#include <iterator>
#include <set>
#include <stdexcept>
#include <string>
#include <unordered_map>
#include <unordered_set>
#include <vector>

using Estudiante = std::string;
using Curso = std::string;

class Academia {
public:
  Academia() {}

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
      for (Estudiante id_est : info_curso.estudiantes) {
        estudiantes.at(id_est).cursos.erase(curso);
      }
      cursos.erase(it);
    }
  }

  void anyadir_estudiante(const Estudiante &id_est, const std::string &nombre,
                          const std::string &apellidos) {
    if (estudiantes.contains(id_est)) {
      throw std::domain_error("estudiante ya existente");
    }
    estudiantes.insert({id_est, InfoEstudiante(id_est, nombre, apellidos)});
  }

  int plazas_libres(const Curso &curso) {
    const InfoCurso &info_curso = buscar_curso(curso);
    return info_curso.numero_plazas - info_curso.estudiantes.size();
  }

  void matricular_en_curso(const Estudiante &est, const Curso &curso) {
    InfoCurso &info_curso = buscar_curso(curso);
    InfoEstudiante &info_est = buscar_estudiante(est);
    if (info_curso.estudiantes.contains(est)) {
      throw std::domain_error("estudiante ya matriculado");
    }
    if (info_curso.estudiantes.size() < info_curso.numero_plazas) {
      info_curso.estudiantes.insert(est);
      info_est.cursos.insert(curso);
    } else {
      throw std::domain_error("no hay plazas disponibles");
    }
  }

  std::vector<std::string> estudiantes_matriculados(const Curso &curso) const {
    const InfoCurso &info_curso = buscar_curso(curso);

    std::vector<std::string> result;

    for (const Estudiante &id_est : info_curso.estudiantes) {
      const InfoEstudiante &info_est = estudiantes.at(id_est);
      result.push_back(info_est.apellidos + ", " + info_est.nombre);
    }

    std::sort(result.begin(), result.end());
    return result;
  }

  std::vector<std::string> cursos_estudiante(const Estudiante &id_est) const {
    const InfoEstudiante &info_est = buscar_estudiante(id_est);
    std::vector<std::string> result;

    std::copy(info_est.cursos.begin(), info_est.cursos.end(),
              std::back_insert_iterator<std::vector<std::string>>(result));
    std::sort(result.begin(), result.end());

    return result;
  }

private:
  struct InfoCurso {

    std::string nombre;
    int numero_plazas;
    std::unordered_set<Estudiante> estudiantes;

    InfoCurso(const std::string &nombre, int numero_plazas)
        : nombre(nombre), numero_plazas(numero_plazas) {}
  };

  struct InfoEstudiante {
    Estudiante id_est;
    std::string nombre;
    std::string apellidos;

    std::set<std::string> cursos;

    InfoEstudiante(const Estudiante &id_est, const std::string &nombre,
                   const std::string &apellidos)
        : id_est(id_est), nombre(nombre), apellidos(apellidos) {}
  };

  const InfoEstudiante &buscar_estudiante(const std::string id_est) const {
    auto it_estudiante = estudiantes.find(id_est);
    if (it_estudiante == estudiantes.end()) {
      throw std::domain_error("estudiante no encontrado");
    } else {
      return it_estudiante->second;
    }
  }

  InfoEstudiante &buscar_estudiante(const std::string id_est) {
    auto it_estudiante = estudiantes.find(id_est);
    if (it_estudiante == estudiantes.end()) {
      throw std::domain_error("estudiante no encontrado");
    } else {
      return it_estudiante->second;
    }
  }

  const InfoCurso &buscar_curso(const std::string nombre) const {
    auto it_curso = cursos.find(nombre);
    if (it_curso == cursos.end()) {
      throw std::domain_error("curso no encontrado");
    } else {
      return it_curso->second;
    }
  }

  InfoCurso &buscar_curso(const std::string nombre) {
    auto it_curso = cursos.find(nombre);
    if (it_curso == cursos.end()) {
      throw std::domain_error("curso no encontrado");
    } else {
      return it_curso->second;
    }
  }

  std::unordered_map<Curso, InfoCurso> cursos;
  std::unordered_map<Estudiante, InfoEstudiante> estudiantes;
};

#endif
