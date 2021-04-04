#include <iostream>
#include "../../container/container.hpp"
#include "../../vector/vector.hpp"
#include "../menu.hpp"

using namespace std;

void VectorInt();
void VectorDouble();
void VectorString();
void Tipo(){cout<<"Intero(1)\nDouble(2)\nString(3)"<< endl;}

void SceltaSuiVettori(){
  Tipo();
  char sceltavector;
  VectorInt();
}

void VectorInt(){
  unsigned int dim;
  cout<< "Inserire la dimensione del vettore: "<<endl;
  cin >> dim;
  lasd::Vector<int> vec(dim);
  cout << vec[1] << endl;
  //menu();
  cout<<"Seleziona il tipo di struttura\n\tVettore (1)\n\tLista(2)\n (premi 8 per uscire)"<< endl;
}
