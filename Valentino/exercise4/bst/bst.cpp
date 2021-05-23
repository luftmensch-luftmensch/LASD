
namespace lasd {

template <typename Data>
BST<Data>::BST(const LinearContainer<Data>& con){
  for(ulong i=0; i<con.Size(); i++){
    Insert(con[i]);
  }
}

template<typename Data>
BST<Data>::BST(const BST<Data> &BinarySearchTree): BinaryTreeLnk<Data>::BinaryTreeLnk(BinarySearchTree) {}

template<typename Data>
BST<Data>::BST(BST<Data>&& BinarySearchTree)noexcept: BinaryTreeLnk<Data>::BinaryTreeLnk(std::move(BinarySearchTree)) {}


template <typename Data>
BST<Data>& BST<Data>::operator=(const BST<Data>& BinarySearchTree){
  BinaryTreeLnk<Data>::operator=(BinarySearchTree);
  return *this;
}
template <typename Data>
BST<Data>& BST<Data>::operator=(BST<Data>&& BinarySearchTree)noexcept{
  BinaryTreeLnk<Data>::operator=(std::move(BinarySearchTree));
  return *this;
}

template <typename Data>
inline bool BST<Data>::operator==(const BST<Data>& BinarySearchTree)const noexcept{
  if (dimensione == BinarySearchTree.Size()) {
    BTInOrderIterator<Data> Iteratore1(*this);
    BTInOrderIterator<Data> Iteratore2(BinarySearchTree);
    for (; !Iteratore1.Terminated(); ++Iteratore1, ++Iteratore2) {
      if (*Iteratore1 != *Iteratore2) {
	return false;
      }
    }
    return true;
  }
  return false;
}

template <typename Data>
inline bool BST<Data>::operator!=(const BST<Data>& BinarySearchTree)const noexcept{
  return !(*this == BinarySearchTree);
}


template <typename Data>
void BST<Data>::Insert(const Data & valore){
  NodeLnk*& puntatore=FindPointerTo(root, valore);
  if(puntatore==nullptr){
    puntatore=new NodeLnk(valore);
    dimensione++;
  }
}
template <typename Data>
void BST<Data>::Remove(const Data& valore){
  delete Detach(FindPointerTo(root,valore));
}

template <typename Data>
void BST<Data>::Insert(Data && valore){
  NodeLnk*& puntatore=FindPointerTo(root, valore);
  if(puntatore==nullptr){
    puntatore=new NodeLnk(std::move(valore));
    dimensione++;
  }
}

template<typename Data>
const Data& BST<Data>::Min()const {
  if (root != nullptr) {
    return FindPointerToMin(root)->Valore;
  } else {
    throw std::length_error("L'albero è vuoto");
  }
}

template <typename Data>
const Data& BST<Data>::Max()const{
  if (root != nullptr) {
    return FindPointerToMax(root)->Valore;
  } else {
    throw std::length_error("L'albero è vuoto");
  }
}
template <typename Data>
Data BST<Data>::MinNRemove(){
  if (root != nullptr) {
    return DataNDelete(DetachMin(root));
  } else {
    throw std::length_error("L'albero è vuoto");
  }
}

template <typename Data>
Data BST<Data>::MaxNRemove(){
  if (root != nullptr) {
    return DataNDelete(DetachMax(root));
  } else {
    throw std::length_error("L'albero è vuoto");
  }
}
template<typename Data>
void BST<Data>::RemoveMin(){
  if (root != nullptr) {
    delete DetachMin(root);
  } else {
    throw std::length_error("L'albero è vuoto");
  }
}
template<typename Data>
void BST<Data>::RemoveMax(){
  if (root != nullptr) {
    delete DetachMax(root);
  } else {
    throw std::length_error("L'albero è vuoto");
  }
}
template <typename Data>
const Data& BST<Data>::Predecessor(const Data& valore) const{
  NodeLnk* const* puntatore=&FindPointerToPredecessor(root,valore);
  if(puntatore !=nullptr){
    return (*puntatore)->Valore;
  }
  else{
    throw std::length_error("Predecessore non trovato");
  }
}

template <typename Data>
const Data& BST<Data>::Successor(const Data& valore) const{
  NodeLnk* const* puntatore=&FindPointerToSuccessor(root,valore);
  if(puntatore !=nullptr){
    return (*puntatore)->Valore;
  }
  else{
    throw std::length_error("Successore non trovato");
  }
}
template <typename Data>
Data BST<Data>::PredecessorNRemove(const Data& valore){
  NodeLnk** puntatore=&FindPointerToPredecessor(root,valore);
  if(puntatore!=nullptr){
    return DataNDelete(Detach(*puntatore));
  }
  else{
    throw std::length_error("Predecessore non trovato");
  }
}

template <typename Data>
Data BST<Data>::SuccessorNRemove(const Data& valore){
  NodeLnk** puntatore=&FindPointerToSuccessor(root,valore);
  if(puntatore!=nullptr){
    return DataNDelete(Detach(*puntatore));
  }
  else{
    throw std::length_error("Successore non trovato");
  }
}
template <typename Data>
void BST<Data>::RemovePredecessor(const Data& valore){
  NodeLnk** puntatore=&FindPointerToPredecessor(root,valore);
  if(puntatore!=nullptr){
    delete Detach(*puntatore);
  }
  else{
    throw std::length_error("Predecessore non trovato");
  }
}

template <typename Data>
void BST<Data>::RemoveSuccessor(const Data& valore){
  NodeLnk** puntatore=&FindPointerToSuccessor(root,valore);
  if(puntatore!=nullptr){
    delete Detach(*puntatore);
  }
  else{
    throw std::length_error("Successore non trovato");
  }
}
template <typename Data>
bool BST<Data>::Exists(const Data& valore)const noexcept{
  return (FindPointerTo(root,valore) !=nullptr);
}


template<typename Data>
Data BST<Data>::DataNDelete(NodeLnk* puntatore){
  Data valore {};
  std::swap(valore, puntatore->Valore);
  delete puntatore;
  return valore;
}
template<typename Data>
typename BST<Data>::NodeLnk* BST<Data>::Detach(typename BST<Data>::NodeLnk*& nod) noexcept{
  if(nod!=nullptr){
    if(nod->sinistro==nullptr){
      return SkipOnRight(nod);
    }
    else if(nod->destro==nullptr){
      return SkipOnLeft(nod);
    }
    else{
      NodeLnk* max=DetachMax(nod->sinistro);
      std::swap(nod->Valore,max->Valore);
      return max;
    }
  }
  return nullptr;
}
template<typename Data>
typename BST<Data>::NodeLnk* BST<Data>::DetachMin(typename BST<Data>::NodeLnk*& nod)noexcept{
  return SkipOnRight(FindPointerToMin(nod));
}

template<typename Data>
typename BST<Data>::NodeLnk* BST<Data>::DetachMax(typename BST<Data>::NodeLnk*& nod)noexcept{
  return SkipOnLeft(FindPointerToMax(nod));
}
template <typename Data>
typename BST<Data>::NodeLnk* BST<Data>::SkipOnLeft(typename BST<Data>::NodeLnk*& nod) noexcept{
  NodeLnk* lef=nullptr;
  if(nod!=nullptr){
    std::swap(lef, nod->sinistro);
    std::swap(lef,nod);
    --dimensione;
  }
  return lef;
}
template <typename Data>
typename BST<Data>::NodeLnk* BST<Data>::SkipOnRight(typename BST<Data>::NodeLnk*& nod) noexcept{
  NodeLnk* rig=nullptr;
  if(nod!=nullptr){
    std::swap(rig, nod->destro);
    std::swap(rig,nod);
    --dimensione;
  }
  return rig;
}
template<typename Data>
typename BST<Data>::NodeLnk* const& BST<Data>::FindPointerToMin(typename BST<Data>::NodeLnk* const& nod)const noexcept{
  NodeLnk* const* puntatore=&nod;
  NodeLnk* curr=nod;
  if(curr!=nullptr){
    while(curr->sinistro!=nullptr){
      puntatore=&curr->sinistro;
      curr=curr->sinistro;
    }
  }
  return *puntatore;
}
template<typename Data>
typename BST<Data>::NodeLnk*& BST<Data>::FindPointerToMin(typename BST<Data>::NodeLnk*& nod) noexcept{
  return const_cast<NodeLnk*&>(static_cast<const BST<Data>*>(this)->FindPointerToMin(nod));
}

template<typename Data>
typename BST<Data>::NodeLnk* const& BST<Data>::FindPointerToMax(typename BST<Data>::NodeLnk* const& nod)const noexcept{
  NodeLnk* const* puntatore=&nod;
  NodeLnk* curr=nod;
  if(curr!=nullptr){
    while(curr->destro!=nullptr){
      puntatore=&curr->destro;
      curr=curr->destro;
    }
  }
  return *puntatore;
}
template<typename Data>
typename BST<Data>::NodeLnk*& BST<Data>::FindPointerToMax(typename BST<Data>::NodeLnk*& nod) noexcept{
  return const_cast<NodeLnk*&>(static_cast<const BST<Data> *>(this)->FindPointerToMax(nod));
}

template<typename Data>
typename BST<Data>::NodeLnk* const& BST<Data>::FindPointerTo(typename BST<Data>::NodeLnk* const& nod, Data valore) const noexcept{
  NodeLnk* const* puntatore=&nod;
  NodeLnk* curr=nod;

   while(curr!=nullptr&&curr->Valore!=valore){
     if(valore<curr->Valore){
       puntatore=&curr->sinistro;
       curr=curr->sinistro;
     }
     else if(valore>curr->Valore){
       puntatore=&curr->destro;
       curr=curr->destro;
     }
   }
  return *puntatore;
}

template<typename Data>
typename BST<Data>::NodeLnk*& BST<Data>::FindPointerTo(typename BST<Data>::NodeLnk*& nod, Data valore) noexcept{
  return const_cast<NodeLnk*&>(static_cast<const BST<Data>*>(this)->FindPointerTo(nod,valore));
}

template<typename Data>
typename BST<Data>::NodeLnk* const& BST<Data>::FindPointerToPredecessor(typename BST<Data>::NodeLnk* const& nod, Data valore) const noexcept{
  NodeLnk* const* pred=nullptr;
  NodeLnk* const* curr=&nod;

  while((*curr)!=nullptr&&(*curr)->Valore !=valore){
    if((*curr)->Valore > valore){
      curr=&(*curr)->sinistro;
    }
    else if((*curr)->Valore < valore){
      pred=curr;
      curr=&(*curr)->destro;
    }
  }
  if((*curr)!=nullptr&&(*curr)->sinistro!=nullptr){
    pred=&FindPointerToMax((*curr)->sinistro);
  }

  return *pred;
}

template<typename Data>
typename BST<Data>::NodeLnk*& BST<Data>::FindPointerToPredecessor(typename BST<Data>::NodeLnk*& nod, Data valore) noexcept{
  return const_cast<NodeLnk*&>(static_cast<const BST<Data>*>(this)->FindPointerToPredecessor(nod,valore));
}

template<typename Data>
typename BST<Data>::NodeLnk* const& BST<Data>::FindPointerToSuccessor(typename BST<Data>::NodeLnk* const& nod, Data valore) const noexcept{
  typename BST<Data>::NodeLnk* const* succ=nullptr;
  typename BST<Data>::NodeLnk* const* curr=&nod;

  while((*curr)!=nullptr&&(*curr)->Valore !=valore){
    if((*curr)->Valore < valore){
      curr=&(*curr)->destro;
    }
    else if((*curr)->Valore > valore){
      succ=curr;
      curr=&(*curr)->sinistro;
    }
  }
  if((*curr)!=nullptr&&(*curr)->destro!=nullptr){
    succ=&FindPointerToMin((*curr)->destro);
  }
  return *succ;
}
template<typename Data>
typename BST<Data>::NodeLnk*& BST<Data>::FindPointerToSuccessor(typename BST<Data>::NodeLnk*& nod, Data valore) noexcept{
  return const_cast<NodeLnk*&>(static_cast<const BST<Data>*>(this)->FindPointerToSuccessor(nod,valore));
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
