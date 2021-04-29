
#ifndef BINARYTREEVEC_HPP
#define BINARYTREEVEC_HPP

/* ************************************************************************** */

#include "../binarytree.hpp"
#include "../../vector/vector.hpp"

/* ************************************************************************** */

namespace lasd {

/* ************************************************************************** */

template <typename Data>
class BinaryTreeVec: virtual public BinaryTree<Data> { // Must extend BinaryTree<Data>

private:

  // ...

protected:
  using Container::dim;
  // using BinaryTree<Data>::???;

  void Expand();
  void Reduce();
  void UpdateReferences() noexcept;
                                       //auxiliary vector
  lasd::Vector<unsigned long int> nodeperlevel = lasd::Vector<unsigned long int>(0);

  struct NodeVec: BinaryTree<Data>::Node { // Must extend Node

  private:

    // ...

  protected:
    Data value;
           //index for the array
    unsigned long int index = 0;
           //pointer reference to the array
    lasd::Vector<NodeVec*>* reference;

  public:

    friend class BinaryTreeVec<Data>;

    virtual Data& Element() noexcept;
    virtual const Data& Element() const noexcept;

    using BinaryTree<Data>::Node::isLeaf;
    bool HasLeftChild() const noexcept override;
    bool HasRightChild() const noexcept override;
    NodeVec& LeftChild() const override;
    NodeVec& RightChild() const override;


  };
protected:
  lasd::Vector<NodeVec*> mycontainer = lasd::Vector<NodeVec*>(0);
  void DeleteTree(NodeVec*&) noexcept;

public:

  // Default constructor
     BinaryTreeVec() = default;

  /* ************************************************************************ */

  // Specific constructors
  // BinaryTreeVec(argument) specifiers; // A binary tree obtained from a LinearContainer

  /* ************************************************************************ */

  // Copy constructor
     BinaryTreeVec(const BinaryTreeVec&);

  // Move constructor
     BinaryTreeVec(BinaryTreeVec&&) noexcept;

  /* ************************************************************************ */

  // Destructor
     ~BinaryTreeVec() noexcept;

  /* ************************************************************************ */

  // Copy assignment
     BinaryTreeVec& operator=(const BinaryTreeVec&);

  // Move assignment
     BinaryTreeVec& operator=(BinaryTreeVec&&) noexcept;

  /* ************************************************************************ */

  // Comparison operators
     bool operator==(const BinaryTreeVec&) const noexcept;
     bool operator!=(const BinaryTreeVec&) const noexcept;

  /* ************************************************************************ */

  // Specific member functions (inherited from BinaryTree)

     virtual NodeVec const& Root() const override; // Override BinaryTree member (throw std::length_error when empty)

  /* ************************************************************************ */

  // Specific member functions (inherited from Container)

     void Clear() noexcept override; // Override Container member
     using Container::Size;
     using Container::Empty;

};

/* ************************************************************************** */

}

#include "binarytreevec.cpp"

#endif
