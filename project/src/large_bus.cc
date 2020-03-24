/**
 * @file large_bus.cc
 *
 * @copyright 2019 3081 Staff, All rights reserved.
 */
#include "src/large_bus.h"

void LargeBus::Report(std::ostream& out) {
    out << "Bus type: Large Bus"<< std::endl;
    out << "Bus capacity" << GetCapacity() << std::endl;
    Bus::Report(out);
}
