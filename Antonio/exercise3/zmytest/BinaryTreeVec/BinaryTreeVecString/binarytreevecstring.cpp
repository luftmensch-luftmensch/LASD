#include "../../../container/container.hpp"
#include "../../../binarytree/vec/binarytreevec.hpp"
#include "../../../binarytree/binarytree.hpp"
#include "../../../vector/vector.hpp"

#include "../../container/container.hpp"
#include "../binarytreevec.hpp"
#include "../../test.hpp"

#include <random>
#include <string>
#include <bits/stdc++.h>
#include <iostream>

#include "binarytreevecstring.hpp"

using namespace std;


/*-----------------------------------------------------------------------------*/
template <typename Data>
void OperazioniBinaryTreeVecString(lasd::BinaryTreeVec<Data>& btvecstring, unsigned long N){
char scelta;
Data elem;
Data value;
std::cout << "\nScegli l'operazione che vuoi effettuare \n "<< std::endl;
std::cout<<"1->Visualizzazione in PreOrder \n2->Visualizzazione in PostOrder \n3->Visualizzazione in InOrder \n4->Visualizzazione in Ampiezza"<< std::endl;
std::cout <<"\n5->Test di vuotezza \n6->Lettura della dimensione \n7->Svuotamento \n8->Controllo di esistenza di un valore "<< std::endl;
std::cout <<"\n9->Interrogazione di un elemento \nA->Navigazione in PreOrder \nB->Navigazione in PostOrder \nC->Navigazione in InOrder"<<std::endl;
std::cout << "\nD->Navigazione in Ampiezza \nE->Concatenazione delle stringhe di lunghezza <= K \nF->Concatenazione in testa alle stringhe contenute nella struttura q->Torna indietro"<<std::endl;

std::cin >>scelta;

switch(scelta){
    case '1':
      std::cout << "\033[2J\033[1;1H";
      cout<<"Visualizzazione in PreOrder: \n\n\n"<<endl;
      MapPreOrder(btvecstring,&MapPrint<string>, 0);
      OperazioniBinaryTreeVecString(btvecstring,N);
      break;
    case '2':
      std::cout << "\033[2J\033[1;1H";
      cout<<"Visualizzazione in PostOrder: \n\n\n"<<endl;
      MapPostOrder(btvecstring,&MapPrint<string>, 0);
      OperazioniBinaryTreeVecString(btvecstring,N);
      break;
    case '3':
      std::cout << "\033[2J\033[1;1H";
      cout<<"Visualizzazione in InOrder: \n\n\n"<<endl;
      MapInOrder(btvecstring,&MapPrint<string>, 0);
      OperazioniBinaryTreeVecString(btvecstring,N);
      break;
    case '4':
      std::cout << "\033[2J\033[1;1H";
      cout<<"Visualizzazione in Ampiezza: \n\n\n"<<endl;
      MapBreadth(btvecstring,&MapPrint<string>,0);
      OperazioniBinaryTreeVecString(btvecstring,N);
      break;
    case '5':
      std::cout << "\033[2J\033[1;1H";
      if(btvecstring.Empty()){
        cout<<"\n"<< "L'albero e' vuoto"<<endl;
      }
      else{
        cout<<"\n"<< "L'albero non e' vuoto"<<endl;
      }
      OperazioniBinaryTreeVecString(btvecstring,N);
      break;
    case '6':
      std::cout << "\033[2J\033[1;1H";
      elem=btvecstring.Size();
      cout<<"\n"<<"La dimensione attuale dell'albero  e': "<<elem<<endl;
      OperazioniBinaryTreeVecString(btvecstring,N);
      break;
    case '7':
      std::cout << "\033[2J\033[1;1H";
      if(btvecstring.Empty()){
        cout<<"\n"<< "Attualmente l'albero e' vuoto"<<endl;
      }
      else{
        cout<<"\n"<< "Attualmente l'albero non e' vuoto";
      }
      btvecstring.Clear();
      if(btvecstring.Empty()){
        cout<<"------>"<< "L'albero e' stato svuotato"<<endl;
      }

      OperazioniBinaryTreeVecString(btvecstring,N);
      break;
      case '8': {
        std::cout << "\033[2J\033[1;1H";
        MapPreOrder(btvecstring,&MapPrint<string>,0);

        cout<<"\nInserisci il valore da ricercare: \n"<<elem<<endl;
        cin >> elem;

        lasd::BTBreadthIterator<Data> itr(btvecstring);

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


        OperazioniBinaryTreeVecString(btvecstring,N);
        break;
      }
    case '9': {
        std::cout << "\033[2J\033[1;1H";

        lasd::BinaryTree<string>* btvecstring1=&btvecstring;
        bool boolean=true;
        typename lasd::BinaryTree<Data>::Node* current = &btvecstring1->Root();
        while(current!=nullptr&&boolean==true){
          cout<<"L'elemento corrente e' : "<<current->Element()<<endl;
          cout<<"\n Cosa vuoi fare? "<<endl;
          cout<<"\n 1->Modifica il valore corrente \n 2->Visita il figlio sinistro (se presente) \n 3->Visita il figlio destro (se presente)\n"<<endl;

          char choice;
          cin >>choice;
          switch(choice){
            case '1':
              cout<<"\nInserisci il valore che vuoi abbia il nodo corrente \n"<<endl;

              cin>>value;
              current->Element()=value;

              break;
            case '2': {
              if(current->HasLeftChild()){
                current=&current->LeftChild();
                cout<<"\nIl figlio sinistro e': "<<current<<endl;
              }
              else{
                cout<<"\nIl nodo corrente non ha figlio sinistro\n"<<endl;
              }
              break;
       }
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
              OperazioniBinaryTreeVecString(btvecstring,N);
              boolean=false;
              break;
            default:
              std::cout << "\033[2J\033[1;1H";
              std::cout<< "Scelta errata. Riprova. \n\n " <<std::endl;
              OperazioniBinaryTreeVecString(btvecstring,N);
            }
        }


        OperazioniBinaryTreeVecString(btvecstring,N);
        break;
    }

    case 'A':{
       cout<<"Navigazione in PreOrder:"<<endl;

       lasd::BTPreOrderIterator<Data> itr(btvecstring);
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

         OperazioniBinaryTreeVecString(btvecstring,N);
       }
       break;
   }
   case 'B':{
      cout<<"Navigazione in PostOrder:"<<endl;

      lasd::BTPostOrderIterator<Data> itr(btvecstring);
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

        OperazioniBinaryTreeVecString(btvecstring,N);
      }
      break;
  }
  case 'C':{
     cout<<"Navigazione in InOrder:"<<endl;

     lasd::BTInOrderIterator<Data> itr(btvecstring);
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

       OperazioniBinaryTreeVecString(btvecstring,N);
     }
     break;
 }
 case 'D':{
    cout<<"Navigazione in Ampiezza:"<<endl;

    lasd::BTBreadthIterator<Data> itr(btvecstring);
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

      OperazioniBinaryTreeVecString(btvecstring,N);
    }
    break;
}
  case 'E':{
    lasd::BTBreadthIterator<string> itr(btvecstring);
    cout<<"***CONCATENAZIONE DELLE STRINGHE CON LUNGHEZZA <= K (LE STRINGHE SONO DI LUNGHEZZA 5)***\n"<<endl;
    cout<<"Inserisci K\n"<<endl;
    int k;
    cin >>k;
    string res="";
    int i=0;
    while(i<N){
      if( 5 <= k){

        res=(*itr)+res;
      }
      ++itr;
      i++;
    }
    if(res==""){
      cout<<"Non ci sono elementi con lunghezza minore o uguale di K"<<endl;

    }
    else{
      cout<<"Il prodotto degli elementi minori di K e': "<<res<<endl;
    }
    OperazioniBinaryTreeVecString(btvecstring,N);
    break;

  }
  case 'F':{
    cout<<"***CONCATENAZIONE IN TESTA ALLE STRINGHE CONTENUTE NELLA STRUTTURA ***\n"<<endl;
    cout<<"\n\n"<<endl;
    cout<<")\nInserire una stringa di lunghezza 5: \n"<<endl;
    string toinsert;
    cin>>toinsert;
    lasd::BTBreadthIterator<string> itr(btvecstring);
    int i=0;
    while(i<N){
      (*itr)= toinsert+(*itr);
      ++itr;
      i++;
    }
    cout<<"\n"<<endl;
    MapPreOrder(btvecstring,&MapPrint<string>,0);
    OperazioniBinaryTreeVecString(btvecstring,N);
    break;

  }
    case 'q':
        std::cout << "\033[2J\033[1;1H";
        mytest();
        break;

    default:
      std::cout << "\033[2J\033[1;1H";
      std::cout<< "Scelta errata. Riprova. \n\n " <<std::endl;
      OperazioniBinaryTreeVecString(btvecstring,N);
  }
}
/* ----------------------------------------------------------------------------*/
void BinaryTreeVecString(){
  srand(time(NULL));
  unsigned long N;
  int stringlenght = 5;

  const int MAX = 52;
  std::cout << "Scegli il numero di elementi da inserire nella struttura (N)" << std::endl;
  std::cin >> N;

  lasd::Vector<string> vectorstring(N);
  std::cout<<"\n"<<std::endl;

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
    vectorstring[i]=resultstring;
    std::cout<< "  "<< resultstring <<"  "<<std::endl;
  }

  lasd::BinaryTreeVec<string> btvecstringstring(vectorstring);

  OperazioniBinaryTreeVecString(btvecstringstring,N);


}
