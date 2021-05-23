#include <iostream>
#include <random>
#include "../../binarytree/binarytree.hpp"
//#include "../../../binarytree/vec/binarytreevec.hpp"
#include "../../vector/vector.hpp"
#include "../../bst/bst.hpp"
#include "../../container/container.hpp"
#include "BinarySearchTree.hpp"
#include "../container/container.hpp"

void BinarySearchTreeString(){
  ulong dim;
  uint j;
  std::string elemento;
  bool quit = false;
  char opzione;
  std::cout << "Inserire la dimensione del BinarySearchTree di stringhe" << std::endl;
  std::cin >> dim;


  std::size_t length;
  std::mt19937 mt(std::random_device{}());
  std::string characters =
      "abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ";
  std::uniform_int_distribution<int> dist(0, characters.length() - 1);
  std::string randStr;

  lasd::Vector<std::string> VettoreString(dim);

  while(j < dim){
    randStr = characters[dist(mt)];
    VettoreString[j] = randStr;
    j++;
  }
  lasd::BST<std::string> BinarySearchTreeString(VettoreString);
  OperazioniDaEseguire();
  std::cout<< "\tConcatenazione delle stringhe con lunghezza minore di n(g)\n";

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
      MapPreOrder(BinarySearchTreeString, &MapPrint<std::string> , 0);
      std::cout << "\n";
      OperazioniDaEseguire();
      std::cout<< "\tConcatenazione delle stringhe con lunghezza minore di n(g)\n";
      std::cout<< "\tUscita(q)\n";
    }

    if (opzione == '2'){ // Visualizzazione in Post-Order
      MapPostOrder(BinarySearchTreeString, &MapPrint<std::string> , 0);
      std::cout << "\n";
      OperazioniDaEseguire();
      std::cout<< "\tConcatenazione delle stringhe con lunghezza minore di n(g)\n";
      std::cout<< "\tUscita(q)\n";
    }

    if (opzione == '3'){ // Visualizzazione Inorder
      MapInOrder(BinarySearchTreeString, &MapPrint<std::string> , 0);
      std::cout << "\n";
      OperazioniDaEseguire();
      std::cout<< "\tConcatenazione delle stringhe con lunghezza minore di n(g)\n";
      std::cout<< "\tUscita(q)\n";
    }

    if (opzione == '4'){ // Visualizzazione in Ampiezza
      MapBreadth(BinarySearchTreeString, &MapPrint<std::string> , 0);
      std::cout << "\n";
      OperazioniDaEseguire();
      std::cout<< "\tConcatenazione delle stringhe con lunghezza minore di n(g)\n";
      std::cout<< "\tUscita(q)\n";
    }
    if (opzione == '5'){ // Test di vuotezza
      if (BinarySearchTreeString.Empty()){
	std::cout << "La Struttura è vuota"<< std::endl;
      } else{
	std::cout << "La Struttura non è vuota" << std::endl;
      }
      OperazioniDaEseguire();
      std::cout<< "\tConcatenazione delle stringhe con lunghezza minore di n(g)\n";
      std::cout<< "\tUscita(q)\n";
    }
    if (opzione == '6'){ // Info dimensione della struttura
      std::cout << "La dimensione della struttura è " << BinarySearchTreeString.Size() << std::endl;
      OperazioniDaEseguire();
      std::cout<< "\tConcatenazione delle stringhe con lunghezza minore di n(g)\n";
      std::cout<< "\tUscita(q)\n";
    }
    if (opzione == '7'){ // Svuotamento
      BinarySearchTreeString.Clear();
      OperazioniDaEseguire();
      std::cout<< "\tConcatenazione delle stringhe con lunghezza minore di n(g)\n";
      std::cout<< "\tUscita(q)\n";
    }

    if (opzione == '8'){ // Controllo di esistenza di un dato valore nella struttura
      std::cout << "Inserisci l'elemento da ricercare: ";
      std::cin >> elemento;
      if (BinarySearchTreeString.Exists(elemento)){
	std::cout << "Elemento trovato" << std::endl;
      } else {
        std::cout << "Elemento non trovato" << std::endl;
      }
      std::cout << "\n";
      OperazioniDaEseguire();
      std::cout<< "\tConcatenazione delle stringhe con lunghezza minore di n(g)\n";
      std::cout<< "\tUscita(q)\n";
    }
    if (opzione == '9') {
      lasd::BinaryTree<std::string> *BinarySearchTreeTempString = &BinarySearchTreeString;
      typename lasd::BinaryTree<std::string>::Node *corrente = &BinarySearchTreeTempString->Root();
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
      std::cout<< "\tConcatenazione delle stringhe con lunghezza minore di n(g)\n";
      std::cout<< "\tUscita(q)\n";
    }
    if (opzione == 'a'){ // Inserimento di un elemento
      std::string valore;
      std::cout << "Digitare l'elemento da inserire nella struttura:\n";
      std::cin >> valore;

      BinarySearchTreeString.Insert(valore);
      
      OperazioniDaEseguire();
      std::cout<< "\tConcatenazione delle stringhe con lunghezza minore di n(g)\n";
      std::cout<< "\tUscita(q)\n";
    }

    if (opzione == 'b'){ // Rimozione di un elemento

      std::string valore;
      std::cout << "Digitare l'elemento da eliminare nella struttura:\n";
      std::cin >> valore;
      while(!BinarySearchTreeString.Exists(valore)){
	std::cout<<"L'elemento scelto non esiste. Riprova\n"<<std::endl;
	std::cout<<"\nDigita il valore da rimuovere dall'ABR:\n"<<std::endl;
	std::cin>>valore;
      }

      BinarySearchTreeString.Remove(valore);
      OperazioniDaEseguire();
      std::cout<< "\tConcatenazione delle stringhe con lunghezza minore di n(g)\n";
      std::cout<< "\tUscita(q)\n";
    }
    if (opzione == 'c'){ // Minimo 

      char scelta;
      std::cout << "\nScegli l'operazione che vuoi effettuare sul minimo :\n "<< std::endl;
      std::cout<<"1->Lettura non distruttiva \n2->Rimozione \n3->Rimozione con lettura \nq->Torna indietro"<< std::endl;
      std::cin >>scelta;

      switch(scelta){
        case '1':{
	  MapPreOrder(BinarySearchTreeString,&MapPrint<std::string>,0);
	  std::string elemento=BinarySearchTreeString.Min();
	   std::cout << "Il minimo è: "<< elemento <<std::endl;
	   MapPreOrder(BinarySearchTreeString,&MapPrint<std::string>,0);
           break;
           }
        case '2':{
	  MapPreOrder(BinarySearchTreeString,&MapPrint<std::string>,0);
           BinarySearchTreeString.RemoveMin();

	   std::cout << "Il minimo è stato rimosso\n";
           MapPreOrder(BinarySearchTreeString,&MapPrint<std::string>,0);
           break;
           }
       case '3': {
             MapPreOrder(BinarySearchTreeString, &MapPrint<std::string>, 0);
	     std::string elemento = BinarySearchTreeString.MinNRemove();
	     std::cout << "Il minimo è stato rimosso\n";
             MapPreOrder(BinarySearchTreeString, &MapPrint<std::string>, 0);
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
      std::cout<< "\tConcatenazione delle stringhe con lunghezza minore di n(g)\n";
      std::cout<< "\tUscita(q)\n";
    }
    if (opzione == 'd'){ // Massimo
      char scelta;
      std::cout << "\nScegli l'operazione che vuoi effettuare sul massimo :\n "<< std::endl;
      std::cout<<"1->Lettura non distruttiva \n2->Rimozione \n3->Rimozione con lettura \nq->Torna indietro"<< std::endl;
      std::cin >>scelta;

      switch(scelta){
        case '1':{
	  MapPreOrder(BinarySearchTreeString,&MapPrint<std::string>,0);
	  std::string elemento=BinarySearchTreeString.Max();
	   std::cout << "Il massimo è: "<< elemento <<std::endl;
	   MapPreOrder(BinarySearchTreeString,&MapPrint<std::string>,0);
           break;
           }
        case '2':{
	  MapPreOrder(BinarySearchTreeString,&MapPrint<std::string>,0);
           BinarySearchTreeString.RemoveMax();

	   std::cout << "Il massimo è stato rimosso\n";
           MapPreOrder(BinarySearchTreeString,&MapPrint<std::string>,0);
           break;
           }
           case '3': {
             MapPreOrder(BinarySearchTreeString, &MapPrint<std::string>, 0);
	     std::string elemento = BinarySearchTreeString.MaxNRemove();
	     std::cout << "Il massimo è stato rimosso\n";
             MapPreOrder(BinarySearchTreeString, &MapPrint<std::string>, 0);
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
      std::cout<< "\tConcatenazione delle stringhe con lunghezza minore di n(g)\n";
      std::cout<< "\tUscita(q)\n";
    }
    if (opzione == 'e'){ // Predecessore
      
      char scelta;
      std::string valore;
      MapPreOrder(BinarySearchTreeString,&MapPrint<std::string>,0);
      std::cout << "\nInserisci l'elemento di cui vuoi esaminare il predecessore :\n "<< std::endl;
      std::cin>>valore;

      std::cout << "\nScegli l'operazione che vuoi effettuare sul predecessore dell'elemento scelto :\n "<< std::endl;
      std::cout<<"1->Lettura non distruttiva \n2->Rimozione \n3->Rimozione con lettura \nq->Torna indietro"<< std::endl;
      std::cin >>scelta;

      switch (scelta) {
      case '1': {
	std::string elemento = BinarySearchTreeString.Predecessor(valore);
	std::cout << "\n\nIl predecesore dell'elemento scelto e': " << elemento << "\n";
	MapPreOrder(BinarySearchTreeString, &MapPrint<std::string>, 0);
	break;
      }
      case '2': {
	MapPreOrder(BinarySearchTreeString, &MapPrint<std::string>, 0);
	BinarySearchTreeString.RemovePredecessor(valore);
	std::cout << "\n\nIl predecessore dell'elemento scelto è stato rimosso\n" << std::endl;
	MapPreOrder(BinarySearchTreeString, &MapPrint<std::string>, 0);
	break;
      }
      case '3': {
	MapPreOrder(BinarySearchTreeString, &MapPrint<std::string>, 0);
	std::string elemento = BinarySearchTreeString.PredecessorNRemove(valore);
	std::cout << "\n\nIl predecessore è stato rimosso\n" << std::endl;
	MapPreOrder(BinarySearchTreeString, &MapPrint<std::string>, 0);
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
      std::cout<< "\tConcatenazione delle stringhe con lunghezza minore di n(g)\n";
      std::cout<< "\tUscita(q)\n";

    }
    if (opzione == 'f'){ // Successore
      
      char scelta;
      std::string valore;
      MapPreOrder(BinarySearchTreeString,&MapPrint<std::string>,0);
      std::cout << "\nInserisci l'elemento di cui vuoi esaminare il successore :\n "<< std::endl;
      std::cin>>valore;

      std::cout << "\nScegli l'operazione che vuoi effettuare sul successore dell'elemento scelto :\n "<< std::endl;
      std::cout<<"1->Lettura non distruttiva \n2->Rimozione \n3->Rimozione con lettura \nq->Torna indietro"<< std::endl;
      std::cin >>scelta;

      switch (scelta) {
      case '1': {
	std::string elemento = BinarySearchTreeString.Predecessor(valore);
	std::cout << "\n\nIl successore dell'elemento scelto e': " << elemento << "\n";
	MapPreOrder(BinarySearchTreeString, &MapPrint<std::string>, 0);
	break;
      }
      case '2': {
	MapPreOrder(BinarySearchTreeString, &MapPrint<std::string>, 0);
	BinarySearchTreeString.RemovePredecessor(valore);
	std::cout << "\n\nIl successore dell'elemento scelto è stato rimosso\n" << std::endl;
	MapPreOrder(BinarySearchTreeString, &MapPrint<std::string>, 0);
	break;
      }
      case '3': {
	MapPreOrder(BinarySearchTreeString, &MapPrint<std::string>, 0);
	std::string elemento = BinarySearchTreeString.PredecessorNRemove(valore);
	std::cout << "\n\nIl successore è stato rimosso\n" << std::endl;
	MapPreOrder(BinarySearchTreeString, &MapPrint<std::string>, 0);
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
      std::cout<< "\tConcatenazione delle stringhe con lunghezza minore di n(g)\n";
      std::cout<< "\tUscita(q)\n";
    }
    if (opzione == 'g'){ // Concatenazione delle stringhe con lunghezza minore di n
      lasd::BTBreadthIterator<std::string> Iteratore(BinarySearchTreeString);
      int n;
      int j=0;
      std::cin >> n;
      std::string val="";

      while (j<dim){
	if (3 < n){
	  val=(*Iteratore)+val;
	}
	++Iteratore;
	j++;
      }
      if (val == "") {

	std::cout << "Non ci sono elementi con lunghezza minore o pari a n";
      } else {
	std::cout << "Non ci sono elementi con lunghezza minore o pari a n";
      }


      MapPreOrder(BinarySearchTreeString, &MapPrint<std::string> , 0);

      OperazioniDaEseguire();
      std::cout<< "\tConcatenazione delle stringhe con lunghezza minore di n(g)\n";
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
