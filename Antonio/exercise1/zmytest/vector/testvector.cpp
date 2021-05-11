/* INCLUSIONI */
#include <iostream>
#include "../../container/container.hpp"
#include "../container/container.hpp"
#include "../../vector/vector.hpp"
#include "../menu.hpp"
#include <random>
#include <string>

#include <bits/stdc++.h>


using namespace std;

void RecapMenu();



void VectorInt(){
  default_random_engine gen(random_device{}());
  uniform_int_distribution<unsigned int> dist(1, 800);

  unsigned long dim;
  int index, value,n,sum=0;

  std::cout<< "Inserisci la dimensione del vettore: ";
  std::cin >> dim;
  std::cout<< "\n";

  lasd::Vector<int> vec(dim);

  for(unsigned long i = 0; i < dim; i++) {
    vec[i] = dist(gen);
  }
  GetFront(vec);
  GetBack(vec);

  // Ricerca dell'elemento di indice scelto dall'utente
  std::cout << "\n\n\n\n\n##############################################################" << std::endl;
  std::cout << "~ Informazoni sul contenuto dell'elemento di indice scelto dall'utente ~" << std::endl;
  std::cout << "###################################################################\n\n\n\n\n" << std::endl;
  std::cout << "Inserisci la posizione dell'elemento di cui ti interessa conoscere il valore: ";
  std::cin >> index;
  while (index > dim - 1){
    std::cout << "L'indice scelto non è valido! Inseriscine uno valido: ";
    std::cin >> index;
  }

  for (int i = 0 ; i < dim ; i ++){
    if (index == i){
      std::cout << "L'indice '" << index <<"' contiene il valore '" << vec[i] <<"'" <<std::endl;
    }
  }

  std::cout << "\n\n\n\n\n###########################################################" << std::endl;
  std::cout << "~ Ricerca di un valore all'interno del vettore ~\n\tInserisci l'elemento da ricercare: ";
  std::cin>> value;
  Exists(vec, value);
  std::cout << "\n" << std::endl;
  std::cout << "\n############################################################" << std::endl;
  std::cout << "\nEsecuzione della Map In PreOrder: \n"<< std::endl;
  MapPreOrder(vec, &MapPrint<int>, 0);
  std::cout << "\n" << std::endl;
  std::cout << "\n\n\n\n\n###########################################################" << std::endl;
  std::cout << "~ Calcolo della somma di elementi minori di N (dato in input) ~"<<std::endl;
  std::cout << "\nInserisci N: \n"<< std::endl;
  std::cin>> n;
  vec.FoldPreOrder([](const int& dat, const void* n, void* sum)
	      {
          if (dat < *((int*)n))
            {
              *((int*)sum) += dat;
          }
      }, &n, &sum);
      if (sum!=0){
        std::cout << "La somma e' "<<sum << std::endl;
      }
      else{
        std::cout << "Non vi sono elementi con valore minore di quello scelto" << std::endl;
      }
  std::cout << "\n\n\n\n\n#########################################################" << std::endl;
  std::cout << "~ Applicazione della funzione 2N agli elementi del vettore ~\n\t"<<std::endl;
  MapPreOrder(vec, &MapDouble<int>,0);
  std::cout << "\n" << std::endl;
  MapPreOrder(vec, &MapPrint<int>, 0);
  std::cout << "\n" << std::endl;
  RecapMenu();
}

void VectorFloat(){
  default_random_engine gen(random_device{}());
  uniform_real_distribution<float> dist(1, 800); // Generazione numeri casuali

  unsigned long dim;
  int index;
  float value;
  float n;
  float prod=1.0;
  std::cout<< "Inserisci la dimensione del vettore: ";
  std::cin >> dim;
  std::cout<< "\n";
  lasd::Vector<float> vec(dim); // Inizializziamo il vettore

  for(unsigned long i = 0; i < dim; i++) { // Riempimento del vettore
    vec[i] = dist(gen);
  }

  GetFront(vec);
  GetBack(vec);

  // Ricerca dell'elemento di indice scelto dall'utente
  std::cout << "\n\n\n\n\n############################################################" << std::endl;
  std::cout << "~ Informazioni sul contenuto dell'elemento di indice scelto dall'utente ~" << std::endl;
  std::cout << "####################################################################\n\n\n\n\n" << std::endl;
  std::cout << "Inserisci la posizione dell'elemento di cui ti interessa conoscere il valore: ";
  cin >> index;
  while (index > dim - 1){
    cout << "L'indice scelto non è valido! Inseriscine uno valido: ";
    cin >> index;
  }

  for (int i = 0 ; i < dim ; i ++){
    if (index == i){
      cout << "L'indice scelto '" << index << "' contiene il valore '" << vec[i] <<"'"<< endl;
    }
  }
  std::cout << "\n\n\n\n\n#############################################################" << std::endl;
  std::cout << "~ Ricerca di un valore all'interno del vettore ~\n\tInserisci l'elemento da ricercare: ";
  std::cin>> value;
  Exists(vec, value);
  std::cout << "\n" << std::endl;
  std::cout << "\n############################################################" << std::endl;
  std::cout << "\nEsecuzione della Map In PreOrder: \n"<< std::endl;
  MapPreOrder(vec, &MapPrint<float>, 0);
  std::cout << "\n" << std::endl;
  std::cout << "\n\n\n\n\n###########################################################" << std::endl;
  std::cout << "~ Calcolo del prodotto di elementi maggiori di N (dato in input) ~"<<std::endl;
  std::cout << "\nInserisci N: \n"<< std::endl;
  std::cin>> n;
  vec.FoldPreOrder(
      [](const float &dat, const void *n, void *prod) {
	if (dat > *((float *)n)) {
	  *((float *)prod) *= dat;
	}
      },
      &n, &prod);
  if (prod != 1.0) {
    std::cout << "Il prodotto e' " << prod << std::endl;
  } else {
    std::cout << "Non vi sono elementi con valore maggiore di quello scelto"
              << std::endl;
  }
  std::cout << "\n\n\n\n\n########################################################" << std::endl;
  std::cout << "~ Applicazione della funzione (N)^2 agli elementi del vettore ~\n\t"<<std::endl;
  MapPreOrder(vec, &MapNxN<float>,0);
  std::cout << "\n" << std::endl;
  MapPreOrder(vec, &MapPrint<float>, 0);
  std::cout << "\n" << std::endl;
  RecapMenu();
}

