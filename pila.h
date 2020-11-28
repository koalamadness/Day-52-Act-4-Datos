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

  void borrarTodo();
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

//Nodo
Pila::Nodo::Nodo() : sig(nullptr) { }

Pila::Nodo::Nodo(const char& e) : dato(e), sig(nullptr) { }

char Pila::Nodo::getDato() const 
{
  return dato;
}

typename Pila::Nodo* Pila::Nodo::getSig() const
{
  return sig;
}

void Pila::Nodo::setDato(const char& e)
{
  dato = e;
}

void Pila::Nodo::setSig(Nodo* p)
{
  sig = p;
}

#endif