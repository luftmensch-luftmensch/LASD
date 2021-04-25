
#ifndef QUEUEVEC_HPP
#define QUEUEVEC_HPP

/* ************************************************************************** */

#include "../queue.hpp"
#include "../../vector/vector.hpp"

/* ************************************************************************** */

namespace lasd {

template <typename Data>
class QueueVec: public virtual Queue<Data>, protected virtual Vector<Data> { // Must extend Queue<Data> and Vector<Data>

private:

  // ...

protected:

  using Vector<Data>::elem;
  using Container::dimensione;
  ulong testa = 0, coda = 0;


public:

  QueueVec(); // Costruttore di default

  /* ************************************************************************ */

  // Costruttore specifico
  QueueVec(const LinearContainer<Data>& ); // A queue obtained from a LinearContainer

  /* ************************************************************************ */

  QueueVec(const QueueVec&);     // Costruttore di copia

  QueueVec(QueueVec&&) noexcept; // Costruttore di spostamento


  // Destructor
  ~QueueVec() noexcept = default; // Distruttore


  QueueVec& operator=(const QueueVec&); // Assegnamento (copia)

  QueueVec& operator=(QueueVec&&) noexcept; // Assegnamento (spostamento)

  /* ************************************************************************ */

  // Operatori di confronto
  bool operator==(const QueueVec&) const noexcept;
  bool operator!=(const QueueVec&) const noexcept;

  /* ************************************************************************ */

  // Specific member functions (inherited from Queue)

  void Enqueue(const Data&) override;    // Override Queue member
  void Enqueue(Data&&) override;        // Override Queue member 
  Data& Head() const override;         // Override Queue member
  void Dequeue() override;            // Override Queue member
  Data HeadNDequeue() override;      // Override Queue member

  /* ************************************************************************ */

  // Specific member functions (inherited from Container)

  bool Empty() const noexcept override;  // Override Container member
  ulong Size() const noexcept override; // Override Container member
  void Clear() noexcept override;      // Override Container member


protected:

  void Expand();
  void Reduce();

};
}

#include "queuevec.cpp"

#endif
