#include "../../container/container.hpp"
#include "../../binarytree/vec/binarytreevec.hpp"
#include "../../binarytree/binarytree.hpp"
#include "../../vector/vector.hpp"

#include "BinaryTreeVecInt/binarytreevecint.hpp"
#include "BinaryTreeVecFloat/binarytreevecfloat.hpp"
#include "BinaryTreeVecString/binarytreevecstring.hpp"
#include "binarytreevec.hpp"

#include "../container/container.hpp"
#include "../test.hpp"


#include <random>
#include <string>
#include <bits/stdc++.h>
#include <iostream>

using namespace std;

void BinaryTreeVec(){
  char scelta;
  std::cout << "Scegli il tipo di dati da gestire: "<< std::endl;
  std::cout<<"(1->Interi; 2->Float; 3->Stringhe; q->Torna indietro)"<< std::endl;
  std::cin >>scelta;

  switch(scelta){
      case '1':
        std::cout << "\033[2J\033[1;1H";
        BinaryTreeVecInt();
        break;

      case '2':
        std::cout << "\033[2J\033[1;1H";
        BinaryTreeVecFloat();
        break;
      case '3':
        std::cout << "\033[2J\033[1;1H";
        BinaryTreeVecString();
        break;
      case 'q':
          std::cout << "\033[2J\033[1;1H";
          mytest();
          break;

      default:
        std::cout << "\033[2J\033[1;1H";
        std::cout<< "Scelta errata. Riprova. \n\n " <<std::endl;
        BinaryTreeVec();
  }
}
