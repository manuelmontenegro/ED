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
 * Clase Complejo, para representar números complejos.
 * Esta versión introduce sobrecarga de operadores.
 */

#include <iomanip>
#include <iostream>

class Complejo {
public:
  Complejo(double real = 0.0, double imag = 0.0) : real(real), imag(imag) {}

  double get_real() const { return real; }
  double get_imag() const { return imag; }

  void display(std::ostream &out) {
    out << real << std::showpos << imag << std::noshowpos << "i";
  }

  Complejo operator+(const Complejo &z2) {
    return {real + z2.real, imag + z2.imag};
  }

private:
  double real, imag;
};

Complejo operator+(const Complejo &z1, const Complejo &z2) {
  return {z1.get_real() + z2.get_real(), z1.get_imag() + z2.get_imag()};
}

Complejo operator*(const Complejo &z1, const Complejo &z2) {
  double z1_real = z1.get_real(), z1_imag = z1.get_imag();
  double z2_real = z2.get_real(), z2_imag = z2.get_imag();
  return {z1_real * z2_real - z1_imag * z2_imag,
          z1_real * z2_imag + z1_imag * z2_real};
}

std::ostream &operator<<(std::ostream &out, Complejo &z) {
  z.display(out);
  return out;
}
