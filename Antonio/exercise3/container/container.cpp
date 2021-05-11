
namespace lasd {

/* ************************************************************************** */

//FoldableContainer:specific member functions


                                        /*AuxFoldExists: auxiliary function used for checking the existance of
                                        a given value(val) into a Container of "Data"
                                         */
template<typename Data>
void AuxFoldExists(const Data& dat, const  void* val, void* exists) {
  if(dat == *((Data*) val)) {
    *((bool*) exists) = true;
  }
}
                                       /*Exists: checks the existance of a "Data" value and then it execute the FoldPreOrder functions
                                        being sure that the value exists into the current container  */
template<typename Data>
bool FoldableContainer<Data>::Exists(const Data& dat) const noexcept {
  bool exists=false;
  FoldPreOrder(&AuxFoldExists<Data>, &dat, &exists);
  return exists;
}


/* ************************************************************************** */

}
