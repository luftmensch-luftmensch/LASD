
namespace lasd {

/* ************************************************************************** */
//MatrixVec specific member function

//Default constructor
template<typename Data>
MatrixVec<Data>::MatrixVec(){
  nrow=0;
  ncol=0;
  dim=0;
}

//Specific constructor
template<typename Data>
MatrixVec<Data>::MatrixVec(unsigned int r, unsigned int c){
  if(r!=0 && c!=0){
    nrow=r;
    ncol=c;
    dim=r*c;
    elem = new Data[dim] {};
  }
}

//Copy constructor
template<typename Data>
MatrixVec<Data>::MatrixVec(const MatrixVec<Data>& matrix):Vector<Data>(matrix){
  nrow=matrix.nrow;
  ncol=matrix.ncol;
}
//:Vector<Data>(std::move(matrix))
//Move constructor
template<typename Data>
MatrixVec<Data>::MatrixVec(MatrixVec<Data>&& matrix)noexcept:Vector<Data>(std::move(matrix)){
  std::swap(nrow,matrix.nrow);
  matrix.nrow=0;
  std::swap(ncol,matrix.ncol);
  //std::swap(elem,matrix.elem);
  //std::swap(dim,matrix.dim);
  matrix.ncol=0;
}

//Destructor
template<typename Data>
MatrixVec<Data>::~MatrixVec(){
  Vector<Data>::Clear();
  nrow=0;
  ncol=0;
}


//Copy assignment
template<typename Data>
MatrixVec<Data>& MatrixVec<Data>::operator=(const MatrixVec<Data>& matrix){
    //Vector<Data>::operator=(matrix);
    nrow=matrix.nrow;
    ncol=matrix.ncol;
    MatrixVec<Data>* newvec= new MatrixVec<Data>(matrix);
    std::swap(*this,*newvec);
    delete newvec;
    return *this;
  }

//Move assignment
template <typename Data>
MatrixVec<Data>& MatrixVec<Data>::operator=(MatrixVec<Data>&& matrix)noexcept{
    Vector<Data>::operator=(std::move(matrix));
    std::swap(nrow,matrix.nrow);
    std::swap(ncol,matrix.ncol);
    return *this;
  }

//Comparison operator
template <typename Data>
bool MatrixVec<Data>::operator==(const MatrixVec<Data>& matrix) const noexcept{
  return Vector<Data>::operator==(matrix);
}

//Other Comparison operator
template <typename Data>
bool MatrixVec<Data>::operator!=(const MatrixVec<Data>& matrix) const noexcept{
  return Vector<Data>::operator!=(matrix);
}

//RowResize function
template<typename Data>
void MatrixVec<Data>::RowResize(unsigned long newnrow){
  unsigned long newdim=newnrow*ncol;
  Vector<Data>::Resize(newdim);
  nrow=newnrow;
}

//ColumnResize function
template<typename Data>
void MatrixVec<Data>::ColumnResize(unsigned long newncol){
  if(newncol==0){
    Clear();
  }
  else if(ncol!=newncol){
    unsigned long newdim=newncol*nrow;
    MatrixVec<Data> tmpelem(nrow,newncol);
    if(ncol<newncol){
       uint i=0;
       while(i<nrow){
         uint j=0;
         while(j<ncol){
           std::swap(elem[i*ncol+j], tmpelem.elem[i*newncol+j]);
           j++;
         }
         i++;
        }
      std::swap(elem,tmpelem.elem);
      ncol = newncol;
      dim=newdim;
    }
    else if(ncol>newncol){
      uint i=0;
      while(i<nrow){
        uint j=0;
        while(j<newncol){
          std::swap(elem[i*ncol+j], tmpelem.elem[i*newncol+j]);
          j++;
        }
        i++;
       }
      std::swap(elem,tmpelem.elem);
      ncol = newncol;
      dim=newdim;
    }
  }
}

//Clear function
template<typename Data>
void MatrixVec<Data>::Clear(){
  Vector<Data>::Clear();
  nrow=0;
  ncol=0;
}

//ExistsCell function
template<typename Data>
bool MatrixVec<Data>::ExistsCell(unsigned long row,unsigned long col)const noexcept{
  return(row<nrow && col<ncol);
}

//Operator () (const)
template<typename Data>
Data const& MatrixVec<Data>::operator()(unsigned long row,unsigned long col)const{
  if(row>=nrow || col>=ncol){
    throw std::out_of_range("out_of_range: you can't access at the desired memory location");
  }
  else{
    return elem[row*ncol+col];
  }
}

//Operator () (non-const)
template<typename Data>
Data& MatrixVec<Data>::operator()(const unsigned long row,const unsigned long col){
  return const_cast<Data&>(static_cast<const MatrixVec<Data>*>(this)->operator()(row,col));
}



/* ************************************************************************** */

}
