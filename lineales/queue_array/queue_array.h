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
 * Implementación del TAD Cola mediante arrays circulares.
 */

#ifndef __QUEUE_ARRAY_H
#define __QUEUE_ARRAY_H

#include <cassert>
#include <iostream>

const int CAPACITY = 100;

template <typename T> class QueueArray {
public:
  QueueArray() {
    elems = new T[CAPACITY];
    front_pos = 0;
    back_pos = 0;
  }
  QueueArray(const QueueArray &other);

  ~QueueArray() { delete elems; }

  QueueArray &operator=(const QueueArray &other);

  void push(const T &elem) {
    assert((back_pos + 1) % CAPACITY != front_pos);
    elems[back_pos] = elem;
    back_pos = (back_pos + 1) % CAPACITY;
  }

  void pop() {
    assert(front_pos != back_pos);
    front_pos = (front_pos + 1) % CAPACITY;
  }

  T &front() {
    assert(front_pos != back_pos);
    return elems[front_pos];
  }

  const T &front() const {
    assert(front_pos != back_pos);
    return elems[front_pos];
  }

  bool empty() const { return front_pos == back_pos; }

private:
  T *elems;
  int front_pos, back_pos;
};

template <typename T>
QueueArray<T>::QueueArray(const QueueArray<T> &other) : QueueArray() {
  for (int i = other.front_pos; i != other.back_pos; i = (i + 1) % CAPACITY) {
    elems[back_pos] = other.elems[i];
    back_pos++;
  }
}

template <typename T>
QueueArray<T> &QueueArray<T>::operator=(const QueueArray<T> &other) {
  if (this != &other) {
    front_pos = 0;
    back_pos = 0;
    for (int i = other.front_pos; i != other.back_pos; i = (i + 1) % CAPACITY) {
      elems[back_pos] = other.elems[i];
      back_pos++;
    }
  }
  return *this;
}

#endif
