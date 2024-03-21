#include <iostream>
#include <string>
#include <vector>
#include <set>

class DTInfoEstudiante{
  private:
    int cédula;
    std::string nombreEst;
    int identificadorInfo;
  public:
    DTInfoEstudiante(int c, std::string nombre, int identificadorInfo) : cédula(c), nombreEst(nombre), identificadorInfo(identificadorInfo) {}
};



class DTFecha {
  private:
    int dia, mes, anio;
  public:
    DTFecha(int d, int m, int a) : dia(d), mes(m), anio(a) {}
    int getDia();
    int getMes();
    int getAnio();
};

int DTFecha::getDia() {
  return dia;
}
int DTFecha::getDia() {
  return mes;
}
int DTFecha::getDia() {
  return anio;
}


class Estudiante{
  private:
    std::string nombre,email;
    int cédula;
  public:
    std::string toString();
    std::set<std::string> listarInfo(DTFecha Desde);
};

std::string Estudiante::toString() {
  return "El nombre del estudiante es " + nombre + "con email " + email + "y su cédula es " + std::to_string(cédula);
}

std::set<std::string> Estudiante::listarInfo(DTFecha Desde) {
  
}

class Informacion{
  protected:
    int identificador;
    DTFecha fecha;
  public:
    virtual std::string toString();
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
    Libro(int id, DTFecha f,  std::string titulo, std::set<std::string> autores, std::string resumen) : Informacion(id,f), titulo(titulo), autores(autores), resumen(resumen) {}
    std::string toString();
};
std::string Libro::toString() {
  return "El libro tiene como autores " + std::to_string(autores.size()) + "y tiene como resumen " + resumen;
}

class PaginaWeb : public Informacion {
  private:
    std::string titulo,link,texto;
  public:
    PaginaWeb(int id, DTFecha f, std::string t, std::string l, std::string txt)
        : Informacion(id, f), titulo(t), link(l), texto(txt) {}
    std::string toString();
};
std::string PaginaWeb:: toString() {
      return "PáginaWeb " + std::to_string(identificador) + ", " +
               std::to_string(fecha.getDia()) + "/" + std::to_string(fecha.getMes()) + "/" + std::to_string(fecha.getAnio()) +
               ", " + titulo + ", " + link + ", " + texto;
    };


class chatGPT : public Informacion {
  private:
    std::string pregunta,respuesta;
  public:
    chatGPT(int id, DTFecha f, std::string p, std::string r) : Informacion(id, f), pregunta(p), respuesta(r) {}
    std::string toString();
};

std::string chatGPT:: toString() {
  return "La respuesta a la pregunta " + pregunta + " es " + respuesta + ". Espero que le resulte de ayuda.";
};

main(){
  
};