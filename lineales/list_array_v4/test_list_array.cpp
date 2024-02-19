#include "../../catch.hpp"
#include "list_array.h"

#include <sstream>

std::string list_to_string(const ListArray &l) {
  std::stringstream output;
  output << l;
  return output.str();
}

TEST_CASE("addition and removal on lists of strings", "ListArray") {
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
    REQUIRE(l[0] == "Clara");
    REQUIRE(list_to_string(l) == "[Clara]");
  }

  SECTION("adding two elements") {
    l.push_back("Clara");
    l.push_back("Adrian");
    REQUIRE_FALSE(l.empty());
    REQUIRE(l.size() == 2);
    REQUIRE(l[0] == "Clara");
    REQUIRE(l[1] == "Adrian");
    REQUIRE(list_to_string(l) == "[Clara, Adrian]");
  }

  SECTION("adding two elements at the first position") {
    l.push_front("Clara");
    l.push_front("Adrian");
    REQUIRE_FALSE(l.empty());
    REQUIRE(l.size() == 2);
    REQUIRE(l[0] == "Adrian");
    REQUIRE(l[1] == "Clara");
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
      REQUIRE( l[i] == "Element " + std::to_string(i) );
    }

  }

  SECTION("force list resize with push_front") {
    const int NUM_ELEMENTS = 1000;
    for (int i = 0; i < NUM_ELEMENTS; i++) {
      l.push_front("Element " + std::to_string(i));
    }
    REQUIRE( l.size() == NUM_ELEMENTS );

    for (int i = 0; i < NUM_ELEMENTS; i++) {
      REQUIRE( l[999 - i] == "Element " + std::to_string(i) );
    }
  }
}

TEST_CASE("update a list of strings", "ListArray") {
  ListArray l;
  l.push_back("David");
  l.push_back("Elvira");
  l.push_back("Gerardo");

  SECTION("modify the first element") {
    l.front() = "Lidia";
    REQUIRE ( l.size() == 3 );
    REQUIRE ( l[0] == "Lidia" );
    REQUIRE ( l[1] == "Elvira" );
    REQUIRE ( l[2] == "Gerardo" );
  }

  SECTION("modify the last element") {
    l.back() = "Lidia";
    REQUIRE ( l.size() == 3 );
    REQUIRE ( l[0] == "David" );
    REQUIRE ( l[1] == "Elvira" );
    REQUIRE ( l[2] == "Lidia" );
  }

  SECTION("modify the element in the middle") {
    l[1] = "Lidia";
    REQUIRE ( l.size() == 3 );
    REQUIRE ( l[0] == "David" );
    REQUIRE ( l[1] == "Lidia" );
    REQUIRE ( l[2] == "Gerardo" );
  }
}

TEST_CASE("creating copies of lists", "ListArray") {
  ListArray l;
  l.push_back("David");
  l.push_back("Elvira");
  l.push_back("Gerardo");

  ListArray l2 = l;

  SECTION("the copy contains the same elements as the original one") {
    REQUIRE ( l2.size() == 3 );
    REQUIRE ( l2[0] == "David" );
    REQUIRE ( l2[1] == "Elvira" );
    REQUIRE ( l2[2] == "Gerardo" );
  }

  SECTION("modifying copy does not affect original") {
    l2.push_back("Diana");
    l2.pop_front();
    l2[0] = "Juan";
    REQUIRE ( l.size() == 3 );
    REQUIRE ( l[0] == "David" );
    REQUIRE ( l[1] == "Elvira" );
    REQUIRE ( l[2] == "Gerardo" );
  }

  SECTION("modifying original does not affect copy") {
    l.push_back("Diana");
    l.pop_front();
    l[0] = "Juan";
    REQUIRE ( l2.size() == 3 );
    REQUIRE ( l2[0] == "David" );
    REQUIRE ( l2[1] == "Elvira" );
    REQUIRE ( l2[2] == "Gerardo" );
  }

  SECTION("create a copy of an empty list") {
    ListArray l;
    ListArray l2 = l;
    REQUIRE ( l2.size() == 0 );
    REQUIRE ( l.size() == 0 );
    l2.push_back("David");
    REQUIRE ( l2.size() == 1 );
    REQUIRE ( l.size() == 0 );
    REQUIRE ( l2.front() == "David" );
  }
}


TEST_CASE("list assignments", "ListArray") {
  ListArray l;
  l.push_back("David");
  l.push_back("Elvira");
  l.push_back("Gerardo");

  ListArray l2;

  l2 = l;

  SECTION("the copy contains the same elements as the original one") {
    REQUIRE ( l2.size() == 3 );
    REQUIRE ( l2[0] == "David" );
    REQUIRE ( l2[1] == "Elvira" );
    REQUIRE ( l2[2] == "Gerardo" );
  }

  SECTION("modifying copy does not affect original") {
    l2.push_back("Diana");
    l2.pop_front();
    l2[0] = "Juan";
    REQUIRE ( l.size() == 3 );
    REQUIRE ( l[0] == "David" );
    REQUIRE ( l[1] == "Elvira" );
    REQUIRE ( l[2] == "Gerardo" );
  }

  SECTION("modifying original does not affect copy") {
    l.push_back("Diana");
    l.pop_front();
    l[0] = "Juan";
    REQUIRE ( l2.size() == 3 );
    REQUIRE ( l2[0] == "David" );
    REQUIRE ( l2[1] == "Elvira" );
    REQUIRE ( l2[2] == "Gerardo" );
  }

  SECTION("create a copy of an empty list") {
    ListArray l;
    ListArray l2;
    l2 = l;
    REQUIRE ( l2.size() == 0 );
    REQUIRE ( l.size() == 0 );
    l2.push_back("David");
    REQUIRE ( l2.size() == 1 );
    REQUIRE ( l.size() == 0 );
    REQUIRE ( l2.front() == "David" );
  }
}
