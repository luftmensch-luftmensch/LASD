
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
  current= &binarytree.Root();
  stack=nullptr;
}



//Copy constuctor
template <typename Data>
BTPreOrderIterator<Data>::BTPreOrderIterator(const BTPreOrderIterator<Data>& iterator){
  current=iterator.current;
  stack=iterator.queue;

}

//Move constructor
template <typename Data>
BTPreOrderIterator<Data>::BTPreOrderIterator(BTPreOrderIterator<Data>&& iterator) noexcept {
  current=iterator.current;
  iterator.current=nullptr;
}

//Destructor
template <typename Data>
BTPreOrderIterator<Data>::~BTPreOrderIterator(){
  current=nullptr;
  stack.Clear();
}


/* ************************************************************************** */

//BTPostOrderIterator class functions

//Specific constructor

template <typename Data>
BTPostOrderIterator<Data>::BTPostOrderIterator(const BinaryTree<Data>& binarytree){
  current= LeftMostLeaf(binarytree);
  stack=nullptr;
}

//Auxiliary for specific constructor
template <typename Data>
typename BinaryTree<Data>::Node& BTPostOrderIterator<Data>::LeftMostLeaf(const BinaryTree<Data>& binarytree){
  struct BinaryTree<Data>::Node* current;
  if(binarytree->Root() == nullptr) {
    current = nullptr;
  }
  else{
    current=binarytree->Root();
    while(current !=nullptr) {
      if(current->HasLeftChild()){
        current=current->LeftChild();
      }
      else if(current->HasRightChild()){
        current=current->RightChild();
        if(current->HasLeftChild()){
          current=current->LeftChild();
        }
      }
    }
  }
  return current;
}


template <typename Data>
Data& BTPostOrderIterator<Data>::operator*() const {
  return current->Element();
}

/*template <typename Data>
BTPostOrderIterator& BTBreadthIterator<Data>::operator++(){

}*/

template <typename Data>
bool BTPostOrderIterator<Data>::Terminated() noexcept{
  return (current == nullptr);
}

/* ************************************************************************** */
//BTInOrderIterator class functions

//Specific constructor

template <typename Data>
BTInOrderIterator<Data>::BTInOrderIterator(const BinaryTree<Data>& binarytree){
  current= LeftMostNode(&binarytree.Root());
  stack=nullptr;
}

//Auxialiary for specific constructor
template <typename Data>
typename BinaryTree<Data>::Node& BTInOrderIterator<Data>::LeftMostNode(const typename BinaryTree<Data>::Node& root){
  struct BinaryTree<Data>::Node current;
  if(root == nullptr) {
    current = nullptr;
  }
  else{
    current =root;
    if(current.HasLeftChild()){
      stack.Push(current->LeftChild());
      LeftMostNode(current->LeftChild());
    }
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
    BTBreadthIterator<Data> *tmp=new BTBreadthIterator<Data>(iterator);
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
  while(current !=nullptr){
    stack.Push(current);

    if(current->HasRightChild){
      current=current->RightChild;
      stack.Push(current);
    }
    else  if (current->HasLeftChild()){
      while (current->HasLeftChild()) {
        current=current->LeftChild();
        stack.Push(current);
      }
    }
    else{
      stack.TopNPop();

    }
  }
  return *this;
}
/* ************************************************************************** */
//BTBreadthIterator class functions (Ampiezza)

//Specific constructor

template <typename Data>
BTBreadthIterator<Data>::BTBreadthIterator(const BinaryTree<Data>& binarytree){
  current= &binarytree.Root();
  queue=nullptr;
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
Data& BTBreadthIterator<Data>::operator*(){
  return current->Element();
}
//++ operator
template <typename Data>
BTBreadthIterator<Data>& BTBreadthIterator<Data>::operator++(){
while(current !=nullptr){
   queue.Enqueue(current);

   if(current->HasLeftChild()){
     queue.Enqueue(current->LeftChild());
   }
   if(current->HasRightChild()){
     queue.Enqueue(current->RightChild());
   }
   if(!queue.Empty()){
     queue.HeadNDequeue();
   }
 }
}

//Terminated function
template <typename Data>
bool BTBreadthIterator<Data>::Terminated(){
  return (current == nullptr);
}

}
/* ************************************************************************** */
