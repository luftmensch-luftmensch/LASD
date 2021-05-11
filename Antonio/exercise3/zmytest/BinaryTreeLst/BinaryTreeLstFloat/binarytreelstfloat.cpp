#include "../../../container/container.hpp"
#include "../../../binarytree/lnk/binarytreelnk.hpp"
#include "../../../binarytree/binarytree.hpp"
#include "../../../vector/vector.hpp"

#include "../../container/container.hpp"
#include "../binarytreelst.hpp"
#include "../../test.hpp"

#include "binarytreelstfloat.hpp"

#include <random>
#include <string>
#include <bits/stdc++.h>
#include <iostream>

using namespace std;

template <typename Data>
void OperazioniBinaryTreeLstFloat(lasd::BinaryTreeLnk<Data>& btlstfloat, unsigned long N){
char scelta;
Data elem;
std::cout << "\nScegli l'operazione che vuoi effettuare \n "<< std::endl;
std::cout<<"1->Visualizzazione in PreOrder \n2->Visualizzazione in PostOrder \n3->Visualizzazione in InOrder \n4->Visualizzazione in Ampiezza"<< std::endl;
std::cout <<"\n5->Test di vuotezza \n6->Lettura della dimensione \n7->Svuotamento \n8->Controllo di esistenza di un valore "<< std::endl;
std::cout <<"\n9->Interrogazione di un elemento \nA->Navigazione in PreOrder \nB->Navigazione in PostOrder \nC->Navigazione in InOrder"<<std::endl;
std::cout << "\nD->Navigazione in Ampiezza \nE->Somma dei float maggiori di K \nF->Applicazione della funzione N^3 agli elementi \nq->Torna indietro"<<std::endl;

std::cin >>scelta;

switch(scelta){
    case '1':
      std::cout << "\033[2J\033[1;1H";
      cout<<"Visualizzazione in PreOrder: \n\n\n"<<endl;
      MapPreOrder(btlstfloat,&MapPrint<float>, 0);
      OperazioniBinaryTreeLstFloat(btlstfloat,N);
      break;
    case '2':
      std::cout << "\033[2J\033[1;1H";
      cout<<"Visualizzazione in PostOrder: \n\n\n"<<endl;
      MapPostOrder(btlstfloat,&MapPrint<float>, 0);
      OperazioniBinaryTreeLstFloat(btlstfloat,N);
      break;
    case '3':
      std::cout << "\033[2J\033[1;1H";
      cout<<"Visualizzazione in InOrder: \n\n\n"<<endl;
      MapInOrder(btlstfloat,&MapPrint<float>, 0);
      OperazioniBinaryTreeLstFloat(btlstfloat,N);
      break;
    case '4':
      std::cout << "\033[2J\033[1;1H";
      cout<<"Visualizzazione in Ampiezza: \n\n\n"<<endl;
      MapBreadth(btlstfloat,&MapPrint<float>,0);
      OperazioniBinaryTreeLstFloat(btlstfloat,N);
      break;
    case '5':
      std::cout << "\033[2J\033[1;1H";
      if(btlstfloat.Empty()){
        cout<<"\n"<< "L'albero e' vuoto"<<endl;
      }
      else{
        cout<<"\n"<< "L'albero non e' vuoto"<<endl;
      }
      OperazioniBinaryTreeLstFloat(btlstfloat,N);
      break;
    case '6':
      std::cout << "\033[2J\033[1;1H";
      elem=btlstfloat.Size();
      cout<<"\n"<<"La dimensione attuale dell'albero  e': "<<elem<<endl;
      OperazioniBinaryTreeLstFloat(btlstfloat,N);
      break;
    case '7':
      std::cout << "\033[2J\033[1;1H";
      if(btlstfloat.Empty()){
        cout<<"\n"<< "Attualmente l'albero e' vuoto"<<endl;
      }
      else{
        cout<<"\n"<< "Attualmente l'albero non e' vuoto";
      }
      btlstfloat.Clear();
      if(btlstfloat.Empty()){
        cout<<"------>"<< "L'albero e' stato svuotato"<<endl;
      }

      OperazioniBinaryTreeLstFloat(btlstfloat,N);
      break;
      case '8': {
        std::cout << "\033[2J\033[1;1H";
        MapPreOrder(btlstfloat,&MapPrint<float>,0);

        cout<<"\nInserisci il valore da ricercare: \n"<<elem<<endl;
        cin >> elem;

        lasd::BTBreadthIterator<Data> itr(btlstfloat);

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


        OperazioniBinaryTreeLstFloat(btlstfloat,N);
        break;
      }
    case '9': {
        std::cout << "\033[2J\033[1;1H";

        lasd::BinaryTree<float>* btlstfloat1=&btlstfloat;
        bool boolean=true;
        typename lasd::BinaryTree<Data>::Node* current = &btlstfloat1->Root();
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
              OperazioniBinaryTreeLstFloat(btlstfloat,N);
              boolean=false;
              break;
            default:
              std::cout << "\033[2J\033[1;1H";
              std::cout<< "Scelta errata. Riprova. \n\n " <<std::endl;
              OperazioniBinaryTreeLstFloat(btlstfloat,N);
            }
        }


        OperazioniBinaryTreeLstFloat(btlstfloat,N);
        break;
    }

    case 'A':{
       cout<<"Navigazione in PreOrder:"<<endl;

       lasd::BTPreOrderIterator<Data> itr(btlstfloat);
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

         OperazioniBinaryTreeLstFloat(btlstfloat,N);
       }
       break;
   }
   case 'B':{
      cout<<"Navigazione in PostOrder:"<<endl;

      lasd::BTPostOrderIterator<Data> itr(btlstfloat);
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

        OperazioniBinaryTreeLstFloat(btlstfloat,N);
      }
      break;
  }
  case 'C':{
     cout<<"Navigazione in InOrder:"<<endl;

     lasd::BTInOrderIterator<Data> itr(btlstfloat);
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

       OperazioniBinaryTreeLstFloat(btlstfloat,N);
     }
     break;
 }
 case 'D':{
    cout<<"Navigazione in Ampiezza:"<<endl;

    lasd::BTBreadthIterator<Data> itr(btlstfloat);
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

      OperazioniBinaryTreeLstFloat(btlstfloat,N);
    }
    break;
}
  case 'E':{
    lasd::BTBreadthIterator<float> itr(btlstfloat);
    cout<<"***SOMMA DEI FLOAT MAGGIORI DI K***\n"<<endl;
    cout<<"Inserisci K\n"<<endl;
    float k;
    cin >>k;
    float prod=1;
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
    OperazioniBinaryTreeLstFloat(btlstfloat,N);
    break;

  }
  case 'F':{
    cout<<"***APPLICAZIONE DELLA FUNZIONE N^3 AI FLOAT***\n"<<endl;
    cout<<"\n\n"<<endl;
    MapPreOrder(btlstfloat,&MapPrint<float>,0);
    MapPreOrder(btlstfloat,&MapNxNxN<float>,0);
    cout<<"\n\n"<<endl;
    MapPreOrder(btlstfloat,&MapPrint<float>,0);

    OperazioniBinaryTreeLstFloat(btlstfloat,N);
    break;

  }
    case 'q':
        std::cout << "\033[2J\033[1;1H";
        mytest();
        break;

    default:
      std::cout << "\033[2J\033[1;1H";
      std::cout<< "Scelta errata. Riprova. \n\n " <<std::endl;
      OperazioniBinaryTreeLstFloat(btlstfloat,N);
  }
}
/* ----------------------------------------------------------------------------*/
void BinaryTreeLstFloat(){
  unsigned long N;
  std::cout << "Scegli il numero di elementi da inserire nella struttura (N)" << std::endl;
  std::cin >> N;

  default_random_engine gen(random_device{}());
  uniform_real_distribution<float> dist(1.0, 100.0);

  lasd::Vector<float> vectorfloat(N);
  std::cout<<"\n"<<std::endl;
  for(unsigned long i = 0; i < N; i++) {
    vectorfloat[i]=dist(gen);
    std::cout<<"Indice "<< i <<": "<<vectorfloat[i]<<"\n"<<std::endl;
  }
  lasd::BinaryTreeLnk<float> btlstfloat(vectorfloat);

  OperazioniBinaryTreeLstFloat(btlstfloat,N);

}
