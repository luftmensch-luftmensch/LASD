#include <iostream>
#include <random>
#include "../../container/container.hpp"
#include "../../queue/queue.hpp"
#include "../../queue/vec/queuevec.hpp"
#include "Queue.hpp"

#include "../../queue/lst/queuelst.hpp"

void QueueVecDouble(){
  uint dim, elemento;
  uint j = 0;
  char opzione;
  bool quit = false;

  std::cout << "Inserire la dimensione della coda di double" << std::endl;
  std::cin >> dim;

  std::default_random_engine gen(std::random_device{}());
  std::uniform_real_distribution<double> dist(1.0, 100.0);
  lasd::QueueVec<double> QueueVecDouble;
  while (j < dim){
    QueueVecDouble.Enqueue(dist(gen));
    j++;
  }

  OperazioniQueue();
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
      QueueVecDouble.Enqueue(elemento);
      OperazioniQueue();
    }
    if (opzione == '2') { // Rimozione
      std::system("clear");
      QueueVecDouble.Dequeue();
      quit = true;
      OperazioniQueue();
    }

    if (opzione == '3') { // Rimozione con lettura
      std::system("clear");
      QueueVecDouble.HeadNDequeue();
      quit = true;
      OperazioniQueue();
    }
    if (opzione == '4') { // Lettura non distruttiva
      std::system("clear");
      elemento = QueueVecDouble.Head();
      std::cout<< "L'elemento in lettura è: " << elemento << std::endl;
      quit = true;
      OperazioniQueue();
    }

    if (opzione == '5') { // Controllo sulla vuotezza della struttura
      std::system("clear");
      if (QueueVecDouble.Empty()) {
	std::cout<< "Lo stack è vuoto"<< std::endl;

      } else {
	std::cout<< "Lo stack non è vuoto"<< std::endl;
      }
      quit = true;
      OperazioniQueue();
    }
    if (opzione == '6') { // Informazione sulla dimensione della struttura
      std::system("clear");
      elemento = QueueVecDouble.Size();
      std::cout<< "La dimensione dello Stack è " << elemento << std::endl;
      quit = true;
      OperazioniQueue();
    }
    if (opzione == '7') { // Svuotamento
      std::system("clear");
      quit = true;
      QueueVecDouble.Clear();
      std::cout<< "Struttura svuotata" << std::endl;
      OperazioniQueue();
    }
    if (opzione == 'q') { // Uscita
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
