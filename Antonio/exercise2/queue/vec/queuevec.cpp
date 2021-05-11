
namespace lasd {

/* ************************************************************************** */
//Default constructor: calls to the default constructor of the class Vector
template <typename Data>
QueueVec<Data>::QueueVec(): Vector<Data>(2){

}

//Specific constructor
template <typename Data>
QueueVec<Data>::QueueVec(const LinearContainer<Data>& con): Vector<Data>::Vector(con) {

  dim=con.Size();
  elem= new Data[dim];
  unsigned long ind=0;
  while(ind<con.Size()){
                  //using the Enqueue function defined later
    Enqueue(con[ind]);
    ind++;
  }
}

//Copy constructor: calls to the copy constructor of the class Vector
template <typename Data>
QueueVec<Data>::QueueVec (const QueueVec& queuevector): Vector<Data>::Vector(queuevector){
                  //copy of the head and tail values from the other queue
  head = queuevector.head;
  tail = queuevector.tail;
}

//Move constructor: calls to the move constructor of the class Vector
template <typename Data>
QueueVec<Data>::QueueVec(QueueVec&& queuevector) noexcept: Vector<Data>::Vector(std::move(queuevector)) {
                            //move of the head and tail values from the other queue
  std::swap(head, queuevector.head);
  std::swap(tail, queuevector.tail);
                            //clear of the old queue
  queuevector.Clear();
}

//Copy assignment: calls to the copy assignment from the class Vector
template <typename Data>
QueueVec<Data>& QueueVec<Data>::operator= (const QueueVec& queuevector){
  Vector<Data>::operator=(queuevector);
                      //copy of the head and tail values from the other queue

  tail = queuevector.tail;
  head = queuevector.head;

  return *this;
}

//Move assignment: calls to the move assignment from the class Vector
template <typename Data>
QueueVec<Data>& QueueVec<Data>::operator=(QueueVec&& queuevector)noexcept{
  Vector<Data>::operator=(queuevector);
                         //move of the head and tail values from the other queue
  std::swap(head, queuevector.head);
  std::swap(tail, queuevector.tail);

  return *this;
}

//Comparison operator:
template <typename Data>
bool QueueVec<Data>::operator==(const QueueVec& queuevector) const noexcept{
                             //if the two object are equal, returns true
  if(this == &queuevector){
    return true;
  }
                            //if the two sizes of the two queues are different, returns false
  if( Size() != queuevector.Size() ){
    return false;
  }
                             //else, using the operators from the classe Vector, just scrolling them and matching their values
                             // using the operator [] from the class Vector
  unsigned long i = head,j = queuevector.head,count=0;
  while( i != tail && Vector<Data>::operator[](i) == queuevector.Vector<Data>::operator[](j) ){
    i++;
    j++;
    count++;
  }
                      //at the end, if the counter is equal to the size, returns true
  return (Size() == count);
}

//Other comparison operator: returns false if the two stacks are not equal
template <typename Data>
bool QueueVec<Data>::operator!= (const QueueVec& queuevector)const noexcept{
  return !(*this == queuevector);
}

//Head function: returns the head of the queue using the operator [] from the class Vector
template <typename Data>
Data& QueueVec<Data>::Head() const {
                           //if the stack is empty, throws an exception (lenght_error)
  if( Empty() ){
  	throw std::length_error("Impossible to remove from the Queue: the Queue is empty!");
  }
                          //else returns the head of the queue
  else{
  return Vector<Data>::operator[](head);
  }
}

//Dequeue function: pops an element from the queue
template <typename Data>
void QueueVec<Data>::Dequeue(){
                               //if the stack is empty, throws an exception (lenght_error)
  if( Empty() ){
  	throw std::length_error("Impossible to remove from the Queue: the Queue is empty!");
  }                            //else execute the the dequeue function
  else{
                         //move of the head of the queue into a variable that will be deleted at the end of the scope
    Data to_delete=std::move(Vector<Data>::operator[](head));
    head++;
    if( Size() < dim/4 ){
      Reduce();
    }
  }
}

//HeadNDequeue function: pops from the queue and returns the popped value
template <typename Data>
Data QueueVec<Data>::HeadNDequeue(){
  if( Empty() ){
  	throw std::length_error("Impossible to remove from the Queue: the Queue is empty!");
  }
  else{
                  //move of the head of the queue into an internal variable that will be returned
    Data ret = std::move(Vector<Data>::operator[](head));
    head =(head+1)%dim;
    if( Size() < dim/4 ){
      Reduce();
    }
    return ret;
  }
}

//Enqueue function (copy): insert an element into the queue
template <typename Data>
void QueueVec<Data>::Enqueue(const Data& val){
                          //uses the operator [] from the class Vector to copy the value into the correct index (tail of the queue)
  Vector<Data>::operator[](tail)=val;
  tail = (tail+1) % dim;
  if(tail==head){
    Expand();
  }
}

//Enqueue function (move): insert an element into the queue
template <typename Data>
void QueueVec<Data>::Enqueue(Data&& val) noexcept{
                              //uses the operator [] from the class Vector to move the value into the correct index (tail of the queue)
  Vector<Data>::operator[](tail)=val;
  tail =(tail+1)%dim;
  if(tail==head){
    Expand();
  }
}

//Empty function: returns true if the queue is empty, false otherwise
template <typename Data>
bool QueueVec<Data>::Empty()const noexcept{
  return (tail==head);
}

//Size function: returns the size of the queue
template <typename Data>
unsigned long QueueVec<Data>::Size()const noexcept{

  return (dim+tail-head)%dim;
}

//Clear: returns the queue empty, calls to the resize function from the class Vector
template <typename Data>
void QueueVec<Data>::Clear()noexcept{
  Vector<Data>::Resize(2);
  head=0;
  tail=0;
}

//Expand function: increment the size of the queue, calls to the resize function from the class Vector
template <typename Data>
void QueueVec<Data>::Expand() {
  unsigned long newdim=dim*2;

  Vector<Data>::Resize(newdim);

                               //the new tail will be in the position where the first element is inserted (i=0 => tail=dim/2)
  tail=newdim/2;
  /*2)unsigned long newdim=dim*2;
  Data* tmpelem=new Data[newdim] {};
  unsigned long i=0;
  while(i<dim){
    std::swap(elem[i], tmpelem[i]);
    i++;                                     1 2 3 4 0 0 0 0 ---> 0 0 0 0 1 2 3 4
  }
  std::swap(elem,tmpelem);
  dim=newdim;
  delete[] tmpelem;
  tail=dim/2;*/

  /*3)Vector<Data>::Resize(newdim);
  while(i<tail){
    Vector::operator[i+dim/2]=std::move(Vector::operator[i])
*/
  }

//Reduce function: decrement the size of the queue, calls to the resize function from the class Vector
template <typename Data>
void QueueVec<Data>::Reduce() {
  Vector<Data> newqueue(dim/2);
  unsigned long oldindex = head;
  unsigned long newindex = 0;


                       //move of the values from the old queue to the new queue
  while(oldindex != tail){
      newqueue[newindex++] = std::move(Vector<Data>::operator[](oldindex));
      oldindex++;
  }
                      //setting the values of head and tail correctly
  head = 0;
  tail = newindex;
                      //move of the new queue into the original queue deleting the temporary queue
  Vector<Data>::operator=(std::move(newqueue));
}
/* ************************************************************************** */

}
