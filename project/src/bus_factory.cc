/**
 * @file bus_factory.cc
 *
 * @copyright 2019 3081 Staff, All rights reserved.
 */


#include "src/bus_factory.h"

#include <ctime>

Bus* BusFactory::Generate(std::string name) {
    if (type_ == "small") {
        return new SmallBus(name, outbound_, inbound_, speed_);
    } else if (type_ == "medium") {
        return new MediumBus(name, outbound_, inbound_, speed_);
    } else if (type_ == "large") {
        return new LargeBus(name, outbound_, inbound_, speed_);
    } else {
        std::cout << "type_: " << type_ << std::endl;
        throw "Type must be small, medium or large";
    }
}

static int counter1 = 0;
static int counter2 = 0;
static int counter3 = 0;

class Strategy1:public Strategy {
 public:
  Bus* ReFacterBusFactory(std::string name, Route* outbound, Route*
        inbound, double speed) override {
    while (1){
        if (counter1 % 2 == 0) {
            counter1++;
            return new SmallBus(name, outbound, inbound, speed);
        } else {
            counter1++;
            return new MediumBus(name, outbound, inbound, speed);
        }
    }
  }
};

class Strategy2:public Strategy {
 public:
  Bus* ReFacterBusFactory(std::string name, Route* outbound, Route*
        inbound, double speed) override {
    while (1){
        if (counter2 % 2 == 0) {
            counter2++;
            return new MediumBus(name, outbound, inbound, speed);
        } else {
            counter2++;
            return new LargeBus(name, outbound, inbound, speed);
        }
    }
  }
};

class Strategy3:public Strategy {
 public:
  Bus* ReFacterBusFactory(std::string name, Route* outbound, Route*
        inbound, double speed) override{
    while (1){
      if (counter3 % 3 == 0) {
        counter3++;
        return new SmallBus(name, outbound, inbound, speed);
      } else if (counter3 % 3 == 1) {
        counter3++;
        return new MediumBus(name, outbound, inbound, speed);
      } else {
        counter3++;
        return new LargeBus(name, outbound, inbound, speed);
      }
    }
  }
};

Bus* BusDepot::generate() {
    time_t timer = time(NULL);
    struct tm* now = localtime(&timer);
    int time = now -> tm_hour;


    Strategy* strategy[3];
    strategy[0] = new Strategy1;
    strategy[1] = new Strategy2;
    strategy[2] = new Strategy3;

    if (time >= 6 && time < 8) {
        return strategy[0] ->
            ReFacterBusFactory(name_, outbound_, inbound_, speed_);
    } else if (time >= 8 && time < 15) {
       return strategy[1] ->
            ReFacterBusFactory(name_, outbound_, inbound_, speed_);
    } else if (time >= 15 && time < 20) {
        return strategy[2] ->
            ReFacterBusFactory(name_, outbound_, inbound_, speed_);
    } else {
        return new Bus(name_,
                outbound_, inbound_, 30, 1);
    }
}
