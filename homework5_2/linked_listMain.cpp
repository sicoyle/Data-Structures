//
// Created by Samantha on 3/16/2018.
//

#ifndef HOMEWORK5_STACK_H
#define HOMEWORK5_STACK_H
#include "linked_list.h"
#include <iostream>
using std::cout;
using std::endl;

int main (){
  //Create testing linked lists
  std::cout << "linked list 1: " << endl;
  linked_list ll;
  ll.add_node(1);
  ll.add_node(2);
  ll.display();

  //Test copy constructor
  //Success!
  std::cout << "check for copy constructor: ll2 = l1" << endl;
  linked_list ll2(ll);

  std::cout << "ll2:" << endl;
  ll2.display();
  std::cout << endl;


  //Check for operator = functionality for same linked list
  linked_list checker;
  checker.add_node(5);
  checker.add_node(9);
  std::cout << "checker: " << endl;
  checker.display();
  std::cout << endl;
  checker = ll2;
  std::cout << "checker contents after assignment" << endl;
  checker.display();


  return 0;
}

#endif //HOMEWORK5_STACK_H