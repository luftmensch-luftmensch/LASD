
namespace lasd {

/* ************************************************************************** */
template <typename Data>
QueueVec<Data>::QueueVec(): Vector<Data>(2) {} // Costruttore di default

template <typename Data>
QueueVec<Data>::QueueVec(const LinearContainer<Data>& Container): Vector<Data>::Vector(Container) { // Costruttore specifico
    dimensione = Container.Size();
    elemento = new Data[dimensione];
    for (ulong i = 0; i < Container.Size(); ++i) {
      Enqueue(Container[i]);
    }
}
template <typename Data>
QueueVec<Data>::QueueVec(const QueueVec& Coda): Vector<Data>(Coda){ // Costruttore di copia
    testa = Coda.testa;
    coda = Coda.coda;
}
template <typename Data>
QueueVec<Data>::QueueVec(QueueVec&& Coda) noexcept: Vector<Data>(std::move(Coda)) { // Costruttore di spostamento
    testa = Coda.testa;
    coda = Coda.coda;

    Coda.Clear();
}
template <typename Data>
QueueVec<Data>& QueueVec<Data>::operator=(const QueueVec& Coda){ // Assegnamento (copia)
      Vector<Data>::operator=(Coda);
      testa = Coda.testa;
      coda = Coda.coda;

      return *this;
}
template <typename Data>
QueueVec<Data>& QueueVec<Data>::operator=(QueueVec&& Coda) noexcept { // Assegnamento (spostamento)
      Vector<Data>::operator=(std::move(Coda));
      std::swap(testa, Coda.testa);
      std::swap(coda, Coda.coda);

      return *this;
}
                //Comparison operator
template <typename Data>
bool QueueVec<Data>::operator==(const QueueVec& Coda) const noexcept{
    if(this == &Coda)
      return true;

    if(Size() != Coda.Size())
      return false;

    ulong i = testa;
    ulong j = Coda.testa;
    ulong compares = 0;
    while(i != coda && Vector<Data>::operator[](i) == Coda.Vector<Data>::operator[](j) ){
      i = (i+1) % dimensione;
      j = (j+1) % Coda.dimensione;
      compares++;
    }

  return compares == Size();
}
template <typename Data>
bool QueueVec<Data>::operator!=(const QueueVec& Coda) const noexcept{
  return !(*this == Coda);
}
template <typename Data>
Data& QueueVec<Data>::Head() const { // Funzione Testa
  if(Empty())
  	throw std::length_error("Impossibile rimuovere dalla Coda: la sua dimesione è 0!");

  return Vector<Data>::operator[](testa);
}
template <typename Data>
void QueueVec<Data>::Dequeue(){ // Funzione Dequeue
  if(Empty())
  	throw std::length_error("Impossibile rimuovere dalla Coda: la sua dimesione è 0!");

  //Moving to an internal variable that will be deleted upon exiting the scope
  Data del = std::move(Vector<Data>::operator[](testa));
  (void)del;
  testa = (testa+1) % dimensione;
  if(Size() < dimensione/4)
    Reduce();
}
template <typename Data>
Data QueueVec<Data>::HeadNDequeue(){ // Funzione Headndequeue
  if(Empty())
  	throw std::length_error("Impossibile rimuovere dalla Coda: la sua dimesione è 0!");

  Data ret = std::move(Vector<Data>::operator[](testa));

  testa = (testa+1) % dimensione;
  if(Size() < dimensione/4)
    Reduce();

  return ret;
}
template <typename Data>
void QueueVec<Data>::Enqueue(const Data& d){ // Funzione Enqueue (copia) 
  Vector<Data>::operator[](coda) = d;
  coda = (coda+1) % dimensione;

  if(coda == testa)
    Expand();
}

template <typename Data>
void QueueVec<Data>::Enqueue(Data&& d){ // Funzione Enqueue (spostamento)
  Vector<Data>::operator[](coda) = std::move(d);
  coda = (coda+1) % dimensione;

  if(coda == testa)
    Expand();
}
template <typename Data>
inline bool QueueVec<Data>::Empty() const noexcept { // Funzione Empty
  return testa == coda;
}
template <typename Data>
inline ulong QueueVec<Data>::Size() const noexcept { // Funzione size
  return (dimensione -  testa + coda) % dimensione;
}
template <typename Data>
void QueueVec<Data>::Clear() noexcept { // Funzione clear
  Vector<Data>::Resize(2);
  testa = coda = 0;
}
template <typename Data>
void QueueVec<Data>::Expand(){ // Funzione Expand
  Vector<Data>::Resize(dimensione*2);

  //      t                                  t
  // [1] [1] [1] [1] -> [?] [1] [1] [1] [1] [?] [?] [?]
  //      h                  h
  //
  ulong j;
  for(j = 0; j < coda; j++)
    Vector<Data>::operator[](j+dimensione/2) = std::move(Vector<Data>::operator[](j));

  coda = j + dimensione/2;
}
           //Reduce function
template <typename Data>
void QueueVec<Data>::Reduce(){ // Funzione Reduce

  Vector<Data> d(dimensione/2);

  ulong p = 0;
  ulong j = testa;
  while(j != coda){
      d[p++] = std::move(Vector<Data>::operator[](j));
      j = (j+1) % dimensione;
  }

  testa = 0;
  coda = p;
  Vector<Data>::operator=(std::move(d));
}

}
