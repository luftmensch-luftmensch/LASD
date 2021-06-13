#include "../../../container/container.hpp"
#include "../../../matrix/csr/matrixcsr.hpp"
#include "../../../matrix/matrix.hpp"
#include "../../../vector/vector.hpp"

#include "../../container/container.hpp"
#include "../matrixcsr.hpp"
#include "../../test.hpp"

#include "matrixcsrint.hpp"

#include <random>
#include <string>
#include <bits/stdc++.h>
#include <iostream>

using namespace std;


template <typename Data>
void OperazioniMatrixCSRInt(lasd::MatrixCSR<Data>& matrix){
char scelta;
Data elem;
std::cout << "\nScegli l'operazione che vuoi effettuare: \n "<< std::endl;
std::cout<<"1->Visualizzazione in PreOrder \n2->Visualizzazione in PostOrder \n3->Ridimensionamento righe \n4->Ridimensionamento colonne"<< std::endl;
std::cout <<"\n5->Test di vuotezza \n6->Lettura della dimensione \n7->Svuotamento \n8->Controllo di esistenza di un valore \n9->Accesso ad una cella"<< std::endl;
std::cout << "\nA->Prodotto degli interi minori di K \nB->Applicazione della funzione 2N agli elementi \nq->Torna indietro"<<std::endl;

std::cin >>scelta;

switch(scelta){
    case '1':
      std::cout << "\033[2J\033[1;1H";
      cout<<"Visualizzazione in PreOrder: \n\n\n"<<endl;
      matrix.MapPreOrder(&MapPrint<int>, 0);
      OperazioniMatrixCSRInt(matrix);
      break;
    case '2':
      std::cout << "\033[2J\033[1;1H";
      cout<<"Visualizzazione in PostOrder: \n\n\n"<<endl;
      matrix.MapPostOrder(&MapPrint<int>, 0);
      OperazioniMatrixCSRInt(matrix);
      break;
    case '3':
      unsigned long rows;
      std::cout << "\033[2J\033[1;1H";
      cout<<"Scegli il nuovo numero di righe della matrice:\n"<<endl;
      matrix.RowResize(rows);
      OperazioniMatrixCSRInt(matrix);
      break;
    case '4':
      unsigned long col;
      std::cout << "\033[2J\033[1;1H";
      cout<<"Scegli il nuovo numero di colonne della matrice:\n"<<endl;
      matrix.ColumnResize(col);
      OperazioniMatrixCSRInt(matrix);
      break;
    case '5':
      std::cout << "\033[2J\033[1;1H";
      if(matrix.Empty()){
        cout<<"\n"<< "La matrice e' vuota"<<endl;
      }
      else{
        cout<<"\n"<< "La matrice non e' vuota"<<endl;
      }
      OperazioniMatrixCSRInt(matrix);
      break;
    case '6':
      std::cout << "\033[2J\033[1;1H";
      elem=matrix.Size();
      cout<<"\n"<<"La dimensione attuale della matrice  e': "<<elem<<endl;
      OperazioniMatrixCSRInt(matrix);
      break;
    case '7':
      std::cout << "\033[2J\033[1;1H";
      if(matrix.Empty()){
        cout<<"\n"<< "Attualmente la matrice e' vuota"<<endl;
      }
      else{
        cout<<"\n"<< "Attualmente la matrice non e' vuota";
      }
      matrix.Clear();
      if(matrix.Empty()){
        cout<<"------>"<< "La matrice e' stata svuotata"<<endl;
      }
      OperazioniMatrixCSRInt(matrix);
      break;
    case '8':{
      std::cout << "\033[2J\033[1;1H";
      cout<<"Inserisci il valore da cercare: \n"<<endl;
      cin >> elem;
      bool trovato=false;
      for(unsigned long i=0;i<matrix.RowNumber();i++){
        for(unsigned long j=0;j<matrix.ColumnNumber();j++){
          if(elem==matrix(i,j)){
            trovato=true;
          }
        }
      }

      if(trovato==true){
        cout<<"Il valore scelto e' presente " <<endl;
      }
      else{
        cout<<"La valore scelto non e' presente"<<endl;
      }
      OperazioniMatrixCSRInt(matrix);
      break;
    }
    case '9':
      unsigned long row,column;
      char choice;
      std::cout << "\033[2J\033[1;1H";
      cout<<"Inserisci il valore di riga della cella da esaminare: \n"<<endl;
      cin>>row;
      cout<<"Inserisci il valore di colonna della cella da esaminare: \n"<<endl;
      cin>>column;
      cout<<"Scegli l'operazione da effettuare sulla cella ("<<row<<","<<column<<"):\n"<<endl;
      std::cout<<"1->Controllo di esistenza \n2->Lettura \n3->Inserimento \nb->Torna indietro"<< std::endl;
      cin>>choice;
      switch(choice){
        case '1':
          if(matrix.ExistsCell(row,column)){
            cout<<"La cella scelta e' presente " <<endl;
          }
          else{
            cout<<"La cella scelta non e' presente " <<endl;
          }
        OperazioniMatrixCSRInt(matrix);
        break;
        case '2':
          cout<<"La cella scelta di indice "<<row<<" e di colonna "<<column<<" e' "<<matrix(row,column) <<endl;
          OperazioniMatrixCSRInt(matrix);
          break;
        case '3':
          cout<<"Inserisci il valore che vuoi abbia la cella:" <<endl;
          cin>>elem;
          matrix(row,column)=elem;
          OperazioniMatrixCSRInt(matrix);
          break;
        case 'b':
          std::cout << "\033[2J\033[1;1H";
          OperazioniMatrixCSRInt(matrix);
          break;
        default:
          std::cout << "\033[2J\033[1;1H";
          std::cout<< "Scelta errata. Riprova. \n\n " <<std::endl;
          OperazioniMatrixCSRInt(matrix);
      }
      OperazioniMatrixCSRInt(matrix);
      break;
    case 'A': {
      std::cout << "\033[2J\033[1;1H";
      cout<<"***PRODOTTO DEGLI INTERI MINORI DI K***\n"<<endl;
      cout<<"Inserisci K\n"<<endl;
      int k;
      cin >>k;
      int prod=1;

      matrix.FoldPreOrder([](const int& dat, const void* k, void* prod)
    	      {
              if (dat < *((int*)k))
                {
                  *((int*)prod) *= dat;
              }
          }, &k, &prod);
          if (prod!=1){
            std::cout << "Il prodotto e' "<<prod<<endl;
          }
          else{
            std::cout << "Non vi sono elementi con valore minore di quello scelto" << std::endl;
          }
      matrix.MapPreOrder(&MapPrint<int>,0);
      OperazioniMatrixCSRInt(matrix);
      break;
    }
    case 'B':
      std::cout << "\033[2J\033[1;1H";
      cout<<"***APPLICAZIONE DELLA FUNZIONE 2N***\n"<<endl;
      matrix.MapPreOrder(&MapDoubleNPrint<int>, 0);
      OperazioniMatrixCSRInt(matrix);
      break;

    case 'q':
        std::cout << "\033[2J\033[1;1H";
        MatrixCSR();
        break;

    default:
      std::cout << "\033[2J\033[1;1H";
      std::cout<< "Scelta errata. Riprova. \n\n " <<std::endl;
      OperazioniMatrixCSRInt(matrix);
  }
}



void MatrixCSRInt(){
  unsigned long rows;
  unsigned long columns;

  std::cout << "Scegli il numero di righe della matrice: " << std::endl;
  std::cin >> rows;
  std::cout << "Scegli il numero di colonne della matrice: " << std::endl;
  std::cin >> columns;

  default_random_engine gen(random_device{}());
  uniform_int_distribution<unsigned int> dist(1, 100);

  lasd::MatrixCSR<int> matrix(rows,columns);
  std::cout<<"\n"<<std::endl;

  for(unsigned long i = 0; i < matrix.RowNumber(); i++) {
    for(unsigned long j = 0; j < matrix.ColumnNumber();j++){
      matrix(i,j)=dist(gen);
      std::cout<<"Indici ("<< i <<"," << j <<"): "<<matrix(i,j)<<"\n"<<std::endl;
    }
  }

  OperazioniMatrixCSRInt(matrix);
}
