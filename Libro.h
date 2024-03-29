// Libro.h
#ifndef LIBRO_H
#define LIBRO_H

#include "Informacion.h"

class Libro : public Informacion {
  private:
    std::string titulo;
    std::set<std::string> autores; //
    std::string resumen;

  public:
    Libro(int id, DTFecha f, std::string titulo, std::set<std::string> autores, std::string resumen) : Informacion(id, f), titulo(titulo), autores(autores), resumen(resumen) {} // Contructor
    std::string toString();
}

#endif // LIBRO_H