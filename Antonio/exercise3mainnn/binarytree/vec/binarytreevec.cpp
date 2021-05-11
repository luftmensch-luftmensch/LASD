
namespace lasd {

/* ************************************************************************** */

//NodeVec constructors
template <typename Data>
BinaryTreeVec<Data>::NodeVec::NodeVec(const Data& k, lasd::Vector<NodeVec*>* c, const unsigned long int& p):
index(p), reference(c){
  value = k;
}

template <typename Data>
BinaryTreeVec<Data>::NodeVec::NodeVec(const Data&& k, lasd::Vector<NodeVec*>* c, const unsigned long int& p):
index(p), reference(c){
  value = std::move(k);
}


template <typename Data>
Data const& BinaryTreeVec<Data>::NodeVec::Element() const noexcept{
  return value;
}

template <typename Data>
Data& BinaryTreeVec<Data>::NodeVec::Element() noexcept{
  return value;
}

template <typename Data>
inline bool BinaryTreeVec<Data>::NodeVec::HasLeftChild() const noexcept {
  return index*2+1 < (*reference).Size() && (*reference)[index*2+1] != nullptr;
}

template <typename Data>
inline bool BinaryTreeVec<Data>::NodeVec::HasRightChild() const noexcept {
  return index*2+2 < (*reference).Size() && (*reference)[index*2+2] != nullptr;
}

template <typename Data>
typename BinaryTreeVec<Data>::NodeVec& BinaryTreeVec<Data>::NodeVec::LeftChild() const {
  if(!HasLeftChild())
    throw std::out_of_range("Could not access to the left child: it is not available!");

  return *(*reference)[index*2+1];
}

template <typename Data>
typename BinaryTreeVec<Data>::NodeVec& BinaryTreeVec<Data>::NodeVec::RightChild() const {
  if(!HasRightChild())
    throw std::out_of_range("Could not access to the right child: it is not available!");

  return *(*reference)[index*2+2];
}
/* ************************************************************************** */
//Specific Constructor
template <typename Data>
BinaryTreeVec<Data>::BinaryTreeVec(const LinearContainer<Data>& con){
  if(con.Size()!=0){
    mycontainer.Resize(con.Size());
    for(unsigned int i=0; i< con.Size(); i++){
        mycontainer[i]= new NodeVec(con[i],&mycontainer,i);
      }
    }
  dim=con.Size();
}

//Copy constructor

template <typename Data>
BinaryTreeVec<Data>::BinaryTreeVec(const BinaryTreeVec<Data>& bT){
  //Stiamo copiando un vettore di puntatori
  //Non possiamo utilizzare il copy constructor di vettore!
  //m_container = bT.m_container;
  mycontainer.Resize(bT.mycontainer.Size());
  for(unsigned long int i = 0; i < mycontainer.Size(); i++){
    if(bT.mycontainer[i] != nullptr)
      mycontainer[i] = new NodeVec(bT.mycontainer[i]->Element(),&mycontainer,i );
    else mycontainer[i] = nullptr;
  }

  nodeperlevel = bT.nodeperlevel;
  dim = bT.dim;
}

//Move constructor
template <typename Data>
BinaryTreeVec<Data>::BinaryTreeVec(BinaryTreeVec<Data>&& bT) noexcept {
  std::swap(mycontainer, bT.mycontainer);
  std::swap(nodeperlevel, bT.nodeperlevel);
  std::swap(dim, bT.dim);

  UpdateReferences();
}

//Copy assignment
template <typename Data>
BinaryTreeVec<Data>& BinaryTreeVec<Data>::operator=(const BinaryTreeVec<Data>& bT){
  //No self assignment
  if(this == &bT)
    return *this;

  BinaryTreeVec<Data> *tmp = new BinaryTreeVec<Data>(bT);
	std::swap(*this, *tmp);
	tmp->BinaryTreeVec<Data>::Clear();
	delete tmp;

	return *this;
}

//Move assignment
template <typename Data>
BinaryTreeVec<Data>& BinaryTreeVec<Data>::operator=(BinaryTreeVec<Data>&& bT) noexcept{
  //No self assignment
  if(this == &bT)
    return *this;

  //Clear the current Tree
  BinaryTreeVec<Data>::Clear();

  std::swap(mycontainer, bT.mycontainer);
  std::swap(nodeperlevel, bT.nodeperlevel);
  std::swap(dim, bT.dim);
  UpdateReferences();

  return *this;
}

/* ************************************************************************** */

template <typename Data>
void BinaryTreeVec<Data>::UpdateReferences() noexcept{
  for(unsigned long int i = 0; i < mycontainer.Size(); i++){
    if(mycontainer[i] != nullptr)
      mycontainer[i]->reference = &mycontainer;
  }
}
//Auxiliary funtion to delete the treevec
template <typename Data>
void BinaryTreeVec<Data>::DeleteTree(typename BinaryTreeVec<Data>::NodeVec*& from) noexcept{
  if(from->HasLeftChild())
    DeleteTree(mycontainer[from->LeftChild().index]);

  if(from->HasRightChild())
    DeleteTree(mycontainer[from->RightChild().index]);

  nodeperlevel[from->Height()]--;
  delete from;
  from = nullptr;
  dim--;
}

//Reduce function
template <typename Data>
void BinaryTreeVec<Data>::Reduce(){
  unsigned long int i = nodeperlevel.Size() - 1;
  unsigned long int newSize = mycontainer.Size();
  while(i != 0 && nodeperlevel[i] == 0){
    i--;
    newSize = newSize/2; //(i*2+1);
  }

  mycontainer.Resize(newSize);
  nodeperlevel.Resize(i + 1);
}
//Expand function
template <typename Data>
void BinaryTreeVec<Data>::Expand(){
  const unsigned long int oldSize = mycontainer.Size();
  mycontainer.Resize(oldSize*2+1);

  for(unsigned long int i = oldSize; i < mycontainer.Size(); i++)
    mycontainer[i] = nullptr;

  nodeperlevel.Resize(nodeperlevel.Size() + 1);
  nodeperlevel[nodeperlevel.Size() - 1] = 0;
}
/* ************************************************************************** */
//Destructor
template <typename Data>
BinaryTreeVec<Data>::~BinaryTreeVec() noexcept {
  BinaryTreeVec<Data>::Clear();
}
//Comparison operators
template <typename Data>
bool BinaryTreeVec<Data>::operator==(const BinaryTreeVec<Data>& bT) const noexcept{
  //Self comparison always return true
  if(this == &bT)
   return true;

  //If sizes are different
  if(dim != bT.dim)
    return false;

  //Se il vettore di altezze è diverso
  if(nodeperlevel != bT.nodeperlevel)
    return false;

  for(unsigned long int i = 0; i < dim; i++){
    //Se uno dei due nodi è nullptr ma l'altro non lo è
    if( mycontainer[i] == nullptr && bT.mycontainer[i] != nullptr)
      return false;

    if( mycontainer[i] != nullptr && bT.mycontainer[i] == nullptr)
      return false;


    if(mycontainer[i] != nullptr && bT.mycontainer[i] != nullptr && mycontainer[i]->Element() != bT.mycontainer[i]->Element())
      return false;
  }

  return true;
}
//Other comparison operator
template <typename Data>
bool BinaryTreeVec<Data>::operator!=(const BinaryTreeVec<Data>& bT) const noexcept{
  return !(*this == bT);
}

//ROOT
template <typename Data>
typename BinaryTreeVec<Data>::NodeVec const& BinaryTreeVec<Data>::Root() const {
  if (Empty())
    throw std::out_of_range("Could not access to the root, tree is empty!");
  return *mycontainer[0];
}
//ROOT
template <typename Data>
typename BinaryTreeVec<Data>::NodeVec& BinaryTreeVec<Data>::Root(){
  return const_cast<NodeVec&>(const_cast<const BinaryTreeVec<Data>*>(this)->Root());
}

//Clear
template <typename Data>
void BinaryTreeVec<Data>::Clear() noexcept {
  for(unsigned long int i = 0; i < mycontainer.Size(); i++)
    delete mycontainer[i];
  mycontainer.Clear();
  dim = 0;
  nodeperlevel.Clear();
}

/* ************************************************************************** */

}
