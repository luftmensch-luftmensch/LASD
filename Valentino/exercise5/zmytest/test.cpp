#include <iostream>
#include "test.hpp"
#include  "MatrixVec/matrixVec.hpp"
#include  "MatrixCSR/matrixCSR.hpp"

void testpersonale(){

  bool quit = false;
  char scelta;

  std::cout << "Scegli il tipo di rappresentazione di matrice su cui vuoi operare: "<< std::endl;
  std::cout<<"(Matrice Densa - Naive Representation (1 - Int; 2 - Float; 3 - String) Matrice Sparsa - CSR (4 - Int; 5 - Float; 6 - String) q->exit)"<< std::endl; 

  while (scelta != 'q') {
    std::cin >> scelta;

    if ((scelta != '1') && (scelta != '2') && (scelta != '3') &&
	(scelta != '4') && (scelta != '5') && (scelta != '6') &&
	(scelta != 'q')) {
      std::cout << "ERRORE: scelta non valida\n";
    }

    if (scelta == '1') {
      std::cout << "\033[2J\033[1;1H";
      MatrixVecInt();
    }
    if (scelta == '2') {
      std::cout << "\033[2J\033[1;1H";
      quit = true;
      MatrixVecFloat();
    }

    if (scelta == '3') {
      std::cout << "\033[2J\033[1;1H";
      quit = true;
      MatrixVecString();
    }

    if (scelta == '4') {
      std::cout << "\033[2J\033[1;1H";
      MatrixCsrInt();
    }

    if (scelta == '5') {
      std::cout << "\033[2J\033[1;1H";
      MatrixCsrFloat();
    }

    if (scelta == '6') {
      std::cout << "\033[2J\033[1;1H";
      MatrixCsrString();
    }
    if (scelta == 'q'){
      std::cout<< "Goodbye"<< std::endl;
    }
  }
}
