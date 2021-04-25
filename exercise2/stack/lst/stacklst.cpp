
namespace lasd {

/* ************************************************************************** */
template <typename Data>
StackLst<Data>::StackLst(): List<Data>::List() {} // Costruttore di default


template <typename Data>
StackLst<Data>::StackLst(const LinearContainer<Data>& Container): List<Data>::List(Container) {} // Costruttore specifico

template<typename Data>
StackLst<Data>::StackLst(const StackLst<Data>& StackList): List<Data>::List(StackList){} // Costruttore di copia


template <typename Data>
StackLst<Data>& StackLst<Data>::operator=(const StackLst& ListaDaCopiare){ // Assegnamento (copia)
  List<Data>::operator=(ListaDaCopiare);
  return *this;
}
template<typename Data>
StackLst<Data>::StackLst(StackLst<Data>&& StackList) noexcept: List<Data>::List(std::move(StackList)){} // Costruttore di spostamento

template <typename Data>
StackLst<Data>& StackLst<Data>::operator=(StackLst&& ListaDaSpostare) noexcept { // Assegnamento (spostamento)
  List<Data>::operator=(std::move(ListaDaSpostare));
  return *this;
}


template <typename Data>
bool StackLst<Data>::operator==(const StackLst& ListaDaConfrontare) const noexcept{ // Operatori di confronto
  return List<Data>::operator==(ListaDaConfrontare);
}
template <typename Data>
bool StackLst<Data>::operator!=(const StackLst& ListaDaConfrontare) const noexcept{
  return List<Data>::operator!=(ListaDaConfrontare);
}

template <typename Data>
void StackLst<Data>::Push(const Data& d){ // Funzione Push (copia)
  List<Data>::InsertAtFront(d);
}


template <typename Data>
void StackLst<Data>::Push(Data&& d){ // Funzione Push (spostamento)
  List<Data>::InsertAtFront(std::move(d));
}

template <typename Data>
Data& StackLst<Data>::Top() const { // Funzione Top
  if(Empty())
	    throw std::length_error("Impossibile rimuovere dallo Stack: la sua dimensione è 0!");

  return List<Data>::Front();
}
template <typename Data>
void StackLst<Data>::Pop(){ // Funzione Pop
  if(Empty())
	    throw std::length_error("Impossibile rimuovere dallo Stack: la sua dimensione è 0!");

  List<Data>::RemoveFromFront();
}
template <typename Data>
Data StackLst<Data>::TopNPop(){ // Funzione TopNPop
  if(Empty())
	    throw std::length_error("Impossibile rimuovere dallo Stack: la sua dimensione è 0!");

  return List<Data>::FrontNRemove();
}


}
