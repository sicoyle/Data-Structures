//
// Created by Samantha Coyle on 1/25/2018.
//

//This file provides the implementation of the PhysVec.h header file
#include <iostream>
#include <vector>
#include "PhysVec.h"
using std::cout;
using std::endl;

//Default constructor for a vector with no arguments
PhysVec::PhysVec(){
}

//This function takes in a vector as input and creates a PhysVec vector
//for the output
PhysVec::PhysVec(const std::vector<int> &input_vec){
  (*this).a_vec_ = input_vec;
}

//This function is a copy constructor that takes in a PhysVec reference object
PhysVec::PhysVec(const PhysVec &rhs){
  a_vec_ = rhs.a_vec_;
}

//This function will iterate through the vectors to copy them
//element by element and will return an object reference
//aka an instance pointer
PhysVec &PhysVec::operator= (const PhysVec & rhs){
  //Check if they are already equal
  if(this == &rhs) {
    return *this;
  }

//  if(rhs.a_vec_.size() > this->a_vec_.size())
//    this->a_vec_.resize(rhs.a_vec_.size());
  cout << "rhs.a_vec_.size() " << rhs.a_vec_.size() << endl;
  //Resize vector if sizes !=
  if(rhs.a_vec_.size() > this->a_vec_.size())
    this->a_vec_.resize(rhs.a_vec_.size());

    //Test to see if the vectors are the same size
    if (this->a_vec_.size() != rhs.a_vec_.size()) {
      throw std::invalid_argument("Vectors are not the same length "
                                      "and you are trying to take the assign vectors");
    }



  //Create the iterators
  //First one is const because rhs is const
  std::vector<int>::const_iterator iterator_one;
  std::vector<int>::iterator iterator_two;

  //Deep copy
  //Loop through the vectors and set the rhs element equal to the lhs element
  for(iterator_one = rhs.a_vec_.begin(), iterator_two = this->a_vec_.begin();
      iterator_one != rhs.a_vec_.end(), iterator_two != this->a_vec_.end();
      iterator_one++, iterator_two++){
    *iterator_two = *iterator_one;
  }

  return *this;
}

//This function will add the same elements in 2 vectors and
//place the sum into a 3rd vector
PhysVec PhysVec::operator+ (const PhysVec & rhs) const{
  //Throw a runtime error if the vectors are of different sizes
  if(this->a_vec_.size() != rhs.a_vec_.size())
    throw std::runtime_error("The vectors are of different sizes; thus,"
                                 "they can NOT be added together.");

  //If vectors are same size, create a 3rd vector to store the result of the addition
  PhysVec addition_result_vector(rhs);

  //Create the iterators to be able to access the elements in a vector
  std::vector<int>::const_iterator iterator_one = this->a_vec_.begin();               //lhs
  std::vector<int>::const_iterator iterator_two = rhs.a_vec_.begin();                 //rhs
  std::vector<int>::iterator iterator_three = addition_result_vector.a_vec_.begin();  //result

  //Loop through and do the addition for each element and store result in result vecot
  while(iterator_two != rhs.a_vec_.end()){
    cout << "vector contents: " << *iterator_one << " + " << *iterator_two;
    (*iterator_three) = (*iterator_one) + (*iterator_two);
    cout << " = " << *iterator_three << endl;

    //Increment iterators to next element in vectors
    iterator_one++;
    iterator_two++;
    iterator_three++;
  }

    return addition_result_vector;
}

//This function will be used to figure out the dot product
//using 2 iterators
int PhysVec::calculateDotProduct(const PhysVec & rhs) const{
  auto dot_product_result = 0;

    //Throw exception if the vectors are of different length
    if (this->a_vec_.size() != rhs.a_vec_.size()) {
      throw std::invalid_argument("vectors are not the same length and you are trying to "
                                      "take the dot product");
    }

  //Create iterators for vectors
  std::vector<int>::const_iterator iterator_one = this->a_vec_.begin();
  std::vector<int>::const_iterator iterator_two = rhs.a_vec_.begin();

  //Loop through each vector element by element
  while((iterator_one != a_vec_.end()) && (iterator_two != rhs.a_vec_.end())){
    dot_product_result += ((*iterator_one) * (*iterator_two));

    //Increment vector element iterators
    iterator_one++;
    iterator_two++;
  }

  return dot_product_result;
}

//This function is a getter function. It will turn a PhysVec
//vector into a normal vector
std::vector<int> &PhysVec::get_a_vec_(){
  return this->a_vec_;
}

//This function will print out a vector. It must iterate
//through each element to print out each part of the vector
void PhysVec::printVecs() const{
  cout << "Vector contents: " << endl;

  //Create iterator for vector
  std::vector<int>::const_iterator vector_iterator = this->a_vec_.begin();

  //Loop through until end of vector to print out content
  while(vector_iterator != a_vec_.end()) {
    cout << *vector_iterator << ' ';
    vector_iterator++;
  }

  //New line for readablility
  cout << endl;
}

//This function is a setter function. It will create a non constant
//PhysVec.
void PhysVec::setPhysVec(const std::vector<int> &input_vec){
  (*this).a_vec_ = input_vec;
}