void VectorString(){
  unsigned long dim;
  int index;
  std::string value, StringaConcatenata, StringaToUpper;
  int n;
  std::cout << "Inserisci la dimensione del vettore: ";
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
  std::cout << "\n\n\n\n\n##############################################################" << std::endl;
  std::cout << "~ Informazioni sul contenuto dell'elemento di indice scelto dall'utente ~" << std::endl;
  std::cout << "###################################################################\n\n\n\n\n" << std::endl;
  std::cout << "Inserisci la posizione dell'elemento di cui ti interessa conoscere il valore: ";
  std::cin >> index;
  while (index > dim - 1){
    std::cout << "L'indice scelto non è valido! Inseriscine uno valido: ";
    std::cin >> index;
  }

  for (int i = 0 ; i < dim ; i ++){
    if (index == i){
      std::cout << "L'indice scelto '" << index << "' contiene il valore '" << vec[i] <<"'"<< std::endl;
    }
  }
  std::cout << "\n\n\n\n\n#############################################################" << std::endl;
  std::cout << "~ Ricerca di un valore all'interno del vettore ~\n\tInserisci l'elemento da ricercare: ";
  std::cin>> value;

  Exists(vec, value);
  std::cout << "\n" << std::endl;
  std::cout << "\n############################################################" << std::endl;
  std::cout << "\nEsecuzione della Map In PreOrder: \n"<< std::endl;
  MapPreOrder(vec, &MapPrint<std::string>, 0);
  std::cout << "\n" << std::endl;
  std::cout << "\n\n\n\n\n###########################################################" << std::endl;
  std::cout << "~ Calcolo della concatenazione di stringhe di lunghezza minore o uguale a N (dato in input) ~"<<std::endl;
  std::cout << "\nInserisci N: \n"<< std::endl;
  std::cin>> n;
  vec.FoldPreOrder([](const std::string& dat, const void* n, void* StringaConcatenata)
	      {
                if (dat.length() <= *((int*)n))
                {
                  *((std::string*)StringaConcatenata) += dat;
                }
              }, &n, &StringaConcatenata);
  if (StringaConcatenata!=""){
    std::cout << "La stringa concatenata e' "<<StringaConcatenata << std::endl;
  }
  else{
    std::cout << "Non vi sono stringhe con lunghezza minore o uguale al valore scelto" << std::endl;
  }

  std::cout << "\n\n\n\n\n########################################################" << std::endl;
  std::cout << "~ Stampa delle stringhe contenute nel vettore in Uppercase ~\n\t"<<std::endl;

  for (int j = 0; j < dim; j ++){
    StringaToUpper = vec[j];
    transform(StringaToUpper.begin(), StringaToUpper.end(), StringaToUpper.begin(), ::toupper); // CONTROLLA SE SIA VALIDO SOLO CON L'std::
    StringaToUpper =  StringaToUpper + " ";
    std::cout << StringaToUpper ;

  }

  std::cout << "\n";
  RecapMenu();
}

void RecapMenu(){
  std::cout<<"Seleziona il tipo di struttura su cui voler effettuare dei test.\n\tVettore di interi (1)\tVettore di Float(2)\tVettore di Stringhe(3)\n"<< std::endl;
  std::cout<<"\tLista di interi (4)\tLista di Float(5)\tLista di Stringhe(6)\n"<< std::endl;
  std::cout<<"\t\t\t(premi q(quit) per uscire)"<< std::endl;
}
