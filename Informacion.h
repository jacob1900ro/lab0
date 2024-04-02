// Informacion.h
#ifndef INFORMACION_H
#define INFORMACION_H

#include <vector>
#include "DTFecha.h"

class Estudiante; // declaracion en avanzada

class Informacion {
protected:
  int identificador;
  DTFecha fecha;
  // = std::vector<Estudiante *>(0);
  std::vector<Estudiante *> vectorEst;
public:
  virtual std::string toString()=0;
  void insEst(Estudiante *e);
  Informacion(int id, DTFecha f) : identificador(id), fecha(f) {}; // Constructorm
  virtual ~Informacion(); // Destructor
  int getIdentificador() { return identificador; };
  DTFecha getFecha() { return fecha; };
  Estudiante * getEst(int j){ return vectorEst[j]; };
  int getTamVector(){return vectorEst.size();};
  void eliminarEst(Estudiante *e);
};

#include "Estudiante.h"

#endif // INFORMACION_H