
namespace lasd {

/* ************************************************************************** */

// Specific constructors Node
template<typename Data>
List<Data>::Node::Node( const Data& value ){
  elemento=value;
  next=nullptr;
}

// Specific constructors Node (move)
template<typename Data>
List<Data>::Node::Node (Data&& value) noexcept{
  std::swap(elemento, value);
  next = nullptr;
}

// Copy constructors Node
template<typename Data>
List<Data>::Node::Node (const Node& nodo){
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
  First=nullptr;
  Last=nullptr;
}

//Specific constructor for the list
template<typename Data>
List<Data>::List(const LinearContainer<Data>& con){
                          //if size =0, the list's pointers are nullptr because the container is empty
  if(con.Size()==0){
    First= nullptr;
    Last= nullptr;
  }
                         //else, i can insert at back of the list the elements from the container
  else{
    First= nullptr;
    Last= nullptr;
    for (unsigned long index=0; index < con.Size(); index++){
      InsertAtBack(con[index]);
    }
  }
}


// Copy constructors List
template<typename Data>
List<Data>::List(const List<Data>& oldList){
                            //if the two lists are different i can proceed with comparisons (i can't copy the same list into a list)
  if(this!=&oldList){
                            //if the list to copy is empty, i have nothing to copy
    if(oldList.First==nullptr){
    First=nullptr;
    Last=nullptr;
    dim=0;
    }
                           //else, i create a new node into the new list with the element from the other list
    else{
      struct Node* current;
      current=oldList.First;
      struct Node* node=new Node(current->elemento);
                          //here i can refresh the pointers with the correct values
      First=node;
      Last=First;
                          //i can proceed with the copy until the last one element of the other list
      current=current->next;
      while(current != nullptr){
        struct Node* newnode=new Node(current->elemento);
        Last->next=newnode;
        Last=newnode;
        current=current->next;
      }
                        //at the end, i refresh the size of the new list with the size from the other list
      dim=oldList.dim;
    }
  }
}


// Move constructors list
template<typename Data>
List<Data>::List(List<Data>&& oldList) noexcept{
  dim = oldList.dim;
  oldList.dim = 0;
  First = oldList.First;
  oldList.First = nullptr;
}

// Distruttore list
template<typename Data>
List<Data>::~List(){
  Node* current = First;
                             //delete of nodes from the list until the last one element of the list is found
  while(current != nullptr){
    Node* todelete = current;
    current = current->next;
    delete todelete;
  }
}

// Copy assignment list
template<typename Data>
List<Data>& List<Data>::operator=(const List<Data>& list){
                  //can't assign the same list
  if(this == &list){
		return *this;
  }
  List<Data> *tmplist=new List<Data>(list);
                                 //using the std::swap library function for assign a list to another list
  std::swap(*this,*tmplist);
  delete tmplist;
  return *this;
}

// Move assignment list
template<typename Data>
List<Data>& List<Data>::operator=(List<Data>&& list) noexcept{
                               //using the std::swap library function for simply exchange the pointer from the two lists
  std::swap(First, list.First);
  std::swap(Last, list.Last);
  std::swap(dim, list.dim);
  return *this;
}

// Comparison operator list
template<typename Data>
bool List<Data>::operator==(const List<Data>& list) const noexcept{
                               //the comparison makes sense if the two sizes are equal
  if(dim==list.dim){
    struct Node* currentnode = First;
    struct Node* tmp = list.First;
    for(unsigned long index = 0; index < dim; index++){
                               //comparison between the i-esim element of the two lists
      if(currentnode->elemento != tmp->elemento){
        return false;
      }
      currentnode = currentnode->next;
      tmp = tmp->next;
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
                              //simply return the !(condition) from the other comparison operator
  return !(*this == list);
}

// RemoveFromFront functions list
template<typename Data>
void List<Data>::RemoveFromFront(){
  struct Node* currentnode;
                                 //i can't remove a node from an empty list
  if(First == nullptr){
    throw std::length_error("Accesso ad una lista vuota.");
  }                               //if the pointer to the First and the Last are the same element, simply make the list empty
  else if (First==Last){
    dim--;
    First=nullptr;
    Last=nullptr;
  }
                                //else, just "discard" the pointer to the first and make the next element as First
  else{
    currentnode = First;
    First = First->next;
    dim--;
  }
}

// FrontNRemove functions list
template<typename Data>
Data& List<Data>::FrontNRemove(){
  struct Node* currentnode;
                                   //i can't remove a node from an empty list
  if(First==nullptr){
    throw std::length_error("Accesso ad una lista vuota.");
  }
                                   //if the pointer to the First and the Last are the same element, simply make the list empty and return the element
                                   //saved in the "current" var
  else if(First==Last){
    dim--;
    currentnode=First;
    First=nullptr;
    Last=nullptr;
    return currentnode->elemento;
  }
  else{
                                   //else, just "discard" the pointer to the first and make the next element as First and return the element
                                   //saved in the "current" var
    currentnode=First;
    First=First->next;
    dim--;
    return currentnode->elemento;
  }
}

// InsertAtFront functions list
template<typename Data>
void List<Data>::InsertAtFront (const Data& value){
                                          //creates a new node to insert with his value
  struct Node* newNode;
  newNode = new Node(value);
                                          //the "next" pointer of the new node points to the old head
  newNode->next=First;
                                        //the new node is the new First (head)
  First=newNode;
  dim++;
                                        //refresh the Last pointer of the list if the list is empty
  if (Last==nullptr){
    Last=newNode;
  }
}

// InsertAtFront (move) functions list
template<typename Data>
void List<Data>::InsertAtFront (Data&& value) noexcept{
                                              //creates a new node to insert with his value
  struct Node* newNode;
  newNode=new Node(std::move(value));
                                                //the "next" pointer of the new node points to the old head
  newNode->next=First;
                                                 //the new node is the new First (head)
  First=newNode;
  dim++;
                                                //refresh the Last pointer of the list if the list is empty
  if(Last == nullptr){
    Last = newNode;
  }
}

// InsertAtBack functions list
template<typename Data>
void List<Data>::InsertAtBack (const Data& value){
                                   //creates a new node to insert with his value
  struct Node* newNode;
  newNode=new Node(value);
                                  //if the list is empty, the new node is the one and only node of the list
  if(!First){
    First=newNode;
    Last=newNode;
    dim++;
  }
  else{
                                 //else, go to the bottom of the list and insert the node there
    struct Node* tmp=First;
    while(tmp->next){
       tmp = tmp->next;
    }
    tmp->next=newNode;
    dim++;
                                 //refresh the Last pointer
    Last=tmp->next;
  }
}

// InsertAtBack (move) functions list
template<typename Data>
void List<Data>::InsertAtBack(Data&& value) noexcept{
                                   //creates a new node to insert with his value
  struct Node* newNode;
  newNode = new Node(std::move(value));
                                  //if the list is empty, the new node is the one and only node of the list
  if(!First){
    First = newNode;
    Last = newNode;
    dim++;
  }
  else{
                                  //else, go to the bottom of the list and insert the node there
    struct Node* tmp=First;
    while(tmp->next) tmp=tmp->next;
    tmp->next=newNode;
    dim++;
                                  //refresh the Last pointer
    Last=tmp->next;
  }
}

// Clear functions list: non-destructive
template<typename Data>
void List<Data>::Clear(){
  struct Node* tmp;

  while(First!=nullptr){
    tmp=First;
    First=First->next;
  }
  Last=nullptr;
  dim=0;
  First=nullptr;
}

// Front functions list
template<typename Data>
Data& List<Data>::Front() const{
                                 //if the First element is empty, return the value associated
  if (First!=nullptr){
    return First->elemento;
  }
                                //else i can't return nothing because the list is empty
  else{
    throw std::length_error("La lista e' vuota.");
  }
}

// Back function for the list
template<typename Data>
Data& List<Data>::Back() const{
                            //if the size!=0, return the Last element of the list
  if(dim!=0){
    return Last->elemento;
  }
                           //else i can't return nothing because the list is empty
  else{
    throw std::length_error("Accesso ad una lista vuota.");
  }
}
// Operator [] functions list
template<typename Data>
Data& List<Data>::operator[](const unsigned long index) const{
                           //i can gain access to a specific index only if the index is between 0 and size-1
  if(index < dim){
    struct Node* current;
    current = First;
                           //now i can flow the list until i find the right element (i=index) and return the element associated
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

// Map (protected) functions PreOrder list:executed from one point of the list onwards
template<typename Data>
void List<Data>::MapPreOrder(MapFunctor fun, void* par, Node* curr){
  for(; curr != nullptr; curr = curr->next){
    fun(curr->elemento, par);
  }
}

// Map (protected) functions PostOrder list:executed from one point of the list onwards
template<typename Data>
void List<Data>::MapPostOrder(MapFunctor fun, void* par, Node* curr){
  unsigned long index = dim;
  while(index > 0){
    fun((*this)[--index],par);
  }
}

// Fold (protected) functions PreOrder list:executed from one point of the list onwards
template<typename Data>
void List<Data>::FoldPreOrder(FoldFunctor fun, const void* par, void* acc, Node* curr) const{
  for(; curr != nullptr; curr=curr->next){
    fun(curr->elemento,par,acc);
  }
}

// Fold (protected) functions PostOrder list:executed from one point of the list onwards
template<typename Data>
void List<Data>::FoldPostOrder(FoldFunctor fun, const void* par, void* acc, Node* curr) const{
  unsigned long index=dim;
  while (index > 0){
    fun((*this)[index-1],par,acc);
    index--;
    }
  }

/* ************************************************************************** */

}
