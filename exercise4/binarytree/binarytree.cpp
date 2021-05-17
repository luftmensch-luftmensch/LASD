
namespace lasd {

/* ************************************************************************** */
//BinaryTree<Data>::Node functions

//operator ==
template <typename Data>
bool BinaryTree<Data>::Node::operator==(const Node& node) const noexcept{

  return this == &node;
}
//operator !=
template <typename Data>
bool BinaryTree<Data>::Node::operator!=(const Node& node) const noexcept{
  return this != &node;
}

//IsLeaf() function: returns true if the current node has no childs, false otherwise
template <typename Data>
bool BinaryTree<Data>::Node::isLeaf() noexcept {

  if(!HasLeftChild()&& !HasRightChild()){
    return true;
  }
  else{
    return false;
  }
}

/* ************************************************************************** */
//BinaryTree<Data> functions

//Auxiliary function for comparison operator
template<typename Data>
bool BinaryTree<Data>::EqualTrees(const typename BinaryTree<Data>::Node* firsttreenode,const typename BinaryTree<Data>::Node* secondtreenode)const noexcept{

  bool first = true, second = true;

  if(firsttreenode->Element() != secondtreenode->Element()){
    return false;
  }
  if((firsttreenode->HasLeftChild() != secondtreenode->HasLeftChild()) || (firsttreenode->HasRightChild() != secondtreenode->HasRightChild())){
    return false;
  }
  if(firsttreenode->HasLeftChild() && secondtreenode->HasLeftChild()){
    first = EqualTrees(&firsttreenode->LeftChild(),&secondtreenode->LeftChild());
  }
  if(firsttreenode->HasRightChild() && secondtreenode->HasRightChild()){
    second = EqualTrees(&firsttreenode->RightChild(), &secondtreenode->RightChild());
  }
  return first && second;

}

//operator ==: returns true if the two trees are equal
template<typename Data>
bool BinaryTree<Data>::operator==(const BinaryTree<Data>& binarytree) const noexcept{

  if(dim!=binarytree.dim){//se hanno size diverse, sono gia' due alberi diversi.
    return false;
  }
  else if(dim==0 && binarytree.dim==0){
    return true;
  }else{
    return EqualTrees(&Root(),&binarytree.Root());
  }
}

//operator !=: returns false if the two trees are not equal
template <typename Data>
bool BinaryTree<Data>::operator!=(const BinaryTree<Data>& bT) const noexcept{

  return !(*this == bT);
}

// Specific member functions (inherited from MappableContainer)

template <typename Data>
void BinaryTree<Data>::MapPreOrder(MapFunctor mapFunctor, void* par) noexcept{

  if(!Empty()){
    AuxMapPreOrder(mapFunctor, par, &Root());
  }
}

template <typename Data>
void BinaryTree<Data>::MapPostOrder(MapFunctor mapFunctor, void* par) noexcept{

  if(!Empty()){
    AuxMapPostOrder(mapFunctor, par, &Root());
  }
}

// Specific member functions (inherited from FoldableContainer)

template <typename Data>
void BinaryTree<Data>::FoldPreOrder(FoldFunctor foldFunctor, const void* par, void* acc) const noexcept{

  if(!Empty()){
    AuxFoldPreOrder(foldFunctor, par, acc, &Root());
  }
}

template <typename Data>
void BinaryTree<Data>::FoldPostOrder(FoldFunctor foldFunctor, const void* par, void* acc) const noexcept{

  if(!Empty()){
    AuxFoldPostOrder(foldFunctor, par, acc, &Root());
  }
}

// Specific member functions (inherited from InOrderMappableContainer)

template <typename Data>
void BinaryTree<Data>::MapInOrder(MapFunctor mapFunctor, void* par) noexcept{

  if(!Empty()){
    AuxMapInOrder(mapFunctor, par, &Root());
  }

}

// Specific member functions (inherited from InOrderFoldableContainer)

template <typename Data>
void BinaryTree<Data>::FoldInOrder(FoldFunctor foldFunctor, const void* par, void* acc) const noexcept{

  if(!Empty()){
    AuxFoldInOrder(foldFunctor, par, acc, &Root());
  }
}

// Specific member functions (inherited from BreadthMappableContainer)

template <typename Data>
void BinaryTree<Data>::MapBreadth(MapFunctor mapFunctor, void* par) noexcept{

  if(!Empty()){
    AuxMapBreadth(mapFunctor, par, &Root());
  }
}

// Specific member functions (inherited from BreadthFoldableContainer)

template <typename Data>
void BinaryTree<Data>::FoldBreadth(FoldFunctor foldFunctor, const void* par, void* acc) const noexcept{

  if(!Empty()){
    AuxFoldBreadth(foldFunctor, par, acc, &Root());
  }
}

// Auxiliary member functions (for PreOrderMappableContainer)
template <typename Data>
void BinaryTree<Data>::AuxMapPreOrder(MapFunctor mapFunctor, void* par, Node* currentnode) noexcept{
    //center, sx, dx
  mapFunctor(currentnode->Element(), par);

  if(currentnode->HasLeftChild()){
    AuxMapPreOrder(mapFunctor, par, &currentnode->LeftChild());
  }
  if(currentnode->HasRightChild()){
    AuxMapPreOrder(mapFunctor, par, &currentnode->RightChild());
  }
}

// Auxiliary member functions (for PreOrderFoldableContainer)
template <typename Data>
void BinaryTree<Data>::AuxFoldPreOrder(FoldFunctor foldFunctor, const void* par, void* acc, const Node* currentnode) const noexcept{
  //center, sx, dx
  foldFunctor(currentnode->Element(), par, acc);

  if(currentnode->HasLeftChild()){
    AuxFoldPreOrder(foldFunctor, par, acc, &currentnode->LeftChild());
  }
  if(currentnode->HasRightChild()){
    AuxFoldPreOrder(foldFunctor, par, acc, &currentnode->RightChild());
  }
}

// Auxiliary member functions (for PostOrderMappableContainer)
template <typename Data>
void BinaryTree<Data>::AuxMapPostOrder(MapFunctor mapFunctor, void* par, Node* currentnode) noexcept{
  //sx, dx, center
  if(currentnode->HasLeftChild()){
    AuxMapPostOrder(mapFunctor, par, &currentnode->LeftChild());
  }
  if(currentnode->HasRightChild()){
    AuxMapPostOrder(mapFunctor, par, &currentnode->RightChild());
  }
  mapFunctor(currentnode->Element(), par);
}

// Auxiliary member functions (for PostOrderFoldableContainer)
template <typename Data>
void BinaryTree<Data>::AuxFoldPostOrder(FoldFunctor foldFunctor, const void* par, void* acc, const Node* currentnode) const noexcept{
  //dx, sx, center
  if(currentnode->HasLeftChild()){
    AuxFoldPostOrder(foldFunctor, par, acc, &currentnode->LeftChild());
  }
  if(currentnode->HasRightChild()){
    AuxFoldPostOrder(foldFunctor, par, acc, &currentnode->RightChild());
  }
  foldFunctor(currentnode->Element(), par, acc);
}

// Auxiliary member functions (for InOrderMappableContainer)
template <typename Data>
void BinaryTree<Data>::AuxMapInOrder(MapFunctor mapFunctor, void* par, Node* currentnode) noexcept{
  //sx, center, dx
  if(currentnode->HasLeftChild()){
    AuxMapInOrder(mapFunctor, par, &currentnode->LeftChild());
  }

  mapFunctor(currentnode->Element(), par);

  if(currentnode->HasRightChild()){
    AuxMapInOrder(mapFunctor, par, &currentnode->RightChild());
  }
}

// Auxiliary member functions (for InOrderFoldableContainer)

template <typename Data>
void BinaryTree<Data>::AuxFoldInOrder(FoldFunctor foldFunctor, const void* par, void* acc, const Node* node) const noexcept{
  //sx, center, dx
  if(node->HasLeftChild()){
    AuxFoldInOrder(foldFunctor, par, acc, &node->LeftChild());
  }
  foldFunctor(node->Element(), par, acc);

  if(node->HasRightChild()){
    AuxFoldInOrder(foldFunctor, par, acc, &node->RightChild());
  }
}

// Auxiliary member functions (for BreadthMappableContainer)
template <typename Data>
void BinaryTree<Data>::AuxMapBreadth(MapFunctor mapFunctor, void* par, Node* node) noexcept{

  QueueLst<BinaryTree<Data>::Node*> queue;
  if(node != nullptr){
    queue.Enqueue(node);
  }
  while(!queue.Empty()){

    BinaryTree<Data>::Node* current;
    current= queue.HeadNDequeue();

    mapFunctor(current->Element(),par);

    if(current->HasLeftChild()){
      queue.Enqueue(&current->LeftChild());
    }
    if(current->HasRightChild()){
      queue.Enqueue(&current->RightChild());
    }
  }
}

// Auxiliary member functions (for BreadthFoldableContainer)

template <typename Data>
void BinaryTree<Data>::AuxFoldBreadth(FoldFunctor foldFunctor, const void* par, void* acc, const Node* node) const noexcept{

  QueueLst<const BinaryTree<Data>::Node*> queue;

  if(node != nullptr){
    queue.Enqueue(node);
  }
  while(!queue.Empty()){
    const BinaryTree<Data>::Node* current;
    current=queue.HeadNDequeue();

    foldFunctor(current->Element(),par,acc);

    if(current->HasLeftChild()){
      queue.Enqueue(&current->LeftChild());
    }
    if(current->HasRightChild()){
      queue.Enqueue(&current->RightChild());
    }
  }
}


/* ************************************************************************** */
//BTPreOrderIterator class functions


//Specific constructor
template <typename Data>
BTPreOrderIterator<Data>::BTPreOrderIterator(const BinaryTree<Data>& binarytree){

  if(!binarytree.Empty()){
    currnode = const_cast<typename BinaryTree<Data>::Node*>(&binarytree.Root());
  }
  else{
   currnode=nullptr;
  }

}


//Copy constuctor
template <typename Data>
BTPreOrderIterator<Data>::BTPreOrderIterator(const BTPreOrderIterator<Data>& preorderiterator){

  auxstack=preorderiterator.auxstack;
  currnode=preorderiterator.currnode;
}

//Move constructor
template <typename Data>
BTPreOrderIterator<Data>::BTPreOrderIterator(BTPreOrderIterator<Data>&& preorderiterator) noexcept{

  auxstack=preorderiterator.auxstack;
  preorderiterator.auxstack.Clear();
  currnode=preorderiterator.currnode;
  preorderiterator.currnode = nullptr;

}

//Destructor
template <typename Data>
BTPreOrderIterator<Data>::~BTPreOrderIterator(){

  currnode=nullptr;
  auxstack.Clear();
}

//Copy assignment
template <typename Data>
BTPreOrderIterator<Data>& BTPreOrderIterator<Data>::operator=(const BTPreOrderIterator& preorderiterator){

  if(this == &preorderiterator){
    return *this;
  }
  else{
    BTPreOrderIterator<Data> *tempiterator = new BTPreOrderIterator<Data>(preorderiterator);
    std::swap(*this, *tempiterator);
    delete tempiterator;
    return *this;
  }
}

//Move assignment
template <typename Data>
BTPreOrderIterator<Data>& BTPreOrderIterator<Data>::operator=(BTPreOrderIterator<Data>&& preorderiterator) noexcept{

  std::swap(currnode, preorderiterator.currnode);
  std::swap(auxstack, preorderiterator.auxstack);

  return *this;
}

//Comparison operator
template <typename  Data>
bool BTPreOrderIterator<Data>::operator==(const BTPreOrderIterator<Data>& preorderiterator) const noexcept{

  if(currnode == preorderiterator.currnode  && auxstack==preorderiterator.auxstack){
    return true;
  }
  else{
    return false;
  }
}

//Other comparison operator
template <typename  Data>
bool BTPreOrderIterator<Data>::operator!=(const BTPreOrderIterator<Data>& preorderiterator) const noexcept{

  return !(*this == preorderiterator);
}

//operator ++
template <typename Data>
BTPreOrderIterator<Data>& BTPreOrderIterator<Data>::operator++(){
                          //proceed just if the currentnode is not nullptr (not terminated)
  if(currnode!=nullptr){

    if(currnode->HasLeftChild()){

      if(currnode->HasRightChild()){

        auxstack.Push(&currnode->RightChild());
      }
      currnode=(&currnode->LeftChild());
    }
    else if(currnode->HasRightChild()){

      currnode=(&currnode->RightChild());
    }
    else{
      if(auxstack.Empty()){
        currnode=nullptr;
      }
      else{
      currnode=auxstack.TopNPop();
      }
    }
  }
  return *this;
}

//*operator
template <typename Data>
Data& BTPreOrderIterator<Data>::operator*() const{

  return currnode->Element();
}

//Terminated function
template <typename Data>
bool BTPreOrderIterator<Data>::Terminated() const noexcept{

  if(currnode==nullptr){
    return true;
  }
  else{
    return false;
  }
}


/* ************************************************************************** */
//BTPostOrderIterator class functions

//Specific constructor

template <typename Data>
BTPostOrderIterator<Data>::BTPostOrderIterator(const BinaryTree<Data>& binarytree){

  if(!binarytree.Empty()){
    currnode= const_cast<typename BinaryTree<Data>::Node*>(&binarytree.Root());
    currnode=LeftMostLeafNode(currnode);
  }
  else{
    currnode=nullptr;
  }
}

//Auxiliary for specific constructor
template <typename Data>
typename BinaryTree<Data>::Node* BTPostOrderIterator<Data>::LeftMostLeafNode(typename BinaryTree<Data>::Node* currentnode){
                                         //Go to the left most node in the tree
    while(currentnode->HasLeftChild()){
      auxstack.Push(currentnode);
      currentnode=&currentnode->LeftChild();
    }
                                         //If it has a right child, then re-apply the function starting from the right child
    if(currentnode->HasRightChild()){
      auxstack.Push(currentnode);
      currentnode=&currentnode->RightChild();
      currentnode=LeftMostLeafNode(currentnode);
    }
    return currentnode;
  }

//Copy constructor
template<typename Data>
BTPostOrderIterator<Data>::BTPostOrderIterator(const BTPostOrderIterator<Data>& postorderiterator){

    currnode=postorderiterator.currnode;
    auxstack=postorderiterator.auxstack;
}

//Move constructor
template <typename  Data>
BTPostOrderIterator<Data>::BTPostOrderIterator(BTPostOrderIterator<Data>&& postorderiterator) noexcept{

    currnode=postorderiterator.currnode;
    postorderiterator.currnode=nullptr;
    auxstack=postorderiterator.auxstack;
    postorderiterator.auxstack.Clear();
}

//Destructor
template <typename Data>
BTPostOrderIterator<Data>::~BTPostOrderIterator(){

    currnode=nullptr;
    auxstack.Clear();
}

//Copy assignment
template <typename Data>
BTPostOrderIterator<Data>& BTPostOrderIterator<Data>::operator=(const BTPostOrderIterator& postorderiterator){

    if(this == &postorderiterator){
        return *this;
    }
    BTPostOrderIterator<Data> *tmp=new BTPostOrderIterator<Data>(postorderiterator);
    std::swap(*tmp, *this);
    delete tmp;
    return *this;
}

//Move assignment
template <typename Data>
BTPostOrderIterator<Data>& BTPostOrderIterator<Data>::operator=(BTPostOrderIterator<Data>&& postorderiterator) noexcept{

  std::swap(currnode, postorderiterator.currnode);
  std::swap(auxstack, postorderiterator.auxstack);
  return *this;
}

//Comparison operator
template <typename  Data>
bool BTPostOrderIterator<Data>::operator==(const BTPostOrderIterator<Data>& postorderiterator) const noexcept{

  if(currnode == postorderiterator.currnode && auxstack==postorderiterator.auxstack){
    return true;
  }
  else{
    return false;
  }
}

//Other comparison operator
template <typename  Data>
bool BTPostOrderIterator<Data>::operator!=(const BTPostOrderIterator<Data>& iterator) const noexcept{

  return !(*this == iterator);
}

//++ operator
template <typename Data>
BTPostOrderIterator<Data>& BTPostOrderIterator<Data>::operator++(){
                          //if stack is empty, then the operator is terminated
   if(auxstack.Empty()){
     currnode=nullptr;
   }

   else{
                        //if the top of the stack has a right child that is the current node,
                        //then i need to apply the LeftMostLeaf function to the right child
     if(auxstack.Top()->HasRightChild() && !(&auxstack.Top()->RightChild()==currnode)){
       currnode=&auxstack.Top()->RightChild();
       currnode=LeftMostLeafNode(currnode);
     }
     else{
       currnode=auxstack.TopNPop();
     }
   }
  return *this;
}

//*operator
template <typename Data>
Data& BTPostOrderIterator<Data>::operator*() const{
  return currnode->Element();
}

//Terminated function
template <typename Data>
bool BTPostOrderIterator<Data>::Terminated() const noexcept{

  if(currnode==nullptr){
    return true;
  }
  else{
    return false;
  }
}

/* ************************************************************************** */
//BTInOrderIterator class functions

//Specific constructor

template <typename Data>
BTInOrderIterator<Data>::BTInOrderIterator(const BinaryTree<Data>& binarytree){

  if(!binarytree.Empty()){
    currnode=const_cast<typename BinaryTree<Data>::Node*>(&binarytree.Root());
    currnode=LeftMostNode(currnode);
  }
  else{
    currnode=nullptr;
  }
}

//Auxialiary for specific constructor
template <typename Data>
typename BinaryTree<Data>::Node* BTInOrderIterator<Data>::LeftMostNode(typename BinaryTree<Data>::Node* currentnode){

  while(currentnode->HasLeftChild()){
    auxstack.Push(currentnode);
    currentnode=(&(currentnode->LeftChild()));
  }
  return currentnode;
}

//Copy constructor
template<typename Data>
BTInOrderIterator<Data>::BTInOrderIterator(const BTInOrderIterator<Data>& inorderiterator){

  currnode=inorderiterator.currnode;
  auxstack=inorderiterator.auxstack;
}

//Move constructor
template <typename  Data>
BTInOrderIterator<Data>::BTInOrderIterator(BTInOrderIterator<Data>&& inorderiterator) noexcept{

  currnode=inorderiterator.currnode;
  inorderiterator.currnode=nullptr;
  auxstack=inorderiterator.auxstack;
  inorderiterator.auxstack=nullptr;
}

//Destructor
template <typename Data>
BTInOrderIterator<Data>::~BTInOrderIterator(){

  currnode=nullptr;
  auxstack.Clear();
}

//Copy assignment
template <typename Data>
BTInOrderIterator<Data>& BTInOrderIterator<Data>::operator=(const BTInOrderIterator& inorderiterator){

  if(this == &inorderiterator){
    return *this;
  }
  BTInOrderIterator<Data> *tempiterator=new BTInOrderIterator<Data>(inorderiterator);
  std::swap(*tempiterator, *this);
  delete tempiterator;
  return *this;
}

//Move assignment
template <typename Data>
BTInOrderIterator<Data>& BTInOrderIterator<Data>::operator=(BTInOrderIterator<Data>&& inorderiterator) noexcept{

  std::swap(currnode, inorderiterator.currnode);
  std::swap(auxstack,inorderiterator.auxstack);
  return *this;
}

//Comparison operator
template <typename  Data>
bool BTInOrderIterator<Data>::operator==(const BTInOrderIterator<Data>& inorderiterator) const noexcept{

  if(currnode == inorderiterator.currnode && auxstack==inorderiterator.auxstack){
    return true;
  }
  else{
    return false;
  }
}

//Other comparison operator
template <typename  Data>
bool BTInOrderIterator<Data>::operator!=(const BTInOrderIterator<Data>& inorderiterator) const noexcept{

  return !(*this == inorderiterator);
}

//++ operator
template <typename Data>
BTInOrderIterator<Data>& BTInOrderIterator<Data>::operator++(){

  if(!auxstack.Empty()){
     currnode=auxstack.TopNPop();

     if(currnode->HasRightChild()){
       auxstack.Push(&(currnode->RightChild()));
       LeftMostNode((&(currnode->RightChild())));
     }
  }
  else{
    currnode=nullptr;
  }

  return *this;
}

//*operator
template <typename Data>
Data& BTInOrderIterator<Data>::operator*() const{
  return currnode->Element();
}

//Terminated function
template <typename Data>
bool BTInOrderIterator<Data>::Terminated() const noexcept{

  if(currnode==nullptr){
    return true;
  }
  else{
    return false;
  }
}

/* ************************************************************************** */
//BTBreadthIterator class functions

//Specific constructor
template <typename Data>
BTBreadthIterator<Data>::BTBreadthIterator(const BinaryTree<Data>& binarytree){
  if (!binarytree.Empty()){

    currnode = const_cast<typename BinaryTree<Data>::Node*>(&binarytree.Root());
  }
  else{
    currnode=nullptr;
  }
}

//Copy constuctor
template <typename Data>
BTBreadthIterator<Data>::BTBreadthIterator(const BTBreadthIterator<Data>& breadthiterator){

  currnode=breadthiterator.currnode;
  auxqueue=breadthiterator.auxqueue;
}

//Move constructor
template <typename Data>
BTBreadthIterator<Data>::BTBreadthIterator(BTBreadthIterator<Data>&& breadthiterator) noexcept{

  currnode=breadthiterator.currnode;
  breadthiterator.currnode=nullptr;
  auxqueue=breadthiterator.auxqueue;
  breadthiterator.auxqueue=nullptr;
}

//Destructor
template <typename Data>
BTBreadthIterator<Data>::~BTBreadthIterator(){

  currnode=nullptr;
  auxqueue.Clear();
}

//Copy assignment
template <typename Data>
BTBreadthIterator<Data>& BTBreadthIterator<Data>::operator=(const BTBreadthIterator<Data>& breadthiterator){

  if(this == &breadthiterator){
    return *this;
  }
  BTBreadthIterator<Data> *tempiterator=new BTBreadthIterator<Data>(breadthiterator);
  std::swap(*tempiterator, *this);
  delete tempiterator;
  return *this;
}

//Move assignment
template <typename Data>
BTBreadthIterator<Data>& BTBreadthIterator<Data>::operator=(BTBreadthIterator<Data>&& breadthiterator) noexcept{

  std::swap(currnode, breadthiterator.currnode);
  std::swap(auxqueue, breadthiterator.auxqueue);
  return *this;
}

//Comparison operator
template <typename  Data>
bool BTBreadthIterator<Data>::operator==(const BTBreadthIterator<Data>& breadthiterator) const noexcept{

  if(currnode == breadthiterator.currnode && auxqueue==breadthiterator.auxqueue){
    return true;
  }
  else{
    return false;
  }
}

//Other comparison operator
template <typename  Data>
bool BTBreadthIterator<Data>::operator!=(const BTBreadthIterator<Data>& breadthiterator) const noexcept{

  return !(*this == breadthiterator);
}

//*operator
template <typename Data>
Data& BTBreadthIterator<Data>::operator*() const{

  return currnode->Element();
}

//++ operator
template <typename Data>
BTBreadthIterator<Data>& BTBreadthIterator<Data>::operator++(){

  if(currnode!=nullptr){
    if(currnode->HasLeftChild()){
      auxqueue.Enqueue(&currnode->LeftChild());
    }
    if(currnode->HasRightChild()){
      auxqueue.Enqueue(&currnode->RightChild());
    }
    if(auxqueue.Empty()){
      currnode=nullptr;
    }
    else{
      currnode=auxqueue.HeadNDequeue();
    }
}
return *this;
}

//Terminated function
template <typename Data>
bool BTBreadthIterator<Data>::Terminated() const noexcept{

  if(currnode==nullptr){
    return true;
  }
  else{
    return false;
  }
}

/* ************************************************************************** */

}
