
#ifndef MATRIX_HPP
#define MATRIX_HPP

/* ************************************************************************** */

#include "../container/container.hpp"

/* ************************************************************************** */

namespace lasd {

/* ************************************************************************** */

template <typename Data>
class Matrix: virtual public MappableContainer<Data>, virtual public FoldableContainer<Data>{ // Must extend MappableContainer<Data> and FoldableContainer<Data>

private:

protected:

  unsigned int nrow;
  unsigned int ncol;

public:

     // Destructor
      virtual ~Matrix()=default;

  /* ************************************************************************ */

     // Copy assignment
     Matrix& operator=(const Matrix&)= delete; // Copy assignment of abstract types should not be possible.

     // Move assignment
     Matrix& operator=(Matrix&&) noexcept=delete; // Move assignment of abstract types should not be possible.

  /* ************************************************************************ */

     // Comparison operators
     bool operator==(const Matrix&) noexcept=delete; // Comparison of abstract types might not be possible.
     bool operator!=(const Matrix&) noexcept=delete; // Comparison of abstract types might not be possible.

  /* ************************************************************************ */

  // Specific member functions

     unsigned int RowNumber() const noexcept; // (concrete function should not throw exceptions)
     unsigned int ColumnNumber() const noexcept; // (concrete function should not throw exceptions)

     virtual void RowResize(unsigned long newnrow) =0;
     virtual void ColumnResize(unsigned long newncol)=0;

     virtual bool ExistsCell(unsigned long row, unsigned long column) const noexcept=0; // (concrete function should not throw exceptions) //se la cella è rappresentata in memoria (non se nella cella c'è un valore di default, può anche contenerlo)

     virtual Data& operator()(unsigned long row, unsigned long column) =0; // Mutable access to the element (concrete function should throw exceptions only when out of range when data could't be found or insert into the matrix)
     virtual const Data& operator()(unsigned long row, unsigned long column) const=0; // Immutable access to the element (concrete function should throw exceptions when not present)

};

/* ************************************************************************** */

}

#include "matrix.cpp"

#endif
