
#ifndef MATRIXVEC_HPP
#define MATRIXVEC_HPP

/* ************************************************************************** */

#include "../matrix.hpp"

#include "../../vector/vector.hpp"

/* ************************************************************************** */

namespace lasd {

/* ************************************************************************** */

template <typename Data>
class MatrixVec : virtual public Matrix<Data>,virtual protected Vector<Data>{ // Must extend Matrix<Data>

private:

protected:


  using Matrix<Data>::nrow;
  using Matrix<Data>::ncol;
  using Vector<Data>::dim;
  using Vector<Data>::elem;

public:

     // Default constructor: costruisce una matrice di 0 righe e 0 colonne (vuota)
     MatrixVec();

  /* ************************************************************************ */

     // Specific constructors: costruisce una matrice vuota se.. riga x colonna altrimenti
     MatrixVec(unsigned int,unsigned int); // A matrix of some specified dimension

  /* ************************************************************************ */

     // Copy constructor
     MatrixVec(const MatrixVec<Data>&);

     // Move constructor
     MatrixVec(MatrixVec<Data>&&) noexcept;

  /* ************************************************************************ */
     // Destructor
     ~MatrixVec();

  /* ************************************************************************ */
     // Copy assignment
     MatrixVec<Data>& operator=(const MatrixVec<Data>&);

     // Move assignment
     MatrixVec<Data>& operator=(MatrixVec<Data>&&)noexcept;

  /* ************************************************************************ */
  // Comparison operators
     bool operator==(const MatrixVec<Data>&) const noexcept;
     bool operator!=(const MatrixVec<Data>&) const noexcept;

  /* ************************************************************************ */

  // Specific member functions (inherited from Matrix)

     using Matrix<Data>::RowNumber;
     using Matrix<Data>::ColumnNumber;

     void RowResize(unsigned long newnrow) override; // Override Matrix member
     void ColumnResize(unsigned long newncol) override; // Override Matrix member

     virtual bool ExistsCell(unsigned long row, unsigned long column) const noexcept; // Override Matrix member (should not throw exceptions)

     Data& operator()(unsigned long row,unsigned long col); // Override Matrix member (mutable access to the element; throw out_of_range when out of range)
     Data const& operator()(const unsigned long row,const unsigned long col) const; // Override Matrix member (immutable access to the element; throw out_of_range when out of range and length_error when not present)

  /* ************************************************************************ */

  // Specific member functions (inherited from Container)
     virtual void Clear() override; // Override Container member

  /* ************************************************************************ */

  // Specific member functions (inherited from MappableContainer)
     using Vector<Data>::MapPreOrder;
     using Vector<Data>::MapPostOrder;

  /* ************************************************************************ */

  // Specific member functions (inherited from FoldableContainer)

     using Vector<Data>::FoldPreOrder;
     using Vector<Data>::FoldPostOrder;

};

/* ************************************************************************** */

}

#include "matrixvec.cpp"

#endif
