#include <string>
#include <vector>
#include <set>
#include <iostream>
#include "Estudiante.h"
#include "Informacion.h"
#include "ChatGPT.h"
#include "Libro.h"
#include "PaginaWeb.h"

void Asociar(Estudiante* est, Informacion* info){
  est->insInfo(info);
  info->insEst(est);
}

void BorrarInfo(std::set<Informacion*> &infos, Informacion * i){
  auto it = infos.find(i);
  if (it!=infos.end()){
    delete (*it);
    infos.erase(*it);
  }
}

std::set<DTInfoEstudiante*> Polimorfismo (std::set<Informacion*> info){ // POLIMORFISMO
  std::set<DTInfoEstudiante*> res;
  for(auto it = info.begin(); it!= info.end();it++){                                ///para todas las informaciones
    std::string texto = (*it)->toString();                                          // texto que guarda la informacion en un string
    if (texto.find("polimorfismo")!=std::string::npos){                             
      for (int j=0;j<(*it)->getTamVector();j++){                                 //para cada informacion que encontro "polimorfismo" reviso todos los estudiantes
        DTInfoEstudiante *e = new DTInfoEstudiante((*it)->getEst(j)->getCedula(), (*it)->getEst(j)->getNombre(), (*it)->getIdentificador()); // dtinfo( cedula , nombre , idInfo )
        res.insert(e);
      }
    }
  }
  return res;
}

