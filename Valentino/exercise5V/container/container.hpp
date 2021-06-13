
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

  ulong dimensione=0;

public:

  virtual ~Container()=default;

  /* ************************************************************************ */

  Container& operator=(const Container&) = delete;

  Container& operator=(Container&&) noexcept = delete;

  /* ************************************************************************ */

  bool operator==(const Container&) const noexcept = delete;
  bool operator!=(const Container&) const noexcept = delete;

  /* ************************************************************************ */

    virtual bool Empty() const noexcept{
      return (dimensione==0);
    }
    virtual ulong Size() const noexcept { return dimensione; }
    virtual void Clear()=0;

};

/* ************************************************************************** */

template <typename Data>
class LinearContainer: virtual public Container {

private:


protected:


public:

  virtual ~LinearContainer()=default;

  /* ************************************************************************ */

  LinearContainer& operator=(const LinearContainer&) = delete;

  LinearContainer& operator=(LinearContainer&&) noexcept = delete;

  /* ************************************************************************ */

  bool operator==(const LinearContainer&) const noexcept = delete;
  bool operator!=(const LinearContainer&) const noexcept = delete;

  /* ************************************************************************ */

  virtual Data& Front() const = 0;
  virtual Data& Back() const = 0;
  virtual Data& operator[](const ulong) const = 0;

};

/* ************************************************************************** */

template <typename Data>
class TestableContainer : virtual public Container {

private:


protected:


public:

  virtual ~TestableContainer()=default;

  /* ************************************************************************ */

  TestableContainer& operator=(const TestableContainer&) = delete;

  TestableContainer& operator=(TestableContainer&&) noexcept = delete;

  /* ************************************************************************ */

  bool operator==(const TestableContainer&) const noexcept = delete;
  bool operator!=(const TestableContainer&) const noexcept = delete;

  /* ************************************************************************ */

  virtual bool Exists(const Data &) const noexcept = 0;
};

/* ************************************************************************** */

template <typename Data>
class MappableContainer: virtual public Container {

private:

protected:

public:

  virtual ~MappableContainer()=default;

  /* ************************************************************************ */

  MappableContainer& operator=(const MappableContainer&) = delete;

  MappableContainer& operator=(MappableContainer&&) noexcept = delete;

  /* ************************************************************************ */

  bool operator==(const MappableContainer&) const noexcept=delete;
  bool operator!=(const MappableContainer&) const noexcept=delete;

  /* ************************************************************************ */

  typedef std::function<void(Data&, void*)> MapFunctor;
  virtual void MapPreOrder(MapFunctor, void*)=0;
  virtual void MapPostOrder(MapFunctor, void*)=0;

};

/* ************************************************************************** */

template <typename Data>
class FoldableContainer : virtual public TestableContainer<Data> {

private:

protected:

public:

  virtual  ~FoldableContainer() = default;

  /* ************************************************************************ */

  FoldableContainer& operator=(const FoldableContainer&) = delete;

  FoldableContainer& operator=(FoldableContainer&&) noexcept = delete;

  /* ************************************************************************ */

  bool operator==(const FoldableContainer&) const noexcept = delete;
  bool operator!=(const FoldableContainer&) const noexcept = delete;

  /* ************************************************************************ */

  typedef std::function<void(const Data&, const void*, void*) noexcept> FoldFunctor;

  virtual void FoldPreOrder(const FoldFunctor, const void*, void*) const = 0;
  virtual void FoldPostOrder(const FoldFunctor, const void*, void*) const = 0;

  virtual bool Exists(const Data&) const noexcept override;

};

/* ************************************************************************** */

template <typename Data>
class InOrderMappableContainer: virtual public MappableContainer<Data> {

private:

protected:

public:

     virtual ~InOrderMappableContainer() noexcept= default;

  /* ************************************************************************ */

     InOrderMappableContainer& operator=(const InOrderMappableContainer&)= delete;

     InOrderMappableContainer& operator=(InOrderMappableContainer&&)= delete;

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
