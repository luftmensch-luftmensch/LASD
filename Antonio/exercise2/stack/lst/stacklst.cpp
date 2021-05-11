
namespace lasd {

/* ************************************************************************** */
//Default Constructor: calls to the constructor of the class List
template <typename Data>
StackLst<Data>::StackLst(): List<Data>::List() {

}


// Specific constructor: calls to the specific constructor of the class List
template <typename Data>
StackLst<Data>::StackLst (const LinearContainer<Data>& con): List<Data>::List(con) {

}

// Copy constructor: calls to the copy constructor of the class List
 template<typename Data>
 StackLst<Data>::StackLst (const StackLst<Data>& stacklist): List<Data>::List(stacklist){

 }

//Move constructor list: calls to the move constructor of the class List
template<typename Data>
StackLst<Data>::StackLst (StackLst<Data>&& stacklist)noexcept: List<Data>::List(std::move(stacklist)){

}

//Copy assignment: calls to the copy assignment of the class List
template <typename Data>
StackLst<Data>& StackLst<Data>::operator= (const StackLst& stacklist){
  List<Data>::operator=(stacklist);
  return *this;
}

//Move assignment: calls to the move assignment of the class List
template <typename Data>
StackLst<Data>& StackLst<Data>::operator= (StackLst&& stacklist) noexcept{
  List<Data>::operator=(stacklist);
  return *this;
}


//Comparison operator: calls to the comparison operator of the class List
template <typename Data>
bool StackLst<Data>::operator==(const StackLst& stacklist) const noexcept{
  return List<Data>::operator==(stacklist);
}

//Other Comparison operator: calls to the comparison operator of the class List
template <typename Data>
bool StackLst<Data>::operator!=(const StackLst& stacklist) const noexcept{
  return List<Data>::operator!=(stacklist);
}

//Push function (copy): calls to the InsertAtFront function of the class List
template <typename Data>
void StackLst<Data>::Push (const Data& val){
  List<Data>::InsertAtFront(val);
}


//Push function (move): calls to the InsertAtFront function of the class List
template <typename Data>
void StackLst<Data>::Push (Data&& val) noexcept{
  List<Data>::InsertAtFront(val);
}

//Top function: calls to the Front function from the class List
template <typename Data>
Data& StackLst<Data>::Top() const {
  if( Empty() ){
  	throw std::length_error("Impossible to remove from the Stack: the Stack is empty!");
  }
  else{
  return List<Data>::Front();
  }
}

//Pop function: calls to the RemoveFromFront function from the class List
template <typename Data>
void StackLst<Data>::Pop(){
  if( Empty() ){
  	throw std::length_error("Impossible to remove from the Stack: the Stack is empty!");
  }
  else{
  List<Data>::RemoveFromFront();
  }
}

//TopNPop function: calls to the FrontNRemove function from the class List
template <typename Data>
Data StackLst<Data>::TopNPop(){
  if( Empty() ){
  	throw std::length_error("Impossible to remove from the Stack: the Stack is empty!");
  }
  else{
  return List<Data>::FrontNRemove();
  }
}

/* ************************************************************************** */

}
