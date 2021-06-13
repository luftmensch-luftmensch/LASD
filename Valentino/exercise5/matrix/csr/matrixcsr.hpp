
#ifndef MATRIXCSR_HPP
#define MATRIXCSR_HPP

/* ************************************************************************** */

#include "../matrix.hpp"

#include "../../list/list.hpp"  //per la lista di colonne e dati
#include "../../vector/vector.hpp" //per il vettore delle righe

/* ************************************************************************** */

namespace lasd {

/* ************************************************************************** */

template <typename Data>
class MatrixCSR: virtual public Matrix<Data>, virtual protected List<std::pair<Data,unsigned long>> { // Must extend Matrix<Data>

private:

  // ...

protected:

   using Matrix<Data>::nrow;
   using Matrix<Data>::ncol;
   using List<std::pair<Data,unsigned long>>::dim;

   using typename List<std::pair<Data,ulong>>::Node;


   Vector<Node**> rowsvector;


   using List<std::pair<Data,ulong>>::First;
   using List<std::pair<Data,ulong>>::Last;



public:

  // Default constructor: matrice sparsa vuota di dim 0x0
     MatrixCSR();

  /* ************************************************************************ */

  // Specific constructors: costruisce una mtrice di una certa dimensione anche senza dati
     MatrixCSR(unsigned long rows, unsigned long columns); // A matrix of some specified dimension

  /* ************************************************************************ */

  // Copy constructor: attenzione perchè quando si va a fare la copia, si deve scorrere la vecchia matrice e si fa una nuova matrice per inserimento
     MatrixCSR(const MatrixCSR<Data>&);

  // Move constructor: swap di puntatori
     MatrixCSR(MatrixCSR<Data>&&)noexcept;

  /* ************************************************************************ */

  // Destructor
     //~MatrixCSR()=default;
     ~MatrixCSR();

  /* ************************************************************************ */

  // Copy assignment: costruire un nuovo oggetto, fare la copia
     MatrixCSR<Data>& operator=(const MatrixCSR<Data>&);

  // Move assignment: swap
     MatrixCSR<Data>& operator=(MatrixCSR<Data>&&) noexcept;

  /* ************************************************************************ */

  // Comparison operators: non bisogna confrontare il vettore delle righe ma solo i dati, quindi man mano che scorro le righe verifico che i dati siano gli stesi
     bool  operator==(const MatrixCSR<Data>&) const noexcept;
     bool  operator!=(const MatrixCSR<Data>&) const noexcept;

  /* ************************************************************************ */

  // Specific member functions (inherited from Matrix)

     void RowResize(unsigned long r)override; // Override Matrix member
     //IN ESTENSIONE NULLA,
     void ColumnResize(unsigned long c)override; // Override Matrix member

     bool ExistsCell(unsigned long row,unsigned long column) const noexcept override; // Override Matrix member (should not throw exceptions)

     Data& operator()(unsigned long row,unsigned long col) override;// Override Matrix member (mutable access to the element; throw out_of_range when out of range)
  //USARE UNA FUNZIONE PROTETTA PER L'INSERIMENTO UNA VOLTA TROVATO IL PUNTO GIUSTO DOVE INSERIRE
     Data const& operator()(unsigned long row,unsigned long col) const override; // Override Matrix member (immutable access to the element; throw out_of_range when out of range and length_error when not present)

  /* ************************************************************************ */

  // Specific member functions (inherited from Container)

     void Clear(); // Override Container member

  /* ************************************************************************ */
   //nel caso di liste di pair, bisogna trasformare la fun in una nuova funzione che fa le stesse cose ma solo sul primo argomento della coppia e se ne frega del secondo argomento
   //il costrutto è quello di lambda astraction

  // Specific member functions (inherited from MappableContainer)

     using typename MappableContainer<Data>::MapFunctor;
     void MapPreOrder(MapFunctor fun, void* par)override; // Override MappableContainer member
     void MapPostOrder(MapFunctor fun, void* par)override; // Override MappableContainer member

  /* ************************************************************************ */

  // Specific member functions (inherited from FoldableContainer)

     using typename FoldableContainer<Data>::FoldFunctor;
     void FoldPreOrder(FoldFunctor fun, const void* par, void* acc)const override; // Override FoldableContainer member
     void FoldPostOrder(FoldFunctor fun, const void* par, void* acc)const override; // Override FoldableContainer member

};


/* ************************************************************************** */

}

#include "matrixcsr.cpp"

#endif
