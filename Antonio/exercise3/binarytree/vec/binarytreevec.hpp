
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

protected:

  using BinaryTree<Data>::dim;
  void Expand();
  void Reduce();

  struct NodeVec: virtual public BinaryTree<Data>::Node { // Must extend Node

  private:

  protected:

    friend class BinaryTreeVec<Data>;

    using BinaryTree<Data>::Node::value;
           //index for the array
    unsigned int index = 0;
           //pointer reference to the array
    lasd::Vector<NodeVec*>* myrefvector;

    NodeVec(const Data& toinsert, lasd::Vector<NodeVec*>* con, const unsigned long int& ind);

  public:

    ~NodeVec() = default;
    NodeVec& operator=(const NodeVec&);
    NodeVec& operator=(NodeVec&&) noexcept;

    virtual Data& Element() noexcept;
    virtual const Data& Element() const noexcept;

    using BinaryTree<Data>::Node::isLeaf;
    bool HasLeftChild() const noexcept override;
    bool HasRightChild() const noexcept override;
    NodeVec& LeftChild() const override;
    NodeVec& RightChild() const override;


  };
protected:
                           //auxiliary container
  lasd::Vector<NodeVec*> cont = lasd::Vector<NodeVec*>(0);
  void DeleteTree(NodeVec*&) noexcept;


public:

     // Default constructor
     BinaryTreeVec() = default;

  /* ************************************************************************ */

     // Specific constructors
     BinaryTreeVec(const LinearContainer<Data>&); // A binary tree obtained from a LinearContainer

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
     virtual NodeVec& Root() override;

     virtual NodeVec const& Root() const override; // Override BinaryTree member (throw std::length_error when empty)

  /* ************************************************************************ */

     // Specific member functions (inherited from Container)

     void Clear() noexcept override; // Override Container member
     using Container::Size;
     using Container::Empty;

     // Specific member functions (inherited from MappableContainer)
     
     using typename MappableContainer<Data>::MapFunctor;
     void MapBreadth(MapFunctor, void*) noexcept override;

     // Specific member functions (inherited from FoldableContainer)

     using typename FoldableContainer<Data>::FoldFunctor;
     void FoldBreadth(FoldFunctor, const void*, void*) const noexcept override;

};

/* ************************************************************************** */

}

#include "binarytreevec.cpp"

#endif
