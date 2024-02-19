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
 * Implementación del TAD Lista mediante listas enlazadas dobles.
 *
 * Esta es la primera versión.
 */

#ifndef __LIST_LINKED_DOUBLE_H
#define __LIST_LINKED_DOUBLE_H

#include <cassert>
#include <iostream>
#include <string>

class ListLinkedDouble {
private:
  struct Node {
    std::string value;
    Node *next;
    Node *prev;
  };

public:
  ListLinkedDouble() {
    head = new Node;
    head->next = nullptr;
    head->prev = nullptr;
  }

  ~ListLinkedDouble() { delete_list(head); }

  ListLinkedDouble(const ListLinkedDouble &other)
      : head(copy_nodes(other.head)) {}

  void push_front(const std::string &elem) {
    Node *new_node = new Node{elem, head->next, head};
    if (head->next != nullptr) {
      head->next->prev = new_node;
    }
    head->next = new_node;
  }

  void push_back(const std::string &elem) {
    Node *last = last_node();
    Node *new_node = new Node{elem, nullptr, last};
    last->next = new_node;
  }

  void pop_front() {
    assert(head->next != nullptr);
    Node *target = head->next;
    head->next = target->next;
    if (target->next != nullptr) {
      target->next->prev = head;
    }
    delete target;
  }

  void pop_back() {
    assert(head->next != nullptr);
    Node *last = last_node();
    last->prev->next = nullptr;
    delete last;
  }

  int size() const;

  bool empty() const { return head->next == nullptr; };

  const std::string &front() const {
    assert(head->next != nullptr);
    return head->next->value;
  }

  std::string &front() {
    assert(head->next != nullptr);
    return head->next->value;
  }

  const std::string &back() const { return last_node()->value; }

  std::string &back() { return last_node()->value; }

  const std::string &at(int index) const {
    Node *result_node = nth_node(index);
    assert(result_node != nullptr);
    return result_node->value;
  }

  std::string &at(int index) {
    Node *result_node = nth_node(index);
    assert(result_node != nullptr);
    return result_node->value;
  }

  void display(std::ostream &out) const;

  void display() const { display(std::cout); }

private:
  Node *head;

  void delete_list(Node *start_node);
  Node *last_node() const;
  Node *nth_node(int n) const;
  Node *copy_nodes(Node *start_node) const;
};

ListLinkedDouble::Node *ListLinkedDouble::copy_nodes(Node *start_node) const {
  if (start_node != nullptr) {
    Node *copy_next = copy_nodes(start_node->next);
    Node *result = new Node{start_node->value, copy_next, nullptr};
    if (copy_next != nullptr) {
      copy_next->prev = result;
    }
    return result;
  } else {
    return nullptr;
  }
}

void ListLinkedDouble::delete_list(Node *start_node) {
  if (start_node != nullptr) {
    delete_list(start_node->next);
    delete start_node;
  }
}

int ListLinkedDouble::size() const {
  int num_nodes = 0;

  Node *current = head->next;
  while (current != nullptr) {
    num_nodes++;
    current = current->next;
  }

  return num_nodes;
}

ListLinkedDouble::Node *ListLinkedDouble::last_node() const {
  Node *current = head;
  while (current->next != nullptr) {
    current = current->next;
  }
  return current;
}

ListLinkedDouble::Node *ListLinkedDouble::nth_node(int n) const {
  assert(0 <= n);
  int current_index = 0;
  Node *current = head->next;

  while (current_index < n && current != nullptr) {
    current_index++;
    current = current->next;
  }

  return current;
}

void ListLinkedDouble::display(std::ostream &out) const {
  out << "[";
  if (head->next != nullptr) {
    out << head->next->value;
    Node *current = head->next->next;
    while (current != nullptr) {
      out << ", " << current->value;
      current = current->next;
    }
  }
  out << "]";
}

#endif
