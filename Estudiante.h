// Estudiante.h
#ifndef ESTUDIANTE_H
#define ESTUDIANTE_H
#include <string>
#include <vector>
#include <set>
#include <iostream>

class Informacion;

class Estudiante {
    private:
  std::string nombre, email;
  int cedula;
  // std::set<Informacion *> info;
  std::vector<Informacion *> vectorInfo = std::vector<Informacion *>(0); // Vector de Links a Informacion
  
public : Estudiante(std::string nombre, std::string email, int cedula) : nombre(nombre), email(email), cedula(cedula) {} // Constructor
  ~Estudiante();
  std::string toString();
  void insInfo(Informacion *i);
  void eliminarInfo(Informacion *i);
  std::set<std::string> listarInfo(DTFecha Desde);
  int getCedula(){return cedula;};
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
};

#include "Informacion.h" // Incluye la declaracion completa de la clase Informacion

#endif // ESTUDIANTE_H