
#include <string>
#include <vector>
#include <set>
#include <iostream>
#include "DTInfoEstudiante.h"

/*
class DTInfoEstudiante
{
private:
  int cedula;
  std::string nombreEst;
  int identificadorInfo;

public:
  DTInfoEstudiante(int c, std::string nombre, int identificadorInfo) : cedula(c), nombreEst(nombre), identificadorInfo(identificadorInfo) {} // Constructor
  ~DTInfoEstudiante()
  {
    std::cout << "se borro correctamente";
  };
};
*/

std::ostream &operator<<(std::ostream &o, const DTInfoEstudiante &estudiante)
{
  // o << "lo que diga el string" //sobrecarga de <<
  return o;
}

class DTFecha
{
private:
  int dia, mes, anio;

public:
  DTFecha(int d, int m, int a) : dia(d), mes(m), anio(a) {} // Constructor
  ~DTFecha()
  { // Destructor
    std::cout << "se elimino corectamente";
  }
  int getDia() { return dia; };
  int getMes() { return mes; };
  int getAnio() { return anio; };
};

class Informacion;      //Desclaracion forward de la clase informacion
class Estudiante
{
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
};

Estudiante::~Estudiante(){
  for(int i=0 ; i < vectorInfo.size(); i++ ) {  
    vectorInfo[i]->eliminarEst(this);
  }
  vectorInfo.clear();
}


