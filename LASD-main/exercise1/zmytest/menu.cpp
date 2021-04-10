#include <iostream>
#include "vector/testvector.hpp"
#include "list/testlist.hpp"
void menu(){

  bool quit = false;
  //int opzione(0);
  char opzione;

  std::cout<<"Seleziona il tipo di struttura\n\tVettore di interi (1)\tVettore di Float(2)\tVettore di Stringhe(3)\n"<< std::endl;
  std::cout<<"\tLista di interi (4)\tLista di Float(5)\tListe di Stringhe(6)\n"<< std::endl;
  std::cout<<"\t\t\t(premi q per uscire)"<< std::endl;
  while (opzione != 'q'){
    std::cin >> opzione;

      if ((opzione !='1') && (opzione != '2')  && (opzione != '3') && (opzione != '4') && (opzione != '5') && (opzione !='6') && (opzione !='q')){
	std::cout << "ERRORE: scelta non valida\nLe strutture valide sono i Vettori(1-2-3) e le Liste(4-5-6)\n";
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
	std::cout<< "Goodbye!"<< std::endl;
	quit = true;
      }
    }

}
