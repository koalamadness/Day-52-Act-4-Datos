#ifndef PILA_H_INCLUDED
#define PILA_H_INCLUDED

#include <iostream>

#include "exception.h"

class Pila
{
private:
  class Nodo 
  {
  private:
    char dato;
    Nodo* sig;
  public:
    Nodo();
    Nodo(const char&);

    char getDato() const;
    Nodo* getSig() const;
    
    void setDato(const char&);
    void setSig(Nodo*);
  };

  Nodo* ancla;

  void copiarTodo(const Pila&);

  void eliminarTodo();
public:

  Pila();
  Pila(const Pila&);

  ~Pila();

  bool estaVacio() const;

  void push(const char&);

  char pop();

  char peek();

  Pila& operator = (const Pila&);
};



#endif