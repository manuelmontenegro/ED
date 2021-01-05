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
 * TAD ConjuntoChar, implementado mediante un array de booleanos
 */

#include <cassert>

const int MAX_CHARS = 26;

struct ConjuntoChar {
  bool esta[MAX_CHARS];
};


bool pertenece(char c, const ConjuntoChar &conjunto) {
  assert (c >= 'A' && c <= 'Z');
  return conjunto.esta[c - 'A'];
}

void vacio(ConjuntoChar &result) {
  for (int i = 0; i < MAX_CHARS; i++) {
    result.esta[i] = false;
  }
}

void anyadir(char letra, ConjuntoChar &conjunto) {
  assert (letra >= 'A' && letra <= 'Z');
  conjunto.esta[letra - 'A'] = true;
}
