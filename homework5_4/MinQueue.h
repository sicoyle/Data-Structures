//
// Created by Samantha on 3/18/2018.
//

#ifndef HOMEWORK5_4_MINQUEUE_H
#define HOMEWORK5_4_MINQUEUE_H

#include <queue>
#include <stack>
#include "stack.h"
#include "cirQueue.h"

class MinQueue : public stack, public circQueue {

 public:
//This function displays the minimum value
  void displayMin(std::stack<std::pair<int, int>> s) {
    std::cout << "The min value in the queue is: " << s.top().second << std::endl;
  }

//This function gets the minimul value in the queue
  int queueMin(std::vector<int> vectorContents) {
    //variables to collect min, and use pair--as per directions
    std::pair<int, int> couple;

    //Make a queue that takes ints
    std::queue<int> myQueue;

    //Make a stack of pairs, <value, minVal>
    std::stack<std::pair<int, int>> myStack;

    //Other variables
    int minimumValue;
    int i = -1;

    //Loop through vector contents
    for (i = 0; i < vectorContents.size(); i++) {
      //Check if the stack is empty
      if (myStack.empty()) {
        //Initialize variables to vector contents
        minimumValue = vectorContents[i];
        couple.first = vectorContents[i];
        couple.second = minimumValue;

        //Push a pair <value, current min> onto stack
        myStack.push(couple);
      } else {
        //Stack has values in it and is not empty
        //Initialize variables to vector contents
        couple.first = vectorContents[i];

        //Check for minimum value
        if (couple.first < myStack.top().second)
          minimumValue = couple.first;

        //Keep minimum value
        couple.second = minimumValue;

        //Push to the stack the couple
        myStack.push(couple);
      }
      //Enqueue value into the queue using push
      myQueue.push(vectorContents[i]);
    }

    //Display the contents of the minimum value from data structure
    displayMin(myStack);

    //return the minimum number
    return myStack.top().second;
  }
};
#endif //HOMEWORK5_4_MINQUEUE_H
