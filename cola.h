#ifndef COLA_H
#define COLA_H

#include <iostream>

#include "exception.h"

class Cola
{
private:
  class Nodo 
  {
  private:
    char* datoPtr;
    Nodo* prev;
    Nodo* sig;
  public:
    Nodo();
    Nodo(const char&);

    ~Nodo();

    char* getDatoPtr() const;
    char getDato() const;
    Nodo* getPrev() const;
    Nodo* getSig() const;

    void setDatoPtr(char*);
    void setDato(const char&);
    void setPrev(Nodo*);
    void setSig(Nodo*);
  };

  Nodo* header;

  void copiarTodo(const Cola&);

  void eliminarTodo();

public:
  Cola();
  Cola(const Cola&);

  ~Cola();

  bool estaVacio();

  void enqueue(const char&);

  char dequeue();

  char getFrente();

  Cola& operator = (const Cola&);
};

#endif