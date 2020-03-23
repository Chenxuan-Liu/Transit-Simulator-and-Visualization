/**
 * @file bus_factory.h
 *
 * @copyright 2019 3081 Staff, All rights reserved.
 */
#ifndef SRC_BUS_FACTORY_H_
#define SRC_BUS_FACTORY_H_

#include <string>

#include "src/bus.h"
#include "src/small_bus.h"
#include "src/regular_bus.h"
#include "src/large_bus.h"

class BusFactory {
 public:
  static Bus * Generate(std::string name, Route* out, Route* in, int capacity, double speed);
};
#endif  // SRC_BUS_FACTORY_H_
