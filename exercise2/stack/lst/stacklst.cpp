
namespace lasd {

/* ************************************************************************** */

// Specific constructor
template <typename Data>
StackLst<Data>::StackLst(const LinearContainer<Data>&){
                           //if size =0, the list's pointers are nullptr because the container is empty
  if(con.Size()==0){
     top= nullptr;
  }
                           //else, i can insert at back of the list the elements from the container
  else{
     top= nullptr;
     for (unsigned long i=0; i < con.Size(); i++){
       InsertAtBack(con[i]);
     }
  }
}

// Copy constructor
 template<typename Data>
 StackLst<Data>::StackLst(const StackLst<Data>& otherStackLst){
                                   //if the two lists are different i can proceed with comparisons (i can't copy the same list into a list)
   if(this != &otherList){
                                   //if the list to copy is empty, i have nothing to copy
     if(otherStackLst.First==nullptr){
       top=nullptr;
       dim=0;
     }
                                  //else, i create a new node into the new list with the element from the other list
     else{
       Node* current = otherStackLst.First;
       List<Data>::InsertAtBack(otherStackLst.First->elemento);
                                 //i can proceed with the copy until the last one element of the other list
       current=current->next;
       while(current != nullptr){
         List<Data>::InsertAtBack(current->elemento);
         current=current->next;
       }
                                 //at the end, i refresh the size of the new list with the size from the other list
     dim=otherStackLst.dim;
    }
  }
}


//Push function (copy)
template <typename Data>
void Push(const Data& value){
  List<Data>::InsertAtFront(value);
}

//Push function (move)
template <typename Data>
void Push(Data&& value){
  List<Data>::InsertAtFront(value);
}

//Top function
void Top(){
  List<Data>::Front();
}

//Pop function
void Pop(){
  List<Data>::RemoveFromFront();
}

//TopNPop function
template <typename Data>
Data& TopNPop(){
  List<Data>::FrontNRemove();
}

/* ************************************************************************** */

}
