/* INCLUSIONI */
#include <iostream>
#include "../../container/container.hpp"
#include "../../vector/vector.hpp"
#include "../menu.hpp"
#include <random>
#include <string>
#include <ctime>
#include <unistd.h>
#include <bits/stdc++.h>

using namespace std;

/* Prototipi */
void VectorInt(){
  default_random_engine gen(random_device{}()); 
  uniform_int_distribution<unsigned int> dist(10000, 80000); // Generazione numeri casuali

  unsigned long dim; // Dichiariamo una variabile per la scelta della dimensione del vettore
  int index, value;

  std::cout<< "Inserire la dimensione del vettore: ";
  std::cin >> dim;
  lasd::Vector<int> vec(dim); // Inizializziamo il vettore
  
  for(unsigned long i = 0; i < dim; i++) { // Riempimento del vettore
    vec[i] = dist(gen);
  }
  std::cout << "Il Front del vettore è: "<< vec.Front() << std::endl; // Stampa del Front del Vettore
  std::cout << "Il Back del vettore è: "<< vec.Back() << std::endl; // Stampa del Back del Vettore
 
  // Ricerca dell'elemento di indice scelto dall'utente
  std::cout << "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~" << std::endl;
  std::cout << "~~~Info sul contenuto dell'elemento di indice scelto dall'utente ~~~" << std::endl;
  std::cout << "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~" << std::endl;
  std::cin >> index;
  while (index > dim - 1){
    std::cout << "L'indice selezionato non è valido! Inserirne uno valido: ";
    std::cin >> index;
  }

  for (int i = 0 ; i < dim ; i ++){
    if (index == i){
      std::cout << "L'indice scelto " << index << " contiene il valore " << vec[i] << std::endl;
    }
  }
  
  std::cout << "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~" << std::endl;
  std::cout << "Ricerca di un valore all'interno della struttura\n\tInserisci elemento: ";
  std::cin>> value;
   if (vec.Exists(value)){
     std::cout << "Elemento trovato" << std::endl;
  
   }else{
     std::cout << "Elemento non trovato" << std::endl;
   }
}

void VectorDouble(){
  default_random_engine gen(random_device{}()); 
  uniform_real_distribution<double> dist(1000.000, 8000.000); // Generazione numeri casuali

  unsigned long dim;
  int index;
  double value;
  std::cout<< "Inserire la dimensione del vettore: ";
  std::cin >> dim;
  lasd::Vector<double> vec(dim); // Inizializziamo il vettore
  
  for(unsigned long i = 0; i < dim; i++) { // Riempimento del vettore
    vec[i] = dist(gen);
  }
  std::cout << "Il Front del vettore è: "<< vec.Front() << std::endl; // Stampa del Front del Vettore
  std::cout << "Il Back del vettore è: "<< vec.Back() << std::endl; // Stampa del Back del Vettore

  for(unsigned long i = 0; i < dim; i++) {
    cout << "VEC:" << vec[i] << endl;
  }
 
  // Ricerca dell'elemento di indice scelto dall'utente
  cout << "Ricerca dell'elemento di indice scelto dall'utente ";
  cin >> index;
  while (index > dim - 1){
    cout << "L'indice selezionato non è valido! Inserirne uno valido: ";
    cin >> index;
  }

  for (int i = 0 ; i < dim ; i ++){
    if (index == i){
      cout << "L'indice scelto " << index << " contiene il valore " << vec[i] << endl;
    }
  }
  std::cout << "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~" << std::endl;
  std::cout << "Ricerca di un valore all'interno della struttura\n\tInserisci elemento: ";
  std::cin>> value;
   if (vec.Exists(value)){
     std::cout << "Elemento trovato" << std::endl;
  
   }else{
     std::cout << "Elemento non trovato" << std::endl;
   }
  
}

void VectorString(){
  unsigned long dim;
  int index;
  string value;
  std::cout << "Inserire la dimensione del vettore: ";
  std::cin >> dim;
  lasd::Vector<string> vec(dim); // Inizializziamo il vettore
  std::size_t length;
  std::mt19937 mt(std::random_device{}());
  std::string characters =
      "abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ!@#$%^&*()";
  std::uniform_int_distribution<int> dist(0, characters.length() - 1);
  std::string randStr;

  for (unsigned long i = 0; i < dim; i++) { // Riempimento del vettore
    randStr = characters[dist(mt)];
    vec[i] = randStr;
  }
  std::cout << "Il Front del vettore è: "<< vec.Front() << endl; // Stampa del Front del Vettore
  std::cout << "Il Back del vettore è: "<< vec.Back() << endl; // Stampa del Back del Vettore
  std::cout << "Ricerca dell'elemento di indice scelto dall'utente ";
  std::cin >> index;
  while (index > dim - 1){
    std::cout << "L'indice selezionato non è valido! Inserirne uno valido: ";
    std::cin >> index;
  }

  for (int i = 0 ; i < dim ; i ++){
    if (index == i){
      std::cout << "L'indice scelto " << index << " contiene il valore " << vec[i] << std::endl;
    }
  }
  std::cout << "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~" << std::endl;
  std::cout << "Ricerca di un valore all'interno della struttura\n\tInserisci elemento: ";
  std::cin>> value;
   if (vec.Exists(value)){
     std::cout << "Elemento trovato" << std::endl;
  
   }else{
     std::cout << "Elemento non trovato" << std::endl;
   }

}
