
namespace lasd {

template<typename Data>
MatrixCSR<Data>::MatrixCSR(){
  nColonne=0;
  nRighe=0;
  vettoreDiRighe.Resize(1);
  vettoreDiRighe[0]=&First;
}

template <typename Data>
MatrixCSR<Data>::MatrixCSR(ulong righe,ulong colonne){
  nColonne=colonne;
  nRighe=righe;

  vettoreDiRighe.Resize(righe+1);
  for(ulong j=0;j<=righe;j++){
    vettoreDiRighe[j]=&First;
  }
}

template<typename Data>
MatrixCSR<Data>::~MatrixCSR(){
  List<std::pair<Data,ulong>>::Clear();
  vettoreDiRighe.Clear();
  nRighe=0;
  nColonne=0;
}

template <typename Data>
MatrixCSR<Data>::MatrixCSR(const MatrixCSR<Data>& mat) : MatrixCSR(mat.nRighe,mat.nColonne){
  for (ulong riga = 0; riga < nRighe; riga++) {
    for (Node **nodoPtr = mat.vettoreDiRighe[riga]; nodoPtr != mat.vettoreDiRighe[riga + 1]; nodoPtr = &((*nodoPtr)->next)) {
      Node &current = **nodoPtr;
      (*this)(riga, current.elemento.second) = current.elemento.first;
    }
  }
}

template <typename Data>
MatrixCSR<Data>::MatrixCSR(MatrixCSR<Data>&& matrice)noexcept:List<std::pair<Data,ulong>>::List(std::move(matrice)){
  vettoreDiRighe.Resize(1);
  std::swap(nRighe,matrice.nRighe);
  std::swap(nColonne,matrice.nColonne);
  std::swap(vettoreDiRighe,matrice.vettoreDiRighe);
  vettoreDiRighe[0]=&First;
  for(ulong j=0;j<matrice.dimensione &&matrice.vettoreDiRighe[j]==&matrice.First;++j){
    matrice.vettoreDiRighe[j]=&matrice.First;
  }
  matrice.Clear();
}

template <typename Data>
MatrixCSR<Data>& MatrixCSR<Data>::operator=(const MatrixCSR<Data>& matrice){
  MatrixCSR<Data>* nuovaMatrice= new MatrixCSR<Data>(matrice);
  std::swap(*this,*nuovaMatrice);
  delete nuovaMatrice;
  return *this;
}

template<typename Data>
MatrixCSR<Data>& MatrixCSR<Data>::operator=(MatrixCSR<Data>&& matrice) noexcept{

  std::swap(First, matrice.First);
  std::swap(nRighe, matrice.nRighe);
  std::swap(nColonne, matrice.nColonne);
  std::swap(vettoreDiRighe, matrice.vettoreDiRighe);
  std::swap(dimensione, matrice.dimensione);
  for (ulong j = 0; j < dimensione && vettoreDiRighe[j] == &matrice.First; ++j) {
    vettoreDiRighe[j] = &First;
  }
  for(ulong j=0;j<matrice.dimensione &&matrice.vettoreDiRighe[j]==&First;++j){
    matrice.vettoreDiRighe[j]=&matrice.First;
  }
  return *this;
}

template <typename Data>
bool MatrixCSR<Data>::operator==(const MatrixCSR<Data>& matrice) const noexcept{
  return (nRighe==matrice.nRighe) && (nColonne==matrice.nColonne) && List<std::pair<Data,ulong>>::operator==(matrice);
}

template <typename Data>
bool MatrixCSR<Data>::operator!=(const MatrixCSR<Data>& matrice) const noexcept{
  return !(*this==matrice);
}

template <typename Data>
void MatrixCSR<Data>::RowResize(ulong newNRighe){
  if (newNRighe == 0) {
    List<std::pair<Data, ulong>>::Clear();
  } else if (newNRighe < nRighe) {
    Node **nodoPtr = vettoreDiRighe[newNRighe];
    while ((*nodoPtr) != nullptr) {
      Node *temp = *nodoPtr;
      *nodoPtr = (*nodoPtr)->next;
      delete temp;
      temp = nullptr;
      --dimensione;
    }
    vettoreDiRighe.Resize(newNRighe+1);
  } else {
    vettoreDiRighe.Resize(newNRighe+1);
    for(uint i=nRighe;i<newNRighe;i++){
      vettoreDiRighe[i+1]=vettoreDiRighe[i];
    }
  }
  nRighe=newNRighe;
}

template <typename Data>
void MatrixCSR<Data>::ColumnResize(ulong newNColonne){
  if (newNColonne == 0) {
    List<std::pair<Data, ulong>>::Clear();
  } else if (newNColonne < nColonne) {
    ulong j=1;
    Node** nodoPtr=&First;
    while(j<=nRighe){
      Node* current;
      Node** nextRiga = vettoreDiRighe[j];
      while(nodoPtr!= nextRiga && (*nodoPtr)->elemento.second < newNColonne){
        current=*nodoPtr;
        nodoPtr=&(current->next);
      }
      if(nodoPtr!=nextRiga){
        if(nextRiga==vettoreDiRighe[nRighe]){
          Last=current;
        }
        Node* temp=*nodoPtr;
        *nodoPtr=*nextRiga;
        *nextRiga=nullptr;
        for(Node* nodoPtr=temp;nodoPtr!=nullptr;nodoPtr=nodoPtr->next){
          dimensione--;
        }
        delete temp;
      }
      for(;j<=nRighe && vettoreDiRighe[j]==nextRiga;++j){
        vettoreDiRighe[j]=nodoPtr;
      }
    }
  }
  nColonne=newNColonne;
}

template <typename Data>
void MatrixCSR<Data>::Clear(){
  nRighe = 0;
  nColonne = 0;
  List<std::pair<Data, ulong>>::Clear();
  vettoreDiRighe.Resize(1);
}

template <typename Data>
bool MatrixCSR<Data>::ExistsCell(ulong riga,ulong colonna )const noexcept{
  if ((riga < nRighe) && (colonna < nColonne)) {
    Node **nodoPtr = vettoreDiRighe[riga];
    while (nodoPtr != vettoreDiRighe[riga + 1]) {
      Node &current = **nodoPtr;
      if (current.elemento.second == colonna) {
	return true;
      }
      nodoPtr = &(current.next);
    }
  }
  return false;
}

template <typename Data>
Data& MatrixCSR<Data>::operator()(ulong riga,ulong colonna ){
  if((riga<nRighe) && (colonna <nColonne)){
    Node** nodoPtr=vettoreDiRighe[riga];
    while (nodoPtr != vettoreDiRighe[riga + 1]) {
      if ((*nodoPtr)->elemento.second == colonna) {
	return (*nodoPtr)->elemento.first;
      } else if ((*nodoPtr)->elemento.second > colonna) {
	Node *nuovoNodo = new Node;
	nuovoNodo->elemento.second = colonna;
	Node *temp = *nodoPtr;
	*nodoPtr = nuovoNodo;
	nuovoNodo->next = temp;
	++dimensione;
	return nuovoNodo->elemento.first;
      } else {
	nodoPtr = &((*nodoPtr)->next);
      }
    }
    Node *nuovoNodo = new Node;
    nuovoNodo->elemento.second=colonna ;
    Node* temp=*nodoPtr;
    *nodoPtr=nuovoNodo;
    if(*nodoPtr!=nullptr){
      nuovoNodo->next=temp;
    }
    for(ulong i=riga+2;i<nRighe+1;i++){
      if(vettoreDiRighe[i]==vettoreDiRighe[riga+1]){
        vettoreDiRighe[i]=&nuovoNodo->next;
      }
    }
    vettoreDiRighe[riga+1]=&nuovoNodo->next;
    ++dimensione;
    return nuovoNodo->elemento.first;

  }
  else{
    throw std::out_of_range("Impossibile accedere all'area di memoria desiderata");
  }
}



template <typename Data>
Data const& MatrixCSR<Data>::operator()(ulong riga,ulong colonna )const{
   if((riga<nRighe) && (colonna <nColonne)){
     Node** nodoPtr=vettoreDiRighe[riga];
     bool trovato=false;
     while (nodoPtr != vettoreDiRighe[riga + 1] && (*nodoPtr)->elemento.second <= colonna) {
       if ((*nodoPtr)->elemento.second == colonna) {
	 return (*nodoPtr)->elemento.first;
       }
       nodoPtr = &((*nodoPtr)->next);
     }
     if (trovato == false) {
       throw std::length_error("L'elemento desiderato non è presente nella matrice");
     }
   }
   else{
     throw std::out_of_range("Impossibile accedere all'area di memoria desiderata");
   }
   throw std::out_of_range("Impossibile accedere all'area di memoria desiderata");
}


template<typename Data>
void MatrixCSR<Data>::MapPreOrder(MapFunctor fun,void* par){
  List<std::pair<Data, ulong>>::MapPreOrder(
      [&fun](std::pair<Data, ulong> &datx, void *parx) {
	fun(datx.first, parx);
      },
      par);
}

template<typename Data>
void MatrixCSR<Data>::MapPostOrder(MapFunctor fun,void* par){
  List<std::pair<Data, ulong>>::MapPostOrder(
      [&fun](std::pair<Data, ulong> &datx, void *parx) {
	fun(datx.first, parx);
      },
      par);
}

template<typename Data>
void MatrixCSR<Data>::FoldPreOrder(FoldFunctor fun,const void* par,void* acc)const{
  List<std::pair<Data, ulong>>::FoldPreOrder(
      [&fun](const std::pair<Data, ulong> &datx, const void *parx, void *accx) {
	fun(datx.first, parx, accx);
      },
      par, acc);
}

template<typename Data>
void MatrixCSR<Data>::FoldPostOrder(FoldFunctor fun,const void* par,void* acc)const{
  List<std::pair<Data, ulong>>::FoldPostOrder(
      [&fun](const std::pair<Data, ulong> &datx, const void *parx, void *accx) {
	fun(datx.first, parx, accx);
      },
      par, acc);
}
}
