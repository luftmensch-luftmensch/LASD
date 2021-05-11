#include "../test.hpp"
#include "StackVec/stackvec.hpp"
#include "StackList/stacklist.hpp"
#include "stack.hpp"
#include <iostream>
/* ************************************************************************** */



void Stack(){
  char scelta;
  std::cout << "Scegli il tipo di implementazione per lo Stack: "<< std::endl;
  std::cout<<"(1->Vettore; 2->Lista; q->Torna indietro)"<< std::endl;
  std::cin >> scelta;

  switch(scelta){
      case '1':
        std::cout << "\033[2J\033[1;1H";  //for windows: system("CLS");
        StackVec();
        break;

      case '2':

        std::cout << "\033[2J\033[1;1H";
        StackList();
        break;
      case 'q':
          std::cout << "\033[2J\033[1;1H";
          mytest();
          break;

      default:
        std::cout << "\033[2J\033[1;1H";
        std::cout<< "Scelta errata. Riprova. \n\n " <<std::endl;
        Stack();
  }
}
