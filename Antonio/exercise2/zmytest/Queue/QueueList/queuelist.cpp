#include "../queue.hpp"
#include "../../test.hpp"
#include "../../../queue/lst/queuelst.hpp"
#include "queuelist.hpp"

#include <iostream>
#include <string>
#include <bits/stdc++.h>
#include <iostream>

using namespace std;

template <typename Data>
void OperazioniQueueList(lasd::QueueLst<Data>& queuelist){
char scelta;
Data elem;
std::cout << "\nScegli l'operazione che vuoi effettuare \n "<< std::endl;
std::cout<<"1->Inserimento \n2->Rimozione \n3->Rimozione con lettura \n4->Lettura non distruttiva"<< std::endl;
std::cout <<"5->Test di vuotezza \n6->Lettura della dimensione \n7->Svuotamento \nq->Torna indietro "<< std::endl;

std::cin >>scelta;

switch(scelta){
    case '1':
      cout << "\033[2J\033[1;1H";
      cout<<"Scegli l'elemento da inserire: \n"<<endl;
      cin>> elem;
      queuelist.Enqueue(elem);
      OperazioniQueueList(queuelist);
      break;
    case '2':
      cout << "\033[2J\033[1;1H";
      queuelist.Dequeue();
      OperazioniQueueList(queuelist);
      break;
    case '3':
      cout << "\033[2J\033[1;1H";
      elem=queuelist.HeadNDequeue();
      cout<<"\n"<< elem <<endl;
      OperazioniQueueList(queuelist);
      break;
    case '4':
      cout << "\033[2J\033[1;1H";
      elem=queuelist.Head();
      cout<<"\n"<< elem <<endl;
      OperazioniQueueList(queuelist);
      break;
    case '5':
      cout << "\033[2J\033[1;1H";
      if(queuelist.Empty()){
        cout<<"\n"<< "La Queue e' vuota"<<endl;
      }
      else{
        cout<<"\n"<< "La Queue non e' vuota"<<endl;
      }
      OperazioniQueueList(queuelist);
      break;
    case '6':
      cout << "\033[2J\033[1;1H";
      elem=queuelist.Size();
      cout<<"\n"<<"La dimensione attuale della Queue e': "<<elem<<endl;
      OperazioniQueueList(queuelist);
      break;
    case '7':
      cout << "\033[2J\033[1;1H";
      if(queuelist.Empty()){
        cout<<"\n"<< "Attualmente la Queue e' vuota"<<endl;
      }
      else{
        cout<<"\n"<< "Attualmente la Queue non e' vuota";
      }
      queuelist.Clear();
      if(queuelist.Empty()){
        cout<<"------>"<< "La Queue e' stato svuotata"<<endl;
      }

      OperazioniQueueList(queuelist);
      break;
    case 'q':
        std::cout << "\033[2J\033[1;1H";
        Queue();
        break;

    default:
      std::cout << "\033[2J\033[1;1H";
      std::cout<< "Scelta errata. Riprova. \n\n " <<std::endl;
      OperazioniQueueList(queuelist);
  }
}
void QueueListInt(){
  unsigned long N;
  std::cout << "Scegli il numero di elementi da inserire nella struttura (N)" << std::endl;
  std::cin >> N;

  default_random_engine gen(random_device{}());
  uniform_int_distribution<unsigned int> dist(1, 100);

  lasd::QueueLst<int> queuelist;
  std::cout<<"\n"<<std::endl;
  for(unsigned long i = 0; i < N; i++) {
    int elem=dist(gen);
    queuelist.Enqueue(elem);
    std::cout<< " "<< elem <<"->";
  }
  OperazioniQueueList(queuelist);
}


void QueueListFloat(){
  unsigned long N;
  std::cout << "Scegli il numero di elementi da inserire nella struttura (N)" << std::endl;
  std::cin >> N;

  default_random_engine gen(random_device{}());
  uniform_real_distribution<float> dist(1.0, 100.0);

  lasd::QueueLst<float> queuelist;
  std::cout<<"\n"<<std::endl;
  for(unsigned long i = 0; i < N; i++) {
    float elem=dist(gen);
    queuelist.Enqueue(elem);
    std::cout<< " "<< elem <<"->";
  }
  OperazioniQueueList(queuelist);
}


void QueueListString(){
  srand(time(NULL));
  unsigned long N;
  int stringlenght = 5;
  const int MAX = 52;
  lasd::QueueLst<string> queuelist;
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
  queuelist.Enqueue(resultstring);
  std::cout<< " "<< resultstring <<"->";

  }
  OperazioniQueueList(queuelist);
}

void QueueList(){
  char scelta;
  std::cout << "Scegli il tipo di dati da gestire: "<< std::endl;
  std::cout<<"(1->Interi; 2->Float; 3->Stringhe; q->Torna indietro)"<< std::endl;
  std::cin >>scelta;

  switch(scelta){
      case '1':
        std::cout << "\033[2J\033[1;1H";
        QueueListInt();
        break;

      case '2':
        std::cout << "\033[2J\033[1;1H";
        QueueListFloat();
        break;
      case '3':
        std::cout << "\033[2J\033[1;1H";
        QueueListString();
        break;
      case 'q':
          std::cout << "\033[2J\033[1;1H";
          Queue();
          break;

      default:
        std::cout << "\033[2J\033[1;1H";
        std::cout<< "Scelta errata. Riprova. \n\n " <<std::endl;
        QueueList();
  }

}
