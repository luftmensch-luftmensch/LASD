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
        system("CLS");
        QueueVec();
        break;

      case '2':
        system("CLS");
        QueueList();
        break;
      case 'q':
          system("CLS");
          mytest();
          break;

      default:
        system("CLS");
        std::cout<< "Scelta errata. Riprova. \n\n " <<std::endl;
        Queue();
  }

}
