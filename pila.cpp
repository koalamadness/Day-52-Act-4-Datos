#include "pila.h"

using namespace std;

void Pila::copiarTodo(const Pila& p)
{
  Nodo* aux(p.ancla);
  Nodo* ultimo(nullptr);
  Nodo* nuevoNodo;

  while(aux != nullptr)
  {

    if((nuevoNodo = new Nodo(aux->getDato())) == nullptr)
    {
      throw Exception("Memoria no disponible, copiarTodo"); 
    }

    if (ultimo == nullptr)
    {
      ancla = nuevoNodo;
    }
    else
    {
      ultimo->setSig(nuevoNodo);
    }
    
    ultimo = nuevoNodo;
    
    aux = aux->getSig();
  }
}

Pila::Pila() : ancla(nullptr) { }

Pila::Pila(const Pila& p) : ancla(nullptr) 
{
  copiarTodo(p);
}

Pila::~Pila()
{
  borrarTodo();
}

bool Pila::estaVacio() const 
{
  return ancla == nullptr;
}

void Pila::push(const char& c)
{
  Nodo* aux(new Nodo(c));

  if(aux == nullptr)
  {
    // thorw
  }

  aux->setSig(ancla);

  ancla = aux;
}

char Pila::pop()
{
  if(ancla == nullptr)
  {
    // thorw
  }

  char result(ancla->getDato());

  Nodo* aux(ancla);

  ancla = ancla->getSig();

  delete aux;

  return result;
}

char Pila::peek()
{
  if(ancla == nullptr)
  {
    // thorw
  }

  return ancla->getDato();
}

Pila& Pila::operator = (const Pila& p){

  borrarTodo();

  copiarTodo(p);

  return *this;
}
