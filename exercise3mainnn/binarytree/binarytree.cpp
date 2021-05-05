
// #include "..."
#include <iostream>
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
    right = AreEqual<Data>(first.RightChild(), second.RightChild());

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
  return dim == binarytree.dim && AreEqual<Data>(Root(), binarytree.Root());
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

// Auxiliary member functions (for PreOrderMappableContainer)
template <typename Data>
void BinaryTree<Data>::AuxMapPreOrder(MapFunctor mapFunctor, void* par, Node* n) noexcept{
    //center, sx, dx
  mapFunctor(n->Element(), par);

  if(n->HasLeftChild())
    AuxMapPreOrder(mapFunctor, par, &n->LeftChild());

  if(n->HasRightChild())
    AuxMapPreOrder(mapFunctor, par, &n->RightChild());
}

// Auxiliary member functions (for PreOrderFoldableContainer)
template <typename Data>
void BinaryTree<Data>::AuxFoldPreOrder(FoldFunctor foldFunctor, const void* par, void* acc, const Node* n) const noexcept{
  //center, sx, dx
  foldFunctor(n->Element(), par, acc);

  if(n->HasLeftChild())
    AuxFoldPreOrder(foldFunctor, par, acc, &n->LeftChild());

  if(n->HasRightChild())
    AuxFoldPreOrder(foldFunctor, par, acc, &n->RightChild());
}
// Auxiliary member functions (for PostOrderMappableContainer)
template <typename Data>
void BinaryTree<Data>::AuxMapPostOrder(MapFunctor mapFunctor, void* par, Node* n) noexcept{
  //sx, dx, center
  if(n->HasLeftChild())
    AuxMapPostOrder(mapFunctor, par, &n->LeftChild());

  if(n->HasRightChild())
    AuxMapPostOrder(mapFunctor, par, &n->RightChild());

  mapFunctor(n->Element(), par);
}
// Auxiliary member functions (for PostOrderFoldableContainer)
template <typename Data>
void BinaryTree<Data>::AuxFoldPostOrder(FoldFunctor foldFunctor, const void* par, void* acc, const Node* n) const noexcept{
  //dx, sx, center
  if(n->HasLeftChild())
    AuxFoldPostOrder(foldFunctor, par, acc, &n->LeftChild());
  if(n->HasRightChild())
    AuxFoldPostOrder(foldFunctor, par, acc, &n->RightChild());
  foldFunctor(n->Element(), par, acc);
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
  QueueLst<BinaryTree<Data>::Node*> queue;

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
  QueueLst<const BinaryTree<Data>::Node*> queue;

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
  if(binarytree.Empty()){
    current=nullptr;
  }
  else{
    current = const_cast<typename BinaryTree<Data>::Node*>(&(binarytree.Root()));
  }

}



//Copy constuctor
template <typename Data>
BTPreOrderIterator<Data>::BTPreOrderIterator(const BTPreOrderIterator<Data>& iterator){
  current=iterator.current;
  stack=iterator.stack;

}

//Move constructor
template <typename Data>
BTPreOrderIterator<Data>::BTPreOrderIterator(BTPreOrderIterator<Data>&& iterator) noexcept {
  current=iterator.current;
  iterator.current=nullptr;
  stack=iterator.stack;
  iterator.stack.Clear();
}

//Destructor
template <typename Data>
BTPreOrderIterator<Data>::~BTPreOrderIterator(){
  current=nullptr;
  stack.Clear();
}

//Copy assignment
template <typename Data>
BTPreOrderIterator<Data>& BTPreOrderIterator<Data>::operator=(const BTPreOrderIterator& iterator){
    if(this == &iterator){
        return *this;
    }
    BTPreOrderIterator<Data> *tmp=new BTPreOrderIterator<Data>(iterator);
    std::swap(*tmp, *this);
    delete tmp;
    return *this;
}

