
#ifndef BINARYTREELNK_HPP
#define BINARYTREELNK_HPP

/* ************************************************************************** */

#include "../binarytree.hpp"

namespace lasd{
/* ************************************************************************** */

template <typename Data>
class BinaryTreeLnk : virtual public BinaryTree<Data>{ // Must extend BinaryTree<Data>

private:

protected:

  using BinaryTree<Data>::dim;

  struct NodeLnk: virtual public BinaryTree<Data>::Node{ // Must extend Node

   private:

  protected:
    friend class BinaryTreeLnk<Data>;





  public:
    using BinaryTree<Data>::Node::value;
    NodeLnk* left = nullptr;
    NodeLnk* right = nullptr;
    //NodeLnk constructor
    NodeLnk(const Data&);
    NodeLnk(Data&&)noexcept;

    ~NodeLnk() = default;

    virtual Data& Element() noexcept;
    virtual const Data& Element() const noexcept;

    using BinaryTree<Data>::Node::isLeaf;
    virtual bool HasLeftChild() const noexcept override;
    virtual bool HasRightChild() const noexcept override;


    virtual NodeLnk& LeftChild() const override;
    virtual NodeLnk& RightChild() const override;


  };

protected:

    NodeLnk* root=nullptr;

    //Auxiliary functions
    void RecursiveFillingTree(const LinearContainer<Data>&, BinaryTreeLnk<Data>::NodeLnk*&, unsigned int, unsigned long);
    NodeLnk* CopyTree(const BinaryTreeLnk<Data>&);
    void AuxCopyTree(NodeLnk**, const NodeLnk*);
    void AuxRecursiveDeleteTree(NodeLnk*&) noexcept;

public:

     // Default constructor
     BinaryTreeLnk() noexcept= default;

  /* ************************************************************************ */

     // Specific constructors
     BinaryTreeLnk(const LinearContainer<Data>&); // A binary tree obtained from a LinearContainer

  /* ************************************************************************ */

     // Copy constructor
     BinaryTreeLnk(const BinaryTreeLnk&);

     // Move constructor
     BinaryTreeLnk(BinaryTreeLnk&&) noexcept;

  /* ************************************************************************ */

     // Destructor
     virtual ~BinaryTreeLnk() noexcept;

  /* ************************************************************************ */

     // Copy assignment
     BinaryTreeLnk& operator=(const BinaryTreeLnk&);

     // Move assignment
     BinaryTreeLnk& operator=(BinaryTreeLnk&&) noexcept;

  /* ************************************************************************ */

     // Comparison operators
     bool operator==(const BinaryTreeLnk<Data>&) const noexcept;
     bool operator!=(const BinaryTreeLnk<Data>&) const noexcept;

  /* ************************************************************************ */

     // Specific member functions (inherited from BinaryTree)
     virtual NodeLnk& Root() override;

     virtual NodeLnk const& Root() const override; // Override BinaryTree member (throw std::length_error when empty)

  /* ************************************************************************ */

     // Specific member functions (inherited from BinaryTree<Data>)

     virtual void Clear() override; //Override Container member
     using BinaryTree<Data>::Size;
     using BinaryTree<Data>::Empty;

};

/* ************************************************************************** */

}

#include "binarytreelnk.cpp"

#endif
