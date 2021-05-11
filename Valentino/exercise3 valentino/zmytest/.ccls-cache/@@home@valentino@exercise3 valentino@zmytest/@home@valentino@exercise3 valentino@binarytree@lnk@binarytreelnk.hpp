#ifndef BINARYTREELNK_HPP
#define BINARYTREELNK_HPP

#include "../binarytree.hpp"

namespace lasd {


template <typename Data>
class BinaryTreeLnk : virtual public BinaryTree<Data>{

private:

protected:
  using Container::dimensione;

  struct NodeLnk : virtual public BinaryTree<Data>::Node {

  private:

  protected:
    friend class BinaryTreeLnk<Data>;


    Data Valore;
    NodeLnk* sinistro = nullptr;
    NodeLnk* destro = nullptr;

    NodeLnk(const Data&);
    NodeLnk(Data&&) noexcept;

  public:

    using BinaryTree<Data>::Node::isLeaf;
    ~NodeLnk() = default;


    virtual Data& Element() noexcept;
    virtual const Data& Element() const noexcept;

    virtual NodeLnk& LeftChild() const override;
    virtual bool HasLeftChild() const noexcept override;

    virtual NodeLnk& RightChild() const override;
    virtual bool HasRightChild() const noexcept override;
  };

protected:
    NodeLnk* root=nullptr;

    void Insert(const LinearContainer<Data>&, BinaryTreeLnk<Data>::NodeLnk*& , uint , ulong );

    void RecursiveCopy(NodeLnk**, const NodeLnk*);

    NodeLnk* Copy(const BinaryTreeLnk<Data>&);

    void DeleteTree(NodeLnk*&) noexcept;

public:
     using Container::Size;
     using Container::Empty;

     virtual ~BinaryTreeLnk() noexcept;

     BinaryTreeLnk() noexcept= default;
     BinaryTreeLnk(const LinearContainer<Data>&);

     BinaryTreeLnk(const BinaryTreeLnk&);
     BinaryTreeLnk& operator=(const BinaryTreeLnk&);

     BinaryTreeLnk(BinaryTreeLnk&&) noexcept;
     BinaryTreeLnk& operator=(BinaryTreeLnk&&) noexcept;

     bool operator==(const BinaryTreeLnk<Data>&) const noexcept;
     bool operator!=(const BinaryTreeLnk<Data>&) const noexcept;

     virtual NodeLnk& Root() override;

     virtual NodeLnk const& Root() const override;

     virtual void Clear() override;

};

}

#include "binarytreelnk.cpp"

#endif
