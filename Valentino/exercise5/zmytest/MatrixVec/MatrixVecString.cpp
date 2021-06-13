#include "../../container/container.hpp"
#include "../../matrix/vec/matrixvec.hpp"
#include "../../matrix/matrix.hpp"
#include "../../vector/vector.hpp"
#include "../container/container.hpp"
#include "matrixVec.hpp"
#include <iostream>
#include <random>


void MatrixVecString(){
  const int MAX = 52;
  int stringlenght = 5;
  bool quit = false;
  char opzione;
  ulong righe;
  ulong colonne;

  std::cout << "Scegli il numero di righe della matrice: " << std::endl;
  std::cin >> righe;
  std::cout << "Scegli il numero di colonne della matrice: " << std::endl;
  std::cin >> colonne;

  srand(time(NULL));
  char alphabet[MAX] = {'a','b','c','d','e','f','g','h','i','j','k','l','m','n',
                        'o','p','q','r','s','t','u','v','w','x','y','z','A','B',
                        'C','D','E','F','G','H','I','J','K','L','M','N','O','P',
                        'Q','R','S','T','U','V','W','X','Y','Z' };
  std::cout<<"\n"<<std::endl;

  lasd::MatrixVec<std::string> matriceVecString(righe,colonne);

  for(unsigned long i = 0; i < matriceVecString.RowNumber(); i++) {
    for(unsigned long j = 0; j < matriceVecString.ColumnNumber();j++){
      std::string resultstring = "";
      for (int k = 0; k < stringlenght; k++){
          resultstring = resultstring + alphabet[rand() % MAX];
      }
      matriceVecString(i,j)=resultstring;
    }
  }

  OperazioniDaEseguire();
  std::cout << "\nConcatenazione stringhe di lunghezza <= n(a) \nInserimento in testa a tutti gli elementi(b) \nUscita(q)"<<std::endl;

  while (opzione != 'q') {
    std::cin >> opzione;

    if ((opzione != '1') && (opzione != '2') && (opzione != '3') &&
        (opzione != '4') && (opzione != '5') && (opzione != '6') &&
        (opzione != '7') && (opzione != '8') && (opzione != '9') &&
        (opzione != 'a') && (opzione != 'b') && (opzione != 'q')) {
   	   std::cout << "ERRORE: opzione non valida\n";
	   std::cin >> opzione;
    }
    if (opzione == '1') { // Visualizzazione in Pre-Order
      matriceVecString.MapPreOrder(&MapPrint<std::string>, 0);

      OperazioniDaEseguire();
      std::cout << "\nConcatenazione stringhe di lunghezza <= n(a) \nInserimento in testa a tutti gli elementi(b) \nUscita(q)"<<std::endl;
    }

    if (opzione == '2') { // Visualizzazione in Post-Order
      matriceVecString.MapPostOrder(&MapPrint<std::string>, 0);

      OperazioniDaEseguire();
      std::cout << "\nConcatenazione stringhe di lunghezza <= n(a) \nInserimento in testa a tutti gli elementi(b) \nUscita(q)"<<std::endl;
    }
    if (opzione == '3'){ // Resize riga
      ulong newRiga;
      std::cout << "\033[2J\033[1;1H";
      std::cout<<"Scegli il nuovo numero di righe della matrice:\n"<<std::endl;
      std::cin>> newRiga;
      matriceVecString.RowResize(newRiga);
      
      OperazioniDaEseguire();
      std::cout << "\nConcatenazione stringhe di lunghezza <= n(a) \nInserimento in testa a tutti gli elementi(b) \nUscita(q)"<<std::endl;
    }

    if (opzione == '4'){ // Resize colonna
      ulong newColonna;
      std::cout << "\033[2J\033[1;1H";
      std::cout<<"Scegli il nuovo numero di righe della matrice:\n"<<std::endl;
      std::cin>> newColonna;
      matriceVecString.ColumnResize(newColonna);
      
      OperazioniDaEseguire();
      std::cout << "\nConcatenazione stringhe di lunghezza <= n(a) \nInserimento in testa a tutti gli elementi(b) \nUscita(q)"<<std::endl;
    }
    if (opzione == '5'){ // Test di vuotezza
      if(matriceVecString.Empty()){
	std::cout<<"\n"<< "La matrice è vuota"<<std::endl;
      }
      else{
	std::cout<<"\n"<< "La matrice non è vuota"<<std::endl;
      }

      OperazioniDaEseguire();
      std::cout << "\nConcatenazione stringhe di lunghezza <= n(a) \nInserimento in testa a tutti gli elementi(b) \nUscita(q)"<<std::endl;
    }
    if (opzione == '6'){ // Size
      std::cout<<"\n"<<"La dimensione attuale della matrice  e': "<<matriceVecString.Size()<<std::endl;

      OperazioniDaEseguire();
      std::cout << "\nConcatenazione stringhe di lunghezza <= n(a) \nInserimento in testa a tutti gli elementi(b) \nUscita(q)"<<std::endl;
    }
    if (opzione == '7'){ // Svuotamento
      matriceVecString.Clear();

      OperazioniDaEseguire();
      std::cout << "\nConcatenazione stringhe di lunghezza <= n(a) \nInserimento in testa a tutti gli elementi(b) \nUscita(q)"<<std::endl;
    }
    if (opzione == '8'){ // Controllo di esistenza di un valore
      std::string elemento;
      std::cout << "\033[2J\033[1;1H";
      std::cout<<"Inserisci il valore da cercare: \n"<<std::endl;
      std::cin >> elemento;
      bool trovato=false;
      for(ulong i=0;i<matriceVecString.RowNumber();i++){
        for(ulong j=0;j<matriceVecString.ColumnNumber();j++){
          if(elemento==matriceVecString(i,j)){
            trovato=true;
          }
        }
      }

      if (trovato == true) {
	std::cout << "Il valore scelto è presente " << std::endl;
      } else {
	std::cout << "Il valore scelto non è presente " << std::endl;
      }
      OperazioniDaEseguire();
      std::cout << "\nConcatenazione stringhe di lunghezza <= n(a) \nInserimento in testa a tutti gli elementi(b) \nUscita(q)"<<std::endl;
    }
    if (opzione == '9'){ // Accesso a una cella
      ulong row,column,elem;
      char choice;
      std::cout << "\033[2J\033[1;1H";
      std::cout<<"Inserisci il valore di riga della cella da esaminare: \n";
      std::cin>>row;
      std::cout<<"Inserisci il valore di colonna della cella da esaminare: \n";
      std::cin>>column;
      std::cout<<"Scegli l'operazione da effettuare sulla cella ("<<row<<","<<column<<"):\n";
      std::cout<<"1->Controllo di esistenza \n2->Lettura \n3->Inserimento \n4->Torna indietro"<< std::endl;
      std::cin>>choice;
      switch(choice){
        case '1':
          if(matriceVecString.ExistsCell(row,column)){
	    std::cout<<"La cella scelta e' presente " <<std::endl;
          }
          else{
	    std::cout<<"La cella scelta non e' presente " <<std::endl;
          }

	OperazioniDaEseguire();
	std::cout << "\nConcatenazione stringhe di lunghezza <= n(a) \nInserimento in testa a tutti gli elementi(b) \nUscita(q)"<<std::endl;
	break;
        case '2':
	  std::cout<<"La cella scelta di indice "<<row<<" e di colonna "<<column<<" e' "<<matriceVecString(row,column) <<std::endl;
	  OperazioniDaEseguire();
	  std::cout << "\nConcatenazione stringhe di lunghezza <= n(a) \nInserimento in testa a tutti gli elementi(b) \nUscita(q)"<<std::endl;
          break;
        case '3':
	  std::cout<<"Inserisci il valore che vuoi abbia la cella:" <<std::endl;
	  std::cin>>elem;
          matriceVecString(row,column)=elem;
	  OperazioniDaEseguire();
	  std::cout << "\nConcatenazione stringhe di lunghezza <= n(a) \nInserimento in testa a tutti gli elementi(b) \nUscita(q)"<<std::endl;

          break;
        case '4':
          std::cout << "\033[2J\033[1;1H";

	  OperazioniDaEseguire();
	  std::cout << "\nConcatenazione stringhe di lunghezza <= n(a) \nInserimento in testa a tutti gli elementi(b) \nUscita(q)"<<std::endl;

	  break;
        default:
          std::cout << "\033[2J\033[1;1H";
          std::cout<< "Scelta errata. Riprova. \n\n " <<std::endl;
      }
    }
    if (opzione == 'a'){ // Concatenazione stringhe
      int k;
      std::cin >>k;
      std::string res="";

      matriceVecString.FoldPreOrder([](const std::string& dat, const void* k, void* res)
    	      {
              if (5 <= *((int*)k))
                {
                  *((std::string*)res) += dat;
              }
          }, &k, &res);

      OperazioniDaEseguire();
      std::cout << "\nConcatenazione stringhe di lunghezza <= n(a) " "\nInserimento in testa a tutti gli elementi(b) \nUscita(q)" << std::endl;
    }
    if (opzione == 'b'){
      std::string k;

      std::cout<<"Inserisci la stringa: \n";
      std::cin>>k;
      matriceVecString.MapPreOrder([]( std::string& dat, const void* k)
    	      {
		dat=*((std::string*)k) + dat;
          }, &k);

      
      OperazioniDaEseguire();
      std::cout << "\nConcatenazione stringhe di lunghezza <= n(a) \nInserimento in testa a tutti gli elementi(b) \nUscita(q)"<<std::endl;
    }
    if (opzione == 'q'){

      std::cout << "Scegli il tipo di rappresentazione di matrice su cui vuoi operare: "<< std::endl;
      std::cout<<"(Matrice Densa - Naive Representation (1 - Int; 2 - Float; 3 - String) Matrice Sparsa - CSR (4 - Int; 5 - Float; 6 - String) q->exit)"<< std::endl; 
      
    }

  }
}
