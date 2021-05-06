#include <iostream>
#include <random>
#include "../../../binarytree/binarytree.hpp"
#include "../../../binarytree/vec/binarytreevec.hpp"
#include "../../container/container.hpp"
#include "binarytreevec.hpp"

void BinaryTreeVecInt(){
  uint dim, elemento;
  uint j = 0;
  bool quit = false;
  char opzione;

  std::cout << "Inserire la dimensione del binarytree di interi" << std::endl;
  std::cin >> dim;

  std::default_random_engine gen(std::random_device{}());
  std::uniform_int_distribution<unsigned int> dist(1, 100);
  lasd::Vector<int> VettoreInt(dim);

  while(j < dim){
    VettoreInt[j] = dist(gen);
    j++;
  }
  lasd::BinaryTreeVec<int> BinaryTreeInt(VettoreInt);

  OperazioniDaEseguire();
  while (opzione != 'q') {
    std::cin >> opzione;

    if ((opzione != '1') && (opzione != '2') && (opzione != '3') &&
	(opzione != '4') && (opzione != '5') && (opzione != '6') &&
	(opzione != '7') &&  (opzione != '8') && (opzione != '9') &&
	(opzione != 'a') &&  (opzione != 'b') &&
	(opzione != 'q')) {
      std::cout << "ERRORE: opzione non valida\n";
    }
    if (opzione == '1'){ // Visualizzazione in Pre-Order
      MapPreOrder(BinaryTreeInt, &MapPrint<int> , 0);
    }

    if (opzione == '2'){ // Visualizzazione in Post-Order
      MapPostOrder(BinaryTreeInt, &MapPrint<int> , 0);
    }

    if (opzione == '3'){ // Visualizzazione Inorder
      MapInOrder(BinaryTreeInt, &MapPrint<int> , 0);
    }

    if (opzione == '4'){ // Visualizzazione in Ampiezza
      MapBreadth(BinaryTreeInt, &MapPrint<int> , 0);
    }

    if (opzione == '5'){ // Controllo di esistenza di un dato valore nella struttura
      std::cout << "Inserisci l'elemento da ricercare: ";
      std::cin >> elemento;
      if (BinaryTreeInt.Exists(elemento)){
	std::cout << "Elemento trovato";
      } else{
	std::cout << "Elemento non trovato";
      }
    }

    if (opzione == '6'){ // Controllo di vuotezza della  Struttura
      if (BinaryTreeInt.Empty()){
	std::cout << "La Struttura è vuota"<< std::endl;
      } else{
	std::cout << "La Struttura non è vuota" << std::endl;
      }
    }
    if (opzione == '7'){
      std::cout << "La dimensione della struttura è " << BinaryTreeInt.Size() << std::endl;
    }
    if (opzione == '8'){
      BinaryTreeInt.Clear();
      std::cout << "Struttura svuotata" << std::endl;
    }
    if (opzione == 'q'){
      std::cout << "Scegli il tipo di struttura: "<< std::endl;
      std::cout<<"Binarytree implementato con vettori (1 -> int; 2 -> float; 3 -> string)"<< std::endl;
      std::cout<<"Binarytree implementato con lista (4 -> int; 5 -> float; 6 -> string)"<< std::endl;
      std::cout<< "Premi q per uscire" << std::endl;
    }
  }
}
