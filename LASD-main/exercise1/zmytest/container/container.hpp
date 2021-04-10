
#ifndef CONTAINERTEST_HPP
#define CONTAINERTEST_HPP
#include<iostream>

#include "../../container/container.hpp"

/* ************************************************************************** */

// Container member functions!

void Empty(unsigned int&, unsigned int&, const lasd::Container&, bool);

void Size(unsigned int&, unsigned int&, const lasd::Container&, bool, unsigned long);

/* ************************************************************************** */

// LinearContainer member functions!

template <typename Data>
void GetFront(const lasd::LinearContainer<Data>& con){
  try{
    std::cout << "Il Front del Linear container: " << con.Front()<< std::endl;

  }catch(std::exception e){
    std::cout << std::endl << "Eccezione di tipo: " << e.what() << "!" << std::endl;

  }
}

template <typename Data>
void GetBack(const lasd::LinearContainer<Data>& con){
  try{
    std::cout << "Il Back del Linear container: " << con.Back()<< std::endl;

  }catch(std::exception e){
    std::cout << std::endl << "Eccezione di tipo: " << e.what() << "!" << std::endl;

  }
}

template <typename Data>
void GetAt(lasd::LinearContainer<Data>& con, const unsigned long& index) {
  try {
    std::cout << "All'indice " << index << " è presente il valore " << con[index] << std::endl;
  } catch(std::exception e) {
    std::cout << std::endl << "Eccezione di tipo: " << e.what() << "!" << std::endl;
  }
}

/* ************************************************************************** */

// TestableContainer member functions!

template <typename Data>
void Exists(const lasd::TestableContainer<Data>& con, const Data& val) {
  if (con.Exists(val)){
     std::cout << "Elemento trovato" << std::endl;
   }else{
     std::cout << "Elemento non trovato" << std::endl;
   }
}


/* ************************************************************************** */

// MappableContainer member functions!

template <typename Data, typename Parameter>
void MapPreOrder(lasd::MappableContainer<Data>& con, typename lasd::MappableContainer<Data>::MapFunctor fun, const Parameter& inipar) {
  Parameter par = {inipar};
  try {
    con.MapPreOrder(fun, &par);
  }
  catch(std::exception exc) {
    std::cout << exc.what()<< std::endl;
  }
}

template <typename Data>
void MapPrint(const Data& dat, void* _) {
  std::cout << dat << " ";
}



template <typename Data>
void MapIncrement(Data& dat, void* _) {
  dat++;
}

template <typename Data>
void MapIncrementNPrint(Data& dat, void* _) {
  std::cout << dat++ << "->" << dat << "; ";
}

template <typename Data>
void MapNxN(Data& dat, void* _) {
  dat= dat*dat;
}

template <typename Data>
void MapDouble(Data& dat, void* _) {
  dat *= 2;
}

template <typename Data>
void MapDoubleNPrint(Data& dat, void* _) {
  std::cout << dat << "->" << (dat *= 2) << "; ";
}

template <typename Data>
void MapInvert(Data& dat, void* _) {
  dat = -dat;
}

template <typename Data>
void MapInvertNPrint(Data& dat, void* _) {
  std::cout << dat << "->" << (dat = -dat) << "; ";
}

template <typename Data>
void MapParityInvert(Data& dat, void* _) {
  if (dat % 2 != 0) { dat = -dat; }
}

void MapStringAppend(std::string&, void*);

/* ************************************************************************** */

// FoldableContainer member functions!

template <typename Data, typename Parameter, typename Value>
void FoldPreOrder(const lasd::FoldableContainer<Data>& con, typename lasd::FoldableContainer<Data>::FoldFunctor fun, const Parameter& inipar, const Value& inival, const Value& finval) {
  unsigned int index=0;
  Parameter par = {inipar};
  Value val = inival;
  try {
    std::cout << " Executing fold in pre order - ";
    con.FoldPreOrder(fun, &par, &val);
    std::cout << "obtained value is \"" << val << "\": ";
  } catch(std::exception exc) {
    std::cout << exc.what() << std::endl;
  }
}

template <typename Data>
void FoldAdd(const Data& dat, const void* _, void* acc) {
  *((Data*) acc) += dat;
}

template <typename Data>
void FoldMultiply(const Data& dat, const void* _, void* acc) {
  *((Data*) acc) *= dat;
}

void FoldParity(const int&, const void*, void*);

void FoldStringConcatenate(const std::string&, const void*, void*);


#endif
