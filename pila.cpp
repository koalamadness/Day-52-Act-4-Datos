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

void Pila::eliminarTodo()
{
  Nodo* aux;

  while(ancla != nullptr)
  {
    aux = ancla;

    ancla = ancla->getSig();

    delete aux;
  }
}

Pila::~Pila()
{
  eliminarTodo();
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
    throw Exception("Memoria no disponible, push"); 
  }

  aux->setSig(ancla);


  ancla = aux;
}

char Pila::pop()
{
  if(ancla == nullptr)
  {
    throw Exception("Insuficiencia de datos, pop"); 
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
    throw Exception("Insuficiencia de datos, peek"); 
  }

  return ancla->getDato();
}

Pila& Pila::operator = (const Pila& p){

  eliminarTodo();

  copiarTodo(p);

  return *this;
}

// Nodo

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

