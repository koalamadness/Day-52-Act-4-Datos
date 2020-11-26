#include "cola.h"

using namespace std;

void Cola::copiarTodo(const Cola& co) // FALTA
{
  int i(0);
  while(i <= co.finPos)
  {
    this-> cadena[i] = co.cadena[i];
    i++;
  }

  this->finPos = co.finPos;
  this->frentePos = co.frentePos;
}

Cola::Cola() : frentePos(0), finPos(49) { }
Cola::Cola(const Cola& co) {copiarTodo(co);} 

bool Cola::estaVacio()
{
  return frentePos == finPos + 1 or (frentePos == 0 and finPos == 49);
}

bool Cola::estaLleno()
{
  return frentePos == finPos + 2 or (frentePos == 0 and finPos == 48)
         or (frentePos == 1 and finPos == 49);
}

void Cola::enqueue(const char& c)
{
  if(estaLleno())
  {
    throw Exception("Desbordamiento de datos, enqueue");
  }

  if(++finPos == 50){
    finPos = 0;
  }

  cadena[finPos] = c;
}

char Cola::dequeue()
{
  if(estaVacio())
  {
    throw Exception("Insuficiencia de datos, dequeue");    
  }

  char elemento(cadena[frentePos]);

  if(++frentePos == 50){
    frentePos = 0;
  }

  return elemento;
}

char Cola::getFrente()
{
  if(estaVacio())
  {
    throw Exception("Insuficiencia de datos, dequeue");    
  }

  return cadena[frentePos];
}

Cola& Cola::operator = (const Cola &co)
{
  copiarTodo(co);

  return *this;
}

