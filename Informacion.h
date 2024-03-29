// Informacion.h
#ifndef INFORMACION_H
#define INFORMACION_H

#include <string>
#include <vector>
#include "DTFecha.h"
#include "Estudiante.h"

class Estudiante; // declaracion en avanzada

class Informacion {
protected:
  int identificador;
  DTFecha fecha;
  std::vector<Estudiante *> vectorEst = std::vector<Estudiante *>(0);

public:
  virtual std::string toString();
  void insEst(Estudiante *e);
  Informacion(int id, DTFecha f) : identificador(id), fecha(f) {} // Constructor
  ~Informacion(); // Destructor
  int getIdentificador() { return identificador; }
  DTFecha getFecha() { return fecha; }
  void eliminarEst(Estudiante *e);
};

#include "Estudiante.h"

#endif // INFORMACION_H