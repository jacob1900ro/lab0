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
    Libro(int id1, DTFecha f1, std::string titulo1, std::string autor1, std::string resumen1) : Informacion(id1, f1) {                                               //Constructor poor String autor
      titulo = titulo1;
      autores.insert(autor1);
      resumen = resumen1;
    } 
    std::string toString();
};

#endif // LIBRO_H