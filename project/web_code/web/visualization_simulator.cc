
/**
 * @file visualization_simulator.cc
 *
 * @copyright 2019 3081 Staff, All rights reserved.
 */

#include <iostream>
#include <ctime>

#include "web_code/web/visualization_simulator.h"

#include "src/bus.h"
#include "src/route.h"



VisualizationSimulator::VisualizationSimulator(WebInterface*
    webI, ConfigManager* configM, std::ostream* out) {
    webInterface_ = webI;
    configManager_ = configM;
    paused_ = false;
    out_ = out;
}

VisualizationSimulator::~VisualizationSimulator() {}

void VisualizationSimulator::TogglePause() {
    std::cout << "Toggling Pause" << std::endl;
    paused_ = !paused_;
}

void VisualizationSimulator::Start(const std::vector<int>&
    busStartTimings, const int& numTimeSteps) {
    busStartTimings_ = busStartTimings;
    numTimeSteps_ = numTimeSteps;

    timeSinceLastBus_.resize(busStartTimings_.size());
    for (int i = 0; i < static_cast<int>(timeSinceLastBus_.size()); i++) {
        timeSinceLastBus_[i] = 0;
    }

    simulationTimeElapsed_ = 0;

    prototypeRoutes_ = configManager_->GetRoutes();
    for (int i = 0; i < static_cast<int>(prototypeRoutes_.size()); i++) {
        prototypeRoutes_[i]->Report(*out_);

        prototypeRoutes_[i]->UpdateRouteData();
        webInterface_->UpdateRoute(prototypeRoutes_[i]->GetRouteData());
    }
}

bool VisualizationSimulator::Update() {
    // Code called to update simulator. Will first check if
    // we are in a state where we can update (e.g., not paused, not finished)
    // then call ExecuteUpdate() to actually call update if possible
    // return whether or not ExecuteUpdate() was called
    bool can_update = CanUpdate();
    if (can_update) {
        ExecuteUpdate();
    }
    return can_update;
}

bool VisualizationSimulator::CanUpdate() {
    // Check whether or not simulator can update
    // maybe unable to update because paused, terminated, etcetra
    // only cares about whether or not it is paused right now
    return !paused_;
}

void VisualizationSimulator::ExecuteUpdate() {
    // This function has the same text as what Update() used to have
    // I added a gating mechanism for pause functionality
    simulationTimeElapsed_++;

    std::cout << "~~~~~~~~~~ The time is now " << simulationTimeElapsed_;
    std::cout << "~~~~~~~~~~" << std::endl;

    std::cout << "~~~~~~~~~~ Generating new busses if needed ";
    std::cout << "~~~~~~~~~~" << std::endl;


    // Check if we need to generate new busses
    for (int i = 0; i < static_cast<int>(timeSinceLastBus_.size()); i++) {
        // Check if we need to make a new bus
        if (0 >= timeSinceLastBus_[i]) {
            Route * outbound = prototypeRoutes_[2 * i];
            Route * inbound = prototypeRoutes_[2 * i + 1];

            BusDepot* busdepot = new BusDepot(std::to_string(busId),
                outbound->Clone(), inbound->Clone(), 1);

            busses_.push_back(busdepot -> generate());
            busId++;
            timeSinceLastBus_[i] = busStartTimings_[i];
        } else {
            timeSinceLastBus_[i]--;
        }
    }

    std::cout << "~~~~~~~~~ Updating busses ";
    std::cout << "~~~~~~~~~" << std::endl;
    FileWriterManager *fwm = new FileWriterManager;
    FileWriter *fw = fwm -> Getinstance();
    // Update busses
    for (int i = static_cast<int>(busses_.size()) - 1; i >= 0; i--) {
        busses_[i]->Update();
        // set the color to bus
        if (busses_[i] -> checkState()) {
            IBus * coloredbus = new BusDecorator(busses_[i]);
            coloredbus -> setColor(255, 223, 0, 250);
        } else {
            IBus * coloredbus = new BusDecorator(busses_[i]);
            coloredbus -> setColor(128, 0, 0, 250);
        }
        // set color density
        int numPass = static_cast<int>(busses_[i] -> GetNumPassengers());
        int capacity = busses_[i] -> GetCapacity();
        busses_[i] -> setDensity(50 + ((numPass/capacity) * 250));

        if (busses_[i]->IsTripComplete()) {
            webInterface_->UpdateBus(busses_[i]->GetBusData(), true);
            busses_[i] -> ClearPassenger();
            std::ostringstream foo;
            busses_[i]->Report(foo);
            std::vector<std::string> output = Util::processOutput(foo);
            fw->Write(bus_stats_file_name, output);
            busses_.erase(busses_.begin() + i);
            continue;
        }

        webInterface_->UpdateBus(busses_[i]->GetBusData());
        busses_[i]->Report(*out_);
    }

    // if (simulationTimeElapsed_ == numTimeSteps_) {
    //     for (int i = static_cast<int>(busses_.size()) - 1; i >= 0; i--) {
    //         busses_[i] -> ClearPassenger();
    //         std::ostringstream boo;
    //         busses_[i]->Report(boo);
    //         fw->Write(bus_stats_file_name, Util::processOutput(boo));
    //     }
    // }

    std::cout << "~~~~~~~~~ Updating routes ";
    std::cout << "~~~~~~~~~" << std::endl;
    // Update routes
    for (int i = 0; i < static_cast<int>(prototypeRoutes_.size()); i++) {
        prototypeRoutes_[i]->Update();

        webInterface_->UpdateRoute(prototypeRoutes_[i]->GetRouteData());

        prototypeRoutes_[i]->Report(*out_);
    }
}

void VisualizationSimulator::ClearListeners() {
    if (paused_ != true) {
        for (int i = static_cast<int>(busses_.size()) - 1; i >= 0; i--) {
            busses_[i] -> ClearObservers();
        }
    }
}

void VisualizationSimulator::ClearListenersStop() {
    if (paused_ != true) {
      for (std::vector<Route*> :: iterator iter = prototypeRoutes_.begin();
        iter !=prototypeRoutes_.end(); ++iter) {
            std::list <Stop*> stops = (*iter)->GetStops();
        for (std::list<Stop*> :: iterator it = stops.begin();
            it != stops.end(); ++it) {
                (*it)->ClearObservers();
            }
      }
    }
}


void VisualizationSimulator::AddListeners(std::string*
    id, IObserver<BusData*>* observer) {
    for (int i = static_cast<int>(busses_.size()) - 1; i >= 0; i--) {
        std::string test = *id;
        if (test.compare(busses_[i] -> GetBusData().id)) {
            busses_[i] -> RegisterObserver(observer);
        }
    }
}

void VisualizationSimulator::AddListenerStop(
    std::string* id, IObserver<Stop*>* observer) {
  // loop through the bus list
  for (std::vector<Route*> :: iterator r = prototypeRoutes_.begin();
        r !=prototypeRoutes_.end(); ++r) {
           std::list <Stop*> stops = (*r)->GetStops();
        for (std::list <Stop*> :: iterator it = stops.begin();
            it != stops.end(); ++it) {
            std::string strNew = *id;  // convert string pointer
            // check id
            // if equal, add observer to this bus
            if ((*it)->GetId() == std::stoi(strNew)) {
                (*it)->RegisterObserver(observer);
            }
        }
    }
}


// void VisualizationSimulator::Pause() {
//     pausestate = !pausestate;
// }
