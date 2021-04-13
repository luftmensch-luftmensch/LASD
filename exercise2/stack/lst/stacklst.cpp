
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
       struct Node* current;
       current=otherStackLst.First;
       struct Node* node=new Node(current->elemento);
                                 //here i can refresh the pointers with the correct values
       First=node;
       top=First;
       Last=First;
                                 //i can proceed with the copy until the last one element of the other list
       current=current->next;
       while(current != nullptr){
         struct Node* newnode=new Node(current->elemento);
         Last->next=newnode;
         Last=newnode;
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
