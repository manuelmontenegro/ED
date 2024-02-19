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
 * Implementación de los métodos de ConjuntoChar.h
 */

#include "ConjuntoChar.h"

#include <cassert>

ConjuntoChar::ConjuntoChar() {
  for (int i = 0; i < MAX_CHARS; i++) {
    esta[i] = false;
  }
}

bool ConjuntoChar::contiene(char l) const {
  assert (l >= 'A' && l <= 'Z');
  return esta[l - (int)'A'];
}

void ConjuntoChar::anyadir(char l) {
  assert (l >= 'A' && l <= 'Z');
  esta[l - (int) 'A'] = true;
}

