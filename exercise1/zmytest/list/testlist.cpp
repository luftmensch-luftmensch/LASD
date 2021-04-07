/* INCLUSIONI */
#include <iostream>
#include "../../container/container.hpp"
#include "../../list/list.hpp"

#include "../container/container.hpp"
#include "../menu.hpp"
#include <random>

/* Prototipi */
void RecapMenuList();
void ListInt(){
  typedef lasd::MappableContainer<int>::MapFunctor fun;
  unsigned long index, dim;
  unsigned int value;
  std::default_random_engine gen(std::random_device{}()); 
  std::uniform_int_distribution<unsigned int> dist(1, 800); // Generazione numeri casuali

  std::cout<< "Inserire la dimensione della lista: ";
  std::cin >> dim;
  std::cout<< "\n";
  lasd::List<int> list;// Inizializziamo la lista
  
  for (unsigned long i = 0 ; i < dim; i ++){
    list.InsertAtFront(dist(gen));
    
  }
  
  GetFront(list);
  GetBack(list);
  std::cout << "\n\n\n\n\n~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~" << std::endl;
  std::cout << "~~~Info sul contenuto dell'elemento di indice scelto dall'utente ~~~" << std::endl;
  std::cout << "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n\n\n\n\n" << std::endl;
  std::cout << "Inserisci la posizione dell'elemento di cui ti interessa conoscere il valore: ";
  std::cin >> index;
  while (index > dim - 1){
    std::cout << "L'indice selezionato non è valido! Inserirne uno valido: ";
    std::cin >> index;
  }
  GetAt(list, index);

  std::cout << "\n\n\n\n\n~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~" << std::endl;
  std::cout << "~~~ Ricerca di un valore all'interno della struttura~~~\n\tInserisci elemento: ";
  std::cin>> value;
  Exists(list, value);

  std::cout << "\n~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~" << std::endl;
  MapPreOrder(list, &MapPrint<int>, 0);

  std::cout << "\n" << std::endl;

  RecapMenuList();
  
}

void ListDouble(){
  unsigned long index, dim;
  double value;
  std::default_random_engine gen(std::random_device{}()); 
  std::uniform_real_distribution<double> dist(1, 800); // Generazione numeri casuali

  std::cout<< "Inserire la dimensione della lista: ";
  std::cin >> dim;
  std::cout<< "\n";
  lasd::List<double> list;// Inizializziamo la lista
  
  for (unsigned long i = 0 ; i < dim; i ++){
    list.InsertAtFront(dist(gen));
    
  }
  GetFront(list);
  GetBack(list);
  std::cout << "\n\n\n\n\n~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~" << std::endl;
  std::cout << "~~~Info sul contenuto dell'elemento di indice scelto dall'utente ~~~" << std::endl;
  std::cout << "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n\n\n\n\n" << std::endl;
  std::cout << "Inserisci la posizione dell'elemento di cui ti interessa conoscere il valore: ";
  std::cin >> index;
  while (index > dim - 1){
    std::cout << "L'indice selezionato non è valido! Inserirne uno valido: ";
    std::cin >> index;
  }
  GetAt(list, index);

  std::cout << "\n\n\n\n\n~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~" << std::endl;
  std::cout << "~~~ Ricerca di un valore all'interno della struttura~~~\n\tInserisci elemento: ";
  std::cin>> value;
  Exists(list, value);

  std::cout << "\n~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~" << std::endl;
  MapPreOrder(list, &MapPrint<int>, 0);

  std::cout << "\n" << std::endl;

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

  GetFront(list);
  GetBack(list);
  std::cout << "\n\n\n\n\n~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~" << std::endl;
  std::cout << "~~~Info sul contenuto dell'elemento di indice scelto dall'utente ~~~" << std::endl;
  std::cout << "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n\n\n\n\n" << std::endl;
  std::cout << "Inserisci la posizione dell'elemento di cui ti interessa conoscere il valore: ";
  std::cin >> index;
  while (index > dim - 1){
    std::cout << "L'indice selezionato non è valido! Inserirne uno valido: ";
    std::cin >> index;
  }
  GetAt(list, index);

  std::cout << "\n\n\n\n\n~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~" << std::endl;
  std::cout << "~~~ Ricerca di un valore all'interno della struttura~~~\n\tInserisci elemento: ";
  std::cin>> value;
  ExistsString(list, value);

  std::cout << "\n~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~" << std::endl;
  MapPreOrder(list, &MapPrint<std::string>, 0);

  std::cout << "\n" << std::endl;
  RecapMenuList();
}

void RecapMenuList(){
  std::cout<<"Seleziona il tipo di struttura\n\tVettore di interi (1)\tVettore di Double(2)\tVettore di Stringhe(3)\n"<< std::endl;
  std::cout<<"\tLista di interi (4)\tLista di Double(5)\tListe di Stringhe(6)\n"<< std::endl;
  std::cout<<"\t\t\t(premi q per uscire)"<< std::endl;
}
