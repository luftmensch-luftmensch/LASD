
namespace lasd {

/* ************************************************************************** */

//Default constructor: calls to the default constructor of the class Vector
template <typename Data>
StackVec<Data>::StackVec(): Vector<Data>::Vector(2){

}


//Specific Constructor
template<typename Data>
StackVec<Data>::StackVec (const LinearContainer<Data>& con){
  dim=con.Size();
  elem= new Data[dim];
  unsigned long ind=0;
  while(ind<con.Size()){
                      //using the Push function defined later
    Push(con[ind]);
    ind++;
  }
}

//Copy Constructor: calls to the copy constructor of the class Vector
template<typename Data>
StackVec<Data>::StackVec(const StackVec<Data>& stackvector): Vector<Data>::Vector(stackvector){
                        //copy of the top value from the other stack
  top= stackvector.top;
}

//Move constructor: calls to the move constructor of the class Vector
template<typename Data>
StackVec<Data>::StackVec(StackVec<Data>&& stackvector) : Vector<Data>::Vector(std::move(stackvector)){
                       //move of the top value from the other stack
  std::swap(top, stackvector.top);
  stackvector.Clear();

}

//Copy assignment: calls to the copy assignment from the class Vector
template<typename Data>
StackVec<Data>& StackVec<Data>::operator=(const StackVec<Data>& stackvector){
    Vector<Data>::operator=(stackvector);
                      //copy of the top value from the other stack
    top=stackvector.top;
    return *this;
}

//Move assignment: calls to the move assignment from the class Vector
template<typename Data>
StackVec<Data>& StackVec<Data>::operator=(StackVec<Data>&& stackvector) noexcept{
  Vector<Data>::operator=(stackvector);
                      //move of the top value from the other stack
  std::swap(top, stackvector.top);
  return *this;
}

//Comparison operator
template <typename Data>
bool StackVec<Data>::operator== (const StackVec& stackvector) const noexcept{
                      //if the two object are equal, returns true
  if(this == &stackvector)
    return true;
                      //if the two top of the two stacks are different, returns false
  if(top != stackvector.top)
    return false;
                      //else, using the operators from the classe Vector, just scrolling them and matching their values
                      // using the operator [] from the class Vector
  unsigned long j = 0;
  while(j < top && Vector<Data>::operator[](j) == stackvector.Vector<Data>::operator[](j))
    j++;

                     //at the end, if the two index from the other stacks are equal, returns true
  return top == j;
}

//Other comparison operator: returns false if the two stacks are not equal
template <typename Data>
bool StackVec<Data>::operator!= (const StackVec& stackvector) const noexcept{
  return !(*this == stackvector);
}

//Top function: returns the top of the stack using the operator [] from the class Vector
template <typename Data>
Data& StackVec<Data>::Top() const {
                              //if the stack is empty, throws an exception (lenght_error)
  if( Empty() ){
  	throw std::length_error("Impossible to remove from the Stack: the Stack is empty!");
  }
  else{
  return Vector<Data>::operator[](top);
  }
}

//Pop function: pops an element from the stack
template <typename Data>
void StackVec<Data>::Pop() {
  if( Empty() ){
  	throw std::length_error("Impossible to remove from the Stack: the Stack is empty!");
                            //free the memory of the old top value
  }
  else{
    std::move(Vector<Data>::operator[](top));
                            //decrement of the top sentinel
    top--;
                           //if the stack has too much empty location, the reduce his size
    if(top < ((dim-1)/4)){
      Reduce();
    }
  }
}

//TopNPop function: pops from the stack and returns the popped value
template <typename Data>
Data StackVec<Data>::TopNPop() {
  if( Empty() ){
  	throw std::length_error("Impossible to remove from the Stack: the Stack is empty!");
  }
                        //free the memory of the old top value
  Data ret = std::move(Vector<Data>::operator[](top));
  top--;
                       //if the stack has too much empty location, the reduce his size
  if(top < ((dim-1)/4)){
    Reduce();
  }
                       //returns the popped value
  return ret;
}

//Push function (copy): pushes an element into the stack
template <typename Data>
void StackVec<Data>::Push (const Data& val){
  top=top+1;
  Vector<Data>::operator[](top)=val;

  if(top == dim-1){
    Expand();
  }
}

//Push function (move): pushes an element into the stack
template <typename Data>
void StackVec<Data>::Push (Data&& val) noexcept{
  top=top+1;
  Vector<Data>::operator[](top)=val;

  if(top == dim-1){
    Expand();
  }
}

//Empty function: returns true if the stack is empty, false otherwise
template <typename Data>
bool StackVec<Data>::Empty() const noexcept {
  return top == -1;
}

//Size function: returns the size of the stack
template <typename Data>
unsigned long StackVec<Data>::Size() const noexcept {
  return top+1;
}

//Clear function: returns the stack empty, calls to the resize function from the class Vector
template <typename Data>
void StackVec<Data>::Clear() noexcept {
    Vector<Data>::Resize(2);
  top = -1;
}

//Expand function: increment the size of the stack, calls to the resize function from the class Vector
template <typename Data>
void StackVec<Data>::Expand(){
  Vector<Data>::Resize(dim*2);
}

//Reduce function: decrement the size of the stack, calls to the resize function from the class Vector
template <typename Data>
void StackVec<Data>::Reduce(){
  Vector<Data>::Resize(dim/2);
}

/* ************************************************************************** */

}