//Move assignment
template <typename Data>
BTPreOrderIterator<Data>& BTPreOrderIterator<Data>::operator=(BTPreOrderIterator<Data>&& iterator) noexcept{
std::swap(current, iterator.current);
return *this;
}

//Comparison operator
template <typename  Data>
bool BTPreOrderIterator<Data>::operator==(const BTPreOrderIterator<Data>& iterator) const noexcept{
if(current != iterator.current){
return false;
}
if(stack.Size() != iterator.stack.Size()){
return false;
}
int count=0;
for(unsigned int i=0; i<stack.Size();i++) {
if (stack[i] == iterator.stack[i]) {
count++;
}
}
return count==stack.Size();
}

//Other comparison operator
template <typename  Data>
bool BTPreOrderIterator<Data>::operator!=(const BTPreOrderIterator<Data>& iterator) const noexcept{
return !(*this == iterator);
}
//operator ++
template <typename Data>
BTPreOrderIterator<Data>& BTPreOrderIterator<Data>::operator++(){
  if (!Terminated()){
    if(current->HasLeftChild()){
      if(current->HasRightChild()){
        stack.Push(&(current->RightChild()));
      }
      current=(&(current->LeftChild()));
    }
    else if(current->HasRightChild()){
      current=(&(current->RightChild()));
    }
    else{
      if(!stack.Empty()){
        current=stack.TopNPop();
      }
      else{
        current=nullptr;
      }
    }
  }

  return *this;
}

//*operator
template <typename Data>
Data& BTPreOrderIterator<Data>::operator*() const{
  return current->Element();
}

//Terminated function
template <typename Data>
bool BTPreOrderIterator<Data>::Terminated() const noexcept{
  return (current == nullptr);
}


/* ************************************************************************** */

//BTPostOrderIterator class functions

//Specific constructor

template <typename Data>
BTPostOrderIterator<Data>::BTPostOrderIterator(const BinaryTree<Data>& binarytree){
  current= const_cast<typename BinaryTree<Data>::Node*>(&(binarytree.Root()));
  current=LeftMostLeaf(current);
}


//Auxiliary for specific constructor
template <typename Data>
typename BinaryTree<Data>::Node* BTPostOrderIterator<Data>::LeftMostLeaf(typename BinaryTree<Data>::Node* curr){

    while(curr->HasLeftChild()){
      stack.Push(curr);
      curr=&curr->LeftChild();
    }
    if(curr->HasRightChild()){
      stack.Push(curr);
      curr=&curr->RightChild();
      LeftMostLeaf(curr);
    }
    return curr;
  }

//Copy constructor
template<typename Data>
BTPostOrderIterator<Data>::BTPostOrderIterator(const BTPostOrderIterator<Data>& iterator){
    current=iterator.current;
    stack=iterator.stack;
}

//Move constructor
template <typename  Data>
BTPostOrderIterator<Data>::BTPostOrderIterator(BTPostOrderIterator<Data>&& iterator) noexcept{
    current=iterator.current;
    iterator.current=nullptr;
    stack=iterator.stack;
    iterator.stack.Clear();
}

//Destructor
template <typename Data>
BTPostOrderIterator<Data>::~BTPostOrderIterator(){
    current=nullptr;
    stack.Clear();

}

//Copy assignment
template <typename Data>
BTPostOrderIterator<Data>& BTPostOrderIterator<Data>::operator=(const BTPostOrderIterator& iterator){
    if(this == &iterator){
        return *this;
    }
    BTPostOrderIterator<Data> *tmp=new BTPostOrderIterator<Data>(iterator);
    std::swap(*tmp, *this);
    delete tmp;
    return *this;
}

//Move assignment
template <typename Data>
BTPostOrderIterator<Data>& BTPostOrderIterator<Data>::operator=(BTPostOrderIterator<Data>&& iterator) noexcept{
std::swap(current, iterator.current);
return *this;
}

