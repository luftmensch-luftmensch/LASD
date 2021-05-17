
#ifndef BST_HPP
#define BST_HPP

/* ************************************************************************** */

#include "../binarytree/lnk/binarytreelnk.hpp"

/* ************************************************************************** */

namespace lasd {

/* ************************************************************************** */

template <typename Data>
class BST: virtual public BinaryTreeLnk<Data> { // Must extend BinaryTreeLnk<Data>

private:

protected:

  using BinaryTreeLnk<Data>::root;

  using Container::dim;

  using typename BinaryTreeLnk<Data>::NodeLnk;

  virtual NodeLnk & Root() override;

public:

  // Default constructor:It will be called the default constructor of BinaryTreeLnk<Data>
     BST() = default;
     virtual const NodeLnk & Root() const override;

  /* ************************************************************************ */

  // Specific constructors
     BST(const LinearContainer<Data>& ); // A bst obtained from a LinearContainer

  /* ************************************************************************ */

  // Copy constructor
     BST(const BST&);

  // Move constructor
     BST(BST&&) noexcept;

  /* ************************************************************************ */

  // Destructor
     virtual ~BST() = default;

  /* ************************************************************************ */

  // Copy assignment
     BST& operator=(const BST&);

  // Move assignment
     BST& operator=(BST &&) noexcept;

  /* ************************************************************************ */

  // Comparison operators:InOrder visit to the two BST's
     bool operator==(const BST &) const noexcept;
     bool operator!=(const BST &) const noexcept;

  /* ************************************************************************ */

  // Specific member functions

     virtual void Insert(const Data&); // Copy of the value
     virtual void Insert(Data&&); // Move of the value
     virtual void Remove(const Data &);


                           //These functions assume the existance of the tree (empty function)
     virtual const Data& Min() const; // (concrete function must throw std::length_error when empty)
     virtual Data MinNRemove(); // (concrete function must throw std::length_error when empty)
     virtual void RemoveMin(); // (concrete function must throw std::length_error when empty)

     virtual const Data& Max() const; // (concrete function must throw std::length_error when empty)
     virtual Data MaxNRemove(); // (concrete function must throw std::length_error when empty)
     virtual void RemoveMax(); // (concrete function must throw std::length_error when empty)

     virtual const Data& Predecessor(const Data &) const;   // (concrete function must throw std::length_error when not found)
     virtual Data PredecessorNRemove(const Data &);   // (concrete function must throw std::length_error when not found)
     virtual void RemovePredecessor(const Data &);   // (concrete function must throw std::length_error when not found)

     virtual const Data& Successor(const Data &) const;   // (concrete function must throw std::length_error when not found)
     virtual Data SuccessorNRemove(const Data &);   // (concrete function must throw std::length_error when not found)
     virtual void RemoveSuccessor(const Data &);   // (concrete function must throw std::length_error when not found)

     using BinaryTreeLnk<Data>::Size;
     using BinaryTreeLnk<Data>::Empty;
     using BinaryTreeLnk<Data>::Clear;

     using BinaryTreeLnk<Data>::MapInOrder;
     using BinaryTreeLnk<Data>::MapPreOrder;
     using BinaryTreeLnk<Data>::MapPostOrder;
     using BinaryTreeLnk<Data>::MapBreadth;

     using BinaryTreeLnk<Data>::FoldInOrder;
     using BinaryTreeLnk<Data>::FoldPreOrder;
     using BinaryTreeLnk<Data>::FoldPostOrder;
     using BinaryTreeLnk<Data>::FoldBreadth;

  /* ************************************************************************ */

  // Specific member functions (inherited from TestableContainer)

     bool Exists(const Data&) const noexcept override; // Override TestableContainer member



protected:

  // Auxiliary member functions

     Data DataNDelete(NodeLnk*);

            //Extraction of a node from the BST (not destroyed)
     NodeLnk* Detach(NodeLnk*& )noexcept;

     NodeLnk* DetachMin(NodeLnk*&) noexcept;
     NodeLnk* DetachMax(NodeLnk*&) noexcept;

     NodeLnk* SkipOnLeft(NodeLnk*&) noexcept;
     NodeLnk* SkipOnRight(NodeLnk*&) noexcept;

     NodeLnk* const& FindPointerToMin(NodeLnk* const& nod)const noexcept;
     NodeLnk*& FindPointerToMin(NodeLnk*& nod)noexcept;

     NodeLnk* const& FindPointerToMax(NodeLnk* const& nod)const noexcept;
     NodeLnk*& FindPointerToMax(NodeLnk*& nod)noexcept;

                        //Existance functions
     NodeLnk* const& FindPointerTo(NodeLnk* const& nod, Data dat)const noexcept;
     NodeLnk*& FindPointerTo(NodeLnk*& nod, Data dat) noexcept;

     NodeLnk* const& FindPointerToPredecessor(NodeLnk* const& nod, Data dat) const noexcept;
     NodeLnk*& FindPointerToPredecessor(NodeLnk*& nod, Data dat) noexcept;

     NodeLnk* const& FindPointerToSuccessor(NodeLnk* const& nod, Data dat)const noexcept;
     NodeLnk*& FindPointerToSuccessor(NodeLnk*& nod, Data dat) noexcept;


};

/* ************************************************************************** */

}

#include "bst.cpp"

#endif
