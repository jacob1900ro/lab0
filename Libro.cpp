#include <iostream>
#include <string>
#include "Libro.h"

std::string Libro::toString(){
    std::string res = "";
    bool primero=true;
    for (const std::string& autor : this->autores){
        if( !primero ){
            res = res + ", ";
        }
        else{
            primero=false;
        }
        res=res+autor;
    }
    return "Libro: " + std::to_string(this->identificador) + ", " +  std::to_string(this->fecha.getDia()) + "/" + std::to_string(this->fecha.getMes()) + "/" + std::to_string(this->fecha.getAnio()) + ", " + this->titulo + ", " + res + ", " + this->resumen;
}