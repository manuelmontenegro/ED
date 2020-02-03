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
  * Versión inicial.
  */

#ifndef __LIST_ARRAY_H
#define __LIST_ARRAY_H

#include <cassert>
#include <iostream>
#include <string>

const int DEFAULT_CAPACITY = 10;

class ListArray {
public:

  ListArray(int initial_capacity = DEFAULT_CAPACITY)
    : num_elems(0), capacity(initial_capacity), elems(new std::string[capacity]) { }

  ~ListArray() { delete[] elems; }

  void push_front(const std::string &elem);
  void push_back(const std::string &elem);
  void pop_front();
  void pop_back();

  int size() const { return num_elems; }
  bool empty() const { return num_elems == 0; }
  std::string front() const {
    assert (num_elems > 0);
    return elems[0];
  }
  std::string back() const {
    assert (num_elems > 0);
    return elems[num_elems - 1];
  }
  std::string at(int index) const {
    assert (0 <= index && index < num_elems);
    return elems[index];
  }

  void display(std::ostream &out) const;
  void display() const {
    display(std::cout);
  }

private:
  int num_elems;
  int capacity;
  std::string *elems;

  void resize_array(int new_capacity);
};


void ListArray::push_front(const std::string &elem) {
  if (num_elems == capacity) {
    resize_array(capacity * 2);
  }

  for (int i = num_elems - 1; i >= 0; i--) {
    elems[i + 1] = elems[i];
  }
  
  elems[0] = elem;
  num_elems++;
}

void ListArray::pop_front() {
  assert (num_elems > 0);

  for (int i = 1; i < num_elems; i++) {
    elems[i - 1] = elems[i];
  }
  
  num_elems--;
}

void ListArray::push_back(const std::string &elem) {
  if (num_elems == capacity) {
    resize_array(capacity * 2);
  }

  elems[num_elems] = elem;
  num_elems++;
}

void ListArray::pop_back() {
  assert (num_elems > 0);
  num_elems--;
}


void ListArray::resize_array(int new_capacity) {
  std::string *new_elems = new std::string[new_capacity];
  
  for (int i = 0; i < num_elems; i++) {
    new_elems[i] = elems[i];
  }

  delete[] elems;
  elems = new_elems;
  capacity = new_capacity;
}


void ListArray::display(std::ostream &out) const {
  out << "[";
  if (num_elems > 0) {
    out << elems[0];
    for (int i = 1; i < num_elems; i++) {
      out << ", " << elems[i];
    }
  }
  out << "]";
}

#endif