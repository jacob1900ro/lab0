#include <iostream>
#include <string>
#include <vector>
#include <set>

class Estudiante{
  private:
    std::string Nombre,Email;
    int CI;
  public:
    std::string toString();
    std::set<std::string> listarInfo(DTFecha Desde);
};

class DTInfoEstudiante{
  private:
    int CI;
    std::string NombreEst;
    int IdentificadorInfo;
  public:
    
};
class DTFecha {
  private:
    int dia, mes, anio;
  public:
    DTFecha(int d, int m, int a) : dia(d), mes(m), anio(a) {}
    int getDia()  { return dia; }
    int getMes()  { return mes; }
    int getAnio()  { return anio; }
};

class Informacion{
  protected:
    int identificador;
    DTFecha fecha;
  public:
    Informacion(int id, DTFecha f) : identificador(id), fecha(f) {}
    int getIdentificador() { return identificador; }
    DTFecha getFecha() { return fecha; }
};

class Libro : public Informacion {
private:
    std::string titulo;
    std::set<std::string> autores; //
    std::string resumen;
  public:
    
};

class PaginaWeb : public Informacion {
  private:
    std::string titulo,link,texto;
  public:
    PaginaWeb(int id, DTFecha f, std::string t, std::string l, std::string txt)
        : Informacion(id, f), titulo(t), link(l), texto(txt) {}
    std::string toString() {
      return "PáginaWeb " + std::to_string(identificador) + ", " +
               std::to_string(fecha.getDia()) + "/" + std::to_string(fecha.getMes()) + "/" + std::to_string(fecha.getAnio()) +
               ", " + titulo + ", " + link + ", " + texto;
    }; 
};


class chatGPT : public Informacion {
  private:
    std::string Pregunta,Respuesta;
  public:
    std::string toString() {
      return "La respuesta a la pregunta " + Pregunta + " es " + Respuesta + ". Espero que le resulte de ayuda.";
    };
};


main(){
  
};