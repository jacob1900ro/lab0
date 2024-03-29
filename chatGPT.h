// ChatGPT.h
#ifndef CHATGPT_H
#define CHATGPT_H

#include <string>
#include "Informacion.h"

class chatGPT : public Informacion {
  private:
    std::string pregunta, respuesta;
  public:
    chatGPT(int id, DTFecha f, std::string p, std::string r) : Informacion(id, f), pregunta(p), respuesta(r) {} // Constructor
    std::string toString();
    ~chatGPT(){}; // Destructor
}
std::string chatGPT::toString()
{
  return "La respuesta a la pregunta " + this->pregunta + " es " + this->respuesta + ". Espero que le resulte de ayuda.";
};

#endif // CHATGPT_H