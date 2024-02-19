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
 * Implementación del TAD Cola mediante listas enlazadas.
 */

#ifndef __QUEUE_LINKEDLIST_H
#define __QUEUE_LINKEDLIST_H

#include <cassert>
#include <iostream>

template <typename T> class QueueLinkedList {
public:
  QueueLinkedList() : front_node(nullptr), back_node(nullptr) {}
  QueueLinkedList(const QueueLinkedList &other) {
    copy_nodes_from(other.front_node);
  }

  ~QueueLinkedList() { free_nodes_from(front_node); }

  QueueLinkedList &operator=(const QueueLinkedList &other) {
    if (this != &other) {
      free_nodes_from(front_node);
      copy_nodes_from(other.front_node);
    }
    return *this;
  }

  void push(const T &elem) {
    Node *new_node = new Node{elem, nullptr};
    if (back_node == nullptr) {
      back_node = new_node;
      front_node = new_node;
    } else {
      back_node->next = new_node;
      back_node = new_node;
    }
  }

  void pop() {
    assert(front_node != nullptr);
    Node *target = front_node;
    front_node = front_node->next;
    if (back_node == target) {
      back_node = nullptr;
    }
    delete target;
  }

  T &front() {
    assert(front_node != nullptr);
    return front_node->value;
  }

  const T &front() const {
    assert(front_node != nullptr);
    return front_node->elem;
  }

  bool empty() const { return (front_node == nullptr); }

private:
  struct Node {
    T value;
    Node *next;
  };

  void copy_nodes_from(Node *other);
  void free_nodes_from(Node *other);

  Node *front_node;
  Node *back_node;
};

template <typename T> void QueueLinkedList<T>::copy_nodes_from(Node *other) {
  if (other == nullptr) {
    front_node = nullptr;
    back_node = nullptr;
  } else {
    front_node = new Node{other->value, nullptr};
    back_node = front_node;
    Node *current = other->next;
    while (current != nullptr) {
      Node *new_node = new Node{current->value, nullptr};
      back_node->next = new_node;
      current = current->next;
      back_node = new_node;
    }
  }
}

template <typename T> void QueueLinkedList<T>::free_nodes_from(Node *other) {
  Node *current = other;
  while (current != nullptr) {
    Node *next = current->next;
    delete current;
    current = next;
  }
}

#endif
