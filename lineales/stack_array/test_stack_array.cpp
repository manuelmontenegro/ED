#include "../../catch.hpp"
#include "stack_array.h"


TEST_CASE("adding and removing elements from a stack", "StackArray") {
  StackArray<int> s;

  SECTION("stack is initially empty") {
    REQUIRE(s.empty());
  }

  SECTION("after adding one element, it is no longer empty") {
    s.push(10);
    REQUIRE(!s.empty());
  }
  
  SECTION("after adding two elements, it is no longer empty") {
    s.push(10);
    s.push(5);
    REQUIRE(!s.empty());
  }

  SECTION("after adding one element and removing it, it is empty again") {
    s.push(10);
    s.pop();
    REQUIRE(s.empty());
  }

  SECTION("after adding two elements and removing them, it is empty again") {
    s.push(10);
    s.push(5);
    s.pop();
    s.pop();
    REQUIRE(s.empty());
  }

  SECTION("after adding each element, it becomes the topmost one") {
    for (int i = 0; i < 10; i++) {
      s.push(i);
      REQUIRE(s.top() == i);
    }
  }

  SECTION("after adding several elements, we retrieve them in reverse order") {
    for (int i = 0; i < 10; i++) {
      s.push(i);
    }

    int cont = 9;
    while (!s.empty()) {
      REQUIRE(s.top() == cont);
      s.pop();
      cont--;
    }
  }

  SECTION("modifying the topmost element") {
    s.push(10);
    s.top() = 20;
    REQUIRE(!s.empty());
    REQUIRE(s.top() == 20);
    s.pop();
    REQUIRE(s.empty());
  }

  SECTION("modifiying elements while inserting") {
    for (int i = 0; i < 10; i++) {
      s.push(i);
      s.top() += 1;
    }
    
    int cont = 10;
    while (!s.empty()) {
      REQUIRE (s.top() == cont);
      s.pop();
      cont--;
    }

  }
}


TEST_CASE("copy constructor for empty stack", "StackArray") {
  StackArray<int> s1;
  StackArray<int> s2 = s1;

  SECTION("copy is empty") {
    REQUIRE (s2.empty());
  }

  SECTION("original does not affect copy") {
    s1.push(10);
    REQUIRE (s2.empty());
    REQUIRE (!s1.empty());
  }

  SECTION("copy does not affect original") {
    s2.push(10);
    REQUIRE (s1.empty());
    REQUIRE (!s2.empty());
  }
}

TEST_CASE("assignment operator for empty stack", "StackArray") {
  StackArray<int> s1;
  StackArray<int> s2;
  s2.push(20);
  s2 = s1;

  SECTION("copy is empty") {
    REQUIRE (s2.empty());
  }

  SECTION("original does not affect copy") {
    s1.push(10);
    REQUIRE (s2.empty());
    REQUIRE (!s1.empty());
  }

  SECTION("copy does not affect original") {
    s2.push(10);
    REQUIRE (s1.empty());
    REQUIRE (!s2.empty());
  }
}


TEST_CASE("copy constructor for nonempty stack", "StackArray") {
  StackArray<int> s1;
  s1.push(1);
  s1.push(2);
  StackArray<int> s2 = s1;

  SECTION("copy has the same elements as original") {
    REQUIRE (!s2.empty());
    REQUIRE (s2.top() == 2);
    s2.pop();
    REQUIRE (s2.top() == 1);
    s2.pop();
    REQUIRE (s2.empty());
  }

  SECTION("original does not affect copy") {
    s1.push(10);
    REQUIRE (s2.top() == 2);
    REQUIRE (s1.top() == 10);
  }

  SECTION("copy does not affect original") {
    s2.push(10);
    REQUIRE (s2.top() == 10);
    REQUIRE (s1.top() == 2);
  }

}

TEST_CASE("assignment operator to nonempty stack", "StackArray") {
  StackArray<int> s1;
  s1.push(1);
  s1.push(2);
  StackArray<int> s2;
  s2.push(3);
  s2 = s1;

  SECTION("copy has the same elements as original") {
    REQUIRE (!s2.empty());
    REQUIRE (s2.top() == 2);
    s2.pop();
    REQUIRE (s2.top() == 1);
    s2.pop();
    REQUIRE (s2.empty());
  }

  SECTION("original does not affect copy") {
    s1.push(10);
    REQUIRE (s2.top() == 2);
    REQUIRE (s1.top() == 10);
  }

  SECTION("copy does not affect original") {
    s2.push(10);
    REQUIRE (s2.top() == 10);
    REQUIRE (s1.top() == 2);
  }

}