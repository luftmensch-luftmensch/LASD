
#ifndef VECTOR_HPP
#define VECTOR_HPP

/* ************************************************************************** */

#include "../container/container.hpp"

/* ************************************************************************** */

namespace lasd {

/* ************************************************************************** */

template <typename Data>
class Vector { // Must extend LinearContainer<Data>, MappableContainer<Data>, and FoldableContainer<Data>

private:

  // ...

protected:

  // using LinearContainer<Data>::???;

  // ...

public:

  // Default constructor
  // Vector() specifiers;

  /* ************************************************************************ */

  // Specific constructors
  // Vector(argument) specifiers; // A vector with a given initial dimension
  // Vector(argument) specifiers; // A vector obtained from a LinearContainer

  /* ************************************************************************ */

  // Copy constructor
  // Vector(argument) specifiers;

  // Move constructor
  // Vector(argument) specifiers;

  /* ************************************************************************ */

  // Destructor
  // ~Vector() specifiers;

  /* ************************************************************************ */

  // Copy assignment
  // type operator=(argument) specifiers;

  // Move assignment
  // type operator=(argument) specifiers;

  /* ************************************************************************ */

  // Comparison operators
  // type operator==(argument) specifiers;
  // type operator!=(argument) specifiers;

  /* ************************************************************************ */

  // Specific member functions

  // type Resize(argument) specifiers; // Resize the vector to a given size

  /* ************************************************************************ */

  // Specific member functions (inherited from Container)

  // type Clear() specifiers; // Override Container member

  /* ************************************************************************ */

  // Specific member functions (inherited from LinearContainer)

  // type Front() specifiers; // Override LinearContainer member (must throw std::length_error when empty)
  // type Back() specifiers; // Override LinearContainer member (must throw std::length_error when empty)

  // type operator[](argument) specifiers; // Override LinearContainer member (must throw std::out_of_range when out of range)

  /* ************************************************************************ */

  // Specific member functions (inherited from MappableContainer)

  // using typename MappableContainer<Data>::MapFunctor;

  // type MapPreOrder(arguments) specifiers; // Override MappableContainer member
  // type MapPostOrder(arguments) specifiers; // Override MappableContainer member

  /* ************************************************************************ */

  // Specific member functions (inherited from FoldableContainer)

  // using typename FoldableContainer<Data>::FoldFunctor;

  // type FoldPreOrder(arguments) specifiers; // Override FoldableContainer member
  // type FoldPostOrder(arguments) specifiers; // Override FoldableContainer member

};

/* ************************************************************************** */

}

#include "vector.cpp"

#endif
