
#ifndef QUEUELST_HPP
#define QUEUELST_HPP

/* ************************************************************************** */

#include "../queue.hpp"
#include "../../list/list.hpp"

/* ************************************************************************** */

namespace lasd {

/* ************************************************************************** */

template <typename Data>
class QueueLst : public virtual Queue<Data>, protected virtual List<Data>{ // Must extend Queue<Data> and List<Data>

private:

protected:

  using Container::dimensione;

public:

  QueueLst(); // Costruttore di default

  QueueLst(const LinearContainer<Data>& ); // Costruttore specifico


  QueueLst(const QueueLst&); // Costruttore di copia

  QueueLst(QueueLst&&) noexcept; // Costruttore di spostamento


  ~QueueLst() noexcept = default; // Distruttore

  QueueLst& operator=(const QueueLst&); // Assegnamento (copia)

  QueueLst& operator=(QueueLst&&) noexcept; // Assegnamento (spostamento)

  // Operatori di confronto
  bool operator==(const QueueLst&) const noexcept;
  bool operator!=(const QueueLst&) const noexcept;

  // Specific member functions (inherited from Queue)

  void Enqueue(const Data&) override;       // Override Queue member
  void Enqueue(Data&&) override;           // Override Queue member
  Data& Head() const override;            // Override Queue member
  void Dequeue() override;               // Override Queue member
  Data HeadNDequeue() override;         // Override Queue member

  /* ************************************************************************ */

  // Specific member functions (inherited from Container)

  using List<Data>::Empty;

  using List<Data>::Size;

  using List<Data>::Clear;

};

}

#include "queuelst.cpp"

#endif
