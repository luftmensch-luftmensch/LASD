#include "../../../container/container.hpp"
#include "../../../queue/vec/queuevec.hpp"
#include "queuevec.hpp"
#include "../queue.hpp"
#include "../../test.hpp"

#include <iostream>
#include <string>
#include <bits/stdc++.h>
#include <iostream>

using namespace std;


template <typename Data>
void OperazioniQueueVec(lasd::QueueVec<Data>& queuevec){
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
      queuevec.Enqueue(elem);
      OperazioniQueueVec(queuevec);
      break;
    case '2':
      std::cout << "\033[2J\033[1;1H";
      queuevec.Dequeue();
      OperazioniQueueVec(queuevec);
      break;
    case '3':
      std::cout << "\033[2J\033[1;1H";
      elem=queuevec.HeadNDequeue();
      cout<<"\n"<< elem <<endl;
      OperazioniQueueVec(queuevec);
      break;
    case '4':
      std::cout << "\033[2J\033[1;1H";
      elem=queuevec.Head();
      cout<<"\n"<< elem <<endl;
      OperazioniQueueVec(queuevec);
      break;
    case '5':
      std::cout << "\033[2J\033[1;1H";
      if(queuevec.Empty()){
        cout<<"\n"<< "La Queue e' vuota"<<endl;
      }
      else{
        cout<<"\n"<< "La Queue non e' vuota"<<endl;
      }
      OperazioniQueueVec(queuevec);
      break;
    case '6':
      std::cout << "\033[2J\033[1;1H";
      elem=queuevec.Size();
      cout<<"\n"<<"La dimensione attuale della Queue e': "<<elem<<endl;
      OperazioniQueueVec(queuevec);
      break;
    case '7':
      std::cout << "\033[2J\033[1;1H";
      if(queuevec.Empty()){
        cout<<"\n"<< "Attualmente la Queue e' vuota"<<endl;
      }
      else{
        cout<<"\n"<< "Attualmente la Queue non e' vuota";
      }
      queuevec.Clear();
      if(queuevec.Empty()){
        cout<<"------>"<< "La Queue e' stato svuotata"<<endl;
      }

      OperazioniQueueVec(queuevec);
      break;
    case 'q':
        std::cout << "\033[2J\033[1;1H";
        Queue();
        break;

    default:
      std::cout << "\033[2J\033[1;1H";
      std::cout<< "Scelta errata. Riprova. \n\n " <<std::endl;
      OperazioniQueueVec(queuevec);
  }
}

void QueueVecInt(){
  unsigned long N;
  std::cout << "Scegli il numero di elementi da inserire nella struttura (N)" << std::endl;
  std::cin >> N;

  default_random_engine gen(random_device{}());
  uniform_int_distribution<unsigned int> dist(1, 100);

  lasd::QueueVec<int> queuevec;
  std::cout<<"\n"<<std::endl;
  for(unsigned long i = 0; i < N; i++) {
    int elem=dist(gen);
    queuevec.Enqueue(elem);
    std::cout<< "  "<< elem <<"  "<<std::endl;
  }
  OperazioniQueueVec(queuevec);
}


void QueueVecFloat(){
  unsigned long N;
  std::cout << "Scegli il numero di elementi da inserire nella struttura (N)" << std::endl;
  std::cin >> N;

  default_random_engine gen(random_device{}());
  uniform_real_distribution<float> dist(1.0, 100.0);

  lasd::QueueVec<float> queuevec;
  std::cout<<"\n"<<std::endl;
  for(unsigned long i = 0; i < N; i++) {
    float elem=dist(gen);
    queuevec.Enqueue(elem);
    std::cout<< "  "<< elem <<"  "<<std::endl;
  }
    OperazioniQueueVec(queuevec);
}
void QueueVecString(){
  srand(time(NULL));
  unsigned long N;
  int stringlenght = 5;
  const int MAX = 52;
  lasd::QueueVec<string> queuevec;
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
  queuevec.Enqueue(resultstring);
  std::cout<< "  "<< resultstring <<"  "<<std::endl;

  }
  OperazioniQueueVec(queuevec);
}

void QueueVec(){
  char scelta;
  std::cout << "Scegli il tipo di dati da gestire: "<< std::endl;
  std::cout<<"(1->Interi; 2->Float; 3->Stringhe; q->Torna indietro)"<< std::endl;
  std::cin >>scelta;

  switch(scelta){
      case '1':
        std::cout << "\033[2J\033[1;1H";
        QueueVecInt();
        break;

      case '2':
        std::cout << "\033[2J\033[1;1H";
        QueueVecFloat();
        break;
      case '3':
        std::cout << "\033[2J\033[1;1H";
        QueueVecString();
        break;
      case 'q':
          std::cout << "\033[2J\033[1;1H";
          Queue();
          break;

      default:
        std::cout << "\033[2J\033[1;1H";
        std::cout<< "Scelta errata. Riprova. \n\n " <<std::endl;
        QueueVec();
  }

}
