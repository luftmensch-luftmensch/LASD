#include "../../container/container.hpp"
#include "../../matrix/vec/matrixvec.hpp"
#include "../../matrix/matrix.hpp"
#include "../../vector/vector.hpp"
#include "../container/container.hpp"
#include "matrixVec.hpp"
#include <iostream>
#include <random>


void MatrixVecInt(){
  bool quit = false;
  char opzione;
  ulong righe;
  ulong colonne;

  std::cout << "Scegli il numero di righe della matrice: " << std::endl;
  std::cin >> righe;
  std::cout << "Scegli il numero di colonne della matrice: " << std::endl;
  std::cin >> colonne;
  

  std::default_random_engine gen(std::random_device{}());
  std::uniform_int_distribution<unsigned int> dist(1, 100);

  lasd::MatrixVec<int> matriceVecInt(righe,colonne);

  for(unsigned long i = 0; i < matriceVecInt.RowNumber(); i++) {
    for(unsigned long j = 0; j < matriceVecInt.ColumnNumber();j++){
      matriceVecInt(i,j)=dist(gen);
    }
  }

  OperazioniDaEseguire();
  std::cout << "\nProdotto degli interi minori di n (a) \nApplicazione della funzione 2N agli elementi(b) \nUscita(q)"<<std::endl;

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
      matriceVecInt.MapPreOrder(&MapPrint<int>, 0);

      OperazioniDaEseguire();
      std::cout << "\nProdotto degli interi minori di n (a) \nApplicazione della funzione 2N agli elementi(b) \nUscita(q)"<<std::endl;
    }

    if (opzione == '2') { // Visualizzazione in Post-Order
      matriceVecInt.MapPostOrder(&MapPrint<int>, 0);

      OperazioniDaEseguire();
      std::cout << "\nProdotto degli interi minori di n (a) \nApplicazione della funzione 2N agli elementi(b) \nUscita(q)"<<std::endl;
    }
    if (opzione == '3'){ // Resize riga
      ulong newRiga;
      std::cout << "\033[2J\033[1;1H";
      std::cout<<"Scegli il nuovo numero di righe della matrice:\n"<<std::endl;
      std::cin>> newRiga;
      matriceVecInt.RowResize(newRiga);
      
      OperazioniDaEseguire();
      std::cout << "\nProdotto degli interi minori di n (a) \nApplicazione della funzione 2N agli elementi(b) \nUscita(q)"<<std::endl;
    }

    if (opzione == '4'){ // Resize colonna
      ulong newColonna;
      std::cout << "\033[2J\033[1;1H";
      std::cout<<"Scegli il nuovo numero di righe della matrice:\n"<<std::endl;
      std::cin>> newColonna;
      matriceVecInt.ColumnResize(newColonna);
      
      OperazioniDaEseguire();
      std::cout << "\nProdotto degli interi minori di n (a) \nApplicazione della funzione 2N agli elementi(b) \nUscita(q)"<<std::endl;
    }
    if (opzione == '5'){ // Test di vuotezza
      if(matriceVecInt.Empty()){
	std::cout<<"\n"<< "La matrice è vuota"<<std::endl;
      }
      else{
	std::cout<<"\n"<< "La matrice non è vuota"<<std::endl;
      }

      OperazioniDaEseguire();
      std::cout << "\nProdotto degli interi minori di n (a) \nApplicazione della funzione 2N agli elementi(b) \nUscita(q)"<<std::endl;
    }
    if (opzione == '6'){ // Size
      std::cout<<"\n"<<"La dimensione attuale della matrice  e': "<<matriceVecInt.Size()<<std::endl;

      OperazioniDaEseguire();
      std::cout << "\nProdotto degli interi minori di n (a) \nApplicazione della funzione 2N agli elementi(b) \nUscita(q)"<<std::endl;
    }
    if (opzione == '7'){ // Svuotamento
      matriceVecInt.Clear();

      OperazioniDaEseguire();
      std::cout << "\nProdotto degli interi minori di n (a) \nApplicazione della funzione 2N agli elementi(b) \nUscita(q)"<<std::endl;
    }
    if (opzione == '8'){ // Controllo di esistenza di un valore
      ulong elemento;
      std::cout << "\033[2J\033[1;1H";
      std::cout<<"Inserisci il valore da cercare: \n"<<std::endl;
      std::cin >> elemento;
      bool trovato=false;
      for(ulong i=0;i<matriceVecInt.RowNumber();i++){
        for(ulong j=0;j<matriceVecInt.ColumnNumber();j++){
          if(elemento==matriceVecInt(i,j)){
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
      std::cout << "\nProdotto degli interi minori di n (a) \nApplicazione della funzione 2N agli elementi(b) \nUscita(q)"<<std::endl;
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
          if(matriceVecInt.ExistsCell(row,column)){
	    std::cout<<"La cella scelta e' presente " <<std::endl;
          }
          else{
	    std::cout<<"La cella scelta non e' presente " <<std::endl;
          }

	OperazioniDaEseguire();
	std::cout << "\nProdotto degli interi minori di n (a) \nApplicazione della funzione 2N agli elementi(b) \nUscita(q)"<<std::endl;
        break;
        case '2':
	  std::cout<<"La cella scelta di indice "<<row<<" e di colonna "<<column<<" e' "<<matriceVecInt(row,column) <<std::endl;
	  OperazioniDaEseguire();
	  std::cout << "\nProdotto degli interi minori di n (a) \nApplicazione della funzione 2N agli elementi(b) \nUscita(q)"<<std::endl;
          break;
        case '3':
	  std::cout<<"Inserisci il valore che vuoi abbia la cella:" <<std::endl;
	  std::cin>>elem;
          matriceVecInt(row,column)=elem;
	  OperazioniDaEseguire();
	  std::cout << "\nProdotto degli interi minori di n (a) \nApplicazione della funzione 2N agli elementi(b) \nUscita(q)"<<std::endl;

          break;
        case '4':
          std::cout << "\033[2J\033[1;1H";

	  OperazioniDaEseguire();
	  std::cout << "\nProdotto degli interi minori di n (a) \nApplicazione della funzione 2N agli elementi(b) \nUscita(q)"<<std::endl;

          break;
        default:
          std::cout << "\033[2J\033[1;1H";
          std::cout<< "Scelta errata. Riprova. \n\n " <<std::endl;
      }
    }
    if (opzione == 'a'){ // Prodotto di interi < n
      std::cout<<"Inserisci n\n"<<std::endl;
      int n;
      std::cin >>n;
      int prod=1;

      matriceVecInt.FoldPreOrder([](const int& dat, const void* n, void* prod)
    	      {
              if (dat < *((int*)n))
                {
                  *((int*)prod) *= dat;
              }
          }, &n, &prod);
          if (prod!=1){
            std::cout << "Il prodotto e' "<<prod<<std::endl;
          }
          else{
            std::cout << "Non vi sono elementi con valore minore di quello scelto" << std::endl;
          }

	OperazioniDaEseguire();
	std::cout << "\nProdotto degli interi minori di n (a) \nApplicazione della funzione 2N agli elementi(b) \nUscita(q)"<<std::endl;
    }
    if (opzione == 'b'){
      
      matriceVecInt.MapPreOrder(&MapDoubleNPrint<int>, 0);
      OperazioniDaEseguire();
      std::cout << "\nProdotto degli interi minori di n (a) \nApplicazione della funzione 2N agli elementi(b) \nUscita(q)"<<std::endl;
    }
    if (opzione == 'q'){

      std::cout << "Scegli il tipo di rappresentazione di matrice su cui vuoi operare: "<< std::endl;
      std::cout<<"(Matrice Densa - Naive Representation (1 - Int; 2 - Float; 3 - String) Matrice Sparsa - CSR (4 - Int; 5 - Float; 6 - String) q->exit)"<< std::endl; 
      
    }

  }
}