//Comparison operator
template <typename  Data>
bool BTPostOrderIterator<Data>::operator==(const BTPostOrderIterator<Data>& iterator) const noexcept{
if(current != iterator.current){
return false;
}
if(stack.Size() != iterator.stack.Size()){
return false;
}
int count=0;
for(unsigned int i=0; i<stack.Size();i++) {
if (stack[i] == iterator.stack[i]) {
count++;
}
}
return count==stack.Size();
}

//Other comparison operator
template <typename  Data>
bool BTPostOrderIterator<Data>::operator!=(const BTPostOrderIterator<Data>& iterator) const noexcept{
return !(*this == iterator);
}

//++ operator
template <typename Data>
BTPostOrderIterator<Data>& BTPostOrderIterator<Data>::operator++(){

   if(stack.Empty()){
     current=nullptr;
   }
   else{
     if(stack.Top()->HasRightChild() && !(&stack.Top()->RightChild() == current)){
       current=&stack.Top()->RightChild();
       LeftMostLeaf(current);
     }
     else{
       current=stack.TopNPop();
     }
   }
  return *this;
}

//*operator
template <typename Data>
Data& BTPostOrderIterator<Data>::operator*() const{
  return current->Element();
}

//Terminated function
template <typename Data>
bool BTPostOrderIterator<Data>::Terminated() const noexcept{
  return (current == nullptr);
}

/* ************************************************************************** */
//BTInOrderIterator class functions

//Specific constructor

template <typename Data>
BTInOrderIterator<Data>::BTInOrderIterator(const BinaryTree<Data>& binarytree){
  current=const_cast<typename BinaryTree<Data>::Node*>(&(binarytree.Root()));
  current=LeftMostNode(current);
}

//Auxialiary for specific constructor
template <typename Data>
typename BinaryTree<Data>::Node* BTInOrderIterator<Data>::LeftMostNode(typename BinaryTree<Data>::Node* current){

  /*  while(current!=nullptr){
      stack.Push(current);
      current=(&(current->LeftChild()));
    }*/
    if(current->HasLeftChild()){
      stack.Push(current);
      current=LeftMostNode(&(current->LeftChild()));
    }

  return current;
}

//Copy constructor
template<typename Data>
BTInOrderIterator<Data>::BTInOrderIterator(const BTInOrderIterator<Data>& iterator){
    current=iterator.current;
    stack=iterator.stack;
}

//Move constructor
template <typename  Data>
BTInOrderIterator<Data>::BTInOrderIterator(BTInOrderIterator<Data>&& iterator) noexcept{
    current=iterator.current;
    iterator.current=nullptr;
    stack=iterator.stack;
    iterator.stack=nullptr;
}

//Destructor
template <typename Data>
BTInOrderIterator<Data>::~BTInOrderIterator(){
    current=nullptr;
    stack.Clear();

}

//Copy assignment
template <typename Data>
BTInOrderIterator<Data>& BTInOrderIterator<Data>::operator=(const BTInOrderIterator& iterator){
    if(this == &iterator){
        return *this;
    }
    BTInOrderIterator<Data> *tmp=new BTInOrderIterator<Data>(iterator);
    std::swap(*tmp, *this);
    delete tmp;
    return *this;
}

//Move assignment
template <typename Data>
BTInOrderIterator<Data>& BTInOrderIterator<Data>::operator=(BTInOrderIterator<Data>&& iterator) noexcept{
std::swap(current, iterator.current);
return *this;
}

//Comparison operator
template <typename  Data>
bool BTInOrderIterator<Data>::operator==(const BTInOrderIterator<Data>& iterator) const noexcept{
if(current != iterator.current){
return false;
}
if(stack.Size() != iterator.stack.Size()){
return false;
}
int count=0;
for(unsigned int i=0; i<stack.Size();i++) {
if (stack[i] == iterator.stack[i]) {
count++;
}
}
return count==stack.Size();
}

