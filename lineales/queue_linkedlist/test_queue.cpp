#include "../../catch.hpp"

#include "queue_linkedlist.h"

TEST_CASE("adding elements to a queue", "QueueLinkedList") {
  QueueLinkedList<int> q;
  SECTION("queue is empty") {
    REQUIRE( q.empty() );
  }

  SECTION("after adding one element, queue is no longer empty") {
    q.push(10);
    REQUIRE( !q.empty() );
  }

  SECTION("adding one element and removing it, queue is empty") {
    q.push(10);
    q.pop();
    REQUIRE( q.empty() );
  }

  SECTION("adding two elements and removing them") {
    q.push(10);
    q.push(20);
    q.pop();
    q.pop();
    REQUIRE( q.empty() );
  }

  SECTION("adding two elements alternatively and removing them") {
    q.push(10);
    q.pop();
    q.push(20);
    q.pop();
    REQUIRE( q.empty() );
  }

  SECTION("after adding an element, it is at the front") {
    q.push(10);
    REQUIRE( q.front() == 10 );
  }

  SECTION("after adding two elements, the first one is at the front") {
    q.push(10);
    q.push(20);
    REQUIRE( q.front() == 10 );
  }

  SECTION("after adding two elements, and removing one, the second one is at the front") {
    q.push(10);
    q.push(20);
    q.pop();
    REQUIRE( q.front() == 20 );
  }

  SECTION("adding three elements, and removing one, the second one is at the front") {
    q.push(10);
    q.push(20);
    q.push(30);
    q.pop();
    REQUIRE( q.front() == 20 );
  }

  SECTION("adding three elements, and removing two, the last one is at the front") {
    q.push(10);
    q.push(20);
    q.push(30);
    q.pop();
    q.pop();
    REQUIRE( q.front() == 30 );
  }

  SECTION("push/pop twice") {
    q.push(10);
    REQUIRE( q.front() == 10 );
    q.pop();
    q.push(20);
    REQUIRE( q.front() == 20 );
    q.pop();
  }

  SECTION("push three elements and dequeue them") {
    q.push(10);
    REQUIRE( q.front() == 10 );
    q.push(20);
    REQUIRE( q.front() == 10 );
    q.push(30);
    REQUIRE( q.front() == 10 );
    q.pop();
    REQUIRE( q.front() == 20 );
    q.pop();
    REQUIRE( q.front() == 30 );
  }
}

TEST_CASE("copy of an empty queue") {
  QueueLinkedList<int> q1;
  QueueLinkedList<int> q2 = q1;

  SECTION("both are empty") {
    REQUIRE( q1.empty() );
    REQUIRE( q2.empty() );
  }

  SECTION("modifying q1 does not affect q2") {
    q1.push(10);
    REQUIRE( q2.empty() );
  }

  SECTION("modifying q2 does not affect q1") {
    q2.push(10);
    REQUIRE( q1.empty() );
  }
}

TEST_CASE("copy of a nonempty queue") {
  QueueLinkedList<int> q1;
  q1.push(10);
  q1.push(20);
  QueueLinkedList<int> q2 = q1;

  SECTION("q2 contains the same elements as q2") {
    REQUIRE( q2.front() == 10 );
    q2.pop();
    REQUIRE( q2.front() == 20 );
    q2.pop();
    REQUIRE( q2.empty() );
  }

  SECTION("modifying q1 does not affect q2") {
    q1.push(30);
    REQUIRE( q2.front() == 10 );
    q2.pop();
    REQUIRE( q2.front() == 20 );
    q2.pop();
    REQUIRE( q2.empty() );
  }

  SECTION("modifying q2 does not affect q1") {
    q2.push(30);
    REQUIRE( q1.front() == 10 );
    q1.pop();
    REQUIRE( q1.front() == 20 );
    q1.pop();
    REQUIRE( q1.empty() );
  }
}

TEST_CASE("queue assignment") {
  QueueLinkedList<int> q1;
  q1.push(10);
  q1.push(20);
  QueueLinkedList<int> q2;
  q2.push(30);
  q2 = q1;

  SECTION("q2 contains the same elements as q2") {
    REQUIRE( q2.front() == 10 );
    q2.pop();
    REQUIRE( q2.front() == 20 );
    q2.pop();
    REQUIRE( q2.empty() );
  }

  SECTION("modifying q1 does not affect q2") {
    q1.push(30);
    REQUIRE( q2.front() == 10 );
    q2.pop();
    REQUIRE( q2.front() == 20 );
    q2.pop();
    REQUIRE( q2.empty() );
  }

  SECTION("modifying q2 does not affect q1") {
    q2.push(30);
    REQUIRE( q1.front() == 10 );
    q1.pop();
    REQUIRE( q1.front() == 20 );
    q1.pop();
    REQUIRE( q1.empty() );
  }
}