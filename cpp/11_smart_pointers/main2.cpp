/*
 * ---------------------------------------------------
 *                ESTRUCTURAS DE DATOS
 * ---------------------------------------------------
 *              Manuel Montenegro Montes
 *              Facultad de Informática
 *         Universidad Complutense de Madrid
 * ---------------------------------------------------
 */

/* Uso de punteros inteligentes compartidos (shared_ptr) */

#include "Fecha.h"
#include <iostream>
#include <memory>

using namespace std;

int main() {
  std::shared_ptr<Fecha> f1 = std::make_shared<Fecha>(25, 12, 2019);

  std::cout << "f1 apunta a un objeto Fecha con año " << f1->get_anyo()
            << std::endl;
  std::cout << "f1 apunta al objeto Fecha " << *f1 << std::endl;

  std::shared_ptr<Fecha> f2 = f1;
  std::shared_ptr<Fecha> f3 = f2;

  f1 = std::make_shared<Fecha>(9, 2, 2020);
  f2 = nullptr;
  f3 = nullptr;

  std::cout << "Fin de programa" << std::endl;
  return 0;
}
