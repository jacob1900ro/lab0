// PaginaWeb.h
#ifndef PAGINAWEB_H
#define PAGINAWEB_H

#include "Informacion.h"

class PaginaWeb : public Informacion {
private:
  std::string titulo, link, texto;

public:
  PaginaWeb(int id, DTFecha f, std::string t, std::string l, std::string txt)
      : Informacion(id, f), titulo(t), link(l), texto(txt) {}
  std::string toString(){
    return "PaginaWeb: " + std::to_string(this->identificador) + ", " +
         std::to_string(fecha.getDia()) + "/" + std::to_string(fecha.getMes()) + "/" + std::to_string(fecha.getAnio()) +
         ", " + this->titulo + ", " + this->link + ", " + this->texto;
  }
  ~PaginaWeb(){}
};


#endif // PAGINAWEB_H