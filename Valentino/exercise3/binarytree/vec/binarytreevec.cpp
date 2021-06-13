
namespace lasd {


template <typename Data>
BinaryTreeVec<Data>::NodeVec::NodeVec(const Data& k, lasd::Vector<NodeVec*>* c, const unsigned long int& p): in(p), riferimento(c){
  Valore = k;
}

template <typename Data>
BinaryTreeVec<Data>::NodeVec::NodeVec(const Data&& k, lasd::Vector<NodeVec*>* c, const unsigned long int& p): in(p), riferimento(c){
  Valore = std::move(k);
}

template <typename Data>
Data const& BinaryTreeVec<Data>::NodeVec::Element() const noexcept{
  return Valore;
}

template <typename Data>
Data& BinaryTreeVec<Data>::NodeVec::Element() noexcept{
  return Valore;
}

template <typename Data>
inline bool BinaryTreeVec<Data>::NodeVec::HasLeftChild() const noexcept {
  return in*2+1 < (*riferimento).Size() && (*riferimento)[in*2+1] != nullptr;
}

template <typename Data>
inline bool BinaryTreeVec<Data>::NodeVec::HasRightChild() const noexcept {
  return in*2+2 < (*riferimento).Size() && (*riferimento)[in*2+2] != nullptr;
}


template <typename Data>
typename BinaryTreeVec<Data>::NodeVec& BinaryTreeVec<Data>::NodeVec::RightChild() const {
  if(!HasRightChild())
    throw std::out_of_range("Impossibile accedere al figlio destro (non disponibile)");

  return *(*riferimento)[in*2+2];
}
template <typename Data>
typename BinaryTreeVec<Data>::NodeVec& BinaryTreeVec<Data>::NodeVec::LeftChild() const {
  if(!HasLeftChild())
    throw std::out_of_range("Impossibile accedere al figlio sinistro (non disponibile)");

  return *(*riferimento)[in*2+1];
}

template <typename Data>
BinaryTreeVec<Data>::BinaryTreeVec(const LinearContainer<Data>& linearContainer){
  if(linearContainer.Size()!=0){
    containerP.Resize(linearContainer.Size());
    for(uint i=0; i< linearContainer.Size(); i++){
        containerP[i]= new NodeVec(linearContainer[i],&containerP,i);
      }
    }
  dimensione=linearContainer.Size();
}


template <typename Data>
BinaryTreeVec<Data>::BinaryTreeVec(const BinaryTreeVec<Data>& binaryTree){

  containerP.Resize(binaryTree.containerP.Size());
  for(unsigned long int i = 0; i < containerP.Size(); i++){
    if(binaryTree.containerP[i] != nullptr)
      containerP[i] = new NodeVec(binaryTree.containerP[i]->Element(),&containerP,i );
    else containerP[i] = nullptr;
  }

  nodeperlevel = binaryTree.nodeperlevel;
  dimensione = binaryTree.dimensione;
}

template <typename Data>
BinaryTreeVec<Data>::BinaryTreeVec(BinaryTreeVec<Data>&& binaryTree) noexcept {
  std::swap(containerP, binaryTree.containerP);
  std::swap(nodeperlevel, binaryTree.nodeperlevel);
  std::swap(dimensione, binaryTree.dimensione);

  UpdateReferences();
}

template <typename Data>
BinaryTreeVec<Data>& BinaryTreeVec<Data>::operator=(const BinaryTreeVec<Data>& binaryTree){
  if(this == &binaryTree)
    return *this;

  BinaryTreeVec<Data> *tmp = new BinaryTreeVec<Data>(binaryTree);
	std::swap(*this, *tmp);
	tmp->BinaryTreeVec<Data>::Clear();
	delete tmp;

	return *this;
}

template <typename Data>
BinaryTreeVec<Data>& BinaryTreeVec<Data>::operator=(BinaryTreeVec<Data>&& binaryTree) noexcept{
  if(this == &binaryTree)
    return *this;

  BinaryTreeVec<Data>::Clear();

  std::swap(containerP, binaryTree.containerP);
  std::swap(nodeperlevel, binaryTree.nodeperlevel);
  std::swap(dimensione, binaryTree.dimensione);
  UpdateReferences();

  return *this;
}


template <typename Data>
void BinaryTreeVec<Data>::UpdateReferences() noexcept{
  for(unsigned long int i = 0; i < containerP.Size(); i++){
    if(containerP[i] != nullptr)
      containerP[i]->riferimento = &containerP;
  }
}

template <typename Data>
void BinaryTreeVec<Data>::DeleteTree(typename BinaryTreeVec<Data>::NodeVec*& treevec) noexcept{
  if (treevec->HasLeftChild())
    DeleteTree(containerP[treevec->LeftChild().in]);

  if (treevec->HasRightChild())
    DeleteTree(containerP[treevec->RightChild().in]);

  nodeperlevel[treevec->Height()]--;
  delete treevec;
  treevec = nullptr;
  dimensione--;
}

template <typename Data>
void BinaryTreeVec<Data>::Reduce(){
  unsigned long int i = nodeperlevel.Size() - 1;
  unsigned long int newSize = containerP.Size();
  while (i != 0 && nodeperlevel[i] == 0) {
    i--;
    newSize = newSize / 2;
  }

  containerP.Resize(newSize);
  nodeperlevel.Resize(i + 1);
}
  
template <typename Data>
void BinaryTreeVec<Data>::Expand(){
  const unsigned long int oldSize = containerP.Size();
  containerP.Resize(oldSize * 2 + 1);

  for (unsigned long int i = oldSize; i < containerP.Size(); i++)
    containerP[i] = nullptr;

  nodeperlevel.Resize(nodeperlevel.Size() + 1);
  nodeperlevel[nodeperlevel.Size() - 1] = 0;
}

template <typename Data>
BinaryTreeVec<Data>::~BinaryTreeVec() noexcept {
  BinaryTreeVec<Data>::Clear();
}
  
template <typename Data>
bool BinaryTreeVec<Data>::operator==(const BinaryTreeVec<Data>& binaryTree) const noexcept{
  if(this == &binaryTree)
   return true;
  if(dimensione != binaryTree.dimensione)
    return false;
  if(nodeperlevel != binaryTree.nodeperlevel)
    return false;

  for (unsigned long int i = 0; i < dimensione; i++) {
    if (containerP[i] == nullptr && binaryTree.containerP[i] != nullptr)
      return false;

    if (containerP[i] != nullptr && binaryTree.containerP[i] == nullptr)
      return false;

    if (containerP[i] != nullptr && binaryTree.containerP[i] != nullptr && containerP[i]->Element() != binaryTree.containerP[i]->Element())
      return false;
  }

  return true;
}

template <typename Data>
bool BinaryTreeVec<Data>::operator!=(const BinaryTreeVec<Data>& binaryTree) const noexcept{
  return !(*this == binaryTree);
}

template <typename Data>
typename BinaryTreeVec<Data>::NodeVec const& BinaryTreeVec<Data>::Root() const {
  if (Empty())
    throw std::out_of_range("Impossibile accedere alla root, l'albero è vuoto");
  return *containerP[0];
}
  
template <typename Data>
typename BinaryTreeVec<Data>::NodeVec& BinaryTreeVec<Data>::Root(){
  return const_cast<NodeVec&>(const_cast<const BinaryTreeVec<Data>*>(this)->Root());
}

  
template <typename Data>
void BinaryTreeVec<Data>::Clear() noexcept {
  for (unsigned long int i = 0; i < containerP.Size(); i++)
    delete containerP[i];
  containerP.Clear();
  dimensione = 0;
  nodeperlevel.Clear();
}

}
