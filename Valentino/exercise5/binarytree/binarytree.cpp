
// #include "..."
#include <iostream>
namespace lasd {

/* ************************************************************************** */

//lasd::BinaryTree<Data>::Node functions
template <typename Data>
bool BinaryTree<Data>::Node::operator==(const Node& nodo) const noexcept{
  return &nodo == this;
}

template <typename Data>
bool BinaryTree<Data>::Node::operator!=(const Node& nodo) const noexcept{
  return &nodo != this;
}


template <typename Data>
bool BinaryTree<Data>::Node::isLeaf() noexcept {
  return !HasLeftChild() && !HasRightChild();
}


template <typename Data>
bool AreEqual(const typename BinaryTree<Data>::Node& primo,const typename BinaryTree<Data>::Node& secondo) noexcept {
  if (primo.Element() != secondo.Element())
    return false;

  if ((primo.HasLeftChild() != secondo.HasLeftChild()) || (primo.HasRightChild() != secondo.HasRightChild()))
    return false;

  bool sinistro = true, destro = true;

  if (primo.HasLeftChild() && secondo.HasLeftChild())
    sinistro = AreEqual<Data>(primo.LeftChild(), secondo.LeftChild());

  if(sinistro && primo.HasRightChild() && secondo.HasRightChild())
    destro = AreEqual<Data>(primo.RightChild(), secondo.RightChild());

  return sinistro && destro;
}

template <typename Data>
bool BinaryTree<Data>::operator==(const BinaryTree<Data>& binaryTree) const noexcept{
  if(this == &binaryTree)
    return true;

  if(dimensione == 0 && binaryTree.dimensione == 0)
    return true;

  return dimensione == binaryTree.dimensione && AreEqual<Data>(Root(), binaryTree.Root());
}

template <typename Data>
bool BinaryTree<Data>::operator!=(const BinaryTree<Data>& binaryTree) const noexcept{
  return !(*this == binaryTree);
}

template <typename Data>
void BinaryTree<Data>::MapPreOrder(MapFunctor MapFunctor, void* parametro) noexcept{
  if(!Empty())
    MapPreOrderPersonale(MapFunctor, parametro, &Root());
}
template <typename Data>
void BinaryTree<Data>::FoldPreOrder(FoldFunctor FoldFunctor, const void* parametro, void* accumulatore) const noexcept{
  if(!Empty())
    FoldPreOrderPersonale(FoldFunctor, parametro, accumulatore, &Root());
}

template <typename Data>
void BinaryTree<Data>::MapPostOrder(MapFunctor MapFunctor, void* parametro) noexcept{
  if(!Empty())
    MapPostOrderPersonale(MapFunctor, parametro, &Root());
}

template <typename Data>
void BinaryTree<Data>::FoldPostOrder(FoldFunctor FoldFunctor, const void* parametro, void* accumulatore) const noexcept{
  if(!Empty())
    FoldPostOrderPersonale(FoldFunctor, parametro, accumulatore, &Root());
}
template <typename Data>
void BinaryTree<Data>::MapInOrder(MapFunctor MapFunctor, void* parametro) noexcept{
  if(!Empty())
    MapInOrderPersonale(MapFunctor, parametro, &Root());
}
template <typename Data>
void BinaryTree<Data>::FoldInOrder(FoldFunctor FoldFunctor, const void* parametro, void* accumulatore) const noexcept{
  if(!Empty())
    FoldInOrderPersonale(FoldFunctor, parametro, accumulatore, &Root());
}

template <typename Data>
void BinaryTree<Data>::MapBreadth(MapFunctor MapFunctor, void* parametro) noexcept{
  if(!Empty())
    MapBreadthPersonale(MapFunctor, parametro, &Root());
}
template <typename Data>
void BinaryTree<Data>::FoldBreadth(FoldFunctor FoldFunctor, const void* parametro, void* accumulatore) const noexcept{
  if(!Empty())
    FoldBreadthPersonale(FoldFunctor, parametro, accumulatore, &Root());
}

template <typename Data>
void BinaryTree<Data>::MapPreOrderPersonale(MapFunctor MapFunctor, void* parametro, Node* nodo) noexcept{
  MapFunctor(nodo->Element(), parametro);

  if(nodo->HasLeftChild())
    MapPreOrderPersonale(MapFunctor, parametro, &nodo->LeftChild());

  if(nodo->HasRightChild())
    MapPreOrderPersonale(MapFunctor, parametro, &nodo->RightChild());
}

template <typename Data>
void BinaryTree<Data>::FoldPreOrderPersonale(FoldFunctor FoldFunctor, const void* parametro, void* accumulatore, const Node* nodo) const noexcept{
  FoldFunctor(nodo->Element(), parametro, accumulatore);

  if (nodo->HasLeftChild())
    FoldPreOrderPersonale(FoldFunctor, parametro, accumulatore, &nodo->LeftChild());

  if (nodo->HasRightChild())
    FoldPreOrderPersonale(FoldFunctor, parametro, accumulatore, &nodo->RightChild());
}

template <typename Data>
void BinaryTree<Data>::MapPostOrderPersonale(MapFunctor MapFunctor, void* parametro, Node* nodo) noexcept{
  if (nodo->HasLeftChild())
    MapPostOrderPersonale(MapFunctor, parametro, &nodo->LeftChild());

  if (nodo->HasRightChild())
    MapPostOrderPersonale(MapFunctor, parametro, &nodo->RightChild());

  MapFunctor(nodo->Element(), parametro);
}

template <typename Data>
void BinaryTree<Data>::FoldPostOrderPersonale(FoldFunctor FoldFunctor, const void* parametro, void* accumulatore, const Node* nodo) const noexcept{

  if (nodo->HasLeftChild())
    FoldPostOrderPersonale(FoldFunctor, parametro, accumulatore, &nodo->LeftChild());
  if (nodo->HasRightChild())
    FoldPostOrderPersonale(FoldFunctor, parametro, accumulatore, &nodo->RightChild());
  FoldFunctor(nodo->Element(), parametro, accumulatore);
}

template <typename Data>
void BinaryTree<Data>::MapInOrderPersonale(MapFunctor MapFunctor, void* parametro, Node* node) noexcept{
  if (node->HasLeftChild())
    MapInOrderPersonale(MapFunctor, parametro, &node->LeftChild());

  MapFunctor(node->Element(), parametro);

  if (node->HasRightChild())
    MapInOrderPersonale(MapFunctor, parametro, &node->RightChild());
}
  
template <typename Data>
void BinaryTree<Data>::FoldInOrderPersonale(FoldFunctor FoldFunctor, const void* parametro, void* accumulatore, const Node* node) const noexcept{

  if (node->HasLeftChild())
    FoldInOrderPersonale(FoldFunctor, parametro, accumulatore, &node->LeftChild());

  FoldFunctor(node->Element(), parametro, accumulatore);

  if (node->HasRightChild())
    FoldInOrderPersonale(FoldFunctor, parametro, accumulatore, &node->RightChild());
}

template <typename Data>
void BinaryTree<Data>::MapBreadthPersonale(MapFunctor MapFunctor, void* parametro, Node* nodo) noexcept{
  QueueLst<BinaryTree<Data>::Node*> coda;

  if (nodo != nullptr)
    coda.Enqueue(nodo);

  while (!coda.Empty()) {
    BinaryTree<Data>::Node *currentNode = coda.HeadNDequeue();

    MapFunctor(currentNode->Element(), parametro);

    if (currentNode->HasLeftChild())
      coda.Enqueue(&currentNode->LeftChild());

    if (currentNode->HasRightChild())
      coda.Enqueue(&currentNode->RightChild());
  }
}
template <typename Data>
void BinaryTree<Data>::FoldBreadthPersonale(FoldFunctor FoldFunctor, const void* parametro, void* accumulatore, const Node* nodo) const noexcept{
  QueueLst<const BinaryTree<Data>::Node*> coda;

  if (nodo != nullptr)
    coda.Enqueue(nodo);

  while (!coda.Empty()) {
    const BinaryTree<Data>::Node *currentNode = coda.HeadNDequeue();

    FoldFunctor(currentNode->Element(), parametro, accumulatore);

    if (currentNode->HasLeftChild())
      coda.Enqueue(&currentNode->LeftChild());

    if (currentNode->HasRightChild())
      coda.Enqueue(&currentNode->RightChild());
  }
}

template <typename Data>
BTPreOrderIterator<Data>::BTPreOrderIterator(const BinaryTree<Data>& binaryTree){
  if (binaryTree.Empty()) {
    current = nullptr;
  } else {
    current =
	const_cast<typename BinaryTree<Data>::Node *>(&(binaryTree.Root()));
  }
}

template <typename Data>
BTPreOrderIterator<Data>::BTPreOrderIterator(const BTPreOrderIterator<Data>& Iteratore){
  current=Iteratore.current;
  stack=Iteratore.stack;

}

template <typename Data>
BTPreOrderIterator<Data>::BTPreOrderIterator(BTPreOrderIterator<Data>&& Iteratore) noexcept {
  current=Iteratore.current;
  Iteratore.current=nullptr;
  stack=Iteratore.stack;
  Iteratore.stack.Clear();
}

template <typename Data>
BTPreOrderIterator<Data>::~BTPreOrderIterator(){
  current=nullptr;
  stack.Clear();
}

template <typename Data>
BTPreOrderIterator<Data>& BTPreOrderIterator<Data>::operator=(const BTPreOrderIterator& Iteratore){
  if (this == &Iteratore) {
    return *this;
  }
  BTPreOrderIterator<Data> *tmp = new BTPreOrderIterator<Data>(Iteratore);
  std::swap(*tmp, *this);
  delete tmp;
  return *this;
}

template <typename Data>
BTPreOrderIterator<Data>& BTPreOrderIterator<Data>::operator=(BTPreOrderIterator<Data>&& Iteratore) noexcept{
  std::swap(current, Iteratore.current);
  return *this;
}

template <typename  Data>
bool BTPreOrderIterator<Data>::operator==(const BTPreOrderIterator<Data>& Iteratore) const noexcept{
  int contatore = 0;
  if (current != Iteratore.current) {
    return false;
  }
  if (stack.Size() != Iteratore.stack.Size()) {
    return false;
  }
  for (uint i = 0; i < stack.Size(); i++) {
    if (stack[i] == Iteratore.stack[i]) {
      contatore++;
    }
  }
  return contatore == stack.Size();
}

template <typename  Data>
bool BTPreOrderIterator<Data>::operator!=(const BTPreOrderIterator<Data>& Iteratore) const noexcept{
  return !(*this == Iteratore);
}

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

template <typename Data>
Data& BTPreOrderIterator<Data>::operator*() const{
  return current->Element();
}

template <typename Data>
bool BTPreOrderIterator<Data>::Terminated() const noexcept{
  return (current == nullptr);
}
  
template <typename Data>
BTPostOrderIterator<Data>::BTPostOrderIterator(const BinaryTree<Data>& binaryTree){
  current= const_cast<typename BinaryTree<Data>::Node*>(&(binaryTree.Root()));
  current=LeftMostLeaf(current);
}

template <typename Data>
typename BinaryTree<Data>::Node* BTPostOrderIterator<Data>::LeftMostLeaf(typename BinaryTree<Data>::Node* corrente){

    while(corrente->HasLeftChild()){
      stack.Push(corrente);
      corrente=&corrente->LeftChild();
    }
    if(corrente->HasRightChild()){
      stack.Push(corrente);
      corrente=&corrente->RightChild();
      corrente = LeftMostLeaf(corrente);
    }
    return corrente;
  }

template<typename Data>
BTPostOrderIterator<Data>::BTPostOrderIterator(const BTPostOrderIterator<Data>& Iteratore){
    current=Iteratore.current;
    stack=Iteratore.stack;
}

template <typename  Data>
BTPostOrderIterator<Data>::BTPostOrderIterator(BTPostOrderIterator<Data>&& Iteratore) noexcept{
    current=Iteratore.current;
    Iteratore.current=nullptr;
    stack=Iteratore.stack;
    Iteratore.stack.Clear();
}

template <typename Data>
BTPostOrderIterator<Data>::~BTPostOrderIterator(){
    current=nullptr;
    stack.Clear();

}

//Copy assignment
template <typename Data>
BTPostOrderIterator<Data>& BTPostOrderIterator<Data>::operator=(const BTPostOrderIterator& Iteratore){
  if (this == &Iteratore) {
    return *this;
  }
  BTPostOrderIterator<Data> *tmp = new BTPostOrderIterator<Data>(Iteratore);
  std::swap(*tmp, *this);
  delete tmp;
  return *this;
}

template <typename Data>
BTPostOrderIterator<Data>& BTPostOrderIterator<Data>::operator=(BTPostOrderIterator<Data>&& Iteratore) noexcept{
  std::swap(current, Iteratore.current);
  return *this;
}

template <typename  Data>
bool BTPostOrderIterator<Data>::operator==(const BTPostOrderIterator<Data>& Iteratore) const noexcept{
  int contatore = 0;
  if (current != Iteratore.current) {
    return false;
  }
  if (stack.Size() != Iteratore.stack.Size()) {
    return false;
  }
  for (uint i = 0; i < stack.Size(); i++) {
    if (stack[i] == Iteratore.stack[i]) {
      contatore++;
    }
  }
  return contatore == stack.Size();
}

template <typename  Data>
bool BTPostOrderIterator<Data>::operator!=(const BTPostOrderIterator<Data>& Iteratore) const noexcept{
  return !(*this == Iteratore);
}

template <typename Data>
BTPostOrderIterator<Data>& BTPostOrderIterator<Data>::operator++(){

  if (stack.Empty()) {
    current = nullptr;
  } else {
    if (stack.Top()->HasRightChild() && !(&stack.Top()->RightChild() == current)) {
      current = &stack.Top()->RightChild();
      current = LeftMostLeaf(current);
    } else {
      current = stack.TopNPop();
    }
  }
  return *this;
}

template <typename Data>
Data& BTPostOrderIterator<Data>::operator*() const{
  return current->Element();
}

template <typename Data>
bool BTPostOrderIterator<Data>::Terminated() const noexcept{
  return (current == nullptr);
}

template <typename Data>
BTInOrderIterator<Data>::BTInOrderIterator(const BinaryTree<Data>& binaryTree){
  current = const_cast<typename BinaryTree<Data>::Node *>(&(binaryTree.Root()));
  current = LeftMostNode(current);
}

template <typename Data>
typename BinaryTree<Data>::Node* BTInOrderIterator<Data>::LeftMostNode(typename BinaryTree<Data>::Node* corrente){
  
    if(corrente->HasLeftChild()){
      stack.Push(corrente);
      corrente=LeftMostNode(&(corrente->LeftChild()));
    }
  return corrente;
}

template<typename Data>
BTInOrderIterator<Data>::BTInOrderIterator(const BTInOrderIterator<Data>& Iteratore){
  current = Iteratore.current;
  stack = Iteratore.stack;
}

template <typename  Data>
BTInOrderIterator<Data>::BTInOrderIterator(BTInOrderIterator<Data>&& Iteratore) noexcept{
  current = Iteratore.current;
  Iteratore.current = nullptr;
  stack = Iteratore.stack;
  Iteratore.stack = nullptr;
}

template <typename Data>
BTInOrderIterator<Data>::~BTInOrderIterator(){
    current=nullptr;
    stack.Clear();

}

template <typename Data>
BTInOrderIterator<Data>& BTInOrderIterator<Data>::operator=(const BTInOrderIterator& Iteratore){
  if (this == &Iteratore) {
    return *this;
  }
  BTInOrderIterator<Data> *tmp = new BTInOrderIterator<Data>(Iteratore);
  std::swap(*tmp, *this);
  delete tmp;
  return *this;
}

template <typename Data>
BTInOrderIterator<Data>& BTInOrderIterator<Data>::operator=(BTInOrderIterator<Data>&& Iteratore) noexcept{
  std::swap(current, Iteratore.current);
  return *this;
}

template <typename  Data>
bool BTInOrderIterator<Data>::operator==(const BTInOrderIterator<Data>& Iteratore) const noexcept{
  int contatore = 0;
  if (current != Iteratore.current) {
    return false;
  }
  if (stack.Size() != Iteratore.stack.Size()) {
    return false;
  }
  for (uint i = 0; i < stack.Size(); i++) {
    if (stack[i] == Iteratore.stack[i]) {
      contatore++;
    }
  }
  return contatore == stack.Size();
}

template <typename  Data>
bool BTInOrderIterator<Data>::operator!=(const BTInOrderIterator<Data>& Iteratore) const noexcept{
  return !(*this == Iteratore);
}

template <typename Data>
BTInOrderIterator<Data>& BTInOrderIterator<Data>::operator++(){
  if (!stack.Empty()) {
    current = stack.TopNPop();

    if (current->HasRightChild()) {
      stack.Push(&(current->RightChild()));
      LeftMostNode((&(current->RightChild())));
    }
  } else {
    current = nullptr;
  }

  return *this;
}

template <typename Data>
Data& BTInOrderIterator<Data>::operator*() const{
  return current->Element();
}

template <typename Data>
bool BTInOrderIterator<Data>::Terminated() const noexcept{
  return (current == nullptr);
}

template <typename Data>
BTBreadthIterator<Data>::BTBreadthIterator(const BinaryTree<Data>& binaryTree){
  if (binaryTree.Empty()) {
    current = nullptr;
  } else {
    current = const_cast<typename BinaryTree<Data>::Node *>(&(binaryTree.Root()));
  }
}

template <typename Data>
BTBreadthIterator<Data>::BTBreadthIterator(const BTBreadthIterator<Data>& Iteratore){
  current = Iteratore.current;
  queue = Iteratore.queue;
}

template <typename Data>
BTBreadthIterator<Data>::BTBreadthIterator(BTBreadthIterator<Data>&& Iteratore) noexcept {
  current = Iteratore.current;
  Iteratore.current = nullptr;
  queue = Iteratore.queue;
  Iteratore.queue = nullptr;
}
  
template <typename Data>
BTBreadthIterator<Data>::~BTBreadthIterator(){
  current = nullptr;
  queue.Clear();
}

template <typename Data>
BTBreadthIterator<Data>& BTBreadthIterator<Data>::operator=(const BTBreadthIterator<Data>& Iteratore){
  if (this == &Iteratore) {
    return *this;
  }
  BTBreadthIterator<Data> *tmp = new BTBreadthIterator<Data>(Iteratore);
  std::swap(*tmp, *this);
  delete tmp;
  return *this;
}

template <typename Data>
BTBreadthIterator<Data>& BTBreadthIterator<Data>::operator=(BTBreadthIterator<Data>&& Iteratore) noexcept{
  std::swap(current, Iteratore.current);
  std::swap(queue, Iteratore.queue);
  return *this;
}

template <typename  Data>
bool BTBreadthIterator<Data>::operator==(const BTBreadthIterator<Data>& Iteratore) const noexcept{
  int contatore = 0;
  if (current != Iteratore.current) {
    return false;
  }
  if (queue.Size() != Iteratore.queue.Size()) {
    return false;
  }
  for (uint i = 0; i < queue.Size(); i++) {
    if (queue[i] == Iteratore.queue[i]) {
      contatore++;
    }
  }
  return contatore == queue.Size();
}

template <typename  Data>
bool BTBreadthIterator<Data>::operator!=(const BTBreadthIterator<Data>& Iteratore) const noexcept{
  return !(*this == Iteratore);
}

template <typename Data>
Data& BTBreadthIterator<Data>::operator*() const{
  return current->Element();
}
  
template <typename Data>
BTBreadthIterator<Data>& BTBreadthIterator<Data>::operator++(){

  if (current != nullptr) {

    if (current->HasLeftChild()) {
      queue.Enqueue(&(current->LeftChild()));
    }
    if (current->HasRightChild()) {
      queue.Enqueue(&(current->RightChild()));
    }

    if (!queue.Empty()) {
      current = queue.HeadNDequeue();
    } else {
      current = nullptr;
    }
  }
  return *this;
}

template <typename Data>
bool BTBreadthIterator<Data>::Terminated() const noexcept{
  return (current == nullptr);
}
}
