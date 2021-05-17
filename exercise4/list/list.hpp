
#ifndef LIST_HPP
#define LIST_HPP

/* ************************************************************************** */

#include "../container/container.hpp"

/* ************************************************************************** */

namespace lasd {

/* ************************************************************************** */

template <typename Data>
class List : virtual public LinearContainer<Data>, virtual public MappableContainer<Data>,virtual public FoldableContainer<Data>{

private:

  // ...

protected:

  using LinearContainer<Data>::dim;

  struct Node
  {

    Data elemento;
    struct Node* next;

    /* ********************************************************************** */

    // Default constructors node
    Node() = default;

    // Specific constructors
    Node(const Data&);

    // Specific constructors move
    Node(Data&&) noexcept;


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

  };

  // ...

public:

  // Default constructor
  List();

  // Specific constructor
  List(const LinearContainer<Data>&); // A list obtained from a LinearContainer
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

  void RemoveFromFront();
  Data& FrontNRemove();
  void InsertAtFront(const Data&);
  void InsertAtFront(Data&&) noexcept; // Move of the value

  void InsertAtBack(const Data&); // Copy of the value
  void InsertAtBack(Data&&) noexcept; // Move of the value

  /* ************************************************************************ */

  // Specific member functions (inherited from Container)

  void Clear() override; // Override Container member

  /* ************************************************************************ */

  // Specific member functions (inherited from LinearContainer)

  Data& Front() const override;
  Data& Back() const override;

  Data& operator[](const unsigned long)const override;

  /* ************************************************************************ */

  // Specific member functions (inherited from SearchableContainer)

  using typename MappableContainer<Data>::MapFunctor;
  virtual void MapPreOrder(MapFunctor, void*) override;
  virtual void MapPostOrder(MapFunctor, void*) override;

  using typename FoldableContainer<Data>::FoldFunctor;
  void FoldPreOrder(FoldFunctor, const void*, void*) const override;
  void FoldPostOrder(FoldFunctor, const void*, void*) const override;


protected:

  virtual void MapPreOrder(MapFunctor, void*, Node*);
  virtual void MapPostOrder(MapFunctor, void*, Node*);

  void FoldPreOrder(FoldFunctor, const void*, void*, Node*) const;
  void FoldPostOrder(FoldFunctor, const void*, void*, Node*) const;

  struct Node* First;
  struct Node* Last;



};

/* ************************************************************************** */

}

#include "list.cpp"

#endif
