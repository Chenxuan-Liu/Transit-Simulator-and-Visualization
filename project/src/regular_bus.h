/**
 * @file regular_bus.h
 *
 * @copyright 2019 3081 Staff, All rights reserved.
 */
#ifndef REGULAR_BUS_H_
#define REGULAR_BUS_H_

#include <string>
#include "src/bus.h"

/**
 * @brief The sub class to generate the regular bus.
 *
 * Calls to \ref RegularBus constructor to get a new instance of a regular bus object
 */
class RegularBus:public Bus {
 public:
 /**
  * @brief Generation of a regular bus with a name, route out and route in, and speed. 
  *
  * This function will call the bus constructor in Bus classes with capacity 60
  *
  * @param[in] bus name
  * @param[in] bus route goes outward
  * @param[in] bus route goes inward
  * @param[in] bus speed, default is 1
  *
  * @return Bus object with name, route in, route out, capacity, and speed.
  */
  RegularBus(std::string name, Route * out, Route * in,
          double speed):Bus(name, out, in, 60, speed) {}


/**
  * @brief Override the Report function in Bus classes print out related information
  *
  * This function will call the Bus override function and it will also print out the bus type and capacity.
  *
  */
  void Report(std::ostream&) override;
};
#endif  // REGULAR_BUS_H_