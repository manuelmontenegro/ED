#include "../../catch.hpp"
#include "academia.h"

TEST_CASE("Añadir estudiantes y cursos", "Academia") {

  Academia ac;
  ac.anyadir_curso("Curso 1", 2);
  ac.anyadir_curso("Curso 2", 15);
  ac.anyadir_curso("Curso 3", 10);
  ac.anyadir_estudiante("1", "Bertoldo", "Ramirez");
  ac.anyadir_estudiante("2", "Bertolda", "Perez");
  ac.anyadir_estudiante("3", "Modicio", "Distrajez");

  SECTION("Añadir un curso que ya existe debe fallar") {
    REQUIRE_THROWS_WITH(ac.anyadir_curso("Curso 1", 30), "curso ya existente");
  }

  SECTION("Añadir un estudiante que ya existe debe fallar") {
    REQUIRE_THROWS_WITH(ac.anyadir_estudiante("1", "Nadie", "Nadie"),
                        "estudiante ya existente");
  }

  SECTION("Obtener estudiantes en un curso que no existe") {
    REQUIRE_THROWS_WITH(ac.estudiantes_matriculados("Curso 0"),
                        "curso no encontrado");
  }

  SECTION("Obtener plazas en un curso que no existe") {
    REQUIRE_THROWS_WITH(ac.plazas_libres("Curso 0"), "curso no encontrado");
  }

  SECTION(
      "Obtener estudiantes y plazas en un curso que existe sin estudiantes") {
    REQUIRE(ac.plazas_libres("Curso 2") == 15);
    auto matriculados = ac.estudiantes_matriculados("Curso 2");
    REQUIRE(matriculados.empty());
  }

  SECTION("Matricular estudiantes en un curso") {
    ac.matricular_en_curso("1", "Curso 1");
    ac.matricular_en_curso("3", "Curso 1");
    auto matriculados = ac.estudiantes_matriculados("Curso 1");
    REQUIRE(matriculados.size() == 2);
    REQUIRE(ac.plazas_libres("Curso 1") == 0);
    REQUIRE(matriculados[0] == "Distrajez, Modicio");
    REQUIRE(matriculados[1] == "Ramirez, Bertoldo");
  }

  SECTION("Matricular estudiantes en varios cursos") {
    ac.matricular_en_curso("3", "Curso 1");
    std::vector<std::string> cursos = {"Curso 1", "Curso 2", "Curso 3"};
    for (const auto &c : cursos) {
      ac.matricular_en_curso("1", c);
    }

    for (const std::string &c : cursos) {
      auto matriculados = ac.estudiantes_matriculados(c);
      REQUIRE(std::binary_search(matriculados.begin(), matriculados.end(),
                                 "Ramirez, Bertoldo"));
    }

    auto cursos_est = ac.cursos_estudiante("1");
    REQUIRE(std::is_permutation(cursos_est.begin(), cursos_est.end(),
                                cursos.begin()));
  }

  SECTION("Matricular estudiantes en varios cursos y dar de baja") {
    std::vector<std::string> cursos = {"Curso 1", "Curso 2", "Curso 3"};
    for (const auto &c : cursos) {
      ac.matricular_en_curso("1", c);
    }

    int plazas_libres_antes = ac.plazas_libres("Curso 1");
    ac.dar_de_baja_en_curso("1", "Curso 1");
    int plazas_libres_despues = ac.plazas_libres("Curso 1");

    REQUIRE(plazas_libres_despues - plazas_libres_antes == 1);
    auto matriculados = ac.estudiantes_matriculados("Curso 1");
    REQUIRE(matriculados.empty());

    auto cursos_est = ac.cursos_estudiante("1");
    REQUIRE(find(cursos_est.begin(), cursos_est.end(), "Curso 1") ==
            cursos_est.end());
    REQUIRE(find(cursos_est.begin(), cursos_est.end(), "Curso 2") !=
            cursos_est.end());
    REQUIRE(find(cursos_est.begin(), cursos_est.end(), "Curso 3") !=
            cursos_est.end());
  }

  SECTION("Matricularse en curso lleno") {
    ac.matricular_en_curso("1", "Curso 1");
    ac.matricular_en_curso("2", "Curso 1");
    REQUIRE(ac.plazas_libres("Curso 1") == 0);
    ac.matricular_en_curso("3", "Curso 1");

    auto matriculados = ac.estudiantes_matriculados("Curso 1");
    REQUIRE(find(matriculados.begin(), matriculados.end(), "3") ==
            matriculados.end());

    ac.dar_de_baja_en_curso("2", "Curso 1");
    REQUIRE(ac.plazas_libres("Curso 1") == 0);

    matriculados = ac.estudiantes_matriculados("Curso 1");

    REQUIRE(find(matriculados.begin(), matriculados.end(),
                 "Ramirez, Bertoldo") != matriculados.end());
    REQUIRE(find(matriculados.begin(), matriculados.end(), "Perez, Bertolda") ==
            matriculados.end());
    REQUIRE(find(matriculados.begin(), matriculados.end(),
                 "Distrajez, Modicio") != matriculados.end());
  }
}
