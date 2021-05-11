/* INCLUSIONI */
#include <iostream>
#include "../../container/container.hpp"
#include "../container/container.hpp"
#include "../../vector/vector.hpp"
#include "../menu.hpp"
#include <random>
#include <string>
#include <ctime>
#include <unistd.h>
#include <bits/stdc++.h>

using namespace std;

/* Prototipi */
void RecapMenu();
void VectorInt(){
  default_random_engine gen(random_device{}()); 
  uniform_int_distribution<unsigned int> dist(10000, 80000); // Generazione numeri casuali

  unsigned long dim; // Dichiariamo una variabile per la scelta della dimensione del vettore
  int index, value;

  std::cout<< "Inserire la dimensione del vettore: ";
  std::cin >> dim;
  std::cout<< "\n";
  lasd::Vector<int> vec(dim); // Inizializziamo il vettore
  
  for(unsigned long i = 0; i < dim; i++) { // Riempimento del vettore
    vec[i] = dist(gen);
  }
  GetFront(vec);
  GetBack(vec);
 
  // Ricerca dell'elemento di indice scelto dall'utente
  std::cout << "\n\n\n\n\n~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~" << std::endl;
  std::cout << "~~~Info sul contenuto dell'elemento di indice scelto dall'utente ~~~" << std::endl;
  std::cout << "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n\n\n\n\n" << std::endl;
  std::cout << "Inserisci la posizione dell'elemento di cui ti interessa conoscere il valore: ";
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
  
  std::cout << "\n\n\n\n\n~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~" << std::endl;
  std::cout << "~~~ Ricerca di un valore all'interno della struttura~~~\n\tInserisci elemento: ";
  std::cin>> value;
  Exists(vec, value);
  std::cout << "\n" << std::endl;
  MapPreOrder(vec, &MapPrint<int>, 0);
  std::cout << "\n" << std::endl;
  std::cout << "Fine!" << std::endl;
  RecapMenu();
}

void VectorDouble(){
  default_random_engine gen(random_device{}()); 
  uniform_real_distribution<double> dist(1000.000, 8000.000); // Generazione numeri casuali

  unsigned long dim;
  int index;
  double value;
  std::cout<< "Inserire la dimensione del vettore: ";
  std::cin >> dim;
  std::cout<< "\n";
  lasd::Vector<double> vec(dim); // Inizializziamo il vettore
  
  for(unsigned long i = 0; i < dim; i++) { // Riempimento del vettore
    vec[i] = dist(gen);
  }

  GetFront(vec);
  GetBack(vec);

  // Ricerca dell'elemento di indice scelto dall'utente
  std::cout << "\n\n\n\n\n~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~" << std::endl;
  std::cout << "~~~Info sul contenuto dell'elemento di indice scelto dall'utente ~~~" << std::endl;
  std::cout << "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n\n\n\n\n" << std::endl;
  std::cout << "Inserisci la posizione dell'elemento di cui ti interessa conoscere il valore: ";
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
  std::cout << "\n\n\n\n\n~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~" << std::endl;
  std::cout << "~~~ Ricerca di un valore all'interno della struttura~~~\n\tInserisci elemento: ";
  std::cin>> value;
  Exists(vec, value);
  std::cout << "\n" << std::endl;
  MapPreOrder(vec, &MapPrint<int>, 0);
  std::cout << "\n" << std::endl;
  std::cout << "Fine!" << std::endl;
  RecapMenu();
}

void VectorString(){
  unsigned long dim;
  int index;
  string value;
  std::cout << "Inserire la dimensione del vettore: ";
  std::cin >> dim;
  std::cout<< "\n";
  lasd::Vector<string> vec(dim); // Inizializziamo il vettore
  std::size_t length;
  std::mt19937 mt(std::random_device{}());
  std::string characters =
      "abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ";
  std::uniform_int_distribution<int> dist(0, characters.length() - 1);
  std::string randStr;

  for (unsigned long i = 0; i < dim; i++) { // Riempimento del vettore
    randStr = characters[dist(mt)];
    vec[i] = randStr;
  }

  GetFront(vec);
  GetBack(vec);

  // Ricerca dell'elemento di indice scelto dall'utente
  std::cout << "\n\n\n\n\n~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~" << std::endl;
  std::cout << "~~~Info sul contenuto dell'elemento di indice scelto dall'utente ~~~" << std::endl;
  std::cout << "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n\n\n\n\n" << std::endl;
  std::cout << "Inserisci la posizione dell'elemento di cui ti interessa conoscere il valore: ";
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
  std::cout << "\n\n\n\n\n~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~" << std::endl;
  std::cout << "~~~ Ricerca di un valore all'interno della struttura~~~\n\tInserisci elemento: ";
  std::cin>> value;

  ExistsString(vec, value);
  std::cout << "\n" << std::endl;
  MapPreOrder(vec, &MapPrint<std::string>, 0);
  std::cout << "\n" << std::endl;
  std::cout << "Fine!" << std::endl;
  RecapMenu();
}

void RecapMenu(){
  std::cout<<"Seleziona il tipo di struttura\n\tVettore di interi (1)\tVettore di Double(2)\tVettore di Stringhe(3)\n"<< std::endl;
  std::cout<<"\tLista di interi (4)\tLista di Double(5)\tListe di Stringhe(6)\n"<< std::endl;
  std::cout<<"\t\t\t(premi q per uscire)"<< std::endl;
}
