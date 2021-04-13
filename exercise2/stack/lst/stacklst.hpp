
#ifndef STACKLST_HPP
#define STACKLST_HPP

/* ************************************************************************** */

#include "../stack.hpp"
#include "../../list/list.hpp"

/* ************************************************************************** */

namespace lasd {

/* ************************************************************************** */

template <typename Data>
class StackLst : virtual public Stack<Data>, virtual protected List<Data> { // Must extend Stack<Data> and List<Data>

private:

  StackNode<Data>* top;

protected:


  using List<Data>::dim;

public:

  // Default constructor
   StackLst() {
     top=nullptr;
     size=0;
   }

  /* ************************************************************************ */

  // Specific constructor
  StackLst(const LinearContainer<Data>&); // A stack obtained from a LinearContainer

  /* ************************************************************************ */

  // Copy constructor
   StackLst(const StackLst&);

  // Move constructor
    StackLst(StackLst&&);

  /* ************************************************************************ */

  // Destructor
    ~StackLst();

  /* ************************************************************************ */

  // Copy assignment
     StackLst& operator=(const StackLst&);

  // Move assignment
     StackLst& operator=(StackLst&&);

  /* ************************************************************************ */

  // Comparison operators
     bool operator==(const StackLst&) const noexcept;
     bool operator!=(const StackLst&) const noexcept;

  /* ************************************************************************ */

  // Specific member functions (inherited from Stack)

     void Push(const Data&) override; // Override Stack member (copy of the value)
     void Push(Data&&) override; // Override Stack member (move of the value)
     void Top() override; // Override Stack member (must throw std::length_error when empty)
     void Pop() override; // Override Stack member (must throw std::length_error when empty)
     Data& TopNPop() override; // Override Stack member (must throw std::length_error when empty)

  /* ************************************************************************ */

  // Specific member functions (inherited from Container)

     void Clear() override; // Override Container member

};

/* ************************************************************************** */

}

#include "stacklst.cpp"

#endif
