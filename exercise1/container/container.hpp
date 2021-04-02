
#ifndef CONTAINER_HPP
#define CONTAINER_HPP

/* ************************************************************************** */
#include <stdexcept>
#include <functional>

/* ************************************************************************** */

namespace lasd {

/* ************************************************************************** */

class Container {

private:


protected:

  unsigned long dim=0;

public:

                                //Destructor for the class Container
  virtual ~Container()=default;

  /* ************************************************************************ */

  // Copy assignment
  Container& operator=(const Container&) = delete; // Copy assignment of abstract types should not be possible.

  // Move assignment
  Container& operator=(Container&&) noexcept = delete; // Move assignment of abstract types should not be possible.

  /* ************************************************************************ */

  // Comparison operators
  bool operator==(const Container&) const noexcept = delete; // Comparison of abstract types might not be possible.
  bool operator!=(const Container&) const noexcept = delete; // Comparison of abstract types might not be possible.

  /* ************************************************************************ */

  // Specific member functions
                                  //Empty: returns true if Container is empty, false otherwise
                                  //It doesn't throw exceptions
    virtual bool Empty() const noexcept{
      return (dim==0);
    }
                                  //Size: returns the Container's size
                                  //It doesn't throw exceptions
    virtual unsigned long Size() const noexcept{
      return dim;
    }
                                  //Clear: clears the Container
                                  //Pure virtual function, defined later
    virtual void Clear()=0;

};

/* ************************************************************************** */

template <typename Data>
class LinearContainer: virtual public Container {

private:


protected:


public:

  // Destructor
  virtual ~LinearContainer()=default;

  /* ************************************************************************ */

  // Copy assignment
  LinearContainer& operator=(const LinearContainer&) = delete; // Copy assignment of abstract types should not be possible.

  // Move assignment
  LinearContainer& operator=(LinearContainer&&) noexcept = delete; // Move assignment of abstract types should not be possible.

  /* ************************************************************************ */

  // Comparison operators
  bool operator==(const LinearContainer&) const noexcept = delete; // Comparison of abstract types might not be possible.
  bool operator!=(const LinearContainer&) const noexcept = delete; // Comparison of abstract types might not be possible.

  /* ************************************************************************ */

  // Specific member functions
                                    //Front: returns the first element
                                    //throws std::length_error when empty
                                    //pure virtual function, defined later
  virtual Data& Front() const = 0;
                                    //Back(): returns the last element
                                    //throws std::length_error when empty
                                    //pure virtual function, defined later
  virtual Data& Back() const = 0;
                                    //operator[]: returns the i-th element
                                    //throws std::out_of_range when out of out_of_range
                                    //pure virtual function, defined later
  virtual Data& operator[](const unsigned long) = 0;

};

/* ************************************************************************** */

template <typename Data>
class TestableContainer : virtual public Container { 

private:


protected:


public:

  //Destructor for the class TestableContainer
  virtual ~TestableContainer()=default;

  /* ************************************************************************ */

  // Copy assignment
  TestableContainer& operator=(const TestableContainer&) = delete; // Copy assignment of abstract types should not be possible.

  // Move assignment
  TestableContainer& operator=(TestableContainer&&) noexcept = delete; // Move assignment of abstract types should not be possible.

  /* ************************************************************************ */

  // Comparison operators
  bool operator==(const TestableContainer&) const noexcept = delete; // Comparison of abstract types might not be possible.
  bool operator!=(const TestableContainer&) const noexcept = delete; // Comparison of abstract types might not be possible.

  /* ************************************************************************ */

  // Specific member functions
                                                     //Exists(): returns true if the container exists, false otherwise
                                                     //pure virtual function, defined later
  virtual bool Exists(const Data&) const noexcept = 0;

};

/* ************************************************************************** */

template <typename Data>
class MappableContainer: virtual public Container {

private:

protected:

public:

  // Destructor for the class MappableContainer
  virtual ~MappableContainer()=default;

  /* ************************************************************************ */

  // Copy assignment
  MappableContainer& operator=(const MappableContainer&) = delete; // Copy assignment of abstract types should not be possible.

