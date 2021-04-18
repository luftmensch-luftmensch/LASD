
namespace lasd {

/* ************************************************************************** */
                 //Default constructor
template <typename Data>
QueueVec<Data>::QueueVec(): Vector<Data>(2) {}

template <typename Data>
QueueVec<Data>::QueueVec(const LinearContainer<Data>& con): Vector<Data>::Vector(con) {
  dim=con.Size();
  elem= new Data[dim];
  for (unsigned long i=0; i<con.Size(); ++i){
    Enqueue(con[i]);
  }
}
                 //Copy constructor
template <typename Data>
QueueVec<Data>::QueueVec(const QueueVec& q): Vector<Data>(q){
  head = q.head;
  tail = q.tail;
}
                 //Move constructor
template <typename Data>
QueueVec<Data>::QueueVec(QueueVec&& q) noexcept: Vector<Data>(std::move(q)) {
  head = q.head;
  tail = q.tail;

  q.Clear();
}
                //Copy assignment
template <typename Data>
QueueVec<Data>& QueueVec<Data>::operator=(const QueueVec& q){
  Vector<Data>::operator=(q);
  head = q.head;
  tail = q.tail;

  return *this;
}
               //Move assignment
template <typename Data>
QueueVec<Data>& QueueVec<Data>::operator=(QueueVec&& q) noexcept {
  Vector<Data>::operator=(std::move(q));
  std::swap(head, q.head);
  std::swap(tail, q.tail);

  return *this;
}
                //Comparison operator
template <typename Data>
bool QueueVec<Data>::operator==(const QueueVec& q) const noexcept{
  if(this == &q)
    return true;

  if(Size() != q.Size())
    return false;

  unsigned long i = head;
  unsigned long j = q.head;
  unsigned long compares = 0;
  while(i != tail && Vector<Data>::operator[](i) == q.Vector<Data>::operator[](j) ){
    i = (i+1) % dim;
    j = (j+1) % q.dim;
    compares++;
  }

  return compares == Size();
}
              //Other comparison operator
template <typename Data>
bool QueueVec<Data>::operator!=(const QueueVec& q) const noexcept{
  return !(*this == q);
}
             //Head function
template <typename Data>
Data& QueueVec<Data>::Head() const {
  if(Empty())
  	throw std::length_error("Could not remove from the Queue: Queue size is 0!");

  return Vector<Data>::operator[](head);
}
            //Dequeue function
template <typename Data>
void QueueVec<Data>::Dequeue(){
  if(Empty())
  	throw std::length_error("Could not remove from the Queue: Queue size is 0!");

  //Moving to an internal variable that will be deleted upon exiting the scope
  Data del = std::move(Vector<Data>::operator[](head));
  (void)del;
  head = (head+1) % dim;
  if(Size() < dim/4)
    Reduce();
}
             //HeadNDequeue function
template <typename Data>
Data QueueVec<Data>::HeadNDequeue(){
  if(Empty())
  	throw std::length_error("Could not remove from the Queue: Queue size is 0!");

  Data ret = std::move(Vector<Data>::operator[](head));

  head = (head+1) % dim;
  if(Size() < dim/4)
    Reduce();

  return ret;
}
            //Enqueue function (copy)
template <typename Data>
void QueueVec<Data>::Enqueue(const Data& d){
  Vector<Data>::operator[](tail) = d;
  tail = (tail+1) % dim;

  if(tail == head)
    Expand();
}
             //Enqueue function (move)
template <typename Data>
void QueueVec<Data>::Enqueue(Data&& d){
  Vector<Data>::operator[](tail) = std::move(d);
  tail = (tail+1) % dim;

  if(tail == head)
    Expand();
}
             //Empty function
template <typename Data>
inline bool QueueVec<Data>::Empty() const noexcept {
  return head == tail;
}
            //Size function
template <typename Data>
inline unsigned long QueueVec<Data>::Size() const noexcept {
  return (dim -  head + tail) % dim;
}
           //Clear
template <typename Data>
void QueueVec<Data>::Clear() noexcept {
  Vector<Data>::Resize(2);
  head = tail = 0;
}
          //Expand function
template <typename Data>
void QueueVec<Data>::Expand(){
  Vector<Data>::Resize(dim*2);

  // Sposto tutti gli elementi prima di h (o di t)
  // (per preservarne l'ordine di lettura)
  // Infine, setto t alla metà della dimensione più il numero di elementi spostati più 1
  //
  //      t                                  t
  // [1] [1] [1] [1] -> [?] [1] [1] [1] [1] [?] [?] [?]
  //      h                  h
  //
  unsigned long index;
  for(index = 0; index < tail; index++)
    Vector<Data>::operator[](index+dim/2) = std::move(Vector<Data>::operator[](index));

  tail = index + dim/2;
}
           //Reduce function
template <typename Data>
void QueueVec<Data>::Reduce(){
  //L'operazione di Resize corrisponderebbe comunque ad una copia
  //del vettore precedente
  //Vector<Data>::Resize(m_size/2);

  Vector<Data> d(dim/2);

  unsigned long p = 0;
  unsigned long index = head;
  while(index != tail){
      d[p++] = std::move(Vector<Data>::operator[](index));
      index = (index+1) % dim;
  }

  head = 0;
  tail = p;
  Vector<Data>::operator=(std::move(d));
}
/* ************************************************************************** */

}
