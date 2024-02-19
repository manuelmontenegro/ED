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
 * TAD ConjuntoChar, implementado mediante un array de caracteres
 */

#include <cassert>

const int MAX_CHARS = 26;

struct ConjuntoChar {
  int num_chars;
  char elementos[MAX_CHARS];
};


bool pertenece(char c, const ConjuntoChar &conjunto) {
  int i = 0;
  while (i < conjunto.num_chars && conjunto.elementos[i] != c) {
    i++;
  }
  return conjunto.elementos[i] == c;
}

void vacio(ConjuntoChar &conjunto) {
  conjunto.num_chars = 0;
}

void anyadir(char letra, ConjuntoChar &conjunto) {
  assert (conjunto.num_chars < MAX_CHARS);
  assert (letra >= 'A' && letra <= 'Z');
  conjunto.elementos[conjunto.num_chars] = letra;
  conjunto.num_chars++;
}

