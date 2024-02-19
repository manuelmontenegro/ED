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
 * Implementación del TAD Conjunto mediante árboles binarios de búsqueda.
 *
 * Esta versión añade iteradores.
 */

#ifndef __SET_TREE_H
#define __SET_TREE_H

#include <cassert>
#include <iostream>
#include <stack>

template <typename T, typename ComparatorFunction = std::less<T>>
class SetTree {

private:
  struct Node;

public:
  SetTree(ComparatorFunction less_than)
      : root_node(nullptr), num_elems(0), less_than(less_than) {}
  SetTree() : root_node(nullptr), num_elems(0) {}
  SetTree(const SetTree &other)
      : num_elems(other.num_elems), root_node(copy_nodes(other.root_node)) {}
  ~SetTree() { delete_nodes(root_node); }

  void insert(const T &elem) {
    bool inserted = insert(root_node, elem);
    if (inserted) {
      num_elems++;
    }
  }

  bool contains(const T &elem) const { return search(root_node, elem); }

  void erase(const T &elem) {
    bool removed = erase(root_node, elem);
    if (removed) {
      num_elems--;
    }
  }

  int size() const { return num_elems; }
  bool empty() const { return num_elems == 0; }

  SetTree &operator=(const SetTree &other) {
    if (this != &other) {
      num_elems = other.num_elems;
      delete_nodes(root_node);
      root_node = copy_nodes(other.root_node);
    }
    return *this;
  }

  void display(std::ostream &out) const {
    out << "{";
    display(root_node, out);
    out << "}";
  }

  class iterator {
  public:
    const T &operator*() const {
      assert(!st.empty());
      return st.top()->elem;
    }

    const T *operator->() const { return &operator*(); }

    iterator &operator++() {
      assert(!st.empty());
      Node *top = st.top();
      st.pop();
      descend_and_push(top->right, st);
      return *this;
    }

    iterator operator++(int) {
      iterator previous = *this;
      ++(*this);
      return previous;
    }

    bool operator==(const iterator &other) { return st == other.st; }

    bool operator!=(const iterator &other) { return !this->operator==(other); }

  private:
    friend class SetTree;

    iterator() {}

    iterator(Node *root) { descend_and_push(root, st); }

    std::stack<Node *> st;
    static void descend_and_push(Node *node, std::stack<Node *> &st) {
      Node *current = node;
      while (current != nullptr) {
        st.push(current);
        current = current->left;
      }
    }
  };

  iterator begin() const { return iterator(root_node); }

  iterator end() const { return iterator(); }

private:
  struct Node {
    T elem;
    Node *left, *right;

    Node(Node *left, const T &elem, Node *right)
        : left(left), elem(elem), right(right) {}
  };

  Node *root_node;
  int num_elems;

  ComparatorFunction less_than;

  static Node *copy_nodes(const Node *node) {
    if (node == nullptr) {
      return nullptr;
    } else {
      return new Node(copy_nodes(node->left), node->elem,
                      copy_nodes(node->right));
    }
  }

  static void delete_nodes(const Node *node) {
    if (node != nullptr) {
      delete_nodes(node->left);
      delete_nodes(node->right);
      delete node;
    }
  }

  bool insert(Node *&root, const T &elem) {
    if (root == nullptr) {
      root = new Node(nullptr, elem, nullptr);
      return true;
    } else if (less_than(elem, root->elem)) {
      return insert(root->left, elem);
    } else if (less_than(root->elem, elem)) {
      return insert(root->right, elem);
    } else {
      return false;
    }
  }

  bool search(const Node *root, const T &elem) const {
    if (root == nullptr) {
      return false;
    } else if (less_than(elem, root->elem)) {
      return search(root->left, elem);
    } else if (less_than(root->elem, elem)) {
      return search(root->right, elem);
    } else {
      return true;
    }
  }

  bool erase(Node *&root, const T &elem) {
    if (root == nullptr) {
      return false;
    } else if (less_than(elem, root->elem)) {
      return erase(root->left, elem);
    } else if (less_than(root->elem, elem)) {
      return erase(root->right, elem);
    } else {
      remove_root(root);
      return true;
    }
  }

  static void remove_root(Node *&root) {
    Node *left_child = root->left, *right_child = root->right;
    delete root;
    if (left_child == nullptr && right_child == nullptr) {
      root = nullptr;
    } else if (left_child == nullptr) {
      root = right_child;
    } else if (right_child == nullptr) {
      root = left_child;
    } else {
      Node *lowest = remove_lowest(right_child);
      lowest->left = left_child;
      lowest->right = right_child;
      root = lowest;
    }
  }

  static Node *remove_lowest(Node *&root) {
    assert(root != nullptr);
    if (root->left == nullptr) {
      Node *result = root;
      root = root->right;
      return result;
    } else {
      return remove_lowest(root->left);
    }
  }

  static void display(Node *root, std::ostream &out) {
    if (root != nullptr) {
      if (root->left != nullptr) {
        display(root->left, out);
        out << ", ";
      }
      out << root->elem;
      if (root->right != nullptr) {
        out << ", ";
        display(root->right, out);
      }
    }
  }
};

template <typename T>
std::ostream &operator<<(std::ostream &out, const SetTree<T> &set) {
  set.display(out);
  return out;
}

#endif
