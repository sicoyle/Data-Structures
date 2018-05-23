//
// Created by Greg LaKomski on 2/27/18.
//

#ifndef HOMEWORK5_CIRCQUEUE_H
#define HOMEWORK5_CIRCQUEUE_H

#include<iostream>
using std::cout;
using std::endl;

#include "linked_list.h"

class circQueue: public linked_list{

 private:
  linked_list * a;

 public:

  circQueue(){

    a = new linked_list;
  }

  //This function is the destructor for the cirqueue
  //It gets rid of the linked list memory, a, and this
  ~circQueue() {
    //Destruct linked list
    a->~linked_list();
    delete a,this;
  }

  //This functino displays the contents of the queue to the user
  //If the queue is empty, it will tell the user, as per instructions
  //If there are contents, it will display the queue contents
  void displayQueue() {
    if(a->getHeadPointer() == NULL)
      std::cout << "Queue is empty." << std::endl;
    if(a->getHeadPointer() != NULL)
      a->display();
  }

  //This function adds nodes to the tail of the queue when called upon
  void enqueue(int value){
    a->add_node(value);
  }

  //This function will remove nodes from the queue from the front of it
  //Cout statements made as per Greg's email
  int dequeue(){
    //Variables
   int b = 0;
    //Check if queue is empty
    if(a->getHeadPointer() == NULL)
    {
      //Give error statment
      std::cout<< "tree is empty, returning 0" << std::endl;
      return b;
    }else if(a->getHeadPointer() == a->getTailPointer()){
      // if dequeuing last node(one node left) get data from node to return it
      b = a->getTailPointer()->data;

      // delete head pointer
      delete a->getHeadPointer();
      // set the head pointer = null
      a->setHeadPointer(NULL);
      // set the tail pointer = null
      a->setTailPointer(NULL);
    }else{
      // if dequeuing any other node
      b= a->getHeadPointer()->data;
      //Delete the top node
          a->delTop();}
    return b;
  }
};//Close cirqueue
#endif //HOMEWORK5_CIRCQUEUE_H