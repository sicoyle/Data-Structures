//
// Created by Samantha on 3/15/2018.
//

#ifndef HOMEWORK5_1_COMBINATIONS_H
#define HOMEWORK5_1_COMBINATIONS_H

#include <iostream>
#include <vector>
#include <algorithm>
using std::endl;
using std::cout;

//Provide prototypes for the function definitions for the problem
void isNegative(std::vector<int> &data);
void removeRepetition(std::vector<std::vector<int>> &data);
int largestValue(std::vector<int> &data);
std::vector<std::vector<int>> combo(std::vector<int> data, int r, int n);
void displayResult(std::vector<std::vector<int>> &combo);
int initialConditions(int r, int n);

//This function returns a vector of vectors for the combinations for n choose r
//While it may be super inefficient, it still works:)
std::vector<std::vector<int>> combo(std::vector<int> data, int r, int n) {
  //Make vector of vectors to store combinations
  std::vector<std::vector<int>> combinations;
  int index = 0;
  int initial = initialConditions(r,n);

  //Test for initial conditions
  if(initial == -1){
    std::cout << "Invalid n or r value, please enter positive value next time!"
              << std::endl;
    combinations.clear();
    return combinations;
  }else if(initial == 0){
    std::cout << "n < r which makes your result 0!" << std::endl;
    combinations.clear();
    return combinations;
  }

  if(n < 1 || n > 100)
  {
    std::cout << "Error: N out of bounds!" << std::endl;
    combinations.clear();
    return combinations;
  }
  else if(r < 1 || r > 99)
  {
    std::cout << "Error: R out of bounds!" << std::endl;
    combinations.clear();
    return  combinations;
  }

  //Sort the vector
  std::sort(data.begin(), data.end());

  //Check if values are negative
  isNegative(data);

  //Populate vector of vectors
  for (index; index < n; index++){
    //Make temporary vector
    std::vector<int> temporary;

    //Add elements to end of vector
    temporary.push_back(data[index]);
    combinations.push_back(temporary);
  }

  /*
   * This big blob of for loop ugliness gets the job done by basically making all of the different
   * sub problems that are possible of r length, and later deletes the vectors of size < r
   */
  for(int outer = 0 ; outer < r - 1 ; outer++){
    //Variables
    int temp_size = combinations.size();

    for(int inner = 0; inner < temp_size; inner++){
      //Temporary vectors to store data
      std::vector<int> temporary1;
      temporary1 = combinations[inner];

      for(int i =  temporary1.size() - 1; i < data.size(); i++){
        std::vector<int> temporary2;
        temporary2 = temporary1;

        //Add data to end of temporary 2 and combinations
        temporary2.push_back(data[i]);
        combinations.push_back(temporary2);

        //Clear temporary 2 for next loop usage
        temporary2.clear();
      }//Close inner inner for loop
    }//Close inner for loop

    //Variables for iterating through vector of vectors
    auto combination_iterator = combinations.begin();
    std::vector<std::vector<int>> smallerVector;

    //Work on getting rid of vectors of smaller size
    for(combination_iterator, index = 0; combination_iterator != combinations.end();
        combination_iterator++, index++){
      if(combinations[index].size() == outer + 2)
        smallerVector.push_back(combinations[index]);
    }

    //Reassign combinations value
    combinations = smallerVector;

    //Clear contents for next loop usage
    smallerVector.clear();
  }//End big blob of for loops

  //Sort vectors in combinations
  for(index = 0; index < combinations.size(); index++) {
    std::sort(combinations[index].begin(), combinations[index].end());
  }

  //Sort the combinations vector
  std::sort(combinations.begin(), combinations.end());

  //Get rid of duplicates
  removeRepetition(combinations);

  //Find highest value
  int biggestNumber = largestValue(data);
  int occurrenceArray[biggestNumber + 1] = {0};

  //Find occurrence amount of numbers
  for(index = 0; index <= biggestNumber; index++){
    for(int inner = 0; inner < data.size(); inner++){
      if(data[inner] == index){
        occurrenceArray[index]++;}
    }
  }

  //Temporary vector
  std::vector<std::vector<int>> mytemp;

  //Deletes vectors that exceed the number of occurrences from occurrence array
  for(int index = 0 ; index < biggestNumber + 1 ; index++){
    //Create new temporary vector each loop
    mytemp = combinations;
    combinations.clear();

    //Get proper count using counter var
    for (int inner = 0;inner < mytemp.size(); inner++){
      int counter = 0;
      for (int inn = 0; inn < mytemp[inner].size(); inn++){
        if (mytemp[inner][inn] == index)
          counter++;
      }

      //Add value to vector end if its count is less than the number of occurrences
      if (counter <= occurrenceArray[index])
        combinations.push_back(mytemp[inner]);
    }

    //Clear vector for next loop
    mytemp.clear();
  }//close outer loop

    displayResult(combinations);

  //Return vector of vector
  return combinations;
}

//This function goes in and displays the contents of the vector of vectors
void displayResult(std::vector<std::vector<int>> &combo){
    for(int outer = 0 ; outer < combo.size() ; outer++){
      for(int inner = 0 ; inner < combo[outer].size() ; inner++){
        std::cout << combo[outer][inner] << " ";
    }
      //Give new line between each set of numbers
      std::cout << std::endl;
  }//Close outer for loop
}

//This function provides the highest value of a number within the vector passed in as a parameter
int largestValue(std::vector<int> &data){
  //Variables
  int highest = 0;
  int index = 0;

  //Loop through vector to find highest value present
  for(index = 0 ; index < data.size() ; index++){
    if(highest < data[index])
      highest = data[index];
  }

  //Return highest value present
  return highest;
}

//This function goes through the vector of vector and deletes the values that are present
//more than one time
void removeRepetition(std::vector<std::vector<int>> &data){
  //Use iterator to go through vector of vectors
  auto iterator = data.begin();
  int index = 0;

  //Loop through vector of vectors and delete repeated numbers
  for (iterator, index; iterator != data.end(); iterator++, index++){
    while (data[index] == data[index + 1])
      data.erase(iterator + 1);
  }
}

//This function checks if there is a negative number present and notifies user if there is
//a negative value present
  void isNegative(std::vector<int> &data){
  //Create iterator for looping through data
  std::vector<int>::const_iterator iterator_one;

  //Loop through data searching for negative values
  for(iterator_one = data.begin(); iterator_one != data.end(); iterator_one++){
    if(*iterator_one < 0){
      //Notify if neg numb presnt
      cout << "This array contains negative numbers" << endl;
    }
  }//Close for loop
}

//This function tests the initial conditions for n and r values passed into the function
int initialConditions(int r, int n){
  //n and r are flipped here:(
  if(n < 0)
    return -1;
  else if(r < 0)
    return -1;
  else if (n < r)
    return 0;

  return 1;
}

#endif //HOMEWORK5_1_COMBINATIONS_H
