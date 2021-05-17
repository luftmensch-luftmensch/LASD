
namespace lasd {

/* ************************************************************************** */
//Specific constructor
template <typename Data>
BST<Data>::BST(const LinearContainer<Data>& con){
  for(unsigned long index=0; index<con.Size(); index++){
    Insert(con[index]);
  }
}

/* ************************************************************************** */
//Copy constructor
template<typename Data>
BST<Data>::BST(const BST<Data> &bst): BinaryTreeLnk<Data>::BinaryTreeLnk(bst) {}


//Move constructor
template<typename Data>
BST<Data>::BST(BST<Data>&& bst)noexcept: BinaryTreeLnk<Data>::BinaryTreeLnk(std::move(bst)) {}

/* ************************************************************************** */
//Copy assignment

template <typename Data>
BST<Data>& BST<Data>::operator=(const BST<Data>& bst){
  BinaryTreeLnk<Data>::operator=(bst);
  return *this;
}
//Move assignment
template <typename Data>
BST<Data>& BST<Data>::operator=(BST<Data>&& bst)noexcept{
  BinaryTreeLnk<Data>::operator=(std::move(bst));
  return *this;
}

/* ************************************************************************** */

//Comparison operator
template <typename Data>
inline bool BST<Data>::operator==(const BST<Data>& bst)const noexcept{
  if(dim==bst.Size()){
    BTInOrderIterator<Data> itr1(*this);
    BTInOrderIterator<Data> itr2(bst);
    for(; !itr1.Terminated(); ++itr1,++itr2){
      if(*itr1 != *itr2){
        return false;
      }
    }
    return true;
  }
  return false;
}

//Other comparison operator
template <typename Data>
inline bool BST<Data>::operator!=(const BST<Data>& bst)const noexcept{
  return !(*this == bst);
}

/* ************************************************************************** */
//Specific member functions

//Insert function(copy)
template <typename Data>
void BST<Data>::Insert(const Data & d){
  NodeLnk*& pointer=FindPointerTo(root, d);
  if(pointer==nullptr){
    pointer=new NodeLnk(d);
    dim++;
  }
}

//Insert function(move)
template <typename Data>
void BST<Data>::Insert(Data && d){
  NodeLnk*& pointer=FindPointerTo(root, d);
  if(pointer==nullptr){
    pointer=new NodeLnk(std::move(d));
    dim++;
  }
}
//Remove function
template <typename Data>
void BST<Data>::Remove(const Data& dat){
  delete Detach(FindPointerTo(root,dat));
}

//Min function
template<typename Data>
const Data& BST<Data>::Min()const {
  if(root!=nullptr){

    return FindPointerToMin(root)->value;
  }
  else{
    throw std::length_error("The tree is empty!");
  }
}
//MinNRemove function
template <typename Data>
Data BST<Data>::MinNRemove(){
  if(root!=nullptr){
    return DataNDelete(DetachMin(root));
  }
  else{
    throw std::length_error("The tree is empty!");
  }
}
//RemoveMin function
template<typename Data>
void BST<Data>::RemoveMin(){
  if(root!=nullptr){
    delete DetachMin(root);
  }
  else{
    throw std::length_error("The tree is empty!");
  }
}
//Max function
template <typename Data>
const Data& BST<Data>::Max()const{
  if(root!=nullptr){
    return FindPointerToMax(root)->value;
  }
  else{
    throw std::length_error("The tree is empty!");
  }
}
//MaxNRemove function
template <typename Data>
Data BST<Data>::MaxNRemove(){
  if(root!=nullptr){
    return DataNDelete(DetachMax(root));
  }
  else{
    throw std::length_error("The tree is empty!");
  }
}
//RemoveMax function
template<typename Data>
void BST<Data>::RemoveMax(){
  if(root!=nullptr){
    delete DetachMax(root);
  }
  else{
    throw std::length_error("The tree is empty!");
  }
}
//Predecessor function
template <typename Data>
const Data& BST<Data>::Predecessor(const Data& dat) const{
  //NodeLnk* const tmp=FindPointerToPredecessor(root,dat);
  //NodeLnk* const* ptr=&tmp;
  NodeLnk* const* ptr=&FindPointerToPredecessor(root,dat);
  if(ptr !=nullptr){
    return (*ptr)->value;
  }
  else{
    throw std::length_error("Predecessor not found");
  }
  //delete ptr;
}
//PredecessorNRemove function
template <typename Data>
Data BST<Data>::PredecessorNRemove(const Data& dat){
  NodeLnk** ptr=&FindPointerToPredecessor(root,dat);
  if(ptr!=nullptr){
    return DataNDelete(Detach(*ptr));
  }
  else{
    throw std::length_error("Predecessor not found");
  }
}

//RemovePredecessor function
template <typename Data>
void BST<Data>::RemovePredecessor(const Data& dat){
  NodeLnk** ptr=&FindPointerToPredecessor(root,dat);
  if(ptr!=nullptr){
    delete Detach(*ptr);
  }
  else{
    throw std::length_error("Predecessor not found");
  }
}
//Successor function
template <typename Data>
const Data& BST<Data>::Successor(const Data& dat) const{
  //NodeLnk* const tmp=FindPointerToSuccessor(root,dat);
  //NodeLnk* const* ptr=&tmp;
  NodeLnk* const* ptr=&FindPointerToSuccessor(root,dat);
  if(ptr !=nullptr){
    return (*ptr)->value;
  }
  else{
    throw std::length_error("Successor not found");
  }
  //delete ptr;
}
//SuccessorNRemove function
template <typename Data>
Data BST<Data>::SuccessorNRemove(const Data& dat){
  NodeLnk** ptr=&FindPointerToSuccessor(root,dat);
  if(ptr!=nullptr){
    return DataNDelete(Detach(*ptr));
  }
  else{
    throw std::length_error("Successor not found");
  }
}

//RemoveSuccessor function
template <typename Data>
void BST<Data>::RemoveSuccessor(const Data& dat){
  NodeLnk** ptr=&FindPointerToSuccessor(root,dat);
  if(ptr!=nullptr){
    delete Detach(*ptr);
  }
  else{
    throw std::length_error("Successor not found");
  }
}
/* ************************************************************************** */
//Specific member functions (inherited from TestableContainer)
template <typename Data>
bool BST<Data>::Exists(const Data& dat)const noexcept{
  return (FindPointerTo(root,dat) !=nullptr);
}

/* ************************************************************************** */
//Auxiliary member functions

//DataNDelete function
template<typename Data>
Data BST<Data>::DataNDelete(NodeLnk* ptr){
  Data dat {};
  std::swap(dat, ptr->value);
  delete ptr;
  return dat;
}
//Detach function
template<typename Data>
typename BST<Data>::NodeLnk* BST<Data>::Detach(typename BST<Data>::NodeLnk*& nod) noexcept{
  if(nod!=nullptr){
    if(nod->left==nullptr){
      return SkipOnRight(nod);
    }
    else if(nod->right==nullptr){
      return SkipOnLeft(nod);
    }
    else{
      NodeLnk* max=DetachMax(nod->left);
      std::swap(nod->value,max->value);
      return max;
    }
  }
  return nullptr;
}
//DetachMin function
template<typename Data>
typename BST<Data>::NodeLnk* BST<Data>::DetachMin(typename BST<Data>::NodeLnk*& nod)noexcept{
  return SkipOnRight(FindPointerToMin(nod));
}

//DetachMax function
template<typename Data>
typename BST<Data>::NodeLnk* BST<Data>::DetachMax(typename BST<Data>::NodeLnk*& nod)noexcept{
  return SkipOnLeft(FindPointerToMax(nod));
}
//SkipOnLeft function
template <typename Data>
typename BST<Data>::NodeLnk* BST<Data>::SkipOnLeft(typename BST<Data>::NodeLnk*& nod) noexcept{
  NodeLnk* lef=nullptr;
  if(nod!=nullptr){
    std::swap(lef, nod->left);
    std::swap(lef,nod);
    --dim;
  }
  return lef;
}
//SkipOnRight function
template <typename Data>
typename BST<Data>::NodeLnk* BST<Data>::SkipOnRight(typename BST<Data>::NodeLnk*& nod) noexcept{
  NodeLnk* rig=nullptr;
  if(nod!=nullptr){
    std::swap(rig, nod->right);
    std::swap(rig,nod);
    --dim;
  }
  return rig;
}
//FindPointerToMin function (const)
template<typename Data>
typename BST<Data>::NodeLnk* const& BST<Data>::FindPointerToMin(typename BST<Data>::NodeLnk* const& nod)const noexcept{
  NodeLnk* const* ptr=&nod;
  NodeLnk* curr=nod;
  if(curr!=nullptr){
    while(curr->left!=nullptr){
      ptr=&curr->left;
      curr=curr->left;
    }
  }
  return *ptr;
}
//FindPointerToMin function (non-const)
template<typename Data>
typename BST<Data>::NodeLnk*& BST<Data>::FindPointerToMin(typename BST<Data>::NodeLnk*& nod) noexcept{
  return const_cast<NodeLnk*&>(static_cast<const BST<Data>*>(this)->FindPointerToMin(nod));
}

//FindPointerToMax function (const)
template<typename Data>
typename BST<Data>::NodeLnk* const& BST<Data>::FindPointerToMax(typename BST<Data>::NodeLnk* const& nod)const noexcept{
  NodeLnk* const* ptr=&nod;
  NodeLnk* curr=nod;
  if(curr!=nullptr){
    while(curr->right!=nullptr){
      ptr=&curr->right;
      curr=curr->right;
    }
  }
  return *ptr;
}
//FindPointerToMax function (non-const)
template<typename Data>
typename BST<Data>::NodeLnk*& BST<Data>::FindPointerToMax(typename BST<Data>::NodeLnk*& nod) noexcept{
  return const_cast<NodeLnk*&>(static_cast<const BST<Data> *>(this)->FindPointerToMax(nod));
}

//FindPointerTo function
template<typename Data>
typename BST<Data>::NodeLnk* const& BST<Data>::FindPointerTo(typename BST<Data>::NodeLnk* const& nod, Data dat) const noexcept{
  NodeLnk* const* ptr=&nod;
  NodeLnk* curr=nod;

   while(curr!=nullptr&&curr->value!=dat){
     if(dat<curr->value){
       ptr=&curr->left;
       curr=curr->left;
     }
     else if(dat>curr->value){
       ptr=&curr->right;
       curr=curr->right;
     }
   }
  return *ptr;
}

//FindPointerTo function (non-const)
template<typename Data>
typename BST<Data>::NodeLnk*& BST<Data>::FindPointerTo(typename BST<Data>::NodeLnk*& nod, Data dat) noexcept{
  return const_cast<NodeLnk*&>(static_cast<const BST<Data>*>(this)->FindPointerTo(nod,dat));
}

//FindPointerToPredecessor function
template<typename Data>
typename BST<Data>::NodeLnk* const& BST<Data>::FindPointerToPredecessor(typename BST<Data>::NodeLnk* const& nod, Data dat) const noexcept{
  NodeLnk* const* pred=nullptr;
  NodeLnk* const* curr=&nod;

  while((*curr)!=nullptr&&(*curr)->value !=dat){
    if((*curr)->value > dat){
      curr=&(*curr)->left;
    }
    else if((*curr)->value < dat){
      pred=curr;
      curr=&(*curr)->right;
    }
  }
  if((*curr)!=nullptr&&(*curr)->left!=nullptr){
    pred=&FindPointerToMax((*curr)->left);
  }

  return *pred;
}

//FindPointerToPredecessor function (non-const)
template<typename Data>
typename BST<Data>::NodeLnk*& BST<Data>::FindPointerToPredecessor(typename BST<Data>::NodeLnk*& nod, Data dat) noexcept{
  return const_cast<NodeLnk*&>(static_cast<const BST<Data>*>(this)->FindPointerToPredecessor(nod,dat));
}

//FindPointerToSuccessor function
template<typename Data>
typename BST<Data>::NodeLnk* const& BST<Data>::FindPointerToSuccessor(typename BST<Data>::NodeLnk* const& nod, Data dat) const noexcept{
  typename BST<Data>::NodeLnk* const* succ=nullptr;
  typename BST<Data>::NodeLnk* const* curr=&nod;

  while((*curr)!=nullptr&&(*curr)->value !=dat){
    if((*curr)->value < dat){
      curr=&(*curr)->right;
    }
    else if((*curr)->value > dat){
      succ=curr;
      curr=&(*curr)->left;
    }
  }
  if((*curr)!=nullptr&&(*curr)->right!=nullptr){
    succ=&FindPointerToMin((*curr)->right);
  }
  return *succ;
}
//FindPointerToSuccessor function (non-const)
template<typename Data>
typename BST<Data>::NodeLnk*& BST<Data>::FindPointerToSuccessor(typename BST<Data>::NodeLnk*& nod, Data dat) noexcept{
  return const_cast<NodeLnk*&>(static_cast<const BST<Data>*>(this)->FindPointerToSuccessor(nod,dat));
}

/* ************************************************************************** */
template <typename Data>
const typename BST<Data>::NodeLnk & BST<Data>::Root() const{
  if (root == nullptr)
    throw std::out_of_range("L'albero e' vuoto!");

  return static_cast<const NodeLnk&>(BinaryTreeLnk<Data>::Root());
}

template <typename Data>
typename BST<Data>::NodeLnk & BST<Data>::Root(){
  return const_cast<NodeLnk&>(const_cast<const BST<Data>*>(this)->Root());
}


}
