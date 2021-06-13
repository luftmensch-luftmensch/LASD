#include "test.hpp"
#include "MatrixVec/matrixvec.hpp"
#include "MatrixCSR/matrixcsr.hpp"

#include <iostream>


void mytest(){
  char scelta;
  std::cout << "Scegli il tipo di rappresentazione di matrice su cui vuoi operare: "<< std::endl;
  std::cout<<"(1->Matrice Densa (Naive Representation) 2->Matrice Sparsa (CSR) q->exit)"<< std::endl;
  std::cin >> scelta;
  switch(scelta){
      case '1':
        std::cout << "\033[2J\033[1;1H";
        MatrixVec();
        break;

      case '2':
        std::cout << "\033[2J\033[1;1H";
        MatrixCSR();
        break;
      case 'q':
          std::cout << "Cya!" <<std::endl;
          break;

      default :
        std::cout << "\033[2J\033[1;1H";
        std::cout<< "Scelta errata. Riprova. \n\n " <<std::endl;
        mytest();
  }
}
