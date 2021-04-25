
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


protected:


  using List<Data>::dimensione;

public:

  // Default constructor
   StackLst();


  /* ************************************************************************ */

  // Specific constructor
  StackLst(const LinearContainer<Data>&); // A stack obtained from a LinearContainer

  /* ************************************************************************ */

  // Copy constructor
   StackLst(const StackLst&);

  // Move constructor
    StackLst(StackLst&&) noexcept;

  /* ************************************************************************ */

  // Destructor
    ~StackLst()=default;

  /* ************************************************************************ */

  // Copy assignment
     StackLst& operator=(const StackLst&);

  // Move assignment
     StackLst& operator=(StackLst&&) noexcept;

  /* ************************************************************************ */

  // Comparison operators
     bool operator==(const StackLst&) const noexcept;
     bool operator!=(const StackLst&) const noexcept;

  /* ************************************************************************ */

  // Specific member functions (inherited from Stack)

     void Push(const Data&) override; // Override Stack member (copy of the value)
     void Push(Data&&) override; // Override Stack member (move of the value)
     Data& Top() const override; // Override Stack member (must throw std::length_error when empty)
     void Pop() override; // Override Stack member (must throw std::length_error when empty)
     Data TopNPop() override; // Override Stack member (must throw std::length_error when empty)

  /* ************************************************************************ */

  // Specific member functions (inherited from Container)
     using List<Data>::Empty;
     using List<Data>::Size;
     using List<Data>::Clear;

};

/* ************************************************************************** */

}

#include "stacklst.cpp"

#endif
