#include <iostream>
#include "../../../container/container.hpp"
#include "../../stack/stack.hpp"
//#include "../../stack/vec/stackvec.hpp"
#include "../../../stack/lst/stacklst.hpp"
//#include "../../queue/queue.hpp"
//#include "../../queue/vec/queuevec.hpp"
//#include "../../queue/lst/queuelst.hpp"
#include "stacklist.hpp"
#include "../stack.hpp"
void StackListInt(){
  unsigned int dim;
  std::cout << "Inserire la dimensione dello stack di interi" << std::endl;
  std::cin >> dim;
}


void StackListFloat(){
  std::cout << "DOUBLE" << std::endl;
}
void StackListString(){
  std::cout << "STRINGA" << std::endl;
}

void StackList(){
  char scelta;
  std::cout << "Scegli il tipo di dati da gestire: "<< std::endl;
  std::cout<<"(1->Interi; 2->Float; 3->Stringhe; q->Torna indietro)"<< std::endl;
  std::cin >>scelta;

  switch(scelta){
      case '1':
        system("CLS");
        StackListInt();
        break;

      case '2':
        system("CLS");
        StackListFloat();
        break;
      case '3':
        system("CLS");
        StackListString();
        break;
      case 'q':
          system("CLS");
          Stack();
          break;

      default:
        system("CLS");
        std::cout<< "Scelta errata. Riprova. \n\n " <<std::endl;
        StackList();
  }

}
