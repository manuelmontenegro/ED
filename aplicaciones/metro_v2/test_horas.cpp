#include "../../catch.hpp"

#include "hora.h"
#include <sstream>
#include <string>

std::string hora_to_str(const Hora &h) {
  std::ostringstream out;
  out << h;
  return out.str();
}

TEST_CASE("Creación de horas", "hora") {
  SECTION("Hora cero") {
    Hora h(0, 0, 0);
    REQUIRE(h.horas() == 0);
    REQUIRE(h.minutos() == 0);
    REQUIRE(h.segundos() == 0);
  }

  SECTION("Horas no válidas") {
    REQUIRE_THROWS_WITH(Hora(0, 60, 0), "hora no válida");
    REQUIRE_THROWS_WITH(Hora(-3, 0, 0), "hora no válida");
    REQUIRE_THROWS_WITH(Hora(0, -5, 0), "hora no válida");
    REQUIRE_THROWS_WITH(Hora(0, 0, 72), "hora no válida");
    REQUIRE_THROWS_WITH(Hora(0, 0, 60), "hora no válida");
    REQUIRE_THROWS_WITH(Hora(0, 0, -4), "hora no válida");
  }

  SECTION("Horas válidas") {
    Hora h1(23, 5, 16);
    REQUIRE(h1.horas() == 23);
    REQUIRE(h1.minutos() == 5);
    REQUIRE(h1.segundos() == 16);

    Hora h2(51, 59, 59);
    REQUIRE(h2.horas() == 51);
    REQUIRE(h2.minutos() == 59);
    REQUIRE(h2.segundos() == 59);
  }
}

TEST_CASE("Diferencia de horas", "hora") {
  Hora h1(0, 0, 0), h2(10, 15, 23), h3(10, 15, 25), h4(11, 00, 00),
      h5(24, 0, 0);

  SECTION("Diferencia entre todas") {
    REQUIRE(h2 - h1 == 36923);
    REQUIRE(h3 - h2 == 2);
    REQUIRE(h3 - h1 == 36923 + 2);
    REQUIRE(h4 - h3 == 2675);
    REQUIRE(h4 - h2 == 2675 + 2);
    REQUIRE(h4 - h1 == 2675 + 2 + 36923);
    REQUIRE(h5 - h1 == 86400);
  }
}

TEST_CASE("Suma de horas", "hora") {
  Hora h1(0, 0, 0), h2(10, 15, 12), h3(10, 15, 59), h4(10, 59, 59),
      h5(23, 59, 59);

  SECTION("Suma de horas") {
    REQUIRE(hora_to_str(h1 + 10) == "00:00:10");
    REQUIRE(hora_to_str(h2 + 7) == "10:15:19");
    REQUIRE(hora_to_str(h3 + 7) == "10:16:06");
    REQUIRE(hora_to_str(h4 + 1) == "11:00:00");
    REQUIRE(hora_to_str(h5 + 1) == "24:00:00");
  }
}
