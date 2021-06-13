namespace lasd {

template<typename Data>
 unsigned int Matrix<Data>::RowNumber() const noexcept{
   return nRighe;
 }

template<typename Data>
 unsigned int Matrix<Data>::ColumnNumber() const noexcept{
   return nColonne;
 }
}
