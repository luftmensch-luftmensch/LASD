#include <iostream>
#include "vector/testvector.hpp"
using namespace std;
void menu(){

  bool quit = false;
  int opzione(0);

  std::cout<<"Seleziona il tipo di struttura\n\tVettore (1)\n\tLista(2)\n (premi 8 per uscire)"<< std::endl;
  while (!quit){
      cin >> opzione;

      if ((opzione != 1) && (opzione != 2)  && (opzione != 8)){
	cout << "ERRORE: scelta non valida\nLe strutture valide sono i Vettori(1) e le Liste(2)\n";
	}

      if (opzione == 1)
	SceltaSuiVettori();
      if (opzione == 2)
	//SceltaSulleListe(); DA IMPLEMENTARE
      if (opzione ==8) 
	quit = true;
    }

}
