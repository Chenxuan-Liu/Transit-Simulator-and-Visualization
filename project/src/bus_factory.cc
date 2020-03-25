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
out, Route* in, double speed) {
    std::random_device dev;
    std::mt19937 rng(dev());
    std::uniform_int_distribution<std::mt19937::result_type> dist1(1, 3);
    int rand_int = dist1(rng);
    if (rand_int == 1) {
        Bus* smallbus = new SmallBus(name, out, in, speed);
        return smallbus;
    } else if (rand_int == 2) {
        Bus* largebus = new LargeBus(name, out, in, speed);
        return largebus;
    } else {
        Bus* regularbus = new RegularBus(name, out, in, speed);
        return regularbus;
    }
}
