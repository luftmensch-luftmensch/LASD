
#ifndef LIST_HPP
#define LIST_HPP

/* ************************************************************************** */

#include "../container/container.hpp"
#include <stdexcept>
#include <iostream>

/* ************************************************************************** */

namespace lasd {

/* ************************************************************************** */

template <typename Data>
class List : virtual public LinearContainer<Data>, virtual  public MappableContainer<Data>, virtual public FoldableContainer<Data>{

private:


protected:

  using LinearContainer<Data>::dim;

  struct Node
  {

    Data elem;
    struct Node* next;

    /* ********************************************************************** */

    // Default constructors node
    Node() = default;

    // Specific constructor
    Node(const Data&);

    // Specific constructors ( move )
    Node(Data&&) noexcept;


    /* ********************************************************************** */

    // Copy constructor
    Node(const Node&);

    // Move constructor
    Node(Node&&) noexcept;

    /* ********************************************************************** */

    // Destructor
    virtual ~Node() = default;

    /* ********************************************************************** */

    // Comparison operators
    bool operator==(const Node&) const noexcept;
    bool operator!=(const Node&) const noexcept;

    /* ********************************************************************** */

    // Specific member functions



  };


public:

  // Default constructor
  List();

  /* ************************************************************************ */

  // Specific constructor
  List(const LinearContainer<Data>&); // A list obtained from a LinearContainer

  /* ************************************************************************ */

  // Copy constructor
  List(const List&);

  // Move constructor
  List(List&&) noexcept;

  /* ************************************************************************ */

  // Destructor
  ~List();

  /* ************************************************************************ */

  // Copy assignment
  List& operator=(const List&);

  // Move assignment
  List& operator=(List&&) noexcept;

  /* ************************************************************************ */

  // Comparison operators
  bool operator==(const List&) const noexcept;
  bool operator!=(const List&) const noexcept;

  /* ************************************************************************ */

  // Specific member functions

  void InsertAtFront(const Data&); // Copy of the value
  void InsertAtFront(Data&&) noexcept; // Move of the value
  void RemoveFromFront(); // (must throw std::length_error when empty)
  Data& FrontNRemove(); // (must throw std::length_error when empty)

  void InsertAtBack(const Data&); // Copy of the value
  void InsertAtBack(Data&&) noexcept; // Move of the value

  /* ************************************************************************ */

  // Specific member functions (inherited from Container)

  void Clear() override; // Override Container member

  /* ************************************************************************ */

  // Specific member functions (inherited from LinearContainer)

  Data& Front() const override; // Override LinearContainer member (must throw std::length_error when empty)
  Data& Back() const override; // Override LinearContainer member (must throw std::length_error when empty)

  Data& operator[](const unsigned long) const override; // Override LinearContainer member (must throw std::out_of_range when out of range)

  /* ************************************************************************ */

  // Specific member functions (inherited from MappableContainer)

  using typename MappableContainer<Data>::MapFunctor;

  virtual void MapPreOrder(MapFunctor, void*) override; // Override MappableContainer member
  virtual void MapPostOrder(MapFunctor, void*) override; // Override MappableContainer member

  /* ************************************************************************ */

  // Specific member functions (inherited from FoldableContainer)

  using typename FoldableContainer<Data>::FoldFunctor;

  void FoldPreOrder(FoldFunctor, const void*, void*) const override;  // Override FoldableContainer member
  void FoldPostOrder(FoldFunctor, const void*, void*) const override; // Override FoldableContainer member

protected:

  // Auxiliary member functions (for MappableContainer)

  virtual void MapPreOrder(MapFunctor, void*, Node*);  // Accessory function executing from one point of the list onwards
  virtual void MapPostOrder(MapFunctor, void*, Node*); // Accessory function executing from one point of the list onwards

  /* ************************************************************************ */

  // Auxiliary member functions (for FoldableContainer)

  void FoldPreOrder(FoldFunctor, const void*, void*, Node*) const;  // Accessory function executing from one point of the list onwards
  void FoldPostOrder(FoldFunctor, const void*, void*, Node*) const; // Accessory function executing from one point of the list onwards

  struct Node* First;
  struct Node* Last;

};

/* ************************************************************************** */
}
#include "list.cpp"
#endif
