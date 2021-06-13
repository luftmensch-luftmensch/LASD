
namespace lasd {

/* ************************************************************************** */

    template <typename Data>
    StackVec<Data>::StackVec(): Vector<Data>::Vector(1){} // Costruttore di default


    template<typename Data>
    StackVec<Data>::StackVec(const LinearContainer<Data>& Container){ // Costruttore specifico
      dimensione=Container.Size();
      elemento= new Data[dimensione];
      for (ulong i=0; i<Container.Size(); ++i){
	Push(Container[i]);
      }
    }
    template<typename Data>
    StackVec<Data>::StackVec(const StackVec<Data>& stackvec): Vector<Data>::Vector(stackvec){ // Costruttore di copia
      top= stackvec.top;

    }

    template<typename Data>
    StackVec<Data>& StackVec<Data>::operator=(const StackVec<Data>& stackvec){ // Assegnamento (copia)
	Vector<Data>::operator=(stackvec);
	top=stackvec.top;
	return *this;
    }

    template<typename Data>
    StackVec<Data>::StackVec(StackVec<Data>&& stackvec) : Vector<Data>::Vector(std::move(stackvec)){ // Costruttore di spostamento
      top=stackvec.top;
      stackvec.Clear();

    }

    template<typename Data>
    StackVec<Data>& StackVec<Data>::operator=(StackVec<Data>&& stackvec) noexcept{ // Assegnamento (spostamento)
      Vector<Data>::operator=(std::move(stackvec));
      std::swap(top, stackvec.top);
      return *this;
    }

    template <typename Data>
    bool StackVec<Data>::operator==(const StackVec& s) const noexcept{ // Operatori di confronto
      if(this == &s)
	return true;

      if(top != s.top)
	return false;

      ulong index = 0;
      while(index < top && Vector<Data>::operator[](index) == s.Vector<Data>::operator[](index))
	index++;


      return index == top;
    }
    template <typename Data>
    bool StackVec<Data>::operator!=(const StackVec& s) const noexcept{
      return !(*this == s);
    }
    template <typename Data>
    Data& StackVec<Data>::Top() const { // Funzione Top
      if(Empty())
	    throw std::length_error("Impossibile rimuovere dallo Stack: la sua dimensione è 0!");

      return Vector<Data>::operator[](top-1);
    }
    template <typename Data>
    void StackVec<Data>::Pop(){ // Funzione Pop
      if(Empty())
	    throw std::length_error("Impossibile rimuovere dallo Stack: la sua dimensione è 0!");

      Data eliminato = std::move(Vector<Data>::operator[](--top));
      (void)eliminato;

      if(top < dimensione/4)
	Reduce();
    }
    template <typename Data>
    Data StackVec<Data>::TopNPop(){ // Funzione TooNPop
      if(Empty())
	    throw std::length_error("Impossibile rimuovere dallo Stack: la sua dimensione è 0!");

      Data ret = std::move(Vector<Data>::operator[](--top));

      if(top < dimensione/4)
	Reduce();

      return ret;
    }

    template <typename Data>
    void StackVec<Data>::Push(const Data& d){ // Funzione di Push (copia)
      Vector<Data>::operator[](top++) = d;
      if(top == dimensione)
	Expand();
    }
    template <typename Data>
    void StackVec<Data>::Push(Data&& d){ // Funzione di Push (spostamento)
      Vector<Data>::operator[](top++) = std::move(d);
      if(top == dimensione)
	Expand();
    }
    template <typename Data>
    bool StackVec<Data>::Empty() const noexcept { // Funzione Empty
      return top == 0;
    }
    template <typename Data>
    ulong StackVec<Data>::Size() const noexcept { // Funzione size
      return top;
    }
    template <typename Data>
    void StackVec<Data>::Clear() noexcept { // Funzione Clear
      Vector<Data>::Resize(1);
      top = 0;
    }
    template <typename Data>
    void StackVec<Data>::Expand(){ // Funzione Expand
      Vector<Data>::Resize(dimensione*2);
    }
    template <typename Data>
    void StackVec<Data>::Reduce(){ // Funzione Reduce
      Vector<Data>::Resize(dimensione/2);
    }
}
