#include <stdexcept>
namespace lasd {

/* ************************************************************************** */

// Specific constructor for the Node
template<typename Data>
List<Data>::Node::Node(const Data& val){
  elem = val;
  next = nullptr;
}

// Specific constructors Node (move)
template<typename Data>
List<Data>::Node::Node(Data&& val) noexcept{
  std::swap(elem, val);
  next = nullptr;
}

/* ************************************************************************** */

// Copy constructor for the Node
template<typename Data>
List<Data>::Node::Node(const Node& nodo){
  this->elem = nodo.elem;
  this->next = nodo.next;
}

// Move constructor for the Node
template<typename Data>
List<Data>::Node::Node(Node&& nodo) noexcept{
  std::swap(elem, nodo.elem);
  std::swap(next, nodo.next);
}

/* ************************************************************************** */

// first Comparison operator for the Node
template<typename Data>
bool List<Data>::Node::operator==(const Node& nodo) const noexcept{
  if (elem != nodo.elem){
    return false;
  }
  return true;
}

// Second comparison operator for the Node
template<typename Data>
bool List<Data>::Node::operator!=(const Node& nodo) const noexcept{
  return !(*this == nodo);
}

/* ************************************************************************** */

// Default constructor for the list
template<typename Data>
List<Data>::List(){
  First = nullptr;
  Last = nullptr;
}

//Specific constructor for the list
template<typename Data>
List<Data>::List(const LinearContainer<Data>& con){
  if (con.Size() ==0 ) return;
  dim=con.Size();
  Node* ptr = new Node;
  Node* curr = ptr;
  for(unsigned long i=0; i < con.Size(); ++i){
    curr->elem = con[i];
    curr->next = nullptr;
    curr = curr->next;
  }
  First = ptr;
  Last = curr;
  delete ptr,curr;
}

/* ************************************************************************** */
// Copy constructor for the List
template<typename Data>
List<Data>::List(const List<Data>& otherList){
    if(otherList.First == nullptr) return;
    Node* ptr = new Node;
    Node* curr = ptr;
    Node* oth = nullptr;
    for(oth = otherList.First; oth != nullptr; oth = oth->next){
      curr->next = new Node;
      curr = curr->next;
      curr->elem = oth->elem;
      curr->next = nullptr;
    }
    First = ptr->next;
    delete ptr;
}

// Move constructor for the list
template<typename Data>
List<Data>::List(List<Data>&& otherList) noexcept{
  dim = otherList.dim;
  otherList.dim = 0;
  First = otherList.First;
  otherList.First = nullptr;
  Last = otherList.Last;
  otherList.Last = nullptr;
}

/* ************************************************************************** */
// Destructor list
template<typename Data>
List<Data>::~List(){
  Node* current = First;
  while(current != nullptr){
    Node* da_delete = current;
    current = current->next;
    delete da_delete;
  }
}

/* ************************************************************************** */
// Copy assignment list
template<typename Data>
List<Data>& List<Data>::operator=(const List<Data>& list){
  List<Data>* tmplist = new List<Data>(list);
  std::swap(tmplist->First, First);
  return *this;
}

// Move assignment list
template<typename Data>
List<Data>& List<Data>::operator=(List<Data>&& list) noexcept{
  std::swap(First, list.First);
  std::swap(Last, list.Last);
  std::swap(dim, list.dim);
  return *this;
}

/* ************************************************************************** */
// Comparison operator for list
template<typename Data>
bool List<Data>::operator==(const List<Data>& list) const noexcept{
  if(dim == list.dim){
    struct Node* current = First;
    struct Node* Tmp = list.First;
    for(unsigned long i = 0; i < dim; i++){
      if(current->elem != Tmp->elem){
        return false;
      }
      current = current->next;
      Tmp = Tmp->next;
    }
    return true;
  }
  else{
    return false;
  }
}

// Second comparison operator for list
template<typename Data>
bool List<Data>::operator!=(const List<Data>& list) const noexcept{
  return !(*this == list);
}

/* ************************************************************************** */
// RemoveFromFront functions list
template<typename Data>
void List<Data>::RemoveFromFront(){
  struct Node* current;
  if(First == nullptr)
    throw std::length_error("Accesso ad una lista vuota.");
  else if (First == Last){
    dim--;
    First = nullptr;
    Last = nullptr;
  }
  else{
    current = First;
    First = First->next;
    dim--;
  }
}

// FrontNRemove functions list
template<typename Data>
Data& List<Data>::FrontNRemove(){
  struct Node* current;
  if(First == nullptr)
    throw std::length_error("Accesso ad una lista vuota.");
  else if (First == Last){
    dim--;
    current = First;
    First = nullptr;
    Last = nullptr;
    return current->elem;
  }
  else{
    current = First;
    First = First->next;
    dim--;
    return current->elem;
  }
}

// InsertAtFront functions list
template<typename Data>
void List<Data>::InsertAtFront(const Data& value){
  struct Node* newNode;
  newNode = new Node(value);
  newNode->next = First;
  First = newNode;
  dim++;
  if (Last == nullptr)
    Last = newNode;
}

// InsertAtFront (move) functions list
template<typename Data>
void List<Data>::InsertAtFront(Data&& value) noexcept{
  struct Node* newNode;
  newNode = new Node(std::move(value));
  newNode->next = First;
  First = newNode;
  dim++;
  if(Last == nullptr)
    Last = newNode;
}

// InsertAtBack functions list
template<typename Data>
void List<Data>::InsertAtBack(const Data& value){
  struct Node* newNode;
  newNode = new Node(value);
  if(!First){
    First = newNode;
    Last = newNode;
    dim++;
  }
  else{
    struct Node* tmp = First;
    while(tmp->next) tmp = tmp->next;
    tmp->next = newNode;
    dim++;
  }
}

// InsertAtBack (move) functions list
template<typename Data>
void List<Data>::InsertAtBack(Data&& value) noexcept{
  struct Node* newNode;
  newNode = new Node(std::move(value));
  if(!First){
    First = newNode;
    Last = newNode;
    dim++;
  }
  else{
    struct Node* tmp = First;
    while(tmp->next) tmp = tmp->next;
    tmp->next = newNode;
    dim++;
  }
}

/* ************************************************************************** */
// Clear function for the list
template<typename Data>
void List<Data>::Clear(){
  struct Node* tmp;
  while(First != nullptr){
    tmp = First;
    First = First->next;
  }
  Last = nullptr;
  dim = 0;
  First = nullptr;
}

/* ************************************************************************** */
// Front function for the list
template<typename Data>
Data& List<Data>::Front() const{
  if (First != nullptr){
    return First->elem;
  }
  else{
    throw std::length_error("La lista e' vuota.");
  }
}

// Back function for the list
template<typename Data>
Data& List<Data>::Back() const{
if(Last != nullptr){
    return Last->elem;
  }
  else{
    throw std::length_error("La lista e' vuota.");
  }
}

// Operator [] function fort the list
template<typename Data>
Data& List<Data>::operator[](const unsigned long i) const {
  if(i < dim){
    struct Node* current;
    current = First;
    for(unsigned long i = 0; i < i; i++){
      current = current->next;
    }
    return current->elem;
  }
  else{
    throw std::out_of_range("Accesso all'indice " + std::to_string(i) + ": lunghezza della lista" + std::to_string(dim) + ".");
  }
}
/* ************************************************************************** */
// Map  PreOrder list
template<typename Data>
void List<Data>::MapPreOrder(MapFunctor fun, void* par){
  MapPreOrder(fun,par,First);
}

// Map (protected) function PreOrder list
template<typename Data>
void List<Data>::MapPreOrder(MapFunctor fun, void* par, Node* curr){
  for(; curr != nullptr; curr = curr->next){
    fun(curr->elem, par);
  }
}

// Map function PostOrder list
template<typename Data>
void List<Data>::MapPostOrder(MapFunctor fun, void* par){
  MapPostOrder(fun,par,First);
}

// Map (protected) function PostOrder list
template<typename Data>
void List<Data>::MapPostOrder(MapFunctor fun, void* par, Node* curr){
  if(curr != nullptr){
    MapPostOrder(fun,par,curr->next);
    fun(curr->elem,par);
  }
}
/* ************************************************************************** */

// Fold functions PreOrder list
template<typename Data>
void List<Data>::FoldPreOrder(FoldFunctor fun, const void* par, void* acc) const{
  FoldPreOrder(fun,par,acc,First);
}

// Fold functions PostOrder list
template<typename Data>
void List<Data>::FoldPostOrder(FoldFunctor fun, const void* par, void* acc) const{
  FoldPostOrder(fun,par,acc,First);
}

// Fold (protected) functions PreOrder list
template<typename Data>
void List<Data>::FoldPreOrder(FoldFunctor fun, const void* par, void* acc, Node* curr) const{
  for(; curr != nullptr; curr = curr->next){
    fun(curr->elem,par,acc);
  }
}

// Fold (protected) functions PostOrder list
template<typename Data>
void List<Data>::FoldPostOrder(FoldFunctor fun, const void* par, void* acc, Node* curr) const{
  if(curr != nullptr){
    FoldPostOrder(fun,par,acc,curr);
    fun(curr->elem,par,acc);
  }
}


}
