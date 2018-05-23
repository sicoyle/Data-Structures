//Created by Samantha Coyle on 4/23/2018
#include <iostream>
#include <vector>
#include <cstdio>
#include <limits>
#include <iomanip>
#include <iterator>

//This function gets the starting and end time
std::pair<int,int> timing(int start_hour, int start_minute, int end_hour, int end_minute){
  //Variables
  const int MINIMUM_HOURS = 10;
  const int MINUTES_PER_HOUR = 60;

  int start = ((start_hour - MINIMUM_HOURS) * MINUTES_PER_HOUR) + start_minute;
  int end = ((end_hour - MINIMUM_HOURS) * MINUTES_PER_HOUR) + end_minute;

  //Return the pair
  return std::make_pair(start,end);
}

int main() {
  //Get total time available
  //using time stipulations and minutes per hour
  int TOTAL_TIME = (18-10) * 60;

  //Variables
  std::vector<bool> availability(TOTAL_TIME + 2);
  availability[TOTAL_TIME + 1] = false;
  int day{1};
  int input_amount = 0;
  int start_hour, start_minute, end_hour, end_minute, start, end;
  char colon = ':';
  std::string trash;
  int longest_nap{0};
  int best_start{0};

  //Read in user input
  while(std::cin >> input_amount) {

    //Set bool vector to true/false on if time is available for nap
    for (int index = 0; index <= TOTAL_TIME; ++index)
      availability[index] = true;

    while (input_amount--) {
      //Read stuff in
      std::cin >> start_hour >> colon >> start_minute >> end_hour >> colon >> end_minute;
      getline(std::cin, trash);

      //Make pair for start/end time
      std::pair<int, int> time = timing(start_hour, start_minute, end_hour, end_minute);

      for (int starting_point = time.first; starting_point < time.second; starting_point++)
        availability[starting_point] = false;
    }

    for (int index = 0; index <= TOTAL_TIME; ++index)
    {
      //If time is available, then enter
      if (availability[index])
      {
        int tmp = index + 1;

        while (availability[tmp])
          ++tmp;

        //End case
        if (tmp == TOTAL_TIME + 1)
          --tmp;

        if (tmp - index > longest_nap)
        {
          best_start = index;
          longest_nap = tmp - index;
        }

        index = tmp;
      }
    }


    if (longest_nap >= 60)
      printf("Day #%d: the longest nap starts at %d:%02d and will last for %d hours and %d minutes.\n",
             day++, best_start / 60 + 10, best_start % 60, longest_nap / 60, longest_nap % 60);
    else
      printf("Day #%d: the longest nap starts at %d:%02d and will last for %d minutes.\n",
             day++, best_start / 60 + 10, best_start % 60, longest_nap);










  }


  return 0;
}

