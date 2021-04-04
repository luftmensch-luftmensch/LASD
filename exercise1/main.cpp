
#include "zlasdtest/test.hpp"
#include "zmytest/test.hpp"

/* ************************************************************************** */

#include <iostream>

/* ************************************************************************** */

int main() {
  std::cout << "Lasd Libraries 2021" << std::endl;
  int scelta;
  std::cout<<"Scegli il tipo di test che vuoi fare:"<<std::endl;
  std::cout<<"1) Test professore"<<std::endl;
  std::cout<<"2) Test studente"<<std::endl;
  std::cin>>scelta;
  if(scelta == 1){
    std::cout<<""<<std::endl;
    lasdtest(); // To call in the menu of your library test!
  }
  if(scelta == 2){
    std::cout<<""<<std::endl;
    miotest();
  }
  
  return 0;
}
