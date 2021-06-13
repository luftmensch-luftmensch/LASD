#include "../../../container/container.hpp"
#include "../../../matrix/vec/matrixvec.hpp"
#include "../../../matrix/matrix.hpp"
#include "../../../vector/vector.hpp"

#include "../../container/container.hpp"
#include "../matrixvec.hpp"
#include "../../test.hpp"

#include "matrixvecint.hpp"

#include <random>
#include <string>
#include <bits/stdc++.h>
#include <iostream>

using namespace std;

template <typename Data>
void OperazioniMatrixVecInt(lasd::MatrixVec<Data>& matrix){
char scelta;
Data elem;
std::cout << "\nScegli l'operazione che vuoi effettuare: \n "<< std::endl;
std::cout<<"1->Visualizzazione in PreOrder \n2->Visualizzazione in PostOrder \n3->Ridimensionamento righe \n4->Ridimensionamento colonne"<< std::endl;
std::cout <<"\n5->Test di vuotezza \n6->Lettura della dimensione \n7->Svuotamento \n8->Controllo di esistenza di un valore \n9->Accesso ad una cella"<< std::endl;
std::cout << "\nA->Prodotto degli interi minori di K \nB->Applicazione della funzione 2N agli elementi \nq->Torna indietro"<<std::endl;

std::cin >>scelta;

switch(scelta){

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
      OperazioniMatrixVecInt(matrix);
      break;
    }
    case 'B':
      std::cout << "\033[2J\033[1;1H";
      cout<<"***APPLICAZIONE DELLA FUNZIONE 2N***\n"<<endl;
      matrix.MapPreOrder(&MapDoubleNPrint<int>, 0);
      OperazioniMatrixVecInt(matrix);
      break;

    case 'q':
        std::cout << "\033[2J\033[1;1H";
        MatrixVec();
        break;

    default:
      std::cout << "\033[2J\033[1;1H";
      std::cout<< "Scelta errata. Riprova. \n\n " <<std::endl;
      OperazioniMatrixVecInt(matrix);
  }
}



void MatrixVecInt(){
  unsigned long rows;
  unsigned long columns;

  std::cout << "Scegli il numero di righe della matrice: " << std::endl;
  std::cin >> rows;
  std::cout << "Scegli il numero di colonne della matrice: " << std::endl;
  std::cin >> columns;

  default_random_engine gen(random_device{}());
  uniform_int_distribution<unsigned int> dist(1, 100);

  lasd::MatrixVec<int> matrix(rows,columns);
  std::cout<<"\n"<<std::endl;

  for(unsigned long i = 0; i < matrix.RowNumber(); i++) {
    for(unsigned long j = 0; j < matrix.ColumnNumber();j++){
      matrix(i,j)=dist(gen);
      std::cout<<"Indici ("<< i <<"," << j <<"): "<<matrix(i,j)<<"\n"<<std::endl;
    }
  }

  OperazioniMatrixVecInt(matrix);
}
