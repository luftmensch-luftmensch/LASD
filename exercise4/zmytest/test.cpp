#include "test.hpp"
#include "BST/bst.hpp"

#include <iostream>


void mytest(){
  char scelta;
  std::cout << "$$$ ALBERI BINARI DI RICERCA $$$ "<< std::endl;
  std::cout<<"Scegli il tipo di dati da gestire: "<< std::endl;
  std::cout<<"(1->Interi; 2->Float; 3->Stringhe; q->Torna indietro)"<< std::endl;
  std::cin >>scelta;

  switch(scelta){
      case '1':
        std::cout << "\033[2J\033[1;1H";
        BinaryTreeLstInt();
        break;

      case '2':
        std::cout << "\033[2J\033[1;1H";
        BinaryTreeLstFloat();
        break;
      case '3':
        std::cout << "\033[2J\033[1;1H";
        BinaryTreeLstString();
        break;

      default:
        std::cout << "\033[2J\033[1;1H";
        std::cout<< "Scelta errata. Riprova. \n\n " <<std::endl;
        mytest();
  }

}
