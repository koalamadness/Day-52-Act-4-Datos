#include "cola.h"

using namespace std;

//Nodo

Cola::Nodo::Nodo() : datoPtr(nullptr), prev(nullptr), sig(nullptr) { }

Cola::Nodo::Nodo(const char& e) : datoPtr(new char(e)), prev(nullptr), sig(nullptr) 
{ 
  if(datoPtr == nullptr)
  {
    throw Exception("Memoria insuficiente, creando nodo");
  }
}

Cola::Nodo::~Nodo()
{
  delete datoPtr;
}

char* Cola::Nodo::getDatoPtr() const 
{
  return datoPtr;
}

char Cola::Nodo::getDato() const
{
  if(datoPtr == nullptr)
  {
    throw Exception("Dato inexistente, getDato");
  }
  return *datoPtr;
}

typename Cola::Nodo* Cola::Nodo::getPrev() const
{
  return prev;
}

typename Cola::Nodo* Cola::Nodo::getSig() const
{
  return sig;
}

void Cola::Nodo::setDatoPtr(char *p)
{
  datoPtr = p;
}

void Cola::Nodo::setDato(const char &e)
{
  if(datoPtr == nullptr)
  {
    if((datoPtr = new char(e)) == nullptr)
    {
      throw Exception("Memoria no disponible, setDato");
    }
  }
  else 
  {
    *datoPtr = e;
  }
}

void Cola::Nodo::setSig(Nodo *p)
{
  sig = p;
}

void Cola::Nodo::setPrev(Nodo *p)
{
  prev = p;
}

// Cola

void Cola::copiarTodo(const Cola& co) 
{
  Nodo* aux(co.header->getSig());
  Nodo* newNode;

  while(aux != co.header)
  {
    if((newNode = new Nodo(aux->getDato())) == nullptr)
    {
        throw Exception("Memoria no disponible, copiarTodo");     
    }
    newNode->setPrev(header->getPrev());
    newNode->setSig(header);

    header->getPrev()->setSig(newNode);   
    header->setPrev(newNode);

    aux = aux->getSig(); 
  }

}

void Cola::eliminarTodo()
{
  Nodo* aux;

  while(header->getSig() != header)
  {
    aux = header->getSig();

    header->setSig(aux->getSig());

    delete aux;
  }

  header->setSig(header);
}

Cola::Cola() : header(new Nodo) 
{ 
  if(header == nullptr)
  {
      throw Exception("Memoria no disponible, iniciando Cola");
  }

  header->setPrev(header);
  header->setSig(header);
}

Cola::Cola(const Cola& co) : Cola()
{
  copiarTodo(co);
} 

Cola::~Cola()
{
  eliminarTodo();

  delete header;
}

bool Cola::estaVacio()
{
  return header->getSig() == header;
}


void Cola::enqueue(const char& c)
{
  Nodo* aux;

  if((aux = new Nodo(c)) == nullptr)
  {
      throw Exception("Memoria no disponible, enqueue");     
  }

  aux->setPrev(header->getPrev());
  aux->setSig(header);

  header->getPrev()->setSig(aux);
  header->setPrev(aux);
}

char Cola::dequeue()
{
  if(estaVacio())
  {
    throw Exception("Insuficiencia de datos, dequeue");    
  }

  char result(header->getSig()->getDato());

  Nodo* aux(header->getSig());

  aux->getPrev()->setSig(aux->getSig());
  aux->getSig()->setPrev(aux->getPrev());

  delete aux;

  return result;
}

char Cola::getFrente()
{
  if(estaVacio())
  {
    throw Exception("Insuficiencia de datos, dequeue");    
  }

  return header->getSig()->getDato();
}

Cola& Cola::operator = (const Cola &co)
{
  eliminarTodo();

  copiarTodo(co);

  return *this;
}

