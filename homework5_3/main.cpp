//
// Created by Samantha Coyle on 3/16/2018.
//

#include <iostream>
#include "palindrome.h"

#include <iostream>
using std::cout;
using std::endl;


int main (){

  //Test for palindrome
  //Variables
  int isPalindrome;
  std::string input = "abcba";

  //Get value from function
  isPalindrome = palindrome(input);

  //Palindrome
  if(isPalindrome == 0){
    std::cout << "This is a palindrome" << std::endl;
  }else if(isPalindrome == -1){
    //Not palindrome
    std::cout << "This is not a palindrome" << std::endl;
  }else if(isPalindrome == -2){
    //Invalid input from user
    std::cout << "Incorrect input" << std::endl;
  }

  //Test for palindrome
//Variables
  isPalindrome;
  input = "abababababa";

  //Get value from function
  isPalindrome = palindrome(input);

  //Palindrome
  if(isPalindrome == 0){
    std::cout << "This is a palindrome" << std::endl;
  }else if(isPalindrome == -1){
    //Not palindrome
    std::cout << "This is not a palindrome" << std::endl;
  }else if(isPalindrome == -2){
    //Invalid input from user
    std::cout << "Incorrect input" << std::endl;
  }

  //Test for palindrome
  //Variables
  input = "racecar";

  //Get value from function
  isPalindrome = palindrome(input);

  //Palindrome
  if(isPalindrome == 0){
    std::cout << "This is a palindrome" << std::endl;
  }else if(isPalindrome == -1){
    //Not palindrome
    std::cout << "This is not a palindrome" << std::endl;
  }else if(isPalindrome == -2){
    //Invalid input from user
    std::cout << "Incorrect input" << std::endl;
  }

  //Test for too few char
  //Variables
  input = "";

  //Get value from function
  isPalindrome = palindrome(input);

  //Palindrome
  if(isPalindrome == 0){
    std::cout << "This is a palindrome" << std::endl;
  }else if(isPalindrome == -1){
    //Not palindrome
    std::cout << "This is not a palindrome" << std::endl;
  }else if(isPalindrome == -2){
    //Invalid input from user
    std::cout << "Incorrect input" << std::endl;
  }

  //Test for too many char
  //Variables
  input = "lalskdjsdkljf;laksdjf;lkajsd;lfkjasdl;kfjalskdjflkajsdflkjasdklfjlkasjdfkljasdf";

  //Get value from function
  isPalindrome = palindrome(input);

  //Palindrome
  if(isPalindrome == 0){
    std::cout << "This is a palindrome" << std::endl;
  }else if(isPalindrome == -1){
    //Not palindrome
    std::cout << "This is not a palindrome" << std::endl;
  }else if(isPalindrome == -2){
    //Invalid input from user
    std::cout << "Incorrect input" << std::endl;
  }

  //Test for non palindrome
  //Variables
  input = "abcbae";

  //Get value from function
  isPalindrome = palindrome(input);

  //Palindrome
  if(isPalindrome == 0){
    std::cout << "This is a palindrome" << std::endl;
  }else if(isPalindrome == -1){
    //Not palindrome
    std::cout << "This is not a palindrome" << std::endl;
  }else if(isPalindrome == -2){
    //Invalid input from user
    std::cout << "Incorrect input" << std::endl;
  }

  //Return successfully
  return 0;

}