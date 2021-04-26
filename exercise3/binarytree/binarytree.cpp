
// #include "..."

namespace lasd {

/* ************************************************************************** */

//lasd::BinaryTree<Data>::Node functions
template <typename Data>
bool BinaryTree<Data>::Node::operator==(const Node& node) const noexcept{
  return &node == this;
}

template <typename Data>
bool BinaryTree<Data>::Node::operator!=(const Node& node) const noexcept{
  return &node != this;
}

template <typename Data>
Data const& BinaryTree<Data>::Node::Element() const noexcept{
  return Nodevalue;
}

template <typename Data>
Data& BinaryTree<Data>::Node::Element() noexcept{
  return Nodevalue;
}


template <typename Data>
bool BinaryTree<Data>::Node::isLeaf() noexcept {
  return !HasLeftChild() && !HasRightChild();
}


template <typename Data>
bool AreEqual(const typename BinaryTree<Data>::Node& first,const typename BinaryTree<Data>::Node& second) noexcept {
                      //If the data field is different
  if(first.Element() != second.Element())
    return false;

                      //If the overall structure is different
  if((first.HasLeftChild() != first.HasLeftChild()) || (first.HasRightChild() != second.HasRightChild()))
    return false;

  bool left = true, right = true;
                      //Recursive call to the left subtree
  if(first.HasLeftChild() && second.HasLeftChild())
    left = AreEqual<Data>(first.LeftChild(), second.LeftChild());

                     //Recursive call to the right subtree if subLeft is still true
  if(left && first.HasRightChild() && second.HasRightChild())
    right = AreEqual(first.RightChild(), second.RightChild());

  return left && right;
}

template <typename Data>
bool BinaryTree<Data>::operator==(const BinaryTree<Data>& binarytree) const noexcept{
                         //Same pointer
  if(this == &binarytree)
    return true;

                         //Both are empty
  if(dim == 0 && binarytree.dim == 0)
    return true;

                        //If the two sizes are equal, i proceed with recursive calls to the left or right child
  return dim == binarytree.dim && AreEqual(Root(), binarytree.Root());
}

template <typename Data>
bool BinaryTree<Data>::operator!=(const BinaryTree<Data>& bT) const noexcept{
  return !(*this == bT);
}

// Specific member functions (inherited from MappableContainer)

template <typename Data>
void BinaryTree<Data>::MapPreOrder(MapFunctor mapFunctor, void* par) noexcept{
  if(!Empty())
    AuxMapPreOrder(mapFunctor, par, &Root());
}

template <typename Data>
void BinaryTree<Data>::MapPostOrder(MapFunctor mapFunctor, void* par) noexcept{
  if(!Empty())
    AuxMapPostOrder(mapFunctor, par, &Root());
}

// Specific member functions (inherited from FoldableContainer)

template <typename Data>
void BinaryTree<Data>::FoldPreOrder(FoldFunctor foldFunctor, const void* par, void* acc) const noexcept{
  if(!Empty())
    AuxFoldPreOrder(foldFunctor, par, acc, &Root());
}

template <typename Data>
void BinaryTree<Data>::FoldPostOrder(FoldFunctor foldFunctor, const void* par, void* acc) const noexcept{
  if(!Empty())
    AuxFoldPostOrder(foldFunctor, par, acc, &Root());
}

// Specific member functions (inherited from InOrderMappableContainer)

template <typename Data>
void BinaryTree<Data>::MapInOrder(MapFunctor mapFunctor, void* par) noexcept{
  if(!Empty())
    AuxMapInOrder(mapFunctor, par, &Root());
}

// Specific member functions (inherited from InOrderFoldableContainer)

template <typename Data>
void BinaryTree<Data>::FoldInOrder(FoldFunctor foldFunctor, const void* par, void* acc) const noexcept{
  if(!Empty())
    AuxFoldInOrder(foldFunctor, par, acc, &Root());
}

// Specific member functions (inherited from BreadthMappableContainer)

template <typename Data>
void BinaryTree<Data>::MapBreadth(MapFunctor mapFunctor, void* par) noexcept{
  if(!Empty())
    AuxMapBreadth(mapFunctor, par, &Root());
}

// Specific member functions (inherited from BreadthFoldableContainer)

template <typename Data>
void BinaryTree<Data>::FoldBreadth(FoldFunctor foldFunctor, const void* par, void* acc) const noexcept{
  if(!Empty())
    AuxFoldBreadth(foldFunctor, par, acc, &Root());
}

// Auxiliary member functions (for InOrderMappableContainer)

template <typename Data>
void BinaryTree<Data>::AuxMapInOrder(MapFunctor mapFunctor, void* par, Node* node) noexcept{
  //sx, center, dx
  if(node->HasLeftChild())
    AuxMapInOrder(mapFunctor, par, &node->LeftChild());

  mapFunctor(node->Element(), par);

  if(node->HasRightChild())
    AuxMapInOrder(mapFunctor, par, &node->RightChild());
}

// Auxiliary member functions (for InOrderFoldableContainer)

template <typename Data>
void BinaryTree<Data>::AuxFoldInOrder(FoldFunctor foldFunctor, const void* par, void* acc, const Node* node) const noexcept{
  //sx, center, dx
  if(node->HasLeftChild())
    AuxFoldInOrder(foldFunctor, par, acc, &node->LeftChild());

  foldFunctor(node->Element(), par, acc);

  if(node->HasRightChild())
    AuxFoldInOrder(foldFunctor, par, acc, &node->RightChild());
}

// Auxiliary member functions (for BreadthMappableContainer)

template <typename Data>
void BinaryTree<Data>::AuxMapBreadth(MapFunctor mapFunctor, void* par, Node* node) noexcept{
  QueueVec<BinaryTree<Data>::Node*> queue;

  if(node != nullptr)
    queue.Enqueue(node);

  while(!queue.Empty()){
    BinaryTree<Data>::Node* currentNode = queue.HeadNDequeue();

    mapFunctor(currentNode->Element(), par);

    if(currentNode->HasLeftChild())
      queue.Enqueue(&currentNode->LeftChild());

    if(currentNode->HasRightChild())
      queue.Enqueue(&currentNode->RightChild());
  }
}

// Auxiliary member functions (for BreadthFoldableContainer)

template <typename Data>
void BinaryTree<Data>::AuxFoldBreadth(FoldFunctor foldFunctor, const void* par, void* acc, const Node* node) const noexcept{
  QueueVec<const BinaryTree<Data>::Node*> queue;

  if(node != nullptr)
    queue.Enqueue(node);

  while(!queue.Empty()){
    const BinaryTree<Data>::Node* currentNode = queue.HeadNDequeue();

    foldFunctor(currentNode->Element(), par, acc);

    if(currentNode->HasLeftChild())
      queue.Enqueue(&currentNode->LeftChild());

    if(currentNode->HasRightChild())
      queue.Enqueue(&currentNode->RightChild());
  }
}
/* ************************************************************************** */

//BTPreOrderIterator class functions
//Specific constructor
template <typename Data>
BTPreOrderIterator<Data>::BTPreOrderIterator(const BinaryTree<Data>& binarytree){
  if(binarytree.Root() == nullptr){
    return;
  }
  typename BinaryTree<Data>::Node current=binarytree.Root();
  Queue<Data> queue;
  queue.Enqueue(current);
  queue.Dequeue(current);

  while(current.HasLeftChild()){
    queue.Enqueue(current.LeftChild());
    current=current.LeftChild();
  }
  while(current.HasRightChild()){
    queue.Enqueue(current.RightChild());
    current=current.RightChild();
  }
}



/* ************************************************************************** */

}
