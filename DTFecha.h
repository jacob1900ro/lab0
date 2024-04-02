// DTFecha.h
#ifndef DTFECHA_H
#define DTFECHA_H

class DTFecha
{
private:
  int dia, mes, anio;

public:
  DTFecha(int d, int m, int a) : dia(d), mes(m), anio(a) {} // Constructor
  ~DTFecha() {}
  int getDia() { return dia; };
  int getMes() { return mes; };
  int getAnio() { return anio; };
};

#endif // DTFECHA_H