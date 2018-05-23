//
// Created by Samantha on 3/18/2018.
//

#include <iostream>
#include <vector>
#include "MinQueue.h"

int main() {

  //Create class object for minQueue
  MinQueue myMinQueue;

  //Normal testing
  std::vector<int> test1 {52,66,10,91919,9};
  std::vector<int> test2 {1,5,0,90,10000,3};
  std::vector<int> test3 {5,4,3,2,1};

  //Test negatives
  std::vector<int> test4 {-1,-2,-9,-12,-6};

  //Test single values
  std::vector<int> test5 {-7};
  std::vector<int> test6 {0};

  //Test for duplicates
  std::vector<int> test7 {1,1,1,1,5};
  std::vector<int> test8 {1,0,1,1,1,5};

  //Use class object to run queuemin function
  myMinQueue.queueMin(test1);
  myMinQueue.queueMin(test2);
  myMinQueue.queueMin(test3);
  myMinQueue.queueMin(test4);
  myMinQueue.queueMin(test5);
  myMinQueue.queueMin(test6);
  myMinQueue.queueMin(test7);
  myMinQueue.queueMin(test8);

  return 0;
}