//
// Created by Samantha Coyle on 2/18/2018.
//

#ifndef HOMEWORK4_4_TURBO_H
#define HOMEWORK4_4_TURBO_H

#include "Motor.h"
class Turbo : public Motor{
 public:
  Turbo(int Cylinders,
          int Displacement,
          int Boost,
          int FuelOctane,
          int Horsepower,
          int Torque);
 private:
  int Boost;
  int FuelOctane;
  int Horsepower;
  int Torque;


};


#endif //HOMEWORK4_4_TURBO_H
