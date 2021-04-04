/* INCLUSIONI */
#include <iostream>
#include "../../container/container.hpp"
#include "../../vector/vector.hpp"
#include "../menu.hpp"
#include <random>

using namespace std;

/* Prototipi */
void VectorInt(){
  default_random_engine gen(random_device{}()); 
  uniform_int_distribution<unsigned int> dist(10000, 80000); // Generazione numeri casuali

  unsigned long dim; // Dichiariamo una variabile per la scelta della dimensione del vettore
  int index;

  cout<< "Inserire la dimensione del vettore: "<<endl;
  cin >> dim;
  lasd::Vector<int> vec(dim); // Inizializziamo il vettore
  
  for(unsigned long i = 0; i < dim; i++) { // Riempimento del vettore
    vec[i] = dist(gen);
  }
  cout << "FRONT: "<< vec.Front() << endl; // Stampa del Front del Vettore
  cout << "FRONT: "<< vec.Back() << endl; // Stampa del Back del Vettore

  for(unsigned long i = 0; i < dim; i++) {
    cout << "VEC:" << vec[i] << endl;
  }
 
  // Ricerca dell'elemento di indice scelto dall'utente
  cout << "Ricerca dell'elemento di indice scelto dall'utente " << endl;
  cin >> index;
  while (index > dim - 1){
    cout << "L'indice selezionato non è valido! " << endl;
    cin >> index;
  }

  for (int i = 0 ; i < dim ; i ++){
    if (index == i){
      cout << "L'indice scelto " << index << " contiene il valore " << vec[i] << endl;
    }
  }
  
}

void VectorDouble(){
  cout << "OK" << endl;
  
}

void VectorString(){
  cout << "Stringa" << endl;
  
}
