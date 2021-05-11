#include <iostream>
#include "../container/container.hpp"
#include "../list/list.hpp"
#include <random>

using namespace std;

int main(){
  
  lasd::List<int> list;
  //cout << list.Empty() << endl;
  
  
  for (uint i = 0; i < 10; i++){
    list.InsertAtBack(i);
  }

  cout << "Vuota?"<< list.Empty() << endl;
  cout << "Coda:" << list.Back() << endl;
  cout << "Testa" << list.Front() << endl;

  for (uint i = 0; i < 10; i++){
    cout << list.Exists(i) << endl;
  }

  std::cout << "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~" << std::endl;
  std::cout << "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~" << std::endl;
  std::cout << "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~" << std::endl;
  std::cout << "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~" << std::endl;
  std::cout << "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~" << std::endl;

  
  lasd::List<int> list2(list);

  cout << "Vuota?"<< list2.Empty() << endl;
  cout << "Coda:" << list2.Back() << endl;
  cout << "Testa" << list2.Front() << endl;

  for (uint i = 0; i < 10; i++){
    cout << list.Exists(i) << endl;
  }
  
  cout << "Vuota?"<< list2.Empty() << endl;
  std::cout << "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~" << std::endl;
  std::cout << "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~" << std::endl;
  std::cout << "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~" << std::endl;
  std::cout << "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~" << std::endl;
}
