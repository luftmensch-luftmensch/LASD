#include "zlasdtest/test.hpp"
#include "zmytest/menu.hpp"

/* ************************************************************************** */

#include <iostream>

/* ************************************************************************** */

int main() {
  std::cout << "Lasd Libraries 2021" << std::endl;
  int scelta;
  std::cout<<"Seleziona il tipo di test che vuoi effettuare: "<<std::endl;
  std::cout<<"\tTest Professore (1)\tTest Studente(2)"<<std::endl;
  std::cin>>scelta;
  if(scelta == 1){
    std::cout<<""<<std::endl;
    lasdtest(); // To call in the menu of your library test!
  }
  if(scelta == 2){
    std::system("clear");
    std::cout<<""<<std::endl;
    menu();
  }
  return 0;
}
