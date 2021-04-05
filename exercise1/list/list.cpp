
#include <stdexcept>
/* ************************************************************************** */
namespace lasd{
// Specific constructors Node
template<typename Data>
List<Data>::Node::Node(const Data& val){
  elemento = val;
  next = nullptr;
}

// Specific constructors Node (move)
template<typename Data>
List<Data>::Node::Node(Data&& val) noexcept{
  std::swap(elemento, val);
  next = nullptr;
}

// Copy constructors Node
template<typename Data>
List<Data>::Node::Node(const Node& nodo){
  this->elemento = nodo.elemento;
  this->next = nodo.next;
}

// Move constructors Node
template<typename Data>
List<Data>::Node::Node(Node&& nodo) noexcept{
  std::swap(elemento, nodo.elemento);
  std::swap(next, nodo.next);
}

// Comparison operator Node
template<typename Data>
bool List<Data>::Node::operator==(const Node& nodo) const noexcept{
  if (elemento != nodo.elemento){
    return false;
  }
  return true;
}

// Other comparison operator Node
template<typename Data>
bool List<Data>::Node::operator!=(const Node& nodo) const noexcept{
  return !(*this == nodo);
}

// Default constructors list
template<typename Data>
List<Data>::List(){
  First = nullptr;
  Last = nullptr;
}
//Specific constructor for the list
template<typename Data>
List<Data>::List(const LinearContainer<Data>& con){
  if (con.Size() ==0 )
     return;
  else
    dim=con.Size();
  unsigned long i=0;
  Node* ptr = new Node;
  Node* curr = ptr;
  while(i < con.Size() -1){
    curr->next = new Node;
    curr = curr->next;
    curr->elemento = con[i];
    i++;
  }
  First = ptr;
  Last = curr;
  delete ptr,Last;//delete Last;
}

// Copy constructors List
template<typename Data>
List<Data>::List(const List<Data>& otherList){
    if(otherList.First == nullptr)
      return;
    Node* ptr = new Node;
    Node* curr = ptr;
    Node* oth = nullptr;
    for(oth = otherList.First; oth != nullptr; oth = oth->next){
      curr->next = new Node;
      curr = curr->next;
      curr->elemento = oth->elemento;
      curr->next = nullptr;
    }
    First = ptr->next;
    delete ptr;
}

// Move constructors list
template<typename Data>
List<Data>::List(List<Data>&& otherList) noexcept{
  dim = otherList.dim;
  otherList.dim = 0;
  First = otherList.First;
  otherList.First = nullptr;
}

// Distruttore list
template<typename Data>
List<Data>::~List(){
  Node* current = First;
  while(current != nullptr){
    Node* da_delete = current;
    current = current->next;
    delete da_delete;
  }
}

// Copy assignment list
template<typename Data>
List<Data>& List<Data>::operator=(const List<Data>& list){
  List<Data> *tmplist = new List<Data>(list);
  std::swap(*tmplist, *this);
  delete tmplist;
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

// Comparison operator list
template<typename Data>
bool List<Data>::operator==(const List<Data>& list) const noexcept{
  if(dim == list.dim){
    struct Node* current = First;
    struct Node* Tmp = list.First;
    for(unsigned long index = 0; index < dim; index++){
      if(current->elemento != Tmp->elemento){
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

// Other comparison list
template<typename Data>
bool List<Data>::operator!=(const List<Data>& list) const noexcept{
  return !(*this == list);
}

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
    return current->elemento;
  }
  else{
    current = First;
    First = First->next;
    dim--;
    return current->elemento;
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

// Clear functions list
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

// Front functions list
template<typename Data>
Data& List<Data>::Front() const{
  if (First != nullptr){
    return First->elemento;
  }
  else{
    throw std::length_error("La lista e' vuota.");
  }
}

// Back function for the list
template<typename Data>
Data& List<Data>::Back() const{
struct Node* current;
current = First;
if(current == nullptr){
  throw std::length_error("La lista e' vuota.");
}
while(current ->next != nullptr){
  current=current->next;
}
return current->elemento;

}
// Operator [] functions list
template<typename Data>
Data& List<Data>::operator[](const unsigned long index) const{
  if(index < dim){
    struct Node* current;
    current = First;
    for(unsigned long i = 0; i < index; i++){
      current = current->next;
    }
    return current->elemento;
  }
  else{
    throw std::out_of_range("Accesso all'indice " + std::to_string(index) + ": lunghezza della lista" + std::to_string(dim) + ".");
  }
}

// Map functions PreOrder list
template<typename Data>
void List<Data>::MapPreOrder(MapFunctor fun, void* par){
  MapPreOrder(fun,par,First);
}

// Map functions PostOrder list
template<typename Data>
void List<Data>::MapPostOrder(MapFunctor fun, void* par){
  MapPostOrder(fun,par,First);
}

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

// Map (protected) functions PreOrder list
template<typename Data>
void List<Data>::MapPreOrder(MapFunctor fun, void* par, Node* curr){
  for(; curr != nullptr; curr = curr->next){
    fun(curr->elemento, par);
  }
}

// Map (protected) functions PostOrder list
template<typename Data>
void List<Data>::MapPostOrder(MapFunctor fun, void* par, Node* curr){
  if(curr != nullptr){
    MapPostOrder(fun,par,curr->next);
    fun(curr->elemento,par);
  }
}

// Fold (protected) functions PreOrder list
template<typename Data>
void List<Data>::FoldPreOrder(FoldFunctor fun, const void* par, void* acc, Node* curr) const{
  for(; curr != nullptr; curr = curr->next){
    fun(curr->elemento,par,acc);
  }
}

// Fold (protected) functions PostOrder list
template<typename Data>
void List<Data>::FoldPostOrder(FoldFunctor fun, const void* par, void* acc, Node* curr) const{
  unsigned long index=dim;
  while (index > 0){

    fun((*this)[index-1],par,acc);
    index--;

}
}
}
