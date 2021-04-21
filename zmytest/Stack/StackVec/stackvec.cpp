#include "../../../container/container.hpp"
#include "../stack.hpp"
#include "../../../stack/vec/stackvec.hpp"
#include "stackvec.hpp"
#include "../../../zlasdtest/container/container.hpp"
#include "../../../vector/vector.hpp"
#include <random>
#include <string>
#include <bits/stdc++.h>
#include <iostream>

using namespace std;
//#include "../../stack/lst/stacklst.hpp"
//#include "../../queue/queue.hpp"
//#include "../../queue/vec/queuevec.hpp"
//#include "../../queue/lst/queuelst.hpp"


template <typename Data>
void OperazioniStackVec(lasd::StackVec<Data>& stackvec){
char scelta;
int elem;
std::cout << "Scegli l'operazione che vuoi effettuare \n "<< std::endl;
std::cout<<"1->Inserimento \n2->Rimozione \n3->Rimozione con lettura \n4->Lettura non distruttiva"<< std::endl;
std::cout <<"5->Test di vuotezza \n6->Lettura della dimensione \n7->Svuotamento \nq->Torna indietro )"<< std::endl;

std::cin >>scelta;

switch(scelta){
    case '1':
      system("CLS");
      cout<<"Scegli l'elemento da inserire: \n"<<endl;
      cin>> elem;
      stackvec.Push(elem);
      OperazioniStackVec(stackvec);
      break;
    case '2':
      system("CLS");
      stackvec.Pop();
      OperazioniStackVec(stackvec);
      break;
    case '3':
      system("CLS");
      elem=stackvec.TopNPop();
      cout<<"\n"<< elem <<endl;
      OperazioniStackVec(stackvec);
      break;
    case '4':
      system("CLS");

      OperazioniStackVec(stackvec);
      break;
    case '5':
      system("CLS");

      OperazioniStackVec(stackvec);
      break;
    case '6':
      system("CLS");

      OperazioniStackVec(stackvec);
      break;
    case '7':
      system("CLS");

      OperazioniStackVec(stackvec);
      break;
    case 'q':
        system("CLS");
        Stack();
        break;

    default:
      system("CLS");
      std::cout<< "Scelta errata. Riprova. \n\n " <<std::endl;
      OperazioniStackVec(stackvec);
  }
}

void StackVecInt(){
  unsigned long N;
  std::cout << "Scegli il numero di elementi da inserire nella struttura (N)" << std::endl;
  std::cin >> N;

  default_random_engine gen(random_device{}());
  uniform_int_distribution<unsigned int> dist(1, 100);

  lasd::StackVec<int> stackvec;
  std::cout<<"\n"<<std::endl;
  for(unsigned long i = 0; i < N; i++) {
    int elem=dist(gen);
    stackvec.Push(elem);
    std::cout<< "  "<< elem <<"  "<<std::endl;
  }
  OperazioniStackVec(stackvec);
}

void StackVecFloat(){
  std::cout << "DOUBLE" << std::endl;
}
void StackVecString(){
  std::cout << "STRINGA" << std::endl;
}

void StackVec(){
  char scelta;
  std::cout << "Scegli il tipo di dati da gestire: "<< std::endl;
  std::cout<<"(1->Interi; 2->Float; 3->Stringhe; q->Torna indietro)"<< std::endl;
  std::cin >>scelta;

  switch(scelta){
      case '1':
        system("CLS");
        StackVecInt();
        break;

      case '2':
        system("CLS");
        StackVecFloat();
        break;
      case '3':
        system("CLS");
        StackVecString();
        break;
      case 'q':
          system("CLS");
          Stack();
          break;

      default:
        system("CLS");
        std::cout<< "Scelta errata. Riprova. \n\n " <<std::endl;
        StackVec();
  }

}
