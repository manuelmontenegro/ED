#include "../../catch.hpp"
#include "map_tree.h"
#include <vector>
#include <unordered_set>

void all_combinations(int min, int max, int current_val,
                      std::unordered_set<int> &marked,
                      std::vector<int> &current,
                      std::vector<std::vector<int>> &result) {
  if (current_val > max) {
    result.push_back(current);
  } else {
    for (int i = min; i <= max; i++) {
      if (!marked.count(i)) {
        marked.insert(i);
        current.push_back(i);
        all_combinations(min, max, current_val + 1, marked, current, result);
        current.pop_back();
        marked.erase(i);
      }
    }
  }
}

std::vector<std::vector<int>> all_combinations(int min, int max) {
  std::vector<std::vector<int>> result;
  std::vector<int> current;
  std::unordered_set<int> marked;
  all_combinations(min, max, min, marked, current, result);
  return result;
}

TEST_CASE("empty maps", "MapTree") {
  MapTree<std::string, int> map;

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

TEST_CASE("nonempty maps", "MapTree") {
  MapTree<std::string, int> map;
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

TEST_CASE("nonempty maps with different insertion order", "MapTree") {
  MapTree<std::string, int> map;
  map.insert({"B", 20});
  map.insert({"A", 10});
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

  SECTION("erasing root") {
    map.erase("B");
    REQUIRE(map.at("A") == 10);
    REQUIRE(map.at("C") == 30);
    REQUIRE_FALSE(map.contains("B"));
  }
}

TEST_CASE("index operator", "MapTree") {
  std::vector<MapTree<int, int>> maps;
  for (const std::vector<int> &comb : all_combinations(1, 7)) {
    MapTree<int, int> map;
    for (int val : comb) {
      map[val] = val * 2;
    }
    maps.push_back(map);
  }

  SECTION("Retrieving all values") {
    for (MapTree<int, int> &map : maps) {
      for (int i = 1; i <= 7; i++) {
        REQUIRE(map[i] == i * 2);
      }
    }
  }

  SECTION("Iterating all maps") {
    for (MapTree<int, int> &map : maps) {
      int cont = 1;
      for (auto it = map.begin(); it != map.end(); ++it) {
        REQUIRE((*it).key == cont);
        REQUIRE((*it).value == cont * 2);
        cont++;
      }
    }
  }
}
