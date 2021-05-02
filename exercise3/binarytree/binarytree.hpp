
#ifndef BINARYTREE_HPP
#define BINARYTREE_HPP

/* ************************************************************************** */

#include "../container/container.hpp"

#include "../iterator/iterator.hpp"

#include "../queue/queue.hpp"
#include "../queue/vec/queuevec.hpp"
#include "../queue/lst/queuelst.hpp"

#include "../stack/stack.hpp"
#include "../stack/vec/stackvec.hpp"
#include "../stack/lst/stacklst.hpp"

/* ************************************************************************** */

namespace lasd {

/* ************************************************************************** */

template <typename Data>
class BinaryTree : virtual public InOrderMappableContainer<Data>,virtual public InOrderFoldableContainer<Data>, virtual public BreadthMappableContainer<Data>, virtual public BreadthFoldableContainer<Data>{ // Must extend InOrder/BreadthMappableContainer<Data> and InOrder/BreadthFoldableContainer<Data>

private:

protected:

  // using InOrder/BreadthMappableContainer<Data>::???;

  using Container::dim;

public:

  using Container::Empty;
  using Container::Size;

  struct Node {

  private:

  protected:


    // Comparison operators
       bool operator==(const Node&) const noexcept;// Comparison of abstract types is possible, but should not be visible.
       bool operator!=(const Node&) const noexcept;// Comparison of abstract types is possible, but should not be visible.


  public:

    //   friend class BinaryTree<Data>;



    /* ********************************************************************** */

    // Destructor
       virtual ~Node() = default;

    /* ********************************************************************** */

    // Copy assignment
       Node& operator=(const Node&)=delete; // Copy assignment of abstract types should not be possible.

    // Move assignment
       Node& operator=(Node&&) noexcept =delete; // Move assignment of abstract types should not be possible.

    /* ********************************************************************** */


    /* ********************************************************************** */

    // Specific member functions

       virtual Data& Element() noexcept =0; // Mutable access to the element (concrete function should not throw exceptions)
       virtual const Data& Element() const noexcept =0; // Immutable access to the element (concrete function should not throw exceptions)

       virtual bool isLeaf() noexcept; // (concrete function should not throw exceptions)
       virtual bool HasLeftChild() const  noexcept = 0; // (concrete function should not throw exceptions)
       virtual bool HasRightChild() const noexcept = 0; // (concrete function should not throw exceptions)

       virtual Node& LeftChild() const = 0; // (concrete function must throw std::out_of_range when not existent)
       virtual Node& RightChild() const = 0; // (concrete function must throw std::out_of_range when not existent)

  };

protected:

  /* ************************************************************************ */

  // Destructor
     virtual ~BinaryTree() noexcept = default;

  /* ************************************************************************ */

  // Copy assignment
     virtual BinaryTree& operator=(const BinaryTree&) = delete; // Copy assignment of abstract types should not be possible.

  // Move assignment
     virtual BinaryTree& operator=(BinaryTree&&) noexcept = delete; // Move assignment of abstract types should not be possible.

  /* ************************************************************************ */

  // Comparison operators
     virtual bool operator==(const BinaryTree&) const noexcept; // Comparison of abstract binary tree is possible.
     virtual bool operator!=(const BinaryTree&) const noexcept; // Comparison of abstract binary tree is possible.

  /* ************************************************************************ */

  // Specific member functions

     virtual Node const& Root() const = 0;
     virtual Node& Root() = 0; // (concrete function must throw std::length_error when empty)

  /* ************************************************************************ */



  // Specific member functions (inherited from MappableContainer)

     using typename MappableContainer<Data>::MapFunctor;

     virtual void MapPreOrder(MapFunctor, void*) noexcept override; // Override MappableContainer member
     virtual void MapPostOrder(MapFunctor, void*) noexcept override; // Override MappableContainer member

  /* ************************************************************************ */

  // Specific member functions (inherited from FoldableContainer)

     using typename FoldableContainer<Data>::FoldFunctor;

     virtual void FoldPreOrder(FoldFunctor, const void*, void*) const noexcept override; // Override FoldableContainer member
     virtual void FoldPostOrder(FoldFunctor, const void*, void*) const noexcept override; // Override FoldableContainer member

  /* ************************************************************************ */

  // Specific member functions (inherited from InOrderMappableContainer)

     virtual void MapInOrder(MapFunctor, void*) noexcept; // Override BreadthMappableContainer member (IN ORDER)

  /* ************************************************************************ */

