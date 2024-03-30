#include <iostream>
#include "Informacion.h"
#include "Estudiante.h"

void Informacion::insEst(Estudiante *e) {
    vectorEst.push_back(e); // se crea un lugar en la informacion
    //e->insInfo(this);   //////////////////// agregarle la info al estudiante
}

void Informacion::eliminarEst(Estudiante *e) {
    int m=0 ;
    while((vectorEst[m]->getCedula()!= e->getCedula()) && (m<vectorEst.size())){
      m++;
    }
    if (m<vectorEst.size()){
      vectorEst.erase(vectorEst.begin()+m);
    }
    else {
      std::cout<<"La cagamos xd ";
    }
}

Informacion::~Informacion(){            //Destructor
  for(int i=0 ; i < vectorEst.size(); i++ ) {  
    vectorEst[i]->eliminarInfo(this);
  }
  vectorEst.clear();                          //Borra el vector de punteros a estudiantes
}