int main() {
  std::set<Informacion*> informaciones;
  
  /*------------------PAGINAWEB------------------------*/

  PaginaWeb* paginaweb1 = new PaginaWeb(1, DTFecha(7, 3, 2024), "Programación 4 Guía Semana 1 (4/3)", "https://eva.fing.edu.uy/pluginfile.php/468051/mod_resource/content/4/Guia01_P42024_IntroCBasicos.pdf", "El objetivo de esta semana es contextualizar el paradigma de Orientación a Objetos (OO) en el marco de la Ingeniería de Software, así como comenzar a ver sus conceptos básicos y cómo éstos se implementan en C++.");
  PaginaWeb* paginaweb2 = new PaginaWeb(2, DTFecha(5, 3, 2024), "Programación orientada a objetos", "https://es.wikipedia.org/wiki/Programaci%C3%B3n_orientada_a_objetos","La programación orientada a objetos (POO, en español) es un paradigma deprogramación que parte del concepto de objetos como base, los cuales contienen información en forma de campos (a veces también referidos como atributos o propiedades) y código en forma de métodos. Algunas características clave de la programación orientada a objetos son herencia, cohesión, abstracción, polimorfismo, acoplamiento y encapsulamiento.");
  informaciones.insert(paginaweb1);
  informaciones.insert(paginaweb2);
  /* std::cout << paginaWeb1.toString() << std::endl;
  std::cout << paginaWeb2.toString() << std::endl;*/
  


  /*------------------CHATGPT------------------------*/

  chatGPT* chatgpt3 = new chatGPT(3, DTFecha(8, 3, 2024), "¿Qué es el polimorfismo en orientación a objetos?", "El polimorfismo en programación orientada a objetos se refiere a la capacidad de un objeto de tomar múltiples formas. Puede ser estático, resuelto en tiempo de compilación, basado en la herencia, o dinámico, resuelto en tiempo de ejecución, asociado a interfaces o métodos abstractos. En esencia, permite que objetos de diferentes clases respondan a la misma interfaz de manera coherente, facilitando la flexibilidad y extensibilidad del código.");
  chatGPT* chatgpt4 = new chatGPT(4, DTFecha(5,3,2024), "¿Qué es el acoplamiento en orientación a objetos?", "El acoplamiento en programación orientada a objetos se refiere al grado de dependencia entre las clases o módulos de un sistema. Un bajo acoplamiento es deseable, ya que implica que las clases son independientes entre sí, lo que facilita la modificación, mantenimiento y reutilización del código. Por otro lado, un alto acoplamiento indica una fuerte interdependencia entre las clases, lo que puede hacer que el sistema sea más difícil de entender, modificar y mantener.");
  informaciones.insert(chatgpt3);
  informaciones.insert(chatgpt4);
  /*std::cout << chat1.toString() << std::endl;
  std::cout << chat2.toString() << std::endl;*/


/*------------------LIBRO------------------------*/

   /*std::set<std::string> autoresLibro5;
   autoresLibro5.insert("Craig Larman");*/
  Libro* libro5 = new Libro(5, DTFecha(15,3,2024), "Applying UML and Patterns: An Introduction to Object-Oriented Analysis and Design and Iterative Development", "Craig Larman", "Applying UML and Patterns is the world’s #1 business and college introduction to “thinking in objects”―and using that insight in real-world objectoriented analysis and design. Building on two widely acclaimed previous editions, Craig Larman has updated this book to fully reflect the new UML 2 standard, to help you master the art of object design, and to promote high-impact, iterative, and skillful agile modeling practices.");
  informaciones.insert(libro5);
  /* std::cout << libro5.toString() << std::endl;  */

/*-----------------IMPRIMIR INFORMACIONES----------------------*/
    std::cout << "//---------------------------IMPRIME INFORMACIONES------------------------------// \n";
    for (auto it1=informaciones.begin();it1!=informaciones.end();it1++){
    std::cout << (*it1)->toString() << std::endl << std::endl;
  }   

/*------------------ESTUDIANTE------------------------*/

  std::set<Estudiante*> estudiantes;

  Estudiante* alex = new Estudiante("Alex Garcia", "ag5678@gmail.com", 52365899);
  Estudiante* betina= new Estudiante("Betina Gonzalez", "beg999@gmail.com", 49891239);
  estudiantes.insert(alex);
  estudiantes.insert(betina);

  std::cout << "//---------------------------IMPRIME ESTUDIANTES------------------------------// \n";
  for (auto it2 = estudiantes.begin();it2!=estudiantes.end();it2++){                          //Imprime lista de estudiantes
    std::cout << (*it2)->toString() << std::endl<<std::endl;
  }

  Asociar(alex,paginaweb1);
  Asociar(alex,paginaweb2);
  Asociar(alex,chatgpt3);
  Asociar(betina,chatgpt3); 
  Asociar(betina,chatgpt4); 
  Asociar(betina,libro5);

  std::cout << "//---------------------------LISTAR INFO------------------------------// \n";
  std::cout << "Alex: \n";
  std::set<std::string> listInfoAlex = alex->listarInfo(DTFecha(8,3,2024));                       //Imprimir la informacion posterior a esa fecha
  if (listInfoAlex.size()==0){
    std::cout << "El estudiante "+ alex->getNombre()+ " no tiene informacion posterior a esa fecha " <<std::endl;
  }
  else for(auto it=listInfoAlex.begin();it!=listInfoAlex.end();it++){
    std::cout << (*it) << std::endl << std::endl;
  }

  std::cout << "\nBetina:\n";
  std::set<std::string> listInfoBetina = betina->listarInfo(DTFecha(8,3,2024));                   //Imprimir la informacion posterior a esa fecha
   if (listInfoBetina.size()==0){
    std::cout << "El estudiante " + betina->getNombre() + " no tiene informacion posterior a esa fecha " <<std::endl;
  }
  else for(auto it=listInfoBetina.begin();it!=listInfoBetina.end();it++){
    std::cout << (*it) << std::endl <<std::endl;
  }

  std::cout << "//---------------------------POLIMORFISMO------------------------------// \n";
  std::set<DTInfoEstudiante*> Encontrados = Polimorfismo(informaciones);
  for (auto it=Encontrados.begin();it!=Encontrados.end();it++){
    std::cout << (*it) << std::endl << std::endl; // (imprime: "52365899, Alex García, 5")
  }
  for (auto it=Encontrados.begin();it!=Encontrados.end();it++){
    delete (*it);
  }
    
  std::cout<<"Borra a chatgpt3 \n";
  BorrarInfo(informaciones,chatgpt3);
  
  std::cout << "Verificar que los estudiantes ya no tienen a la información chatgpt3: \n \n";
  for (auto est=estudiantes.begin();est!=estudiantes.end();est++){
    std::set<std::string> listInfoEst = (*est)->listarInfo(DTFecha(8,3,2024));                       //Imprimir la informacion posterior a esa fecha
    if (listInfoEst.size()==0){
      std::cout << "El estudiante "+ (*est)->getNombre()+ " no tiene informacion posterior a esa fecha " <<std::endl<<std::endl;
    }
    else for(auto it=listInfoEst.begin();it!=listInfoEst.end();it++){
      std::cout << (*it) << std::endl << std::endl<< std::endl;
    }
  }

  std::cout<<"Se liberan informaciones: \n";
  for (auto i=informaciones.begin();i!=informaciones.end();i++){
    delete (*i);
  }
  std::cout<<"Se liberan estudiantes: \n";
  for (auto e=estudiantes.begin();e!=estudiantes.end();e++){
    delete (*e);
  }
  
  return 0;
};