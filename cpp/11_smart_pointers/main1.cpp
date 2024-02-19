/*
 * ---------------------------------------------------
 *                ESTRUCTURAS DE DATOS
 * ---------------------------------------------------
 *              Manuel Montenegro Montes
 *              Facultad de Informática
 *         Universidad Complutense de Madrid
 * ---------------------------------------------------
 */

/* Uso de punteros inteligentes exclusivos (unique_ptr) */

#include "Fecha.h"
#include <iostream>
#include <memory>

using namespace std;

int main() {
  std::unique_ptr<Fecha> f1 = std::make_unique<Fecha>(25, 12, 2019);

  std::unique_ptr<Fecha> f2 = std::move(f1);

  f1 = std::make_unique<Fecha>(10, 12, 2020);

  if (f1 != nullptr) {
    std::cout << "f1 apunta a la fecha con año " << f1->get_anyo() << std::endl;
    std::cout << "f1 apunta a la fecha " << *f1 << std::endl;
  }

  f1 = nullptr;

  std::cout << "Vale" << std::endl;

  return 0;
}
