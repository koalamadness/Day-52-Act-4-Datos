#ifndef CONVERSOR_H
#define CONVERSOR_H

#include <iostream>
#include "pila.h"
#include "cola.h"

class Conversor
{
private:
  Cola colaInfija;
  Cola colaPosfija;
  Pila pilaConv;
  std::string cadenaConvertir;

  int nivelPrecedencia(const char&);
  std::string desapilarOperadores(const char&);  
  void pasarPosfija(const std::string&);

public:
  Conversor();
  Conversor(const Conversor&);

  void pasarInfija(const std::string&);
  void convertirPosfija();

  Cola getColaInfija();
  Cola getColaPosfija();
  Pila getPilaConv();
  std::string getCadenaConvertir();

  std::string toString();

  void setColaInfija(const Cola&);
  void setColaPosfija(const Cola&);
  void setPilaConv(const Pila&);
  void setCadenaConvertir(const std::string&);

  Conversor& operator = (const Conversor&);
};

#endif