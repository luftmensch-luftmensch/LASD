
#ifndef ITERATOR_HPP
#define ITERATOR_HPP

/* ************************************************************************** */

namespace lasd {

/* ************************************************************************** */

template <typename Data>
class Iterator {

private:

protected:

  // ...

public:

  // Destructor
  virtual ~Iterator() noexcept = default;

  /* ************************************************************************ */

  // Copy assignment
  virtual Iterator& operator=(const Iterator&) = delete; // Copy assignment of abstract types should not be possible.

  // Move assignment
  virtual Iterator& operator=(Iterator&&) noexcept = delete; // Move assignment of abstract types should not be possible.

  /* ************************************************************************ */

  // Comparison operators
  virtual bool operator==(const Iterator&) noexcept = delete; // Comparison of abstract types might not be possible.
  virtual bool operator!=(const Iterator&) noexcept = delete; // Comparison of abstract types might not be possible.

  /* ************************************************************************ */

  // Specific member functions
                                      //Access operator
   virtual Data& operator*() const = 0;           // (concrete function must throw std::out_of_range when terminated)
                                      //Termination test: if the iterator reaches the end of the current structure
   virtual bool Terminated() const noexcept= 0; // (concrete function should not throw exceptions)

};

/* ************************************************************************** */

template <typename Data>
class ForwardIterator : virtual public Iterator<Data>{ // Must extend Iterator

private:

protected:

public:

  // Destructor
     virtual ~ForwardIterator() = default;



  // Copy assignment
     virtual ForwardIterator& operator=(const ForwardIterator&) = delete; // Copy assignment of abstract types should not be possible.

  // Move assignment
     virtual ForwardIterator& operator=(ForwardIterator&&) = delete; // Move assignment of abstract types should not be possible.



  // Comparison operators
     virtual bool operator==(const ForwardIterator&) noexcept = delete; // Comparison of abstract types might not be possible.
     virtual bool operator!=(const ForwardIterator&) noexcept = delete; // Comparison of abstract types might not be possible.



  // Specific member functions
                                        //pre increment operator ++
     virtual ForwardIterator& operator++() =0; // (concrete function must throw std::out_of_range when terminated)

};

/* ************************************************************************** */

/*template <typename Data>
class BackwardIterator: virtual public Iterator<Data> { // Must extend Iterator

private:

protected:

public:

  // Destructor
  virtual ~BackwardIterator() = default;



  // Copy assignment
     virtual BackwardIterator& operator=(const BackwardIterator&) = delete; // Copy assignment of abstract types should not be possible.

  // Move assignment
     virtual BackwardIterator& operator=(BackwardIterator&&) = delete; // Move assignment of abstract types should not be possible.



  // Comparison operators
     virtual bool operator==(const BackwardIterator&) noexcept = delete; // Comparison of abstract types might not be possible.
     virtual bool operator!=(const BackwardIterator&) noexcept = delete; // Comparison of abstract types might not be possible.


  // Specific member functions
                                        //pre decrement operator ++
     virtual BackwardIterator& operator--()=0; // (concrete function must throw std::out_of_range when terminated)
};*/

/* ************************************************************************** */

/*template <typename Data>
class BidirectionalIterator: virtual public ForwardIterator<Data>, virtual public BackwardIterator<Data> { // Must extend ForwardIterator and BackwardIterator

private:

protected:

public:

  // Destructor
     virtual ~BidirectionalIterator() = default;


  // Copy assignment
     virtual BidirectionalIterator& operator=(const BidirectionalIterator&) = delete; // Copy assignment of abstract types should not be possible.

  // Move assignment
     virtual BidirectionalIterator& operator=(BidirectionalIterator&&) = delete; // Move assignment of abstract types should not be possible.


  // Comparison operators
     virtual bool operator==(const BidirectionalIterator&) noexcept = delete; // Comparison of abstract types might not be possible.
     virtual bool operator!=(const BidirectionalIterator&) noexcept = delete; // Comparison of abstract types might not be possible.



  // Specific member functions

     virtual bool Terminated() override =0; // Override Iterator member

     virtual bool ForwardTerminated()=0; // (concrete function should not throw exceptions)

     virtual bool BackwardTerminated()=0; // (concrete function should not throw exceptions)

};*/

/* ************************************************************************** */

}

#endif
