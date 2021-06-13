#include "../../container/container.hpp"
#include "../../matrix/vec/matrixvec.hpp"
#include "../../matrix/matrix.hpp"
#include "../../vector/vector.hpp"

#include "MatrixVecInt/matrixvecint.hpp"
#include "MatrixVecFloat/matrixvecfloat.hpp"
#include "MatrixVecString/matrixvecstring.hpp"
#include "matrixvec.hpp"

#include "../container/container.hpp"
#include "../test.hpp"


#include <random>
#include <string>
#include <bits/stdc++.h>
#include <iostream>

using namespace std;

void MatrixVec(){
  char scelta;
  std::cout << "Scegli il tipo di dati da gestire: "<< std::endl;
  std::cout<<"(1->Interi; 2->Float; 3->Stringhe; q->Torna indietro)"<< std::endl;
  std::cin >>scelta;

  switch(scelta){
      case '1':
        std::cout << "\033[2J\033[1;1H";
        MatrixVecInt();
        break;

      case '2':
        std::cout << "\033[2J\033[1;1H";
        MatrixVecFloat();
        break;
      case '3':
        std::cout << "\033[2J\033[1;1H";
        MatrixVecString();
        break;
      case 'q':
          std::cout << "\033[2J\033[1;1H";
          mytest();
          break;

      default:
        std::cout << "\033[2J\033[1;1H";
        std::cout<< "Scelta errata. Riprova. \n\n " <<std::endl;
        MatrixVec();
  }
}
