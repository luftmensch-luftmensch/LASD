#ifndef MATRIXVEC_HPP
#define MATRIXVEC_HPP

#include "../matrix.hpp"
#include "../../vector/vector.hpp"

namespace lasd {

template <typename Data>
class MatrixVec : virtual public Matrix<Data>,virtual protected Vector<Data>{

private:

protected:

  using Matrix<Data>::nRighe;
  using Matrix<Data>::nColonne;
  using Vector<Data>::dimensione;
  using Vector<Data>::elemento;

public:

   using Matrix<Data>::RowNumber;
   using Matrix<Data>::ColumnNumber;

   using Vector<Data>::MapPreOrder;
   using Vector<Data>::MapPostOrder;

   using Vector<Data>::FoldPreOrder;
   using Vector<Data>::FoldPostOrder;

   MatrixVec();
   ~MatrixVec();

   MatrixVec(uint,uint);

   MatrixVec(const MatrixVec<Data>&);
   MatrixVec(MatrixVec<Data>&&) noexcept;


   MatrixVec<Data>& operator=(const MatrixVec<Data>&);
   MatrixVec<Data>& operator=(MatrixVec<Data>&&)noexcept;

   bool operator==(const MatrixVec<Data>&) const noexcept;
   bool operator!=(const MatrixVec<Data>&) const noexcept;


   void RowResize(ulong newNRighe) override;
   void ColumnResize(ulong newNColonne) override;
   virtual void Clear() override;

   virtual bool ExistsCell(ulong riga, ulong colonna) const noexcept;

   Data& operator()(ulong riga,ulong colonna);
   Data const& operator()(const ulong riga, const ulong colonna) const;

};
}

#include "matrixvec.cpp"
#endif
