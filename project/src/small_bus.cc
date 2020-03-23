/**
 * @file small_bus.cc
 *
 * @copyright 2019 3081 Staff, All rights reserved.
 */
#include "src/small_bus.h"

void SmallBus::Report(std::ostream& out){
    out << "Bus type: Small Bus"<< std::endl;
    out << "Bus capacity" << GetCapacity() << std::endl;
    Bus::Report(out);
};
