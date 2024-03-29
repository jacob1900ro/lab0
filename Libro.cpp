#include <iostream>
#include <string>
#include "Libro.h"

std::string Libro::toString(){
    std::string res = "";
    int agregados = 0; 
    for (const std::string& autor : this->autores){
        if( agregados != this->autores.size()){
            res = res + autor + ", "
            agregados++;
        }
        else{
            res = res + autor;
        }
    }
    return "El libro tiene como autores " + res + " y tiene como resumen " + this->resumen;
    // return "El libro tiene como autores " + std::to_string(autores.size()) + "y tiene como resumen " + this->resumen;
}