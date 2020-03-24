/**
 * @file bus_factory.cc
 *
 * @copyright 2019 3081 Staff, All rights reserved.
 */

#include <vector>
#include <random>
#include "src/bus_factory.h"

/*******************************************************************************
 * Member Functions
 ******************************************************************************/

Bus* BusFactory::Generate(std::string name, Route*
out, Route* in, int capacity, double speed) {
    if (capacity == 30) {
        Bus* smallbus = new SmallBus(name, out, in, speed);
        return smallbus;
    } else if (capacity == 90) {
        Bus* largebus = new LargeBus(name, out, in, speed);
        return largebus;
    } else {
        Bus* regularbus = new RegularBus(name, out, in, speed);
        return regularbus;
    }
}
