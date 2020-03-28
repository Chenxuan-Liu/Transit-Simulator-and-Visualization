#ifndef BUS_TYPES_H_
#define BUS_TYPES_H_

#include "./bus.h"

class SmallBus : public Bus {
    SmallBus(std::string name, Route* out, Route* in, double speed):
        Bus(name, out, in, 30, speed, "Small") { }
};

class MediumBus : public Bus {
    MediumBus(std::string name, Route* out, Route* in, double speed):
        Bus(name, out, in, 60, speed, "Medium") { }
};

class LargeBus : public Bus { 
    LargeBus(std::string name, Route* out, Route* in, double speed):
        Bus(name, out, in, 90, speed, "Large") { }
};

#endif 