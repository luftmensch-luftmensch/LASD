
namespace lasd {

/* ************************************************************************** */

                          //Default constructor
template <typename Data>
StackVec<Data>::StackVec(): Vector<Data>::Vector(1){}


                   //Specific Constructor
template<typename Data>
StackVec<Data>::StackVec(const LinearContainer<Data>& con){
  dimensione=con.Size();
  elem= new Data[dimensione];
  for (ulong i=0; i<con.Size(); ++i){
    Push(con[i]);
  }
}
                   //Copy Constructor
template<typename Data>
StackVec<Data>::StackVec(const StackVec<Data>& stackvec): Vector<Data>::Vector(stackvec){
  top= stackvec.top;
}

                  // Move constructor
template<typename Data>
StackVec<Data>::StackVec(StackVec<Data>&& stackvec) : Vector<Data>::Vector(std::move(stackvec)){
  top=stackvec.top;
  stackvec.Clear();

}


                  //Copy assignment
template<typename Data>
StackVec<Data>& StackVec<Data>::operator=(const StackVec<Data>& stackvec){
    Vector<Data>::operator=(stackvec);
    top=stackvec.top;
    return *this;
}
                 //Move assignment
template<typename Data>
StackVec<Data>& StackVec<Data>::operator=(StackVec<Data>&& stackvec) noexcept{
  Vector<Data>::operator=(std::move(stackvec));
  std::swap(top, stackvec.top);
  return *this;
}
                 //Comparison operator
template <typename Data>
bool StackVec<Data>::operator==(const StackVec& s) const noexcept{
  if(this == &s)
    return true;

  if(top != s.top)
    return false;

  ulong index = 0;
  while(index < top && Vector<Data>::operator[](index) == s.Vector<Data>::operator[](index))
    index++;


  return index == top;
}
                //Other comparison operator
template <typename Data>
bool StackVec<Data>::operator!=(const StackVec& s) const noexcept{
  return !(*this == s);
}
               //Top function
template <typename Data>
Data& StackVec<Data>::Top() const {
  if(Empty())
  	throw std::length_error("Could not remove from the Stack: Stack size is 0!");

  return Vector<Data>::operator[](top-1);
}
              //Pop function
template <typename Data>
void StackVec<Data>::Pop(){
  if(Empty())
  	throw std::length_error("Could not remove from the Stack: Stack size is 0!");

  Data deleted = std::move(Vector<Data>::operator[](--top));
  (void)deleted;

  if(top < dimensione/4)
    Reduce();
}
                       //TopNPop function
template <typename Data>
Data StackVec<Data>::TopNPop(){
  if(Empty())
  	throw std::length_error("Could not remove from the Stack: Stack size is 0!");

  Data ret = std::move(Vector<Data>::operator[](--top));

  if(top < dimensione/4)
    Reduce();

  return ret;
}

                      //Push function (copy)
template <typename Data>
void StackVec<Data>::Push(const Data& d){
  Vector<Data>::operator[](top++) = d;
  if(top == dimensione)
    Expand();
}
                    //Push function (move)
template <typename Data>
void StackVec<Data>::Push(Data&& d){
  Vector<Data>::operator[](top++) = std::move(d);
  if(top == dimensione)
    Expand();
}
                  //Empty function
template <typename Data>
bool StackVec<Data>::Empty() const noexcept {
  return top == 0;
}
                 //Size function
template <typename Data>
ulong StackVec<Data>::Size() const noexcept {
  return top;
}
                //Clear function
template <typename Data>
void StackVec<Data>::Clear() noexcept {
  Vector<Data>::Resize(1);
  top = 0;
}
                 //Expand function
template <typename Data>
void StackVec<Data>::Expand(){
  Vector<Data>::Resize(dimensione*2);
}
                //Reduce function
template <typename Data>
void StackVec<Data>::Reduce(){
  Vector<Data>::Resize(dimensione/2);
}

/* ************************************************************************** */

}
