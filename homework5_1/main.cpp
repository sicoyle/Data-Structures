//
// Created by Samantha on 3/15/2018.
//

#include <iostream>
#include "combinations.h"

int main() {
  std::cout << "First" <<endl;
  std::vector<int> data{1,2,3,4,5};
  auto results = combo(data,3,5);

  std::cout << endl << "Second" << endl;
  // Testing smallest valid N and R
  results = combo(data,1,1);

  std::cout <<endl << "Third" << endl;
// Testing largest Valid N and R
  results = combo(data, 99,100);
  std::cout <<endl;

// Testing bad input - neg numbers
  results = combo(data, -1,5);

  //Test for n>r
  std::cout << endl << "4th" << endl;
  results = combo(data, 5,3);
  return 0;
}