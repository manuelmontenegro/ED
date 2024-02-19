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
 * Implementación del TAD Conjunto mediante listas ordenadas.
 *
 * Versión inicial
 */

#ifndef __SET_LIST_H
#define __SET_LIST_H

#include <algorithm>
#include <cassert>
#include <iostream>
#include <iterator>
#include <vector>

const int INITIAL_CAPACITY = 20;

template <typename T> class SetList {
public:
  // SetList() { }
  // SetList(const SetList &other): list_elems(other.list_elems) { }
  // ~SetList() { }

  // O(N) en el caso peor, donde N es el número de elementos del conjunto
  void insert(const T &elem) {
    auto position =
        std::lower_bound(list_elems.begin(), list_elems.end(), elem);
    if (position == list_elems.end() || *position != elem) {
      list_elems.insert(position, elem);
    }
  }

  // O(N) en el caso peor, donde N es el número de elementos del conjunto
  void erase(const T &elem) {
    auto position =
        std::lower_bound(list_elems.begin(), list_elems.end(), elem);
    if (position != list_elems.end() && *position == elem) {
      list_elems.erase(position);
    }
  }

  // O(log N) en el caso peor, donde N es el número de elementos del conjunto
  bool contains(const T &elem) const {
    return std::binary_search(list_elems.begin(), list_elems.end(), elem);
  }

  // O(1)
  int size() const { return list_elems.size(); }

  // O(1)
  bool empty() const { return list_elems.empty(); }

  // O(N) en el caso peor, donde N es el número de elementos del conjunto
  void display(std::ostream &out) const {
    out << "{";
    if (!list_elems.empty()) {
      std::copy(list_elems.begin(), --list_elems.end(),
                std::ostream_iterator<T>(out, ", "));
      out << list_elems.back();
    }
    out << "}";
  }

private:
  using List = std::vector<T>;
  List list_elems;
};

template <typename T>
std::ostream &operator<<(std::ostream &out, const SetList<T> &set) {
  set.display(out);
  return out;
}

#endif
