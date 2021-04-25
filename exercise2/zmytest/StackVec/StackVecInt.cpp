#include <iostream>
#include <random>
#include "../../container/container.hpp"
#include "../../stack/stack.hpp"
#include "../../stack/vec/stackvec.hpp"
#include "../../stack/lst/stacklst.hpp"
#include "../../queue/queue.hpp"
#include "../../queue/vec/queuevec.hpp"
#include "../../queue/lst/queuelst.hpp"
#include "StackVec.hpp"

void StackVecInt(){
  uint dim;
  uint j = 0;
  bool quit = false;
  char opzione;
  std::cout << "Inserire la dimensione dello stack di interi" << std::endl;
  std::cin >> dim;

  std::default_random_engine gen(std::random_device{}());
  std::uniform_int_distribution<unsigned int> dist(1, 100);
  lasd::StackVec<int> StacVecInt;
  while (j < dim){
    StacVecInt.Push(dist(gen));
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
    if (opzione == '1') {
      std::system("clear");
      OperazioniDaEseguire();
    }
    if (opzione == '2') {
      std::system("clear");
      quit = true;
      OperazioniDaEseguire();
    }

    if (opzione == '3') {
      std::system("clear");
      quit = true;
      OperazioniDaEseguire();
    }
    if (opzione == '4') {
      std::system("clear");
      quit = true;
      OperazioniDaEseguire();
    }

    if (opzione == '5') {
      std::system("clear");
      quit = true;
      OperazioniDaEseguire();
    }
    if (opzione == '6') {
      std::system("clear");
      quit = true;
      OperazioniDaEseguire();
    }
    if (opzione == '7') {
      std::system("clear");
      quit = true;
      OperazioniDaEseguire();
    }
    if (opzione == 'q'){

      std::cout << "Scegli il tipo di struttura: " << std::endl;
      std::cout << "Stack implementato con vettori (1 -> int; 2 -> double; 3 "
		   "-> string)"
		<< std::endl;
      std::cout
	  << "Stack implementato con lista (4 -> int; 5 -> double; 6 -> string)"
	  << std::endl;
      std::cout << "Queue implementata con vettori (a -> int; b -> double; c "
		   "-> string)"
		<< std::endl;
      std::cout
	  << "Queue implementato con lista (d -> int; e -> double; f -> string)"
          << std::endl;
      std::cout << "\t\t\t(premi q per uscire)" << std::endl;
    }
  }
}
