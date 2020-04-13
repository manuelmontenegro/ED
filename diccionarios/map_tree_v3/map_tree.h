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
 * Implementación del TAD Diccionario mediante árboles binarios
 * de búsqueda.
 *
 * Esta versión incorpora iteradores.
 */

#ifndef __MAP_TREE_H
#define __MAP_TREE_H

#include <iostream>
#include <cassert>
#include <stack>


template <typename K, typename V, typename ComparatorFunction = std::less<K>>
class MapTree {
private:
    template <typename S>
    class iterator_gen;
public:    

    struct MapEntry {
        K key;
        V value;

        MapEntry(K key, V value): key(key), value(value) { }
        MapEntry(K key): key(key) { }
    };

    using const_iterator = iterator_gen<const MapEntry &>;
    using iterator = iterator_gen<MapEntry &>;


    MapTree(): root_node(nullptr), num_elems(0) { }
    MapTree(ComparatorFunction less_than): root_node(nullptr), num_elems(0), less_than(less_than) { }
    MapTree(const MapTree &other): num_elems(other.num_elems), root_node(copy_nodes(other.root_node)) { }
    ~MapTree() {
        delete_nodes(root_node);
    }

    void insert(const MapEntry &entry) {
        if (insert(root_node, entry)) { num_elems++; }
    }

    bool contains(const K &key) const {
        return search(root_node, key) != nullptr;
    }

    const V & at(const K &key) const {
        Node *result = search(root_node, key);
        assert (result != nullptr);
        return result->entry.value;
    }

    V & at(const K &key) {
        Node *result = search(root_node, key);
        assert (result != nullptr);
        return result->entry.value;
    }

    V & operator[](const K &key) {
        bool inserted;
        Node *result = search_or_insert(root_node, key, inserted);
        if (inserted) num_elems++;
        return result->entry.value;
    }

    void erase(const K &key) {
        if (erase(root_node, key)) { num_elems--; }
    }

    int size() const {
        return num_elems;
    }
    bool empty() const {
        return num_elems == 0;
    }

    MapTree & operator=(const MapTree &other) {
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

    iterator begin() {
        return iterator(root_node);
    }

    iterator end() {
        return iterator();
    }

    const_iterator begin() const {
        return const_iterator(root_node);
    }

    const_iterator end() const {
        return const_iterator();
    }

    const_iterator cbegin() {
        return const_iterator(root_node);
    }

    const_iterator cend() {
        return const_iterator();
    }  

private:
    struct Node {
        MapEntry entry;
        Node *left, *right;

        Node(Node *left, const MapEntry &entry, Node *right): left(left), entry(entry), right(right) { }
    };

    Node *root_node;
    int num_elems;
    ComparatorFunction less_than;

    template <typename S>
    class iterator_gen {
    public:
        
        S operator*() const {
            assert(!st.empty());
            return st.top()->entry;
        }

        iterator_gen & operator++() {
            assert(!st.empty());
            Node *top = st.top();
            st.pop();
            descend_and_push(top->right, st);
            return *this;
        }

        iterator_gen operator++(int) {
            iterator_gen previous = *this;
            (*this)++;
            return previous;
        }

        bool operator==(const iterator_gen &other) {
            return st == other.st;
        }

        bool operator!=(const iterator_gen &other) {
            return !this->operator==(other);
        }

    private:
        friend class MapTree;

        iterator_gen() { }

        iterator_gen(Node *root) {
            descend_and_push(root, st);
        }

        std::stack<Node *> st;
    };


    static Node *copy_nodes(const Node *node) {
        if (node == nullptr) {
            return nullptr;
        } else {
            return new Node(copy_nodes(node->left), node->entry, copy_nodes(node->right));
        }
    }

    static void delete_nodes(const Node *node) {
        if (node != nullptr) {
            delete_nodes(node->left);
            delete_nodes(node->right);
            delete node;
        }
    }
    
    bool insert(Node * &root, const MapEntry &entry) {
        if (root == nullptr) {
            root = new Node(nullptr, entry, nullptr);
            return true;
        } else if (less_than(entry.key, root->entry.key)) {
            return insert(root->left, entry);
        } else if (less_than(root->entry.key, entry.key)) {
            return insert(root->right, entry);
        } else {
            return false;
        }
    }

    Node * search(Node *root, const K &key) const {
        if (root == nullptr) {
            return nullptr;
        } else if (less_than(key, root->entry.key)) {
            return search(root->left, key);
        } else if (less_than(root->entry.key, key)) {
            return search(root->right, key);
        } else {
            return root;
        }
    }

    Node * search_or_insert(Node * &root, const K &key, bool &inserted) {
        if (root == nullptr) {
            inserted = true;
            root = new Node(nullptr, {key}, nullptr);
            return root;
        } else if (less_than(key, root->entry.key)) {
            return search_or_insert(root->left, key, inserted);
        } else if (less_than(root->entry.key, key)) {
            return search_or_insert(root->right, key, inserted);
        } else {
            inserted = false;
            return root;
        }
    }

    bool erase(Node * &root, const K &key) {
        if (root == nullptr) {
            return false;
        } else if (less_than(key, root->entry.key)) {
            return erase(root->left, key);
        } else if (less_than(root->entry.key, key)) {
            return erase(root->right, key);
        } else {
            remove_root(root);
            return true;          
        }
    }

    static void remove_root(Node * &root) {
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


    static Node * remove_lowest(Node * &root) {
        assert (root != nullptr);
        if (root->left == nullptr) {
            root = root->right;
            return root;
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
            out << root->entry.key << " -> " << root->entry.value;
            if (root->right != nullptr) {
                out << ", ";
                display(root->right, out);
            }
        }
    }

    static void descend_and_push(Node *node, std::stack<Node *> &st) {
        Node *current = node;
        while (current != nullptr) {
            st.push(current);
            current = current->left;
        }
    }

};

template <typename K, typename V>
std::ostream & operator<<(std::ostream &out, const MapTree<K, V> &map) {
    map.display(out);
    return out;
}

#endif
