/* INCLUSIONI */
#include <iostream>
#include "../../container/container.hpp"
#include "../../list/list.hpp"

#include "../menu.hpp"
#include <random>

/* Prototipi */
void RecapMenuList();
void ListInt(){
  std::default_random_engine gen(std::random_device{}()); 
  std::uniform_int_distribution<unsigned int> dist(10000, 80000); // Generazione numeri casuali

  unsigned long dim; // Dichiariamo una variabile per la scelta della dimensione della lista
  std::cout<< "Inserire la dimensione della lista: ";
  std::cin >> dim;
  std::cout<< "\n";
  lasd::List<int> list;// Inizializziamo la lista
  
  for (unsigned long i = 0 ; i < dim; i ++){
    list.InsertAtFront(dist(gen));
    
  }
  std::cout << "Il Front della Lista è: "<< list.Front() << std::endl; // Stampa del Front del Vettore
  std::cout << "Il Back della Lista è: "<< list.Back() << std::endl; // Stampa del Back del Vettore

  RecapMenuList();
  
}

void ListDouble(){
  std::default_random_engine gen(std::random_device{}()); 
  std::uniform_real_distribution<double> dist(10000, 80000); // Generazione numeri casuali

  unsigned long dim; // Dichiariamo una variabile per la scelta della dimensione della lista
  std::cout<< "Inserire la dimensione della lista: ";
  std::cin >> dim;
  std::cout<< "\n";
  lasd::List<double> list;// Inizializziamo la lista
  
  for (unsigned long i = 0 ; i < dim; i ++){
    list.InsertAtFront(dist(gen));
    
  }
  std::cout << "Il Front della Lista è: "<< list.Front() << std::endl; // Stampa del Front del Vettore
  std::cout << "Il Back della Lista è: "<< list.Back() << std::endl; // Stampa del Back del Vettore
  
  RecapMenuList();

}

void ListString(){
  
  unsigned long dim;
  int index;
  std::string value;
  std::cout << "Inserire la dimensione del vettore: ";
  std::cin >> dim;
  lasd::List<std::string> list;// Inizializziamo la lista
  std::size_t length;
  std::mt19937 mt(std::random_device{}());
  std::string characters =
      "abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ";
  std::uniform_int_distribution<int> dist(0, characters.length() - 1);
  std::string randStr;

  for (unsigned long i = 0; i < dim; i++) { // Riempimento del vettore
    randStr = characters[dist(mt)];
    list.InsertAtFront(randStr);
  }
  std::cout<< "\n";
  std::cout << "Il Front del vettore è: "<< list.Front() << std::endl; // Stampa del Front del Vettore
  std::cout << "Il Back del vettore è: "<< list.Back() << std::endl; // Stampa del Back del Vettore

  RecapMenuList();
}

void RecapMenuList(){
  std::cout<<"Seleziona il tipo di struttura\n\tVettore di interi (1)\tVettore di Double(2)\tVettore di Stringhe(3)\n"<< std::endl;
  std::cout<<"\tLista di interi (4)\tLista di Double(5)\tListe di Stringhe(6)\n"<< std::endl;
  std::cout<<"\t\t\t(premi q per uscire)"<< std::endl;
}
