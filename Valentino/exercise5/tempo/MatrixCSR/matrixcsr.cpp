#include "../../container/container.hpp"
#include "../../matrix/csr/matrixcsr.hpp"
#include "../../matrix/matrix.hpp"
#include "../../vector/vector.hpp"

#include "MatrixCSRInt/matrixcsrint.hpp"
#include "MatrixCSRFloat/matrixcsrfloat.hpp"
#include "MatrixCSRString/matrixcsrstring.hpp"
#include "matrixcsr.hpp"

#include "../container/container.hpp"
#include "../test.hpp"


#include <random>
#include <string>
#include <bits/stdc++.h>
#include <iostream>

using namespace std;

void MatrixCSR(){
  char scelta;
  std::cout << "Scegli il tipo di dati da gestire: "<< std::endl;
  std::cout<<"(1->Interi; 2->Float; 3->Stringhe; q->Torna indietro)"<< std::endl;
  std::cin >>scelta;

  switch(scelta){
      case '1':
        std::cout << "\033[2J\033[1;1H";
        MatrixCSRInt();
        break;

      case '2':
        std::cout << "\033[2J\033[1;1H";
        MatrixCSRFloat();
        break;
      case '3':
        std::cout << "\033[2J\033[1;1H";
        MatrixCSRString();
        break;
      case 'q':
          std::cout << "\033[2J\033[1;1H";
          mytest();
          break;

      default:
        std::cout << "\033[2J\033[1;1H";
        std::cout<< "Scelta errata. Riprova. \n\n " <<std::endl;
        MatrixCSR();
  }
}
