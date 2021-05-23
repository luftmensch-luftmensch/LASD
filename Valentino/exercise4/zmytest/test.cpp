#include <iostream>
#include "test.hpp"
#include "../vector/vector.hpp"
#include "../list/list.hpp"
#include "../binarytree/lnk/binarytreelnk.hpp"
#include "../zmytest/container/container.hpp"
#include "../container/container.hpp"
#include "../binarytree/vec/binarytreevec.hpp"
#include "BinarySearchTree/BinarySearchTree.hpp"

void testpersonale(){
  std::cout<< "TEST" << std::endl;

  bool quit = false;
  char scelta;

  std::cout << "Scegli il tipo di struttura: "<< std::endl;
  std::cout<<"BinarySearchTree (1 -> int; 2 -> float; 3 -> string)"<< std::endl;

  while (scelta != 'q') {
    std::cin >> scelta;

    if ((scelta != '1') && (scelta != '2') && (scelta != '3') && (scelta != 'q')) {
      std::cout << "ERRORE: scelta non valida\n";
    }

    if (scelta == '1') {
      std::cout << "\033[2J\033[1;1H";
      BinarySearchTreeInt();
    }
    if (scelta == '2') {
      std::cout << "\033[2J\033[1;1H";
      BinarySearchTreeFloat();
      quit = true;
    }

    if (scelta == '3') {
      std::cout << "\033[2J\033[1;1H";
      BinarySearchTreeString();
      quit = true;
    }

  }
}
