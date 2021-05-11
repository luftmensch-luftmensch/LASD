#include <iostream>
#include <random>
#include "../../../binarytree/binarytree.hpp"
#include "../../../binarytree/vec/binarytreevec.hpp"
#include "../../container/container.hpp"
#include "binarytreevec.hpp"

void BinaryTreeVecInt(){
  uint dim, elemento;
  uint j = 0;
  bool quit = false;
  char opzione;

  std::cout << "Inserire la dimensione del binarytree di interi" << std::endl;
  std::cin >> dim;

  std::cout << "\033[2J\033[1;1H"; // simil clear
  std::default_random_engine gen(std::random_device{}());
  std::uniform_int_distribution<unsigned int> dist(1, 100);
  lasd::Vector<int> VettoreInt(dim);

  while(j < dim){
    VettoreInt[j] = dist(gen);
    j++;
  }
  lasd::BinaryTreeVec<int> BinaryTreeInt(VettoreInt);

  OperazioniDaEseguire();
  std::cout<< "\tCalcolo del prodotto degli interi minori di n(d)\n";
  std::cout<< "\tCalcolo della funzione 3n(e)\n";
  std::cout<< "\tUscita(q)\n";
  while (opzione != 'q') {
    std::cin >> opzione;

    if ((opzione != '1') && (opzione != '2') && (opzione != '3') &&
	(opzione != '4') && (opzione != '5') && (opzione != '6') &&
	(opzione != '7') &&  (opzione != '8') && (opzione != '9') &&
	(opzione != 'a') &&  (opzione != 'b') &&
	(opzione != 'q')) {
      std::cout << "ERRORE: opzione non valida\n";
    }
    if (opzione == '1'){ // Visualizzazione in Pre-Order
      MapPreOrder(BinaryTreeInt, &MapPrint<int> , 0);
      std::cout << "\n";
      OperazioniDaEseguire();
      std::cout<< "\tCalcolo del prodotto degli interi minori di n(d)\n";
      std::cout<< "\tCalcolo della funzione 3n(e)\n";
      std::cout<< "\tUscita(q)\n";
    }

    if (opzione == '2'){ // Visualizzazione in Post-Order
      MapPostOrder(BinaryTreeInt, &MapPrint<int> , 0);
      std::cout << "\n";
      OperazioniDaEseguire();
      std::cout<< "\tCalcolo del prodotto degli interi minori di n(d)\n";
      std::cout<< "\tCalcolo della funzione 3n(e)\n";
      std::cout<< "\tUscita(q)\n";
    }

    if (opzione == '3'){ // Visualizzazione Inorder
      MapInOrder(BinaryTreeInt, &MapPrint<int> , 0);
      std::cout << "\n";
      OperazioniDaEseguire();
      std::cout<< "\tCalcolo del prodotto degli interi minori di n(d)\n";
      std::cout<< "\tCalcolo della funzione 3n(e)\n";
      std::cout<< "\tUscita(q)\n";
    }

    if (opzione == '4'){ // Visualizzazione in Ampiezza
      MapBreadth(BinaryTreeInt, &MapPrint<int> , 0);
      std::cout << "\n";
      OperazioniDaEseguire();
      std::cout<< "\tCalcolo del prodotto degli interi minori di n(d)\n";
      std::cout<< "\tCalcolo della funzione 3n(e)\n";
      std::cout<< "\tUscita(q)\n";
    }

    if (opzione == '5'){ // Controllo di esistenza di un dato valore nella struttura
      std::cout << "Inserisci l'elemento da ricercare: ";
      std::cin >> elemento;
      if (BinaryTreeInt.Exists(elemento)){
	std::cout << "Elemento trovato" << std::endl;
      } else{
	std::cout << "Elemento non trovato" << std::endl;
      }
      std::cout << "\n";
      OperazioniDaEseguire();

      std::cout<< "\tCalcolo del prodotto degli interi minori di n(d)\n";
      std::cout<< "\tCalcolo della funzione 3n(e)\n";
      std::cout<< "\tUscita(q)\n";
    }

    if (opzione == '6'){ // Controllo di vuotezza della  Struttura
      if (BinaryTreeInt.Empty()){
	std::cout << "La Struttura è vuota"<< std::endl;
      } else{
	std::cout << "La Struttura non è vuota" << std::endl;
      }

      std::cout << "\n";
      OperazioniDaEseguire();

      std::cout<< "\tCalcolo del prodotto degli interi minori di n(d)\n";
      std::cout<< "\tCalcolo della funzione 3n(e)\n";
      std::cout<< "\tUscita(q)\n";
    }
    if (opzione == '7'){
      std::cout << "La dimensione della struttura è " << BinaryTreeInt.Size() << std::endl;

      std::cout << "\n";
      OperazioniDaEseguire();
      std::cout<< "\tCalcolo del prodotto degli interi minori di n(d)\n";
      std::cout<< "\tCalcolo della funzione 3n(e)\n";
      std::cout<< "\tUscita(q)\n";
    }
    if (opzione == '8'){
      BinaryTreeInt.Clear();
      std::cout << "Struttura svuotata" << std::endl;

      std::cout << "\n";
      OperazioniDaEseguire();
      std::cout<< "\tCalcolo del prodotto degli interi minori di n(d)\n";
      std::cout<< "\tCalcolo della funzione 3n(e)\n";
      std::cout<< "\tUscita(q)\n";
    }
    if (opzione == '9'){ // Esplorazione in lettura e/o scrittura

        lasd::BinaryTree<int>* BinaryTreeIntCopia=&BinaryTreeInt;
        bool boolean=true;
        typename lasd::BinaryTree<int>::Node* current = &BinaryTreeIntCopia->Root();
        while(current!=nullptr&&boolean==true){
	  std::cout<<"L'elemento corrente e' : "<<current->Element()<<std::endl;
	  std::cout<<"\n Cosa vuoi fare? "<<std::endl;
	  std::cout<<"\n 1->Modifica il valore corrente \n 2->Visita il figlio sinistro (se presente) \n 3->Visita il figlio destro (se presente)\n"<<std::endl;

          char choice;
	  std::cin >>choice;
          switch(choice){
            case '1':
	      std::cout<<"\nInserisci il valore che vuoi abbia il nodo corrente \n"<<std::endl;
              int valore;
	      std::cin>>valore;
              current->Element()=valore;

              break;
            case '2':
              if(current->HasLeftChild()){
                current=&current->LeftChild();
              }
              else{
		std::cout<<"\nIl nodo corrente non ha figlio sinistro\n"<<std::endl;
              }
              break;

            case '3':
              if(current->HasRightChild()){
                current=&current->RightChild();
              }
              else{
		std::cout<<"\nIl nodo corrente non ha figlio destro\n"<<std::endl;
              }
              break;
            case 'q':
              std::cout << "\033[2J\033[1;1H";
              boolean=false;
              break;
            default:
              std::cout << "\033[2J\033[1;1H";
              std::cout<< "Scelta errata. Riprova. \n\n " <<std::endl;
            }
        }
      std::cout << "\n";
      OperazioniDaEseguire();
      std::cout<< "\tCalcolo del prodotto degli interi minori di n(d)\n";
      std::cout<< "\tCalcolo della funzione 3n(e)\n";
      std::cout<< "\tUscita(q)\n";
    }
    if (opzione == 'a'){ // Navigazione in  Pre-Order
      
      std::cout<<"Navigazione in PreOrder:"<<std::endl;

       lasd::BTPreOrderIterator<int> Iteratore(BinaryTreeInt);
       int i=0;
       char next;
       while(i<dim){ // Sostituire con valore booleano
	 std::cout<<"\nL'elemento corrente e' : "<<*Iteratore<<std::endl;
	 std::cout<<"\nPremi n per continuare la navigazione\n"<<std::endl;
	 std::cin>>next;
         ++Iteratore;
         i++;
       }
       if(i==dim){
	 std::cout<<"Navigazione completata!\n\n"<<std::endl;

       }
      OperazioniDaEseguire();
      std::cout<< "\tCalcolo del prodotto degli interi minori di n(a)\n";
      std::cout<< "\tCalcolo della funzione 3n(b)\n";
      std::cout<< "\tUscita(q)\n";
    }

    if (opzione == 'b'){ // Navigazione in Post-Order

      std::cout<<"Navigazione in PreOrder:"<<std::endl;

       lasd::BTPostOrderIterator<int> Iteratore(BinaryTreeInt);
       int i=0;
       char next;
       while(i<dim){
	 std::cout<<"\nL'elemento corrente e' : "<<*Iteratore<<std::endl;
	 std::cout<<"\nPremi n per continuare la navigazione\n"<<std::endl;
	 std::cin>>next;
         ++Iteratore;
         i++;
       }
       if(i==dim){
	 std::cout<<"Navigazione completata!\n\n"<<std::endl;

       }
      
      OperazioniDaEseguire();
      std::cout<< "\tCalcolo del prodotto degli interi minori di n(a)\n";
      std::cout<< "\tCalcolo della funzione 3n(b)\n";
      std::cout<< "\tUscita(q)\n";
    }

    if (opzione == 'c'){ // Navigazione InOrder
      std::cout<<"Navigazione in PreOrder:"<<std::endl;

       lasd::BTInOrderIterator<int> Iteratore(BinaryTreeInt);
       int i=0;
       char next;
       while(i<dim){
	 std::cout<<"\nL'elemento corrente e' : "<<*Iteratore<<std::endl;
	 std::cout<<"\nPremi n per continuare la navigazione\n"<<std::endl;
	 std::cin>>next;
         ++Iteratore;
         i++;
       }
       if(i==dim){
	 std::cout<<"Navigazione completata!\n\n"<<std::endl;

       }

      OperazioniDaEseguire();
      std::cout<< "\tCalcolo del prodotto degli interi minori di n(a)\n";
      std::cout<< "\tCalcolo della funzione 3n(b)\n";
      std::cout<< "\tUscita(q)\n";
    }

    if (opzione == 'f'){ // Navigazione in Ampiezza

      std::cout<<"Navigazione in PreOrder:"<<std::endl;

       lasd::BTBreadthIterator<int> Iteratore(BinaryTreeInt);
       int i=0;
       char next;
       while(i<dim){
	 std::cout<<"\nL'elemento corrente e' : "<<*Iteratore<<std::endl;
	 std::cout<<"\nPremi n per continuare la navigazione\n"<<std::endl;
	 std::cin>>next;
         ++Iteratore;
         i++;
       }
       if(i==dim){
	 std::cout<<"Navigazione completata!\n\n"<<std::endl;
       }

      OperazioniDaEseguire();
      std::cout<< "\tCalcolo del prodotto degli interi minori di n(a)\n";
      std::cout<< "\tCalcolo della funzione 3n(b)\n";
      std::cout<< "\tUscita(q)\n";
      
    }

    if (opzione == 'd'){ // Prodotto degli interi minori di n

      lasd::BTBreadthIterator<int> Iteratore(BinaryTreeInt);
      std::cout<<"Inserisci il valore:\n"<<std::endl;
      int n;
      int i=0;
      long int prod=1;
      std::cin >>n;
      while(i<dim){
	if(*Iteratore <n){

	  prod=(*Iteratore)*prod;
	}
	++Iteratore;
	i++;
      }
      if(prod==1){
	std::cout<<"Non ci sono elementi minori di N"<<std::endl;

      }
      else{
	std::cout<<"Il prodotto degli elementi minori di N e': "<<prod<<std::endl;
      }

      std::cout << "\n";
      OperazioniDaEseguire();
      std::cout<< "\tCalcolo del prodotto degli interi minori di n(a)\n";
      std::cout<< "\tCalcolo della funzione 3n(b)\n";
      std::cout<< "\tUscita(q)\n";
    }

    if (opzione == 'e'){ // Funzione 3n

      MapPreOrder(BinaryTreeInt, &MapPrint<int> , 0);
      MapPreOrder(BinaryTreeInt, &MapTriple<int> , 0);
      std::cout<<"\n\n"<<std::endl;
      
      MapPreOrder(BinaryTreeInt, &MapPrint<int> , 0);
      std::cout << "\n";
      OperazioniDaEseguire();

      std::cout<< "\tCalcolo del prodotto degli interi minori di n(d)\n";
      std::cout<< "\tCalcolo della funzione 3n(e)\n";
      std::cout<< "\tUscita(q)\n";
    }
    if (opzione == 'q'){
      std::cout << "\033[2J\033[1;1H";
      std::cout << "Scegli il tipo di struttura: "<< std::endl;
      std::cout<<"Binarytree implementato con vettori (1 -> int; 2 -> float; 3 -> string)"<< std::endl;
      std::cout<<"Binarytree implementato con lista (4 -> int; 5 -> float; 6 -> string)"<< std::endl;
      std::cout<< "Premi q per uscire" << std::endl;
    }
  }
}
