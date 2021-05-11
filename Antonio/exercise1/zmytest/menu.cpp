#include <iostream>
#include "vector/testvector.hpp"
#include "list/testlist.hpp"
void menu(){

  bool quit = false;
  char opzione;

  std::cout<<"Seleziona il tipo di struttura su cui voler effettuare dei test.\n\tVettore di interi (1)\tVettore di Float(2)\tVettore di Stringhe(3)\n"<< std::endl;
  std::cout<<"\tLista di interi (4)\tLista di Float(5)\tLista di Stringhe(6)\n"<< std::endl;
  std::cout<<"\t\t\t(premi q (quit) per uscire)"<< std::endl;
  while (opzione != 'q'){
    std::cin >> opzione;

      if ((opzione !='1') && (opzione != '2')  && (opzione != '3') && (opzione != '4') && (opzione != '5') && (opzione !='6') && (opzione !='q')){
	std::cout << "ERRORE: la tua scelta non è valida. Riprova. \nLe strutture valide sono i Vettori(inserisci i numeri 1,2 o 3) e le Liste(inserisci i numeri 1,2 o 3)\n";
	}

      if (opzione == '1'){
	std::system("clear");
	VectorInt();
      }
      if (opzione == '2'){
	std::system("clear");
	VectorFloat();
	quit = true;
      }
      if (opzione == '3'){
	std::system("clear");
	VectorString();
	quit = true;
      }
      if (opzione == '4'){
	std::system("clear");
	ListInt();
	quit = true;
      }
      if (opzione == '5'){
	std::system("clear");
	ListFloat();
	quit = true;
      }
      if (opzione == '6'){
	std::system("clear");
	ListString();
	quit = true;
      }
      if (opzione == 'q'){
	std::cout<< "Cya!"<< std::endl;
	quit = true;
      }
    }

}
