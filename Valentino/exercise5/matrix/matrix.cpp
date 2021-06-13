
namespace lasd {

/* ************************************************************************** */
//Specific member functions

//RowNumber function
template<typename Data>
 unsigned int Matrix<Data>::RowNumber() const noexcept{
   return nrow;
 }

//ColumnNumber function
template<typename Data>
 unsigned int Matrix<Data>::ColumnNumber() const noexcept{
   return ncol;
 }

/* ************************************************************************** */

}
