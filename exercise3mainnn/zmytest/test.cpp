#include "test.hpp"
#include "../vector/vector.hpp"
#include "../list/list.hpp"
#include "../binarytree/lnk/binarytreelnk.hpp"
#include <iostream>
#include "../zmytest/container/container.hpp"
#include "../container/container.hpp"
#include "../binarytree/vec/binarytreevec.hpp"

void mytest(){
  lasd::Vector<int> vec(5);
  vec[0]=1;
  vec[1]=2;
  vec[2]=3;
  vec[3]=4;
  vec[4]=5;
  lasd::BinaryTreeVec<int> bt(vec);
  //std::cout 
  lasd::BTInOrderIterator<int> itr(bt);
  std::cout<< *itr <<std::endl;
  ++itr;
  std::cout<< *itr <<std::endl;
  ++itr;
  std::cout<< *itr <<std::endl;
  ++itr;
  std::cout<< *itr <<std::endl;
  ++itr;
  std::cout<< *itr <<std::endl;
  ++itr;

}
