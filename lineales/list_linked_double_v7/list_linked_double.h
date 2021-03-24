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
 * Implementación del TAD Lista mediante listas doblemente enlazadas circulares.
 *
 * Versión con iteradores constantes y métodos de inserción y borrado.
 */

#ifndef __LIST_LINKED_DOUBLE_H
#define __LIST_LINKED_DOUBLE_H

#include <cassert>
#include <iostream>

template <typename T> class ListLinkedDouble {
private:
  struct Node {
    T value;
    Node *next;
    Node *prev;
  };
  template <typename U> class gen_iterator;

public:
  ListLinkedDouble() : num_elems(0) {
    head = new Node;
    head->next = head;
    head->prev = head;
  }

  ListLinkedDouble(const ListLinkedDouble &other) : ListLinkedDouble() {
    copy_nodes_from(other);
    num_elems = other.num_elems;
  }

  ~ListLinkedDouble() { delete_nodes(); }

  void push_front(const T &elem) { insert(cbegin(), elem); }

  void push_back(const T &elem) { insert(cend(), elem); }

  void pop_front() { erase(cbegin()); }

  void pop_back() {
    assert(num_elems > 0);
    Node *target = head->prev;
    target->prev->next = head;
    head->prev = target->prev;
    delete target;
    num_elems--;
  }

  int size() const { return num_elems; }

  bool empty() const { return num_elems == 0; };

  const T &front() const {
    assert(num_elems > 0);
    return head->next->value;
  }

  T &front() {
    assert(num_elems > 0);
    return head->next->value;
  }

  const T &back() const {
    assert(num_elems > 0);
    return head->prev->value;
  }

  T &back() {
    assert(num_elems > 0);
    return head->prev->value;
  }

  const T &operator[](int index) const {
    assert(0 <= index && index < num_elems);
    Node *result_node = nth_node(index);
    return result_node->value;
  }

  T &operator[](int index) {
    assert(0 <= index && index < num_elems);
    Node *result_node = nth_node(index);
    return result_node->value;
  }

  ListLinkedDouble &operator=(const ListLinkedDouble &other) {
    if (this != &other) {
      delete_nodes();
      head = new Node;
      head->next = head->prev = head;
      copy_nodes_from(other);
      num_elems = other.num_elems;
    }
    return *this;
  }

  void display(std::ostream &out) const;

  void display() const { display(std::cout); }

  using iterator = gen_iterator<T>;
  using const_iterator = gen_iterator<const T>;

  iterator begin() { return iterator(head, head->next); }

  iterator end() { return iterator(head, head); }

  const_iterator begin() const { return const_iterator(head, head->next); }

  const_iterator end() const { return const_iterator(head, head); }

  const_iterator cbegin() const { return const_iterator(head, head->next); }

  const_iterator cend() const { return const_iterator(head, head); }

  iterator insert(const_iterator it, const T &elem) {
    // Comprobamos que el iterador pertenece a la misma
    // lista en la que realizamos la inserción.
    assert(it.head == head);
    Node *new_node = new Node{elem, it.current, it.current->prev};
    it.current->prev->next = new_node;
    it.current->prev = new_node;
    num_elems++;
    return iterator(head, new_node);
  }

  iterator erase(const_iterator it) {
    // Comprobamos que el iterador pertenece a la misma
    // lista en la que realizamos la inserción, y que no
    // estamos en el último elemento.
    assert(it.head == head && it.current != head);
    Node *target = it.current;
    it.current->prev->next = it.current->next;
    it.current->next->prev = it.current->prev;
    iterator result(head, it.current->next);
    delete target;
    num_elems--;
    return result;
  }

private:
  template <typename U> class gen_iterator {
  public:
    void advance() { current = current->next; }

    U &elem() { return current->value; }

    bool operator==(const gen_iterator &other) const {
      return (head == other.head) && (current == other.current);
    }

    bool operator!=(const gen_iterator &other) const {
      return !(*this == other);
    }

    friend class ListLinkedDouble;

  private:
    gen_iterator(Node *head, Node *current) : head(head), current(current) {}
    Node *head;
    Node *current;
  };

  Node *head;
  int num_elems;

  Node *nth_node(int n) const;
  void delete_nodes();
  void copy_nodes_from(const ListLinkedDouble &other);
};

template <typename T>
typename ListLinkedDouble<T>::Node *ListLinkedDouble<T>::nth_node(int n) const {
  int current_index = 0;
  Node *current = head->next;

  while (current_index < n && current != head) {
    current_index++;
    current = current->next;
  }

  return current;
}

template <typename T> void ListLinkedDouble<T>::delete_nodes() {
  Node *current = head->next;
  while (current != head) {
    Node *target = current;
    current = current->next;
    delete target;
  }

  delete head;
}

template <typename T>
void ListLinkedDouble<T>::copy_nodes_from(const ListLinkedDouble &other) {
  Node *current_other = other.head->next;
  Node *last = head;

  while (current_other != other.head) {
    Node *new_node = new Node{current_other->value, head, last};
    last->next = new_node;
    last = new_node;
    current_other = current_other->next;
  }
  head->prev = last;
}

template <typename T>
void ListLinkedDouble<T>::display(std::ostream &out) const {
  out << "[";
  if (head->next != head) {
    out << head->next->value;
    Node *current = head->next->next;
    while (current != head) {
      out << ", " << current->value;
      current = current->next;
    }
  }
  out << "]";
}

template <typename T>
std::ostream &operator<<(std::ostream &out, const ListLinkedDouble<T> &l) {
  l.display(out);
  return out;
}

#endif
