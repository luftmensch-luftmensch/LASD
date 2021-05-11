#include "test.hpp"
#include "BinaryTreeVec/binarytreevec.hpp"
#include "BinaryTreeLst/binarytreelst.hpp"

#include <iostream>


void mytest(){
  char scelta;
  std::cout << "Scegli il tipo di rappresentazione di Albero Binario su cui vuoi operare: "<< std::endl;
  std::cout<<"(1->Linked List Representation; 2->Array Representation; q->exit)"<< std::endl;
  std::cin >> scelta;
  switch(scelta){
      case '1':
        std::cout << "\033[2J\033[1;1H";
        BinaryTreeLst();
        break;

      case '2':
        std::cout << "\033[2J\033[1;1H";
        BinaryTreeVec();
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
