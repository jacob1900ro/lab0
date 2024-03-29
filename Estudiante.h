// Estudiante.h
#ifndef ESTUDIANTE_H
#define ESTUDIANTE_H
#include <string>
#include <vector>
#include <set>
#include <iostream>
#include "Informacion.h"

class Informacion;

class Estudiante {
    private:
  std::string nombre, email;
  int cedula;
  std::vector<Informacion *> vectorInfo = std::vector<Informacion *>(0); // Vector de Links a Informacion
  
public : Estudiante(std::string nombre, std::string email, int cedula) : nombre(nombre), email(email), cedula(cedula) {} // Constructor
  ~Estudiante();
  std::string toString();
  void insInfo(Informacion *i);
  void eliminarInfo(Informacion *i);
  std::set<std::string> listarInfo(DTFecha Desde);
  int getCedula(){return cedula;};
  std::string getNombre(){return nombre;};
}

class DTInfoEstudiante
{
private:
  int cedula;
  std::string nombreEst;
  int identificadorInfo;

public:
  DTInfoEstudiante(int c, std::string nombre, int identInfo) : cedula(c), nombreEst(nombre), identificadorInfo(identInfo) {} // Constructor
  ~DTInfoEstudiante() {
    std::cout << "Se borro correctamente";
  };
  friend std::ostream& operator<<(std::ostream& os, const DTInfoEstudiante& estudiante){
    os << estudiante.cedula << ", " << estudiante.nombreEst << ", " << estudiante.identificadorInfo;
    return os;
  }
  // std::cout << estudiante << std::endl; (imprime: "52365899, Alex García, 5")
};

#include "Informacion.h" // Incluye la declaracion completa de la clase Informacion

#endif // ESTUDIANTE_H