//
// Created by Samantha Coyle on 3/16/2018.
//
#include <stack>
#include <queue>
#include <algorithm>
#include <iostream>
#ifndef HOMEWORK5_3_PALINDROME_H
#define HOMEWORK5_3_PALINDROME_H

//This function tests if a word inputted is the same forwards as it is backwards.
int palindrome(std::string inputString){
  //Ensure string is between 1 and 50 characters
  //Doesn't say inclusive in directions
  if((inputString.length() > 50 || inputString.length() < 1)){
    return -2;
  }else{
    //String length okay
    //Create queue and stack
    std::queue<char> myQueue;
    std::stack<char> myStack;

    //Use for each to push char onto queue and stack as per instructions for this problem
    std::for_each(inputString.begin(),inputString.end(),[&myQueue](char &i){myQueue.push(i);});
    std::for_each(inputString.begin(),inputString.end(),[&myStack](char &i){myStack.push(i);});

    //Loop through queue and stack until they are both empty
    while (!(myQueue.empty() && myStack.empty())){
      //Check the top of the stack and the front of the queue for if they are equivalent values
      if (myStack.top() == myQueue.front()){
        //Remove values if equivalent values
        myQueue.pop();
        myStack.pop();
      }else{return -1;}//Different values->non palidrome tell-tell
    }//wihle

    //Successful return for palindrome
    return 0;
  }//else
}//function

#endif //HOMEWORK5_3_PALINDROME_H