//
// Created by Samantha Coyle on 2/18/2018.
//

#include "Turbo.h"

Turbo::Turbo(int Cylinders,
             int Displacement,
             int boost,
             int fuelOctane,
             int horsepower,
             int torque) : Motor(Cylinders, Displacement), Boost(boost),
                           FuelOctane(fuelOctane),
                           Horsepower(horsepower), Torque(torque) {}
