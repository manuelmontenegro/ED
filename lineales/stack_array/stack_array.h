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
 * Implementación del TAD Pila mediante arrays dinámicamente extensibles.
 */

#ifndef __STACK_ARRAY_H
#define __STACK_ARRAY_H

#include <cassert>
#include <iostream>

const int DEFAULT_CAPACITY = 10;

template <typename T> class StackArray {
public:
  StackArray(int initial_capacity = DEFAULT_CAPACITY)
      : num_elems(0), capacity(initial_capacity), elems(new T[capacity]) {}

  ~StackArray() { delete[] elems; }

  StackArray(const StackArray &other);
  StackArray &operator=(const StackArray<T> &other);

  void push(const T &elem) {
    if (num_elems == capacity) {
      resize_array(capacity * 2);
    }

    elems[num_elems] = elem;
    num_elems++;
  }

  void pop() {
    assert(num_elems > 0);
    num_elems--;
  }

  const T &top() const {
    assert(num_elems > 0);
    return elems[num_elems - 1];
  }

  T &top() {
    assert(num_elems > 0);
    return elems[num_elems - 1];
  }

  bool empty() const { return num_elems == 0; }

private:
  int num_elems;
  int capacity;
  T *elems;

  void resize_array(int new_capacity);
};

template <typename T>
StackArray<T>::StackArray(const StackArray<T> &other)
    : num_elems(other.num_elems), capacity(other.capacity),
      elems(new T[other.capacity]) {
  for (int i = 0; i < num_elems; i++) {
    elems[i] = other.elems[i];
  }
}

template <typename T> void StackArray<T>::resize_array(int new_capacity) {
  T *new_elems = new T[new_capacity];

  for (int i = 0; i < num_elems; i++) {
    new_elems[i] = elems[i];
  }

  delete[] elems;
  elems = new_elems;
  capacity = new_capacity;
}

template <typename T>
StackArray<T> &StackArray<T>::operator=(const StackArray<T> &other) {
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

#endif
