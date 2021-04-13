
#ifndef QUEUELST_HPP
#define QUEUELST_HPP

/* ************************************************************************** */

#include "../queue.hpp"
#include "../../list/list.hpp"

/* ************************************************************************** */

namespace lasd {

/* ************************************************************************** */

template <typename Data>
class QueueLst { // Must extend Queue<Data> and List<Data>

private:

  // ...

protected:

  // using List<Data>::???;

  // ...

public:

  // Default constructor
  // QueueLst() specifier;

  /* ************************************************************************ */

  // Specific constructor
  // QueueLst(argument) specifiers; // A queue obtained from a LinearContainer

  /* ************************************************************************ */

  // Copy constructor
  // QueueLst(argument);

  // Move constructor
  // QueueLst(argument);

  /* ************************************************************************ */

  // Destructor
  // ~QueueLst() specifier;

  /* ************************************************************************ */

  // Copy assignment
  // type operator=(argument);

  // Move assignment
  // type operator=(argument);

  /* ************************************************************************ */

  // Comparison operators
  // type operator==(argument) specifiers;
  // type operator!=(argument) specifiers;

  /* ************************************************************************ */

  // Specific member functions (inherited from Queue)

  // type Enqueue(argument) specifiers; // Override Queue member (copy of the value)
  // type Enqueue(argument) specifiers; // Override Queue member (move of the value)
  // type Head() specifiers; // Override Queue member (must throw std::length_error when empty)
  // type Dequeue() specifiers; // Override Queue member (must throw std::length_error when empty)
  // type HeadNDequeue() specifiers; // Override Queue member (must throw std::length_error when empty)

  /* ************************************************************************ */

  // Specific member functions (inherited from Container)

  // type Clear() specifiers; // Override Container member

};

/* ************************************************************************** */

}

#include "queuelst.cpp"

#endif
