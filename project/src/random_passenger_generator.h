/**
 * @file random_passenger_generator.h
 *
 * @copyright 2019 3081 Staff, All rights reserved.
 */

<<<<<<< HEAD
#ifndef RANDOM_PASSENGER_GENERATOR_H_
#define RANDOM_PASSENGER_GENERATOR_H_
=======
#ifndef SRC_RANDOM_PASSENGER_GENERATOR_H_
#define SRC_RANDOM_PASSENGER_GENERATOR_H_
>>>>>>> support-code

#include <list>
#include <random>
#include <ctime>

#include "src/passenger_generator.h"
#include "src/stop.h"

class Stop;  // forward declaration

class RandomPassengerGenerator : public PassengerGenerator{
 public:
  RandomPassengerGenerator(std::list<double>, std::list<Stop *>);
  int GeneratePassengers() override;

 private:
  static std:: minstd_rand0 my_rand;
};

<<<<<<< HEAD
#endif  // RANDOM_PASSENGER_GENERATOR_H_
=======
#endif  // SRC_RANDOM_PASSENGER_GENERATOR_H_
>>>>>>> support-code
