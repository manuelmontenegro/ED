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
 * Implementación inicial del TAD de los árboles binarios.
 *
 * Esta implementación libera la memoria producida, pero a
 * cambio de realizar copias de los nodos cada vez que construye
 * un árbol a partir de sus hijos.
 */

#ifndef __BINTREE_H
#define __BINTREE_H

#include <cassert>
#include <iostream>

template <class T> class BinTree {
public:
  BinTree() : root_node(nullptr) {}
  BinTree(const T &elem) : root_node(new TreeNode{nullptr, elem, nullptr}) {}
  BinTree(const BinTree &left, const T &elem, const BinTree &right)
      : root_node(new TreeNode{copy_with_children(left.root_node), elem,
                               copy_with_children(right.root_node)}) {}

  BinTree(const BinTree &other) {
    root_node = copy_with_children(other.root_node);
  }

  ~BinTree() { delete_with_children(root_node); }

  bool empty() const { return root_node == nullptr; }

  const T &root() const {
    assert(root_node != nullptr);
    return root_node->elem;
  }

  BinTree left() const {
    assert(root_node != nullptr);
    BinTree result;
    result.root_node = copy_with_children(root_node->left);
    return result;
  }

  BinTree right() const {
    assert(root_node != nullptr);
    BinTree result;
    result.root_node = copy_with_children(root_node->right);
    return result;
  }

  void display(std::ostream &out) const { display_node(root_node, out); }

private:
  struct TreeNode {
    TreeNode(TreeNode *left, const T &elem, TreeNode *right)
        : elem(elem), left(left), right(right) {}

    T elem;
    TreeNode *left, *right;
  };

  TreeNode *root_node;

  static void display_node(const TreeNode *root, std::ostream &out) {
    if (root == nullptr) {
      out << ".";
    } else {
      out << "(";
      display_node(root->left, out);
      out << " " << root->elem << " ";
      display_node(root->right, out);
      out << ")";
    }
  }

  static TreeNode *copy_with_children(const TreeNode *root) {
    if (root == nullptr) {
      return nullptr;
    } else {
      return new TreeNode{copy_with_children(root->left), root->elem,
                          copy_with_children(root->right)};
    }
  }

  static void delete_with_children(const TreeNode *root) {
    if (root != nullptr) {
      delete_with_children(root->left);
      delete_with_children(root->right);
      delete root;
    }
  }
};

template <typename T>
std::ostream &operator<<(std::ostream &out, const BinTree<T> &tree) {
  tree.display(out);
  return out;
}

template <typename T> BinTree<T> read_tree(std::istream &in) {
  char c;
  in >> c;
  if (c == '.') {
    return BinTree<T>();
  } else {
    assert(c == '(');
    BinTree<T> left = read_tree<T>(in);
    T elem;
    in >> elem;
    BinTree<T> right = read_tree<T>(in);
    in >> c;
    assert(c == ')');
    BinTree<T> result(left, elem, right);
    return result;
  }
}

#endif
