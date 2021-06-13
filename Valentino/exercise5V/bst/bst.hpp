#ifndef BST_HPP
#define BST_HPP

#include "../binarytree/lnk/binarytreelnk.hpp"

namespace lasd {

template <typename Data>
class BST: virtual public BinaryTreeLnk<Data> {

private:

protected:

  using Container::dimensione;
  using BinaryTreeLnk<Data>::root;
  using typename BinaryTreeLnk<Data>::NodeLnk;

  virtual NodeLnk & Root() override;

public:
  using BinaryTreeLnk<Data>::Size;
  using BinaryTreeLnk<Data>::Empty;
  using BinaryTreeLnk<Data>::Clear;

  using BinaryTreeLnk<Data>::MapInOrder;
  using BinaryTreeLnk<Data>::FoldInOrder;

  using BinaryTreeLnk<Data>::MapPreOrder;
  using BinaryTreeLnk<Data>::FoldPreOrder;

  using BinaryTreeLnk<Data>::MapPostOrder;
  using BinaryTreeLnk<Data>::FoldPostOrder;

  using BinaryTreeLnk<Data>::MapBreadth;
  using BinaryTreeLnk<Data>::FoldBreadth;

  BST() = default;
  virtual ~BST() = default;
  virtual const NodeLnk &Root() const override;

  BST(const LinearContainer<Data> &);

  BST(const BST &);
  BST(BST &&) noexcept;

  BST &operator=(const BST &);
  BST &operator=(BST &&) noexcept;

  bool operator==(const BST &) const noexcept;
  bool operator!=(const BST &) const noexcept;

  virtual void Insert(const Data &);
  virtual void Insert(Data &&);
  virtual void Remove(const Data &);

  virtual const Data &Min() const;
  virtual const Data &Max() const;

  virtual Data MinNRemove();
  virtual Data MaxNRemove();

  virtual void RemoveMin();
  virtual void RemoveMax();

  virtual const Data &Predecessor(const Data &) const;
  virtual const Data &Successor(const Data &) const;

  virtual void RemovePredecessor(const Data &);
  virtual void RemoveSuccessor(const Data &);

  virtual Data PredecessorNRemove(const Data &);
  virtual Data SuccessorNRemove(const Data &);

  bool Exists(const Data &) const noexcept override;



protected:
  Data DataNDelete(NodeLnk *);

  NodeLnk *Detach(NodeLnk *&) noexcept;

  NodeLnk *DetachMin(NodeLnk *&) noexcept;
  NodeLnk *DetachMax(NodeLnk *&) noexcept;

  NodeLnk *SkipOnLeft(NodeLnk *&) noexcept;
  NodeLnk *SkipOnRight(NodeLnk *&) noexcept;

  NodeLnk *const &FindPointerToMin(NodeLnk *const &nod) const noexcept;
  NodeLnk *const &FindPointerToMax(NodeLnk *const &nod) const noexcept;

  NodeLnk *&FindPointerToMin(NodeLnk *&nod) noexcept;
  NodeLnk *&FindPointerToMax(NodeLnk *&nod) noexcept;

  NodeLnk *const &FindPointerTo(NodeLnk *const &nod, Data dat) const noexcept;
  NodeLnk *&FindPointerTo(NodeLnk *&nod, Data dat) noexcept;

  NodeLnk *const &FindPointerToPredecessor(NodeLnk *const &nod, Data dat) const noexcept;
  NodeLnk *const &FindPointerToSuccessor(NodeLnk *const &nod, Data dat) const noexcept;

  NodeLnk *&FindPointerToPredecessor(NodeLnk *&nod, Data dat) noexcept;
  NodeLnk *&FindPointerToSuccessor(NodeLnk *&nod, Data dat) noexcept;
};
}

#include "bst.cpp"

#endif
