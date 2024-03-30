#include <iostream>
#include <string>
#include <vector>
#include "Estudiante.h"
#include "Informacion.h"
#include "PaginaWeb.h"
#include "ChatGPT.h"
#include "Libro.h"

  std::string Estudiante::toString(){
  return "El nombre del estudiante es " + this->nombre + " con email " + this->email + " y su cedula es " + std::to_string(this->cedula);
} 

void Estudiante::insInfo(Informacion *i) {
    vectorInfo.push_back(i); // se crea un lugar en la informacion
    /* Estudiante* est = this;
    i->insEst(est);// Se agrega el estudiante a la info */
}

void Estudiante::eliminarInfo(Informacion *i) {
    int m=0;
  while((vectorInfo[m]->getIdentificador()!= i->getIdentificador()) && (m<vectorInfo.size())){
    m++;
  }
  if (m<vectorInfo.size()){
    vectorInfo.erase(vectorInfo.begin()+m);
  }
  else {
    std::cout<<"La cagamos xd";
  }
}

Estudiante::~Estudiante() {
for(int i=0 ; i < vectorInfo.size(); i++ ) {  
    vectorInfo[i]->eliminarEst(this);
  }
  vectorInfo.clear();
}

std::set<std::string> Estudiante::listarInfo(DTFecha Desde)   
{
  std::set<std::string> res;
  for (int j = 0; j<vectorInfo.size();j++)
  {
    if ((vectorInfo[j]->getFecha().getAnio() > Desde.getAnio()) ||
        (vectorInfo[j]->getFecha().getAnio() == Desde.getAnio() && vectorInfo[j]->getFecha().getMes() > Desde.getMes()) ||
        (vectorInfo[j]->getFecha().getAnio() == Desde.getAnio() && vectorInfo[j]->getFecha().getMes() == Desde.getMes() && vectorInfo[j]->getFecha().getDia() > Desde.getDia()))
    {
      res.insert(vectorInfo[j]->toString());
    }
  }
  return res;
}