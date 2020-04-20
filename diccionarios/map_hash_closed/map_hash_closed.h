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
 * Implementación del TAD Diccionario mediante tablas hash
 * cerradas. El tamaño no varía a medida que se llena la tabla.
 */

#ifndef __MAP_HASH_CLOSED
#define __MAP_HASH_CLOSED

#include <string>
#include <iostream>
#include <cassert>
#include <forward_list>

const int CAPACITY = 31;

template <typename K, typename V, typename Hash = std::hash<K>>
class MapHash {
public:
    struct MapEntry {
        K key;
        V value;

        MapEntry(K key, V value): key(key), value(value) { }
        MapEntry(K key): key(key) { }
        MapEntry() { }
    };

    MapHash(): num_elems(0), buckets(new Bucket[CAPACITY]) { }

    MapHash(const MapHash &other): num_elems(other.num_elems), buckets(new Bucket[CAPACITY]) {
        copy(other.buckets, other.buckets + CAPACITY, buckets);
    }

    ~MapHash() {
        delete[] buckets;
    }
    

    void insert(const MapEntry &entry) {
        int pos_to_insert, pos_found;
        search_pos(entry.key, pos_to_insert, pos_found);
        if (pos_found == -1) {
            assert (pos_to_insert != -1);
            buckets[pos_to_insert].state = State::occupied;
            buckets[pos_to_insert].entry = entry;
            num_elems++;
        }
    }

    bool contains(const K &key) const {
        int pos_to_insert, pos_found;
        search_pos(key, pos_to_insert, pos_found);
        return pos_found != -1;
    }

    const V & at(const K &key) const {
        int pos_to_insert, pos_found;
        search_pos(key, pos_to_insert, pos_found);
        assert (pos_found != -1);
        return buckets[pos_found].entry.value;
    }

    V & at(const K &key) {
        int pos_to_insert, pos_found;
        search_pos(key, pos_to_insert, pos_found);
        assert (pos_found != -1);
        return buckets[pos_found].entry.value;
    }

    V & operator[](const K &key) {
        int pos_to_insert, pos_found;
        search_pos(key, pos_to_insert, pos_found);
        if (pos_found == -1) {
            buckets[pos_to_insert].state = State::occupied;
            buckets[pos_to_insert].entry = MapEntry(key);
            num_elems++;
            return buckets[pos_to_insert].entry.value;
        } else {
            return buckets[pos_found].entry.value;
        }
    }

    void erase(const K &key) {
        int pos_to_insert, pos_found;
        search_pos(key, pos_to_insert, pos_found);
        if (pos_found != -1) {
            buckets[pos_found].state = State::deleted;
            num_elems--;
        }
    }

    int size() const {
        return num_elems;
    }

    bool empty() const {
        return num_elems == 0;
    }

    MapHash & operator=(const MapHash &other) {
        if (this != &other) {
            num_elems = other.num_elems;
            hash = other.hash;
            copy(other.buckets, other.buckets + CAPACITY, buckets);
        }
        return *this;
    }

    void display(std::ostream &out) const {
        out << "{";
        bool first = true;
        for (int i = 0; i < CAPACITY; i++) {
            if (buckets[i].state == State::occupied) {
                if (!first) {
                    out << ", ";
                } else {
                    out << " ";
                    first = false;
                }
                out << buckets[i].entry.key << " -> " << buckets[i].entry.value;
            }
        }
        out << " }";
    }
private:
    enum class State { empty, occupied, deleted };
    
    struct Bucket {
        State state;
        MapEntry entry;

        Bucket(): state(State::empty) { }
    };

    Hash hash;

    Bucket *buckets;
    int num_elems;

    void search_pos(const K &key, int &pos_to_insert, int &pos_found) const {
        int h = hash(key) % CAPACITY;
        int cont = 0;

        pos_to_insert = -1;
        pos_found = -1;

        while (cont < CAPACITY && pos_found == -1 && buckets[h].state != State::empty) {
            if (pos_to_insert == -1 && buckets[h].state == State::deleted) {
                pos_to_insert = h;
            }

            if (buckets[h].state == State::occupied && buckets[h].entry.key == key) {
                pos_found = h;
            }

            h = (h + 1) % CAPACITY;
            cont++;
        }

        if (cont < CAPACITY && pos_to_insert == -1)  {
            pos_to_insert = h;
        }
    }
    
};

template <typename K, typename V>
std::ostream & operator<<(std::ostream &out, const MapHash<K, V> &map) {
    map.display(out);
    return out;
}

#endif
