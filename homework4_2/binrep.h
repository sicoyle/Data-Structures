//
// Created by Samantha Coyle on 2/18/2018.
//

#ifndef HOMEWORK4_2_BINREP_H
#define HOMEWORK4_2_BINREP_H

int NumberOfOnes(int n)
{
  //Get base case out of the way
  if (n == 0)
    return 0;
  else if (n == 1)
    return 1;
  else if((n%2) == 1)
    return (NumberOfOnes(n/2) + 1);
  else
    return (NumberOfOnes(n/2));
}

#endif //HOMEWORK4_2_BINREP_H