void Estudiante::eliminarInfo (Informacion *i){
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

void Estudiante::insInfo(Informacion *i)
{
  vectorInfo.push_back(i); // se crea un lugar en la informacion
  i->insEst(this);////////////////////falta agregarke al estudiante la informacion 
}


std::string Estudiante::toString()
{
  return "El nombre del estudiante es " + this->nombre + "con email " + this->email + "y su cedula es " + this->cedula;
}

std::set<std::string> Estudiante::listarInfo(DTFecha Desde)   
{
  std::set<std::string> res;
  for (auto it = info.begin(); it != info.end(); it++)
  {
    if ((it->getFecha().getAnio() > Desde.getAnio()) ||
        (it->getFecha().getAnio() == Desde.getAnio() && it->getFecha().getMes() > Desde.getMes()) ||
        (it->getFecha().getAnio() == Desde.getAnio() && it->getFecha().getMes() == Desde.getMes() && it->getFecha().getDia() > Desde.getDia()))
    {
      res.insert(it->toString());
    }
  }
  return res;
}

class Informacion
{
protected:
  int identificador;
  DTFecha fecha;
  std::vector<Estudiante *> vectorEst = std::vector<Estudiante *>(0);

public:
  virtual std::string toString();
  void insEst(Estudiante *e);
  Informacion(int id, DTFecha f) : identificador(id), fecha(f) {} // Constructor
  ~Informacion() {} // Destructor
  int getIdentificador() { return identificador; }
  DTFecha getFecha() { return fecha; }
  void eliminarEst(Estudiante *e);
};

Informacion::~Informacion(){            //Destructor
  for(int i=0 ; i < vectorEst.size(); i++ ) {  
    vectorEst[i]->eliminarInfo(this);
  }
  vectorEst.clear();                            //Borra el vector de punteros a estudiantes
}


void Informacion::insEst(Estudiante *e)
{
  vectorEst.push_back(e); // se crea un lugar en la informacion
  e->insInfo(this);   //////////////////// agregarle a la informacion el estuidante
}

void Informacion::eliminarEst (Estudiante * e){
  int m=0 ;
  while((vectorEst[m]->getCedula()!= e->getCedula()) && (m<vectorEst.size())){
    m++;
  }
  if (m<vectorInfo.size()){
    vectorEst.erase(vectorEst.begin()+m);
  }
  else {
    std::cout<<"La cagamos xd ";
  }
}

class Libro : public Informacion
{
private:
  std::string titulo;
  std::set<std::string> autores; //
  std::string resumen;

public:
  Libro(int id, DTFecha f, std::string titulo, std::set<std::string> autores, std::string resumen) : Informacion(id, f), titulo(titulo), autores(autores), resumen(resumen) {} // Contructor
  std::string toString();
};



std::string Libro::toString()
{
  return "El libro tiene como autores " + std::to_string(autores.size()) + "y tiene como resumen " + this->resumen;
}

class PaginaWeb : public Informacion
{
private:
  std::string titulo, link, texto;

public:
  PaginaWeb(int id, DTFecha f, std::string t, std::string l, std::string txt)
      : Informacion(id, f), titulo(t), link(l), texto(txt) {}
  std::string toString();
  ~PaginaWeb(){}
};
std::string PaginaWeb::toString()
{
  return "PaginaWeb " + std::to_string(identificador) + ", " +
         std::to_string(fecha.getDia()) + "/" + std::to_string(fecha.getMes()) + "/" + std::to_string(fecha.getAnio()) +
         ", " + this->titulo + ", " + this->link + ", " + this->texto;
};

class chatGPT : public Informacion
{
private:
  std::string pregunta, respuesta;

public:
  chatGPT(int id, DTFecha f, std::string p, std::string r) : Informacion(id, f), pregunta(p), respuesta(r) {} // Constructor
  std::string toString();
  ~chatGPT(){}; // Destructor
};

std::string chatGPT::toString()
{
  return "La respuesta a la pregunta " + this->pregunta + " es " + this->respuesta + ". Espero que le resulte de ayuda.";
};

void imprimir(Estudiante estudiante){
  std::cout << "Informacion del estudiante \n";
  std::set><std::string> infoEstudiante = estudiante.listarInfo(DTFecha(8, 3, 2024));
    for (const auto &info : infoEstudiante) {
        std::cout << info << std::endl;
    }
};

int main() 
{
  PaginaWeb paginaWeb1(1, DTFecha(7, 3, 2024),"" ,"Programación 4 Guía Semana 1 (4/3)","https://eva.fing.edu.uy/pluginfile.php/468051/mod_resource/content/4/Guia01_P42024_IntroCBasicos.pdf", "El objetivo de esta semana es contextualizar el paradigma de Orientación a Objetos (OO) en el marco de la Ingeniería de Software, así como comenzar a ver sus conceptos básicos y cómo éstos se implementan en C++.");

  PaginaWeb paginaWeb2(2, DTFecha(5, 3, 2024), "Programación orientada a objetos", "https://es.wikipedia.org/wiki/Programaci%C3%B3n_orientada_a_objetos","La programación orientada a objetos (POO, en español) es un paradigma deprogramación que parte del concepto de objetos como base, los cuales contienen información en forma de campos (a veces también referidos como atributos o propiedades) y código en forma de métodos. Algunas características clave de la programación orientada a objetos son herencia, cohesión, abstracción, polimorfismo, acoplamiento y encapsulamiento.");

  chatGPT chatGPT3(3, DTFecha(8, 3, 2024), "¿Qué es el polimorfismo en orientación a objetos?", "El polimorfismo en programación orientada a objetos se refiere a la capacidad de un objeto de tomar múltiples formas. Puede ser estático, resuelto en tiempo de compilación, basado en la herencia, o dinámico, resuelto en tiempo de ejecución, asociado a interfaces o métodos abstractos. En esencia, permite que objetos de diferentes clases respondan a la misma interfaz de manera coherente, facilitando la flexibilidad y extensibilidad del código.");
                   
  chatGPT chatGPT4(4, DTFecha(5,3,2024), "¿Qué es el acoplamiento en orientación a objetos?", "El acoplamiento en programación orientada a objetos se refiere al grado de dependencia entre las clases o módulos de un sistema. Un bajo acoplamiento es deseable, ya que implica que las clases son independientes entre sí, lo que facilita la modificación, mantenimiento y reutilización del código. Por otro lado, un alto acoplamiento indica una fuerte interdependencia entre las clases, lo que puede hacer que el sistema sea más difícil de entender, modificar y mantener.");

  Libro libro5(5, DTFecha(15,3,2024), "Applying UML and Patterns: An Introduction to Object-Oriented Analysis and Design and Iterative Development", "Craig Larman", "Applying UML and Patterns is the world’s #1 business and college introduction to “thinking in objects”―and using that insight in real-world objectoriented analysis and design. Building on two widely acclaimed previous editions, Craig Larman has updated this book to fully reflect the new UML 2 standard, to help you master the art of object design, and to promote high-impact, iterative, and skillful agile modeling practices.");

  std::cout << paginaWeb1.toString() << std::endl;
  std::cout << paginaWeb2.toString() << std::endl;
  std::cout << chat1.toString() << std::endl;
  std::cout << chat2.toString() << std::endl;
  std::cout << libro5.toString() << std::endl;

  Estudiante alex("Alex Garcia", "ag5678@gmail.com", 52365899);
  Estudiante betina("Betina Gonzalez", "beg999@gmail.com", 49891239);

  alex.insInfo(&paginaWeb1);
  alex.insInfo(&paginaWeb2);
  alex.insInfo(&chatGPT3);
  
  betina.insInfo(&chatGPT3);
  betina.insInfo(&chatGPT4);
  betina.insInfo(&libro5);

  imprimir(alex);
  imprimir(betina);
};