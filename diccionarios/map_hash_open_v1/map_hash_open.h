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
 * abiertas. El tamaño no varía a medida que se llena la tabla.
 */

#ifndef __MAP_HASH_OPEN
#define __MAP_HASH_OPEN

#include <cassert>
#include <forward_list>
#include <iostream>
#include <string>

const int CAPACITY = 31;

template <typename K, typename V, typename Hash = std::hash<K>> class MapHash {
public:
  struct MapEntry {
    K key;
    V value;

    MapEntry(K key, V value) : key(key), value(value) {}
    MapEntry(K key) : key(key), value() {}
  };

  MapHash() : num_elems(0), buckets(new List[CAPACITY]){};
  MapHash(const MapHash &other)
      : num_elems(other.num_elems), hash(other.hash),
        buckets(new List[CAPACITY]) {
    std::copy(other.buckets, other.buckets + CAPACITY, buckets);
  };
  ~MapHash() { delete[] buckets; }

  void insert(const MapEntry &entry) {
    int h = hash(entry.key) % CAPACITY;

    List &list = buckets[h];

    auto it = find_in_list(list, entry.key);

    if (it == list.end()) {
      list.push_front(entry);
      num_elems++;
    }
  }

  bool contains(const K &key) const {
    int h = hash(key) % CAPACITY;
    const List &list = buckets[h];
    auto it = find_in_list(list, key);
    return it != list.end();
  }

  const V &at(const K &key) const {
    int h = hash(key) % CAPACITY;
    const List &list = buckets[h];
    auto it = find_in_list(list, key);
    assert(it != list.end());
    return it->value;
  }

  V &at(const K &key) {
    int h = hash(key) % CAPACITY;
    List &list = buckets[h];
    auto it = find_in_list(list, key);
    assert(it != list.end());
    return it->value;
  }

  V &operator[](const K &key) {
    int h = hash(key) % CAPACITY;
    List &list = buckets[h];
    auto it = find_in_list(list, key);

    if (it == list.end()) {
      list.push_front(MapEntry(key));
      it = list.begin();
      num_elems++;
    }

    return it->value;
  }

  void erase(const K &key) {
    int h = hash(key) % CAPACITY;
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
      num_elems = other.num_elems;
      hash = other.hash;
      copy(other.buckets, other.buckets + CAPACITY, buckets);
    }
    return *this;
  }

  void display(std::ostream &out) const {
    out << "{";
    bool first_entry = true;
    for (int i = 0; i < CAPACITY; i++) {
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

  // ...
};

template <typename K, typename V>
std::ostream &operator<<(std::ostream &out, const MapHash<K, V> &map) {
  map.display(out);
  return out;
}

#endif
