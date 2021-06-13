
#ifndef STACKVEC_HPP
#define STACKVEC_HPP

/* ************************************************************************** */

#include "../stack.hpp"
#include "../../vector/vector.hpp"

/* ************************************************************************** */

namespace lasd {

/* ************************************************************************** */

    template <typename Data>
    class StackVec: virtual public Stack<Data>, virtual protected Vector<Data> { // Must extend Stack<Data> and Vector<Data>

    private:


    protected:

      using Container::dimensione;
      using Vector<Data>::elemento;
      ulong top = 0;


    public:

      StackVec(); // Costruttore di default

      ~StackVec() noexcept = default; // Distruttore

      StackVec(const LinearContainer<Data>&); // Costruttore specifico


      StackVec(const StackVec&); // Costruttore di copia

      StackVec(StackVec&&); // Costruttore di spostamento


      StackVec& operator=(const StackVec&); // Assegnamento (copia)

      StackVec& operator=(StackVec&&) noexcept; // Assegnamento (spostamento)


      // Operatori di confronto
      bool operator==(const StackVec&) const noexcept;
      bool operator!=(const StackVec&) const noexcept;


      // Specific member functions (inherited from Stack)

      virtual void Push(const Data&) override;     // Override Stack member
      virtual void Push(Data&&) override;         // Override Stack member
      virtual Data& Top() const override;        // Override Stack member
      virtual void Pop() override;              // Override Stack member
      virtual Data TopNPop() override;         // Override Stack member


      // Specific member functions (inherited from Container)

      virtual bool Empty() const noexcept override; // Override Container member

      virtual ulong Size() const noexcept override; // Override Container member

      virtual void Clear() noexcept override; // Override Container member

    protected:

      // Auxiliary member functions

      void Expand();
      void Reduce();

    };

}

#include "stackvec.cpp"

#endif
