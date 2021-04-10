/* INCLUSIONI */
#include <iostream>
#include "../../container/container.hpp"
#include "../../list/list.hpp"

#include "../container/container.hpp"
#include "../menu.hpp"
#include <random>
#include <bits/stdc++.h>

/* Prototipi */
void RecapMenuList();
void ListInt(){
  typedef lasd::MappableContainer<int>::MapFunctor fun;
  unsigned long index, dim;
  int value,sum=0, n;
  std::default_random_engine gen(std::random_device{}());
  std::uniform_int_distribution<int> dist(1, 800); // Generazione numeri casuali

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
  std::cout << "\nEsecuzione della MapFunction In PreOrder: \n"<< std::endl;
  MapPreOrder(list, &MapPrint<int>, 0);

  std::cout << "\n" << std::endl;

  std::cout << "\nInserisci un valore per cui calcolare la somma degli elementi minori del valore dato: \n"<< std::endl;
  std::cin>> n;
  list.FoldPreOrder([](const int& dat, const void* n, void* sum)
	      {
          if (dat < *((int*)n))
            {
              *((int*)sum) += dat;
          }
      }, &n, &sum);
  std::cout << sum << std::endl;
  std::cout << "\n\n\n\n\n~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~" << std::endl;
  std::cout << "~~~ Applicazione della funzione 2N agli elementi del vettore~~~\n\t"<<std::endl;
  MapPreOrder(list, &MapDouble<int>,0);
  std::cout << "\n" << std::endl;
  MapPreOrder(list, &MapPrint<int>, 0);
  std::cout << "\n" << std::endl;
  RecapMenuList();

}

void ListFloat(){
  unsigned long index, dim;
  float value;
  float prod = 1.0;
  float n;
  std::default_random_engine gen(std::random_device{}());
  std::uniform_real_distribution<float> dist(1, 800); // Generazione numeri casuali

  std::cout<< "Inserire la dimensione della lista: ";
  std::cin >> dim;
  std::cout<< "\n";
  lasd::List<float> list;// Inizializziamo la lista

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
  std::cout << value << std::endl;
  Exists(list,value);

  std::cout << "\n~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~" << std::endl;
  MapPreOrder(list, &MapPrint<float>, 0);

  std::cout << "\n" << std::endl;

  std::cout << "\nInserisci un valore per cui calcolare il prodotto degli elementi maggiori del valore dato: \n"<< std::endl;
  std::cin>> n;
  list.FoldPreOrder([](const float& dat, const void* n, void* prod)
	    {
        if (dat > *((float*)n)) {
          *((float*)prod) *= dat;
        }
}, &n, &prod);
if (prod!=1.0){
  std::cout << "Il prodotto e' "<<prod << std::endl;
}
else{
  std::cout << "Non vi sono elementi maggiori dell'elemento scelto" << std::endl;
}
  std::cout << "\n\n\n\n\n~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~" << std::endl;
  std::cout << "~~~ Applicazione della funzione (N)^2 agli elementi del vettore~~~\n\t"<<std::endl;
  MapPreOrder(list, &MapNxN<float>,0);
  std::cout << "\n" << std::endl;
  MapPreOrder(list, &MapPrint<float>, 0);
  std::cout << "\n" << std::endl;
  RecapMenuList();
}

void ListString(){
  unsigned long dim;
  unsigned int n;
  int index;
  std::string value, StringaConcatenata, StringaToUpper;
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
  Exists(list, value);

  std::cout << "\n~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~" << std::endl;
  MapPreOrder(list, &MapPrint<std::string>, 0);

  std::cout << "\n" << std::endl;
  std::cout << "\nCalcolo della concatenazione di stringhe dato un valore n: \n"<< std::endl;
  std::cin>> n;
  list.FoldPreOrder([](const std::string& dat, const void* n, void* StringaConcatenata)
	      {
                if (dat.length() < *((int*)n))
                {
                  *((std::string*)StringaConcatenata) += dat;
                }
              }, &n, &StringaConcatenata);
  std::cout << StringaConcatenata << std::endl;

  std::cout << "Stampa del contenuto della lista in Upper Case"<< std::endl;
  for (int j = 0; j < dim; j ++){
    StringaToUpper = list[j];
    transform(StringaToUpper.begin(), StringaToUpper.end(), StringaToUpper.begin(), ::toupper);
    StringaToUpper =  StringaToUpper + " ";
    std::cout << StringaToUpper ;

  }

  std::cout << "\n";
  RecapMenuList();
}

void RecapMenuList(){
  std::cout<<"Seleziona il tipo di struttura\n\tVettore di interi (1)\tVettore di Double(2)\tVettore di Stringhe(3)\n"<< std::endl;
  std::cout<<"\tLista di interi (4)\tLista di Double(5)\tListe di Stringhe(6)\n"<< std::endl;
  std::cout<<"\t\t\t(premi q per uscire)"<< std::endl;
}
