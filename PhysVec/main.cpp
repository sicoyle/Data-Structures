#include "PhysVec.h"
#include <vector>
#include <iostream>

using std::cout;
using std::endl;

// Created by Samantha Coyle on 1/25/18.

// This main is used to test the physvec class.  It will provide
// vectors for the class to use in its calculation's.
//

int main() {

  // create some vectors - Note c++ 11 uniform initilization!
  std::vector<int> lhs = {3,2,1};
  std::vector<int> rhs = {1,2,3};
  std::vector<int> newrhs = {4,2,1};
  std::vector<int> newlhs = {1,2,5};
  std::vector<int> emptyvec = {0,0,0};

  //use simple constructor and set
  PhysVec myphysvec;
  myphysvec.setPhysVec(newlhs);
  myphysvec.printVecs();

  //use regular constructor
  PhysVec myphysvec2(newrhs);
  myphysvec2.printVecs();

  PhysVec myphysvec3(emptyvec);

  //test the overloading of the addition and the = operators
  myphysvec3 =  myphysvec2 + myphysvec;
  myphysvec3.printVecs();

  //test dot product
  int dotProduct = myphysvec2.calculateDotProduct(myphysvec3);
  cout << endl;
  cout << "Dot product is " << dotProduct << endl;

  //test copy constructor
  PhysVec myphysvec4(myphysvec2);
  cout << "myphysvec4 from copy constructor " << endl;
  myphysvec4.printVecs();

  //try bigger vecs than 3
  std::vector<int> biggervec1 = {1,2,3,4,5};

  std::vector<int> biggervec2 = {-1,-2,-3,-4,-5};

  PhysVec mybigvec1(biggervec1);

  PhysVec mybigvec2(biggervec2);

  mybigvec1.printVecs();
  mybigvec2.printVecs();

  dotProduct = mybigvec2.calculateDotProduct(mybigvec1);
  cout << endl;
  cout << "Dot product is " << dotProduct << endl;

  cout << "Here is myphysvec2 ";
  myphysvec2.printVecs();
  cout << endl;
  cout << "Here is mybigvec1 ";
  mybigvec1.printVecs();
  cout << endl;

  //try unequal vectors in dot product
  try {
    dotProduct = myphysvec2.calculateDotProduct(mybigvec1);
  }
  catch(const std::exception& e)
  {
    cout << "Caught!" << endl;
  }
  cout << "Dot product is " << dotProduct << endl;

  try{

    cout << "in try" << endl;
    myphysvec2.printVecs();
    mybigvec1.printVecs();
    myphysvec2 = mybigvec1;
    myphysvec2.printVecs();
    cout << "here" << endl;
  }
  catch(const std::exception& e)
  {
    cout << "Caught2" << endl;
  }

  try{
    myphysvec3 = myphysvec2 + biggervec1;
    myphysvec3.printVecs();

  }
  catch(const std::exception& e)
  {
    cout << "Success" << endl;
  }

  return 0;
}