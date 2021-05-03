
namespace lasd {

/* ************************************************************************** */
//NodeLnk class functions

template <typename Data>
BinaryTreeLnk<Data>::NodeLnk::NodeLnk(const Data& d){
  value = d;
}

template <typename Data>
BinaryTreeLnk<Data>::NodeLnk::NodeLnk(Data&& d) noexcept{
  value = std::move(d);
}

template <typename Data>
Data const& BinaryTreeLnk<Data>::NodeLnk::Element() const noexcept{
  return value;
}

template <typename Data>
Data& BinaryTreeLnk<Data>::NodeLnk::Element() noexcept{
  return value;
}

template <typename Data>
bool BinaryTreeLnk<Data>::NodeLnk::HasLeftChild() const noexcept {
  return left != nullptr;
}

template <typename Data>
bool BinaryTreeLnk<Data>::NodeLnk::HasRightChild() const noexcept {
  return right!= nullptr;
}


template <typename Data>
typename BinaryTreeLnk<Data>::NodeLnk& BinaryTreeLnk<Data>::NodeLnk::LeftChild() const {
  if (left == nullptr)
    throw std::out_of_range("Could not access to the left node, its pointer is null!");

  return *left;
}

template <typename Data>
typename BinaryTreeLnk<Data>::NodeLnk& BinaryTreeLnk<Data>::NodeLnk::RightChild() const{
  if (right == nullptr)
    throw std::out_of_range("Could not access to the right node, its pointer is null!");

  return *right;
}

//Specific constructor: DA FARE ***
template <typename Data>
BinaryTreeLnk<Data>::BinaryTreeLnk(const LinearContainer<Data>& con){
  root=nullptr;
}


//Copy constructor
template<typename Data>
BinaryTreeLnk<Data>::BinaryTreeLnk(const BinaryTreeLnk <Data> &bT) {

    //Visit the entire tree
    if (bT.root != nullptr) {
        root = Copy(bT);
        dim = bT.Size();
    }
}
//Auxiliary2 for copy
template <typename Data>
void BinaryTreeLnk<Data>::RecursiveCopy(typename BinaryTreeLnk<Data>::NodeLnk** destination,
const typename BinaryTreeLnk<Data>::NodeLnk* toCopy){

  (*destination) = new NodeLnk(toCopy->Element());

  if(toCopy->HasLeftChild()){
    RecursiveCopy(&(*destination)->left, &toCopy->LeftChild());
  }

  if(toCopy->HasRightChild()){
    RecursiveCopy(&(*destination)->right, &toCopy->RightChild());
  }
}
//Auxiliary1 for copy
template <typename Data>
typename BinaryTreeLnk<Data>::NodeLnk* BinaryTreeLnk<Data>::Copy(const BinaryTreeLnk<Data>& toCopy){
  BinaryTreeLnk<Data>::NodeLnk* newTree;
  RecursiveCopy(&newTree, &toCopy.Root());
  return newTree;
}

//Move constructor
template <typename Data>
BinaryTreeLnk<Data>::BinaryTreeLnk(BinaryTreeLnk<Data>&& bT) noexcept{
  std::swap(root, bT.root);
  std::swap(dim, bT.dim);
}

//Copy assignment
template <typename Data>
BinaryTreeLnk<Data>& BinaryTreeLnk<Data>::operator=(const BinaryTreeLnk<Data>& bT){
  //No self assignment
  if(this == &bT)
    return *this;

  BinaryTreeLnk<Data> *tmp = new BinaryTreeLnk<Data>(bT);
	std::swap(*this, *tmp);
	tmp->BinaryTreeLnk<Data>::Clear();
	delete tmp;

	return *this;
}

//Move assignment
template <typename Data>
BinaryTreeLnk<Data>& BinaryTreeLnk<Data>::operator=(BinaryTreeLnk<Data>&& bT) noexcept{
  //No self assignment
  if(this == &bT)
    return *this;

  //Clear the current Tree
  BinaryTreeLnk<Data>::Clear();

  std::swap(root, bT.root);
  std::swap(dim, bT.dim);
  return *this;
}

//Destructor
template <typename Data>
BinaryTreeLnk<Data>::~BinaryTreeLnk() noexcept{
  BinaryTreeLnk<Data>::Clear();
}

//Comparison operator
template <typename Data>
bool BinaryTreeLnk<Data>::operator==(const BinaryTreeLnk<Data>& bT) const noexcept{
  return BinaryTree<Data>::operator==(bT);
}

//Other comparison operator
template <typename Data>
bool BinaryTreeLnk<Data>::operator!=(const BinaryTreeLnk<Data>& bT) const noexcept{
  return BinaryTree<Data>::operator!=(bT);
}

//ROOT (const)
template <typename Data>
typename BinaryTreeLnk<Data>::NodeLnk const& BinaryTreeLnk<Data>::Root() const {
  if (root == nullptr)
    throw std::out_of_range("L'albero e' vuoto!");
  return *root;
}
//ROOT
template <typename Data>
typename BinaryTreeLnk<Data>::NodeLnk& BinaryTreeLnk<Data>::Root(){
  return const_cast<NodeLnk&>(const_cast<const BinaryTreeLnk<Data>*>(this)->Root());
}


//Clear function
template <typename Data>
void BinaryTreeLnk<Data>::Clear() {
  if(root != nullptr)
    DeleteTree(root);
}
//Auxiliary function for clear the tree
template <typename Data>
void BinaryTreeLnk<Data>::DeleteTree(typename BinaryTreeLnk<Data>::NodeLnk*& from) noexcept{
  if(from->HasLeftChild())
    DeleteTree(from->left);


  if(from->HasRightChild())
    DeleteTree(from->right);

  delete from;
  from = nullptr;
  BinaryTree<Data>::dim--;
}
/* ************************************************************************** */

}
