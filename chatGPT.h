// ChatGPT.h
#ifndef CHATGPT_H
#define CHATGPT_H

#include "Informacion.h"

class chatGPT : public Informacion {
  private:
    std::string pregunta, respuesta;
  public:
    chatGPT(int id, DTFecha f, std::string p, std::string r) : Informacion(id, f), pregunta(p), respuesta(r) {}; // Constructor
    std::string toString(){
      return "ChatGPT: "+ std::to_string(this->identificador)+ ", " +  std::to_string(this->fecha.getDia()) + "/" + std::to_string(this->fecha.getMes()) + "/" + std::to_string(this->fecha.getAnio()) + ", " + this->pregunta+ ", " + this->respuesta;
    };
    ~chatGPT(){}; // Destructor
};

#endif // CHATGPT_H
