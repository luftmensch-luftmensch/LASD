#include <iostream>
#include <random>
#include "../../binarytree/binarytree.hpp"
//#include "../../../binarytree/vec/binarytreevec.hpp"
#include "../../vector/vector.hpp"
#include "../../bst/bst.hpp"
#include "../../container/container.hpp"
#include "BinarySearchTree.hpp"
#include "../container/container.hpp"

void BinarySearchTreeInt(){
  ulong dim;
  uint elemento;
  bool quit = false;
  char opzione;
  std::cout << "Inserire la dimensione del BinarySearchTree di interi" << std::endl;
  std::cin >> dim;

  std::default_random_engine gen(std::random_device{}());
  std::uniform_int_distribution<unsigned int> dist(1, 100);

  lasd::Vector<int> VettoreInt(dim);
  std::cout<<"\n"<<std::endl;
  for(ulong i = 0; i < dim; i++) {
    VettoreInt[i]=dist(gen);
  }
  lasd::BST<int> BinarySearchTreeInt(VettoreInt);
  OperazioniDaEseguire();
  std::cout<< "\tCalcolo del prodotto degli interi minori di n(g)\n";

  while (opzione != 'q') {
    std::cin >> opzione;

    if ((opzione != '1') && (opzione != '2') && (opzione != '3') &&
        (opzione != '4') && (opzione != '5') && (opzione != '6') &&
        (opzione != '7') && (opzione != '8') && (opzione != '9') &&
        (opzione != 'a') && (opzione != 'b') && (opzione != 'c') &&
        (opzione != 'd') && (opzione != 'e') && (opzione != 'f') &&
        (opzione != 'g') && (opzione != 'q')) {
   	   std::cout << "ERRORE: opzione non valida\n";
	   std::cin >> opzione;
    }

    if (opzione == '1'){ // Visualizzazione in Pre-Order
      MapPreOrder(BinarySearchTreeInt, &MapPrint<int> , 0);
      std::cout << "\n";
      OperazioniDaEseguire();
      std::cout<< "\tCalcolo del prodotto degli interi minori di n(g)\n";
      std::cout<< "\tUscita(q)\n";
    }

    if (opzione == '2'){ // Visualizzazione in Post-Order
      MapPostOrder(BinarySearchTreeInt, &MapPrint<int> , 0);
      std::cout << "\n";
      OperazioniDaEseguire();
      std::cout<< "\tCalcolo del prodotto degli interi minori di n(g)\n";
      std::cout<< "\tUscita(q)\n";
    }

    if (opzione == '3'){ // Visualizzazione Inorder
      MapInOrder(BinarySearchTreeInt, &MapPrint<int> , 0);
      std::cout << "\n";
      OperazioniDaEseguire();
      std::cout<< "\tCalcolo del prodotto degli interi minori di n(g)\n";
      std::cout<< "\tUscita(q)\n";
    }

    if (opzione == '4'){ // Visualizzazione in Ampiezza
      MapBreadth(BinarySearchTreeInt, &MapPrint<int> , 0);
      std::cout << "\n";
      OperazioniDaEseguire();
      std::cout<< "\tCalcolo del prodotto degli interi minori di n(g)\n";
      std::cout<< "\tUscita(q)\n";
    }
    if (opzione == '5'){ // Test di vuotezza
      if (BinarySearchTreeInt.Empty()){
	std::cout << "La Struttura è vuota"<< std::endl;
      } else{
	std::cout << "La Struttura non è vuota" << std::endl;
      }
      OperazioniDaEseguire();
      std::cout<< "\tCalcolo del prodotto degli interi minori di n(g)\n";
      std::cout<< "\tUscita(q)\n";
    }
    if (opzione == '6'){ // Info dimensione della struttura
      std::cout << "La dimensione della struttura è " << BinarySearchTreeInt.Size() << std::endl;
      OperazioniDaEseguire();
      std::cout<< "\tCalcolo del prodotto degli interi minori di n(g)\n";
      std::cout<< "\tUscita(q)\n";
    }
    if (opzione == '7'){ // Svuotamento
      BinarySearchTreeInt.Clear();
      OperazioniDaEseguire();
      std::cout<< "\tCalcolo del prodotto degli interi minori di n(g)\n";
      std::cout<< "\tUscita(q)\n";
    }

    if (opzione == '8'){ // Controllo di esistenza di un dato valore nella struttura
      std::cout << "Inserisci l'elemento da ricercare: ";
      std::cin >> elemento;
      if (BinarySearchTreeInt.Exists(elemento)){
	std::cout << "Elemento trovato" << std::endl;
      } else {
        std::cout << "Elemento non trovato" << std::endl;
      }
      std::cout << "\n";
      OperazioniDaEseguire();
      std::cout<< "\tCalcolo del prodotto degli interi minori di n(g)\n";
      std::cout<< "\tUscita(q)\n";
    }
    if (opzione == '9') {
      lasd::BinaryTree<int> *BinarySearchTreeTempInt = &BinarySearchTreeInt;
      typename lasd::BinaryTree<int>::Node *corrente = &BinarySearchTreeTempInt->Root();
      bool boolean = true;
      while (corrente != nullptr && boolean == true) {
	std::cout << "L'elemento corrente e' : " << corrente->Element() << std::endl;
	std::cout << "\n 1->Modifica il valore corrente \n 2->Visita il figlio  sinistro (se presente) \n 3->Visita il figlio destro (se presente)\n" << std::endl;
	char scelta;
	std::cin >> scelta;
	switch (scelta) {
	case '1':
	  std::cout
	      << "\nInserisci il valore che vuoi abbia il nodo corrente \n" << std::endl;
	  int value;
	  std::cin >> value;
	  corrente->Element() = value;

	  break;
	case '2':
	  if (corrente->HasLeftChild()) {
	    corrente = &corrente->LeftChild();
	    std::cout << "\nIl figlio sinistro e': " << corrente << std::endl;
	  } else {
	    std::cout << "\nIl nodo corrente non ha figlio sinistro\n" << std::endl;
	  }
	  break;

	case '3':
	  if (corrente->HasRightChild()) {
	    corrente = &corrente->RightChild();
	    std::cout << "\nIl figlio destro e': " << corrente << std::endl;
	  } else {
	    std::cout << "\nIl nodo corrente non ha figlio destro\n" << std::endl;
	  }
	  break;
	case 'k':
	  std::cout << "\033[2J\033[1;1H";
	  boolean = false;
	  break;
        default:
          std::cout << "\033[2J\033[1;1H";
          std::cout << "Scelta errata. Riprova. \n\n " << std::endl;
        }
      }

      OperazioniDaEseguire();
      std::cout<< "\tCalcolo del prodotto degli interi minori di n(g)\n";
      std::cout<< "\tUscita(q)\n";
    }
    if (opzione == 'a'){ // Inserimento di un elemento
      int valore;
      std::cout << "Digitare l'elemento da inserire nella struttura:\n";
      std::cin >> valore;

      BinarySearchTreeInt.Insert(valore);
      
      OperazioniDaEseguire();
      std::cout<< "\tCalcolo del prodotto degli interi minori di n(g)\n";
      std::cout<< "\tUscita(q)\n";
    }

    if (opzione == 'b'){ // Rimozione di un elemento

      int valore;
      std::cout << "Digitare l'elemento da eliminare nella struttura:\n";
      std::cin >> valore;
      while(!BinarySearchTreeInt.Exists(valore)){
	std::cout<<"L'elemento scelto non esiste. Riprova\n"<<std::endl;
	std::cout<<"\nDigita il valore da rimuovere dall'ABR:\n"<<std::endl;
	std::cin>>valore;
      }

      BinarySearchTreeInt.Remove(valore);
      OperazioniDaEseguire();
      std::cout<< "\tCalcolo del prodotto degli interi minori di n(g)\n";
      std::cout<< "\tUscita(q)\n";
    }
    if (opzione == 'c'){ // Minimo 

      char scelta;
      std::cout << "\nScegli l'operazione che vuoi effettuare sul minimo :\n "<< std::endl;
      std::cout<<"1->Lettura non distruttiva \n2->Rimozione \n3->Rimozione con lettura \nq->Torna indietro"<< std::endl;
      std::cin >>scelta;

      switch(scelta){
        case '1':{
           MapPreOrder(BinarySearchTreeInt,&MapPrint<int>,0);
           int elemento=BinarySearchTreeInt.Min();
	   std::cout << "Il minimo è: "<< elemento <<std::endl;
	   MapPreOrder(BinarySearchTreeInt,&MapPrint<int>,0);
           break;
           }
        case '2':{
           MapPreOrder(BinarySearchTreeInt,&MapPrint<int>,0);
           BinarySearchTreeInt.RemoveMin();

	   std::cout << "Il minimo è stato rimosso\n";
           MapPreOrder(BinarySearchTreeInt,&MapPrint<int>,0);
           break;
           }
           case '3': {
             MapPreOrder(BinarySearchTreeInt, &MapPrint<int>, 0);
             int elemento = BinarySearchTreeInt.MinNRemove();
	     std::cout << "Il minimo è stato rimosso\n";
             MapPreOrder(BinarySearchTreeInt, &MapPrint<int>, 0);
	   std::cout << "L'elemento eliminato è: "<< elemento <<std::endl;
             break;
           }
           case 'q':
             std::cout << "\033[2J\033[1;1H";
             break;

           default:
             std::cout << "\033[2J\033[1;1H";
             std::cout << "Scelta errata. Riprova. \n\n " << std::endl;
             break;
           }
      OperazioniDaEseguire();
      std::cout<< "\tCalcolo del prodotto degli interi minori di n(g)\n";
      std::cout<< "\tUscita(q)\n";
    }
    if (opzione == 'd'){ // Massimo
      char scelta;
      std::cout << "\nScegli l'operazione che vuoi effettuare sul massimo :\n "<< std::endl;
      std::cout<<"1->Lettura non distruttiva \n2->Rimozione \n3->Rimozione con lettura \nq->Torna indietro"<< std::endl;
      std::cin >>scelta;

      switch(scelta){
        case '1':{
           MapPreOrder(BinarySearchTreeInt,&MapPrint<int>,0);
           int elemento=BinarySearchTreeInt.Max();
	   std::cout << "Il massimo è: "<< elemento <<std::endl;
	   MapPreOrder(BinarySearchTreeInt,&MapPrint<int>,0);
           break;
           }
        case '2':{
           MapPreOrder(BinarySearchTreeInt,&MapPrint<int>,0);
           BinarySearchTreeInt.RemoveMax();

	   std::cout << "Il massimo è stato rimosso\n";
           MapPreOrder(BinarySearchTreeInt,&MapPrint<int>,0);
           break;
           }
           case '3': {
             MapPreOrder(BinarySearchTreeInt, &MapPrint<int>, 0);
             int elemento = BinarySearchTreeInt.MaxNRemove();
	     std::cout << "Il massimo è stato rimosso\n";
             MapPreOrder(BinarySearchTreeInt, &MapPrint<int>, 0);
	   std::cout << "L'elemento eliminato è: "<< elemento <<std::endl;
             break;
           }
           case 'q':
             std::cout << "\033[2J\033[1;1H";
             break;

           default:
             std::cout << "\033[2J\033[1;1H";
             std::cout << "Scelta errata. Riprova. \n\n " << std::endl;
             break;
           }
      OperazioniDaEseguire();
      std::cout<< "\tCalcolo del prodotto degli interi minori di n(g)\n";
      std::cout<< "\tUscita(q)\n";
    }
    if (opzione == 'e'){ // Predecessore
      
      char scelta;
      int valore;
      MapPreOrder(BinarySearchTreeInt,&MapPrint<int>,0);
      std::cout << "\nInserisci l'elemento di cui vuoi esaminare il predecessore :\n "<< std::endl;
      std::cin>>valore;

      std::cout << "\nScegli l'operazione che vuoi effettuare sul predecessore dell'elemento scelto :\n "<< std::endl;
      std::cout<<"1->Lettura non distruttiva \n2->Rimozione \n3->Rimozione con lettura \nq->Torna indietro"<< std::endl;
      std::cin >>scelta;

      switch (scelta) {
      case '1': {
	int elemento = BinarySearchTreeInt.Predecessor(valore);
	std::cout << "\n\nIl predecesore dell'elemento scelto e': " << elemento << "\n";
	MapPreOrder(BinarySearchTreeInt, &MapPrint<int>, 0);
	break;
      }
      case '2': {
	MapPreOrder(BinarySearchTreeInt, &MapPrint<int>, 0);
	BinarySearchTreeInt.RemovePredecessor(valore);
	std::cout << "\n\nIl predecessore dell'elemento scelto è stato rimosso\n" << std::endl;
	MapPreOrder(BinarySearchTreeInt, &MapPrint<int>, 0);
	break;
      }
      case '3': {
	MapPreOrder(BinarySearchTreeInt, &MapPrint<int>, 0);
	int elemento = BinarySearchTreeInt.PredecessorNRemove(valore);
	std::cout << "\n\nIl predecessore è stato rimosso\n" << std::endl;
	MapPreOrder(BinarySearchTreeInt, &MapPrint<int>, 0);
	std::cout << "L'elemento rimosso e': " << elemento << std::endl;
	break;
      }
      case 'q':
	std::cout << "\033[2J\033[1;1H";
	break;

      default:
	std::cout << "\033[2J\033[1;1H";
	std::cout << "Scelta errata. Riprova. \n\n " << std::endl;
        break;
      }
      OperazioniDaEseguire();
      std::cout<< "\tCalcolo del prodotto degli interi minori di n(g)\n";
      std::cout<< "\tUscita(q)\n";

    }
    if (opzione == 'f'){ // Successore
      
      char scelta;
      int valore;
      MapPreOrder(BinarySearchTreeInt,&MapPrint<int>,0);
      std::cout << "\nInserisci l'elemento di cui vuoi esaminare il successore :\n "<< std::endl;
      std::cin>>valore;

      std::cout << "\nScegli l'operazione che vuoi effettuare sul successore dell'elemento scelto :\n "<< std::endl;
      std::cout<<"1->Lettura non distruttiva \n2->Rimozione \n3->Rimozione con lettura \nq->Torna indietro"<< std::endl;
      std::cin >>scelta;

      switch (scelta) {
      case '1': {
	int elemento = BinarySearchTreeInt.Predecessor(valore);
	std::cout << "\n\nIl successore dell'elemento scelto e': " << elemento << "\n";
	MapPreOrder(BinarySearchTreeInt, &MapPrint<int>, 0);
	break;
      }
      case '2': {
	MapPreOrder(BinarySearchTreeInt, &MapPrint<int>, 0);
	BinarySearchTreeInt.RemovePredecessor(valore);
	std::cout << "\n\nIl successore dell'elemento scelto è stato rimosso\n" << std::endl;
	MapPreOrder(BinarySearchTreeInt, &MapPrint<int>, 0);
	break;
      }
      case '3': {
	MapPreOrder(BinarySearchTreeInt, &MapPrint<int>, 0);
	int elemento = BinarySearchTreeInt.PredecessorNRemove(valore);
	std::cout << "\n\nIl successore è stato rimosso\n" << std::endl;
	MapPreOrder(BinarySearchTreeInt, &MapPrint<int>, 0);
	std::cout << "L'elemento rimosso e': " << elemento << std::endl;
	break;
      }
      case 'q':
	std::cout << "\033[2J\033[1;1H";
	break;

      default:
	std::cout << "\033[2J\033[1;1H";
	std::cout << "Scelta errata. Riprova. \n\n " << std::endl;
        break;
      }
      OperazioniDaEseguire();
      std::cout<< "\tCalcolo del prodotto degli interi minori di n(g)\n";
      std::cout<< "\tUscita(q)\n";
    }
    if (opzione == 'g'){ // Calcolo prodotto degli interi minori di N
      lasd::BTBreadthIterator<int> Iterator(BinarySearchTreeInt);
      int n;
      int prod = 1;
      std::cin >> n;
      int i = 0;
      while (i < dim) {
	if (*Iterator < n) {

	  prod = (*Iterator) * prod;
	}
	++Iterator;
	i++;
      }
      if (prod == 1) {
	std::cout << "Non ci sono elementi minori di n\n";

      } else {
	std::cout << "Il prodotto degli elementi minori di n e': " << prod << std::endl;
      }

      OperazioniDaEseguire();
      std::cout << "\tCalcolo del prodotto degli interi minori di n(g)\n";
      std::cout << "\tUscita(q)\n";
    }
    if (opzione == 'q'){
      std::cout << "\033[2J\033[1;1H";
      std::cout << "Scegli il tipo di struttura: "<< std::endl;
      std::cout<<"BinarySearchTree (1 -> int; 2 -> float; 3 -> string)"<< std::endl;
      std::cout<< "Premi q per uscire" << std::endl;
    }
  }
}
