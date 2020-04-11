/**
 * @file bus_factory.h
 *
 * @copyright 2019 3081 Staff, All rights reserved.
 */

#ifndef SRC_BUS_FACTORY_H_
#define SRC_BUS_FACTORY_H_

#include <string>

#include "./bus.h"
#include "./bus_types.h"



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
        BusFactory(std::string type, Route* outbound, Route*
        inbound, double speed) :
            type_(type), outbound_(outbound), inbound_(inbound),
            speed_(speed) { }
        Bus* Generate(std::string name);

 private:
        std::string type_;
        Route* inbound_;
        Route* outbound_;
        double speed_;
};


class BusDepot {
 public:
  BusDepot(std::string name, Route* outbound, Route*
        inbound, double speed): name_(name), outbound_(outbound),
            inbound_(inbound), speed_(speed) { }
  // virtual BusFactory* ReFacterBusFactory() = 0;
  Bus * generate();
 protected:
    std::string name_;
    Route* inbound_;
    Route* outbound_;
    double speed_;
};

class Strategy {
 public:
  virtual Bus * ReFacterBusFactory(std::string name, Route* outbound, Route*
        inbound, double speed) = 0;
};




#endif   // SRC_BUS_FACTORY_H_
