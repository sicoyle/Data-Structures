//
// Created by Greg LaKomski on 2/25/18.
//

#ifndef HOMEWORK5_STACK_H
#define HOMEWORK5_STACK_H

#include<iostream>
using std::cout;
using std::endl;
#include "linked_list.h"

class stack : public linked_list{

 private:
  linked_list * a;

 public:

  stack(){

    a = new linked_list;
  }

  void displayStack(){

    a->display(a->getHeadPointer());
    a->display();
  }

  void push(int value){
    if(a->getHeadPointer() != NULL){
      a->front(value);
    }else{
      a->add_node(value);
    }
  }

  int pop(){
    if(a->getHeadPointer() != NULL){
      int tmpval = a->getHeadPointer()->data;
      a->delTop();
      return(tmpval);
    }
  }

};

#endif //HOMEWORK5_STACK_H