
namespace lasd {

/* ************************************************************************** */

//MatrixCSR specific member function

//Default constructor
template<typename Data>
MatrixCSR<Data>::MatrixCSR(){
  ncol=0;
  nrow=0;
  rowsvector.Resize(1);
  rowsvector[0]=&First;
}

//Specific constructor
template <typename Data>
MatrixCSR<Data>::MatrixCSR(unsigned long rows,unsigned long columns){
  ncol=columns;
  nrow=rows;

  rowsvector.Resize(rows+1);
  for(unsigned long index=0;index<=rows;index++){
    rowsvector[index]=&First;
  }
}

//Destructor
template<typename Data>
MatrixCSR<Data>::~MatrixCSR(){
  List<std::pair<Data,unsigned long>>::Clear();
  rowsvector.Clear();
  nrow=0;
  ncol=0;
}

//Copy constructor
template <typename Data>
MatrixCSR<Data>::MatrixCSR(const MatrixCSR<Data>& mat) : MatrixCSR(mat.nrow,mat.ncol){
  for(unsigned long row=0;row<nrow;row++){
    for(Node** ptr=mat.rowsvector[row];ptr!=mat.rowsvector[row+1];ptr= &((*ptr)->next)){
      Node& nod= **ptr;
      (*this)(row,nod.elemento.second)= nod.elemento.first;
    }
  }
}

//Move constructor
template <typename Data>
MatrixCSR<Data>::MatrixCSR(MatrixCSR<Data>&& matrix)noexcept:List<std::pair<Data,ulong>>::List(std::move(matrix)){
  rowsvector.Resize(1);
  std::swap(nrow,matrix.nrow);
  std::swap(ncol,matrix.ncol);
  std::swap(rowsvector,matrix.rowsvector);
  rowsvector[0]=&First;
  for(unsigned long index=0;index<matrix.dim &&matrix.rowsvector[index]==&matrix.First;++index){
    matrix.rowsvector[index]=&matrix.First;
  }
  matrix.Clear();
}

//Copy assignment
template <typename Data>
MatrixCSR<Data>& MatrixCSR<Data>::operator=(const MatrixCSR<Data>& matrix){
  MatrixCSR<Data>* newmatrix= new MatrixCSR<Data>(matrix);
  std::swap(*this,*newmatrix);
  delete newmatrix;
  return *this;
}

//Move assignment
template<typename Data>
MatrixCSR<Data>& MatrixCSR<Data>::operator=(MatrixCSR<Data>&& matrix) noexcept{

  std::swap(First,matrix.First);
  std::swap(nrow,matrix.nrow);
  std::swap(ncol,matrix.ncol);
  std::swap(rowsvector,matrix.rowsvector);
  std::swap(dim,matrix.dim);
  for(unsigned long index=0;index<dim &&rowsvector[index]==&matrix.First;++index){
      rowsvector[index]=&First;
  }
  for(unsigned long index=0;index<matrix.dim &&matrix.rowsvector[index]==&First;++index){
    matrix.rowsvector[index]=&matrix.First;
  }
  return *this;
}

//Comparison operator
template <typename Data>
bool MatrixCSR<Data>::operator==(const MatrixCSR<Data>& matrix) const noexcept{
  return (nrow==matrix.nrow) && (ncol==matrix.ncol) && List<std::pair<Data,unsigned long>>::operator==(matrix);
}
//Other comparison operator
template <typename Data>
bool MatrixCSR<Data>::operator!=(const MatrixCSR<Data>& matrix) const noexcept{
  return !(*this==matrix);
}

//RowResize function
template <typename Data>
void MatrixCSR<Data>::RowResize(unsigned long newnrow){
  if(newnrow==0){
    List<std::pair<Data,unsigned long>>::Clear();
  }
  else if(newnrow<nrow){
    Node** ptr=rowsvector[newnrow];
     while((*ptr)!=nullptr){
       Node* tmp=*ptr;
       *ptr=(*ptr)->next;
       delete tmp;
       tmp=nullptr;
       --dim;
     }
    rowsvector.Resize(newnrow+1);
  }
  else{
    rowsvector.Resize(newnrow+1);
    for(uint i=nrow;i<newnrow;i++){

      rowsvector[i+1]=rowsvector[i];
    }
  }
nrow=newnrow;
}

//ColumnResize function
template <typename Data>
void MatrixCSR<Data>::ColumnResize(unsigned long newncol){
  if(newncol==0){
    List<std::pair<Data,unsigned long>>::Clear();
  }
  else if(newncol<ncol){
    unsigned long index=1;
    Node** ptr=&First;
    while(index<=nrow){
      Node* nod;
      Node** ext=rowsvector[index];
      while(ptr!=ext && (*ptr)->elemento.second< newncol){
        nod=*ptr;
        ptr=&(nod->next);
      }
      if(ptr!=ext){
        if(ext==rowsvector[nrow]){
          Last=nod;
        }
        Node* tmp=*ptr;
        *ptr=*ext;
        *ext=nullptr;
        for(Node* ptr=tmp;ptr!=nullptr;ptr=ptr->next){
          dim--;
        }
        delete tmp;
      }
      for(;index<=nrow && rowsvector[index]==ext;++index){
        rowsvector[index]=ptr;
      }
    }
  }
  ncol=newncol;
}

//Clear function
template <typename Data>
void MatrixCSR<Data>::Clear(){
  nrow=0;
  ncol=0;
  List<std::pair<Data,unsigned long>>::Clear();
  rowsvector.Resize(1);

}

//ExistsCell function
template <typename Data>
bool MatrixCSR<Data>::ExistsCell(unsigned long row,unsigned long column)const noexcept{
  if((row<nrow) && (column<ncol)){
    Node** ptr= rowsvector[row];
    while(ptr!= rowsvector[row+1]) {
      Node& nod=**ptr;
      if(nod.elemento.second==column){
        return true;
      }
      ptr=&(nod.next);
    }
  }
  return false;
}


//Operator () function (non-const)
template <typename Data>
Data& MatrixCSR<Data>::operator()(unsigned long row,unsigned long col){
  if((row<nrow) && (col<ncol)){
    Node** ptr=rowsvector[row];
    while(ptr!=rowsvector[row+1]){
      if((*ptr)->elemento.second==col){
        return (*ptr)->elemento.first;
      }
      else if((*ptr)->elemento.second>col){
        Node* newnode=new Node;
        newnode->elemento.second=col;
        Node* tmp=*ptr;
        *ptr=newnode;
        newnode->next=tmp;
        ++dim;
        return newnode->elemento.first;
      }
      else{
        ptr=&((*ptr)->next);
      }
    }
    Node* newnode=new Node;
    newnode->elemento.second=col;
    Node* tmp=*ptr;
    *ptr=newnode;
    if(*ptr!=nullptr){
      newnode->next=tmp;
    }
    for(ulong i=row+2;i<nrow+1;i++){
      if(rowsvector[i]==rowsvector[row+1]){
        rowsvector[i]=&newnode->next;
      }
    }
    rowsvector[row+1]=&newnode->next;
    ++dim;
    return newnode->elemento.first;

  }
  else{
    throw std::out_of_range("out_of_range: you can't access at the desired memory location");
  }
}



//Operator () function (const)
template <typename Data>
Data const& MatrixCSR<Data>::operator()(unsigned long row,unsigned long col)const{
   if((row<nrow) && (col<ncol)){
     Node** ptr=rowsvector[row];
     bool trovato=false;
     while(ptr!=rowsvector[row+1] && (*ptr)->elemento.second<=col){

       if((*ptr)->elemento.second==col){
         return (*ptr)->elemento.first;
       }
       ptr=&((*ptr)->next);
     }
     if(trovato==false){
       throw std::length_error("the desired element is not present into the matrix");
     }
   }
   else{
     throw std::out_of_range("out_of_range: you can't access at the desired memory location");
   }
  throw std::out_of_range("out_of_range: you can't access at the desired memory location");
}


//MapPreOrder function
template<typename Data>
void MatrixCSR<Data>::MapPreOrder(MapFunctor fun,void* par){
  List<std::pair<Data,unsigned long>>::MapPreOrder(
    [&fun](std::pair<Data,unsigned long>& datx, void* parx) {  fun(datx.first,parx); }
  ,par);
}

//MapPostOrder function
template<typename Data>
void MatrixCSR<Data>::MapPostOrder(MapFunctor fun,void* par){
  List<std::pair<Data,unsigned long>>::MapPostOrder(
    [&fun](std::pair<Data,unsigned long>& datx, void* parx) {  fun(datx.first,parx); }
  ,par);
}

//FoldPreOrder function
template<typename Data>
void MatrixCSR<Data>::FoldPreOrder(FoldFunctor fun,const void* par,void* acc)const{
  List<std::pair<Data,unsigned long>>::FoldPreOrder(
    [&fun](const std::pair<Data,unsigned long>& datx, const void* parx,void* accx) {  fun(datx.first,parx,accx); }
  ,par,acc);
}

//FoldPostOrder function
template<typename Data>
void MatrixCSR<Data>::FoldPostOrder(FoldFunctor fun,const void* par,void* acc)const{
  List<std::pair<Data,unsigned long>>::FoldPostOrder(
    [&fun](const std::pair<Data,unsigned long>& datx, const void* parx,void* accx) {  fun(datx.first,parx,accx); }
  ,par,acc);
}
/* ************************************************************************** */

}
