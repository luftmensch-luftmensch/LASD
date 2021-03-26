
#ifndef LIST_HPP
#define LIST_HPP

/* ************************************************************************** */

#include "../container/container.hpp"

/* ************************************************************************** */

namespace lasd {

/* ************************************************************************** */

template <typename Data>
class List { // Must extend LinearContainer<Data>, MappableContainer<Data>, and FoldableContainer<Data>

private:

  // ...

protected:

  // using LinearContainer<Data>::???;

  struct Node
  {

    // Data
    // ...

    /* ********************************************************************** */

    // Specific constructors
    // ...

    /* ********************************************************************** */

    // Copy constructor
    // ...

    // Move constructor
    // ...

    /* ********************************************************************** */

    // Destructor
    // ...

    /* ********************************************************************** */

    // Comparison operators
    // ...

    /* ********************************************************************** */

    // Specific member functions

    // ...

  };

  // ...

public:

  // Default constructor
  // List() specifiers;

  /* ************************************************************************ */

  // Specific constructor
  // List(argument) specifiers; // A list obtained from a LinearContainer

  /* ************************************************************************ */

  // Copy constructor
  // List(argument) specifiers;

  // Move constructor
  // List(argument) specifiers;

  /* ************************************************************************ */

  // Destructor
  // ~List() specifiers;

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

  // type InsertAtFront(argument) specifier; // Copy of the value
  // type InsertAtFront(argument) specifier; // Move of the value
  // type RemoveFromFront() specifier; // (must throw std::length_error when empty)
  // type FrontNRemove() specifier; // (must throw std::length_error when empty)

  // type InsertAtBack(argument) specifier; // Copy of the value
  // type InsertAtBack(argument) specifier; // Move of the value

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

protected:

  // Auxiliary member functions (for MappableContainer)

  // type MapPreOrder(arguments) specifiers; // Accessory function executing from one point of the list onwards
  // type MapPostOrder(arguments) specifiers; // Accessory function executing from one point of the list onwards

  /* ************************************************************************ */

  // Auxiliary member functions (for FoldableContainer)

  // type FoldPreOrder(arguments) specifiers; // Accessory function executing from one point of the list onwards
  // type FoldPostOrder(arguments) specifiers; // Accessory function executing from one point of the list onwards

};

/* ************************************************************************** */

}

#include "list.cpp"

#endif