//Other comparison operator
template <typename  Data>
bool BTInOrderIterator<Data>::operator!=(const BTInOrderIterator<Data>& iterator) const noexcept{
return !(*this == iterator);
}
//++ operator
template <typename Data>
BTInOrderIterator<Data>& BTInOrderIterator<Data>::operator++(){

  if(!stack.Empty()){
     current=stack.TopNPop();

    if(current->HasRightChild()){
      stack.Push(&(current->RightChild()));
      LeftMostNode((&(current->RightChild())));
    }
  }
  else{
    current=nullptr;
  }

  return *this;
}

//*operator
template <typename Data>
Data& BTInOrderIterator<Data>::operator*() const{
  return current->Element();
}

//Terminated function
template <typename Data>
bool BTInOrderIterator<Data>::Terminated() const noexcept{
  return (current == nullptr);
}

/* ************************************************************************** */
//BTBreadthIterator class functions (Ampiezza)

//Specific constructor

template <typename Data>
BTBreadthIterator<Data>::BTBreadthIterator(const BinaryTree<Data>& binarytree){
  if (binarytree.Empty()){
    current=nullptr;
  }
  else{
    current = const_cast<typename BinaryTree<Data>::Node*>(&(binarytree.Root()));
  }

}

//Copy constuctor
template <typename Data>
BTBreadthIterator<Data>::BTBreadthIterator(const BTBreadthIterator<Data>& iterator){
  current=iterator.current;
  queue=iterator.queue;

}

//Move constructor
template <typename Data>
BTBreadthIterator<Data>::BTBreadthIterator(BTBreadthIterator<Data>&& iterator) noexcept {
  current=iterator.current;
  iterator.current=nullptr;
  queue=iterator.queue;
  iterator.queue=nullptr;
}

//Destructor
template <typename Data>
BTBreadthIterator<Data>::~BTBreadthIterator(){
  current=nullptr;
  queue.Clear();
}
//Copy assignment
template <typename Data>
BTBreadthIterator<Data>& BTBreadthIterator<Data>::operator=(const BTBreadthIterator<Data>& iterator){
  if(this == &iterator){
    return *this;
  }
  BTBreadthIterator<Data> *tmp=new BTBreadthIterator<Data>(iterator);
  std::swap(*tmp, *this);
  delete tmp;
  return *this;
}

//Move assignment
template <typename Data>
BTBreadthIterator<Data>& BTBreadthIterator<Data>::operator=(BTBreadthIterator<Data>&& iterator) noexcept{
  std::swap(current, iterator.current);
  return *this;
}

//Comparison operator
template <typename  Data>
bool BTBreadthIterator<Data>::operator==(const BTBreadthIterator<Data>& iterator) const noexcept{
if(current != iterator.current){
  return false;
}
if(queue.Size() != iterator.queue.Size()){
  return false;
}
int count=0;
for(unsigned int i=0; i<queue.Size();i++) {
  if (queue[i] == iterator.queue[i]) {
    count++;
  }
}
return count==queue.Size();
}

//Other comparison operator
template <typename  Data>
bool BTBreadthIterator<Data>::operator!=(const BTBreadthIterator<Data>& iterator) const noexcept{
  return !(*this == iterator);
}

//*operator
template <typename Data>
Data& BTBreadthIterator<Data>::operator*() const{
  return current->Element();
}
//++ operator
template <typename Data>
BTBreadthIterator<Data>& BTBreadthIterator<Data>::operator++(){

    if(current->HasLeftChild()){
      queue.Enqueue(&(current->LeftChild()));
      if(current->HasRightChild()){
        queue.Enqueue(&(current->RightChild()));
      }
    }

    if(!queue.Empty()){
      current=queue.HeadNDequeue();
    }
    else{
      current=nullptr;
    }

return *this;
}

//Terminated function
template <typename Data>
bool BTBreadthIterator<Data>::Terminated() const noexcept{
  return (current == nullptr);
}

/* ************************************************************************** */

}
