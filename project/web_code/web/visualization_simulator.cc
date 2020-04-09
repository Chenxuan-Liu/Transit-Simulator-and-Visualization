<<<<<<< HEAD
/**
 * @file visualization_simulator.cc
 *
 * @copyright 2019 3081 Staff, All rights reserved.
 */
#include "web_code/web/visualization_simulator.h"

#include "src/bus.h"
#include "src/bus_factory.h"
#include "src/route.h"

VisualizationSimulator::VisualizationSimulator(WebInterface*
webI, ConfigManager* configM) {
=======

#include "visualization_simulator.h"

#include "bus.h"
#include "route.h"

#include <iostream>

VisualizationSimulator::VisualizationSimulator(WebInterface* webI, ConfigManager* configM, std::ostream* out) {
>>>>>>> support-code
    webInterface_ = webI;
    configManager_ = configM;
    paused_ = false;
    out_ = out;
}

VisualizationSimulator::~VisualizationSimulator() {}

<<<<<<< HEAD
void VisualizationSimulator::Start(const std::
vector<int>& busStartTimings, const int& numTimeSteps) {
=======
void VisualizationSimulator::TogglePause() {
    std::cout << "Toggling Pause" << std::endl;
    paused_ = !paused_;
}

void VisualizationSimulator::Start(const std::vector<int>& busStartTimings, const int& numTimeSteps) {
>>>>>>> support-code
    busStartTimings_ = busStartTimings;
    numTimeSteps_ = numTimeSteps;

    timeSinceLastBus_.resize(busStartTimings_.size());
    for (int i = 0; i < static_cast<int>(timeSinceLastBus_.size()); i++) {
        timeSinceLastBus_[i] = 0;
    }

    simulationTimeElapsed_ = 0;

    prototypeRoutes_ = configManager_->GetRoutes();
    for (int i = 0; i < static_cast<int>(prototypeRoutes_.size()); i++) {
<<<<<<< HEAD
        prototypeRoutes_[i]->Report(std::cout);

=======
        prototypeRoutes_[i]->Report(*out_);
        
>>>>>>> support-code
        prototypeRoutes_[i]->UpdateRouteData();
        webInterface_->UpdateRoute(prototypeRoutes_[i]->GetRouteData());
    }
}

<<<<<<< HEAD
void VisualizationSimulator::Update() {
    if (!pausestate) {
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

                busses_.push_back(BusFactory::Generate(std::to_string(busId),
                    outbound->Clone(), inbound->Clone(), 1));
                busId++;

                timeSinceLastBus_[i] = busStartTimings_[i];
            } else {
                timeSinceLastBus_[i]--;
            }
        }
=======
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
>>>>>>> support-code

        std::cout << "~~~~~~~~~ Updating busses ";
        std::cout << "~~~~~~~~~" << std::endl;

        // Update busses
        for (int i = static_cast<int>(busses_.size()) - 1; i >= 0; i--) {
            busses_[i]->Update();

            if (busses_[i]->IsTripComplete()) {
                webInterface_->UpdateBus(busses_[i]->GetBusData(), true);
                busses_.erase(busses_.begin() + i);
                continue;
            }

            webInterface_->UpdateBus(busses_[i]->GetBusData());

            busses_[i]->Report(std::cout);
        }

<<<<<<< HEAD
        std::cout << "~~~~~~~~~ Updating routes ";
        std::cout << "~~~~~~~~~" << std::endl;
        // Update routes
        for (int i = 0; i < static_cast<int>(prototypeRoutes_.size()); i++) {
            prototypeRoutes_[i]->Update();
=======
        busses_[i]->Report(*out_);
    }
    
    std::cout << "~~~~~~~~~ Updating routes ";
    std::cout << "~~~~~~~~~" << std::endl;
    // Update routes
    for (int i = 0; i < static_cast<int>(prototypeRoutes_.size()); i++) {
        prototypeRoutes_[i]->Update();
>>>>>>> support-code

            webInterface_->UpdateRoute(prototypeRoutes_[i]->GetRouteData());

<<<<<<< HEAD
            prototypeRoutes_[i]->Report(std::cout);
        }
=======
        prototypeRoutes_[i]->Report(*out_);
>>>>>>> support-code
    }
}

void VisualizationSimulator::Pause() {
    pausestate = !pausestate;
}
