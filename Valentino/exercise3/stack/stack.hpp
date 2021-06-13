#ifndef STACK_HPP
#define STACK_HPP

/* ************************************************************************** */

#include "../container/container.hpp"

/* ************************************************************************** */

namespace lasd {


  template <typename Data>
  class Stack : virtual public Container{ // Must extend Container

  private:


  protected:

    using Container::dimensione;

  public:

    
    virtual ~Stack() =default; // Distruttore


    // Copy assignment
     Stack& operator=(const Stack&)=delete; // Copy assignment of abstract types should not be possible.

    // Move assignment
    Stack& operator=(Stack&&)=delete; // Move assignment of abstract types should not be possible.


    // Comparison operators
    bool operator==(const Stack&) const noexcept = delete; // Comparison of abstract types might not be possible.
    bool operator!=(const Stack&) const noexcept = delete; // Comparison of abstract types might not be possible.

    /* ************************************************************************ */

    // Specific member functions

    virtual void Push(const Data&) = 0;       // Copia del valore
    virtual void Push(Data&&) = 0;           // Spostamento del valore
    virtual Data& Top() const=0;            // (concrete function must throw std::length_error when empty)
    virtual void Pop() = 0;                // (concrete function must throw std::length_error when empty)
    virtual Data TopNPop()=0;             // (concrete function must throw std::length_error when empty)

};

/* ************************************************************************** */

}

#endif
