#include <iostream>
#include <random>
#include "../../container/container.hpp"
#include "../../stack/stack.hpp"
#include "../../stack/vec/stackvec.hpp"
#include "Stack.hpp"

void StackVecInt(){
  uint dim, elemento;
  uint j = 0;
  bool quit = false;
  char opzione;
  std::cout << "Inserire la dimensione dello stack di interi" << std::endl;
  std::cin >> dim;

  std::default_random_engine gen(std::random_device{}());
  std::uniform_int_distribution<unsigned int> dist(1, 100);
  lasd::StackVec<int> StackVecInt;
  while (j < dim){
    StackVecInt.Push(dist(gen));
    j++;
  }
  OperazioniDaEseguire();

  while (opzione != 'q'){
    std::cin >> opzione;

    if ((opzione != '1') && (opzione != '2') && (opzione != '3') &&
	(opzione != '4') && (opzione != '5') && (opzione != '6') &&
	(opzione != '7') && opzione != 'q') {
      std::cout << "ERRORE: opzione non valida\n";
    }
    if (opzione == '1') { // Inserimento
      std::system("clear");
      std::cout<< "Digita l'elemento da inserire nella struttura"<< std::endl;
      std::cin >> elemento;
      StackVecInt.Push(elemento);
      OperazioniDaEseguire();
    }
    if (opzione == '2') { // Rimozione
      std::system("clear");
      StackVecInt.Pop();
      quit = true;
      OperazioniDaEseguire();
    }

    if (opzione == '3') { // Rimozione con lettura
      std::system("clear");
      StackVecInt.TopNPop();
      quit = true;
      OperazioniDaEseguire();
    }
    if (opzione == '4') { // Lettura non distruttiva
      std::system("clear");
      elemento = StackVecInt.Top();
      std::cout<< "L'elemento in lettura è: " << elemento << std::endl;
      quit = true;
      OperazioniDaEseguire();
    }

    if (opzione == '5') { // Controllo sulla vuotezza della struttura
      std::system("clear");
      if (StackVecInt.Empty()) {
	std::cout<< "Lo stack è vuoto"<< std::endl;

      } else {
	std::cout<< "Lo stack non è vuoto"<< std::endl;
      }
      quit = true;
      OperazioniDaEseguire();
    }
    if (opzione == '6') { // Informazione sulla dimensione della struttura
      std::system("clear");
      elemento = StackVecInt.Size();
      std::cout<< "La dimensione dello Stack è " << elemento << std::endl;
      quit = true;
      OperazioniDaEseguire();
    }
    if (opzione == '7') { // Svuotamento
      std::system("clear");
      quit = true;
      StackVecInt.Clear();
      std::cout<< "Struttura svuotata" << std::endl;
      OperazioniDaEseguire();
    }
    if (opzione == 'q') { // Uscita

	std::cout << "Scegli il tipo di struttura: "<< std::endl;
	std::cout<<"Stack implementato con vettori (1 -> int; 2 -> double; 3 -> string)"<< std::endl;
	std::cout<<"Stack implementato con lista (4 -> int; 5 -> double; 6 -> string)"<< std::endl;
	std::cout<<"Queue implementata con vettori (a -> int; b -> double; c -> string)"<< std::endl;
	std::cout<<"Queue implementato con lista (d -> int; e -> double; f -> string)"<< std::endl;
	std::cout<<"\t\t\t(premi q per uscire)"<< std::endl;
    }
  }
}
