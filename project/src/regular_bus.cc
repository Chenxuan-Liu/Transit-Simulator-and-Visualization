/**
 * @file regular_bus.cc
 *
 * @copyright 2019 3081 Staff, All rights reserved.
 */
#include "src/regular_bus.h"

void RegularBus::Report(std::ostream& out){
    out << "Bus type: Regular Bus"<< std::endl;
    out << "Bus capacity" << GetCapacity() << std::endl;
    Bus::Report(out);
};
