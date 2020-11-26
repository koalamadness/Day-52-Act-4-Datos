#include "pila.h"

using namespace std;

void Pila::copiarTodo(const Pila& p)
{
  int i(0);
  while(i <= p.tope)
  {
    this->cadena[i] = p.cadena[i];
    i++;
  }

  this->tope = p.tope;
}

Pila::Pila() : tope(-1) { }

Pila::Pila(const Pila& p) {copiarTodo(p);}

bool Pila::estaVacio() {return tope == -1;}

bool Pila::estaLleno() {return 49;}

void Pila::push(const char& c)
{
  if(estaLleno())
  {

  }

  cadena[++tope] = c;
}

char Pila::pop()
{
  if(estaVacio())
  {
    throw Exception("Insuficiencia de datos, pop");    
  }

  return cadena[tope--];
}

char Pila::peek()
{
  if(estaVacio())
  {
     
  }

  return cadena[tope];
}

Pila& Pila::operator = (const Pila& p){
  copiarTodo(p);

  return *this;
}
