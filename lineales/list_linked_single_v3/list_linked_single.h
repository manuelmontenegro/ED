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
  * Implementación del TAD Lista mediante listas enlazadas simples.
  *
  * Esta versión introduce el nodo fantasma.
  */
  
#ifndef __LIST_LINKED_SINGLE_H
#define __LIST_LINKED_SINGLE_H

#include <cassert>
#include <iostream>
#include <string>


class ListLinkedSingle {
private:
  struct Node {
    std::string value;
    Node *next;
  };

public:
  ListLinkedSingle() { 
    head = new Node;
    head->next = nullptr;
  }
  
  ~ListLinkedSingle() {
    delete_list(head);
  }

  ListLinkedSingle(const ListLinkedSingle &other)
    : head(copy_nodes(other.head)) { }

  void push_front(const std::string &elem) {
    Node *new_node = new Node { elem, head->next };
    head->next = new_node;
  }

  void push_back(const std::string &elem);

  void pop_front() {
    assert (head->next != nullptr);
    Node *old_head = head->next;
    head->next = head->next->next;
    delete old_head;
  }

  void pop_back();

  int size() const;

  bool empty() const {
    return head->next == nullptr;
  };
  
  const std::string & front() const {
    assert (head->next != nullptr);
    return head->next->value;
  }

  std::string & front() {
    assert (head->next != nullptr);
    return head->next->value;
  }

  const std::string & back() const {
    return last_node()->value;
  }

  std::string & back() {
    return last_node()->value;
  }
  
  const std::string & at(int index) const {
    Node *result_node = nth_node(index);
    assert (result_node != nullptr);
    return result_node->value;
  }

  std::string & at(int index) {
    Node *result_node = nth_node(index);
    assert (result_node != nullptr);
    return result_node->value;
  }

  void display(std::ostream &out) const;
  
  void display() const {
    display(std::cout);
  }

private:
  Node *head;

  void delete_list(Node *start_node);
  Node *last_node() const;
  Node *nth_node(int n) const;
  Node *copy_nodes(Node *start_node) const;

};

ListLinkedSingle::Node * ListLinkedSingle::copy_nodes(Node *start_node) const {
  if (start_node != nullptr) {
    Node *result = new Node { start_node->value, copy_nodes(start_node->next) };
    return result;
  } else {
    return nullptr;
  }
}

void ListLinkedSingle::delete_list(Node *start_node) {
  if (start_node != nullptr) {
    delete_list(start_node->next);
    delete start_node;
  }
}

void ListLinkedSingle::push_back(const std::string &elem) {
  Node *new_node = new Node { elem, nullptr };
  last_node()->next = new_node;
}

void ListLinkedSingle::pop_back() {
  assert (head->next != nullptr);
  Node *previous = head;
  Node *current = head->next;

  while (current->next != nullptr) {
    previous = current;
    current = current->next;
  }

  delete current;
  previous->next = nullptr;
}

int ListLinkedSingle::size() const {
  int num_nodes = 0;

  Node *current = head->next;
  while (current != nullptr) {
    num_nodes++;
    current = current->next;
  }

  return num_nodes;
}

ListLinkedSingle::Node * ListLinkedSingle::last_node() const {
  Node *current = head;
  while (current->next != nullptr) {
    current = current->next;
  }
  return current;
}

ListLinkedSingle::Node * ListLinkedSingle::nth_node(int n) const {
  assert (0 <= n);
  int current_index = 0;
  Node *current = head->next;

  while (current_index < n && current != nullptr) {
    current_index++;
    current = current->next;
  }

  return current;
}

void ListLinkedSingle::display(std::ostream &out) const {
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
