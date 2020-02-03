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
 * Batería de tests para el TAD Lista
 */
 
#include "../../catch.hpp"
#include "list_array.h"

#include <sstream>

std::string list_to_string(const ListArray &l) {
  std::stringstream output;
  l.display(output);
  return output.str();
}

TEST_CASE("operations on lists of strings", "ListArray") {
  ListArray l;

  SECTION("list is initially empty") {
    REQUIRE(l.empty());
    REQUIRE(l.size() == 0);
    REQUIRE(list_to_string(l) == "[]");
  }

  SECTION("after adding an element, list is no longer empty") {
    l.push_back("Clara");
    REQUIRE_FALSE(l.empty());
    REQUIRE(l.size() == 1);
    REQUIRE(l.at(0) == "Clara");
    REQUIRE(list_to_string(l) == "[Clara]");
  }

  SECTION("adding two elements") {
    l.push_back("Clara");
    l.push_back("Adrian");
    REQUIRE_FALSE(l.empty());
    REQUIRE(l.size() == 2);
    REQUIRE(l.at(0) == "Clara");
    REQUIRE(l.at(1) == "Adrian");
    REQUIRE(list_to_string(l) == "[Clara, Adrian]");
  }

  SECTION("adding two elements at the first position") {
    l.push_front("Clara");
    l.push_front("Adrian");
    REQUIRE_FALSE(l.empty());
    REQUIRE(l.size() == 2);
    REQUIRE(l.at(0) == "Adrian");
    REQUIRE(l.at(1) == "Clara");
    REQUIRE(list_to_string(l) == "[Adrian, Clara]");
  }

  SECTION("adding elements at back, then removing them from back") {
    l.push_back("Clara");
    l.push_back("Adrian");
    REQUIRE( l.back() == "Adrian" );
    l.pop_back();
    REQUIRE( l.back() == "Clara" );
    l.pop_back();
    REQUIRE( l.empty() );
  }

  SECTION("adding elements at back, then removing them from front") {
    l.push_back("Clara");
    l.push_back("Adrian");
    REQUIRE( l.front() == "Clara" );
    l.pop_front();
    REQUIRE( l.front() == "Adrian" );
    l.pop_front();
    REQUIRE( l.empty() );
  }

  SECTION("adding elements at front, then removing them from back") {
    l.push_front("Clara");
    l.push_front("Adrian");
    REQUIRE( l.back() == "Clara" );
    l.pop_back();
    REQUIRE( l.back() == "Adrian" );
    l.pop_back();
    REQUIRE( l.empty() );
  }

  SECTION("adding elements at front, then removing them from front") {
    l.push_front("Clara");
    l.push_front("Adrian");
    REQUIRE( l.front() == "Adrian" );
    l.pop_front();
    REQUIRE( l.front() == "Clara" );
    l.pop_front();
    REQUIRE( l.empty() );
  }

  SECTION("force list resize with push_back") {
    const int NUM_ELEMENTS = 1000;
    for (int i = 0; i < NUM_ELEMENTS; i++) {
      l.push_back("Element " + std::to_string(i));
    }
    REQUIRE( l.size() == NUM_ELEMENTS );

    for (int i = 0; i < NUM_ELEMENTS; i++) {
      REQUIRE( l.at(i) == "Element " + std::to_string(i) );
    }

  }

  SECTION("force list resize with push_front") {
    const int NUM_ELEMENTS = 1000;
    for (int i = 0; i < NUM_ELEMENTS; i++) {
      l.push_front("Element " + std::to_string(i));
    }
    REQUIRE( l.size() == NUM_ELEMENTS );

    for (int i = 0; i < NUM_ELEMENTS; i++) {
      REQUIRE( l.at(999 - i) == "Element " + std::to_string(i) );
    }

  }
}

