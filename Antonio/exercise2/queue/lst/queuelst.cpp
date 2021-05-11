  
namespace lasd {

/* ************************************************************************** */
//Default constructor: calls to the constructor of the class List
template <typename Data>
QueueLst<Data>::QueueLst(): List<Data>() {

}

//Specific constructor: calls to the specific constructor of the class List
template <typename Data>
QueueLst<Data>::QueueLst (const LinearContainer<Data>& con): List<Data>::List(con) {

}

//Copy constructor: calls to the copy constructor of the class List
template <typename Data>
QueueLst<Data>::QueueLst(const QueueLst& queuelist): List<Data>(queuelist){

}

//Move constructor: calls to the move constructor of the class List
template <typename Data>
QueueLst<Data>::QueueLst(QueueLst&& queuelist) noexcept : List<Data>(std::move(queuelist)){

}

//Copy assignment:calls to the copy assignment of the class List
template <typename Data>
QueueLst<Data>& QueueLst<Data>::operator= (const QueueLst& queuelist){
  List<Data>::operator=(queuelist);
  return *this;
}

//Move assignment: calls to the move assignment of the class List
template <typename Data>
QueueLst<Data>& QueueLst<Data>::operator=(QueueLst&& queuelist) noexcept {
  List<Data>::operator=(queuelist);
  return *this;
}

//Comparison operator: calls to the comparison operator of the class List
template <typename Data>
bool QueueLst<Data>::operator== (const QueueLst& queuelist) const noexcept{
  return List<Data>::operator== (queuelist);
}

//Other comparison operator: calls to the comparison operator of the class List
template <typename Data>
bool QueueLst<Data>::operator!= (const QueueLst& queuelist) const noexcept{
  return List<Data>::operator!= (queuelist);
}

//Head function: calls to the Front function of the class List
template <typename Data>
Data& QueueLst<Data>::Head() const {
                            //if the queue is empty, throws an exception (lenght_error)
  if( Empty() ){
  	throw std::length_error("Impossible to remove from the Queue: the Queue is empty!");
  }
  else{
  return List<Data>::Front();
  }
}

//HeadNDequeue function
template <typename Data>
Data QueueLst<Data>::HeadNDequeue(){
                        //if the queue is empty, throws an exception (lenght_error)
  if( Empty() ){
    throw std::length_error("Impossible to remove from the Queue: the Queue is empty!");
  }
  else{
    return List<Data>::FrontNRemove();
  }
}

//Enqueue function (copy): calls to the InsertAtBack function of the class List
template <typename Data>
void QueueLst<Data>::Enqueue (const Data& val){
  List<Data>::InsertAtBack(val);
}

//Enqueue function (move): calls to the InsertAtBack function of the class List
template <typename Data>
void QueueLst<Data>::Enqueue(Data&& val) noexcept{
  List<Data>::InsertAtBack(val);
}

//Dequeue function: calls to the RemoveFromFront function from the class List
template <typename Data>
void QueueLst<Data>::Dequeue(){
                               //if the queue is empty, throws an exception (lenght_error)
  if( Empty() ){
  	throw std::length_error("Impossible to remove from the Queue: the Queue is empty!");
  }
  else{
  return List<Data>::RemoveFromFront();
  }
}





/* ************************************************************************** */

}
