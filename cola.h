#ifndef COLA_H
#define COLA_H

#include <iostream>

#include "exception.h"

class Cola
{
private:
  char cadena[50];
  int frentePos;
  int finPos;

  void copiarTodo(const Cola&);

public:
  Cola();
  Cola(const Cola&);

  bool estaVacio();
  bool estaLleno();

  void enqueue(const char&);

  char dequeue();

  char getFrente();

  Cola& operator = (const Cola&);
};

#endif