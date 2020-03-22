/**
 * @file passenger_factory.h
 *
 * @copyright 2019 3081 Staff, All rights reserved.
 */
<<<<<<< HEAD
#ifndef PASSENGER_FACTORY_H_
#define PASSENGER_FACTORY_H_
=======
#ifndef SRC_PASSENGER_FACTORY_H_
#define SRC_PASSENGER_FACTORY_H_
>>>>>>> support-code

#include <string>

#include "src/passenger.h"

class PassengerFactory {
 public:
  static Passenger * Generate(int, int);
 private:
  static std::string NameGeneration();
};
<<<<<<< HEAD
#endif  // PASSENGER_FACTORY_H_
=======
#endif  // SRC_PASSENGER_FACTORY_H_
>>>>>>> support-code
