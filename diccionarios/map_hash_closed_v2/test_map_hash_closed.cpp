#include "../../catch.hpp"
#include "map_hash_closed.h"

TEST_CASE("empty maps", "MapHash") {
  MapHash<std::string, int> map;

  SECTION("Map has no entries initially") {
    REQUIRE(map.empty());
    REQUIRE(map.size() == 0);
  }

  SECTION("After adding one element, it is no longer empty") {
    map.insert({"A", 10});
    REQUIRE_FALSE(map.empty());
    REQUIRE(map.size() != 0);
  }

  SECTION("After adding one element and removing it, map is empty again") {
    map.insert({"A", 10});
    map.erase("A");
    REQUIRE(map.empty());
    REQUIRE(map.size() == 0);
  }
}

TEST_CASE("nonempty maps", "MapHash") {
  MapHash<std::string, int> map;
  map.insert({"A", 10});
  map.insert({"B", 20});
  map.insert({"C", 30});

  SECTION("Map is not empty") {
    REQUIRE_FALSE(map.empty());
    REQUIRE(map.size() == 3);
  }

  SECTION("Accessing elements in the map") {
    REQUIRE(map.contains("A"));
    REQUIRE(map.at("A") == 10);
    REQUIRE(map.contains("B"));
    REQUIRE(map.at("B") == 20);
    REQUIRE(map.contains("C"));
    REQUIRE(map.at("C") == 30);
  }

  SECTION("Checking that the following elements are not in the map") {
    REQUIRE_FALSE(map.contains(""));
    REQUIRE_FALSE(map.contains("AA"));
    REQUIRE_FALSE(map.contains("D"));
    REQUIRE_FALSE(map.contains("BB"));
  }

  SECTION("After removing one element, it is no longer in the map") {
    map.erase("A");
    REQUIRE(map.size() == 2);
    REQUIRE_FALSE(map.contains("A"));
    REQUIRE(map.contains("B"));
    REQUIRE(map.contains("C"));
    REQUIRE(map.at("B") == 20);
    REQUIRE(map.at("C") == 30);
  }

  SECTION("After removing two elements, they are no longer in the map") {
    map.erase("A");
    map.erase("C");
    REQUIRE(map.size() == 1);
    REQUIRE_FALSE(map.contains("A"));
    REQUIRE(map.contains("B"));
    REQUIRE_FALSE(map.contains("C"));
    REQUIRE(map.at("B") == 20);
  }  

  SECTION("After removing three elements, map is empty") {
    map.erase("A");
    map.erase("C");
    map.erase("B");
    REQUIRE(map.empty());
    REQUIRE(map.size() == 0);
    REQUIRE_FALSE(map.contains("A"));
    REQUIRE_FALSE(map.contains("B"));
    REQUIRE_FALSE(map.contains("C"));
  }    

  SECTION("After removing two elements and adding one of them ...") {
    map.erase("A");
    map.erase("C");
    map.insert({"A", 15});
    REQUIRE(map.size() == 2);
    REQUIRE(map.contains("A"));
    REQUIRE(map.contains("B"));
    REQUIRE_FALSE(map.contains("C"));
    REQUIRE(map.at("A") == 15);
    REQUIRE(map.at("B") == 20);
  }    

  SECTION("After removing two elements and adding one of them, and another unrelated") {
    map.erase("A");
    map.insert({"D", 14});
    map.erase("C");
    map.insert({"A", 15});
    REQUIRE(map.size() == 3);
    REQUIRE(map.contains("A"));
    REQUIRE(map.contains("B"));
    REQUIRE_FALSE(map.contains("C"));
    REQUIRE(map.contains("D"));
    REQUIRE(map.at("A") == 15);
    REQUIRE(map.at("B") == 20);
    REQUIRE(map.at("D") == 14);
  }

  SECTION("updating one element") {
    map.at("A") = 20;
    REQUIRE(map.size() == 3);
    REQUIRE(map.contains("A"));
    REQUIRE(map.contains("B"));
    REQUIRE(map.contains("C"));
    REQUIRE(map.at("A") == 20);
    REQUIRE(map.at("B") == 20);
    REQUIRE(map.at("C") == 30);
  }

  SECTION("incrementing one element") {
    map.at("A")++;
    REQUIRE(map.size() == 3);
    REQUIRE(map.contains("A"));
    REQUIRE(map.contains("B"));
    REQUIRE(map.contains("C"));
    REQUIRE(map.at("A") == 11);
    REQUIRE(map.at("B") == 20);
    REQUIRE(map.at("C") == 30);
  }

  SECTION("modifying one element with []") {
    map["A"]++;
    REQUIRE(map.size() == 3);
    REQUIRE(map.contains("A"));
    REQUIRE(map.contains("B"));
    REQUIRE(map.contains("C"));
    REQUIRE(map.at("A") == 11);
    REQUIRE(map.at("B") == 20);
    REQUIRE(map.at("C") == 30);
  }

  SECTION("modifying an element with []") {
    map["D"] = 23;
    REQUIRE(map.size() == 4);
    REQUIRE(map.contains("A"));
    REQUIRE(map.contains("B"));
    REQUIRE(map.contains("C"));
    REQUIRE(map.contains("D"));
    REQUIRE(map.at("A") == 10);
    REQUIRE(map.at("B") == 20);
    REQUIRE(map.at("C") == 30);
    REQUIRE(map.at("D") == 23);
  }  
}


