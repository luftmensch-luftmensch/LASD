#ifndef BINARYTREE_HPP
#define BINARYTREE_HPP

#include "../container/container.hpp"
#include "../iterator/iterator.hpp"
#include "../queue/queue.hpp"
#include "../queue/lst/queuelst.hpp"
#include "../stack/stack.hpp"
#include "../stack/lst/stacklst.hpp"

namespace lasd {
template <typename Data>
class BinaryTree : virtual public InOrderMappableContainer<Data>,virtual public InOrderFoldableContainer<Data>, virtual public BreadthMappableContainer<Data>, virtual public BreadthFoldableContainer<Data>{

private:

protected:
  using Container::dimensione;

public:

  using Container::Empty;
  using Container::Size;

  struct Node {

  private:

  protected:
       bool operator==(const Node&) const noexcept;
       bool operator!=(const Node&) const noexcept;


  public:
       virtual ~Node() = default;

       Node& operator=(const Node&)=delete;
       Node& operator=(Node&&) noexcept =delete;

       virtual Data& Element() noexcept =0;
       virtual const Data& Element() const noexcept =0;

       virtual bool isLeaf() noexcept;

       virtual Node& LeftChild() const = 0;
       virtual bool HasLeftChild() const  noexcept = 0;

       virtual Node& RightChild() const = 0;
       virtual bool HasRightChild() const noexcept = 0;

  };

public:
     using typename MappableContainer<Data>::MapFunctor;
     using typename FoldableContainer<Data>::FoldFunctor;

     virtual ~BinaryTree() noexcept = default;

     virtual BinaryTree& operator=(const BinaryTree&) = delete;
     virtual BinaryTree& operator=(BinaryTree&&) noexcept = delete;
  
     virtual bool operator==(const BinaryTree&) const noexcept;
     virtual bool operator!=(const BinaryTree&) const noexcept;
  
     virtual const Node& Root() const = 0;
     virtual Node& Root() = 0;


     virtual void MapPreOrder(MapFunctor, void*) noexcept override;
     virtual void FoldPreOrder(FoldFunctor, const void*, void*) const noexcept override;

     virtual void MapPostOrder(MapFunctor, void*) noexcept override;
     virtual void FoldPostOrder(FoldFunctor, const void*, void*) const noexcept override;

     virtual void MapInOrder(MapFunctor, void*) noexcept;
     virtual void FoldInOrder(FoldFunctor, const void*, void*) const noexcept;

     virtual void MapBreadth(MapFunctor, void*) noexcept override;
     virtual void FoldBreadth(FoldFunctor, const void*, void*) const noexcept override;

protected:
     virtual void AuxMapPreOrder(MapFunctor, void*, Node*) noexcept; 
     virtual void AuxFoldPreOrder(FoldFunctor, const void*, void*, const Node*) const noexcept;

     virtual void AuxMapPostOrder(MapFunctor, void*, Node*) noexcept;
     virtual void AuxFoldPostOrder(FoldFunctor, const void*, void*, const Node*) const noexcept;

     virtual void AuxMapInOrder(MapFunctor, void*, Node*) noexcept;
     virtual void AuxFoldInOrder(FoldFunctor, const void*, void*, const Node*) const noexcept;
  
     virtual void AuxMapBreadth(MapFunctor, void*, Node*) noexcept;
     virtual void AuxFoldBreadth(FoldFunctor, const void*, void*, const Node*) const noexcept;

};


template <typename Data>
class BTPreOrderIterator : virtual public ForwardIterator<Data>{

private:

protected:

  typename BinaryTree<Data>::Node* current=nullptr;

  StackLst<typename BinaryTree<Data>::Node*> stack;

public:
     virtual ~BTPreOrderIterator();

     BTPreOrderIterator(const BinaryTree<Data> &);
     BTPreOrderIterator(const BTPreOrderIterator &);
     BTPreOrderIterator(BTPreOrderIterator &&) noexcept;

  
     virtual BTPreOrderIterator& operator=(const BTPreOrderIterator&);
     virtual BTPreOrderIterator& operator=(BTPreOrderIterator&&) noexcept;
  
     bool operator==(const BTPreOrderIterator&) const noexcept;
     bool operator!=(const BTPreOrderIterator&) const noexcept;
  
     virtual Data& operator*() const override;
     virtual bool Terminated() const noexcept override;

     virtual BTPreOrderIterator& operator++() override;

};
  
template <typename Data>
class BTPostOrderIterator: virtual public ForwardIterator<Data> {

private:

protected:
  typename BinaryTree<Data>::Node* current=nullptr;

  typename BinaryTree<Data>::Node* LeftMostLeaf(typename BinaryTree<Data>::Node*);

  StackLst<typename BinaryTree<Data>::Node*> stack;

public:
     virtual ~BTPostOrderIterator();
  
     BTPostOrderIterator(const BinaryTree<Data>&);
     BTPostOrderIterator(const BTPostOrderIterator&);
     BTPostOrderIterator(BTPostOrderIterator&&) noexcept;

     virtual BTPostOrderIterator& operator=(const BTPostOrderIterator&);
     virtual BTPostOrderIterator& operator=(BTPostOrderIterator&&) noexcept;

     bool operator==(const BTPostOrderIterator&) const noexcept;
     bool operator!=(const BTPostOrderIterator&) const noexcept;

     virtual Data& operator*() const override;
     virtual bool Terminated() const noexcept override;
  
     BTPostOrderIterator& operator++() override;

};
template <typename Data>
class BTInOrderIterator: virtual public ForwardIterator<Data> {

private:

protected:
  typename BinaryTree<Data>::Node* current=nullptr;
  typename BinaryTree<Data>::Node* LeftMostNode(typename BinaryTree<Data>::Node* );

  StackLst<typename BinaryTree<Data>::Node*> stack;

public:
     virtual ~BTInOrderIterator();

     BTInOrderIterator(const BinaryTree<Data>&);
     BTInOrderIterator(const BTInOrderIterator&);
     BTInOrderIterator(BTInOrderIterator&&) noexcept;

     BTInOrderIterator& operator=(const BTInOrderIterator&);
     BTInOrderIterator& operator=(BTInOrderIterator&&) noexcept;

     bool operator==(const BTInOrderIterator&) const noexcept;
     bool operator!=(const BTInOrderIterator&) const noexcept;

     virtual Data& operator*() const override;
     virtual bool Terminated() const noexcept override;

     BTInOrderIterator& operator++() override;

};

template <typename Data>
class BTBreadthIterator : virtual public ForwardIterator<Data>{

private:

protected:

  typename BinaryTree<Data>::Node* current=nullptr;

  QueueLst<typename BinaryTree<Data>::Node*> queue;

public:

     virtual ~BTBreadthIterator();

     BTBreadthIterator(const BinaryTree<Data>&);
     BTBreadthIterator(const BTBreadthIterator&);
     BTBreadthIterator(BTBreadthIterator&&) noexcept;
  
     BTBreadthIterator& operator=(const BTBreadthIterator&);
     BTBreadthIterator& operator=(BTBreadthIterator&&) noexcept;

     bool operator==(const BTBreadthIterator&) const noexcept;
     bool operator!=(const BTBreadthIterator&) const noexcept;

     Data& operator*() const override;

     virtual bool Terminated() const noexcept override;

     BTBreadthIterator& operator++() override;

};
}

#include "binarytree.cpp"

#endif
