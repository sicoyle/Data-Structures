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

  ~circQueue() {
    //Destruct the linked list
    a->~linked_list();
    //Destruct objects
    delete a,this;
  }

  void displayQueue() {
    //Display if queue is empty, or display contents
    if(a->getHeadPointer() == NULL)
      std::cout << "In display function: Queue is empty." << std::endl;
    else
      a->display();
  }

  void enqueue(int value){
    //Add node to the tail of the queue
    a->add_node(value);
  }

  int dequeue(){
    //Remove from the front
    int b = 0;
    //Check if queue is empty
    //Give cout statment Greg wants
    if(a->getHeadPointer() == NULL)
    {
      std::cout<< "tree is empty, returning 0" << std::endl;
      return b;
    }else if(a->getHeadPointer() == a->getTailPointer()) {
      // if dequeuing last node - meaning there is only one node left to dequeue
      // get the data from the node so you can return it
      b = a->getTailPointer()->data;

      // delete the head pointer
      delete a->getHeadPointer();
      // set the head pointer to null
      a->setHeadPointer(NULL);
      // set the tail pointer to null
      a->setTailPointer(NULL);
    }else{
      // if dequeuing any other node

      b= a->getHeadPointer()->data;
      a->delTop();}
    return b;
  }


};
#endif //HOMEWORK5_CIRCQUEUE_H