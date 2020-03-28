#ifndef SRC_BUS_FACTORY_H_
#define SRC_BUS_FACTORY_H_

#include "./bus.h"
#include "./bus_types.h"

class BusFactory {
    public:
        BusFactory(std::string type, Route* inbound, Route* outbound, double speed) : 
            type_(type), inbound_(inbound), outbound_(outbound), speed_(speed) { }
        Bus* Generate();
    private:
        std::string type_;
        Route* inbound_;
        Route* outbound_;
        double speed_;
}

#endif 