#include "../../../container/container.hpp"
#include "../../../stack/stack.hpp"
#include "../../../stack/lst/stacklst.hpp"
#include "stacklist.hpp"
#include "../stack.hpp"

#include <random>
#include <string>
#include <bits/stdc++.h>
#include <iostream>

using namespace std;

template <typename Data>
void OperazioniStackList(lasd::StackLst<Data>& stacklist){
char scelta;
Data elem;
std::cout << "\nScegli l'operazione che vuoi effettuare \n "<< std::endl;
std::cout<<"1->Inserimento \n2->Rimozione \n3->Rimozione con lettura \n4->Lettura non distruttiva"<< std::endl;
std::cout <<"5->Test di vuotezza \n6->Lettura della dimensione \n7->Svuotamento \nq->Torna indietro "<< std::endl;

std::cin >>scelta;

switch(scelta){
    case '1':
      std::cout << "\033[2J\033[1;1H";
      cout<<"Scegli l'elemento da inserire: \n"<<endl;
      cin>> elem;
      stacklist.Push(elem);
      OperazioniStackList(stacklist);
      break;
    case '2':
      std::cout << "\033[2J\033[1;1H";
      stacklist.Pop();
      OperazioniStackList(stacklist);
      break;
    case '3':
      std::cout << "\033[2J\033[1;1H";
      elem=stacklist.TopNPop();
      cout<<"\n"<< elem <<endl;
      OperazioniStackList(stacklist);
      break;
    case '4':
      std::cout << "\033[2J\033[1;1H";
      elem=stacklist.Top();
      cout<<"\n"<< elem <<endl;
      OperazioniStackList(stacklist);
      break;
    case '5':
      std::cout << "\033[2J\033[1;1H";
      if(stacklist.Empty()){
        cout<<"\n"<< "Lo stack e' vuoto"<<endl;
      }
      else{
        cout<<"\n"<< "Lo stack non e' vuoto"<<endl;
      }
      OperazioniStackList(stacklist);
      break;
    case '6':
      std::cout << "\033[2J\033[1;1H";
      elem=stacklist.Size();
      cout<<"\n"<<"La dimensione attuale dello stack e': "<<elem<<endl;
      OperazioniStackList(stacklist);
      break;
    case '7':
      std::cout << "\033[2J\033[1;1H";
      if(stacklist.Empty()){
        cout<<"\n"<< "Attualmente lo stack e' vuoto"<<endl;
      }
      else{
        cout<<"\n"<< "Attualmente lo stack non e' vuoto";
      }
      stacklist.Clear();
      if(stacklist.Empty()){
        cout<<"------>"<< "Lo stack e' stato svuotato"<<endl;
      }

      OperazioniStackList(stacklist);
      break;
    case 'q':
        std::cout << "\033[2J\033[1;1H";
        Stack();
        break;

    default:
      std::cout << "\033[2J\033[1;1H";
      std::cout<< "Scelta errata. Riprova. \n\n " <<std::endl;
      OperazioniStackList(stacklist);
  }
}



void StackListInt(){
  unsigned long N;
  std::cout << "Scegli il numero di elementi da inserire nella struttura (N)" << std::endl;
  std::cin >> N;

  default_random_engine gen(random_device{}());
  uniform_int_distribution<unsigned int> dist(1, 100);

  lasd::StackLst<int> stacklist;
  std::cout<<"\n"<<std::endl;
  for(unsigned long i = 0; i < N; i++) {
    int elem=dist(gen);
    stacklist.Push(elem);
    std::cout<< "<-"<< elem <<" ";
  }
  OperazioniStackList(stacklist);
}


void StackListFloat(){
  unsigned long N;
  std::cout << "Scegli il numero di elementi da inserire nella struttura (N)" << std::endl;
  std::cin >> N;

  default_random_engine gen(random_device{}());
  uniform_real_distribution<float> dist(1.0, 100.0);

  lasd::StackLst<float> stacklist;
  std::cout<<"\n"<<std::endl;
  for(unsigned long i = 0; i < N; i++) {
    float elem=dist(gen);
    stacklist.Push(elem);
    std::cout<< "<-"<< elem <<" ";
  }
  OperazioniStackList(stacklist);
}


void StackListString(){
  srand(time(NULL));
  unsigned long N;
  int stringlenght = 5;
  const int MAX = 52;
  lasd::StackLst<string> stacklist;
  std::cout << "Scegli il numero di elementi da inserire nella struttura (N)" << std::endl;
  std::cin >> N;

  char alphabet[MAX] = {'a','b','c','d','e','f','g','h','i','j','k','l','m','n',
                        'o','p','q','r','s','t','u','v','w','x','y','z','A','B',
                        'C','D','E','F','G','H','I','J','K','L','M','N','O','P',
                        'Q','R','S','T','U','V','W','X','Y','Z' };
  std::cout<<"\n"<<std::endl;
  for(unsigned long i = 0; i < N; i++) {
    string resultstring = "";
    for (int j = 0; j < stringlenght; j++){
        resultstring = resultstring + alphabet[rand() % MAX];
    }
  stacklist.Push(resultstring);
  std::cout<< "<-"<< resultstring <<" ";

  }
  OperazioniStackList(stacklist);
}

void StackList(){
  char scelta;
  std::cout << "Scegli il tipo di dati da gestire: "<< std::endl;
  std::cout<<"(1->Interi; 2->Float; 3->Stringhe; q->Torna indietro)"<< std::endl;
  std::cin >>scelta;

  switch(scelta){
      case '1':
        std::cout << "\033[2J\033[1;1H";
        StackListInt();
        break;

      case '2':
        std::cout << "\033[2J\033[1;1H";
        StackListFloat();
        break;
      case '3':
        std::cout << "\033[2J\033[1;1H";
        StackListString();
        break;
      case 'q':
          std::cout << "\033[2J\033[1;1H";
          Stack();
          break;

      default:
        std::cout << "\033[2J\033[1;1H";
        std::cout<< "Scelta errata. Riprova. \n\n " <<std::endl;
        StackList();
  }

}
