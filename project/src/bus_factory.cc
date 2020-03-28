#include "src/bus_factory.h"

Bus* BusFactory::Generate(std::string name) {
    if(type_ == "small") {
        return new SmallBus(name, outbound_, inbound_, speed_);
    } else if(type_ == "medium") {
        return new MediumBus(name, outbound_, inbound_, speed_);
    } else if(type_ == "large") {
        return new LargeBus(name, outbound_, inbound_, speed_);
    } else {
        std::cout << "type_: " << type_ << std::endl;
        throw "Type must be small, medium or large";
    }
}