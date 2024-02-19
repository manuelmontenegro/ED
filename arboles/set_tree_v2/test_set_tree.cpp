#include "../../catch.hpp"
#include "set_tree.h"

TEST_CASE("creation of sets", "SetTree") {
    SetTree<int> s;

    SECTION("set is initially empty") {
        REQUIRE(s.empty());
        REQUIRE(s.size() == 0);
    }

    SECTION("after adding an element, it is no longer empty") {
        s.insert(4);
        REQUIRE_FALSE(s.empty());
        REQUIRE(s.size() == 1);
    }

    SECTION("if no elements are added, contains returns false") {
        for (int i = 0; i < 10; i++) {
            REQUIRE_FALSE(s.contains(i));
        }
    }

    SECTION("if an element is inserted, contains returns true for that element") {
        s.insert(4);
        for (int i = 0; i < 10; i++) {
            if (i == 4) {
                REQUIRE(s.contains(i));
            } else {
                REQUIRE_FALSE(s.contains(i));
            }
        }
    }

    SECTION("if two elements are inserted, its cardinality is 2") {
        s.insert(4);
        s.insert(2);
        REQUIRE(s.size() == 2);
    }

    SECTION("if two elements are inserted in reverse order, its cardinality is 2") {
        s.insert(2);
        s.insert(4);
        REQUIRE(s.size() == 2);
    }

    SECTION("if two elements are inserted, both are in the set") {
        s.insert(2);
        s.insert(4);
        REQUIRE(s.contains(2));
        REQUIRE(s.contains(4));
        REQUIRE_FALSE(s.contains(1));
    }    

    SECTION("if two elements are inserted in reverse order, both are in the set") {
        s.insert(4);
        s.insert(2);
        REQUIRE(s.contains(2));
        REQUIRE(s.contains(4));
        REQUIRE_FALSE(s.contains(1));
        REQUIRE_FALSE(s.contains(3));
        REQUIRE_FALSE(s.contains(5));
    }       

    SECTION("if three elements are inserted, the three are in the set") {
        s.insert(1);
        s.insert(5);
        s.insert(3);
        REQUIRE(s.contains(1));
        REQUIRE(s.contains(3));
        REQUIRE(s.contains(5));
        REQUIRE_FALSE(s.contains(0));
        REQUIRE_FALSE(s.contains(2));
        REQUIRE_FALSE(s.contains(4));
        REQUIRE_FALSE(s.contains(6));
    }

    SECTION("inserting an element twice does not change size") {
        s.insert(1);
        REQUIRE(s.size() == 1);
        s.insert(1);
        REQUIRE(s.size() == 1);        
    }
}


TEST_CASE("removing elements from sets", "SetTree") {
    SetTree<int> s;
    for (int i = 0; i < 100; i += 10) {
        s.insert(i);
    }
    int old_size = s.size();

    SECTION("removing an element that does not exist") {
        s.erase(22);
        REQUIRE(s.size() == old_size);
    }

    SECTION("removing an element that does exist") {
        s.erase(20);
        REQUIRE(s.size() == old_size - 1);
        REQUIRE(s.contains(10));
        REQUIRE(s.contains(30));
        REQUIRE_FALSE(s.contains(20));
    }

    SECTION("insertion after removal") {
        s.erase(20);
        REQUIRE(s.size() == old_size - 1);
        s.insert(21);
        REQUIRE(s.size() == old_size);
        REQUIRE_FALSE(s.contains(20));
        REQUIRE(s.contains(21));
    }
}

TEST_CASE("deletion in a balanced tree") {
    SetTree<int> s;
    s.insert(2);
    s.insert(1);
    s.insert(3);

    SECTION("removing root") {
        s.erase(2);
        REQUIRE (s.size() == 2);
    }
}
