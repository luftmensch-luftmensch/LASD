#ifndef BINARYTREEVEC_HPP
#define BINARYTREEVEC_HPP

#include "../binarytree.hpp"
#include "../../vector/vector.hpp"

namespace lasd {


template <typename Data>
class BinaryTreeVec: virtual public BinaryTree<Data> {

private:

protected:

  using Container::dimensione;
  void Expand();
  void Reduce();
  void UpdateReferences() noexcept;
  
  lasd::Vector<unsigned long int> nodeperlevel = lasd::Vector<unsigned long int>(0);

  struct NodeVec: virtual public BinaryTree<Data>::Node {

  private:

  protected:
    friend class BinaryTreeVec<Data>;

    Data Valore;

    uint in = 0;
    
    lasd::Vector<NodeVec*>* riferimento;

    NodeVec(const Data& k, lasd::Vector<NodeVec*>* c, const unsigned long int& p);
    NodeVec(const Data&& k, lasd::Vector<NodeVec*>* c, const unsigned long int& p);

  public:
    using BinaryTree<Data>::Node::isLeaf;

    NodeVec& operator=(const NodeVec&);
    NodeVec& operator=(NodeVec&&) noexcept;

    virtual Data& Element() noexcept;
    virtual const Data& Element() const noexcept;

    NodeVec& LeftChild() const override;
    bool HasLeftChild() const noexcept override;

    NodeVec& RightChild() const override;
    bool HasRightChild() const noexcept override;

  };
protected:
  lasd::Vector<NodeVec*> containerP = lasd::Vector<NodeVec*>(0);
  void DeleteTree(NodeVec*&) noexcept;

public:

     using Container::Size;
     using Container::Empty;

     ~BinaryTreeVec() noexcept;

     BinaryTreeVec() = default;
     BinaryTreeVec(const LinearContainer<Data>&); // A binary tree obtained from a LinearContainer

     BinaryTreeVec(const BinaryTreeVec&);
     BinaryTreeVec& operator=(const BinaryTreeVec&);

     BinaryTreeVec(BinaryTreeVec&&) noexcept;
     BinaryTreeVec& operator=(BinaryTreeVec&&) noexcept;

     bool operator==(const BinaryTreeVec&) const noexcept;
     bool operator!=(const BinaryTreeVec&) const noexcept;

     virtual NodeVec& Root() override;

     virtual NodeVec const& Root() const override;

     void Clear() noexcept override;

};
}

#include "binarytreevec.cpp"

#endif
