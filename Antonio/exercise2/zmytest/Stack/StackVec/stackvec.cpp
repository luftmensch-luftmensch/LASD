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


template <typename Data>
void OperazioniStackVec(lasd::StackVec<Data>& stackvec){
char scelta;
Data elem;
std::cout << "Scegli l'operazione che vuoi effettuare \n "<< std::endl;
std::cout<<"1->Inserimento \n2->Rimozione \n3->Rimozione con lettura \n4->Lettura non distruttiva"<< std::endl;
std::cout <<"5->Test di vuotezza \n6->Lettura della dimensione \n7->Svuotamento \nq->Torna indietro "<< std::endl;

std::cin >>scelta;

switch(scelta){
    case '1':
      std::cout << "\033[2J\033[1;1H";
      cout<<"Scegli l'elemento da inserire: \n"<<endl;
      cin>> elem;
      stackvec.Push(elem);
      OperazioniStackVec(stackvec);
      break;
    case '2':
      std::cout << "\033[2J\033[1;1H";
      stackvec.Pop();
      OperazioniStackVec(stackvec);
      break;
    case '3':
      std::cout << "\033[2J\033[1;1H";
      elem=stackvec.TopNPop();
      cout<<"\n"<< elem <<endl;
      OperazioniStackVec(stackvec);
      break;
    case '4':
      std::cout << "\033[2J\033[1;1H";
      elem=stackvec.Top();
      cout<<"\n"<< elem <<endl;
      OperazioniStackVec(stackvec);
      break;
    case '5':
      std::cout << "\033[2J\033[1;1H";
      if(stackvec.Empty()){
        cout<<"\n"<< "Lo Stack e' vuoto"<<endl;
      }
      else{
        cout<<"\n"<< "Lo Stack non e' vuoto"<<endl;
      }
      OperazioniStackVec(stackvec);
      break;
    case '6':
      std::cout << "\033[2J\033[1;1H";
      elem=stackvec.Size();
      cout<<"\n"<<"La dimensione attuale dello Stack e': "<<elem<<endl;
      OperazioniStackVec(stackvec);
      break;
    case '7':
      std::cout << "\033[2J\033[1;1H";
      if(stackvec.Empty()){
        cout<<"\n"<< "Attualmente lo Stack e' vuoto"<<endl;
      }
      else{
        cout<<"\n"<< "Attualmente lo Stack non e' vuoto";
      }
      stackvec.Clear();
      if(stackvec.Empty()){
        cout<<"------>"<< "Lo Stack e' stato svuotato"<<endl;
      }

      OperazioniStackVec(stackvec);
      break;
    case 'q':
        std::cout << "\033[2J\033[1;1H";
        Stack();
        break;

    default:
      std::cout << "\033[2J\033[1;1H";
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
  unsigned long N;
  std::cout << "Scegli il numero di elementi da inserire nella struttura (N)" << std::endl;
  std::cin >> N;

  default_random_engine gen(random_device{}());
  uniform_real_distribution<float> dist(1.0, 100.0);

  lasd::StackVec<float> stackvec;
  std::cout<<"\n"<<std::endl;
  for(unsigned long i = 0; i < N; i++) {
    float elem=dist(gen);
    stackvec.Push(elem);
    std::cout<< "  "<< elem <<"  "<<std::endl;
  }
  OperazioniStackVec(stackvec);
}
void StackVecString(){
  srand(time(NULL));
  unsigned long N;
  int stringlenght = 5;
  const int MAX = 52;
  lasd::StackVec<string> stackvec;
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
  stackvec.Push(resultstring);
  std::cout<< "  "<< resultstring <<"  "<<std::endl;

  }
  OperazioniStackVec(stackvec);
}

void StackVec(){
  char scelta;
  std::cout << "Scegli il tipo di dati da gestire: "<< std::endl;
  std::cout<<"(1->Interi; 2->Float; 3->Stringhe; q->Torna indietro)"<< std::endl;
  std::cin >>scelta;

  switch(scelta){
      case '1':
        std::cout << "\033[2J\033[1;1H";
        StackVecInt();
        break;

      case '2':
        std::cout << "\033[2J\033[1;1H";
        StackVecFloat();
        break;
      case '3':
        std::cout << "\033[2J\033[1;1H";
        StackVecString();
        break;
      case 'q':
          std::cout << "\033[2J\033[1;1H";
          Stack();
          break;

      default:
        std::cout << "\033[2J\033[1;1H";
        std::cout<< "Scelta errata. Riprova. \n\n " <<std::endl;
        StackVec();
  }

}
