#include <iostream>
//#include "../../stack/stack.hpp"
//#include "../../stack/vec/stackvec.hpp"
//#include "../../stack/lst/stacklst.hpp"
#include "../queue.hpp"
#include "../../test.hpp"
//#include "../../queue/vec/queuevec.hpp"
#include "../../../queue/lst/queuelst.hpp"
#include "queuelist.hpp"
void QueueListInt(){
  unsigned int dim;
  std::cout << "Inserire la dimensione dello stack di interi" << std::endl;
  std::cin >> dim;
}


void QueueListFloat(){
  std::cout << "DOUBLE" << std::endl;
}
void QueueListString(){
  std::cout << "STRINGA" << std::endl;
}

void QueueList(){
  char scelta;
  std::cout << "Scegli il tipo di dati da gestire: "<< std::endl;
  std::cout<<"(1->Interi; 2->Float; 3->Stringhe; q->Torna indietro)"<< std::endl;
  std::cin >>scelta;

  switch(scelta){
      case '1':
        system("CLS");
        QueueListInt();
        break;

      case '2':
        system("CLS");
        QueueListFloat();
        break;
      case '3':
        system("CLS");
        QueueListString();
        break;
      case 'q':
          system("CLS");
          Queue();
          break;

      default:
        system("CLS");
        std::cout<< "Scelta errata. Riprova. \n\n " <<std::endl;
        QueueList();
  }

}
