#ifndef PILA_H
#define PILA_H

#include <iostream>

#include "exception.h"

class Pila
{
private:
  char cadena[50];
  int tope;

  void copiarTodo(const Pila&);
public:
  Pila();
  Pila(const Pila&);

  bool estaVacio();
  bool estaLleno();

  void push(const char&);

  char pop();

  char peek();

  Pila& operator = (const Pila&);
};

#endif