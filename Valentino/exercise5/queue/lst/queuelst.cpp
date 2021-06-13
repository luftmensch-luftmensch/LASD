
namespace lasd {
    template <typename Data>
    QueueLst<Data>::QueueLst(): List<Data>() {} // Costruttore di default

    template <typename Data>
    QueueLst<Data>::QueueLst(const LinearContainer<Data>& con): List<Data>::List(con) {} // Costruttore Specifico

    template <typename Data>
    QueueLst<Data>::QueueLst(const QueueLst& q): List<Data>(q){} // Costruttore di copia

    template <typename Data>
    QueueLst<Data>::QueueLst(QueueLst&& q) noexcept : List<Data>(std::move(q)){} // Costuttore di spostamento

    template <typename Data>
    QueueLst<Data>& QueueLst<Data>::operator=(const QueueLst& q){ // Assegnamento (copia)
      List<Data>::operator=(q);
      return *this;
    }
    template <typename Data>
    QueueLst<Data>& QueueLst<Data>::operator=(QueueLst&& q) noexcept { // Assegnamento (spostamento)
      List<Data>::operator=(std::move(q));
      return *this;
    }
    template <typename Data>
    bool QueueLst<Data>::operator==(const QueueLst& q) const noexcept{ // Operatori di confronto
      return List<Data>::operator==(q);
    }

    template <typename Data>
    bool QueueLst<Data>::operator!=(const QueueLst& q) const noexcept{
      return List<Data>::operator!=(q);
    }
    template <typename Data>
    Data& QueueLst<Data>::Head() const { // Funzione Head
      if(Empty())
	    throw std::length_error("Impossibile rimuovere dalla Coda: la sua dimesione è 0!");

      return List<Data>::Front();
    }
    template <typename Data>
    void QueueLst<Data>::Dequeue(){ // Funzione Dequeue
      if(Empty())
	    throw std::length_error("Impossibile rimuovere dalla Coda: la sua dimesione è 0!");

      return List<Data>::RemoveFromFront();
    }

    template <typename Data>
    Data QueueLst<Data>::HeadNDequeue(){ // Funzione HeadNDequeue 
      if(Empty())
	    throw std::length_error("Impossibile rimuovere dalla Coda: la sua dimesione è 0!");

      return List<Data>::FrontNRemove();
    }
    template <typename Data>
    void QueueLst<Data>::Enqueue(const Data& d){ // Funzione Enqueue (copia)
      List<Data>::InsertAtBack(d);
    }
    template <typename Data>
    void QueueLst<Data>::Enqueue(Data&& d){ // Funzione Enqueue (spostamento)
      List<Data>::InsertAtBack(std::move(d));
    }
}