TEST_CASE("hash map without collisions", "MapHash") {
  MapHash<int, int> map;
  const int capacity = 31;
  for (int i = 1; i <= capacity; i++) {
    if (i % 3 == 0) {
      map.insert({i, 2 * i});
    } else {
      map[i] = 2 * i;
    }
  }

  SECTION("map contains every number between 1 and capacity") {
    for (int i = 1; i <= capacity; i++) {
      REQUIRE(map.contains(i));
    }
  }

  SECTION("map contains every number between 1 and capacity associated with its double") {
    for (int i = 1; i <= capacity; i++) {
      REQUIRE(map.at(i) == 2 * i);
    }
  }

  SECTION("map contains every number between 1 and capacity associated with its double") {
    for (int i = 1; i <= capacity; i++) {
      REQUIRE(map[i] == 2 * i);
    }
  }

  SECTION("after removing every element with odd key, map size is halved") {
    for (int i = 1; i <= capacity; i += 2) {
      map.erase(i);
    }
    REQUIRE(map.size() == 15);
  }  

  SECTION("after removing every element, map is empty") {
    for (int i = 1; i <= capacity; i++) {
      map.erase(i);
    }
    REQUIRE(map.size() == 0);
    REQUIRE(map.empty());
  }  
}

TEST_CASE("hash map with collisions", "MapHash") {
  MapHash<int, int> map;
  const int capacity = 31;
  for (int i = 1; i <= capacity; i++) {
    if (i % 3 == 0) {
      map.insert({2 + 31*i, 2 * i});
    } else {
      map[2 + 31*i] = 2 * i;
    }
  }

  SECTION("map contains every number between 1 and capacity") {
    for (int i = 1; i <= capacity; i++) {
      REQUIRE(map.contains(2 + 31*i));
    }
  }

  SECTION("map contains every number between 1 and capacity associated with its double") {
    for (int i = 1; i <= capacity; i++) {
      REQUIRE(map.at(2 + 31*i) == 2 * i);
    }
  }

  SECTION("map contains every number between 1 and capacity associated with its double") {
    for (int i = 1; i <= capacity; i++) {
      REQUIRE(map[2 + 31*i] == 2 * i);
    }
  }

  SECTION("after removing every element with odd key, map size is halved") {
    for (int i = 1; i <= capacity; i += 2) {
      map.erase(2 + 31*i);
    }
    REQUIRE(map.size() == 15);
  }  

  SECTION("after removing every element, map is empty") {
    for (int i = 1; i <= capacity; i++) {
      map.erase(2 + 31*i);
    }
    REQUIRE(map.size() == 0);
    REQUIRE(map.empty());
  }  
}