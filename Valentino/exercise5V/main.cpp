#include <iostream>
#include "zlasdtest/test.hpp"
//#include "zmytest/test.hpp"

int main() {
  std::cout << "Lasd Libraries 2021" << std::endl;
  int scelta;
  std::cout<<"Seleziona il tipo di test da eseguire:"<<std::endl;
  std::cout<<"\tTest professore (1)\tTest Studente(2)"<<std::endl;
  std::cin>>scelta;
  if(scelta == 1){
    std::cout<<""<<std::endl;
    lasdtest();
  }
  if(scelta == 2){
    std::cout<<""<<std::endl;
    //testpersonale();
  }
  return 0;
}