  // Move assignment
  MappableContainer& operator=(MappableContainer&&) noexcept = delete; // Move assignment of abstract types should not be possible.

  /* ************************************************************************ */

  // Comparison operators
  bool operator==(const MappableContainer&) const noexcept=delete; // Comparison of abstract types might not be possible.
  bool operator!=(const MappableContainer&) const noexcept=delete; // Comparison of abstract types might not be possible.

  /* ************************************************************************ */

  // Specific member functions
                                          //Function pointer to the function MapFunctor
                                          //Used for the scan of elements in MapPreOrder and MapPostOrder
                                          //it modifies data
  typedef std::function<void(Data&, void*)> MapFunctor;
                                          //MapPreOrder: returns the elements of the container from the first to the last element
                                          //pure virtual function, defined later
  virtual void MapPreOrder(MapFunctor, void*)=0;
                                          //MapPostOrder: returns the elements of the container from the last to the first element
                                          //pure virtual function, defined later
  virtual void MapPostOrder(MapFunctor, void*)=0;

};

/* ************************************************************************** */

template <typename Data>
class FoldableContainer : virtual public TestableContainer<Data> {

private:

protected:

public:

  // Destructor for the class FoldableContainer
  virtual  ~FoldableContainer() = default;

  /* ************************************************************************ */

  // Copy assignment
  FoldableContainer& operator=(const FoldableContainer&) = delete; // Copy assignment of abstract types should not be possible.

  // Move assignment
  FoldableContainer& operator=(FoldableContainer&&) noexcept = delete; // Move assignment of abstract types should not be possible.

  /* ************************************************************************ */

  // Comparison operators
  bool operator==(const FoldableContainer&) const noexcept = delete; // Comparison of abstract types might not be possible.
  bool operator!=(const FoldableContainer&) const noexcept = delete; // Comparison of abstract types might not be possible.

  /* ************************************************************************ */

  // Specific member functions
                                         //Function pointer to the function FoldFunctor
                                         //Used for the scan of elements in FoldPreOrder and FoldPostOrder
                                         //it doesn't modify data, it uses an accumulator
  typedef std::function<void(const Data&, const void*, void*) noexcept> FoldFunctor;

  virtual void FoldPreOrder(const FoldFunctor, const void*, void*) const = 0;
  virtual void FoldPostOrder(const FoldFunctor, const void*, void*) const = 0;

  virtual bool Exists(const Data&) const noexcept override; // Override TestableContainer member

};

/* ************************************************************************** */

template <typename Data>
class BreadthMappableContainer { // Must extend MappableContainer

private:

  // ...

protected:

  // ...

public:

  // Destructor
  // ~BreadthMappableContainer() specifiers

  /* ************************************************************************ */

  // Copy assignment
  // type operator=(argument); // Copy assignment of abstract types should not be possible.

  // Move assignment
  // type operator=(argument); // Move assignment of abstract types should not be possible.

  /* ************************************************************************ */

  // Comparison operators
  // type operator==(argument) specifiers; // Comparison of abstract types might not be possible.
  // type operator!=(argument) specifiers; // Comparison of abstract types might not be possible.

  /* ************************************************************************ */

  // Specific member functions

  // using typename MappableContainer<Data>::MapFunctor;

  // type MapBreadth(arguments) specifiers;

};

/* ************************************************************************** */

template <typename Data>
class BreadthFoldableContainer { // Must extend FoldableContainer

private:

  // ...

protected:

  // ...

public:

  // Destructor
  // ~BreadthFoldableContainer() specifiers

  /* ************************************************************************ */

  // Copy assignment
  // type operator=(argument); // Copy assignment of abstract types should not be possible.

  // Move assignment
  // type operator=(argument); // Move assignment of abstract types should not be possible.

  /* ************************************************************************ */

  // Comparison operators
  // type operator==(argument) specifiers; // Comparison of abstract types might not be possible.
  // type operator!=(argument) specifiers; // Comparison of abstract types might not be possible.

  /* ************************************************************************ */

  // Specific member functions

  // using typename FoldableContainer<Data>::FoldFunctor;

  // type FoldBreadth(arguments) specifiers;

};

/* ************************************************************************** */

}

#include "container.cpp"

#endif
