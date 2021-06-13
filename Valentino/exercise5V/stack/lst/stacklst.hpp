
#ifndef STACKLST_HPP
#define STACKLST_HPP

/* ************************************************************************** */

#include "../stack.hpp"
#include "../../list/list.hpp"

/* ************************************************************************** */

namespace lasd {

/* ************************************************************************** */

  template <typename Data>
  class StackLst : virtual public Stack<Data>, virtual protected List<Data> { // Must extend Stack<Data> and List<Data>

  private:


  protected:


    using List<Data>::dimensione;

  public:

    StackLst(); // Costruttore di default
    ~StackLst()=default; // Distruttore


    // Specific constructor
    StackLst(const LinearContainer<Data>&); // A stack obtained from a LinearContainer

    StackLst(const StackLst&); // Costruttore di copia

    StackLst(StackLst&&) noexcept; // Costruttore di spostamento

    StackLst& operator=(const StackLst&); // Assegnamento (copia)

    StackLst& operator=(StackLst&&) noexcept; // Assegnamento (spostamento)


    // Operatori di confronto
    bool operator==(const StackLst&) const noexcept;
    bool operator!=(const StackLst&) const noexcept;

    /* ************************************************************************ */

    // Specific member functions (inherited from Stack)

    void Push(Data &&) override;      // Override Stack member
    void Push(const Data &) override; // Override Stack member
    Data& Top() const override;       // Override Stack member
    void Pop() override;              // Override Stack member
    Data TopNPop() override;          // Override Stack member


    // Specific member functions (inherited from Container)
    using List<Data>::Empty;

    using List<Data>::Size;

    using List<Data>::Clear;

};


}

#include "stacklst.cpp"

#endif
