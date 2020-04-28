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

#include <string>
#include <vector>
#include <unordered_map>
#include <set>
#include <cassert>


using Estudiante = std::string;

class Academia {
public:
  
  void anyadirCurso(const std::string &nombre, int numero_plazas) {
    assert(cursos.find(nombre) == cursos.end());
    cursos.insert({nombre, Curso(nombre, numero_plazas)});
  }

  void eliminarCurso(const std::string &nombre) {
    auto it = cursos.find(nombre);
    assert(it != cursos.end());
    cursos.erase(it);
  }

  int plazas_libres(const std::string nombre_curso) const {
    auto it = cursos.find(nombre_curso);
    assert(it != cursos.end());
    const Curso &curso = it->second;
    return curso.numero_plazas - curso.estudiantes.size();
  }

  void matricular(const Estudiante &estudiante, const std::string nombre_curso) {
    auto it_curso = cursos.find(nombre_curso);
    assert(it_curso != cursos.end());
    Curso &curso = it_curso->second;

    assert(!curso.estudiantes.contains(estudiante));
    assert(curso.numero_plazas > curso.estudiantes.size());

    curso.estudiantes.insert(estudiante);
  }

  std::vector<Estudiante> estudiantes_matriculados(const std::string &nombre_curso) const {
    auto it_curso = cursos.find(nombre_curso);
    assert(it_curso != cursos.end());
    const Curso &curso = it_curso->second;
    
    std::vector<Estudiante> result;
    copy(curso.estudiantes.begin(), curso.estudiantes.end(),
         std::back_insert_iterator<std::vector<Estudiante>>(result));
         
    return result;
  }

private:
  struct Curso {
    std::string nombre;
    int numero_plazas;

    std::set<Estudiante> estudiantes;

    Curso(const std::string &nombre, int numero_plazas): nombre(nombre), numero_plazas(numero_plazas) { }
  };

  std::unordered_map<std::string, Curso> cursos;  
};

#endif
