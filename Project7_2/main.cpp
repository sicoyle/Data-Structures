//Created by Samantha Coyle on 4/23/2018
#include<cstdio>
#include<vector>
#include<algorithm>
#include<iostream>
int main()
{
  //Variables
  int pancake[30];
  int flip_pos[50];
  int i;
  char cakes[150];
  int count = 0;
  int num = 0;
  int flip = 0;

  //Read in characters
  while (std::getline(std::cin, cakes))
  {
    //Loop through each character
    for (i = 0; cakes[i]; i++)
    {
      if (cakes[i] != ' ')
        num = num * 10 + cakes[i] - 0;
      else
      {
        pancake[count++] = num;
        num = 0;
      }
    }
    pancake[count++] = num;

    std::vector<int> v;
    //cake[0] is top
    for (i = count - 1; i >= 0; i--)
      v.push_back(pancake[i]);

    //v[0] is bottom
    for (i = 0; i < count; i++)
    {
      int max = v[i], pos = 0;
      for (int j = i + 1; j < count; j++)
        if (max < v[j])
        {
          max = v[j];
          pos = j;
        }

      if (pos)
      {
        if (pos != count - 1)
        {
          std::reverse(v.begin() + pos, v.end());
          flip_pos[flip++] = pos + 1;
        }

        std::reverse(v.begin() + i, v.end());
        flip_pos[flip++] = i + 1;
      }
    }

    //output
    std::cout << cakes;
    for (i = 0; i < flip; i++)
      printf("%d ", flip_pos[i]);
    std::cout << "0";

  }

  return 0;
}
