
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
  virtual Data& operator[](const unsigned long) const = 0;

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
  virtual ~FoldableContainer() = default;

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
class InOrderMappableContainer: virtual public MappableContainer<Data> { // Must extend MappableContainer

private:

protected:

public:

  // Destructor
     virtual ~InOrderMappableContainer() noexcept= default;

  /* ************************************************************************ */

  // Copy assignment
     InOrderMappableContainer& operator=(const InOrderMappableContainer&)= delete; // Copy assignment of abstract types should not be possible.

  // Move assignment
     InOrderMappableContainer& operator=(InOrderMappableContainer&&)= delete; // Move assignment of abstract types should not be possible.

  /* ************************************************************************ */

  // Comparison operators
     bool operator==(const InOrderMappableContainer&) const noexcept = delete; // Comparison of abstract types might not be possible.
     bool operator!=(const InOrderMappableContainer&) const noexcept = delete;// Comparison of abstract types might not be possible.

  /* ************************************************************************ */

  // Specific member functions

     using typename MappableContainer<Data>::MapFunctor;

     virtual void MapInOrder(MapFunctor, void*) noexcept = 0;

};

/* ************************************************************************** */

template <typename Data>
class InOrderFoldableContainer: virtual public FoldableContainer<Data>{ // Must extend FoldableContainer

private:

protected:

public:

  // Destructor
     virtual ~InOrderFoldableContainer() noexcept=default;

  /* ************************************************************************ */

  // Copy assignment
     InOrderFoldableContainer& operator=(const InOrderFoldableContainer&)= delete; // Copy assignment of abstract types should not be possible.

  // Move assignment
     InOrderFoldableContainer& operator=(InOrderFoldableContainer&&)= delete; // Move assignment of abstract types should not be possible.

  /* ************************************************************************ */

  // Comparison operators
     bool operator==(const InOrderFoldableContainer&) const noexcept = delete; // Comparison of abstract types might not be possible.
     bool operator!=(const InOrderFoldableContainer&) const noexcept = delete; // Comparison of abstract types might not be possible.

  /* ************************************************************************ */

  // Specific member functions

     using typename FoldableContainer<Data>::FoldFunctor;

     virtual void FoldInOrder(FoldFunctor, const void*, void*) const noexcept =0;

};
/* ************************************************************************ */

template <typename Data>
class BreadthMappableContainer: virtual public MappableContainer<Data> { // Must extend MappableContainer

private:

protected:

public:

  // Destructor
  virtual ~BreadthMappableContainer() noexcept = default;

  /* ************************************************************************ */

  // Copy assignment
  virtual BreadthMappableContainer& operator=(const BreadthMappableContainer&) = delete; // Copy assignment of abstract types should not be possible.

  // Move assignment
  virtual BreadthMappableContainer& operator=(BreadthMappableContainer&&) noexcept = delete; // Move assignment of abstract types should not be possible.

  /* ************************************************************************ */

  // Comparison operators
  virtual bool operator==(const BreadthMappableContainer&) const noexcept = delete; // Comparison of abstract types might not be possible.
  virtual bool operator!=(const BreadthMappableContainer&) const noexcept = delete; // Comparison of abstract types might not be possible.

  /* ************************************************************************ */

  // Specific member functions

  using typename MappableContainer<Data>::MapFunctor;

  virtual void MapBreadth(MapFunctor, void*) noexcept = 0;


};

/* ************************************************************************** */

template <typename Data>
class BreadthFoldableContainer : virtual public FoldableContainer<Data> { // Must extend FoldableContainer

private:

protected:

public:

  // Destructor
  virtual ~BreadthFoldableContainer() noexcept =default;

  /* ************************************************************************ */

  // Copy assignment
  virtual BreadthFoldableContainer& operator=(const BreadthFoldableContainer&) = delete; // Copy assignment of abstract types should not be possible.

  // Move assignment
  virtual BreadthFoldableContainer& operator=(BreadthFoldableContainer&&) noexcept =delete; // Move assignment of abstract types should not be possible.

  /* ************************************************************************ */

  // Comparison operators
  virtual bool operator==(const BreadthFoldableContainer&) noexcept = delete; // Comparison of abstract types might not be possible.
  virtual bool operator!=(const BreadthFoldableContainer&) noexcept = delete; // Comparison of abstract types might not be possible.

  /* ************************************************************************ */

  // Specific member functions

   using typename FoldableContainer<Data>::FoldFunctor;

   virtual void FoldBreadth(FoldFunctor, const void*, void*) const noexcept = 0;

};
/* ************************************************************************** */

}

#include "container.cpp"

#endif
