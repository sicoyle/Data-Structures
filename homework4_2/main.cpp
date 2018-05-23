#include <iostream>
#include "binrep.h"
int main() {
  std::cout << "The number of 1's for N equal to " << '0' << " is " << NumberOfOnes(0) << std::endl;
  std::cout << "The number of 1's for N equal to " << '1' << " is " <<  NumberOfOnes(1) << std::endl;
  std::cout << "The number of 1's for N equal to " << "25" << " is " <<  NumberOfOnes(25) << std::endl;
  std::cout << "The number of 1's for N equal to " << "40" << " is " << NumberOfOnes(40) << std::endl;
  std::cout << "The number of 1's for N equal to " << "50" << " is " <<  NumberOfOnes(50) << std::endl;
  std::cout << "The number of 1's for N equal to " << "100" << " is " << NumberOfOnes(100) << std::endl;
  std::cout << "The number of 1's for N equal to " << "100000" << " is " <<  NumberOfOnes(100000) << std::endl;
  std::cout << "The number of 1's for N equal to " << "100000000" << " is " <<  NumberOfOnes(100000000) << std::endl;


  return 0;
}