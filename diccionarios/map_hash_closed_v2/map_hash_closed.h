/*
 * ---------------------------------------------------
 *                ESTRUCTURAS DE DATOS
 * ---------------------------------------------------
 *          Manuel Montenegro y Alberto Verdejo
 *               Facultad de Informática
 *          Universidad Complutense de Madrid
 * ---------------------------------------------------
 */

/*
 * Implementación del TAD Diccionario mediante tablas hash
 * cerradas.  La tabla se redimensiona a medida que el factor
 * de carga supera MAX_LOAD_FACTOR
 */

#ifndef __MAP_HASH_CLOSED
#define __MAP_HASH_CLOSED

#include <cassert>
#include <forward_list>
#include <iostream>
#include <string>
#include <utility>

const int INITIAL_CAPACITY = 31;
const double MAX_LOAD_FACTOR = 0.5;

template <typename K, typename V, typename Hash = std::hash<K>> class MapHash {
public:
  struct MapEntry {
    K key;
    V value;

    MapEntry(K key, V value) : key(key), value(value) {}
    MapEntry(K key) : key(key), value() {}
    MapEntry() {}
  };

  MapHash()
      : num_elems(0), capacity(INITIAL_CAPACITY),
        buckets(new Bucket[INITIAL_CAPACITY]) {}

  MapHash(const MapHash &other)
      : num_elems(other.num_elems), hash(other.hash), capacity(other.capacity),
        buckets(new Bucket[other.capacity]) {
    copy(other.buckets, other.buckets + other.capacity, buckets);
  }

  ~MapHash() { delete[] buckets; }

  void insert(const MapEntry &entry) {
    auto [pos_to_insert, pos_found] = search_pos(entry.key);
    if (pos_found == -1) {
      resize_if_necessary();
      auto [pos_to_insert, pos_found] = search_pos(entry.key);
      buckets[pos_to_insert].state = State::occupied;
      buckets[pos_to_insert].entry = entry;
      num_elems++;
    }
  }

  bool contains(const K &key) const {
    auto [pos_to_insert, pos_found] = search_pos(key);
    return pos_found != -1;
  }

  const V &at(const K &key) const {
    auto [pos_to_insert, pos_found] = search_pos(key);
    assert(pos_found != -1);
    return buckets[pos_found].entry.value;
  }

  V &at(const K &key) {
    auto [pos_to_insert, pos_found] = search_pos(key);
    assert(pos_found != -1);
    return buckets[pos_found].entry.value;
  }

  V &operator[](const K &key) {
    auto [pos_to_insert, pos_found] = search_pos(key);
    if (pos_found == -1) {
      resize_if_necessary();
      auto [pos_to_insert, pos_found] = search_pos(key);
      buckets[pos_to_insert].state = State::occupied;
      buckets[pos_to_insert].entry = MapEntry(key);
      num_elems++;
      return buckets[pos_to_insert].entry.value;
    } else {
      return buckets[pos_found].entry.value;
    }
  }

  void erase(const K &key) {
    auto [pos_to_insert, pos_found] = search_pos(key);
    if (pos_found != -1) {
      buckets[pos_found].state = State::deleted;
      num_elems--;
    }
  }

  int size() const { return num_elems; }

  bool empty() const { return num_elems == 0; }

  MapHash &operator=(const MapHash &other) {
    if (this != &other) {
      num_elems = other.num_elems;
      hash = other.hash;
      if (capacity != other.capacity) {
        capacity = other.capacity;
        delete[] buckets;
        buckets = new Bucket[capacity];
      }
      copy(other.buckets, other.buckets + other.capacity, buckets);
    }
    return *this;
  }

  void display(std::ostream &out) const {
    out << "{";
    bool first = true;
    for (int i = 0; i < capacity; i++) {
      if (buckets[i].state == State::occupied) {
        if (!first) {
          out << ", ";
        } else {
          out << " ";
          first = false;
        }
        out << buckets[i].entry.key << " -> " << buckets[i].entry.value;
      }
    }
    out << " }";
  }

private:
  enum class State { empty, occupied, deleted };

  struct Bucket {
    State state;
    MapEntry entry;

    Bucket() : state(State::empty) {}
  };

  Hash hash;

  Bucket *buckets;
  int num_elems;
  int capacity;

  void resize_if_necessary() {
    double load_factor = ((double)num_elems) / capacity;
    if (load_factor < MAX_LOAD_FACTOR)
      return;

    Bucket *old_array = buckets;
    int old_capacity = capacity;

    capacity = next_prime_after(2 * capacity);
    buckets = new Bucket[capacity];
    for (int i = 0; i < old_capacity; i++) {
      if (old_array[i].state == State::occupied) {
        auto [pos_to_insert, pos_found] = search_pos(old_array[i].entry.key);
        buckets[pos_to_insert].state = State::occupied;
        buckets[pos_to_insert].entry = MapEntry(old_array[i].entry);
      }
    }

    delete[] old_array;
  }

  static int next_prime_after(int num) {
    while (!is_prime(num)) {
      num++;
    }
    return num;
  }

  static bool is_prime(int n) {
    int i = 2;
    bool is_prime = true;
    while (is_prime && i * i <= n) {
      if (n % i == 0)
        is_prime = false;
      i++;
    }
    return is_prime;
  }

  std::pair<int, int> search_pos(const K &key) const {
    int h = hash(key) % capacity;
    int cont = 0;

    int pos_to_insert = -1;
    int pos_found = -1;

    while (cont < capacity && pos_found == -1 &&
           buckets[h].state != State::empty) {
      if (pos_to_insert == -1 && buckets[h].state == State::deleted) {
        pos_to_insert = h;
      }

      if (buckets[h].state == State::occupied && buckets[h].entry.key == key) {
        pos_found = h;
      }

      h = (h + 1) % capacity;
      cont++;
    }

    if (cont < capacity && pos_to_insert == -1) {
      pos_to_insert = h;
    }

    return {pos_to_insert, pos_found};
  }
};

template <typename K, typename V>
std::ostream &operator<<(std::ostream &out, const MapHash<K, V> &map) {
  map.display(out);
  return out;
}

#endif
