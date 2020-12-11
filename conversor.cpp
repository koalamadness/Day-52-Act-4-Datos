#include "conversor.h"

using namespace std;

Conversor::Conversor() {}
Conversor::Conversor(const Conversor& con) : colaInfija(con.colaInfija),
colaPosfija(con.colaPosfija), pilaConv(con.pilaConv), cadenaConvertir(con.cadenaConvertir) {}

void Conversor::pasarPosfija(const string& s)
{
	for (string::size_type i = 0; i < s.size(); i++) {
    colaPosfija.enqueue(s[i]);
	}    
}

void Conversor::pasarInfija(const string& s)
{
	for (string::size_type i = 0; i < s.size(); i++) {
    colaInfija.enqueue(s[i]);
	}  
}

int Conversor::nivelPrecedencia(const char &c)
{
  switch(c)
  {
    case '+':
    case '-':
    {
      return 1;
      break;
    }

    case '*':
    case '/':
    {
      return 2;
      break;
    }    

    case '^':
    {
      return 3;
      break;
    }
  }

  return 0;
}

string Conversor::desapilarOperadores(const char &e)
{

  string resultado;

  if(pilaConv.estaVacio())
  {
    pilaConv.push(e);
    return resultado;
  }

  int precOperadorAct = nivelPrecedencia(e);
  char elementoTope = pilaConv.peek();
  int precOperadorTope = nivelPrecedencia(elementoTope);
  
  while(!pilaConv.estaVacio())
  {

    if(elementoTope == '(')
    {
      break;
    }

    if(precOperadorTope < precOperadorAct)
    { 
      
      break;
    }    

    if(precOperadorTope == precOperadorAct)
    {
      resultado += pilaConv.pop();
      pilaConv.push(e);
      return resultado;
      break;      
    }

    elementoTope = pilaConv.pop();
    precOperadorTope = nivelPrecedencia(elementoTope);
    resultado += elementoTope;
  }
  pilaConv.push(e);
  return resultado;
} 

void Conversor::convertirPosfija()
{

  string resultado;

  while(!colaInfija.estaVacio())
  {
    char elemento = colaInfija.dequeue();

    switch(elemento)
    { 
      case '+':
      case '-':
      case '*':
      case '/':
      case '^':
      {
        resultado += desapilarOperadores(elemento);
        break;
      }      

      case '(': 
      {
        pilaConv.push(elemento);
        break;
      }

      case ')':
      {
        while(!pilaConv.estaVacio())
        {

          char elementoADesp = pilaConv.pop();

          if(elementoADesp == '(') 
          {
            break;
          }

          resultado += elementoADesp;
        }
        
        break;
      }

      default: 
      {
        resultado += elemento;
        break;
      }
    }
  }
  
  while(!pilaConv.estaVacio())
  {
    resultado += pilaConv.pop();
  }

  pasarPosfija(resultado);
}

Cola Conversor::getColaInfija()
{
  return colaInfija;
}

Cola Conversor::getColaPosfija()
{
  return colaPosfija;
}

Pila Conversor::getPilaConv()
{
  return pilaConv;
}

string Conversor::getCadenaConvertir()
{
  return cadenaConvertir;
}

string Conversor::toString()
{
  string resultado;

  while(!colaPosfija.estaVacio())
  {
    resultado += colaPosfija.dequeue();
  }

  return resultado;
}

void Conversor::setColaInfija(const Cola& coi)
{
  colaInfija = coi;
}

void Conversor::setColaPosfija(const Cola& cop)
{
  colaPosfija = cop;
}

void Conversor::setPilaConv(const Pila& piv)
{
  pilaConv = piv;
}

void Conversor::setCadenaConvertir(const string& cad)
{
  cadenaConvertir = cad;
}

Conversor& Conversor::operator=(const Conversor& con) {
  colaInfija = con.colaInfija;
  colaPosfija = con.colaPosfija;
  pilaConv = con.pilaConv;
  cadenaConvertir = con.cadenaConvertir;

  return *this;
}

