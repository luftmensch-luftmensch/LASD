namespace lasd {

template<typename Data>
MatrixVec<Data>::MatrixVec(){
  nRighe=0;
  nColonne=0;
  dimensione=0;
}

template<typename Data>
MatrixVec<Data>::MatrixVec(unsigned int riga, unsigned int colonna){
  if (riga != 0 && colonna != 0) {
    nRighe = riga;
    nColonne = colonna;
    dimensione = riga * colonna;
    elemento = new Data[dimensione]{};
  }
}

template<typename Data>
MatrixVec<Data>::MatrixVec(const MatrixVec<Data>& matrice):Vector<Data>(matrice){
  nRighe = matrice.nRighe;
  nColonne = matrice.nColonne;
}

template<typename Data>
MatrixVec<Data>::MatrixVec(MatrixVec<Data>&& matrice)noexcept:Vector<Data>(std::move(matrice)){
  std::swap(nRighe, matrice.nRighe);
  matrice.nRighe = 0;
  std::swap(nColonne, matrice.nColonne);
  matrice.nColonne = 0;
}

template<typename Data>
MatrixVec<Data>::~MatrixVec(){
  Vector<Data>::Clear();
  nRighe = 0;
  nColonne = 0;
}

template<typename Data>
MatrixVec<Data>& MatrixVec<Data>::operator=(const MatrixVec<Data>& matrice){
  nRighe = matrice.nRighe;
  nColonne = matrice.nColonne;
  MatrixVec<Data> *nuovoVettore = new MatrixVec<Data>(matrice);
  std::swap(*this, *nuovoVettore);
  delete nuovoVettore;
  return *this;
}

template <typename Data>
MatrixVec<Data>& MatrixVec<Data>::operator=(MatrixVec<Data>&& matrice)noexcept{
  Vector<Data>::operator=(std::move(matrice));
  std::swap(nRighe, matrice.nRighe);
  std::swap(nColonne, matrice.nColonne);
  return *this;
}

template <typename Data>
bool MatrixVec<Data>::operator==(const MatrixVec<Data>& matrice) const noexcept{
  return Vector<Data>::operator==(matrice);
}

template <typename Data>
bool MatrixVec<Data>::operator!=(const MatrixVec<Data>& matrice) const noexcept{
  return Vector<Data>::operator!=(matrice);
}

template<typename Data>
void MatrixVec<Data>::RowResize(ulong newNRighe){
  ulong nuovaDim=newNRighe*nColonne;
  Vector<Data>::Resize(nuovaDim);
  nRighe=newNRighe;
}

template<typename Data>
void MatrixVec<Data>::ColumnResize(ulong newNColonne){
  if (newNColonne == 0) {
    Clear();
  } else if (nColonne != newNColonne) {
    ulong nuovaDim = newNColonne * nRighe;
    MatrixVec<Data> elementoTemp(nRighe, newNColonne);
    if (nColonne < newNColonne) {
      uint i = 0;
      while (i < nRighe) {
	uint j = 0;
	while (j < nColonne) {
	  std::swap(elemento[i * nColonne + j],
		    elementoTemp.elemento[i * newNColonne + j]);
	  j++;
	}
	i++;
      }
      std::swap(elemento, elementoTemp.elemento);
      nColonne = newNColonne;
      dimensione = nuovaDim;
    } else if (nColonne > newNColonne) {
      uint i=0;
      while(i<nRighe){
        uint j=0;
        while(j<newNColonne){
          std::swap(elemento[i*nColonne+j], elementoTemp.elemento[i*newNColonne+j]);
          j++;
        }
        i++;
       }
      std::swap(elemento,elementoTemp.elemento);
      nColonne = newNColonne;
      dimensione=nuovaDim;
    }
  }
}

template<typename Data>
void MatrixVec<Data>::Clear(){
  Vector<Data>::Clear();
  nRighe=0;
  nColonne=0;
}

template <typename Data>
bool MatrixVec<Data>::ExistsCell(ulong righe, ulong colonne) const noexcept {
  return (righe < nRighe && colonne < nColonne);
}

template<typename Data>
Data const& MatrixVec<Data>::operator()(ulong righe,ulong colonne)const{
  if (righe >= nRighe || colonne >= nColonne) {
    throw std::out_of_range("Impossibile accedere all'area di memoria desiderata");
  } else {
    return elemento[righe * nColonne + colonne];
  }
}

template<typename Data>
Data& MatrixVec<Data>::operator()(const ulong righe,const ulong colonne){
  return const_cast<Data&>(static_cast<const MatrixVec<Data>*>(this)->operator()(righe,colonne));
}
}
