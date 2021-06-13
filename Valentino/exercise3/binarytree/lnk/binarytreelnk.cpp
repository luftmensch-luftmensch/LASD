
namespace lasd {

template <typename Data>
BinaryTreeLnk<Data>::NodeLnk::NodeLnk(const Data& d){
  Valore = d;
}

template <typename Data>
BinaryTreeLnk<Data>::NodeLnk::NodeLnk(Data&& d) noexcept{
  Valore = std::move(d);
}


template <typename Data>
Data const& BinaryTreeLnk<Data>::NodeLnk::Element() const noexcept{
  return Valore;
}

template <typename Data>
Data& BinaryTreeLnk<Data>::NodeLnk::Element() noexcept{
  return Valore;
}

template <typename Data>
bool BinaryTreeLnk<Data>::NodeLnk::HasLeftChild() const noexcept {
  return sinistro != nullptr;
}

template <typename Data>
bool BinaryTreeLnk<Data>::NodeLnk::HasRightChild() const noexcept {
  return destro!= nullptr;
}


template <typename Data>
typename BinaryTreeLnk<Data>::NodeLnk& BinaryTreeLnk<Data>::NodeLnk::LeftChild() const {
  if (sinistro == nullptr)
    throw std::out_of_range("Impossibile accedere al nodo sinistro, il suo puntatore è nullo");

  return *sinistro;
}

template <typename Data>
typename BinaryTreeLnk<Data>::NodeLnk& BinaryTreeLnk<Data>::NodeLnk::RightChild() const{
  if (destro == nullptr)
    throw std::out_of_range("Impossibile accedere al nodo destro, il suo puntatore è nullo");

  return *destro;
}

template <typename Data>
BinaryTreeLnk<Data>::BinaryTreeLnk(const LinearContainer<Data>& linearContainer){
  if (linearContainer.Size() != 0) {
    Insert(linearContainer, root, 0, linearContainer.Size());
  }
}

template <typename Data>
void BinaryTreeLnk<Data>::Insert(const LinearContainer<Data>& linearContainer, BinaryTreeLnk<Data>::NodeLnk*& root, uint i, ulong dimensioneContainer){
  if (i < dimensioneContainer) {
    root = new NodeLnk(linearContainer[i]);
    dimensione++;
    NodeLnk *node = root;
    Insert(linearContainer, node->sinistro, (2 * i) + 1, dimensioneContainer);
    Insert(linearContainer, node->destro, (2 * i) + 2, dimensioneContainer);
  }
}

template<typename Data>
BinaryTreeLnk<Data>::BinaryTreeLnk(const BinaryTreeLnk <Data> &binaryTree) {
  if (binaryTree.root != nullptr) {
    root = Copy(binaryTree);
    dimensione = binaryTree.Size();
  }
}
template <typename Data>
void BinaryTreeLnk<Data>::RecursiveCopy(typename BinaryTreeLnk<Data>::NodeLnk** StrutturaDiArrivo, const typename BinaryTreeLnk<Data>::NodeLnk* DaCopiare){

  (*StrutturaDiArrivo) = new NodeLnk(DaCopiare->Element());

  if(DaCopiare->HasLeftChild()){
    RecursiveCopy(&(*StrutturaDiArrivo)->sinistro, &DaCopiare->LeftChild());
  }

  if(DaCopiare->HasRightChild()){
    RecursiveCopy(&(*StrutturaDiArrivo)->destro, &DaCopiare->RightChild());
  }
}

template <typename Data>
typename BinaryTreeLnk<Data>::NodeLnk* BinaryTreeLnk<Data>::Copy(const BinaryTreeLnk<Data>& DaCopiare){
  BinaryTreeLnk<Data>::NodeLnk* alberoDiArrivo;
  RecursiveCopy(&alberoDiArrivo, &DaCopiare.Root());
  return alberoDiArrivo;
}

template <typename Data>
BinaryTreeLnk<Data>::BinaryTreeLnk(BinaryTreeLnk<Data>&& binaryTree) noexcept{
  std::swap(root, binaryTree.root);
  std::swap(dimensione, binaryTree.dimensione);
}

template <typename Data>
BinaryTreeLnk<Data>& BinaryTreeLnk<Data>::operator=(const BinaryTreeLnk<Data>& binaryTree){
  if (this == &binaryTree)
    return *this;

  BinaryTreeLnk<Data> *tmp = new BinaryTreeLnk<Data>(binaryTree);
  std::swap(*this, *tmp);
  tmp->BinaryTreeLnk<Data>::Clear();
  delete tmp;

  return *this;
}

template <typename Data>
BinaryTreeLnk<Data>& BinaryTreeLnk<Data>::operator=(BinaryTreeLnk<Data>&& binaryTree) noexcept{
  if (this == &binaryTree)
    return *this;

  BinaryTreeLnk<Data>::Clear();

  std::swap(root, binaryTree.root);
  std::swap(dimensione, binaryTree.dimensione);
  return *this;
}

template <typename Data>
BinaryTreeLnk<Data>::~BinaryTreeLnk() noexcept{
  BinaryTreeLnk<Data>::Clear();
}

template <typename Data>
bool BinaryTreeLnk<Data>::operator==(const BinaryTreeLnk<Data>& binaryTree) const noexcept{
  return BinaryTree<Data>::operator==(binaryTree);
}

template <typename Data>
bool BinaryTreeLnk<Data>::operator!=(const BinaryTreeLnk<Data>& binaryTree) const noexcept{
  return BinaryTree<Data>::operator!=(binaryTree);
}

template <typename Data>
typename BinaryTreeLnk<Data>::NodeLnk const& BinaryTreeLnk<Data>::Root() const {
  if (root == nullptr)
    throw std::out_of_range("L'albero è vuoto!");
  return *root;
}

template <typename Data>
typename BinaryTreeLnk<Data>::NodeLnk& BinaryTreeLnk<Data>::Root(){
  return const_cast<NodeLnk&>(const_cast<const BinaryTreeLnk<Data>*>(this)->Root());
}

template <typename Data>
void BinaryTreeLnk<Data>::Clear() {
  if (root != nullptr)
    DeleteTree(root);
}

template <typename Data>
void BinaryTreeLnk<Data>::DeleteTree(typename BinaryTreeLnk<Data>::NodeLnk*& alberoDiPartenza) noexcept{
  if (alberoDiPartenza->HasLeftChild())
    DeleteTree(alberoDiPartenza->sinistro);

  if (alberoDiPartenza->HasRightChild())
    DeleteTree(alberoDiPartenza->destro);

  delete alberoDiPartenza;
  alberoDiPartenza = nullptr;
  BinaryTree<Data>::dimensione--;
}
}
