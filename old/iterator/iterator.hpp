#ifndef ITERATOR_HPP
#define ITERATOR_HPP

namespace lasd {


template <typename Data>
class Iterator {

private:

protected:

public:

  virtual ~Iterator() noexcept = default;

  virtual Iterator& operator=(const Iterator&) = delete;
  virtual Iterator& operator=(Iterator&&) noexcept = delete;

  virtual bool operator==(const Iterator&) noexcept = delete;
  virtual bool operator!=(const Iterator&) noexcept = delete;

   virtual Data& operator*() const = 0;
   virtual bool Terminated() const noexcept= 0;

};

template <typename Data>
class ForwardIterator : virtual public Iterator<Data>{

private:

protected:

public:

     virtual ~ForwardIterator() = default;

     virtual ForwardIterator& operator=(const ForwardIterator&) = delete;
     virtual ForwardIterator& operator=(ForwardIterator&&) = delete;

     virtual bool operator==(const ForwardIterator&) noexcept = delete;
     virtual bool operator!=(const ForwardIterator&) noexcept = delete;


     virtual ForwardIterator& operator++() =0;

};

}

#endif
