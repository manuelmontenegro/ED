#include "../../catch.hpp"
#include "dequeue.h"

#include <sstream>

TEST_CASE("addition and removal on lists of strings", "Dequeue") {
  Dequeue<std::string> l;

  SECTION("dequeue is initially empty") {
    REQUIRE(l.empty());
  }

  SECTION("after adding an element, dequeue is no longer empty") {
    l.push_back("Clara");
    REQUIRE_FALSE(l.empty());
    REQUIRE(l.front() == "Clara");
    REQUIRE(l.back() == "Clara");
  }

  SECTION("adding two elements") {
    l.push_back("Clara");
    l.push_back("Adrian");
    REQUIRE_FALSE(l.empty());
    REQUIRE(l.front() == "Clara");
    REQUIRE(l.back() == "Adrian");
  }

  SECTION("adding two elements at the first position") {
    l.push_front("Clara");
    l.push_front("Adrian");
    REQUIRE_FALSE(l.empty());
    REQUIRE(l.front() == "Adrian");
    REQUIRE(l.back() == "Clara");
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

}
