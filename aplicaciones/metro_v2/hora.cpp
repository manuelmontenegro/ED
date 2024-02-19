#include "hora.h"

std::ostream &operator<<(std::ostream &out, const Hora &hora) {
  hora.display(out);
  return out;
}
