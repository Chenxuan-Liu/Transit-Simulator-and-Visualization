/**
 * @file rtest_passenger_generator.h
 *
 * @copyright 2019 3081 Staff, All rights reserved.
 */

#ifndef SRC_RTEST_PASSENGER_GENERATOR_H_
#define SRC_RTEST_PASSENGER_GENERATOR_H_

#include <list>
#include <random>
#include <ctime>

#include "src/passenger_generator.h"
#include "src/stop.h"

class Stop;  // forward declaration

/**
 * @brief 
 *
 * Calls to \ref GeneratePassengers function to get a random passenger
 * This function is override function.
 */
class RtestPassengerGenerator : public PassengerGenerator{
 public:
/**
  * @brief Random generation of a passenger. 
  *
  * This is a constructor.
  *
  * @param[in] passenger distance
  * @param[in] stop iter
  * 
  * @return none
  */
  RtestPassengerGenerator(std::list<double>, std::list<Stop *>);
/**
  * @brief Random generation of a passenger. 
  *
  * This is a constructor.
  *
  * @param none
  * 
  * @return integer of how many passenger are added
  */
  int GeneratePassengers() override;

 private:
  static std:: minstd_rand0 my_rand;
};

#endif  // SRC_RTEST_PASSENGER_GENERATOR_H_
