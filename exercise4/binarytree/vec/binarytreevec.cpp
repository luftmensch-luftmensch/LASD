
namespace lasd {

/* ************************************************************************** */
//NodeVec class functions

//NodeVec constructor
template <typename Data>
BinaryTreeVec<Data>::NodeVec::NodeVec(const Data& toinsert, lasd::Vector<NodeVec*>* con, const unsigned long int& ind):index(ind), myrefvector(con){

  BinaryTree<Data>::Node::value = toinsert;
}

//Element() function: returns the value of the node
template <typename Data>
Data const& BinaryTreeVec<Data>::NodeVec::Element() const noexcept{

  return BinaryTree<Data>::Node::value;
}

//Element() function: returns the value of the node
template <typename Data>
Data& BinaryTreeVec<Data>::NodeVec::Element() noexcept{

  return BinaryTree<Data>::Node::value;
}

//HasLeftChild() function: returns true if the current node has a left child, false otherwise
template <typename Data>
bool BinaryTreeVec<Data>::NodeVec::HasLeftChild() const noexcept {
  if((index*2+1)< (*myrefvector).Size() && (*myrefvector)[index*2+1] !=nullptr){
    return true;
  }
  else{
    return false;
  }
}

//HasRightChild() function: returns true if the current node has a right child, false otherwise
template <typename Data>
bool BinaryTreeVec<Data>::NodeVec::HasRightChild() const noexcept {
  if((index*2+2)< (*myrefvector).Size() && (*myrefvector)[index*2+2] != nullptr){
    return true;
  }
  else{
    return false;
  }
}

//LeftChild() function: returns the left child of the current node
template <typename Data>
typename BinaryTreeVec<Data>::NodeVec& BinaryTreeVec<Data>::NodeVec::LeftChild() const {
  if(HasLeftChild()){
    return *(*myrefvector)[index*2+1];
  }
  else{
    throw std::out_of_range("Unable to access to the left child of the current node");
  }
}

//RightChild() function: returns the right child of the current node
template <typename Data> typename BinaryTreeVec<Data>::NodeVec& BinaryTreeVec<Data>::NodeVec::RightChild()const {
  if(HasRightChild()){
    return *(*myrefvector)[index*2+2];
  }
  else{
    throw std::out_of_range("Unable to access to the right child of the current node");
  }
}

/* ************************************************************************** */
//BinaryTreeVec class function

//Specific Constructor
template <typename Data>
BinaryTreeVec<Data>::BinaryTreeVec(const LinearContainer<Data>& con){
  if(con.Size()!=0){
    cont.Resize(con.Size());
    int i=0;
    while( i< con.Size()){
        cont[i]= new NodeVec(con[i],&cont,i);
        i++;
      }
    }
    dim=con.Size();
}


//Copy constructor
template <typename Data>
BinaryTreeVec<Data>::BinaryTreeVec(const BinaryTreeVec<Data>& binarytree){
                       //Copying the vector of pointers
  cont.Resize(binarytree.cont.Size());
  int i=0;
  while( i < cont.Size()){
    if(binarytree.cont[i] != nullptr)
      cont[i] = new NodeVec(binarytree.cont[i]->Element(),&cont,i );
    else{
      cont[i] = nullptr;
    }
    i++;
  }
  dim = binarytree.dim;
}

//Move constructor
template <typename Data>
BinaryTreeVec<Data>::BinaryTreeVec(BinaryTreeVec<Data>&& binarytree) noexcept {

  std::swap(cont, binarytree.cont);
  std::swap(dim, binarytree.dim);
                                 //update of the myrefvectors
  for(unsigned long int i = 0; i < cont.Size(); i++){
    if(cont[i] != nullptr)
      cont[i]->myrefvector = &cont;
  }
}

//Copy assignment
template <typename Data>
BinaryTreeVec<Data>& BinaryTreeVec<Data>::operator=(const BinaryTreeVec<Data>& binarytree){

  if(this == &binarytree)
    return *this;

  BinaryTreeVec<Data> *temptree = new BinaryTreeVec<Data>(binarytree);
	std::swap(*this, *temptree);
	temptree->BinaryTreeVec<Data>::Clear();
	delete temptree;
	return *this;
}

//Move assignment
template <typename Data>
BinaryTreeVec<Data>& BinaryTreeVec<Data>::operator=(BinaryTreeVec<Data>&& binarytree) noexcept{

  if(this == &binarytree){
    return *this;
  }
  BinaryTreeVec<Data>::Clear();
  std::swap(cont, binarytree.cont);
  std::swap(dim, binarytree.dim);
                             //update of the myrefvectors
  int i=0;
  while( i < cont.Size()){
    if(cont[i] != nullptr){
      cont[i]->myrefvector = &cont;
    }
    i++;
  }
  return *this;
}

/* ************************************************************************** */

//Auxiliary function to delete the treevec
template <typename Data>
void BinaryTreeVec<Data>::DeleteTree(typename BinaryTreeVec<Data>::NodeVec*& node) noexcept{

  if(node->HasLeftChild()){
    DeleteTree(cont[node->LeftChild().index]);
  }
  if(node->HasRightChild()){
    DeleteTree(cont[node->RightChild().index]);
  }
  delete node;
  node = nullptr;
  dim--;
}

//Reduce function
template <typename Data>
void BinaryTreeVec<Data>::Reduce(){

  unsigned long newsize;
  newsize = cont.Size();
  newsize=newsize/2;
  cont.Resize(newsize);
}

//Expand function
template <typename Data>
void BinaryTreeVec<Data>::Expand(){
                      //Creazione del nuovo vettore con size*2+1
  unsigned long oldsize;
  oldsize=cont.Size();
  cont.Resize(oldsize*2+1);
                     //Svuotamento del vecchio vettore
  int i=oldsize;
  while(i < cont.Size()){
    cont[i] = nullptr;
    i++;
  }
}
/* ************************************************************************** */
//Destructor
template <typename Data>
BinaryTreeVec<Data>::~BinaryTreeVec()noexcept{

  BinaryTreeVec<Data>::Clear();
}

//Comparison operators
template <typename Data>
bool BinaryTreeVec<Data>::operator==(const BinaryTreeVec<Data>& binarytree) const noexcept{
                      //Self comparison returns true
  if(this == &binarytree){
    return true;
  }
                        //If sizes are different,returns false
  if(dim != binarytree.dim){
    return false;
  }

  unsigned int index=0;

  while(index < dim){
                               //if one of the two nodes is nullptr and the other is not nullptr
    if( cont[index]==nullptr && binarytree.cont[index]!=nullptr){
      return false;
    }
    if( cont[index]!=nullptr && binarytree.cont[index]==nullptr){
      return false;
    }
                                   //if the two elements are different
    if(cont[index]!=nullptr && binarytree.cont[index]!=nullptr && cont[index]->Element()!=binarytree.cont[index]->Element()){
      return false;
    }
    index++;
  }
  return true;
}

//Other comparison operator
template <typename Data>
bool BinaryTreeVec<Data>::operator!=(const BinaryTreeVec<Data>& binarytree) const noexcept{

  return !(*this == binarytree);
}

//Root function (const): returns the root of the binary tree
template <typename Data>
typename BinaryTreeVec<Data>::NodeVec const& BinaryTreeVec<Data>::Root() const {

  if(!Empty()){
    return *cont[0];
  }
  else{
    throw std::out_of_range("Could not access to the root, tree is empty!");
  }


}

//Root function: returns the root of the binary tree
template <typename Data>
typename BinaryTreeVec<Data>::NodeVec& BinaryTreeVec<Data>::Root(){

  return const_cast<NodeVec&>(const_cast<const BinaryTreeVec<Data>*>(this)->Root());
}

//Clear function
template <typename Data>
void BinaryTreeVec<Data>::Clear() noexcept {

  unsigned int i=0;
  while(i < cont.Size()){
    delete cont[i];
    i++;
  }
  cont.Clear();
  dim=0;
}


//lasd::BreadthMappableContainer<Data> protected function
template <typename Data>
void BinaryTreeVec<Data>::MapBreadth(MapFunctor mapFunctor, void* par) noexcept{

  for(unsigned long i = 0; i < cont.Size(); i++){
    if(cont[i] != nullptr)
      mapFunctor(cont[i]->value, par);
  }
}

//lasd::BreadthFoldableContainer<Data> protected function
template <typename Data>
void BinaryTreeVec<Data>::FoldBreadth(FoldFunctor foldFunctor, const void* par, void* acc) const noexcept{

  for(unsigned long i = 0; i < cont.Size(); i++){
    if(cont[i] != nullptr)
      foldFunctor(cont[i]->value, par, acc);
  }
}

/* ************************************************************************** */

}
