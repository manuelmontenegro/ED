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
 * Implementación de una clase genérica para trabajar con números complejos
 */

#include <iomanip>
#include <iostream>

template <typename T = double> class Complejo {
public:
  Complejo(T real, T imag) : real(real), imag(imag) {}

  T get_real() const { return real; }
  T get_imag() const { return imag; }

  void display(std::ostream &out) const {
    out << real << std::showpos << imag << std::noshowpos << "i";
  }

  Complejo operator+(const Complejo &z1) const;
  Complejo operator*(const Complejo &z1) const;

private:
  T real, imag;
};

template <typename T>
Complejo<T> Complejo<T>::operator+(const Complejo<T> &z) const {
  return {real + z.real, imag + z.imag};
}

template <typename T>
Complejo<T> Complejo<T>::operator*(const Complejo<T> &z) const {
  return {real * z.real - imag * z.imag, real * z.imag + imag * z.real};
}

template <typename T>
std::ostream &operator<<(std::ostream &out, const Complejo<T> &z) {
  z.display(out);
  return out;
}
