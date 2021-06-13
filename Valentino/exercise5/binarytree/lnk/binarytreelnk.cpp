
namespace lasd {

/* ************************************************************************** */

//NodeLnk class functions

//NodeLnk constructor
template <typename Data>
BinaryTreeLnk<Data>::NodeLnk::NodeLnk(const Data& dat){

  BinaryTree<Data>::Node::value = dat;
}
//NodeLnk constructor
template <typename Data>
BinaryTreeLnk<Data>::NodeLnk::NodeLnk(Data&& dat)noexcept{

  BinaryTree<Data>::Node::value = std::move(dat);
}


//Element() function: returns the value of the node
template <typename Data>
Data const& BinaryTreeLnk<Data>::NodeLnk::Element() const noexcept{

  return BinaryTree<Data>::Node::value;
}

//Element() function: returns the value of the node
template <typename Data>
Data& BinaryTreeLnk<Data>::NodeLnk::Element() noexcept{

  return BinaryTree<Data>::Node::value;
}

//HasLeftChild() function: returns true if the current node has a left child, false otherwise
template <typename Data>
bool BinaryTreeLnk<Data>::NodeLnk::HasLeftChild() const noexcept {

  if(left!=nullptr){
    return true;
  }
  else{
    return false;
  }
}

//HasRightChild() function: returns true if the current node has a right child, false otherwise
template <typename Data>
bool BinaryTreeLnk<Data>::NodeLnk::HasRightChild() const noexcept {

  if(right!=nullptr){
    return true;
  }
  else{
    return false;
  }
}

//LeftChild() function: returns the left child of the current node
template <typename Data>
typename BinaryTreeLnk<Data>::NodeLnk& BinaryTreeLnk<Data>::NodeLnk::LeftChild() const{

  if(left != nullptr){
    return *left;
  }
  else{
    throw std::out_of_range("Unable to access to the left node");
  }
}

//RightChild() function: returns the right child of the current node
template <typename Data>
typename BinaryTreeLnk<Data>::NodeLnk& BinaryTreeLnk<Data>::NodeLnk::RightChild() const{

  if(right != nullptr){
    return *right;
  }
  else{
    throw std::out_of_range("Unable to access to the right node");
  }
}
/******************************************************************************/
//BinaryTreeLnk class function

//Specific constructor
template <typename Data>
BinaryTreeLnk<Data>::BinaryTreeLnk(const LinearContainer<Data>& con){

  if(con.Size()!=0){
    RecursiveFillingTree(con, root,0,con.Size());
  }
}

//Auxiliary function for specific constructor
template <typename Data>
void BinaryTreeLnk<Data>::RecursiveFillingTree(const LinearContainer<Data>& con, BinaryTreeLnk<Data>::NodeLnk*& root, unsigned int index, unsigned long condim){

  if(index<condim){
    root = new NodeLnk(con[index]);
    dim++;
    NodeLnk* tempnode=root;

    RecursiveFillingTree(con,tempnode->left ,2*index+1,condim);
    RecursiveFillingTree(con, tempnode->right,2*index+2,condim);
  }
}

//Copy constructor
template <typename Data>
BinaryTreeLnk<Data>::BinaryTreeLnk(const BinaryTreeLnk<Data>& oldtree){

  if(oldtree.root!=nullptr){
    AuxCopyTree(oldtree.root,root);
    dim=oldtree.dim;
  }
  else{
    root=nullptr;
  }
}

//Auxiliary function for copy constructor
template <typename Data>
void BinaryTreeLnk<Data>::AuxCopyTree(NodeLnk* const& oldtreenode,NodeLnk*& newtreenode){

  if(oldtreenode==nullptr){
    newtreenode=nullptr;
    return;
  }
  else{
    newtreenode=new NodeLnk(oldtreenode->value);
    AuxCopyTree(oldtreenode->left,newtreenode->left);
    AuxCopyTree(oldtreenode->right,newtreenode->right);
  }
}

//Move constructor
template <typename Data>
BinaryTreeLnk<Data>::BinaryTreeLnk(BinaryTreeLnk<Data>&& binarytree) noexcept {

  std::swap(root, binarytree.root);
  std::swap(dim,binarytree.dim);
  binarytree.Clear();
}


//Copy assignment
template <typename Data>
BinaryTreeLnk<Data>& BinaryTreeLnk<Data>::operator=(const BinaryTreeLnk<Data>& binarytree){
                        //Cannot assign the same tree
  if(this == &binarytree){
    return *this;
  }

  BinaryTreeLnk<Data> *temptree=new BinaryTreeLnk<Data>(binarytree);
	std::swap(*this, *temptree);
	temptree->Clear();
	delete temptree;

	return *this;
}

//Move assignment
template <typename Data>
BinaryTreeLnk<Data>& BinaryTreeLnk<Data>::operator=(BinaryTreeLnk<Data>&& binarytree) noexcept{
                         //Cannot assign the same tree
  if(this == &binarytree){
    return *this;
  }
  std::swap(root, binarytree.root);
  std::swap(dim, binarytree.dim);

  binarytree.Clear();

  return *this;
}

//Destructor
template <typename Data>
BinaryTreeLnk<Data>::~BinaryTreeLnk() noexcept{

  BinaryTreeLnk<Data>::Clear();
}

//Comparison operator
template <typename Data>
bool BinaryTreeLnk<Data>::operator==(const BinaryTreeLnk<Data>& binarytree) const noexcept{

  return BinaryTree<Data>::operator==(binarytree);
}

//Other comparison operator
template <typename Data>
bool BinaryTreeLnk<Data>::operator!=(const BinaryTreeLnk<Data>& binarytree) const noexcept{

  return BinaryTree<Data>::operator!=(binarytree);
}

//Root function (const): returns the root of the binary tree
template <typename Data>
typename BinaryTreeLnk<Data>::NodeLnk const& BinaryTreeLnk<Data>::Root() const {

  if(root != nullptr){
    return *root;
  }
  else{
    throw std::out_of_range("Tree is empty!");
  }
}

//Root function: returns the root of the binary tree
template <typename Data>
typename BinaryTreeLnk<Data>::NodeLnk& BinaryTreeLnk<Data>::Root(){

  return const_cast<NodeLnk&>(const_cast<const BinaryTreeLnk<Data>*>(this)->Root());
}

//Clear function
template <typename Data>
void BinaryTreeLnk<Data>::Clear() {

  if(root != nullptr){
    AuxRecursiveDeleteTree(root);
  }
}

//Auxiliary function for clearing the tree
template <typename Data>
void BinaryTreeLnk<Data>::AuxRecursiveDeleteTree(NodeLnk*& currentnode) noexcept{

  if(currentnode->HasLeftChild()){
    AuxRecursiveDeleteTree(currentnode->left);
  }
  if(currentnode->HasRightChild()){
    AuxRecursiveDeleteTree(currentnode->right);
  }

  delete currentnode;
  currentnode = nullptr;
  BinaryTree<Data>::dim=dim-1;
}

/* ************************************************************************** */

}
