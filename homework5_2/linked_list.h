//
// Created by Greg LaKomski on 2/25/18.
//
#include <iostream>
using std::cout;
using std::endl;
using std::swap;

#ifndef HOMEWORK5_LINKED_LIST_H
#define HOMEWORK5_LINKED_LIST_H


struct node{
  // this doesnâ€™t have to be an int - think template  we will talk about in class
  int data;
  node *next;
};

class linked_list{
 private:
  node *head;
  node *tail;
 public:
  // constructor
  linked_list() : head(NULL), tail(NULL) {}

  // destructor
  ~linked_list(){
    node * tmp = new node;
    while(head != tail) {
      tmp = head->next;
      head = NULL;
      delete head;
      head = tmp;
    }
    delete tail;
    tmp = NULL;
    delete tmp;
  }

  // copy constructor - implemented and finished on time
  linked_list(node * rhList){
    //Check if the first node is empty first of all
    if (rhList == NULL){
      return;
    }else{
      //There are nodes present to be copied
      //Create the nodes to be able to copy stuff
      //to the assigned link-list
      node *newListHead = new node;
      node *oldList = rhList;
      node *newListTail = NULL;
      node *tempPtr = newListHead;

      //While there are still nodes that need to be copied over,
      //do the following
      while(oldList != NULL){
        tempPtr->data = oldList->data;
        tempPtr = oldList->next;
        //If the tail is null, make a new tail
        if (newListTail == NULL) {
          newListTail = tempPtr;
        }
        //Go through linked list
        oldList = oldList->next;
      }//While
    }//Else
  }//Function


  // = operator implemented and finished on time
  const linked_list & operator = (const linked_list & other){
    //First, check if they are already equal to one another
    if(this == &other){
      return *this;
    }else{
      //If they aren't equal to one another go here
      //Create variables
      node *origPtr = other.head;
      //If there are contents in the list, clear them to allow for assignment
        if(this->head != NULL){
          //Use destructor
          this->~linked_list();
        }

      //Do the actual assignment of data node per node
      while(origPtr != NULL)
      {
        this->add_node(origPtr->data);
        //Continue through linked list to each node
        origPtr = origPtr->next;
      }

      return *this;
    }//else
  }//function

  void add_node(int n) {
    node *tmp = new node;
    tmp->data = n;
    tmp->next = NULL;

    if(head == NULL){
      head = tmp;
      tail = tmp;
    }else{
      tail->next = tmp;
      tail = tail->next;
    }
  }

  void display()
  {
    node *tmp;
    tmp = head;
    while (tmp != NULL) {
      std::cout << tmp->data << std::endl;
      tmp = tmp->next;
    }
  }

  // recursive example
  void display(node * start) {
    if(start == NULL){
      cout << "NULL" << endl;
    }else{
      cout << start->data << endl;
      display(start->next);
    }
  }

  void after(node *z, int value) {
    if (z != NULL) {
      node *p = new node;
      p->data = value;
      p->next = z->next;
      z->next = p;
    }

    if(z == tail){
      tail = tail->next;
    }
  }

  void front(int n){
    node *tmp = new node;
    tmp -> data = n;
    tmp -> next = head;
    head = tmp;
  }

  // deletes a node after a specific node before_del
  void del (node *before_del) {
    // if the node before delete is pointing to NULL
    // circular ?
    if (before_del->next == NULL) {
      cout << "Trying to delete past end!" << endl;
    } else{
      node *temp;
      temp = before_del->next;
      before_del->next = temp->next;
      //delete temp->data;
      delete temp;
    }
  }

  // deletes the top most node - the head node
  void delTop(){
    // if there are no nodes
    if(head == NULL){
      cout << "Empty, nothing to erase" << endl;
    }
    node* temp;
    // if there is only the head node left
    if(head == tail){
      delete head;
    }else{  // more than one node
      temp = head;
      head = head->next;
      //delete temp ->data;
      delete temp;
    }

  }

  node * getHeadPointer(){
    return head;
  }

  void setHeadPointer(node * newHead){
    head = newHead;
  }

  node * getTailPointer(){
    return tail;
  }

  void setTailPointer(node * newTail){
    tail = newTail;
  }
};

#endif //HOMEWORK5_LINKED_LIST_H