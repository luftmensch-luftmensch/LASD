#include "Stack/stack.hpp"
#include "Queue/queue.hpp"
#include "test.hpp"
/* ************************************************************************** */

#include <iostream>

/* ************************************************************************** */


void mytest(){
  char scelta;
  std::cout << "Scegli il tipo di struttura: "<< std::endl;
  std::cout<<"(1->Stack; 2->Queue; q->exit)"<< std::endl;
  std::cin >> scelta;
  switch(scelta){
      case '1':
        system("CLS");
        Stack();
        break;

      case '2':
        system("CLS");
        Queue();
        break;
      case 'q':
          std::cout << "Cya!" <<std::endl;
          break;

      default :
        system("CLS");
        std::cout<< "Scelta errata. Riprova. \n\n " <<std::endl;
        mytest();
  } 
}
