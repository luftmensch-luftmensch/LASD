#include "../../../container/container.hpp"
#include "../../../matrix/csr/matrixcsr.hpp"
#include "../../../matrix/matrix.hpp"
#include "../../../vector/vector.hpp"

#include "../../container/container.hpp"
#include "../matrixcsr.hpp"
#include "../../test.hpp"

#include "matrixcsrstring.hpp"

#include <random>
#include <string>
#include <bits/stdc++.h>
#include <iostream>

using namespace std;

template <typename Data>
void OperazioniMatrixCSRString(lasd::MatrixCSR<Data>& matrix){
char scelta;
Data elem;
std::cout << "\nScegli l'operazione che vuoi effettuare: \n "<< std::endl;
std::cout<<"1->Visualizzazione in PreOrder \n2->Visualizzazione in PostOrder \n3->Ridimensionamento righe \n4->Ridimensionamento colonne"<< std::endl;
std::cout <<"\n5->Test di vuotezza \n6->Lettura della dimensione \n7->Svuotamento \n8->Controllo di esistenza di un valore \n9->Accesso ad una cella"<< std::endl;
std::cout << "\nA->Concatenazione delle stringhe di lunghezza minore o uguale a K \nB->Inserimento in testa di una stringa a tutti gli elementi \nq->Torna indietro"<<std::endl;

std::cin >>scelta;

switch(scelta){
    case '1':
      std::cout << "\033[2J\033[1;1H";
      cout<<"Visualizzazione in PreOrder: \n\n\n"<<endl;
      matrix.MapPreOrder(&MapPrint<string>, 0);
      OperazioniMatrixCSRString(matrix);
      break;
    case '2':
      std::cout << "\033[2J\033[1;1H";
      cout<<"Visualizzazione in PostOrder: \n\n\n"<<endl;
      matrix.MapPostOrder(&MapPrint<string>, 0);
      OperazioniMatrixCSRString(matrix);
      break;
    case '3':
      unsigned long rows;
      std::cout << "\033[2J\033[1;1H";
      cout<<"Scegli il nuovo numero di righe della matrice:\n"<<endl;
      matrix.RowResize(rows);
      OperazioniMatrixCSRString(matrix);
      break;
    case '4':
      unsigned long col;
      std::cout << "\033[2J\033[1;1H";
      cout<<"Scegli il nuovo numero di colonne della matrice:\n"<<endl;
      matrix.ColumnResize(col);
      OperazioniMatrixCSRString(matrix);
      break;
    case '5':
      std::cout << "\033[2J\033[1;1H";
      if(matrix.Empty()){
        cout<<"\n"<< "La matrice e' vuota"<<endl;
      }
      else{
        cout<<"\n"<< "La matrice non e' vuota"<<endl;
      }
      OperazioniMatrixCSRString(matrix);
      break;
    case '6':
      std::cout << "\033[2J\033[1;1H";
      elem=matrix.Size();
      cout<<"\n"<<"La dimensione attuale della matrice  e': "<<elem<<endl;
      OperazioniMatrixCSRString(matrix);
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
      OperazioniMatrixCSRString(matrix);
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
      OperazioniMatrixCSRString(matrix);
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
        OperazioniMatrixCSRString(matrix);
        break;
        case '2':
          cout<<"La cella scelta di indice "<<row<<" e di colonna "<<column<<" e' "<<matrix(row,column) <<endl;
          OperazioniMatrixCSRString(matrix);
          break;
        case '3':
          cout<<"Inserisci il valore che vuoi abbia la cella:" <<endl;
          cin>>elem;
          matrix(row,column)=elem;
          OperazioniMatrixCSRString(matrix);
          break;
        case 'b':
          std::cout << "\033[2J\033[1;1H";
          OperazioniMatrixCSRString(matrix);
          break;
        default:
          std::cout << "\033[2J\033[1;1H";
          std::cout<< "Scelta errata. Riprova. \n\n " <<std::endl;
          OperazioniMatrixCSRString(matrix);
      }
      OperazioniMatrixCSRString(matrix);
      break;
    case 'A': {
      std::cout << "\033[2J\033[1;1H";
      cout<<"***CONCATENAZIONE DELLE STRINGHE DI LUNGHEZZA <= K (LE STRINGHE SONO DI LUNGHEZZA 5)***\n"<<endl;
      cout<<"Inserisci K\n"<<endl;
      int k;
      cin >>k;
      string res="";

      matrix.FoldPreOrder([](const string& dat, const void* k, void* res)
    	      {
              if (5 <= *((int*)k))
                {
                  *((string*)res) += dat;
              }
          }, &k, &res);
      matrix.MapPreOrder(&MapPrint<string>,0);
      OperazioniMatrixCSRString(matrix);
      break;
    }
    case 'B':{
      string k;
      std::cout << "\033[2J\033[1;1H";
      cout<<"***INSERIMENTO IN TESTA DI UNA STRINGA A TUTTI GLI ELEMENTI***\n"<<endl;
      cout<<"Inserisci la stringa: \n"<<endl;
      cin>>k;
      matrix.MapPreOrder([]( string& dat, const void* k)
    	      {
              dat=*((string*)k) + dat;
              //*((string*)res) += dat;
          }, &k);

      matrix.MapPreOrder(&MapPrint<string>,0);
      OperazioniMatrixCSRString(matrix);
      break;
    }
    case 'q':
        std::cout << "\033[2J\033[1;1H";
        MatrixCSR();
        break;

    default:
      std::cout << "\033[2J\033[1;1H";
      std::cout<< "Scelta errata. Riprova. \n\n " <<std::endl;
      OperazioniMatrixCSRString(matrix);
  }
}




void MatrixCSRString(){

  unsigned long rows;
  unsigned long columns;
  srand(time(NULL));
  int stringlenght = 5;
  const int MAX = 52;

  std::cout << "Scegli il numero di righe della matrice: " << std::endl;
  std::cin >> rows;
  std::cout << "Scegli il numero di colonne della matrice: " << std::endl;
  std::cin >> columns;


  lasd::MatrixCSR<string> matrix(rows,columns);
  std::cout<<"\n"<<std::endl;

  char alphabet[MAX] = {'a','b','c','d','e','f','g','h','i','j','k','l','m','n',
                        'o','p','q','r','s','t','u','v','w','x','y','z','A','B',
                        'C','D','E','F','G','H','I','J','K','L','M','N','O','P',
                        'Q','R','S','T','U','V','W','X','Y','Z' };
  std::cout<<"\n"<<std::endl;

  for(unsigned long i = 0; i < matrix.RowNumber(); i++) {
    for(unsigned long j = 0; j < matrix.ColumnNumber();j++){
      string resultstring = "";
      for (int k = 0; k < stringlenght; k++){
          resultstring = resultstring + alphabet[rand() % MAX];
      }
      matrix(i,j)=resultstring;
      std::cout<<"Indici ("<< i <<"," << j <<"): "<<matrix(i,j)<<"\n"<<std::endl;
    }
  }

  OperazioniMatrixCSRString(matrix);
}
