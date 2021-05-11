#include <iostream>
#include "test.hpp"
#include "BinaryTree/BinaryTreeVec/binarytreevec.hpp"
#include "BinaryTree/BinaryTreeList/binarytreelist.hpp"
#include "../vector/vector.hpp"
#include "../list/list.hpp"
#include "../binarytree/lnk/binarytreelnk.hpp"
#include "../zmytest/container/container.hpp"
#include "../container/container.hpp"
#include "../binarytree/vec/binarytreevec.hpp"

void testpersonale(){
  std::cout<< "TEST" << std::endl;

  bool quit = false;
  char scelta;

  std::cout << "Scegli il tipo di struttura: "<< std::endl;
  std::cout<<"Binarytree implementato con vettori (1 -> int; 2 -> float; 3 -> string)"<< std::endl;
  std::cout<<"Binarytree implementato con lista (4 -> int; 5 -> float; 6 -> string)"<< std::endl;

  while (scelta != 'q') {
    std::cin >> scelta;

    if ((scelta != '1') && (scelta != '2') && (scelta != '3') &&
	(scelta != '4') && (scelta != '5') && (scelta != '6') &&
	(scelta != 'q')) {
      std::cout << "ERRORE: scelta non valida\n";
    }

    if (scelta == '1') {
      std::cout << "\033[2J\033[1;1H";
      BinaryTreeVecInt(); 
    }
    if (scelta == '2') {
      std::cout << "\033[2J\033[1;1H";
      BinaryTreeVecFloat();
      quit = true;
    }

    if (scelta == '3') {
      std::cout << "\033[2J\033[1;1H";
      BinaryTreeVecString();
      quit = true;
    }
    if (scelta == '4') {
      std::cout << "\033[2J\033[1;1H";
      BinaryTreeListInt();
      quit = true;
    }

    if (scelta == '5') {
      std::cout << "\033[2J\033[1;1H";
      BinaryTreeListFloat();
      quit = true;
    }
    if (scelta == '6') {
      std::cout << "\033[2J\033[1;1H";
      BinaryTreeListString();
      quit = true;
    }


  }
}
