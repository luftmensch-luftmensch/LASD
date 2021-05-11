#include "../test.hpp"
#include "QueueList/queuelist.hpp"
#include "QueueVec/queuevec.hpp"
#include "queue.hpp"
#include <iostream>
/* ************************************************************************** */


void Queue(){
  char scelta;
  std::cout << "Scegli il tipo di implementazione per la Queue: "<< std::endl;
  std::cout<<"(1->Vettore; 2->Lista; q->Torna indietro)"<< std::endl;
  std::cin >> scelta;

  switch(scelta){
      case '1':
        std::cout << "\033[2J\033[1;1H";
        QueueVec();
        break;

      case '2':
        std::cout << "\033[2J\033[1;1H";
        QueueList();
        break;
      case 'q':
          std::cout << "\033[2J\033[1;1H";
          mytest();
          break;

      default:
        std::cout << "\033[2J\033[1;1H";
        std::cout<< "Scelta errata. Riprova. \n\n " <<std::endl;
        Queue();
  }

}
