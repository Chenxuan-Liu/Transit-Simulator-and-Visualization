/**
 * @file large_bus.h
 *
 * @copyright 2019 3081 Staff, All rights reserved.
 */
#ifndef LARGE_BUS_H_
#define LARGE_BUS_H_

#include <string>
#include "src/bus.h"

/**
 * @brief The sub class to generate the large bus.
 *
 * Calls to \ref LargeBus constructor to get a new instance of a largebus object
 */

class LargeBus:public Bus {
 public:
 /**
  * @brief Generation of a large bus with a name, route out and route in, and speed. 
  *
  * This function will call the bus constructor in Bus classes with capacity 90
  *
  * @param[in] bus name
  * @param[in] bus route goes outward
  * @param[in] bus route goes inward
  * @param[in] bus speed, default is 1
  *
  * @return Bus object with name, route in, route out, capacity, and speed.
  */
  LargeBus(std::string name, Route * out, Route * in,
          double speed):Bus(name, out, in, 90, speed) {}

/**
  * @brief Override the Report function in Bus classes print out related information
  *
  * This function will call the Bus override function and it will also print out the bus type and capacity.
  *
  */
  void Report(std::ostream&) override;
};
#endif  // LARGE_BUS_H_