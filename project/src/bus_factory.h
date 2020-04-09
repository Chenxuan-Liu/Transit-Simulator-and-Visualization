<<<<<<< HEAD
/**
 * @file bus_factory.h
 *
 * @copyright 2019 3081 Staff, All rights reserved.
 */
#ifndef BUS_FACTORY_H_
#define BUS_FACTORY_H_

#include <string>

#include "src/bus.h"
#include "src/small_bus.h"
#include "src/regular_bus.h"
#include "src/large_bus.h"

/**
 * @brief The main class to generate the bus.
 *
 * Calls to \ref Generate function to get a new instance of a bus object
 *  This is a static call, not requiring an instance to invoke the method.
 */
class BusFactory {
 public:
 /**
  * @brief Generation of a bus with a name, route out and route in, capacity, and speed. 
  *
  * This function/constructor will be used for simulation purposes.
  *
  * @param[in] bus name
  * @param[in] bus route goes outward
  * @param[in] bus route goes inward
  * @param[in] bus capacity, default is 60
  * @param[in] bus speed, default is 1
  *
  * @return Bus object with name, route in, route out, capacity, and speed.
  */
  static Bus * Generate(std::string name, Route* out,
  Route* in, double speed);
};
#endif  // BUS_FACTORY_H_
=======
#ifndef SRC_BUS_FACTORY_H_
#define SRC_BUS_FACTORY_H_

#include "./bus.h"
#include "./bus_types.h"

class BusFactory {
    public:
        BusFactory(std::string type, Route* outbound, Route* inbound, double speed) : 
            type_(type), outbound_(outbound), inbound_(inbound),  speed_(speed) { };
        Bus* Generate(std::string name);
    private:
        std::string type_;
        Route* inbound_;
        Route* outbound_;
        double speed_;
};

#endif 
>>>>>>> support-code
