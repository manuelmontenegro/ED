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
 * Implementación del TAD Lista mediante arrays.
 *
 * Esta versión introduce genericidad mediante plantillas.
 */

#ifndef __LIST_ARRAY_H
#define __LIST_ARRAY_H

#include <cassert>
#include <iostream>
#include <string>

const int DEFAULT_CAPACITY = 10;

template <typename T> class ListArray {
public:
  ListArray(int initial_capacity = DEFAULT_CAPACITY)
      : num_elems(0), capacity(initial_capacity), elems(new T[capacity]) {}

  ~ListArray() { delete[] elems; }

  ListArray(const ListArray &other);

  void push_front(const T &elem);
  void push_back(const T &elem);
  void pop_front();
  void pop_back();

  int size() const { return num_elems; }
  bool empty() const { return num_elems == 0; }

  const T &front() const {
    assert(num_elems > 0);
    return elems[0];
  }

  T &front() {
    assert(num_elems > 0);
    return elems[0];
  }

  const T &back() const {
    assert(num_elems > 0);
    return elems[num_elems - 1];
  }

  T &back() {
    assert(num_elems > 0);
    return elems[num_elems - 1];
  }

  const T &operator[](int index) const {
    assert(0 <= index && index < num_elems);
    return elems[index];
  }

  T &operator[](int index) {
    assert(0 <= index && index < num_elems);
    return elems[index];
  }

  ListArray &operator=(const ListArray &other);

  void display(std::ostream &out) const;
  void display() const { display(std::cout); }

private:
  int num_elems;
  int capacity;
  T *elems;

  void resize_array(int new_capacity);
};

template <typename T>
ListArray<T>::ListArray(const ListArray<T> &other)
    : num_elems(other.num_elems), capacity(other.capacity),
      elems(new T[other.capacity]) {
  for (int i = 0; i < num_elems; i++) {
    elems[i] = other.elems[i];
  }
}

template <typename T> void ListArray<T>::push_front(const T &elem) {
  if (num_elems == capacity) {
    resize_array(capacity * 2);
  }

  for (int i = num_elems - 1; i >= 0; i--) {
    elems[i + 1] = elems[i];
  }

  elems[0] = elem;
  num_elems++;
}

template <typename T> void ListArray<T>::pop_front() {
  assert(num_elems > 0);

  for (int i = 1; i < num_elems; i++) {
    elems[i - 1] = elems[i];
  }

  num_elems--;
}

template <typename T> void ListArray<T>::push_back(const T &elem) {
  if (num_elems == capacity) {
    resize_array(capacity * 2);
  }

  elems[num_elems] = elem;
  num_elems++;
}

template <typename T> void ListArray<T>::pop_back() {
  assert(num_elems > 0);
  num_elems--;
}

template <typename T> void ListArray<T>::resize_array(int new_capacity) {
  T *new_elems = new T[new_capacity];

  for (int i = 0; i < num_elems; i++) {
    new_elems[i] = elems[i];
  }

  delete[] elems;
  elems = new_elems;
  capacity = new_capacity;
}

template <typename T>
ListArray<T> &ListArray<T>::operator=(const ListArray<T> &other) {
  if (this != &other) {
    if (capacity < other.num_elems) {
      delete[] elems;
      elems = new T[other.capacity];
      capacity = other.capacity;
    }
    num_elems = other.num_elems;
    for (int i = 0; i < num_elems; i++) {
      elems[i] = other.elems[i];
    }
  }

  return *this;
}

template <typename T> void ListArray<T>::display(std::ostream &out) const {
  out << "[";
  if (num_elems > 0) {
    out << elems[0];
    for (int i = 1; i < num_elems; i++) {
      out << ", " << elems[i];
    }
  }
  out << "]";
}

template <typename T>
std::ostream &operator<<(std::ostream &out, const ListArray<T> &l) {
  l.display(out);
  return out;
}

#endif
