#include "../../catch.hpp"
#include "metro.h"

TEST_CASE("Añadir lineas de metro", "Metro") {
  Metro m;

  SECTION("Añadir varias líneas", "Metro") {
    m.nueva_linea("1");
    m.nueva_linea("2");
    m.nueva_linea("5");
  }

  SECTION("Añadir una línea que existe debe fallar", "Metro") {
    m.nueva_linea("1");
    m.nueva_linea("2");
    m.nueva_linea("5");
    REQUIRE_THROWS_WITH(m.nueva_linea("2"), "linea ya existente");
  }
}

TEST_CASE("Añadir paradas a una línea de metro", "Metro") {
  Metro m;
  m.nueva_linea("1");
  m.nueva_linea("2");

  SECTION("Inicialmente no hay trenes en ninguna línea") {
    REQUIRE(m.numero_trenes("1") == 0);
    REQUIRE(m.numero_trenes("2") == 0);
  }

  SECTION("Añadimos tres trenes") {
    m.nuevo_tren("1", {10, 0, 0});
    m.nuevo_tren("1", {10, 30, 0});
    m.nuevo_tren("2", {10, 0, 0});
    REQUIRE(m.numero_trenes("1") == 2);
    REQUIRE(m.numero_trenes("2") == 1);
  }

  SECTION("Consulta de líneas que no existen") {
    REQUIRE_THROWS_WITH(m.numero_trenes("3"), "línea no encontrada");
  }

  SECTION("Añadimos trenes duplicados") {
    m.nuevo_tren("1", {10, 0, 0});
    m.nuevo_tren("1", {10, 30, 0});
    m.nuevo_tren("1", {10, 0, 0});
    REQUIRE(m.numero_trenes("1") == 2);
  }
}

TEST_CASE("Tiempo de espera") {
  Metro m;
  m.nueva_linea("1");
  m.nueva_parada("1", "Parada 1", 0);
  m.nueva_parada("1", "Parada 2", 60);
  m.nueva_parada("1", "Parada 3", 120);
  m.nueva_parada("1", "Parada 4", 120);
  m.nueva_parada("1", "Parada 5", 120);
  m.nuevo_tren("1", {10, 0, 0});
  m.nuevo_tren("1", {10, 10, 0});
  m.nuevo_tren("1", {10, 15, 0});

  SECTION("Tiempos en parada 1") {
    REQUIRE(m.tiempo_proximo_tren("1", "Parada 1", {9, 59, 30}) == 30);
    REQUIRE(m.tiempo_proximo_tren("1", "Parada 1", {10, 0, 0}) == 0);
    REQUIRE(m.tiempo_proximo_tren("1", "Parada 1", {10, 0, 1}) == 10 * 60 - 1);
    REQUIRE(m.tiempo_proximo_tren("1", "Parada 1", {10, 9, 0}) == 60);
    REQUIRE(m.tiempo_proximo_tren("1", "Parada 1", {10, 10, 0}) == 0);
    REQUIRE(m.tiempo_proximo_tren("1", "Parada 1", {10, 10, 1}) == 5 * 60 - 1);
    REQUIRE(m.tiempo_proximo_tren("1", "Parada 1", {10, 15, 0}) == 0);
    REQUIRE(m.tiempo_proximo_tren("1", "Parada 1", {10, 15, 1}) == -1);
  }

  SECTION("Tiempos en parada 2") {
    REQUIRE(m.tiempo_proximo_tren("1", "Parada 2", {10, 0, 30}) == 30);
    REQUIRE(m.tiempo_proximo_tren("1", "Parada 2", {10, 1, 0}) == 0);
    REQUIRE(m.tiempo_proximo_tren("1", "Parada 2", {10, 1, 1}) == 10 * 60 - 1);
    REQUIRE(m.tiempo_proximo_tren("1", "Parada 2", {10, 10, 0}) == 60);
    REQUIRE(m.tiempo_proximo_tren("1", "Parada 2", {10, 11, 0}) == 0);
    REQUIRE(m.tiempo_proximo_tren("1", "Parada 2", {10, 11, 1}) == 5 * 60 - 1);
    REQUIRE(m.tiempo_proximo_tren("1", "Parada 2", {10, 16, 0}) == 0);
    REQUIRE(m.tiempo_proximo_tren("1", "Parada 2", {10, 16, 1}) == -1);
  }

  SECTION("Tiempos en parada 3") {
    REQUIRE(m.tiempo_proximo_tren("1", "Parada 3", {10, 2, 30}) == 30);
    REQUIRE(m.tiempo_proximo_tren("1", "Parada 3", {10, 3, 0}) == 0);
    REQUIRE(m.tiempo_proximo_tren("1", "Parada 3", {10, 3, 1}) == 10 * 60 - 1);
    REQUIRE(m.tiempo_proximo_tren("1", "Parada 3", {10, 12, 0}) == 60);
    REQUIRE(m.tiempo_proximo_tren("1", "Parada 3", {10, 13, 0}) == 0);
    REQUIRE(m.tiempo_proximo_tren("1", "Parada 3", {10, 13, 1}) == 5 * 60 - 1);
    REQUIRE(m.tiempo_proximo_tren("1", "Parada 3", {10, 18, 0}) == 0);
    REQUIRE(m.tiempo_proximo_tren("1", "Parada 3", {10, 18, 1}) == -1);
  }

  SECTION("Tiempos en línea inexistente") {
    REQUIRE_THROWS_WITH(m.tiempo_proximo_tren("2", "Falsa", {0, 0, 0}),
                        "línea no encontrada");
  }

  SECTION("Tiempos en parada inexistente") {
    REQUIRE_THROWS_WITH(m.tiempo_proximo_tren("1", "Falsa", {0, 0, 0}),
                        "parada no encontrada");
  }
}
