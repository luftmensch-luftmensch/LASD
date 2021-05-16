#include <iostream>
#include <random>
#include "../../../binarytree/binarytree.hpp"
#include "../../../binarytree/lnk/binarytreelnk.hpp"
#include "../../container/container.hpp"
#include "binarytreelist.hpp"

void BinaryTreeListFloat(){
  uint dim, elemento;
  uint j = 0;
  bool quit = false;
  char opzione;

  std::cout << "Inserire la dimensione del binarytree di float" << std::endl;
  std::cin >> dim;

  std::cout << "\033[2J\033[1;1H"; // simil clear
  std::default_random_engine gen(std::random_device{}());
  std::uniform_real_distribution<float> dist(1.0, 100.0);
  lasd::Vector<float> VettoreFloat(dim);

  while(j < dim){
    VettoreFloat[j] = dist(gen);
    j++;
  }
  lasd::BinaryTreeLnk<float> BinaryTreeFloat(VettoreFloat);

  OperazioniDaEseguireList();
  std::cout<< "\tCalcolo del prodotto degli float maggiori di n(e)\n";
  std::cout<< "\tCalcolo della funzione 3n(f)\n";
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
      MapPreOrder(BinaryTreeFloat, &MapPrint<float> , 0);
      std::cout << "\n";
      OperazioniDaEseguireList();
      std::cout<< "\tCalcolo del prodotto degli float maggiori di n(e)\n";
      std::cout<< "\tCalcolo della funzione 3n(f)\n";
      std::cout<< "\tUscita(q)\n";
    }

    if (opzione == '2'){ // Visualizzazione in Post-Order
      MapPostOrder(BinaryTreeFloat, &MapPrint<float> , 0);
      std::cout << "\n";
      OperazioniDaEseguireList();
      std::cout<< "\tCalcolo del prodotto degli float maggiori di n(e)\n";
      std::cout<< "\tCalcolo della funzione 3n(f)\n";
      std::cout<< "\tUscita(q)\n";
    }

    if (opzione == '3'){ // Visualizzazione Inorder
      MapInOrder(BinaryTreeFloat, &MapPrint<float> , 0);
      std::cout << "\n";
      OperazioniDaEseguireList();
      std::cout<< "\tCalcolo del prodotto degli float maggiori di n(e)\n";
      std::cout<< "\tCalcolo della funzione 3n(f)\n";
      std::cout<< "\tUscita(q)\n";
    }

    if (opzione == '4'){ // Visualizzazione in Ampiezza
      MapBreadth(BinaryTreeFloat, &MapPrint<float> , 0);
      std::cout << "\n";
      OperazioniDaEseguireList();
      std::cout<< "\tCalcolo del prodotto degli float maggiori di n(e)\n";
      std::cout<< "\tCalcolo della funzione 3n(f)\n";
      std::cout<< "\tUscita(q)\n";
    }

    if (opzione == '5'){ // Controllo di esistenza di un dato valore nella struttura
      std::cout << "Inserisci l'elemento da ricercare: ";
      std::cin >> elemento;
      if (BinaryTreeFloat.Exists(elemento)){
	std::cout << "Elemento trovato" << std::endl;
      } else{
	std::cout << "Elemento non trovato" << std::endl;
      }
      std::cout << "\n";
      OperazioniDaEseguireList();

      std::cout<< "\tCalcolo del prodotto degli float maggiori di n(e)\n";
      std::cout<< "\tCalcolo della funzione 3n(f)\n";
      std::cout<< "\tUscita(q)\n";
    }

    if (opzione == '6'){ // Controllo di vuotezza della  Struttura
      if (BinaryTreeFloat.Empty()){
	std::cout << "La Struttura è vuota"<< std::endl;
      } else{
	std::cout << "La Struttura non è vuota" << std::endl;
      }

      std::cout << "\n";
      OperazioniDaEseguireList();

      std::cout<< "\tCalcolo del prodotto degli float maggiori di n(e)\n";
      std::cout<< "\tCalcolo della funzione 3n(f)\n";
      std::cout<< "\tUscita(q)\n";
    }
    if (opzione == '7'){
      std::cout << "La dimensione della struttura è " << BinaryTreeFloat.Size() << std::endl;

      std::cout << "\n";
      OperazioniDaEseguireList();
      std::cout<< "\tCalcolo del prodotto degli float maggiori di n(e)\n";
      std::cout<< "\tCalcolo della funzione 3n(f)\n";
      std::cout<< "\tUscita(q)\n";
    }
    if (opzione == '8'){ // Svuotamento della struttura
      BinaryTreeFloat.Clear();
      std::cout << "Struttura svuotata" << std::endl;

      std::cout << "\n";
      OperazioniDaEseguireList();
      std::cout<< "\tCalcolo del prodotto degli float maggiori di n(e)\n";
      std::cout<< "\tCalcolo della funzione 3n(f)\n";
      std::cout<< "\tUscita(q)\n";
    }
    if (opzione == '9'){ // Esplorazione in lettura e/o scrittura

        lasd::BinaryTree<float>* BinaryTreeFloatCopia=&BinaryTreeFloat;
        bool check=true;
        typename lasd::BinaryTree<float>::Node* current = &BinaryTreeFloatCopia->Root();
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
      std::cout<< "\tCalcolo del prodotto degli float maggiori di n(e)\n";
      std::cout<< "\tCalcolo della funzione 3n(f)\n";
      std::cout<< "\tUscita(q)\n";
    }
    if (opzione == 'a'){ // Navigazione in  Pre-Order
      
      std::cout<<"Navigazione in PreOrder:"<<std::endl;

       lasd::BTPreOrderIterator<float> Iteratore(BinaryTreeFloat);
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
      std::cout<< "\tCalcolo del prodotto degli float maggiori di n(a)\n";
      std::cout<< "\tCalcolo della funzione 3n(b)\n";
      std::cout<< "\tUscita(q)\n";
    }

    if (opzione == 'b'){ // Navigazione in Post-Order

      std::cout<<"Navigazione in PreOrder:"<<std::endl;

       lasd::BTPostOrderIterator<float> Iteratore(BinaryTreeFloat);
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
      std::cout<< "\tCalcolo del prodotto degli float maggiori di n(a)\n";
      std::cout<< "\tCalcolo della funzione 3n(b)\n";
      std::cout<< "\tUscita(q)\n";
    }

    if (opzione == 'c'){ // Navigazione InOrder
      std::cout<<"Navigazione in PreOrder:"<<std::endl;

       lasd::BTInOrderIterator<float> Iteratore(BinaryTreeFloat);
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
      std::cout<< "\tCalcolo del prodotto degli float maggiori di n(a)\n";
      std::cout<< "\tCalcolo della funzione 3n(b)\n";
      std::cout<< "\tUscita(q)\n";
    }

    if (opzione == 'd'){ // Navigazione in Ampiezza

      std::cout<<"Navigazione in PreOrder:"<<std::endl;

       lasd::BTBreadthIterator<float> Iteratore(BinaryTreeFloat);
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
      std::cout<< "\tCalcolo del prodotto degli float maggiori di n(a)\n";
      std::cout<< "\tCalcolo della funzione 3n(b)\n";
      std::cout<< "\tUscita(q)\n";
      
    }

    if (opzione == 'e'){ // Prodotto degli float maggiori di n

      lasd::BTBreadthIterator<float> Iteratore(BinaryTreeFloat);
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
	std::cout<<"Non ci sono elementi maggiori di N"<<std::endl;

      }
      else{
	std::cout<<"Il prodotto degli elementi maggiori di N e': "<<prod<<std::endl;
      }

      std::cout << "\n";
      OperazioniDaEseguireList();
      std::cout<< "\tCalcolo del prodotto degli float maggiori di n(a)\n";
      std::cout<< "\tCalcolo della funzione 3n(b)\n";
      std::cout<< "\tUscita(q)\n";
    }

    if (opzione == 'f'){ // Funzione 3n

      MapPreOrder(BinaryTreeFloat, &MapPrint<float> , 0);
      MapPreOrder(BinaryTreeFloat, &MapTriple<float> , 0);
      std::cout<<"\n\n"<<std::endl;
      
      MapPreOrder(BinaryTreeFloat, &MapPrint<float> , 0);
      std::cout << "\n";
      OperazioniDaEseguireList();

      std::cout<< "\tCalcolo del prodotto degli float maggiori di n(e)\n";
      std::cout<< "\tCalcolo della funzione 3n(f)\n";
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
