
namespace lasd {

/* ************************************************************************** */
                         //Default Constructor
template <typename Data>
StackLst<Data>::StackLst(): List<Data>::List() {}


// Specific constructor
template <typename Data>
StackLst<Data>::StackLst(const LinearContainer<Data>& con): List<Data>::List(con) {}

// Copy constructor
 template<typename Data>
 StackLst<Data>::StackLst(const StackLst<Data>& otherStackLst): List<Data>::List(otherStackLst){}

                     //Move constructor list
template<typename Data>
StackLst<Data>::StackLst(StackLst<Data>&& otherStackLst) noexcept: List<Data>::List(std::move(otherStackLst)){}
                    //Copy assignment
template <typename Data>
StackLst<Data>& StackLst<Data>::operator=(const StackLst& s){
  List<Data>::operator=(s);
  return *this;
}
                    //Move assignment
template <typename Data>
StackLst<Data>& StackLst<Data>::operator=(StackLst&& s) noexcept {
  List<Data>::operator=(std::move(s));
  return *this;
}


                           //Comparison operator
template <typename Data>
bool StackLst<Data>::operator==(const StackLst& s) const noexcept{
  return List<Data>::operator==(s);
}
                          //Other Comparison operator
template <typename Data>
bool StackLst<Data>::operator!=(const StackLst& s) const noexcept{
  return List<Data>::operator!=(s);
}

//Push function (copy)
template <typename Data>
void StackLst<Data>::Push(const Data& d){
  List<Data>::InsertAtFront(d);
}


//Push function (move)
template <typename Data>
void StackLst<Data>::Push(Data&& d){
  List<Data>::InsertAtFront(std::move(d));
}

                          //Top function
template <typename Data>
Data& StackLst<Data>::Top() const {
  if(Empty())
  	throw std::length_error("Could not remove from the Stack: Stack size is 0!");

  return List<Data>::Front();
}
                          //Pop function
template <typename Data>
void StackLst<Data>::Pop(){
  if(Empty())
  	throw std::length_error("Could not remove from the Stack: Stack size is 0!");

  List<Data>::RemoveFromFront();
}
                         //TopNPop function
template <typename Data>
Data StackLst<Data>::TopNPop(){
  if(Empty())
  	throw std::length_error("Could not remove from the Stack: Stack size is 0!");

  return List<Data>::FrontNRemove();
}

/* ************************************************************************** */

}
