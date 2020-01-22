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
 * Implementación de los métodos de ConjuntoCharArray.h
 */

#include "ConjuntoCharArray.h"

#include <cassert>

bool ConjuntoChar::contiene(char c) const {
  int i = 0;
  while (i < num_chars && elementos[i] != c) {
    i++;
  }
  return elementos[i] == c;
}

void ConjuntoChar::anyadir(char letra) {
  assert (num_chars < MAX_CHARS);
  assert (letra >= 'A' && letra <= 'Z');
  elementos[num_chars] = letra;
  num_chars++;
}

