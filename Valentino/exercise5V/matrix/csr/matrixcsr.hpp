#ifndef MATRIXCSR_HPP
#define MATRIXCSR_HPP

#include "../matrix.hpp"
#include "../../list/list.hpp"
#include "../../vector/vector.hpp"

namespace lasd {

template <typename Data>
class MatrixCSR: virtual public Matrix<Data>, virtual protected List<std::pair<Data,unsigned long>> {

private:

protected:

   using Matrix<Data>::nRighe;
   using Matrix<Data>::nColonne;
   using List<std::pair<Data,unsigned long>>::dimensione;

   using typename List<std::pair<Data,ulong>>::Node;
   using List<std::pair<Data,ulong>>::First;
   using List<std::pair<Data,ulong>>::Last;

   Vector<Node**> vettoreDiRighe;


public:

     using typename MappableContainer<Data>::MapFunctor;
     using typename FoldableContainer<Data>::FoldFunctor;

     MatrixCSR();
     ~MatrixCSR();
     MatrixCSR(ulong rows, ulong columns);

     MatrixCSR(const MatrixCSR<Data>&);
     MatrixCSR(MatrixCSR<Data>&&)noexcept;

     MatrixCSR<Data>& operator=(const MatrixCSR<Data>&);
     MatrixCSR<Data>& operator=(MatrixCSR<Data>&&) noexcept;

     bool  operator==(const MatrixCSR<Data>&) const noexcept;
     bool  operator!=(const MatrixCSR<Data>&) const noexcept;

     void RowResize(ulong newNRighe)override;
     void ColumnResize(ulong newNColonne)override;

     bool ExistsCell(ulong riga, ulong colonna) const noexcept override;

     Data& operator()(ulong riga, ulong colonna) override;
     Data const& operator()(ulong riga, ulong colonna) const override;

     void Clear();


     void MapPreOrder(MapFunctor fun, void* par)override;
     void MapPostOrder(MapFunctor fun, void* par)override;
     void FoldPreOrder(FoldFunctor fun, const void* par, void* acc)const override;
     void FoldPostOrder(FoldFunctor fun, const void* par, void* acc)const override;

};

}

#include "matrixcsr.cpp"
#endif
