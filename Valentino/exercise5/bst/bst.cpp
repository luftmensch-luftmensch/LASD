
namespace lasd {

/* ************************************************************************** */
//BST member functions

//constructor
template<typename Data>
BST<Data>::BST(): BinaryTreeLnk<Data>::BinaryTreeLnk(){}

//Specific constructor
template <typename Data>
BST<Data>::BST(const LinearContainer<Data>& con){

  int index=0;
  while(index<con.Size()){
    Insert(con[index]);
    index++;
  }
}

/* ************************************************************************** */
//Copy constructor
template<typename Data>
BST<Data>::BST(const BST<Data> &bst): BinaryTreeLnk<Data>::BinaryTreeLnk(bst){

}

//Move constructor
template<typename Data>
BST<Data>::BST(BST<Data>&& bst)noexcept: BinaryTreeLnk<Data>::BinaryTreeLnk(std::move(bst)){

}

/* ************************************************************************** */
//Copy assignment
template <typename Data>
BST<Data>& BST<Data>::operator=(const BST<Data>& bst){

  BinaryTreeLnk<Data>::operator=(bst);
  return *this;
}

//Move assignment
template <typename Data>
BST<Data>& BST<Data>::operator=(BST<Data>&& bst) noexcept {

  BinaryTreeLnk<Data>::operator=(std::move(bst));
  return *this;
}

/* ************************************************************************** */

//Comparison operator
template <typename Data>
bool BST<Data>::operator==(const BST<Data>& bst) const noexcept {
                        //if the two sizes are different, returns false
  if(bst.Size()!=dim){
    return false;
  }
  else{

    BTInOrderIterator<Data> firstiterator(*this);
    BTInOrderIterator<Data> seconditerator(bst);

    while(firstiterator.Terminated()==false){
      if(*firstiterator == *seconditerator){
        ++firstiterator;
        ++seconditerator;
      }
      else{
        return false;
      }
    }
    return true;
  }
}


//Other comparison operator
template <typename Data>
bool BST<Data>::operator!=(const BST<Data>& bst) const noexcept {

  return !(*this == bst);
}

/* ************************************************************************** */
//Specific member functions

//Insert function(copy)
template <typename Data>
void BST<Data>::Insert(const Data& value){

  NodeLnk*& ret_index = FindPointerTo(root,value);

  if(ret_index==nullptr){
    ret_index=new NodeLnk(value);
    dim++;
  }
}

//Insert function(move)
template <typename Data>
void BST<Data>::Insert(Data&& value){

  NodeLnk*& ret_index = FindPointerTo(root,value);

  if(ret_index==nullptr){
    ret_index=new NodeLnk(std::move(value));
    dim++;
  }
}

//Remove function
template <typename Data>
void BST<Data>::Remove(const Data& value){

  NodeLnk* todelete=Detach(FindPointerTo(root,value));
  delete todelete;
}

//Min function
template<typename Data>
const Data& BST<Data>::Min() const {

  if(root==nullptr){
    throw std::length_error("The tree is empty!");
  }
  else{
    NodeLnk* min=FindPointerToMin(root);
    return min->value;
  }
}

//MinNRemove function
template <typename Data>
Data BST<Data>::MinNRemove(){

  if(root==nullptr){
    throw std::length_error("The tree is empty!");
  }
  else{
    Data min=DataNDelete(DetachMin(root));
    return min;
  }
}

//RemoveMin function
template<typename Data>
void BST<Data>::RemoveMin(){

  if(root==nullptr){
    throw std::length_error("The tree is empty!");
  }
  else{
    NodeLnk* toremove=DetachMin(root);
    delete toremove;
  }
}

//Max function
template <typename Data>
const Data& BST<Data>::Max() const {

  if(root==nullptr){
    throw std::length_error("The tree is empty!");
  }
  else{
    NodeLnk* max=FindPointerToMax(root);
    return max->value;
  }
}

//MaxNRemove function
template <typename Data>
Data BST<Data>::MaxNRemove(){

  if(root==nullptr){
    throw std::length_error("The tree is empty!");
  }
  else{
    Data max=DataNDelete(DetachMax(root));
    return max;
  }
}

//RemoveMax function
template<typename Data>
void BST<Data>::RemoveMax(){

  if(root==nullptr){
    throw std::length_error("The tree is empty!");
  }
  else{
    NodeLnk* toremove=DetachMax(root);
    delete toremove;
  }
}

//Predecessor function
template <typename Data>
const Data& BST<Data>::Predecessor(const Data& value) const {

  NodeLnk* const* pred=&FindPointerToPredecessor(root,value);
  if(pred == nullptr){
    throw std::length_error("Predecessor not found");
  }
  else{
    return (*pred)->value;
  }
}

//PredecessorNRemove function
template <typename Data>
Data BST<Data>::PredecessorNRemove(const Data& value){

  NodeLnk*& toremove=FindPointerToPredecessor(root,value);
  if(toremove==nullptr){
    throw std::length_error("Predecessor not found");
  }
  else{
    Data pred=DataNDelete(Detach(toremove));
    return pred;
  }
}

//RemovePredecessor function
template <typename Data>
void BST<Data>::RemovePredecessor(const Data& value){

  NodeLnk*& toremove=FindPointerToPredecessor(root,value);
  if(toremove==nullptr){
    throw std::length_error("Predecessor not found");
  }
  else{
    NodeLnk* pred=Detach(toremove);
    delete pred;
  }
}

//Successor function
template <typename Data>
const Data& BST<Data>::Successor(const Data& value) const {

  NodeLnk* const* succ=&FindPointerToSuccessor(root,value);
  if(succ == nullptr){
    throw std::length_error("Successor not found");
  }
  else{
    return (*succ)->value;
  }
}

//SuccessorNRemove function
template <typename Data>
Data BST<Data>::SuccessorNRemove(const Data& dat){

  NodeLnk*& toremove=FindPointerToSuccessor(root,dat);
  if(toremove==nullptr){
    throw std::length_error("Successor not found");
  }
  else{
    Data succ=DataNDelete(Detach(toremove));
    return succ;
  }
}

//RemoveSuccessor function
template <typename Data>
void BST<Data>::RemoveSuccessor(const Data& value){

  NodeLnk*& toremove=FindPointerToSuccessor(root,value);
  if(toremove==nullptr){
    throw std::length_error("Successor not found");
  }
  else{
    NodeLnk* succ=Detach(toremove);
    delete succ;
  }
}

/* ************************************************************************** */
//Specific member functions (inherited from TestableContainer)
template <typename Data>
bool BST<Data>::Exists(const Data& value) const noexcept {

  NodeLnk* toexists=FindPointerTo(root,value);

  if(toexists==nullptr){
    return false;
  }
  else{
    return true;
  }
}

/* ************************************************************************** */
//Auxiliary member functions

//DataNDelete function
template<typename Data>
Data BST<Data>::DataNDelete(NodeLnk* todelete){

  Data value=todelete->value;
  delete todelete;
  return value;
}

//Detach function
template<typename Data>
typename BST<Data>::NodeLnk* BST<Data>::Detach(NodeLnk*& todetach) noexcept {

  if(todetach!=nullptr){
    NodeLnk* res;
    if(todetach->left==nullptr){
      res=SkipOnRight(todetach);
      return res;
    }
    else if(todetach->right==nullptr){
      res=SkipOnLeft(todetach);
      return res;
    }
    else{                    //if the node has left and right child, detach the max of the left subtree
                             //and swap the value field of the two nodes (the node to detach and the max)
      NodeLnk* max=DetachMax(todetach->left);
      std::swap(todetach->value,max->value);
      return max;
    }
  }
  return nullptr;
}

//DetachMin function
template<typename Data>
typename BST<Data>::NodeLnk* BST<Data>::DetachMin(NodeLnk*& root) noexcept {

  NodeLnk* res=SkipOnRight(FindPointerToMin(root));
  return res;
}

//DetachMax function
template<typename Data>
typename BST<Data>::NodeLnk* BST<Data>::DetachMax(NodeLnk*& root) noexcept {

  NodeLnk* res=SkipOnLeft(FindPointerToMax(root));
  return res;
}

//SkipOnLeft function
template <typename Data>
typename BST<Data>::NodeLnk* BST<Data>::SkipOnLeft(NodeLnk*& node) noexcept {

  NodeLnk* res;
  if(node!=nullptr){
    std::swap(res, node->left);
    std::swap(res,node);
    dim--;
  }
  return res;
}

//SkipOnRight function
template <typename Data>
typename BST<Data>::NodeLnk* BST<Data>::SkipOnRight(NodeLnk*& node) noexcept {

  NodeLnk* res;
  if(node!=nullptr){
    std::swap(res, node->right);
    std::swap(res,node);
    dim--;
  }
  return res;
}

//FindPointerToMin function (const)
template<typename Data>
typename BST<Data>::NodeLnk* const& BST<Data>::FindPointerToMin(NodeLnk* const& node) const noexcept {

  NodeLnk* const* min=&node;
  NodeLnk* currentnode=node;
  if(currentnode!=nullptr){
    while(currentnode->left!=nullptr){
      min=&currentnode->left;
      currentnode=currentnode->left;
    }
  }
  return *min;
}

//FindPointerToMin function (non-const)
template<typename Data>
typename BST<Data>::NodeLnk*& BST<Data>::FindPointerToMin(NodeLnk*& node) noexcept {

  return const_cast<NodeLnk*&>(static_cast<const BST<Data>*>(this)->FindPointerToMin(node));
}

//FindPointerToMax function (const)
template<typename Data>
typename BST<Data>::NodeLnk* const& BST<Data>::FindPointerToMax(NodeLnk* const& node) const noexcept {

  NodeLnk* const* max=&node;
  NodeLnk* currentnode=node;
  if(currentnode!=nullptr){
    while(currentnode->right!=nullptr){
      max=&currentnode->right;
      currentnode=currentnode->right;
    }
  }
  return *max;
}

//FindPointerToMax function (non-const)
template<typename Data>
typename BST<Data>::NodeLnk*& BST<Data>::FindPointerToMax(NodeLnk*& node) noexcept {

  return const_cast<NodeLnk*&>(static_cast<const BST<Data>*>(this)->FindPointerToMax(node));
}

//FindPointerTo function (grazie benny)
template<typename Data>
typename BST<Data>::NodeLnk* const& BST<Data>::FindPointerTo(NodeLnk* const& node, Data key) const noexcept {

  NodeLnk* currentnode=node;
  NodeLnk* const* res=&node;

  while(currentnode!=nullptr && currentnode->value!=key){
    if(key < currentnode->value){
      res=&currentnode->left;
      currentnode=currentnode->left;
    }
    else if(key > currentnode->value){
      res=&currentnode->right;
      currentnode=currentnode->right;
    }
  }
  return *res;
}

//FindPointerTo function (non-const)
template<typename Data>
typename BST<Data>::NodeLnk*& BST<Data>::FindPointerTo(NodeLnk*& node, Data key) noexcept {

  return const_cast<NodeLnk*&>(static_cast<const BST<Data>*>(this)->FindPointerTo(node,key));
}

//FindPointerToPredecessor function
template<typename Data>
typename BST<Data>::NodeLnk* const& BST<Data>::FindPointerToPredecessor(NodeLnk* const& node, Data key) const noexcept {

  NodeLnk* const* currentnode=&node;
  NodeLnk* const* pred=nullptr;

  while( (*currentnode) != nullptr && (*currentnode)->value != key ){
    if( (*currentnode)->value > key ){
      currentnode=&(*currentnode)->left;
    }
    else if( (*currentnode)->value < key ){
      pred=currentnode;
      currentnode=&(*currentnode)->right;
    }
  }

  if( (*currentnode) != nullptr && (*currentnode)->left != nullptr ){
    pred=&FindPointerToMax((*currentnode)->left);
  }
  return *pred;
}

//FindPointerToPredecessor function (non-const)
template<typename Data>
typename BST<Data>::NodeLnk*& BST<Data>::FindPointerToPredecessor(NodeLnk*& node, Data key) noexcept {

  return const_cast<NodeLnk*&>(static_cast<const BST<Data>*>(this)->FindPointerToPredecessor(node,key));
}

//FindPointerToSuccessor function
template<typename Data>
typename BST<Data>::NodeLnk* const& BST<Data>::FindPointerToSuccessor(NodeLnk* const& node, Data key) const noexcept {

  NodeLnk* const* currentnode=&node;
  NodeLnk* const* succ=nullptr;

  while( (*currentnode) != nullptr && (*currentnode)->value !=key ){

    if( (*currentnode)->value > key){
      succ=currentnode;
      currentnode=&(*currentnode)->left;
    }
    else if( (*currentnode)->value < key ){
      currentnode=&(*currentnode)->right;
    }
  }
  if( (*currentnode) != nullptr && (*currentnode)->right != nullptr ){
    succ=&FindPointerToMin((*currentnode)->right);
  }
  return *succ;
}

//FindPointerToSuccessor function (non-const)
template<typename Data>
typename BST<Data>::NodeLnk*& BST<Data>::FindPointerToSuccessor(NodeLnk*& node, Data key) noexcept {

  return const_cast<NodeLnk*&>(static_cast<const BST<Data>*>(this)->FindPointerToSuccessor(node,key));
}

}
