#ifndef MATRIX_HPP
#define MATRIX_HPP

#include "../container/container.hpp"

namespace lasd {

template <typename Data>
class Matrix: virtual public MappableContainer<Data>, virtual public FoldableContainer<Data>{

private:

protected:

  uint nRighe;
  uint nColonne;

public:

      virtual ~Matrix()=default;

     Matrix& operator=(const Matrix&)= delete;

     Matrix& operator=(Matrix&&) noexcept=delete;

     bool operator==(const Matrix&) noexcept=delete;
     bool operator!=(const Matrix&) noexcept=delete;
 
     uint RowNumber() const noexcept;
     uint ColumnNumber() const noexcept;

     virtual void RowResize(ulong newNRighe) =0;
     virtual void ColumnResize(ulong newNColonne)=0;

     virtual bool ExistsCell(ulong riga, ulong colonna) const noexcept=0;

     virtual Data& operator()(ulong riga, ulong colonna) =0;
     virtual const Data& operator()(ulong riga, ulong colonna) const=0;

};

}

#include "matrix.cpp"

#endif
