
#include <stdexcept>
namespace lasd {

/* ************************************************************************** */

template<typename Data>
Vector<Data>::Vector(const ulong DimensioneN){
  elemento = new Data[DimensioneN] {};
  dimensione = DimensioneN;
}
                                    //Constructor of a vector starting with a list or a vector
template<typename Data>
Vector<Data>::Vector(const LinearContainer<Data>& Container){
  dimensione=Container.Size();
  elemento= new Data[dimensione];
  for (ulong i=0; i< dimensione; ++i){
    elemento[i]=Container[i];
  }
}

                                  //Copy Constructor
                                  //Uses the library function "copy" where:
                                  //    vec.elemento is the pointer to the first elementoent to copy
                                  //    vec.elemento+vec.size is the pointer to the last elementoent to copy
                                  //    elemento is the destination's vector
template<typename Data>
Vector<Data>::Vector (const Vector<Data>& vec){
  elemento= new Data[vec.dimensione];
  std::copy(vec.elemento, vec.elemento+vec.dimensione, elemento);
  dimensione=vec.dimensione;
}

template<typename Data>
Vector<Data>::Vector (Vector<Data>&& vec) noexcept{
  std::swap(elemento, vec.elemento);
  std::swap(dimensione, vec.dimensione);
}

                                 //Destructor
template<typename Data>
Vector<Data>::~Vector() {
  delete[] elemento;
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
  std::swap(elemento, vec.elemento);
  std::swap(dimensione, vec.dimensione);
  return *this;
}
                              //Comparison operators
template<typename Data>
bool Vector<Data>::operator==(const Vector<Data>& vec) const noexcept{
  if(dimensione == vec.dimensione){
    for(ulong i = 0; i < dimensione; ++i){
      if(elemento[i] != vec.elemento[i]){
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

template<typename Data>
void Vector<Data>::Resize(const unsigned long DimensioneN){
  if(DimensioneN == 0){
    Clear();
  }
  else if(dimensione != DimensioneN){
    ulong elemDaCopiare = (dimensione < DimensioneN) ? dimensione : DimensioneN;
    ulong i = 0;

    Data* TempArray = new Data[DimensioneN] {};

    while (i < elemDaCopiare){
      std::swap(elemento[i], TempArray[i]);
      ++i;
    }
    std::swap(elemento,TempArray);
    dimensione = DimensioneN;
    delete[] TempArray;
  }
}

template<typename Data>
void Vector<Data>::Clear(){
  delete[] elemento;
  elemento = nullptr;
  dimensione = 0;
}
template<typename Data>
Data& Vector<Data>::Front() const{
  if(dimensione != 0){
    return elemento[0];
  }
  else{
    throw std::length_error("Array vuoto!");
  }
}
template<typename Data>
Data& Vector<Data>::Back() const{
  if(dimensione != 0){
    return elemento[dimensione - 1];
  }
  else{
    throw std::length_error("Array vuoto");
  }
}

template<typename Data>
Data& Vector<Data>::operator[](const ulong j) const{
  if(j < dimensione){
    return elemento[j];
  }
  else{
    throw std::out_of_range("Accesso ad un indice non valido");
  }
}

template<typename Data>
void Vector<Data>::MapPreOrder(MapFunctor fun, void* par){
  ulong j = 0;
  while (j < dimensione){
    fun(elemento[j],par);
    j++;
  }
}
template<typename Data>
void Vector<Data>::MapPostOrder(MapFunctor fun, void* par){
  ulong j = dimensione;
  while (j > 0){
    fun(elemento[j],par);
    --j;
  }
}

template<typename Data>
void Vector<Data>::FoldPreOrder(FoldFunctor fun, const void* par, void* acc) const{
  ulong j = 0;
  while (j < dimensione){
    fun(elemento[j],par,acc);
    j++;
  }
}

template<typename Data>
void Vector<Data>::FoldPostOrder(FoldFunctor fun, const void* par, void* acc) const{
  for (ulong i = dimensione; i > 0; --i){
    fun(elemento[i-1],par,acc);
  }
}
}
