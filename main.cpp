#include <iostream>
#include <string>

#include "pila.h"
#include "cola.h"
#include "conversor.h"

using namespace std;

int main() {
  string myString;
  Pila myPila;
  Cola myCola;
  Conversor myConv;

  cout << "Ingresa la expresión en notación infija: " << endl;
  cin >> myString;

  myConv.pasarInfija(myString);
  cout << endl;
  
  myConv.convertirPosfija();

  cout << "Notación posfija: " << myConv.toString() << endl;
}