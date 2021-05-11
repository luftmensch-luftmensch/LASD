
#include <stdexcept>
namespace lasd {

/* ************************************************************************** */
                                     //Constructor of a vector with a given dimension

template<typename Data>
Vector<Data>::Vector(const unsigned long newdim){
  elem = new Data[newdim] {};
  dim = newdim;
}
                                    //Constructor of a vector starting with a list or a vector
template<typename Data>
Vector<Data>::Vector(const LinearContainer<Data>& con){
  dim=con.Size();
  elem= new Data[dim];
  for (unsigned long i=0; i< dim; ++i){
    elem[i]=con[i];
  }
}

                                  //Copy Constructor
                                  //Uses the library function "copy" where:
                                  //    vec.elem is the pointer to the first element to copy
                                  //    vec.elem+vec.size is the pointer to the last element to copy
                                  //    elem is the destination's vector
template<typename Data>
Vector<Data>::Vector (const Vector<Data>& vec){
  elem= new Data[vec.dim];
  std::copy(vec.elem, vec.elem+vec.dim, elem);
  dim=vec.dim;
}

                                 //Move Constructor
                                 //Uses the library function "swap" to swap the elements of the two vectors first,
                                 //and then the sizes of the two vectors
template<typename Data>
Vector<Data>::Vector (Vector<Data>&& vec) noexcept{
  std::swap(elem, vec.elem);
  std::swap(dim, vec.dim);
}

                                 //Destructor
template<typename Data>
Vector<Data>::~Vector() {
  delete[] elem;
}

                                //Copy assignment
                                //Create a new Vector using the constructors
                                //Then there is a swap of pointers between the new vector pointer and the old one
template <typename Data>
Vector<Data>& Vector<Data>::operator=(const Vector<Data>& vec) {
  Vector<Data>* newvec= new Vector<Data>(vec);
  std::swap(*newvec, *this);
  delete newvec;
  return *this;
}

                               //Move assignment
template<typename Data>
Vector<Data>& Vector<Data>::operator=(Vector<Data>&& vec) noexcept{
  std::swap(elem, vec.elem);
  std::swap(dim, vec.dim);
  return *this;
}
                              //Comparison operators
template<typename Data>
bool Vector<Data>::operator==(const Vector<Data>& vec) const noexcept{
  if(dim == vec.dim){
    for(unsigned long i = 0; i < dim; ++i){
      if(elem[i] != vec.elem[i]){
        return false;
      }
    }
    return true;
  }
  else{
    return false;
  }
}

template<typename Data>
bool Vector<Data>::operator!=(const Vector<Data>& vec) const noexcept{
  return !(*this == vec);
}

                            /* Resize function
                               If newsize=0 then call the function Clear()
                               else if the new size is different from the old one then create a tmparray and fill it until all the elements have been moved
                                and then swap the two pointers and the sizes
                            */
template<typename Data>
void Vector<Data>::Resize(const unsigned long newdim){
  if(newdim == 0){
    Clear();
  }
  else if(dim != newdim){
    unsigned long limit = (dim < newdim) ? dim : newdim;
    Data* tmpelem = new Data[newdim] {};
    for(unsigned long i = 0; i < limit; ++i){
      std::swap(elem[i], tmpelem[i]);
    }
    std::swap(elem,tmpelem);
    dim = newdim;
    delete[] tmpelem;
  }
}

                           // Clear function
template<typename Data>
void Vector<Data>::Clear(){
  delete[] elem;
  elem = nullptr;
  dim = 0;
}

                          /* Front function
                             If size=0, returns the first element
                             else it throws a lenght_error;
                          */
template<typename Data>
Data& Vector<Data>::Front() const{
  if(dim != 0){
    return elem[0];
  }
  else{
    throw std::length_error("Accesso ad un array vuoto.");
  }
}

                            /* Back function
                               If size=0, returns the last elemento
                               else it throws a lenght_error
                            */
template<typename Data>
Data& Vector<Data>::Back() const{
  if(dim != 0){
    return elem[dim - 1];
  }
  else{
    throw std::length_error("Accesso ad un array vuoto.");
  }
}

                            /* Access ( [] ) operator
                              Returns the element in a specific index if the index <= sizes
                              else it throws an out_of_range exception */
template<typename Data>
Data& Vector<Data>::operator[](const unsigned long i) const{
  if(i < dim){
    return elem[i];
  }
  else{
    throw std::out_of_range("Accesso all'indice: " + std::to_string(i) + ": lunghezza del vettore: " + std::to_string(dim) + ".");
  }
}

                            /* Map function PreOrder
                               Array visit from the first to the last element
                               Can modify data who have been visited*/
template<typename Data>
void Vector<Data>::MapPreOrder(MapFunctor fun, void* par){
  for(unsigned long i = 0; i < dim; ++i){
    fun(elem[i],par);
  }
}

                           /* Map function PostOrder
                              Array visit from the last to the first element
                              Can modify data who have been visited*/
template<typename Data>
void Vector<Data>::MapPostOrder(MapFunctor fun, void* par){
  unsigned long i = dim;
  while(i > 0){
    fun(elem[--i],par);
  }
}

                          /*Fold function PreOrder
                            Array visit from the first to the last element
                            Can't modify data who have been visited but remembers the data*/
template<typename Data>
void Vector<Data>::FoldPreOrder(FoldFunctor fun, const void* par, void* acc) const{
  for(unsigned long i = 0; i < dim; ++i){
    fun(elem[i],par,acc);
  }
}

                         /* Fold function PostOrder
                            Array visit from the last to the first element
                            Can't modify data who have been visited but remembers the data */
template<typename Data>
void Vector<Data>::FoldPostOrder(FoldFunctor fun, const void* par, void* acc) const{
  unsigned long i = dim;
  while(i > 0){
    fun(elem[--i],par,acc);
  }
}
/* ************************************************************************** */
}
