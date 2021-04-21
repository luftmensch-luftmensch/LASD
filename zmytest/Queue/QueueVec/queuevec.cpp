#include <iostream>
#include "../../../container/container.hpp"
//#include "../../stack/stack.hpp"
//#include "../../stack/vec/stackvec.hpp"
//#include "../../stack/lst/stacklst.hpp"
#include "../../../queue/vec/queuevec.hpp"
//#include "../../queue/lst/queuelst.hpp"
#include "queuevec.hpp"
#include "../queue.hpp"
#include "../../test.hpp"
void QueueVecInt(){
  unsigned int dim;
  std::cout << "Inserire la dimensione dello stack di interi" << std::endl;
  std::cin >> dim;
}


void QueueVecFloat(){
  std::cout << "DOUBLE" << std::endl;
}
void QueueVecString(){
  std::cout << "STRINGA" << std::endl;
}

void QueueVec(){
  char scelta;
  std::cout << "Scegli il tipo di dati da gestire: "<< std::endl;
  std::cout<<"(1->Interi; 2->Float; 3->Stringhe; q->Torna indietro)"<< std::endl;
  std::cin >>scelta;

  switch(scelta){
      case '1':
        system("CLS");
        QueueVecInt();
        break;

      case '2':
        system("CLS");
        QueueVecFloat();
        break;
      case '3':
        system("CLS");
        QueueVecString();
        break;
      case 'q':
          system("CLS");
          Queue();
          break;

      default:
        system("CLS");
        std::cout<< "Scelta errata. Riprova. \n\n " <<std::endl;
        QueueVec();
  }

}