  // Specific member functions (inherited from InOrderFoldableContainer)

     virtual void FoldInOrder(FoldFunctor, const void*, void*) const noexcept; // Override BreadthFoldableContainer member (IN ORDER)

  /* ************************************************************************ */

  // Specific member functions (inherited from BreadthMappableContainer)

     virtual void MapBreadth(MapFunctor, void*) noexcept override; // Override BreadthMappableContainer member

  /* ************************************************************************ */

  // Specific member functions (inherited from BreadthFoldableContainer)

     virtual void FoldBreadth(FoldFunctor, const void*, void*) const noexcept override; // Override BreadthFoldableContainer member

protected:

  // Auxiliary member functions (for MappableContainer)

     virtual void AuxMapPreOrder(MapFunctor, void*, Node*) noexcept; // Accessory function executing from one node of the tree
     virtual void AuxMapPostOrder(MapFunctor, void*, Node*) noexcept; // Accessory function executing from one node of the tree

  /* ************************************************************************ */

  // Auxiliary member functions (for FoldableContainer)

     virtual void AuxFoldPreOrder(FoldFunctor, const void*, void*, const Node*) const noexcept; // Accessory function executing from one node of the tree
     virtual void AuxFoldPostOrder(FoldFunctor, const void*, void*, const Node*) const noexcept;// Accessory function executing from one node of the tree

  /* ************************************************************************ */

  // Auxiliary member functions (for InOrderMappableContainer)

     virtual void AuxMapInOrder(MapFunctor, void*, Node*) noexcept; // Accessory function executing from one node of the tree

  /* ************************************************************************ */

  // Auxiliary member functions (for InOrderFoldableContainer)

     virtual void AuxFoldInOrder(FoldFunctor, const void*, void*, const Node*) const noexcept; // Accessory function executing from one node of the tree

  /* ************************************************************************ */

  // Auxiliary member functions (for BreadthMappableContainer)

     virtual void AuxMapBreadth(MapFunctor, void*, Node*) noexcept; // Accessory function executing from one node of the tree

  /* ************************************************************************ */

  // Auxiliary member functions (for BreadthFoldableContainer)

     virtual void AuxFoldBreadth(FoldFunctor, const void*, void*, const Node*) const noexcept;// Accessory function executing from one node of the tree

};

/* ************************************************************************** */

template <typename Data>
class BTPreOrderIterator : virtual public ForwardIterator<Data>{ // Must extend ForwardIterator<Data>

private:

protected:

  typename BinaryTree<Data>::Node* current=nullptr;

  StackLst<typename BinaryTree<Data>::Node*> stack;

public:

  // Specific constructors
     BTPreOrderIterator(const BinaryTree<Data>&); // An iterator over a given binary tree

  /* ************************************************************************ */

  // Copy constructor
     BTPreOrderIterator(const BTPreOrderIterator&);

  // Move constructor
     BTPreOrderIterator(BTPreOrderIterator&&) noexcept;

  /* ************************************************************************ */

  // Destructor
     virtual ~BTPreOrderIterator();

  /* ************************************************************************ */

  // Copy assignment
     virtual BTPreOrderIterator& operator=(const BTPreOrderIterator&);

  // Move assignment
     virtual BTPreOrderIterator& operator=(BTPreOrderIterator&&) noexcept;

  /* ************************************************************************ */

  // Comparison operators
     bool operator==(const BTPreOrderIterator&) const noexcept;
     bool operator!=(const BTPreOrderIterator&) const noexcept;

  /* ************************************************************************ */

  // Specific member functions (inherited from Iterator)

     virtual Data& operator*() const override; // (throw std::out_of_range when terminated)

     virtual bool Terminated() noexcept override; // (should not throw exceptions)

  /* ************************************************************************ */

  // Specific member functions (inherited from ForwardIterator)

     virtual BTPreOrderIterator& operator++() override;// (throw std::out_of_range when terminated) //pre increment operator

};

/* ************************************************************************** */

template <typename Data>
class BTPostOrderIterator: virtual public ForwardIterator<Data> { // Must extend ForwardIterator<Data>

private:

protected:
  typename BinaryTree<Data>::Node* current=nullptr;

  StackLst<typename BinaryTree<Data>::Node*> stack;

  typename BinaryTree<Data>::Node& LeftMostLeaf(const BinaryTree<Data>&);


public:

  // Specific constructors
     BTPostOrderIterator(const BinaryTree<Data>&);  // An iterator over a given binary tree

  /* ************************************************************************ */

