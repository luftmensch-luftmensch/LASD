#include <iostream>
#include <random>
#include "../../../binarytree/binarytree.hpp"
#include "../../../binarytree/vec/binarytreevec.hpp"

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
      
    }
  }
}
