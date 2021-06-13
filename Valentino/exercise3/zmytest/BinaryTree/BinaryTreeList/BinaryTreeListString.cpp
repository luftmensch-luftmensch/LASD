#include <iostream>
#include <random>
#include "../../../binarytree/binarytree.hpp"
#include "../../../binarytree/lnk/binarytreelnk.hpp"
#include "../../container/container.hpp"
#include "binarytreelist.hpp"
void BinaryTreeListString(){
  
  uint dim;
  std::string elemento;
  uint j = 0;
  bool quit = false;
  char opzione;

  std::cout << "Inserire la dimensione del binarytree di stringhe" << std::endl;
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
  lasd::BinaryTreeLnk<std::string> BinaryTreeString(VettoreString);

  OperazioniDaEseguireList();
  std::cout<< "\tCalcolo della concatenazione delle stringhe di lunghezze <= n(e)\n";
  std::cout<< "\tCalcolo della concatenazione delle stringhe in testa di una specifica stringa(f)\n";
  std::cout<< "\tUscita(q)\n";
  while (opzione != 'q') {
    std::cin >> opzione;

    if ((opzione != '1') && (opzione != '2') && (opzione != '3') &&
	(opzione != '4') && (opzione != '5') && (opzione != '6') &&
	(opzione != '7') &&  (opzione != '8') && (opzione != '9') &&
	(opzione != 'a') &&  (opzione != 'b') && (opzione != 'c') &&
	(opzione != 'd') && (opzione != 'e') && (opzione != 'f') &&
	(opzione != 'q')) {
      std::cout << "ERRORE: opzione non valida\n";
    }
    if (opzione == '1'){ // Visualizzazione in Pre-Order
      MapPreOrder(BinaryTreeString, &MapPrint<std::string> , 0);
      std::cout << "\n";
      OperazioniDaEseguireList();
      std::cout<< "\tCalcolo della concatenazione delle stringhe di lunghezze <= n(e)\n";
      std::cout<< "\tCalcolo della concatenazione delle stringhe in testa di una specifica stringa(f)\n";
      std::cout<< "\tUscita(q)\n";
    }

    if (opzione == '2'){ // Visualizzazione in Post-Order
      MapPostOrder(BinaryTreeString, &MapPrint<std::string> , 0);
      std::cout << "\n";
      OperazioniDaEseguireList();
      std::cout<< "\tCalcolo della concatenazione delle stringhe di lunghezze <= n(e)\n";
      std::cout<< "\tCalcolo della concatenazione delle stringhe in testa di una specifica stringa(f)\n";
      std::cout<< "\tUscita(q)\n";
    }

    if (opzione == '3'){ // Visualizzazione Inorder
      MapInOrder(BinaryTreeString, &MapPrint<std::string> , 0);
      std::cout << "\n";
      OperazioniDaEseguireList();
      std::cout<< "\tCalcolo della concatenazione delle stringhe di lunghezze <= n(e)\n";
      std::cout<< "\tCalcolo della concatenazione delle stringhe in testa di una specifica stringa(f)\n";
      std::cout<< "\tUscita(q)\n";
    }

    if (opzione == '4'){ // Visualizzazione in Ampiezza
      MapBreadth(BinaryTreeString, &MapPrint<std::string> , 0);
      std::cout << "\n";
      OperazioniDaEseguireList();
      std::cout<< "\tCalcolo della concatenazione delle stringhe di lunghezze <= n(e)\n";
      std::cout<< "\tCalcolo della concatenazione delle stringhe in testa di una specifica stringa(f)\n";
      std::cout<< "\tUscita(q)\n";
    }

    if (opzione == '5'){ // Controllo di esistenza di un dato valore nella struttura
      std::cout << "Inserisci l'elemento da ricercare: ";
      std::cin >> elemento;
      if (BinaryTreeString.Exists(elemento)){
	std::cout << "Elemento trovato" << std::endl;
      } else{
	std::cout << "Elemento non trovato" << std::endl;
      }
      std::cout << "\n";
      OperazioniDaEseguireList();

      std::cout<< "\tCalcolo della concatenazione delle stringhe di lunghezze <= n(e)\n";
      std::cout<< "\tCalcolo della concatenazione delle stringhe in testa di una specifica stringa(f)\n";
      std::cout<< "\tUscita(q)\n";
    }

    if (opzione == '6'){ // Controllo di vuotezza della  Struttura
      if (BinaryTreeString.Empty()){
	std::cout << "La Struttura è vuota"<< std::endl;
      } else{
	std::cout << "La Struttura non è vuota" << std::endl;
      }

      std::cout << "\n";
      OperazioniDaEseguireList();

      std::cout<< "\tCalcolo della concatenazione delle stringhe di lunghezze <= n(e)\n";
      std::cout<< "\tCalcolo della concatenazione delle stringhe in testa di una specifica stringa(f)\n";
      std::cout<< "\tUscita(q)\n";
    }
    if (opzione == '7'){
      std::cout << "La dimensione della struttura è " << BinaryTreeString.Size() << std::endl;

      std::cout << "\n";
      OperazioniDaEseguireList();
      std::cout<< "\tCalcolo della concatenazione delle stringhe di lunghezze <= n(e)\n";
      std::cout<< "\tCalcolo della concatenazione delle stringhe in testa di una specifica stringa(f)\n";
      std::cout<< "\tUscita(q)\n";
    }
    if (opzione == '8'){ // Svuotamento della struttura
      BinaryTreeString.Clear();
      std::cout << "Struttura svuotata" << std::endl;

      std::cout << "\n";
      OperazioniDaEseguireList();
      std::cout<< "\tCalcolo della concatenazione delle stringhe di lunghezze <= n(e)\n";
      std::cout<< "\tCalcolo della concatenazione delle stringhe in testa di una specifica stringa(f)\n";
      std::cout<< "\tUscita(q)\n";
    }
    if (opzione == '9'){ // Esplorazione in lettura e/o scrittura

      lasd::BinaryTree<std::string>* BinaryTreeStringCopia=&BinaryTreeString;
        bool check=true;
        typename lasd::BinaryTree<std::string>::Node* current = &BinaryTreeStringCopia->Root();
        while(current!=nullptr && check==true){
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
              check=false;
              break;
            default:
              std::cout << "\033[2J\033[1;1H";
              std::cout<< "Scelta errata. Riprova. \n\n " <<std::endl;
            }
        }
      std::cout << "\n";
      OperazioniDaEseguireList();
      std::cout<< "\tCalcolo della concatenazione delle stringhe di lunghezze <= n(e)\n";
      std::cout<< "\tCalcolo della concatenazione delle stringhe in testa di una specifica stringa(f)\n";
      std::cout<< "\tUscita(q)\n";
    }
    if (opzione == 'a'){ // Navigazione in  Pre-Order
      
      std::cout<<"Navigazione in PreOrder:"<<std::endl;

      lasd::BTPreOrderIterator<std::string> Iteratore(BinaryTreeString);
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
      OperazioniDaEseguireList();
      std::cout<< "\tCalcolo della concatenazione delle stringhe di lunghezze <= n(e)\n";
      std::cout<< "\tCalcolo della concatenazione delle stringhe in testa di una specifica stringa(f)\n";
      std::cout<< "\tUscita(q)\n";
    }

    if (opzione == 'b'){ // Navigazione in Post-Order

      std::cout<<"Navigazione in PreOrder:"<<std::endl;

      lasd::BTPostOrderIterator<std::string> Iteratore(BinaryTreeString);
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
      
      OperazioniDaEseguireList();
      std::cout<< "\tCalcolo della concatenazione delle stringhe di lunghezze <= n(e)\n";
      std::cout<< "\tCalcolo della concatenazione delle stringhe in testa di una specifica stringa(f)\n";
      std::cout<< "\tUscita(q)\n";
    }

    if (opzione == 'c'){ // Navigazione InOrder
      std::cout<<"Navigazione in PreOrder:"<<std::endl;

      lasd::BTInOrderIterator<std::string> Iteratore(BinaryTreeString);
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

      OperazioniDaEseguireList();
      std::cout<< "\tCalcolo della concatenazione delle stringhe di lunghezze <= n(e)\n";
      std::cout<< "\tCalcolo della concatenazione delle stringhe in testa di una specifica stringa(f)\n";
      std::cout<< "\tUscita(q)\n";
    }

    if (opzione == 'd'){ // Navigazione in Ampiezza

      std::cout<<"Navigazione in PreOrder:"<<std::endl;

      lasd::BTBreadthIterator<std::string> Iteratore(BinaryTreeString);
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

      OperazioniDaEseguireList();
      std::cout<< "\tCalcolo della concatenazione delle stringhe di lunghezze <= n(e)\n";
      std::cout<< "\tCalcolo della concatenazione delle stringhe in testa di una specifica stringa(f)\n";
      std::cout<< "\tUscita(q)\n";
      
    }

    if (opzione == 'e'){ // Calcolo della concatenazione delle stringhe di lunghezze <= n

      lasd::BTBreadthIterator<std::string> Iteratore(BinaryTreeString);
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

      std::cout << "\n";
      OperazioniDaEseguireList();
      std::cout<< "\tCalcolo della concatenazione delle stringhe di lunghezze <= n(e)\n";
      std::cout<< "\tCalcolo della concatenazione delle stringhe in testa di una specifica stringa(f)\n";
      std::cout<< "\tUscita(q)\n";
    }

    if (opzione == 'f'){ // Calcolo della concatenazione delle stringhe in testa
      std::string stringaDaInserire;
      int n=0;
      lasd::BTBreadthIterator<std::string> Iteratore(BinaryTreeString);
      std::cin >> stringaDaInserire;

      while(n<dim){
	(*Iteratore) = stringaDaInserire+(*Iteratore);

	++Iteratore;
	n++;
      }

      MapPreOrder(BinaryTreeString, &MapPrint<std::string> , 0);

      OperazioniDaEseguireList();

      std::cout<< "\tCalcolo della concatenazione delle stringhe di lunghezze <= n(e)\n";
      std::cout<< "\tCalcolo della concatenazione delle stringhe in testa di una specifica stringa(f)\n";
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