  // Copy constructor
     BTPostOrderIterator(const BTPostOrderIterator&);

  // Move constructor
     BTPostOrderIterator(BTPostOrderIterator&&) noexcept;

  /* ************************************************************************ */

  // Destructor
     virtual ~BTPostOrderIterator()= default;

  /* ************************************************************************ */

  // Copy assignment
     virtual BTPostOrderIterator& operator=(const BTPostOrderIterator&);

  // Move assignment
     virtual BTPostOrderIterator& operator=(BTPostOrderIterator&&) noexcept;

  /* ************************************************************************ */

  // Comparison operators
     bool operator==(const BTPostOrderIterator&) const noexcept;
     bool operator!=(const BTPostOrderIterator&) const noexcept;

  /* ************************************************************************ */

  // Specific member functions (inherited from Iterator)

     virtual Data& operator*() const override; // (throw std::out_of_range when terminated)

     virtual bool Terminated() noexcept override; // (should not throw exceptions)

  /* ************************************************************************ */

  // Specific member functions (inherited from ForwardIterator)

     BTPostOrderIterator& operator++() override; // (throw std::out_of_range when terminated)

};

/* ************************************************************************** */

template <typename Data>
class BTInOrderIterator: virtual public ForwardIterator<Data> { // Must extend ForwardIterator<Data>

private:

protected:
  typename BinaryTree<Data>::Node* current=nullptr;

  StackLst<typename BinaryTree<Data>::Node*> stack;


  typename BinaryTree<Data>::Node& LeftMostNode(const typename BinaryTree<Data>::Node& nodevalue );



public:

  // Specific constructors
     BTInOrderIterator(const BinaryTree<Data>&); // An iterator over a given binary tree

  /* ************************************************************************ */

  // Copy constructor
     BTInOrderIterator(const BTInOrderIterator&);

  // Move constructor
     BTInOrderIterator(BTInOrderIterator&&) noexcept;

  /* ************************************************************************ */

  // Destructor
     virtual ~BTInOrderIterator();

  /* ************************************************************************ */

  // Copy assignment
     BTInOrderIterator& operator=(const BTInOrderIterator&);

  // Move assignment
     BTInOrderIterator& operator=(BTInOrderIterator&&) noexcept;

  /* ************************************************************************ */

  // Comparison operators
     bool operator==(const BTInOrderIterator&) const noexcept;
     bool operator!=(const BTInOrderIterator&) const noexcept;

  /* ************************************************************************ */

  // Specific member functions (inherited from Iterator)

     Data& operator*() const override; // (throw std::out_of_range when terminated)

     virtual bool Terminated() noexcept override; // (should not throw exceptions)

  /* ************************************************************************ */

  // Specific member functions (inherited from ForwardIterator)

     BTInOrderIterator& operator++() override; // (throw std::out_of_range when terminated)

};

/* ************************************************************************** */

template <typename Data>
class BTBreadthIterator : virtual public ForwardIterator<Data>{ // Must extend ForwardIterator<Data>

private:

protected:

  typename BinaryTree<Data>::Node* current=nullptr;

  QueueLst<typename BinaryTree<Data>::Node*> queue;




public:

  // Specific constructors
     BTBreadthIterator(const BinaryTree<Data>&); // An iterator over a given binary tree

  /* ************************************************************************ */

  // Copy constructor
     BTBreadthIterator(const BTBreadthIterator&);

  // Move constructor
     BTBreadthIterator(BTBreadthIterator&&) noexcept;

  /* ************************************************************************ */

  // Destructor
     virtual ~BTBreadthIterator();

  /* ************************************************************************ */

  // Copy assignment
     BTBreadthIterator& operator=(const BTBreadthIterator&);

  // Move assignment
     BTBreadthIterator& operator=(BTBreadthIterator&&) noexcept;

  /* ************************************************************************ */

  // Comparison operators
     bool operator==(const BTBreadthIterator&) const noexcept;
     bool operator!=(const BTBreadthIterator&) const noexcept;

  /* ************************************************************************ */

  // Specific member functions (inherited from Iterator)

     Data& operator*() const override; // (throw std::out_of_range when terminated)

     virtual bool Terminated() noexcept override; // (should not throw exceptions)

  /* ************************************************************************ */

  // Specific member functions (inherited from ForwardIterator)

     BTBreadthIterator& operator++() override;  // (throw std::out_of_range when terminated)

};

/* ************************************************************************** */

}

#include "binarytree.cpp"

#endif
