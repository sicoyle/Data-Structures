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

class linked_list {
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
    delete tail;        //I added, because tail was forgotten
    tmp = NULL;
    delete tmp;
  }

  // copy constructor - implemented
  linked_list(node * rhList){
    //Check if empty first
    if(rhList == NULL)
      return;

    //Create nodes for copying
    node *oldList = rhList;
    node *newListHead = new node;
    node * tempPtr = newListHead;
    node *newListTail = NULL;

    //While not end of rhList copy over
    while (oldList != NULL) {
      tempPtr->data = oldList-> data;
      tempPtr = oldList->next;
      if(newListTail == NULL) {
        newListTail = tempPtr;
      }
      //Increment to next node
      oldList = oldList->next;
    }//Close while
  }

  // = operator implemented
  const linked_list & operator = (const linked_list & other){
    //check if they are the same linked list
    if(this == &other) {
      return *this;
    } else {
      node *origPtr = other.head;
      //Check for if this linked list has contents already
      //Clear contents
      if(this->head != NULL) {
        this->~linked_list();
      }

      //Assign if there are contents to assign to this
      while(origPtr != NULL)
      {
        this->add_node(origPtr -> data);
        //Move to next node
        origPtr = origPtr -> next;
      }

      //Always return *this for overloading = operator
      return *this;
    }//Close else
  }

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