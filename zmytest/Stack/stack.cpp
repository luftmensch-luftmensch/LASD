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
        system("CLS"); // std::system("clear");
        StackVec();
        break;

      case '2':

        system("CLS");
        StackList();
        break;
      case 'q':
          system("CLS");
          mytest();
          break;

      default:
        system("CLS");
        std::cout<< "Scelta errata. Riprova. \n\n " <<std::endl;
        Stack();
  }

}
