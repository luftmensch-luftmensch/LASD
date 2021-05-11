
#ifndef BINARYTREELNK_HPP
#define BINARYTREELNK_HPP

/* ************************************************************************** */

#include "../binarytree.hpp"

/* ************************************************************************** */

namespace lasd {

/* ************************************************************************** */

template <typename Data>
class BinaryTreeLnk : virtual public BinaryTree<Data>{ // Must extend BinaryTree<Data>

private:

protected:

  using Container::dim;





    struct NodeLnk: virtual public BinaryTree<Data>::Node{ // Must extend Node

   private:

  protected:
    friend class BinaryTreeLnk<Data>;


    Data value;
    NodeLnk* left = nullptr;
    NodeLnk* right = nullptr;

    NodeLnk(const Data&);
    NodeLnk(Data&&) noexcept;

  public:

    ~NodeLnk() = default;


    virtual Data& Element() noexcept;
    virtual const Data& Element() const noexcept;
    virtual bool HasLeftChild() const noexcept override;
    virtual bool HasRightChild() const noexcept override;

    using BinaryTree<Data>::Node::isLeaf;
    virtual NodeLnk& LeftChild() const override;
    virtual NodeLnk& RightChild() const override;


  };

protected:
    NodeLnk* root=nullptr;
    void Insert(const LinearContainer<Data>&, BinaryTreeLnk<Data>::NodeLnk*& , unsigned int , unsigned long );
    void RecursiveCopy(NodeLnk**, const NodeLnk*);
    NodeLnk* Copy(const BinaryTreeLnk<Data>&);
    void DeleteTree(NodeLnk*&) noexcept;

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

  // Specific member functions (inherited from Container)

     virtual void Clear() override; // Override Container member
     using Container::Size;
     using Container::Empty;

};
/* ************************************************************************** */

}

#include "binarytreelnk.cpp"

#endif
