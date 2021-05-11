#include "../../../container/container.hpp"
#include "../../../binarytree/vec/binarytreevec.hpp"
#include "../../../binarytree/binarytree.hpp"
#include "../../../vector/vector.hpp"

#include "../../container/container.hpp"
#include "../binarytreevec.hpp"
#include "../../test.hpp"

#include "binarytreevecint.hpp"

#include <random>
#include <string>
#include <bits/stdc++.h>
#include <iostream>

using namespace std;

/* -------------------------------------------------------------------------- */
template <typename Data>
void OperazioniBinaryTreeVecInt(lasd::BinaryTreeVec<Data>& btvec, unsigned long N){
char scelta;
Data elem;
std::cout << "\nScegli l'operazione che vuoi effettuare \n "<< std::endl;
std::cout<<"1->Visualizzazione in PreOrder \n2->Visualizzazione in PostOrder \n3->Visualizzazione in InOrder \n4->Visualizzazione in Ampiezza"<< std::endl;
std::cout <<"\n5->Test di vuotezza \n6->Lettura della dimensione \n7->Svuotamento \n8->Controllo di esistenza di un valore "<< std::endl;
std::cout <<"\n9->Interrogazione di un elemento \nA->Navigazione in PreOrder \nB->Navigazione in PostOrder \nC->Navigazione in InOrder"<<std::endl;
std::cout << "\nD->Navigazione in Ampiezza \nE->Prodotto degli interi minori di K \nF->Applicazione della funzione 3N agli elementi \nq->Torna indietro"<<std::endl;

std::cin >>scelta;

switch(scelta){
    case '1':
      std::cout << "\033[2J\033[1;1H";
      cout<<"Visualizzazione in PreOrder: \n\n\n"<<endl;
      MapPreOrder(btvec,&MapPrint<int>, 0);
      OperazioniBinaryTreeVecInt(btvec,N);
      break;
    case '2':
      std::cout << "\033[2J\033[1;1H";
      cout<<"Visualizzazione in PostOrder: \n\n\n"<<endl;
      MapPostOrder(btvec,&MapPrint<int>, 0);
      OperazioniBinaryTreeVecInt(btvec,N);
      break;
    case '3':
      std::cout << "\033[2J\033[1;1H";
      cout<<"Visualizzazione in InOrder: \n\n\n"<<endl;
      MapInOrder(btvec,&MapPrint<int>, 0);
      OperazioniBinaryTreeVecInt(btvec,N);
      break;
    case '4':
      std::cout << "\033[2J\033[1;1H";
      cout<<"Visualizzazione in Ampiezza: \n\n\n"<<endl;
      MapBreadth(btvec,&MapPrint<int>,0);
      OperazioniBinaryTreeVecInt(btvec,N);
      break;
    case '5':
      std::cout << "\033[2J\033[1;1H";
      if(btvec.Empty()){
        cout<<"\n"<< "L'albero e' vuoto"<<endl;
      }
      else{
        cout<<"\n"<< "L'albero non e' vuoto"<<endl;
      }
      OperazioniBinaryTreeVecInt(btvec,N);
      break;
    case '6':
      std::cout << "\033[2J\033[1;1H";
      elem=btvec.Size();
      cout<<"\n"<<"La dimensione attuale dell'albero  e': "<<elem<<endl;
      OperazioniBinaryTreeVecInt(btvec,N);
      break;
    case '7':
      std::cout << "\033[2J\033[1;1H";
      if(btvec.Empty()){
        cout<<"\n"<< "Attualmente l'albero e' vuoto"<<endl;
      }
      else{
        cout<<"\n"<< "Attualmente l'albero non e' vuoto";
      }
      btvec.Clear();
      if(btvec.Empty()){
        cout<<"------>"<< "L'albero e' stato svuotato"<<endl;
      }

      OperazioniBinaryTreeVecInt(btvec,N);
      break;
      case '8': {
        std::cout << "\033[2J\033[1;1H";
        MapPreOrder(btvec,&MapPrint<int>,0);

        cout<<"\nInserisci il valore da ricercare: \n"<<elem<<endl;
        cin >> elem;

        lasd::BTBreadthIterator<Data> itr(btvec);

        bool boolean=false;
        int i=0;
        while(i<N&&boolean==false){
          if(*itr==elem){
            boolean=true;
          }
          else{
            ++itr;
            i++;
          }
        }

        if(boolean==true){
          cout<<"\nElemento trovato!"<<endl;
        }
        else{
          cout<<"\nElemento non trovato!"<<endl;
        }


        OperazioniBinaryTreeVecInt(btvec,N);
        break;
      }
    case '9': {
        std::cout << "\033[2J\033[1;1H";

        lasd::BinaryTree<int>* btvec1=&btvec;
        bool boolean=true;
        typename lasd::BinaryTree<Data>::Node* current = &btvec1->Root();
        while(current!=nullptr&&boolean==true){
          cout<<"L'elemento corrente e' : "<<current->Element()<<endl;
          cout<<"\n Cosa vuoi fare? "<<endl;
          cout<<"\n 1->Modifica il valore corrente \n 2->Visita il figlio sinistro (se presente) \n 3->Visita il figlio destro (se presente)\n"<<endl;

          char choice;
          cin >>choice;
          switch(choice){
            case '1':
              cout<<"\nInserisci il valore che vuoi abbia il nodo corrente \n"<<endl;
              Data value;
              cin>>value;
              current->Element()=value;

              break;
            case '2':
              if(current->HasLeftChild()){
                current=&current->LeftChild();
                cout<<"\nIl figlio sinistro e': "<<current<<endl;
              }
              else{
                cout<<"\nIl nodo corrente non ha figlio sinistro\n"<<endl;
              }
              break;

            case '3':
              if(current->HasRightChild()){
                current=&current->RightChild();
                cout<<"\nIl figlio destro e': "<<current<<endl;
              }
              else{
                cout<<"\nIl nodo corrente non ha figlio destro\n"<<endl;
              }
              break;
            case 'b':
              std::cout << "\033[2J\033[1;1H";
              OperazioniBinaryTreeVecInt(btvec,N);
              boolean=false;
              break;
            default:
              std::cout << "\033[2J\033[1;1H";
              std::cout<< "Scelta errata. Riprova. \n\n " <<std::endl;
              OperazioniBinaryTreeVecInt(btvec,N);
            }
        }


        OperazioniBinaryTreeVecInt(btvec,N);
        break;
    }

    case 'A':{
       cout<<"Navigazione in PreOrder:"<<endl;

       lasd::BTPreOrderIterator<Data> itr(btvec);
       int i=0;
       char q;
       while(i<N){
         cout<<"\nL'elemento corrente e' : "<<*itr<<endl;
         cout<<"\nPremi q per continuare la navigazione\n"<<endl;
         cin>>q;
         ++itr;
         i++;
       }
       if(i==N){
         cout<<"Navigazione completata!\n\n"<<endl;

         OperazioniBinaryTreeVecInt(btvec,N);
       }
       break;
   }
   case 'B':{
      cout<<"Navigazione in PostOrder:"<<endl;

      lasd::BTPostOrderIterator<Data> itr(btvec);
      int i=0;
      char q;
      while(i<N){
        cout<<"\nL'elemento corrente e' : "<<*itr<<endl;
        cout<<"\nPremi q per continuare la navigazione\n"<<endl;
        cin>>q;
        ++itr;
        i++;
      }
      if(i==N){
        cout<<"Navigazione completata!\n\n"<<endl;

        OperazioniBinaryTreeVecInt(btvec,N);
      }
      break;
  }
  case 'C':{
     cout<<"Navigazione in InOrder:"<<endl;

     lasd::BTInOrderIterator<Data> itr(btvec);
     int i=0;
     char q;
     while(i<N){
       cout<<"\nL'elemento corrente e' : "<<*itr<<endl;
       cout<<"\nPremi q per continuare la navigazione\n"<<endl;
       cin>>q;
       ++itr;
       i++;
     }
     if(i==N){
       cout<<"Navigazione completata!\n\n"<<endl;

       OperazioniBinaryTreeVecInt(btvec,N);
     }
     break;
 }
 case 'D':{
    cout<<"Navigazione in Ampiezza:"<<endl;

    lasd::BTBreadthIterator<Data> itr(btvec);
    int i=0;
    char q;
    while(i<N){
      cout<<"\nL'elemento corrente e' : "<<*itr<<endl;
      cout<<"\nPremi q per continuare la navigazione\n"<<endl;
      cin>>q;
      ++itr;
      i++;
    }
    if(i==N){
      cout<<"Navigazione completata!\n\n"<<endl;

      OperazioniBinaryTreeVecInt(btvec,N);
    }
    break;
}
  case 'E':{
    lasd::BTBreadthIterator<int> itr(btvec);
    cout<<"***PRODOTTO DEGLI INTERI MINORI DI K***\n"<<endl;
    cout<<"Inserisci K\n"<<endl;
    int k;
    cin >>k;
    int prod=1;
    int i=0;
    while(i<N){
      if(*itr <k){

        prod=(*itr)*prod;
      }
      ++itr;
      i++;
    }
    if(prod==1){
      cout<<"Non ci sono elementi minori di K"<<endl;

    }
    else{
      cout<<"Il prodotto degli elementi minori di K e': "<<prod<<endl;
    }
    OperazioniBinaryTreeVecInt(btvec,N);
    break;

  }
  case 'F':{
    cout<<"***APPLICAZIONE DELLA FUNZIONE 3N AGLI INTERI***\n"<<endl;
    cout<<"\n\n"<<endl;
    MapPreOrder(btvec,&MapPrint<int>,0);
    MapPreOrder(btvec,&MapTriple<int>,0);
    cout<<"\n\n"<<endl;
    MapPreOrder(btvec,&MapPrint<int>,0);

    OperazioniBinaryTreeVecInt(btvec,N);
    break;

  }
    case 'q':
        std::cout << "\033[2J\033[1;1H";
        mytest();
        break;

    default:
      std::cout << "\033[2J\033[1;1H";
      std::cout<< "Scelta errata. Riprova. \n\n " <<std::endl;
      OperazioniBinaryTreeVecInt(btvec,N);
  }
}

/* *************************************************************************** */
void BinaryTreeVecInt(){
  unsigned long N;
  std::cout << "Scegli il numero di elementi da inserire nella struttura (N)" << std::endl;
  std::cin >> N;

  default_random_engine gen(random_device{}());
  uniform_int_distribution<unsigned int> dist(1, 100);

  lasd::Vector<int> vector(N);
  std::cout<<"\n"<<std::endl;
  for(unsigned long i = 0; i < N; i++) {
    vector[i]=dist(gen);
    std::cout<<"Indice "<< i <<": "<<vector[i]<<"\n"<<std::endl;
  }
  lasd::BinaryTreeVec<int> btvec(vector);

  OperazioniBinaryTreeVecInt(btvec,N);
}
