#include <iostream>
void Scelta(){
  std::cout<<"Seleziona il tipo di struttura\nVettore (1)\nLista(2)"<< std::endl;
}
void menu(){
  std::cout<<"#################################\nBenvenuto nel test personale!" <<std::endl;
  Scelta();
  char scelta;
  while(scelta != 'q'){
    std::cin >> scelta;
    switch(scelta){
    case '1':
      std::cout<<"Vettore (1)"<< std::endl;
      break;
    case '2':
      std::cout<<"Lista (1)"<< std::endl;
      break;
    case 'q':
      std::cout << std::endl << "Goodbye!" << std::endl;
    default:
      std::cout<<"Scelta errata"<< std::endl;
      Scelta();
      break;
    }
  }
}
