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
 * Implementación del TAD Diccionario mediante tablas hash
 * abiertas. La tabla se redimensiona a medida que el factor
 * de carga supera MAX_LOAD_FACTOR
 */

#ifndef __MAP_HASH_OPEN
#define __MAP_HASH_OPEN

#include <cassert>
#include <forward_list>
#include <iostream>
#include <string>

const int INITIAL_CAPACITY = 31;
const double MAX_LOAD_FACTOR = 0.8;

template <typename K, typename V, typename Hash = std::hash<K>> class MapHash {
public:
  struct MapEntry {
    K key;
    V value;

    MapEntry(K key, V value) : key(key), value(value) {}
    MapEntry(K key) : key(key), value() {}
  };

  MapHash()
      : num_elems(0), capacity(INITIAL_CAPACITY),
        buckets(new List[INITIAL_CAPACITY]){};
  MapHash(const MapHash &other)
      : num_elems(other.num_elems), hash(other.hash), capacity(other.capacity),
        buckets(new List[other.capacity]) {
    std::copy(other.buckets, other.buckets + other.capacity, buckets);
  };
  ~MapHash() { delete[] buckets; }

  void insert(const MapEntry &entry) {
    int h = hash(entry.key) % capacity;

    auto it = find_in_list(buckets[h], entry.key);

    if (it == buckets[h].end()) {
      resize_if_necessary();
      h = hash(entry.key) % capacity;
      buckets[h].push_front(entry);
      num_elems++;
    }
  }

  bool contains(const K &key) const {
    int h = hash(key) % capacity;
    const List &list = buckets[h];
    auto it = find_in_list(list, key);
    return it != list.end();
  }

  const V &at(const K &key) const {
    int h = hash(key) % capacity;
    const List &list = buckets[h];
    auto it = find_in_list(list, key);
    assert(it != list.end());
    return it->value;
  }

  V &at(const K &key) {
    int h = hash(key) % capacity;
    List &list = buckets[h];
    auto it = find_in_list(list, key);
    assert(it != list.end());
    return it->value;
  }

  V &operator[](const K &key) {
    int h = hash(key) % capacity;
    auto it = find_in_list(buckets[h], key);

    if (it == buckets[h].end()) {
      resize_if_necessary();
      h = hash(key) % capacity;
      buckets[h].push_front(MapEntry(key));
      it = buckets[h].begin();
      num_elems++;
    }

    return it->value;
  }

  void erase(const K &key) {
    int h = hash(key) % capacity;
    List &list = buckets[h];

    if (!list.empty()) {
      if (list.front().key == key) {
        list.pop_front();
        num_elems--;
      } else {
        auto it_prev = list.begin();
        auto it_next = ++list.begin();

        while (it_next != list.end() && it_next->key != key) {
          it_prev++;
          it_next++;
        }
        if (it_next != list.end()) {
          list.erase_after(it_prev);
          num_elems--;
        }
      }
    }
  }

  int size() const { return num_elems; }

  bool empty() const { return num_elems == 0; }

  MapHash &operator=(const MapHash &other) {
    if (this != &other) {
      capacity = other.capacity;
      num_elems = other.num_elems;
      hash = other.hash;
      delete[] buckets;
      buckets = new List[capacity];
      copy(other.buckets, other.buckets + capacity, buckets);
    }
    return *this;
  }

  void display(std::ostream &out) const {
    out << "{";
    bool first_entry = true;
    for (int i = 0; i < capacity; i++) {
      const List &current = buckets[i];
      for (const MapEntry &entry : current) {
        out << (first_entry ? " " : ", ");
        first_entry = false;
        out << entry.key << " -> " << entry.value;
      }
    }
    out << " }";
  }

private:
  using List = std::forward_list<MapEntry>;

  Hash hash;

  List *buckets;
  int num_elems;
  int capacity;

  void resize_if_necessary() {
    double load_factor = ((double)num_elems) / capacity;
    if (load_factor < MAX_LOAD_FACTOR)
      return;

    int new_capacity = next_prime_after(2 * capacity);

    List *new_array = new List[new_capacity];
    for (int i = 0; i < capacity; i++) {
      for (const MapEntry &entry : buckets[i]) {
        int new_pos = hash(entry.key) % new_capacity;
        new_array[new_pos].push_front(entry);
      }
    }

    capacity = new_capacity;
    delete[] buckets;
    buckets = new_array;
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

  static typename List::const_iterator find_in_list(const List &list,
                                                    const K &key) {
    auto it = list.begin();
    while (it != list.end() && it->key != key) {
      ++it;
    }
    return it;
  }

  static typename List::iterator find_in_list(List &list, const K &key) {
    auto it = list.begin();
    while (it != list.end() && it->key != key) {
      ++it;
    }
    return it;
  }
};

template <typename K, typename V>
std::ostream &operator<<(std::ostream &out, const MapHash<K, V> &map) {
  map.display(out);
  return out;
}

#endif
